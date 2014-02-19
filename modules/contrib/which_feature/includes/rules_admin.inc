<?php
/**
 * @file
 * Rules UI module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of rules_admin.module.
 */
function rules_admin_which_feature_info() {
  $help = array();
  $table_preprocess = array();

  $help['admin/config/workflow/rules/reaction/manage/%'] = array(
    'component' => 'rules_config',
    'delta source' => 'name',
    'module callback' => 'which_feature_rules_module',
  );

  $table_preprocess['admin/config/workflow/rules'] = array(
    'component' => 'rules_config',
    'components callback' => 'which_feature_rules_components',
    'delta callback' => 'which_feature_rules_delta',
  );
  $table_preprocess['admin/config/workflow/rules/reaction'] = $table_preprocess['admin/config/workflow/rules'];

  return array(
    'help' => $help,
    'table_preprocess' => $table_preprocess,
  );
}

/**
 * Module callback for rules_admin.module.
 */
function which_feature_rules_module($item, $delta, $component) {
  if ($component->status != ENTITY_CUSTOM) {
    return $component->module;
  }
}

/**
 * Components callback for rules_admin.module.
 */
function which_feature_rules_components($item) {
  $components = array();

  $rules = entity_load('rules_config');
  foreach ($rules as $rule) {
    if ($rule->status != ENTITY_CUSTOM) {
      $components[$rule->name] = $rule->module;
    }
  }

  return $components;
}

/**
 * Delta callback for rules_admin.module.
 */
function which_feature_rules_delta(&$delta, $row) {
  // @TODO - Deal with translation string.
  if (preg_match('/Machine name: (.*)/', $row[0]['data']['description']['settings']['machine_name']['#markup'], $matches)) {
    $delta = $matches[1];
  }
}
