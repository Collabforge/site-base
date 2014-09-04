# Behat testing mock api

This module provides a mock endpoint for testing Drupal integrations
with external apis. With this module enabled, your behaviour scenarios
can define expected calls to an API and set the expected response.

To setup this module, you should specify a file in your settings.php
that can be written to by your web user. Expected calls to the webservice
will be stored there.  For example, add this to your settings.php file

    $conf['behat_testing_mock_api_expectation_file'] = '/tmp/behatapi.txt';

To use this, you need to change the endpoint your API connects to
at the start of the tests using this code, usually placed in an
@before scenario function, for example:

    /**
     * @BeforeScenario
     */
    public function before($event) {
      variable_set('my_api_endpoint_url', behat_testing_mock_api_endpoint_url());
    }

You can then set expected calls to the api and specify the response
to that call.

For example, suppose you had a call which got a user from a CRM
system with a REST interface. Assuming the URL is usually of the form:
http://crm.example.com/api/contact/363525

Then during login perhaps Drupal calls that URL to get the users details.
The response is a JSON array with one user object inside it. Inside your
own behat context you can then define a function like this to use where
appropriate.

    public function expectRequestUser($id, $name, $email) {

      // Expect the following request.
      $request = (object) array(
        'args' => array('api', 'contact', $id),
      );

      $contact = (object) array(
        'id' => $id,
        'name' => $name,
        'email' => $email,
      );

      $result = new stdClass();
      $result->contacts = array($contact);

      // Respond with the following response.
      $response = (object) array(
        'headers' => array(
          'Content-Type' => 'application/json',
        ),
        'status' => 200,
        'body' => json_encode($result),
      );

      // Register this expectation.
      behat_testing_mock_api_set_test_api_response($request, $response);
    }

Now, whenever, expectRequestUser() function is called, behat will
expect its mock endpoint to be contacted with those details during
the following STEP.

If you want to fail the test if that request was not made, or if
additional unexpected requests were made to the API, you need to
include the following step.

  Then all expected requests were received by the API
