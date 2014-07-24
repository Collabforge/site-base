<?php

/**
 * Implement hook_views_default_views().
 */
function collabco_structure_views_default_views() {
  return _collabco_core_views_default_views('collabco_structure', array(
    'collabco_search_topic'
  ));
}


