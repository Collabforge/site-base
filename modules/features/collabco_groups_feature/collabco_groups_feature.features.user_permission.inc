<?php
/**
 * @file
 * collabco_groups_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function collabco_groups_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: create closed_group content.
  $permissions['create closed_group content'] = array(
    'name' => 'create closed_group content',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: create group content.
  $permissions['create group content'] = array(
    'name' => 'create group content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any closed_group content.
  $permissions['delete any closed_group content'] = array(
    'name' => 'delete any closed_group content',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any group content.
  $permissions['delete any group content'] = array(
    'name' => 'delete any group content',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own closed_group content.
  $permissions['delete own closed_group content'] = array(
    'name' => 'delete own closed_group content',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own group content.
  $permissions['delete own group content'] = array(
    'name' => 'delete own group content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any closed_group content.
  $permissions['edit any closed_group content'] = array(
    'name' => 'edit any closed_group content',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any group content.
  $permissions['edit any group content'] = array(
    'name' => 'edit any group content',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own closed_group content.
  $permissions['edit own closed_group content'] = array(
    'name' => 'edit own closed_group content',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own group content.
  $permissions['edit own group content'] = array(
    'name' => 'edit own group content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
