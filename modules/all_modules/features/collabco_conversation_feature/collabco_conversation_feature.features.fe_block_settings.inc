<?php
/**
 * @file
 * collabco_conversation_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function collabco_conversation_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-28d52582802129a1e43189419c41eb29'] = array(
    'cache' => -1,
    'css_class' => 'iin-join-conversation-block',
    'custom' => 0,
    'delta' => '28d52582802129a1e43189419c41eb29',
    'module' => 'views',
    'node_types' => array(
      0 => 'closed_group',
    ),
    'pages' => '',
    'roles' => array(
      'authenticated user' => 2,
    ),
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
    'visibility' => 0,
  );

  $export['views-b29a7b66cb8fc01cc6dc10be88c2abbb'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'b29a7b66cb8fc01cc6dc10be88c2abbb',
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

  $export['views-join_the_conversation-block'] = array(
    'cache' => -1,
    'css_class' => 'iin-join-conversation-block',
    'custom' => 0,
    'delta' => 'join_the_conversation-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'custom_theme' => array(
        'region' => 'content_lower',
        'status' => 1,
        'theme' => 'custom_theme',
        'weight' => -23,
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

  return $export;
}
