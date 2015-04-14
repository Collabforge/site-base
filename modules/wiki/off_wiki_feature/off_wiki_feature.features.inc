<?php
/**
 * @file
 * off_wiki_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function off_wiki_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function off_wiki_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function off_wiki_feature_flag_default_flags() {
  $flags = array();
  // Exported flag: "Wikis".
  $flags['follow_wiki'] = array(
    'entity_type' => 'node',
    'title' => 'Wikis',
    'global' => 0,
    'types' => array(
      0 => 'book',
    ),
    'flag_short' => 'Follow Whole Wiki',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unfollow Whole Wiki',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'print' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'off_wiki_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function off_wiki_feature_node_info() {
  $items = array(
    'book' => array(
      'name' => t('Wiki'),
      'base' => 'node_content',
      'description' => t('<em>Wikis (Books)</em> have a built-in hierarchical navigation. Use for handbooks or tutorials.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
