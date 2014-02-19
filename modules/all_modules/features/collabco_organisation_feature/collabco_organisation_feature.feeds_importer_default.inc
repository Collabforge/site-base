<?php
/**
 * @file
 * collabco_organisation_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function collabco_organisation_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'organisation_import';
  $feeds_importer->config = array(
    'name' => 'Organisation Import',
    'description' => 'Imports organisations',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '23',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Organisation Name',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Website URL',
            'target' => 'field_website:url',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Address 1',
            'target' => 'field_address:thoroughfare',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Address 2',
            'target' => 'field_address:premise',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Suburb',
            'target' => 'field_address:locality',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'State or Territory',
            'target' => 'field_address:administrative_area',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Postcode',
            'target' => 'field_address:postal_code',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Member Type',
            'target' => 'field_member_type',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          8 => array(
            'source' => 'Industry',
            'target' => 'field_industry',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          9 => array(
            'source' => 'Type of Organisation',
            'target' => 'field_organisation_type',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          10 => array(
            'source' => 'Organisation Name',
            'target' => 'field_website:title',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Image Path',
            'target' => 'field_organisation_image:uri',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'organisation',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['organisation_import'] = $feeds_importer;

  return $export;
}
