<?php
/**
 * @file
 * Node module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of node.module.
 */
function node_which_feature_info() {
  $help = array();
  $table_preprocess = array();

  $help['admin/structure/types/manage/%'] = array(
    'component' => 'node',
    'delta source' => 'type',
  );

  $table_preprocess['admin/structure/types'] = array(
    'component' => 'node',
    'delta callback' => 'which_feature_node_delta',
  );

  return array(
    'help' => $help,
    'table_preprocess' => $table_preprocess,
  );
}

/**
 * Delta callback for node.module.
 */
function which_feature_node_delta(&$delta, $row) {
  // @TODO - Deal with translation string.
  if (preg_match('/\(Machine name: (.*?)\)/', $row[0], $matches)) {
    $delta = $matches[1];
  }
}
