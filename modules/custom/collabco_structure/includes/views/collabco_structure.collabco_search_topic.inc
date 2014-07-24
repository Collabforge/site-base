<?php
$view = new view();
$view->name = 'collabco_search_topic';
$view->description = '';
$view->tag = 'collabco';
$view->base_table = 'node';
$view->human_name = 'collabco_search_topic';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Topics search';
$handler->display->display_options['use_more'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'Read more';
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  2 => '2',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Show All';
$handler->display->display_options['exposed_form']['options']['bef'] = array(
  'general' => array(
    'allow_secondary' => 0,
    'secondary_label' => 'Advanced options',
  ),
  'combine' => array(
    'more_options' => array(
      'is_secondary' => 0,
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
        ),
      ),
    ),
  ),
);
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['row_class'] = 'topic_feature';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['class'] = 'unstyled';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'title' => 'title',
  'name_1' => 'name_1',
  'body' => 'body',
  'picture_1' => 'picture_1',
  'last_comment_timestamp' => 'last_comment_timestamp',
  'name' => 'name',
);
$handler->display->display_options['row_options']['separator'] = '&nbsp;';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'No results match your keyword.';
$handler->display->display_options['empty']['area']['format'] = 'email';
/* Relationship: Content: Author */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'node';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Relationship: Content: Last comment author */
$handler->display->display_options['relationships']['last_comment_uid']['id'] = 'last_comment_uid';
$handler->display->display_options['relationships']['last_comment_uid']['table'] = 'node_comment_statistics';
$handler->display->display_options['relationships']['last_comment_uid']['field'] = 'last_comment_uid';
/* Relationship: Content: Taxonomy terms on node */
$handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
$handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
$handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
$handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
  'innovation_capabilities' => 'innovation_capabilities',
  'areas_of_participant_expertise' => 0,
  'organization_type' => 0,
  'precinct' => 0,
);
/* Relationship: Comment: Last Comment */
$handler->display->display_options['relationships']['cid_1']['id'] = 'cid_1';
$handler->display->display_options['relationships']['cid_1']['table'] = 'node_comment_statistics';
$handler->display->display_options['relationships']['cid_1']['field'] = 'cid';
/* Relationship: User: Profile */
$handler->display->display_options['relationships']['profile_1']['id'] = 'profile_1';
$handler->display->display_options['relationships']['profile_1']['table'] = 'users';
$handler->display->display_options['relationships']['profile_1']['field'] = 'profile';
$handler->display->display_options['relationships']['profile_1']['relationship'] = 'last_comment_uid';
$handler->display->display_options['relationships']['profile_1']['label'] = 'Comment Profile';
$handler->display->display_options['relationships']['profile_1']['bundle_types'] = array(
  'profile' => 'profile',
);
/* Relationship: User: Profile */
$handler->display->display_options['relationships']['profile']['id'] = 'profile';
$handler->display->display_options['relationships']['profile']['table'] = 'users';
$handler->display->display_options['relationships']['profile']['field'] = 'profile';
$handler->display->display_options['relationships']['profile']['relationship'] = 'uid';
$handler->display->display_options['relationships']['profile']['label'] = 'Host';
$handler->display->display_options['relationships']['profile']['bundle_types'] = array(
  'profile' => 'profile',
);
/* Relationship: Content: Organisation Image (field_organisation_image:fid) */
$handler->display->display_options['relationships']['field_organisation_image_fid']['id'] = 'field_organisation_image_fid';
$handler->display->display_options['relationships']['field_organisation_image_fid']['table'] = 'field_data_field_organisation_image';
$handler->display->display_options['relationships']['field_organisation_image_fid']['field'] = 'field_organisation_image_fid';
/* Relationship: Entity Reference: Referenced Entity */
$handler->display->display_options['relationships']['field_organisation_ref_target_id']['id'] = 'field_organisation_ref_target_id';
$handler->display->display_options['relationships']['field_organisation_ref_target_id']['table'] = 'field_data_field_organisation_ref';
$handler->display->display_options['relationships']['field_organisation_ref_target_id']['field'] = 'field_organisation_ref_target_id';
$handler->display->display_options['relationships']['field_organisation_ref_target_id']['relationship'] = 'profile';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h1';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['exclude'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
$handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'Read more';
$handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_type'] = 'p';
$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
  'trim_length' => '1500',
);
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['exclude'] = TRUE;
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'd M Y @ h:i a';
$handler->display->display_options['fields']['created']['timezone'] = 'Australia/Melbourne';
/* Field: Content: Comment count */
$handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
$handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
$handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
$handler->display->display_options['fields']['comment_count']['label'] = 'Replies';
$handler->display->display_options['fields']['comment_count']['exclude'] = TRUE;
$handler->display->display_options['fields']['comment_count']['element_label_type'] = 'strong';
/* Field: Content: Last comment time */
$handler->display->display_options['fields']['last_comment_timestamp']['id'] = 'last_comment_timestamp';
$handler->display->display_options['fields']['last_comment_timestamp']['table'] = 'node_comment_statistics';
$handler->display->display_options['fields']['last_comment_timestamp']['field'] = 'last_comment_timestamp';
$handler->display->display_options['fields']['last_comment_timestamp']['label'] = '';
$handler->display->display_options['fields']['last_comment_timestamp']['exclude'] = TRUE;
$handler->display->display_options['fields']['last_comment_timestamp']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['last_comment_timestamp']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['last_comment_timestamp']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['last_comment_timestamp']['date_format'] = 'time ago';
/* Field: User: Name */
$handler->display->display_options['fields']['name_1']['id'] = 'name_1';
$handler->display->display_options['fields']['name_1']['table'] = 'users';
$handler->display->display_options['fields']['name_1']['field'] = 'name';
$handler->display->display_options['fields']['name_1']['relationship'] = 'uid';
$handler->display->display_options['fields']['name_1']['label'] = '';
$handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
/* Field: User: Picture */
$handler->display->display_options['fields']['picture']['id'] = 'picture';
$handler->display->display_options['fields']['picture']['table'] = 'users';
$handler->display->display_options['fields']['picture']['field'] = 'picture';
$handler->display->display_options['fields']['picture']['relationship'] = 'uid';
$handler->display->display_options['fields']['picture']['label'] = '';
$handler->display->display_options['fields']['picture']['exclude'] = TRUE;
$handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['picture']['image_style'] = 'user_thumb';
/* Field: Profile: Business Position */
$handler->display->display_options['fields']['field_business_position_1']['id'] = 'field_business_position_1';
$handler->display->display_options['fields']['field_business_position_1']['table'] = 'field_data_field_business_position';
$handler->display->display_options['fields']['field_business_position_1']['field'] = 'field_business_position';
$handler->display->display_options['fields']['field_business_position_1']['relationship'] = 'profile';
$handler->display->display_options['fields']['field_business_position_1']['label'] = '';
$handler->display->display_options['fields']['field_business_position_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_business_position_1']['element_label_colon'] = FALSE;
/* Field: Profile: Organisation */
$handler->display->display_options['fields']['field_organisation_ref_1']['id'] = 'field_organisation_ref_1';
$handler->display->display_options['fields']['field_organisation_ref_1']['table'] = 'field_data_field_organisation_ref';
$handler->display->display_options['fields']['field_organisation_ref_1']['field'] = 'field_organisation_ref';
$handler->display->display_options['fields']['field_organisation_ref_1']['relationship'] = 'profile';
$handler->display->display_options['fields']['field_organisation_ref_1']['label'] = '';
$handler->display->display_options['fields']['field_organisation_ref_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_organisation_ref_1']['element_label_colon'] = FALSE;
/* Field: Comment: Author */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'comment';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'cid_1';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['exclude'] = TRUE;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['name']['empty_zero'] = TRUE;
/* Field: User: Picture */
$handler->display->display_options['fields']['picture_1']['id'] = 'picture_1';
$handler->display->display_options['fields']['picture_1']['table'] = 'users';
$handler->display->display_options['fields']['picture_1']['field'] = 'picture';
$handler->display->display_options['fields']['picture_1']['relationship'] = 'last_comment_uid';
$handler->display->display_options['fields']['picture_1']['label'] = '';
$handler->display->display_options['fields']['picture_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['picture_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['picture_1']['image_style'] = 'user_thumb_small';
/* Field: Profile: Business Position */
$handler->display->display_options['fields']['field_business_position']['id'] = 'field_business_position';
$handler->display->display_options['fields']['field_business_position']['table'] = 'field_data_field_business_position';
$handler->display->display_options['fields']['field_business_position']['field'] = 'field_business_position';
$handler->display->display_options['fields']['field_business_position']['relationship'] = 'profile_1';
$handler->display->display_options['fields']['field_business_position']['label'] = '';
$handler->display->display_options['fields']['field_business_position']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_business_position']['element_label_colon'] = FALSE;
/* Field: Profile: Organisation */
$handler->display->display_options['fields']['field_organisation_ref']['id'] = 'field_organisation_ref';
$handler->display->display_options['fields']['field_organisation_ref']['table'] = 'field_data_field_organisation_ref';
$handler->display->display_options['fields']['field_organisation_ref']['field'] = 'field_organisation_ref';
$handler->display->display_options['fields']['field_organisation_ref']['relationship'] = 'profile_1';
$handler->display->display_options['fields']['field_organisation_ref']['label'] = '';
$handler->display->display_options['fields']['field_organisation_ref']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_organisation_ref']['element_label_colon'] = FALSE;
/* Field: Comment: Comment */
$handler->display->display_options['fields']['comment_body']['id'] = 'comment_body';
$handler->display->display_options['fields']['comment_body']['table'] = 'field_data_comment_body';
$handler->display->display_options['fields']['comment_body']['field'] = 'comment_body';
$handler->display->display_options['fields']['comment_body']['relationship'] = 'cid_1';
$handler->display->display_options['fields']['comment_body']['label'] = '';
$handler->display->display_options['fields']['comment_body']['exclude'] = TRUE;
$handler->display->display_options['fields']['comment_body']['alter']['text'] = '<div class="row-fluid conversationcomment span12">
    <div class="span11">
      <p class"p2"><strong>Recent comment: <em>[last_comment_timestamp]</em></strong></p>
    </div>
    <div class="span2">
      [picture_1]
    </div>
    <div class="span9 commentname" >
      <span class="p">[name]</span>
    </div>
    <div class="p span8">[field_business_position] [field_organisation]</div>
    <div class="span7 commentquote" >
      <span class="p">[comment_body]</span>
    </div>
  </div>';
$handler->display->display_options['fields']['comment_body']['alter']['max_length'] = '200';
$handler->display->display_options['fields']['comment_body']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['comment_body']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['comment_body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['comment_body']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['comment_body']['empty_zero'] = TRUE;
$handler->display->display_options['fields']['comment_body']['type'] = 'text_plain';
/* Field: Comment: Comment */
$handler->display->display_options['fields']['comment_body_1']['id'] = 'comment_body_1';
$handler->display->display_options['fields']['comment_body_1']['table'] = 'field_data_comment_body';
$handler->display->display_options['fields']['comment_body_1']['field'] = 'comment_body';
$handler->display->display_options['fields']['comment_body_1']['relationship'] = 'cid_1';
$handler->display->display_options['fields']['comment_body_1']['label'] = '';
$handler->display->display_options['fields']['comment_body_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['comment_body_1']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['comment_body_1']['alter']['text'] = '<div class="row-fluid conversationcomment span12">
  <div><p><b>Recent comment:</b></p></div>
    <div class="span2 comment-img">
      [picture_1]
    </div>
    <div class="span9 commentname" >
      <span class="excerpt-author">
      [name],</span>
      <br/>[field_business_position] @ [field_organisation_ref]<br/>
      commented [last_comment_timestamp]</span>
    </div>
    <div class="commentquote span11" >
      [comment_body]
    </div>
  </div>';
$handler->display->display_options['fields']['comment_body_1']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title_1']['id'] = 'title_1';
$handler->display->display_options['fields']['title_1']['table'] = 'node';
$handler->display->display_options['fields']['title_1']['field'] = 'title';
$handler->display->display_options['fields']['title_1']['label'] = '';
$handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title_1']['alter']['text'] = 'Have your say';
$handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
$handler->display->display_options['fields']['nothing']['alter']['text'] = '  <div class="row-fluid conversationpreview conversation-item">
  <h3>[title]</h3>
  <div class="hostedby"><p>A conversation hosted by:</p></div>
  <div class="span2">[picture]</div>
  <div class="p span9">
     <div>[name_1] </div>
     <div>[field_business_position_1] @ [field_organisation_ref_1]</div>
  </div>
  <div class="span12 conversation-excerpt">[body]<br>
  [comment_body_1]
  <span class="haveyoursay">[title_1]</span>
</div>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Field: Content: Featured Image */
$handler->display->display_options['fields']['field_featured_image']['id'] = 'field_featured_image';
$handler->display->display_options['fields']['field_featured_image']['table'] = 'field_data_field_featured_image';
$handler->display->display_options['fields']['field_featured_image']['field'] = 'field_featured_image';
$handler->display->display_options['fields']['field_featured_image']['label'] = '';
$handler->display->display_options['fields']['field_featured_image']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_featured_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_featured_image']['empty'] = '<div class="featured-image no-image"><img src="/sites/all/themes/custom_theme/images/placeholder_square.jpg"></div>';
$handler->display->display_options['fields']['field_featured_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_featured_image']['settings'] = array(
  'image_style' => 'small_thumbnail',
  'image_link' => 'content',
);
/* Field: Content: Organisation Image */
$handler->display->display_options['fields']['field_organisation_image']['id'] = 'field_organisation_image';
$handler->display->display_options['fields']['field_organisation_image']['table'] = 'field_data_field_organisation_image';
$handler->display->display_options['fields']['field_organisation_image']['field'] = 'field_organisation_image';
$handler->display->display_options['fields']['field_organisation_image']['relationship'] = 'field_organisation_ref_target_id';
$handler->display->display_options['fields']['field_organisation_image']['label'] = '';
$handler->display->display_options['fields']['field_organisation_image']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_organisation_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_organisation_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_organisation_image']['settings'] = array(
  'image_style' => 'thumbnail',
  'image_link' => '',
);
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['label'] = '';
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="index_item row-fluid">
  <div class="span2">
    [field_featured_image]
  </div>
  <div class="span10 topic_item">
    <div class="hub-header">
      <div class="row-fluid">
        <div class="span8">
        <h3>[title]</h3>
        <div class="article_text">[body]</div>
        </div>
        <div class="span4">
          <!--Placeholder for labels - you are following / you are owner etc.-->
        </div>
      </div>
    </div>
    <div class="article_host row-fluid">        
        <div class="span3"> 
          [field_organisation_image]
        </div>
        <div class="span9"> 
            <h5>Hosted by <span class="article_host_name"><a href="#">[name_1]</a></span></h5>
             [field_business_position_1] at [field_organisation_ref_1]<br>
        </div>
    </div>
  </div>
</div>';
$handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
/* Sort criterion: Content: Sticky */
$handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
$handler->display->display_options['sorts']['sticky']['table'] = 'node';
$handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
$handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'conversation' => 'conversation',
);
/* Filter criterion: Content: Body (body) */
$handler->display->display_options['filters']['body_value']['id'] = 'body_value';
$handler->display->display_options['filters']['body_value']['table'] = 'field_data_body';
$handler->display->display_options['filters']['body_value']['field'] = 'body_value';
$handler->display->display_options['filters']['body_value']['operator'] = 'contains';
$handler->display->display_options['filters']['body_value']['expose']['operator_id'] = 'body_value_op';
$handler->display->display_options['filters']['body_value']['expose']['label'] = 'Search for:';
$handler->display->display_options['filters']['body_value']['expose']['operator'] = 'body_value_op';
$handler->display->display_options['filters']['body_value']['expose']['identifier'] = 'body';
$handler->display->display_options['filters']['body_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  5 => 0,
  4 => 0,
);
$handler->display->display_options['filters']['body_value']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['body_value']['expose']['autocomplete_field'] = 'body';
$handler->display->display_options['filters']['body_value']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['body_value']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['body_value']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'contains';
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  5 => 0,
  4 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Global: Combine fields filter */
$handler->display->display_options['filters']['combine']['id'] = 'combine';
$handler->display->display_options['filters']['combine']['table'] = 'views';
$handler->display->display_options['filters']['combine']['field'] = 'combine';
$handler->display->display_options['filters']['combine']['operator'] = 'contains';
$handler->display->display_options['filters']['combine']['exposed'] = TRUE;
$handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['label'] = 'Search all topics:';
$handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['identifier'] = 'keyword';
$handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  5 => 0,
  4 => 0,
);
$handler->display->display_options['filters']['combine']['fields'] = array(
  'title' => 'title',
  'body' => 'body',
  'name_1' => 'name_1',
  'field_organisation_ref_1' => 'field_organisation_ref_1',
  'field_organisation_ref' => 'field_organisation_ref',
);

/* Display: Search */
$handler = $view->new_display('page', 'Search', 'search');
$handler->display->display_options['exposed_block'] = TRUE;
$handler->display->display_options['path'] = 'topics/search';
