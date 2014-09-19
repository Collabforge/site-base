<?php
/**
 * @file
 * collabco_profile_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function collabco_profile_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-301386dba33cbdacd710e75c8357d743'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '301386dba33cbdacd710e75c8357d743',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'community',
    'roles' => array(),
    'themes' => array(
      'custom_theme' => array(
        'region' => '',
        'status' => 0,
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
    'title' => '',
    'visibility' => 1,
  );

  $export['views-all_users-block'] = array(
    'cache' => -1,
    'css_class' => 'iin-feature',
    'custom' => 0,
    'delta' => 'all_users-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'community',
    'roles' => array(),
    'themes' => array(
      'custom_theme' => array(
        'region' => 'content_lower',
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
    'title' => '',
    'visibility' => 1,
  );

  $export['views-featured_users-team_block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'featured_users-team_block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'custom_theme' => array(
        'region' => '',
        'status' => 0,
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
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
