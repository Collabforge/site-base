<?php

/**
 * @file
 * Run behat tests via drush
 */

/**
 * Implements hook_drush_command().
 */
function behat_testing_drush_command() {
  $items['behat'] = array(
    'description' => 'Run behat tests on the current site',
    'bootstrap' => DRUSH_BOOTSTRAP_MAX,
    'aliases' => array('be'),
    'arguments' => array(
      'tags' => 'List of tag names to restrict the tests to',
    ),
    'options' => array(
      'profile' => 'Profile to use from the behat.yml file. Default is default',
      'format' => 'behat format, default is pretty. Other options are:
                   - progress: Prints one character per step.
                   - html: Generates a nice looking HTML report.
                   - junit: Generates a report similar to Ant+JUnit.
                   - failed: Prints list of failed scenarios.
                   - snippets: Prints only snippets for undefined steps.',
      'out' => 'Output directory to save output into, required for format=junit',
    ),
    'examples' => array(
      'drush be' => 'Run all features tests using the default profile. Current db is cloned and tests run on that clone',
      'drush be --profile=rebuild' => 'Run all feature tests using the rebuild profile. With this profile, the test site\'s db is cleared and the site renistalled. If a module is specified in the behat.yml file then this is then enabled along with all its dependencies.',
    ),
  );

  $items['behat-steps'] = array(
    'description' => 'List all possible behat steps taht can be used in scenarios',
    'bootstrap' => DRUSH_BOOTSTRAP_MAX,
    'aliases' => array('bel'),
    'examples' => array(
      'drush bel' => 'Lists all the steps that you can use in scenarios',
    ),
  );

  $items['behat-test-clean'] = array(
    'description' => 'Cleanup testing tables in the db - these are allprefixed with simpletest101',
    'bootstrap' => DRUSH_BOOTSTRAP_MAX,
    'aliases' => array('btc'),
    'examples' => array(
      'drush btc' => 'Drops all behat testing tables',
    ),
  );

  return $items;
}

/**
 * Cleanup behat dbs.
 */
function drush_behat_testing_behat_test_clean() {
  $tables = db_find_tables('simpletest101%');

  if (empty($tables)) {
    drush_print('No test tables to drop');
    return;
  }

  drush_print('Dropping test tables ...');
  foreach ($tables as $table) {
    db_drop_table($table);
  }
  drush_print('... complete');
}

/**
 * Drush callback. Run behat tests on the current site
 * based on the yml file located in the sites folder.
 */
function drush_behat_testing_behat() {
  try {
    $cmd = _behat_testing_generate_command(drush_get_option('format', 'pretty'), drush_get_option('profile', 'default'), func_get_args(), drush_get_option('out', ''));
    drush_print($cmd);
    $status_code = drush_shell_proc_open($cmd);
    if (!empty($status_code)) {
      throw new Exception('Behat tests failed');
    }
  }
  catch (Exception $e) {
    return drush_set_error($e->getMessage());
  }
}

/**
 * Drush command for listing possible steps.
 */
function drush_behat_testing_behat_steps() {
  try {
    $config = behat_testing_get_config();
    $cmd = "behat --config $config -dl";
    drush_print($cmd);
    $status_code = drush_shell_proc_open($cmd);
    if (!empty($status_code)) {
      throw new Exception('Unexpected problem');
    }
  }
  catch (Exception $e) {
    return drush_set_error($e->getMessage());
  }
}
