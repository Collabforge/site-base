<?php
/**
 * @file
 * Help module integration.
 */

/**
 * Implements hook_help().
 */
function which_feature_help($path, $arg) {
  if (which_feature_access('help')) {
    // Load registry of Which feature? items.
    $items = which_feature_get_items('help');

    // Check if current page is registered for use with Which feature?.
    $menu = menu_get_item();
    if (isset($items[$menu['path']])) {
      $item = $items[$menu['path']];

      // Determine the position of the component argument.
      if (!isset($item['position']) || !is_numeric($item['position'])) {
        $args = explode('/', $menu['path']);
        $position = count($args);
        foreach ($args as $delta => $arg) {
          if ($arg == '%') {
            $position = $delta;
            break;
          }
        }
      }
      else {
        $position = $item['position'];
      }

      // Get component information.
      $component = (object) $menu['map'][$position];

      // Get delta information.
      $delta = $menu['original_map'][$position];
      if (isset($item['delta source']) && isset($component->{$item['delta source']})) {
        $delta = $component->{$item['delta source']};
      }
      if (isset($item['delta callback'])) {
        $item['delta callback']($delta, $component);
      }

      // Get module.
      $module = $item['module callback']($item, $delta, $component);
      if ($module) {
        $modules = &drupal_static('which_feature_modules');
        if (!isset($modules[$module])) {
          $modules[$module] = features_get_info('module', $module);
        }
        $module = $modules[$module];

        $name = $module->info['name'];
        if (isset($module->info['features'][$item['component']]) && (in_array($delta, $module->info['features'][$item['component']]) || in_array($delta, array_keys($module->info['features'][$item['component']])))) {
          $name = l($name, 'admin/structure/features/' . $module->name);
        }

        return t('<strong>Exported to:</strong> !name', array(
          '!name' => $name,
        ));
      }
    }
  }
}

/**
 * Defaults for the 'help' item type.
 */
function which_feature_help_defaults() {
  return array(
    'module callback' => 'which_feature_module_callback',
  );
}

/**
 * Default module callback for Which Feature? Help integration.
 */
function which_feature_module_callback($item, $delta, $component) {
  $components = which_feature_components_callback($item);
  if (isset($components[$delta]) ) {
    return $components[$delta];
  }
  return FALSE;
}
