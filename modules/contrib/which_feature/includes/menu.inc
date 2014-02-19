<?php
/**
 * @file
 * Menu module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of menu.module.
 */
function menu_which_feature_info() {
  $help = array();
  $table_preprocess = array();

  $help['admin/structure/menu/manage/%/edit'] = array(
    'component' => 'menu_custom',
  );

  $table_preprocess['admin/structure/menu'] = array(
    'component' => 'menu_custom',
    'delta callback' => 'which_feature_menu_delta',
  );

  return array(
    'help' => $help,
    'table_preprocess' => $table_preprocess,
  );
}

/**
 * Delta callback for menu.module.
 */
function which_feature_menu_delta(&$delta, $row) {
  if (preg_match('/manage\/(.*?)\"/', $row[1]['data'], $matches)) {
    $delta = $matches[1];
  }
}
