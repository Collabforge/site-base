<?php
/**
 * @file
 * collabco_profile_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function collabco_profile_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function collabco_profile_feature_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_profile2_type().
 */
function collabco_profile_feature_default_profile2_type() {
  $items = array();
  $items['profile'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "profile",
    "label" : "Profile",
    "weight" : "0",
    "data" : { "registration" : 1, "use_page" : 0 },
    "rdf_mapping" : []
  }');
  return $items;
}
