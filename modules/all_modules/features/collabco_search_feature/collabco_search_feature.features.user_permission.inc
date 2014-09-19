<?php
/**
 * @file
 * collabco_search_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function collabco_search_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer search.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'search',
  );

  // Exported permission: search content.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: use advanced search.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  return $permissions;
}
