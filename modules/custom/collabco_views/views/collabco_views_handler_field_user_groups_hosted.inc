<?php

/**
 * @file
 *  Handler for the field 'User: no groups hosted'.
 */

class collabco_views_handler_field_user_groups_hosted extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['uid'] = 'uid';
  }

  function access() {
    return user_access('access user profiles') && user_access('access content');
  }

  function query() {
    // Not calling parent::query() as it will treat this pseudo-field as a real
    // db field, which it is not.
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $uid = $values->{$this->aliases['uid']};
    // @todo
    // see http://localhost:8888/meta/admin/structure/views/view/meta_membership_list_group_by_user/edit/owned
    $result = db_query("SELECT COUNT(ogm.id) FROM {og_membership} ogm INNER JOIN {node} n ON ogm.gid = n.nid AND ogm.group_type = :grouptype WHERE ogm.entity_type = 'user' AND ogm.etid = :uid AND ogm.state IN (:state) AND n.status = 1", array(
      ':grouptype' => 'node',
      ':uid' => $uid,
      ':state' => OG_STATE_ACTIVE,
    ));
    return $result->fetchField();
  }
}
