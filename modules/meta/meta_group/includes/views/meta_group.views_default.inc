<?php

/**
 * Implement hook_views_default_views().
 */
function meta_group_views_default_views() {

  $views = array();


  $aViewsNames = array(
	'meta_user_list_by_group'
	, 'meta_membership_list_group_by_user'
	, 'meta_node_list_group_by_user'
  );
  foreach ($aViewsNames as $_views_name) {
  		require_once dirname(__FILE__) . '/' . 'meta_group.'.$_views_name.'.inc';
  		$views[$view->name] = $view;
  }

  return $views;
}


