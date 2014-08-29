<?php

/**
 * Implement hook_views_default_views().
 */
function meta_structure_views_default_views() {
  return _meta_core_views_default_views('meta_structure', array(
    'meta_search_topic'
  ));
}


