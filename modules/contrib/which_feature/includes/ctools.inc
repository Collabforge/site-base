<?php
/**
 * @file
 * Chaos tool suite (ctools) module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of ctools.module.
 */
function ctools_which_feature_info() {
  $help = array();
  $table_preprocess = array();

  if (function_exists('ctools_get_export_uis')) {
    foreach (ctools_get_export_uis() as $plugin) {
      $menu = $plugin['menu'];
      if (is_array($menu) && !empty($menu)) {
        $table_preprocess["{$menu['menu prefix']}/{$menu['menu item']}"] = array(
          'component' => $plugin['schema'],
          'components callback' => 'which_feature_ctools_components',
        );

        $edit = str_replace('%ctools_export_ui', '%', $menu['items']['edit']['path']);
        $help["{$menu['menu prefix']}/{$menu['menu item']}/{$edit}"] = array(
          'component' => $plugin['schema'],
        );
      }
    }
  }

  return array(
    'help' => $help,
    'table_preprocess' => $table_preprocess,
  );
}

/**
 * Components callback for ctools.module.
 */
function which_feature_ctools_components($item) {
  $components = array();

  $items = ctools_export_crud_load_all($item['component']);
  foreach ($items as $delta => $item) {
    if (isset($item->export_module)) {
      $components[$delta] = $item->export_module;
    }
  }

  return $components;
}
