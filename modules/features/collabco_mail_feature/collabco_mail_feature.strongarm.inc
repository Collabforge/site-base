<?php
/**
 * @file
 * collabco_mail_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function collabco_mail_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mail_system';
  $strongarm->value = array(
    'default-system' => 'MandrillMailSystem',
    'mandrill_test' => 'MandrillMailSystem',
    'mimemail' => 'MandrillMailSystem',
    'views_send_direct' => 'MandrillMailSystem',
  );
  $export['mail_system'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_mail';
  $strongarm->value = 'contact@collabforge.com';
  $export['site_mail'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_cancel_confirm_body';
  $strongarm->value = 'Hello [user:name],<br>
<br>
A request to cancel your account has been made at [site:name].<br>
<br>
You may now cancel your account on [site:url-brief] by clicking this link or copying and pasting it into your browser:<br>
<br>
[user:cancel-url]<br>
<br>
NOTE: The cancellation of your account is not reversible.<br>
<br>
This link expires in one day and nothing will happen if it is not used.<br>
<br>
Kind Regards,<br>
The [site:name] team<br>';
  $export['user_mail_cancel_confirm_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_cancel_confirm_subject';
  $strongarm->value = 'Account cancellation request for [user:name] at the [site:name]';
  $export['user_mail_cancel_confirm_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_custom_mail_body';
  $strongarm->value = '[user:name],

Thanks for choosing us to assist you. We would like to be of assistance in any way we can and hope you have a positive and rewarding experience with our team.

You may contact us directly.

We look forward to serving you!

--  [site:name] team';
  $export['user_mail_custom_mail_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_custom_mail_subject';
  $strongarm->value = 'Welcome to [site:name]';
  $export['user_mail_custom_mail_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_password_reset_body';
  $strongarm->value = 'Hello [user:name],<br>
<br>
A request to reset the password for your account has been made at the [site:name].<br>
<br>
You may now log in by clicking this link or copying and pasting it to your browser:<br>
<br>
[user:one-time-login-url]<br>
<br>
This link can only be used once to log in and will lead you to a page where you can set your password. It expires after one day and nothing will happen if it\'s not used.<br>
<br>
Kind Regards,<br>
The [site:name] team<br>';
  $export['user_mail_password_reset_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_password_reset_subject';
  $strongarm->value = 'Replacement login information for [user:name] at the [site:name]';
  $export['user_mail_password_reset_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_admin_created_body';
  $strongarm->value = 'Hello [user:name],<br>
<br>
We\'ve created a pre-approved account for you on the [site:name]. You may now log in by clicking this link or copying and pasting it to your browser:<br>
<br>
[user:one-time-login-url]<br>
<br>
This link can only be used once to log in and will lead you to a page where you can set your password.<br>
<br>
After setting your password, you will be able to log in at [site:login-url] in the future using:<br>
<br>
username: [user:name]<br>
password: [the password that you will create after you click the link above]<br>
<br>
Kind Regards,<br>
The [site:name] team';
  $export['user_mail_register_admin_created_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_admin_created_subject';
  $strongarm->value = 'Welcome to the [site:name]. We\'ve created an account for you.';
  $export['user_mail_register_admin_created_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_no_approval_required_body';
  $strongarm->value = 'Hello [user:name],<br>
<br>
Thank you for registering at [site:name]. You may now log in by clicking this link or copying and pasting it to your browser:<br>
<br>
[user:one-time-login-url]<br>
<br>
This link can only be used once to log in and will lead you to a page where you can set your password.<br>
<br>
After setting your password, you will be able to log in at [site:login-url] in the future using:<br>
<br>
username: [user:name]<br>
password: [the password that you will create after you click the link above]<br>
<br>
Kind Regards,<br>
The [site:name] team<br>';
  $export['user_mail_register_no_approval_required_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_no_approval_required_subject';
  $strongarm->value = 'Welcome to the [site:name]. You are now ready to access the site';
  $export['user_mail_register_no_approval_required_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_pending_approval_body';
  $strongarm->value = 'Hello [user:name],<br>
<br>
Thank you for registering at the [site:name]. Your application for an account is currently pending approval. Once it has been approved, you will receive another e-mail containing information about how to log in, set your password, and other details.<br>
<br>
Kind Regards,<br>
The [site:name] team';
  $export['user_mail_register_pending_approval_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_pending_approval_subject';
  $strongarm->value = 'Hi [user:name], your account at the [site:name] is awaiting approval';
  $export['user_mail_register_pending_approval_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_activated_body';
  $strongarm->value = 'Hello [user:name],<br>
<br>
Recently you applied for an account on the [site:name]. Your account has been approved. Thank you for your patience.<br>
<br>
You may now log in by clicking this link or copying and pasting it to your browser:<br>
<br>
[user:one-time-login-url]<br>
<br>
This link can only be used once to log in and will lead you to a page where you can set your password.<br>
<br>
After setting your password, you will be able to log in at [site:login-url] in the future using:<br>
<br>
username: [user:name]<br>
password: [the password that you will create after you click the link above]<br>
<br>
Kind Regards,<br>
The [site:name] team';
  $export['user_mail_status_activated_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_activated_notify';
  $strongarm->value = 1;
  $export['user_mail_status_activated_notify'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_activated_subject';
  $strongarm->value = 'Welcome to the [site:name]. Your account has been approved.';
  $export['user_mail_status_activated_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_blocked_body';
  $strongarm->value = 'Hello [user:name],<br>
<br>
An administrator on the [site:name] has blocked your account.<br>
<br>
If this is unexpected or you have further questions, feel free to contact us at contact@collabforge.com<br>
<br>
Kind Regards,<br>
The [site:name] team<br>';
  $export['user_mail_status_blocked_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_blocked_notify';
  $strongarm->value = 1;
  $export['user_mail_status_blocked_notify'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_blocked_subject';
  $strongarm->value = 'Hello [user:name], your account at the [site:name] has been blocked';
  $export['user_mail_status_blocked_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_canceled_body';
  $strongarm->value = 'Hello [user:name],<br>
<br>
Your account on the [site:name] has been canceled. You can reach us at contact@support.au with any questions.<br>
<br>
Kind Regards,<br>
The [site:name] team<br>';
  $export['user_mail_status_canceled_body'] = $strongarm;

  return $export;
}
