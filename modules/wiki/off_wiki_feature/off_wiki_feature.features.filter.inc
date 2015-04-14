<?php
/**
 * @file
 * off_wiki_feature.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function off_wiki_feature_filter_default_formats() {
  $formats = array();

  // Exported format: Wiki.
  $formats['wiki'] = array(
    'format' => 'wiki',
    'name' => 'Wiki',
    'cache' => 1,
    'status' => 1,
    'weight' => -6,
    'filters' => array(
      'filter_html' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <img> <em> <strong> <cite> <s> <sub> <sup> <blockquote> <code> <p> <pre> <ul> <ol> <li> <dl> <dt> <dd> <h1> <h2> <h3> <h4> <h5> <h6> <p> <table> <tbody> <td> <tr> <hr> <div> <iframe>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
