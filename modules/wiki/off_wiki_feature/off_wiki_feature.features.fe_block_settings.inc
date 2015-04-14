<?php
/**
 * @file
 * off_wiki_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function off_wiki_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['book_explorer-book_explorer'] = array(
    'cache' => 5,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'book_explorer',
    'module' => 'book_explorer',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'custom_zurb' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'custom_zurb',
        'weight' => -15,
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

  $export['views-wiki_list-group_block'] = array(
    'cache' => -1,
    'css_class' => 'sidetheme',
    'custom' => 0,
    'delta' => 'wiki_list-group_block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'custom_zurb' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'custom_zurb',
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
