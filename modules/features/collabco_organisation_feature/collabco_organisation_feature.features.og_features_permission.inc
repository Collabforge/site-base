<?php
/**
 * @file
 * collabco_organisation_feature.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function collabco_organisation_feature_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:closed_group:create organisation content'
  $permissions['node:closed_group:create organisation content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:closed_group:delete any organisation content'
  $permissions['node:closed_group:delete any organisation content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:closed_group:delete own organisation content'
  $permissions['node:closed_group:delete own organisation content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:closed_group:update any organisation content'
  $permissions['node:closed_group:update any organisation content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:closed_group:update field_address field'
  $permissions['node:closed_group:update field_address field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:closed_group:update field_industry field'
  $permissions['node:closed_group:update field_industry field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:closed_group:update field_member_type field'
  $permissions['node:closed_group:update field_member_type field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:closed_group:update field_organisation_image field'
  $permissions['node:closed_group:update field_organisation_image field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:closed_group:update field_organisation_type field'
  $permissions['node:closed_group:update field_organisation_type field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:closed_group:update field_website field'
  $permissions['node:closed_group:update field_website field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:closed_group:update own organisation content'
  $permissions['node:closed_group:update own organisation content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:closed_group:view field_address field'
  $permissions['node:closed_group:view field_address field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:closed_group:view field_industry field'
  $permissions['node:closed_group:view field_industry field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:closed_group:view field_member_type field'
  $permissions['node:closed_group:view field_member_type field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:closed_group:view field_organisation_image field'
  $permissions['node:closed_group:view field_organisation_image field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:closed_group:view field_organisation_type field'
  $permissions['node:closed_group:view field_organisation_type field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:closed_group:view field_website field'
  $permissions['node:closed_group:view field_website field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:create organisation content'
  $permissions['node:group:create organisation content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete any organisation content'
  $permissions['node:group:delete any organisation content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete own organisation content'
  $permissions['node:group:delete own organisation content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update any organisation content'
  $permissions['node:group:update any organisation content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update field_address field'
  $permissions['node:group:update field_address field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update field_industry field'
  $permissions['node:group:update field_industry field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update field_member_type field'
  $permissions['node:group:update field_member_type field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update field_organisation_image field'
  $permissions['node:group:update field_organisation_image field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update field_organisation_type field'
  $permissions['node:group:update field_organisation_type field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update field_website field'
  $permissions['node:group:update field_website field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update own organisation content'
  $permissions['node:group:update own organisation content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view field_address field'
  $permissions['node:group:view field_address field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view field_industry field'
  $permissions['node:group:view field_industry field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view field_member_type field'
  $permissions['node:group:view field_member_type field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view field_organisation_image field'
  $permissions['node:group:view field_organisation_image field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view field_organisation_type field'
  $permissions['node:group:view field_organisation_type field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:view field_website field'
  $permissions['node:group:view field_website field'] = array(
    'roles' => array(),
  );

  return $permissions;
}
