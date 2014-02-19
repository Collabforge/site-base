<?php

/**
 * @file
 * Admin interface for the pcp module
 */

/**
 * Form builder; Configure PCP fields for core profile.
 *
 * @ingroup forms
 */
function pcp_admin_settings($form, &$form_state) {
  $form['general_settings'] = array(
    '#type' => 'fieldset',
    '#title' => 'General Settings',
  );
  $form['general_settings']['hide_block_on_complete'] = array(
    '#type' => 'checkbox',
    '#title' => 'Hide When Complete',
    '#default_value' => variable_get('pcp_hide_block_on_complete', 0),
    '#description' => t('When a user reaches 100% complete of their profile, do you want the profile complete percent block to go away or the completeness field to be hidden in Views? If so, check this box on.'),
  );
  if (variable_get('user_pictures', 0)) {
    $form['general_settings']['pcp_enable_user_picture'] = array(
      '#type' => 'checkbox',
      '#title' => 'Enable User Picture Support',
      '#default_value' => variable_get('pcp_enable_user_picture', 0),
      '#description' => t('Picture support has been turned on, do you want to make it required as part of Profile Complete Percent? Checking this box will make it required.'),
    );
  }

  $form['profile_field_settings'] = array(
    '#type' => 'fieldset',
    '#title' => 'Core Profile Field Settings',
    '#description' => t('Checking a profile field below will add that field to the logic of the complete percentage. Please note that these are simply core profile fields, not fields attached to Profile2 profiles.'),
  );

  $options = array();
  $settings = pcp_admin_settings_form_data('user');
  foreach ($settings['profile_fields_options'] as $fiid => $field_name) {
    $field_info = field_info_instance('user', $field_name, 'user');
    $options[$fiid] = $field_info['label'];
  }

  $form['profile_field_settings']['profile_fields'] = array(
    '#title' => t('Profile Fields'),
    '#description' => empty($options) ? t('There are no profile fields enabled. Please <a href="@link">add some profile fields</a> first.', array('@link' => url('admin/config/people/accounts/fields'))) : t('Checking a profile field below will add that field to the logic of the complete percentage.'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => array_flip($settings['default_values']),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Function that sets up parameters to be used
 * when the pcp_admin_settings_form() function
 * is executed.
 *
 * @param $entity_type
 *   this parameter indicates the source of the profile fields. accepted
 *   values include user and profile2.
 * @param $bundle
 *   (optional) NULL The bundle to return fields for.
 *
 * @return - assoc array
 *  ['profile_fields_options']
 *    - An associative array of all fields created from the profile module.
 *  ['default_values']
 *    - An indexed array of all (if any) default values for the form.
 */
function pcp_admin_settings_form_data($entity_type = 'user', $bundle = 'user') {
  $options = array();

  $field_conditions = array(
    'entity_type' => $entity_type,
    'bundle' => $bundle,
  );

  $options['profile_fields_options'] = pcp_get_profile_fields($field_conditions);
  $options['default_values'] = pcp_get_tagged_profile_fields($entity_type, $bundle, NULL);

  return $options;
}

/**
 * Submit callback.
 */
function pcp_admin_settings_submit($form, &$form_state) {
  switch ($form['#form_id']) {

    // admin/config/people/accounts
    case 'user_admin_settings':
      variable_set('pcp_enable_user_picture', $form_state['values']['pcp_enable_user_picture']);
      break;

    // admin/config/people/accounts/fields/[field_name]
    case 'field_ui_field_edit_form':
      if ($form['#instance']['entity_type'] == 'profile2') {
        _pcp_disable_field($form['#instance']['entity_type'], $form['#instance']['bundle'], $form['#instance']['field_name']);
        if ($form_state['values']['instance']['pcp_tag']) {
          _pcp_enable_field($form['#instance']['entity_type'], $form['#instance']['bundle'], $form['#instance']['field_name']);
        }
      }
      break;

    // admin/structure/profiles/manage/[profile_type]
    case 'profile2_type_form':
      // Provides the profile2 pcp data
      $profile_type = $form_state['values']['type'];
      variable_set('pcp_profile2_' . $profile_type . '_hide_block_on_complete', $form_state['values']['hide_block_on_complete']);
      // Process the profile fields that have been modified
      if ($form_state['values']['profile_fields']) {
        _pcp_save_profile_fields($form_state['values']['profile_fields']);
      }

      break;

    // admin/config/people/pcp
    default:
      // Provides the General Settings data
      variable_set('pcp_hide_block_on_complete', $form_state['values']['hide_block_on_complete']);
      if (variable_get('user_pictures', 0)) {
        variable_set('pcp_enable_user_picture', $form_state['values']['pcp_enable_user_picture']);
      }

      // Process the profile fields that have been modified
      if (isset($form_state['values']['profile_fields'])) {
        _pcp_save_profile_fields($form_state['values']['profile_fields']);
      }
  }
}


/**
 *  Utility function used to save fields.
 */
function _pcp_save_profile_fields($profile_fields) {
  foreach ($profile_fields as $field_identifier => $value) {
    list($entity_type, $bundle, $field_name) = explode(':', $field_identifier);
    if (empty($value)) {
      _pcp_disable_field($entity_type, $bundle, $field_name);
    }
    else {
      _pcp_enable_field($entity_type, $bundle, $field_name);
    }
  }
  drupal_set_message(t("Your settings have been saved."));
}
