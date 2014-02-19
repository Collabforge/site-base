<?php
/**
 * @file
 * collabco_groups_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function collabco_groups_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-group_users-block'] = array(
    'cache' => -1,
    'css_class' => 'sidetheme group-members',
    'custom' => 0,
    'delta' => 'group_users-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/*/edit
user/*/edit',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'custom_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'custom_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Group Members',
    'visibility' => 0,
  );

  return $export;
}
