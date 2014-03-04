<?php

/**
 * @file
 * A test endpoint for the Aoc CRM service
 */

/**
 * Menu Callback
 */
function behat_testing_mock_api_callback() {
  $args = func_get_args();

  try {
    $response = behat_testing_mock_api_get_test_api_response($args);

    foreach ($response->headers as $name => $value) {
      drupal_add_http_header($name, $value);
    }

    drupal_add_http_header('Status', _behat_testing_mock_api_set_http_status($response->status));
    print $response->body;

  }
  catch (Exception $e) {
    watchdog_exception('behat_testing_mock_api', $e);
  }

  drupal_exit();
}

/**
 * HTTP status code lookup
 *
 * @param int $status_code
 *   The status code number
 *
 * @return string|bool
 *   The text of the status code or FALSE if none found
 */
function _behat_testing_mock_api_set_http_status($status_code) {
  static $codes = array(
    200 => '200 OK',
    201 => '201 Created',
    202 => '202 Accepted',
    203 => '203 Non-Authoritative Information',
    204 => 'No Content',
    205 => 'Reset Content',
    206 => 'Partial Content',
    207 => 'Multi-Status',
    208 => 'Already Reported',
    300 => 'Multiple Choices',
    301 => 'Moved Permanently',
    302 => 'Found',
    304 => 'Not Modified',
    305 => 'Use Proxy',
    306 => 'Switch Proxy',
    307 => 'Temporary Redirect',
    308 => 'Permanent Redirect',
    400 => 'Bad Request',
    401 => 'Unauthorized',
    402 => 'Payment Required',
    403 => 'Forbidden',
    404 => 'Not Found',
    405 => 'Method Not Allowed',
    406 => 'Not Acceptable',
    410 => 'Gone',
    418 => 'I\'m a teapot',
    500 => 'Internal Server Error',
    501 => 'Not Implemented',
    502 => 'Bad Gateway',
    503 => 'Service Unavailable',
  );

  return !empty($status_code) && !empty($codes[$status_code]) ? $codes[$status_code] : FALSE;
}
