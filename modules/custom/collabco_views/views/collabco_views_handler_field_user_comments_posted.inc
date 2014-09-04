<?php
// $Id$

/**
 * @file
 *  Handler for the field 'User: comments posted'.
 */

class collabco_views_handler_field_user_comments_posted extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['uid'] = 'uid';
  }

  function access() {
    return user_access('access comments');
  }

  function query() {
    // Not calling parent::query() as it will treat this pseudo-field as a
    // real db field, which it is not.
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $uid = $values->{$this->aliases['uid']};
    $result = db_query('SELECT COUNT(cid) FROM {comment} WHERE uid=:uid AND status=:status', array(':uid' => $uid, ':status' => COMMENT_PUBLISHED));
    return $result->fetchField();
  }
}
