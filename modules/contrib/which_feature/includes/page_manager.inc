<?php
/**
 * @file
 * Page Manager module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of page_manager.module.
 */
function page_manager_which_feature_info() {
  $help = array();
  $table_preprocess = array();

  $help['admin/structure/pages/edit/%'] = array(
    'component' => 'page_manager_pages',
    'delta source' => 'subtask_id',
  );

  $table_preprocess['admin/structure/pages'] = array(
    'component' => 'page_manager_pages',
    'components callback' => 'which_feature_page_manager_components',
  );

  return array(
    'help' => $help,
    'table_preprocess' => $table_preprocess,
  );
}

/**
 * Components callback for page_manager.module.
 */
function which_feature_page_manager_components($item) {
  $components = array();

  $tasks = page_manager_get_tasks_by_type('page');
  foreach ($tasks as $task) {
    if (isset($task['subtasks']) && $task['subtasks'] && isset($task['subtasks callback'])) {
      $subtasks = $task['subtasks callback']($task);
      foreach ($subtasks as $subtask) {
        if (!isset($subtask['subtask'])) {
          $components["{$task['name']}-{$subtask['name']}"] = $task['module'];
        }
        elseif (isset($subtask['subtask']->export_module)) {
          $components["{$task['name']}-{$subtask['name']}"] = $subtask['subtask']->export_module;
        }
      }
    }
    else {
      $components[$task['name']] = $task['module'];
    }
  }

  return $components;
}
