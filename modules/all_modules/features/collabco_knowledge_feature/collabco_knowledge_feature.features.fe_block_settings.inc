<?php
/**
 * @file
 * collabco_knowledge_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function collabco_knowledge_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views--exp-knowledge_repository-page'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '-exp-knowledge_repository-page',
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

  $export['views-innovation_at_work-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'innovation_at_work-block',
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

  $export['views-knowledge_repository-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'knowledge_repository-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'uploaded-files',
    'roles' => array(),
    'themes' => array(
      'custom_theme' => array(
        'region' => 'content_upper',
        'status' => 1,
        'theme' => 'custom_theme',
        'weight' => -34,
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

  $export['views-nodequeue_1-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'nodequeue_1-block',
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

  $export['views-recent_files-block'] = array(
    'cache' => -1,
    'css_class' => 'sidetheme paddingreset',
    'custom' => 0,
    'delta' => 'recent_files-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'group/*
services',
    'roles' => array(),
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
    'title' => 'Library Items',
    'visibility' => 0,
  );

  $export['views-recent_files-group_block'] = array(
    'cache' => -1,
    'css_class' => 'sidetheme paddingreset',
    'custom' => 0,
    'delta' => 'recent_files-group_block',
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
    'title' => 'Tier A Library',
    'visibility' => 0,
  );

  return $export;
}
