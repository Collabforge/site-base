<?php

/**
 * @file
 */

/**
 * Be kind on poor Drupal!
 */
define('BEHAT_ERROR_REPORTING', E_ERROR | E_WARNING | E_PARSE);

use Behat\Behat\Context\ClosuredContextInterface,
    Behat\Behat\Context\TranslatedContextInterface,
    Behat\Behat\Context\BehatContext,
    Behat\Behat\Exception\PendingException,
    Behat\Mink\Exception\ElementNotFoundException,
    Behat\Mink\Exception\ExpectationException,
    Behat\Behat\Context\Step,
    Behat\Gherkin\Node\PyStringNode,
    Behat\Gherkin\Node\TableNode,
    Behat\Gherkin\Node\StepNode,
    Behat\MinkExtension\Context\MinkContext,
    Behat\Mink\Session,
    Behat\Behat\Context\ContextDispatcher;

/**
 * Features context.
 */
class DrupalContext extends MinkContext {

  public static $user_roles = array();
  public $behatTestId = NULL;
  public $current_user = NULL;
  public $base_url = "";

  /**
   * Get the currently logged in user.
   */
  public function getCurrentUser() {
    return $this->current_user;
  }

  /**
   * Initializes context.
   * Every scenario gets it's own context object.
   *
   * @param array $parameters
   *   context parameters (set them up through behat.yml)
   */
  public function __construct(array $parameters) {

    $this->parameters = $parameters;
    $this->base_url = "http://meta.local";
    // Bootstrap drupal.
    $_SERVER['PHP_SELF'] = basename(__FILE__);
    $_SERVER['REMOTE_ADDR'] = $parameters['site'];
    $_SERVER['HTTP_HOST'] = $parameters['site'];
    $_SERVER['REQUEST_METHOD'] = 'GET';

    if (!defined('DRUPAL_ROOT')) {
      define('DRUPAL_ROOT', getcwd());
    }

    require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
    drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

    // Register our subclasses.
    // @TODO This can probably be done without a static
    // but I couldn't work out how to get where I needed to be.
    $classlist = MyLocatorProcessor::getClassList();
    $thisclass = get_class($this);
    foreach ($classlist as $id => $class) {
      $c = basename($class, '.behat_testing.php');
      if ($c == $thisclass) {
        continue;
      }
      $this->useContext($c, new $c($parameters));
    }

    $this->behatTestId = variable_get('behat_testing_test_id', time());
  }

  /**
   * Returns Mink session.
   *
   * @param string|NULL $name
   *   name of the session OR active session will be used
   *
   * @return session
   *   A MINK session
   */
  public function getSession($name = NULL) {

    $parameters = $this->parameters;
    $session = parent::getSession($name);

    if (!empty($parameters['use_test_database'])) {
      // This forces the creation of a test version
      // of the database for use with behat.
      // Since it hooks into Simpletest it must use
      // simpletests naming convention.
      $ua = drupal_generate_test_ua('simpletest101');
      $session->setRequestHeader('User-Agent', $ua);
    }

    return $session;
  }

  /** @BeforeSuite */
  public static function prepareForTheSuite($event) {
    $parameters = $event->getContextParameters();

    // Set the test db prefix.
    if (!empty($parameters['use_test_database'])) {
      behat_testing_setup();
    }
  }

  /** @BeforeFeature */
  public static function beforeFeature($event) {
    $parameters = $event->getContextParameters();

    // Reinstall site.
    if (isset($parameters['rebuild_on_feature']) && !empty($parameters['rebuild_on_feature'])) {
      // Clear out statics.
      self::$user_roles = array();

      // Reinstall.
      behat_testing_reinstall($parameters['rebuild_on_feature']);

      if (isset($parameters['rebuild_module']) && !empty($parameters['rebuild_module'])) {
        module_enable(explode(',', $parameters['rebuild_module']));
      }
    }
    elseif (!empty($parameters['use_test_database'])) {

      if (!empty($parameters['reset_test_database']) || !db_table_exists('system')) {

        // There either isn't a test database or it has been set to be reset.
        self::$user_roles = array();

        // Reset the db to be the same as the existing site.
        print 'Resetting DB...';
        behat_testing_copy_database('simpletest101');
        behat_testing_setup_paths();
        print '... DB reset complete';
      }
    }

    // Clean out the temporary email store.
    variable_set('drupal_test_email_collector', array());

    // Generate a behat test id.
    variable_set('behat_testing_test_id', time());

    // Set the testing mailhandler.
    behat_testing_setup_mail();
  }

