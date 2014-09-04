<?php
/**
 * @file
 * collabco_groups_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function collabco_groups_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function collabco_groups_feature_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function collabco_groups_feature_node_info() {
  $items = array(
    'closed_group' => array(
      'name' => t('Closed Group'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Group Name'),
      'help' => '',
    ),
  );
  return $items;
}
