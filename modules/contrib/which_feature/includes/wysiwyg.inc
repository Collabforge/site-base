<?php
/**
 * @file
 * Wysiwyg module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of wysiwyg.module.
 */
function wysiwyg_which_feature_info() {
  $help = array();
  $table_preprocess = array();

  $help['admin/config/content/wysiwyg/profile/%/edit'] = array(
    'component' => 'wysiwyg',
  );

  $table_preprocess['admin/config/content/wysiwyg'] = array(
    'component' => 'wysiwyg',
    'delta callback' => 'which_feature_wysiwyg_delta',
  );

  return array(
    'help' => $help,
    'table_preprocess' => $table_preprocess,
  );
}

/**
 * Delta callback for wysiwyg.module.
 */
function which_feature_wysiwyg_delta(&$delta, $row) {
  if (preg_match('/profile\/(.*?)\/edit/', $row[2], $matches)) {
    $delta = $matches[1];
  }
}
