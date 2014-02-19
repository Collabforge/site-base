<?php
/**
 * @file
 * collabco_knowledge_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function collabco_knowledge_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: create knowledge_object content.
  $permissions['create knowledge_object content'] = array(
    'name' => 'create knowledge_object content',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any knowledge_object content.
  $permissions['delete any knowledge_object content'] = array(
    'name' => 'delete any knowledge_object content',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own knowledge_object content.
  $permissions['delete own knowledge_object content'] = array(
    'name' => 'delete own knowledge_object content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any knowledge_object content.
  $permissions['edit any knowledge_object content'] = array(
    'name' => 'edit any knowledge_object content',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own knowledge_object content.
  $permissions['edit own knowledge_object content'] = array(
    'name' => 'edit own knowledge_object content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: entityconnect add button.
  $permissions['entityconnect add button'] = array(
    'name' => 'entityconnect add button',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'entityconnect',
  );

  // Exported permission: entityconnect edit button.
  $permissions['entityconnect edit button'] = array(
    'name' => 'entityconnect edit button',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'entityconnect',
  );

  return $permissions;
}
