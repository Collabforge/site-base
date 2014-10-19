<?php

/**
 * Implements hook_field_widget_form_alter().
 */
function collabco_theme_field_widget_form_alter(&$element, &$form_state, $context) {
  if (!empty($element['#field_name'])) {
    switch ($element['#field_name']) {
      case 'field_ko_file':
        unset($element['#theme_wrappers']);
        unset($element['#description']);
        $element['#file_upload_description'] = '';
        break;
      case 'field_file_ref':
        $help = t('Or select a file you have already uploaded elsewhere');
        $element['#field_prefix'] = $help;
        break;
      case 'og_group_ref':
        unset($element['#theme_wrappers']);
        break;
    }
  }
}

function collabco_theme_field_widget_file_generic_form_alter(&$element, &$form_state, $context) {
  return;
}

/**
 * Implements hook_form_alter().
 *
 * Adds bootstrap CSS classes to common buttons.
 */
function collabco_theme_form_alter(&$form, &$form_state, $form_id) {
  $form['actions']['submit']['#attributes']['class'][] = 'form-btn-success';
  $form['actions']['delete']['#attributes']['class'][] = 'form-btn-danger';
  $form['actions']['cancel']['#attributes']['class'][] = 'form-btn-danger';  
}

function collabco_theme_preprocess_flag(&$variables) {
  $variables['flag_classes_array'][] ='btn btn-warning';
}

/*
 * Implements hook_menu_link
 * Copy of open_framework_menu_link(). just applying it to all menus
 */
/*function collabco_theme_menu_link(array $vars) {
  $element = $vars['element'];

  $link_theming_functions = (array)$element['#theme'];

  if (_collabco_theme_menu_is_dropdown($link_theming_functions)) {
    $sub_menu = '';
    if ($element['#below']) {
      // Add our own wrapper
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';

      // Check if this element is nested within another
      if ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] > 1)) {
      // Generate as dropdown submenu
        $element['#attributes']['class'][] = 'dropdown-submenu';
      }
      else {
        // Generate as standard dropdown
        $element['#attributes']['class'][] = 'dropdown';
        $element['#localized_options']['html'] = TRUE;
        $element['#title'] .= ' <span class="caret"></span>';
      }

      // Set dropdown trigger element to # to prevent inadvertant page loading with submenu click
      $element['#localized_options']['attributes']['data-target'] = '#';
    }

    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";

  } else {
    $element = $vars['element'];
    $sub_menu = '';

    if ($element['#below']) {
      $sub_menu = drupal_render($element['#below']);
    }
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
  }
}

function _collabco_theme_menu_is_dropdown($link_theming_functions) {
  // @FIXME: may need refinement, see open_framework/templates/template.php
  foreach ($link_theming_functions as $function_name) {
    if (strpos($function_name, '_book_')) {
      return FALSE;
    }
  }
  return TRUE;
}

*/

// in template.php for your theme directory.
 
// Show a message on every page.
collabco_show_sitewide_notification_message();
 
// The message is pulled from a custom defined variable.
function collabco_show_sitewide_notification_message() {
  $notice = variable_get('collabco_sitewide_notification', '');
  if ($notice != '') {
    drupal_set_message($notice, 'warning');
  }
}
