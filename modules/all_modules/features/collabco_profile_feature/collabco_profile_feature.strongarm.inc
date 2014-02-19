<?php
/**
 * @file
 * collabco_profile_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function collabco_profile_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_areas_of_participant_expertise_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_areas_of_participant_expertise_pattern'] = $strongarm;

  return $export;
}
