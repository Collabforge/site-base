<?php
/**
 * Copy this file to your sites/all/tests folder
 * Then you can use this file for your site-specific 
 * tests
 * It will not be loaded from its default position!
 */

use Behat\Behat\Context\ClosuredContextInterface,
    Behat\Behat\Context\TranslatedContextInterface,
    Behat\Behat\Context\BehatContext,
    Behat\Behat\Exception\PendingException,
    Behat\Mink\Exception\ExpectationException,
    Behat\Mink\Exception\ElementNotFoundException,
    Behat\Behat\Context\Step,
    Behat\Gherkin\Node\PyStringNode,
    Behat\Gherkin\Node\TableNode,
    Behat\MinkExtension\Context\MinkContext,
    Behat\Mink\Session,
    Behat\Behat\Context\ContextDispatcher;

/**
 * Example behat subcontext.
 *
 * This is an example Sub Context class for writing behat feature
 * steps. To access functions in the master DrupalContext use the
 * following syntax. For example, to get the contents of the last
 * page request use:
 *
 * $page_contents = $this->getMainContext()->getSession()->getPage()->getText();
 */
class MyDrupalContext extends BehatContext {

}
