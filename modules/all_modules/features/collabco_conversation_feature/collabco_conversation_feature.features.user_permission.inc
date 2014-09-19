<?php
/**
 * @file
 * collabco_conversation_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function collabco_conversation_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: create conversation content.
  $permissions['create conversation content'] = array(
    'name' => 'create conversation content',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any conversation content.
  $permissions['delete any conversation content'] = array(
    'name' => 'delete any conversation content',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own conversation content.
  $permissions['delete own conversation content'] = array(
    'name' => 'delete own conversation content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any conversation content.
  $permissions['edit any conversation content'] = array(
    'name' => 'edit any conversation content',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own conversation content.
  $permissions['edit own conversation content'] = array(
    'name' => 'edit own conversation content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
