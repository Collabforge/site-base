<?php

/**
 * @file
 * Provide short-cut handlers for Viewd data that is hard to retrieve.
 */

/**
 * @defgroup views handlers
 *
 * @{
 */

/**
 * Implements of hook_views_data_alter().
 */
function collabco_views_views_data_alter(&$data) {

  $data['users']['comments_posted'] = array(
    'title' => t('Comments posted'),
    'help' =>t('Number of comments posted by user.'),
    'field' => array(
      'handler' => 'collabco_views_handler_field_user_comments_posted',
    ),
  );

  $data['users']['flag_count'] = array(
    'title' => t('Flag count, all flags') ,
    'help' => t('Total number of items flagged by user via any flag.'),
    'field' => array(
      'handler' => 'collabco_views_handler_field_user_flag_count',
      'click sortable' => TRUE,
    ),
  );
  $data['users']['login_count'] = array(
    'title' => t('Login count') ,
    'help' => t('Total number of logins by any given user'),
    'field' => array(
      'handler' => 'collabco_views_handler_field_user_login_count',
      'click sortable' => TRUE,
    ),
  );
  $data['users']['flag_count_1'] = array(
    'title' => t('Flag1 count') ,
    'help' => t('Number of items flagged by user via flag 1.'),
    'field' => array(
      'handler' => 'collabco_views_handler_field_user_flag1_count',
    ),
  );
  $data['users']['flag_count_2'] = array(
    'title' => t('Flag2 count') ,
    'help' => t('Number of items flagged by user via flag 2.'),
    'field' => array(
      'handler' => 'collabco_views_handler_field_user_flag2_count',
    ),
  );

  $data['users']['groups_hosted'] = array(
    'title' => t('No. groups hosted') ,
    'help' => t('Number of groups hosted.'),
    'field' => array(
      'handler' => 'collabco_views_handler_field_user_groups_hosted',
    ),
  );

  $data['users']['groups_joined'] = array(
    'title' => t('No. groups joined') ,
    'help' => t('Number of groups joined.'),
    'field' => array(
      'handler' => 'collabco_views_handler_field_user_groups_joined',
    ),
  );

}

/**
 * @}
 */
