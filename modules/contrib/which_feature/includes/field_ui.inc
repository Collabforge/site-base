<?php
/**
 * @file
 * Field UI integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of field_ui.module.
 */
function field_ui_which_feature_info() {
  $help = array();
  $table_preprocess = array();

  // Node module integration.
  if (module_exists('node')) {
    $help['admin/structure/types/manage/%/fields/%'] = array(
      'component' => 'field',
      'delta callback' => 'which_feature_field_ui_node_help_delta',
      'position' => 6,
    );

    $table_preprocess['admin/structure/types/manage/%/fields'] = array(
      'component' => 'field',
      'delta callback' => 'which_feature_field_ui_node_table_preprocess_delta',
    );
  }

  return array(
    'help' => $help,
    'table_preprocess' => $table_preprocess,
  );
}

/**
 * Help delta callback for Node fields.
 */
function which_feature_field_ui_node_help_delta(&$delta, $component) {
  $delta = "node-{$component->bundle}-{$delta}";
}

/**
 * Table preprocess delta callback for Node fields.
 */
function which_feature_field_ui_node_table_preprocess_delta(&$delta, $row) {
  if (preg_match('/^\w+$/', $row[3]['data'])) {
    $content_type = str_replace('-', '_', arg(4));
    $delta = "node-{$content_type}-{$row[3]['data']}";
  }
}
