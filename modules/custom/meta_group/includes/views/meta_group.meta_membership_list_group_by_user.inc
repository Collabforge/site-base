<?php

$view = new view();
$view->name = 'meta_membership_list_group_by_user';
$view->description = 'Show groups of a user.';
$view->tag = 'meta_group';
$view->base_table = 'og_membership';
$view->human_name = 'meta_membership_list_group_by_user';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'title' => 'title',
  'state' => 'state',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'title' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'state' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
);
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = '<div class="row-fluid">
<div class="span3"><img src="/sites/default/files/nofollow_bg.png" style="max-height: 160px"></div>
<div class="span8"><p><strong>There’s nothing here, yet!</strong></p>
<p>Click the \'Join\' button, to join the hub and become a member.</p>
<p>So get out there and <a href="/hubs">explore hubs</a>.</p>
</div>
</div>';
$handler->display->display_options['empty']['area']['format'] = 'email';
/* Relationship: OG membership: Group Node from OG membership */
$handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
$handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
$handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
$handler->display->display_options['relationships']['og_membership_related_node_group']['label'] = 'Group node';
/* Relationship: OG membership: OG Roles from membership */
$handler->display->display_options['relationships']['og_users_roles']['id'] = 'og_users_roles';
$handler->display->display_options['relationships']['og_users_roles']['table'] = 'og_membership';
$handler->display->display_options['relationships']['og_users_roles']['field'] = 'og_users_roles';
$handler->display->display_options['relationships']['og_users_roles']['label'] = 'OG Roles';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
$handler->display->display_options['fields']['title']['label'] = 'Group';
$handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
/* Field: Content: Short description */
$handler->display->display_options['fields']['field_tag_line']['id'] = 'field_tag_line';
$handler->display->display_options['fields']['field_tag_line']['table'] = 'field_data_field_tag_line';
$handler->display->display_options['fields']['field_tag_line']['field'] = 'field_tag_line';
$handler->display->display_options['fields']['field_tag_line']['relationship'] = 'og_membership_related_node_group';
$handler->display->display_options['fields']['field_tag_line']['label'] = 'Description';
/* Field: Content: Hub state */
$handler->display->display_options['fields']['meta_og_state_state']['id'] = 'meta_og_state_state';
$handler->display->display_options['fields']['meta_og_state_state']['table'] = 'field_data_meta_og_state_state';
$handler->display->display_options['fields']['meta_og_state_state']['field'] = 'meta_og_state_state';
$handler->display->display_options['fields']['meta_og_state_state']['relationship'] = 'og_membership_related_node_group';
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['sorts']['title']['relationship'] = 'og_membership_related_node_group';
/* Contextual filter: OG membership: Entity id */
$handler->display->display_options['arguments']['etid']['id'] = 'etid';
$handler->display->display_options['arguments']['etid']['table'] = 'og_membership';
$handler->display->display_options['arguments']['etid']['field'] = 'etid';
$handler->display->display_options['arguments']['etid']['default_action'] = 'default';
$handler->display->display_options['arguments']['etid']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['etid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['etid']['validate']['type'] = 'user';
/* Filter criterion: OG membership: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'og_membership';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['relationship'] = 'og_membership';
$handler->display->display_options['filters']['state']['value'] = array(
  1 => '1',
);
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['relationship'] = 'og_membership_related_node_group';
$handler->display->display_options['filters']['status']['value'] = '1';
/* Filter criterion: OG membership: Entity_type */
$handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
$handler->display->display_options['filters']['entity_type']['table'] = 'og_membership';
$handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
$handler->display->display_options['filters']['entity_type']['value'] = 'user';
/* Filter criterion: OG user roles: Role Name */
$handler->display->display_options['filters']['name']['id'] = 'name';
$handler->display->display_options['filters']['name']['table'] = 'og_role';
$handler->display->display_options['filters']['name']['field'] = 'name';
$handler->display->display_options['filters']['name']['relationship'] = 'og_users_roles';
$handler->display->display_options['filters']['name']['value'] = array(
  'administrator member' => 'administrator member',
);

/* Display: Block: List */
$handler = $view->new_display('block', 'Block: List', 'list');
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: OG membership: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'og_membership';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['relationship'] = 'og_membership';
$handler->display->display_options['filters']['state']['value'] = array(
  1 => '1',
);
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['relationship'] = 'og_membership_related_node_group';
$handler->display->display_options['filters']['status']['value'] = '1';
/* Filter criterion: OG membership: Entity_type */
$handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
$handler->display->display_options['filters']['entity_type']['table'] = 'og_membership';
$handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
$handler->display->display_options['filters']['entity_type']['value'] = 'user';

/* Display: Block: Owned */
$handler = $view->new_display('block', 'Block: Owned', 'owned');
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
$handler->display->display_options['fields']['title']['label'] = 'Group';
$handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
/* Field: Content: Short description */
$handler->display->display_options['fields']['field_tag_line']['id'] = 'field_tag_line';
$handler->display->display_options['fields']['field_tag_line']['table'] = 'field_data_field_tag_line';
$handler->display->display_options['fields']['field_tag_line']['field'] = 'field_tag_line';
$handler->display->display_options['fields']['field_tag_line']['relationship'] = 'og_membership_related_node_group';
$handler->display->display_options['fields']['field_tag_line']['label'] = 'Description';
/* Field: Content: Hub state */
$handler->display->display_options['fields']['meta_og_state_state']['id'] = 'meta_og_state_state';
$handler->display->display_options['fields']['meta_og_state_state']['table'] = 'field_data_meta_og_state_state';
$handler->display->display_options['fields']['meta_og_state_state']['field'] = 'meta_og_state_state';
$handler->display->display_options['fields']['meta_og_state_state']['relationship'] = 'og_membership_related_node_group';
/* Field: Content: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['relationship'] = 'og_membership_related_node_group';
$handler->display->display_options['fields']['edit_node']['label'] = '';
$handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: OG membership: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'og_membership';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['relationship'] = 'og_membership';
$handler->display->display_options['filters']['state']['value'] = array(
  1 => '1',
);
$handler->display->display_options['filters']['state']['group'] = 1;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['relationship'] = 'og_membership_related_node_group';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 1;
/* Filter criterion: OG membership: Entity_type */
$handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
$handler->display->display_options['filters']['entity_type']['table'] = 'og_membership';
$handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
$handler->display->display_options['filters']['entity_type']['value'] = 'user';
$handler->display->display_options['filters']['entity_type']['group'] = 1;
/* Filter criterion: OG user roles: Role Name */
$handler->display->display_options['filters']['name']['id'] = 'name';
$handler->display->display_options['filters']['name']['table'] = 'og_role';
$handler->display->display_options['filters']['name']['field'] = 'name';
$handler->display->display_options['filters']['name']['relationship'] = 'og_users_roles';
$handler->display->display_options['filters']['name']['value'] = array(
  'administrator member' => 'administrator member',
);
$handler->display->display_options['filters']['name']['group'] = 1;
