<?php

/**
 * @file
 * Behat Testing Mock API Sub Context.
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
 * Mock API subcontext.
 *
 * This subcontext provides methods to check calls to the
 * behat_testing_mock_api submodule.
 */
class MockAPIContext extends BehatContext {

  /**
   * @BeforeScenario
   */
  public function beforeScenario($event) {
    behat_testing_mock_api_clear_all_api_responses();
  }

  /**
   * Expect a call to the API.
   *
   * Use this function to expect a call to the API. Once that
   * call should have happened you must then call confirmAPIRequests
   * to check that the API requests were actually called.
   *
   * @param object $request
   *   A request object which describes what should have been sent to the API
   *     ->headers array, an array of headers key is the type.
   *       e.g. array('Content-Type' => 'application/json')
   *     ->method string 'GET' or 'POST'
   *     ->args array a list of arguments sent to the URL
   *     ->body string Body content of request
   * @param object $response
   *   A response object containing parameters
   *     ->headers array, an array of headers key is the type.
   *       e.g. array('Content-Type' => 'application/json')
   *     ->status int The status code, this sets the status response header
   *       so don't include that in headers above.
   *     ->body string Body content of response
   */
  public function expectAPIRequest($request, $response) {
    behat_testing_mock_api_set_test_api_response($request, $response);
  }

  /**
   * Check the API calls were as expected.
   *
   * This function is to be used within feature functions to check
   * the status of the API. If the step previously set some expected
   * API calls, this function should be called after those
   * calls should have happened to check that they both did happen
   * and that no other calls to the API happened at the same time.
   */
  public function confirmAPIRequests() {
    $expectations = _behat_testing_mock_api_get_expectations();
    behat_testing_mock_api_clear_all_api_responses();

    $errormsg = '';

    if (!empty($expectations['expected'])) {
      $errormsg = sprintf('Expected API calls not received: %s.', print_r($expectations['expected'], TRUE)) . "\n";
    }

    if (!empty($expectations['unexpected'])) {
      $errormsg .= sprintf('Unexpected calls to the API were received: %s.', print_r($expectations['unexpected'], TRUE));
    }

    if (!empty($errormsg)) {
      throw new ExpectationException($errormsg, $this->getMainContext()->getSession());
    }
  }

  /**
   * @Then /^all expected requests were received by the API$/
   */
  public function allExpectedRequestsWereReceivedByTheAPI() {
    $this->confirmAPIRequests();
  }

}
