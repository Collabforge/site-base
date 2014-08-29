<?php
/**
 * @file
 * collabco_mentions.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function collabco_mentions_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: filter
  $overrides["filter.email.filters|filter_mentions"] = array(
    'settings' => array(),
    'status' => 1,
    'weight' => 0,
  );

 return $overrides;
}
