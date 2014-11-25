<?php
/**
 * @file
 * collabco_knowledge_feature.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function collabco_knowledge_feature_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:closed_group:create knowledge_object content'
  $permissions['node:closed_group:create knowledge_object content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:closed_group:delete any knowledge_object content'
  $permissions['node:closed_group:delete any knowledge_object content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:closed_group:delete own knowledge_object content'
  $permissions['node:closed_group:delete own knowledge_object content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:closed_group:update any knowledge_object content'
  $permissions['node:closed_group:update any knowledge_object content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:closed_group:update own knowledge_object content'
  $permissions['node:closed_group:update own knowledge_object content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:create knowledge_object content'
  $permissions['node:group:create knowledge_object content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:delete any knowledge_object content'
  $permissions['node:group:delete any knowledge_object content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:delete own knowledge_object content'
  $permissions['node:group:delete own knowledge_object content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:group:update any knowledge_object content'
  $permissions['node:group:update any knowledge_object content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:update own knowledge_object content'
  $permissions['node:group:update own knowledge_object content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  return $permissions;
}
