<?php

/**
 * @file
 * Contains default views shipped with the Collabco Views module.
 */

/**
 * Implementation of hook_views_default_views().
 */
function collabco_views_default_views() {
  
  $view = new view;

  // ....

  $views[$view->name] = $view;
    
  return $views;
}
