<?php
// $Id$

function nobookoutline_nodetypes_settings_form() {
  // $types = _node_types_build()->types;
  $nodetypesobj = node_type_get_types();
  $options = array();
  foreach ($nodetypesobj as $nodetype) {
    $options[$nodetype->type] =  $nodetype->type;

  }
  $nooutline_defaults = variable_get('form_nobookoutline_nodetypes', "book");
  $form['form_nobookoutline_nodetypes'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Select Node Types to include book outlines'),
	'#default_value' => !empty($nooutline_defaults) ? array_values((array) $nooutline_defaults) : array(),
    '#options' => $options,
    '#description' => t('<b>Select the node types to show book outline.</b>'),
  );


  return system_settings_form($form);
}

