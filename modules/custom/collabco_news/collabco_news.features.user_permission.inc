<?php
/**
 * @file
 * collabco_news.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function collabco_news_user_default_permissions() {
  $permissions = array();

  // Exported permission: create news_update content.
  $permissions['create news_update content'] = array(
    'name' => 'create news_update content',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any news_update content.
  $permissions['delete any news_update content'] = array(
    'name' => 'delete any news_update content',
    'roles' => array(
      'Admin' => 'Admin',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own news_update content.
  $permissions['delete own news_update content'] = array(
    'name' => 'delete own news_update content',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any news_update content.
  $permissions['edit any news_update content'] = array(
    'name' => 'edit any news_update content',
    'roles' => array(
      'Admin' => 'Admin',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own news_update content.
  $permissions['edit own news_update content'] = array(
    'name' => 'edit own news_update content',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
