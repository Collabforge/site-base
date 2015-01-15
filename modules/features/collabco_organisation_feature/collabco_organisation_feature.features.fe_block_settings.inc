<?php
/**
 * @file
 * collabco_organisation_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function collabco_organisation_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-0ef6861993bdfc5484027fdafe558cf8'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '0ef6861993bdfc5484027fdafe558cf8',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'partners-providers',
    'roles' => array(),
    'themes' => array(
      'custom_theme' => array(
        'region' => 'content_bottom',
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

  $export['views-112bcb4710acf1a126d5d1fb675f146c'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '112bcb4710acf1a126d5d1fb675f146c',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'partners-providers',
    'roles' => array(),
    'themes' => array(
      'custom_theme' => array(
        'region' => 'content_bottom',
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

  $export['views-organizations-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'organizations-block',
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
