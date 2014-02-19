<?php
/**
 * @file
 * Meta tags module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of metatag.module.
 */
function metatag_which_feature_info() {
  $help = array();
  $table_preprocess = array();

  $help['admin/config/search/metatags/config/%'] = array(
    'component' => 'metatag',
  );

  $table_preprocess['admin/config/search/metatags'] = array(
    'component' => 'metatag',
  );

  return array(
    'help' => $help,
    'table_preprocess' => $table_preprocess,
  );
}
