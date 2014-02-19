<?php
/**
 * @file
 * Bean Admin UI module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of bean_admin_ui.module.
 */
function bean_admin_ui_which_feature_info() {
  $help = array();
  $table_preprocess = array();

  $help['admin/structure/block-types/manage/%/edit'] = array(
    'component' => 'bean_type',
    'delta source' => 'type',
  );

  $table_preprocess['admin/structure/block-types'] = array(
    'component' => 'bean_type',
    'delta callback' => 'which_feature_bean_delta',
  );

  return array(
    'help' => $help,
    'table_preprocess' => $table_preprocess
  );
}

/**
 * Delta callback for bean_admin_ui.module.
 */
function which_feature_bean_delta(&$delta, $row) {
  foreach ($row as $column) {
    if (isset($column['data']) && preg_match('/block-types\/manage\/(.*?)\//', $column['data'], $matches)) {
      $delta = str_replace('-', '_', $matches[1]);
    }
  }
}
