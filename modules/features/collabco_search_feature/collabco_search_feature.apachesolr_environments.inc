<?php
/**
 * @file
 * collabco_search_feature.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function collabco_search_feature_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'solr4';
  $environment->url = 'http://localhost:8080/solr4';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_read_only' => '0',
  );
  $environment->index_bundles = array();
  $export['solr'] = $environment;

  return $export;
}