  /** @BeforeScenario **/
  public function beforeScenario($event) {
    if (method_exists($event, 'getOutline')) {
      // Replace [tid] token in example tables with the current test id.
      $outline = $event->getOutline();
      if ($outline->hasExamples()) {
        $examples = $outline->getExamples();
        $new_rows = array();

        foreach ($examples->getRows() as $rid => $row) {
          foreach ($row as $cid => $col) {
            $new_rows[$rid][$cid] = $this->replaceTidToken($col);
          }
        }

        $examples->setRows($new_rows);
      }
    }
  }

  /** @BeforeStep */
  public function beforeStep($event) {
    $step = $event->getStep();
    if ($step->hasArguments()) {
      // Replace [tid] token in input tables with the test id.
      $args = $step->getArguments();
      foreach ($args as $arg) {
        if ($arg instanceof TableNode) {
          $new_rows = array();
          foreach ($arg->getRows() as $row) {
            $new_rows[] = array(
              0 => $row[0],
              1 => $this->replaceTidToken($row[1]),
            );
          }
          $arg->setRows($new_rows);
        }
      }
    }
    elseif ($step instanceof Behat\Gherkin\Node\StepNode) {
      // Replace [tid] token in step definitions with the current test id.
      // Use reflection to allow StepNodes text to be alterable,
      // this is to allow the [tid] token to be added to step
      // definitions and replaced with the test id.
      $reflection_property = new ReflectionProperty('Behat\Gherkin\Node\StepNode', 'text');
      $reflection_property->setAccessible(TRUE);
      $reflection_property->setValue($step, $this->replaceTidToken($step->getText()));
    }
  }

  /**
   * Replace the [tid] token in a string with the test id.
   *
   * @param string $string
   *   The string which may contain the [tid] token.
   *
   * @return string
   *   The same string with [tid] replaced with the current test id.
   */
  public function replaceTidToken($string) {
    return str_replace('[tid]', $this->behatTestId, $string);
  }

  /**
   * @Given /^I am logged in with the role "([^"]*)"$/
   */
  public function iAmLoggedInWithTheRole($role) {
    if (!isset(self::$user_roles[$role])) {
      $r = user_role_load_by_name($role);

      if (empty($r)) {
        throw new Exception(t('No such role @role', array('@role' => $role)));
      }

      $account = $this->drupalCreateUser($this->randomName(), $role);

      if (empty($account)) {
        throw new Exception(t('Could not create user with role @role', array('@role' => $role)));
      }

      self::$user_roles[$role] = $account->name;
    }

    return array(
      new Step\Given('I am logged in as "' . self::$user_roles[$role] . '"'),
    );
  }

  /**
   * @Given /^I should see a "([^"]*)" field with id "([^"]*)"$/
   */
  public function iShouldSeeAFieldWithId($field_type, $id) {
    $element = $this->assertSession()->elementExists('css', $field_type . '#' . $id);
  }

  /**
   * @Then /^I should see nodes of type "([^"]*)" inside "([^"]*)"$/
   */
  public function iShouldSeeNodesOfTypeInside($type, $selector) {
    $element = $this->assertSession()->elementExists('css', $selector);
    $types = $element->find('css', '.node-' . $type);
    if (NULL === $types) {
      throw new ElementNotFoundException($this->getSession(), 'element', $type, $selector);
    }
    return $types;
  }

