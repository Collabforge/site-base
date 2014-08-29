<?php
/**
 * @file
 * Taxonomy module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of taxonomy.module.
 */
function taxonomy_which_feature_info() {
  $help = array();
  $table_preprocess = array();

  $help['admin/structure/taxonomy/%/edit'] = array(
    'component' => 'taxonomy',
  );

  $table_preprocess['admin/structure/taxonomy'] = array(
    'component' => 'taxonomy',
    'delta callback' => 'which_feature_taxonomy_delta',
  );

  return array(
    'help' => $help,
    'table_preprocess' => $table_preprocess,
  );
}

/**
 * Delta callback for taxonomy.module.
 */
function which_feature_taxonomy_delta(&$delta, $row) {
  if (preg_match('/taxonomy\/(.*?)\/edit/', $row[2], $matches)) {
    $delta = $matches[1];
  }
}
