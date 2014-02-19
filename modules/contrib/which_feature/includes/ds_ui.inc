<?php
/**
 * @file
 * Display Suite UI module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of ds_ui.module.
 */
function ds_ui_which_feature_info() {
  $help = array();
  $table_preprocess = array();

  $help['admin/structure/ds/fields/manage_custom'] = array(
    'component' => 'ds_fields',
  );

  $help['admin/structure/ds/view_modes/manage'] = array(
    'component' => 'ds_view_modes',
  );

  $table_preprocess['admin/structure/ds/fields'] = array(
    'component' => 'ds_fields',
    'delta callback' => 'which_feature_ds_fields_delta',
  );

  $table_preprocess['admin/structure/ds/view_modes'] = array(
    'component' => 'ds_view_modes',
    'delta callback' => 'which_feature_ds_view_modes_delta',
  );

  return array(
    'help' => $help,
    'table_preprocess' => $table_preprocess,
  );
}

/**
 * Delta callback for Display Suite fields.
 */
function which_feature_ds_fields_delta(&$delta, $row) {
  $delta = $row[2];
}

/**
 * Delta callback for Display Suite view modes.
 */
function which_feature_ds_view_modes_delta(&$delta, $row) {
  $delta = $row[1];
}
