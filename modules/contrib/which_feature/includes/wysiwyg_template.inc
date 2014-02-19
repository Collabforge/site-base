<?php
/**
 * @file
 * Wysiwyg Template Plugin module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of wysiwyg_template.module.
 */
function wysiwyg_template_which_feature_info() {
  $help = array();
  $table_preprocess = array();

  $help['admin/config/content/wysiwyg-templates/edit/%'] = array(
    'component' => 'wysiwyg_template',
  );

  $table_preprocess['admin/config/content/wysiwyg-templates'] = array(
    'component' => 'wysiwyg_template',
    'delta callback' => 'which_feature_wysiwyg_template_delta',
  );

  return array(
    'help' => $help,
    'table_preprocess' => $table_preprocess,
  );
}

/**
 * Delta callback for wysiwyg_template.module.
 */
function which_feature_wysiwyg_template_delta(&$delta, $row) {
  if (preg_match('/edit\/(.*?)\"/', $row[2], $matches)) {
    $delta = $matches[1];
  }
}
