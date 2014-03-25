<?php
/**
 * @file
 * collabco_mentions.features.inc
 */

/**
 * Implements hook_filter_default_formats_alter().
 */
function collabco_mentions_filter_default_formats_alter(&$data) {
  if (isset($data['email'])) {
    $data['email']['filters']['filter_mentions'] = array(
      'settings' => array(),
      'status' => 1,
      'weight' => 0,
    ); /* WAS: '' */
  }
}
