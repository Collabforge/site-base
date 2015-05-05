<?php

/**
 * @file
 *  Handler for the field 'User: flag count'.
 */

class collabco_views_handler_field_user_login_count extends views_handler_field {

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
    $result = db_query("SELECT value FROM {user_stats_values} WHERE name = 'login_count' AND uid = $uid")->fetchField();
    if ($result==NULL) { $result = 0;}
    return $result;
  }
}
