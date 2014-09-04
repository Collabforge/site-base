<?php
/**
 * @file
 * Filter module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of filter.module.
 */
function filter_which_feature_info() {
  $help = array();
  $table_preprocess = array();

  $help['admin/config/content/formats/%'] = array(
    'component' => 'filter',
  );

  $table_preprocess['admin/config/content/formats'] = array(
    'component' => 'filter',
    'delta callback' => 'which_feature_filter_delta',
  );

  return array(
    'help' => $help,
    'table_preprocess' => $table_preprocess,
  );
}

/**
 * Delta callback for filter.module.
 */
function which_feature_filter_delta(&$delta, $row) {
  if (preg_match('/formats\[(.*?)\]\[weight\]/', $row[2], $matches)) {
    $delta = $matches[1];
  }
}
