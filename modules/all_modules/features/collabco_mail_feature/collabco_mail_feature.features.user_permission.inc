<?php
/**
 * @file
 * collabco_mail_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function collabco_mail_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer mailsystem.
  $permissions['administer mailsystem'] = array(
    'name' => 'administer mailsystem',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'mailsystem',
  );

  // Exported permission: administer mandrill.
  $permissions['administer mandrill'] = array(
    'name' => 'administer mandrill',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'mandrill',
  );

  // Exported permission: administer views_send.
  $permissions['administer views_send'] = array(
    'name' => 'administer views_send',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'views_send',
  );

  // Exported permission: configure mandrill templates.
  $permissions['configure mandrill templates'] = array(
    'name' => 'configure mandrill templates',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'mandrill_template',
  );

  // Exported permission: mass mailing with views_send.
  $permissions['mass mailing with views_send'] = array(
    'name' => 'mass mailing with views_send',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'views_send',
  );

  return $permissions;
}
