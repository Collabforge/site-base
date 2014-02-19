<?php

/**
 * @file
 * Declare Profile Complete Percent fields, filters and sorts.
 */

/**
 * Implements hook_views_data_alter().
 *
 * Here we define pseudo-fields for the {profile} table of the Profile2 module.
 */
function pcp_views_data_alter(&$data) {

  $data['profile']['profile_completeness'] = array(
    'title' => t('Completeness'),
    'help' => t('Profile completeness expressed as a percentage 0..100'),
    'field' => array(
      'handler' => 'pcp_handler_field_profile_completeness',
      'click sortable' => TRUE,
    ),
    // Cannot support sort or filter as 'profile_completeness' cannot be
    // expressed throug WHERE or ORDER BY clauses.
  );

}
