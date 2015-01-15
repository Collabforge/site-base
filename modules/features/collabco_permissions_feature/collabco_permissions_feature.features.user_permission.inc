<?php
/**
 * @file
 * collabco_permissions_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function collabco_permissions_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration menu.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: access administration pages.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'system',
  );

  // Exported permission: access all views.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'views',
  );

  // Exported permission: access comments.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: access contextual links.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'contextual',
  );

  // Exported permission: access devel information.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'devel',
  );

  // Exported permission: access site in maintenance mode.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: access site reports.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: administer CAPTCHA settings.
  $permissions['administer CAPTCHA settings'] = array(
    'name' => 'administer CAPTCHA settings',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'captcha',
  );

  // Exported permission: administer Terms and Conditions.
  $permissions['administer Terms and Conditions'] = array(
    'name' => 'administer Terms and Conditions',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'legal',
  );

  // Exported permission: administer actions.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: administer block classes.
  $permissions['administer block classes'] = array(
    'name' => 'administer block classes',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'block_class',
  );

  // Exported permission: administer blocks.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'block',
  );

  // Exported permission: administer ckeditor.
  $permissions['administer ckeditor'] = array(
    'name' => 'administer ckeditor',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: administer comments.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'comment',
  );

  // Exported permission: administer content types.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: administer features.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'features',
  );

  // Exported permission: administer filters.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'filter',
  );

  // Exported permission: administer image styles.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'image',
  );

  // Exported permission: administer masquerade.
  $permissions['administer masquerade'] = array(
    'name' => 'administer masquerade',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: administer menu.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'menu',
  );

  // Exported permission: administer message types.
  $permissions['administer message types'] = array(
    'name' => 'administer message types',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'message',
  );

  // Exported permission: administer modules.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: administer nodequeue.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: administer nodes.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: administer pathauto.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: administer permissions.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: administer pre-approved.
  $permissions['administer pre-approved'] = array(
    'name' => 'administer pre-approved',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'register_preapproved',
  );

  // Exported permission: administer pre-approved roles.
  $permissions['administer pre-approved roles'] = array(
    'name' => 'administer pre-approved roles',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'register_preapproved',
  );

  // Exported permission: administer realname.
  $permissions['administer realname'] = array(
    'name' => 'administer realname',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'realname',
  );

  // Exported permission: administer recaptcha.
  $permissions['administer recaptcha'] = array(
    'name' => 'administer recaptcha',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'recaptcha',
  );

  // Exported permission: administer site configuration.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: administer software updates.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: administer string overrides.
  $permissions['administer string overrides'] = array(
    'name' => 'administer string overrides',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'stringoverrides',
  );

  // Exported permission: administer taxonomy.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: administer themes.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: administer url aliases.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'path',
  );

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'user',
  );

  // Exported permission: administer uuid.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'uuid',
  );

  // Exported permission: administer views.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'views',
  );

  // Exported permission: block IP addresses.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: bypass node access.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: cancel account.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: change own username.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: create basic_page content.
  $permissions['create basic_page content'] = array(
    'name' => 'create basic_page content',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: create messages.
  $permissions['create messages'] = array(
    'name' => 'create messages',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'message',
  );

  // Exported permission: create url aliases.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'path',
  );

  // Exported permission: customize ckeditor.
  $permissions['customize ckeditor'] = array(
    'name' => 'customize ckeditor',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: delete any basic_page content.
  $permissions['delete any basic_page content'] = array(
    'name' => 'delete any basic_page content',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own basic_page content.
  $permissions['delete own basic_page content'] = array(
    'name' => 'delete own basic_page content',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete revisions.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: display drupal links.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: edit any basic_page content.
  $permissions['edit any basic_page content'] = array(
    'name' => 'edit any basic_page content',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own basic_page content.
  $permissions['edit own basic_page content'] = array(
    'name' => 'edit own basic_page content',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own comments.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: execute php code.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: flush caches.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: manage features.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'features',
  );

  // Exported permission: manipulate all queues.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: manipulate queues.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: masquerade as admin.
  $permissions['masquerade as admin'] = array(
    'name' => 'masquerade as admin',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: masquerade as user.
  $permissions['masquerade as user'] = array(
    'name' => 'masquerade as user',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: notify of path changes.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: post comments.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: revert revisions.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: select account cancellation method.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: show format selection for comment.
  $permissions['show format selection for comment'] = array(
    'name' => 'show format selection for comment',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for message.
  $permissions['show format selection for message'] = array(
    'name' => 'show format selection for message',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for message_type.
  $permissions['show format selection for message_type'] = array(
    'name' => 'show format selection for message_type',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for message_type_category.
  $permissions['show format selection for message_type_category'] = array(
    'name' => 'show format selection for message_type_category',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for node.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for og_membership.
  $permissions['show format selection for og_membership'] = array(
    'name' => 'show format selection for og_membership',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for og_membership_type.
  $permissions['show format selection for og_membership_type'] = array(
    'name' => 'show format selection for og_membership_type',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for profile2.
  $permissions['show format selection for profile2'] = array(
    'name' => 'show format selection for profile2',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for taxonomy_term.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for user.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format tips.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show more format tips link.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: skip CAPTCHA.
  $permissions['skip CAPTCHA'] = array(
    'name' => 'skip CAPTCHA',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'captcha',
  );

  // Exported permission: skip comment approval.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: switch users.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'devel',
  );

  // Exported permission: use text format filtered_html.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format full_html.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format php_code.
  $permissions['use text format php_code'] = array(
    'name' => 'use text format php_code',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'filter',
  );

  // Exported permission: view Terms and Conditions.
  $permissions['view Terms and Conditions'] = array(
    'name' => 'view Terms and Conditions',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'legal',
  );

  // Exported permission: view date repeats.
  $permissions['view date repeats'] = array(
    'name' => 'view date repeats',
    'roles' => array(),
    'module' => 'date_repeat_field',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: view revisions.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: view the administration theme.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Admin' => 'Admin',
      'Community Moderator' => 'Community Moderator',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'system',
  );

  return $permissions;
}
