<?php
/**
 * @file
 * collabco_knowledge_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function collabco_knowledge_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function collabco_knowledge_feature_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function collabco_knowledge_feature_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: innovation_at_work
  $nodequeues['innovation_at_work'] = array(
    'name' => 'innovation_at_work',
    'title' => 'Innovation at Work',
    'subqueue_title' => '',
    'size' => 0,
    'link' => 'add to Innovation at Work queue',
    'link_remove' => 'remove from Innovation at Work queue',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'knowledge_object',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function collabco_knowledge_feature_node_info() {
  $items = array(
    'knowledge_object' => array(
      'name' => t('File'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
