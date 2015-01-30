<?php

/**
 * @file
 *   Drush commands for Collabco.
 */

/**
 * Implements hook_drush_command().
 */
function collabco_drush_drush_command() {
  $items = array();

  // The key in the $items array is the name of the command.
  $items['clear-cache-update'] = array(
    'callback' => 'collabco_drush_clear_cache_update',
    'description' => dt("Clears the cache table belonging to core's Update Manager module."),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'arguments' => array(),
    'aliases' => array('cc-up'),
  );
  return $items;
}

/**
 * Implements hook_drush_help().
 *
 * This function is called in response to: 'drush help clear-cache-update'
 */
function collabco_drush_drush_help($section) {
  switch ($section) {
    case 'drush:clear-cache-update':
      return dt("Truncates the cache_update table belonging to core's Update Manager module.");
  }
}

/**
 * Command to truncate the cache_update table.
 */
function collabco_drush_clear_cache_update() {
  // Check for module_exists('update') does not seem to be necessary.
  db_query('TRUNCATE TABLE cache_update');
  drush_log(dt('The cache_update table was cleared.'), 'success');
}
