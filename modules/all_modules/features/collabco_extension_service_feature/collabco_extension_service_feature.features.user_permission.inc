<?php
/**
 * @file
 * collabco_extension_service_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function collabco_extension_service_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: create service content.
  $permissions['create service content'] = array(
    'name' => 'create service content',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any service content.
  $permissions['delete any service content'] = array(
    'name' => 'delete any service content',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own service content.
  $permissions['delete own service content'] = array(
    'name' => 'delete own service content',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any service content.
  $permissions['edit any service content'] = array(
    'name' => 'edit any service content',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own service content.
  $permissions['edit own service content'] = array(
    'name' => 'edit own service content',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
