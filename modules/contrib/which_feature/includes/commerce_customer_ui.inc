<?php
/**
 * @file
 * Customer UI module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of
 * commerce_customer_ui.module.
 */
function commerce_customer_ui_which_feature_info() {
  $table_preprocess = array();

  $table_preprocess['admin/commerce/customer-profiles/types'] = array(
    'component' => 'commerce_customer_type',
    'delta callback' => 'which_feature_commerce_customer_delta',
  );

  return array('table_preprocess' => $table_preprocess);
}

/**
 * Delta callback for commerce_customer_ui.module.
 */
function which_feature_commerce_customer_delta(&$delta, $row) {
  // @TODO - Deal with translation string.
  if (preg_match('/\(Machine name: (.*?)\)/', $row[0], $matches)) {
    $delta = $matches[1];
  }
}
