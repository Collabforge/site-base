<?php
/**
 * @file
 * collabco_conversation_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function collabco_conversation_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function collabco_conversation_feature_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function collabco_conversation_feature_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: join_the_conversation_queue
  $nodequeues['join_the_conversation_queue'] = array(
    'name' => 'join_the_conversation_queue',
    'title' => 'join the conversation queue',
    'subqueue_title' => '',
    'size' => 0,
    'link' => 'add to Join the Conversation',
    'link_remove' => 'remove from Join the Conversation',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'conversation',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function collabco_conversation_feature_node_info() {
  $items = array(
    'conversation' => array(
      'name' => t('Conversation'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Topic'),
      'help' => '',
    ),
  );
  return $items;
}
