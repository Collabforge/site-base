<?php
/**
 * @file
 * collabco_organisation_feature.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function collabco_organisation_feature_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'uid' => 0,
  'title' => 'Partners and Providers',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => 'd6544e2a-1318-4726-8741-cb5fb698553e',
  'type' => 'basic_page',
  'language' => 'und',
  'created' => 1376472499,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '67cd30b7-6ec3-45d3-af18-87b6d38cddab',
  'revision_uid' => 0,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>This page is under construction. Collaboration partners and providers will appear here shortly.</p>
',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>This page is under construction. Collaboration partners and providers will appear here shortly.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 0,
  'comment_count' => 0,
  'name' => '',
  'picture' => 0,
  'data' => NULL,
  'date' => '2013-08-14 02:28:19 -0700',
);
  $nodes[] = array(
  'uid' => 0,
  'title' => 'Member Organisations',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '9543a023-946f-47b7-af9f-f47c49b29949',
  'type' => 'basic_page',
  'language' => 'und',
  'created' => 1376548823,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '89df9b2d-3914-44a0-92c7-3348a6417b0e',
  'revision_uid' => 0,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Welcome to the Tier A Community. &nbsp;Please browse through the list of companies that have been confirmed as Tier A members. &nbsp;If you see member information that is out of date or incorrect, please let us know at contact@meta.org.au</p>
',
        'summary' => '',
        'format' => 'full_html',
        'safe_value' => '<p>Welcome to the Tier A Community.  Please browse through the list of companies that have been confirmed as Tier A members.  If you see member information that is out of date or incorrect, please let us know at <a href="mailto:contact@meta.org.au">contact@meta.org.au</a></p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'cid' => 0,
  'last_comment_name' => NULL,
  'last_comment_uid' => 0,
  'comment_count' => 0,
  'name' => '',
  'picture' => 0,
  'data' => NULL,
  'date' => '2013-08-14 23:40:23 -0700',
);
  return $nodes;
}
