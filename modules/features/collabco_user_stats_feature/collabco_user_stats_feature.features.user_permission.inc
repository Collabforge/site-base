<?php
/**
 * @file
 * collabco_user_stats_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function collabco_user_stats_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: access statistics.
  $permissions['access statistics'] = array(
    'name' => 'access statistics',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'statistics',
  );

  // Exported permission: administer google analytics.
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: administer statistics.
  $permissions['administer statistics'] = array(
    'name' => 'administer statistics',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'statistics',
  );

  // Exported permission: opt-in or out of tracking.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: use PHP for tracking visibility.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: view post access counter.
  $permissions['view post access counter'] = array(
    'name' => 'view post access counter',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'statistics',
  );

  return $permissions;
}