  /**
   * @Given /^I go to the "([^"]*)" node form$/
   */
  public function iGoToTheNodeForm($nodeform) {
    list($operation, $type) = explode(" ", $nodeform);
    if ($operation == 'add') {
      return array(
        new Step\Given('I am on "node/add/' . $type . '"'),
      );
    }
  }

  /**
   * @Then /^I should see nodes of type "([^"]*)" inside "([^"]*)" with taxonomy "([^"]*)" matching "([^"]*)"$/
   */
  public function iShouldSeeNodesOfTypeInsideWithTaxonomyMatching($type, $selector, $node_property, $matching) {
    $node = $this->iShouldSeeNodesOfTypeInside($type, $selector);
    $node = explode('-', ($node->getAttribute('id')));
    if (!isset($node[1])) {
      throw new ElementNotFoundException($this->getSession(), 'element', $type, $selector);
    }
    $nid = $node[1];
    $n = node_load($nid);
    $terms = field_view_field('node', $n, $node_property);
    foreach ($terms as $id => $term) {
      if (is_numeric($id)) {
        if ($term['#title'] == $matching) {
          return TRUE;
        }
      }
    }
    throw new ElementNotFoundException($this->getSession(), 'element', $type, $selector);
  }

  /**
   * @Given /^a node of type "([^"]*)" with the title "([^"]*)" and language "([^"]*)" exists$/
   */
  public function aNodeOfTypeWithTheTitleAndLanguageExists($content_type, $title, $language) {
    $account = user_load(1);
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $content_type)
      ->propertyCondition('title', $title)
      ->propertyCondition('language', $language)
      ->addMetaData('account', $account)
      ->execute();

    $nodes = isset($result['node']) ? entity_load('node', array_keys($result['node'])) : array();

