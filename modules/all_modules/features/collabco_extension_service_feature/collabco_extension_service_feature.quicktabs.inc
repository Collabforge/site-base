<?php
/**
 * @file
 * collabco_extension_service_feature.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function collabco_extension_service_feature_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'services';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = '    Services';
  $quicktabs->tabs = array(
    0 => array(
      'nid' => '117',
      'teaser' => 0,
      'hide_title' => 1,
      'title' => 'Business Value-Chain services ',
      'weight' => '-100',
      'type' => 'node',
    ),
    1 => array(
      'nid' => '115',
      'teaser' => 0,
      'hide_title' => 1,
      'title' => 'Business Support Services ',
      'weight' => '-99',
      'type' => 'node',
    ),
    2 => array(
      'nid' => '116',
      'teaser' => 0,
      'hide_title' => 1,
      'title' => 'Applied Services',
      'weight' => '-98',
      'type' => 'node',
    ),
    3 => array(
      'nid' => '114',
      'teaser' => 0,
      'hide_title' => 1,
      'title' => 'Share Industry Services',
      'weight' => '-97',
      'type' => 'node',
    ),
  );
  $quicktabs->renderer = 'ui_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array(
    'history' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('    Services');
  t('Applied Services');
  t('Business Support Services ');
  t('Business Value-Chain services ');
  t('Share Industry Services');

  $export['services'] = $quicktabs;

  return $export;
}
