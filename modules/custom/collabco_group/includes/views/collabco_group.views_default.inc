<?php

/**
 * Implement hook_views_default_views().
 */
function collabco_group_views_default_views() {

  $views = array();


  $aViewsNames = array(
	'collabco_user_list_by_group'
	, 'collabco_membership_list_group_by_user'
  );
  foreach ($aViewsNames as $_views_name) {
  		require_once dirname(__FILE__) . '/' . 'collabco_group.'.$_views_name.'.inc';
  		$views[$view->name] = $view;
  }

  return $views;
}


