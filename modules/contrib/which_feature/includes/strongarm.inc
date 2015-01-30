<?php
/**
 * @file
 * Strongarm module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of strongarm.module.
 */
function strongarm_which_feature_info() {
  $help = array();
  $table_preprocess = array();

  $table_preprocess['admin/config/development/strongarm'] = array(
    'component' => 'variable',
    'delta callback' => 'which_feature_strongarm_delta',
  );

  // Devel module integration.
  if (module_exists('devel')) {
    $help['devel/variable/edit/%'] = array(
      'component' => 'variable',
    );

    $table_preprocess['devel/variable'] = array(
      'component' => 'variable',
      'delta callback' => 'which_feature_strongarm_delta',
    );
  }

  return array(
    'help' => $help,
    'table_preprocess' => $table_preprocess,
  );
}

/**
 * Delta callback for strongarm.module.
 */
function which_feature_strongarm_delta(&$delta, $row) {
  $delta = $row[1];
}