    if (empty($nodes)) {
      $node = new stdClass();
      $node->type = $content_type;
      $node->title = $title;
      $node->language = $language;
      node_save($node);
    }
  }

  /**
   * @Given /^a node of type "([^"]*)" with the title "([^"]*)" exists$/
   */
  public function aNodeOfTypeWithTheTitleExists($content_type, $title) {
    return $this->aNodeOfTypeWithTheTitleAndLanguageExists($content_type, $title, 'und');
  }

  /**
   * @Given /^cron has run$/
   */
  public function cronHasRun() {
    return new Step\Given('I am on "/cron.php?cron_key=' . variable_get('cron_key', 'drupal') . '"');
  }

  /**
   * @Given /^I am not logged in$/
   */
  public function iAmNotLoggedIn() {
    $this->current_user = FALSE;
    $this->getSession()->reset();
  }

  /**
   * @Given /^I should see a "([^"]*)" field with id "([^"]*)" and value "([^"]*)"$/
   */
  public function iShouldSeeAFieldWithIdAndValue($field_type, $id, $value) {
    $page = $this->getSession()->getPage();
    $field = $page->find('css', $field_type . '#' . $id);
    if ($field->getValue() != $value) {
      throw new Exception("$field_type with id $id does not equal $value. Found '" . $field->getValue() . "' instead");
    }
  }

  /**
   * @Given /^there should be a form error on the element with id "([^"]*)"$/
   */
  public function thereShouldBeAFormErrorOnTheElementWithId($id) {
    $page = $this->getSession()->getPage();
    $field = $page->find('css', '#' . $id);
    if (empty($field)) {
      throw new Exception('No element with id ' . $id);
    }

    if (!$this->elementHasClass($field, 'error')) {
      throw new Exception("The element with id $id has not been flagged as in an error state");
    }
  }

  /**
   * Helper function to determine if an element has a class.
   */
  public function elementHasClass($element, $class) {
    $classes = explode(' ', $element->getAttribute('class'));
    return in_array($class, $classes);
  }

  /**
   * @Given /^I logout$/
   */
  public function logout() {
    $session = $this->getSession();
    $this->current_user = FALSE;
    $session->reset();
  }

  /**
   * @Given /^I am logged in as "([^"]*)"$/
   */
  public function iAmLoggedInAs($name) {

    // Load the user fresh.
    $users = user_load_multiple(array(), array('name' => $name), TRUE);

    if (empty($users)) {
      throw new Exception(t('No such user with username "@name"', array('@name' => $name)));
    }

    $user = array_pop($users);

    if (!empty($this->current_user)) {
      if ($this->current_user->name == $name) {
        // Already logged in as this person.
        return;
      }
      $this->logout();
    }

    $session = $this->getSession();
    $session->visit($link);
    $this->current_user = $user;
  }

  /**
   * Generate a one time login link.
   *
   * @param user $account
   *   The user account you need to login as
   *
   * @return string
   *   URL to login
   */
  public function generateOneTimeLogin($account) {
    $timestamp = time();
    return url("user/reset/$account->uid/$timestamp/" . user_pass_rehash($account->pass, $timestamp, $account->login) . '/login', array('absolute' => TRUE, 'base_url' => $this->base_url));
  }

  /**
   * @Given /^User with name "([^"]*)" and roles "([^"]*)" exists$/
   *
   * @param string $name
   *   login username
   * @param string $roles_string
   *   comma separated list of roles
   */
  public function drupalCreateUser($name, $roles_string) {
    $roles = array();
    foreach (explode(',', $roles_string) as $role) {
      $role = trim($role);
      $role_obj = user_role_load_by_name($role);
      if (empty($role_obj)) {
        throw new Exception(t('Role @role does not exist', array('@role' => $role)));
      }
      $roles[] = $role_obj;
    }

    $rids = array();
    foreach ($roles as $role) {
      $rids[$role->rid] = $role->rid;
    }

    // Create a user assigned to that role.
    $edit = array();
    $edit['name']   = $name;
    $edit['mail']   = $edit['name'] . '@example.com';
    $edit['pass']   = user_password();
    $edit['status'] = 1;

    if (!empty($rids)) {
      $edit['roles'] = $rids;
    }

    $account = user_save(drupal_anonymous_user(), $edit);

    if (empty($account->uid)) {
      return FALSE;
    }

    // Add the raw password so that we can log in as this user.
    $account->pass_raw = $edit['pass'];

    // Reference user above.
    $this->users[$account->uid] = $account;

    return $account;
  }

  /**
   * Generates a random string containing letters and numbers.
   *
   * The string will always start with a letter. The letters may be upper or
   * lower case. This method is better for restricted inputs that do not
   * accept certain characters. For example, when testing input fields that
   * require machine readable values (i.e. without spaces and non-standard
   * characters) this method is best.
   *
   * Do not use this method when testing unvalidated user input. Instead, use
   * DrupalWebTestCase::randomString().
   *
   * @param int $length
   *   Length of random string to generate.
   *
   * @return string
   *   Randomly generated string.
   */
  public function randomName($length = 8) {
    $values = array_merge(range(65, 90), range(97, 122), range(48, 57));
    $max = count($values) - 1;
    $str = chr(mt_rand(97, 122));
    for ($i = 1; $i < $length; $i++) {
      $str .= chr($values[mt_rand(0, $max)]);
    }
    return $str;
  }


  /**
   * @Given /^I should see a drupal "([^"]*)" message "([^"]*)"$/
   */
  public function iShouldSeeADrupalMessage($message_type, $message) {
    return array(
      new Step\Then('I should see "' . $message . '" in the ".' . $message_type . '" element'),
    );
  }

    /**
     * @Then /^an email should be sent to "([^"]*)"$/
     */
  public function anEmailShouldBeSentTo($mail) {
    $emails = behat_testing_variable_get('drupal_test_email_collector', array());

    foreach ($emails as $email) {
      if ($email['to'] == $mail) {
        return TRUE;
      }
    }

    $message = sprintf('No email was sent to "%s".', $mail);
    throw new ExpectationException($message, $this->getSession());
  }

}
