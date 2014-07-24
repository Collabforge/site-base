<?php

$view = new view();
$view->name = 'collabco_user_list_by_group';
$view->description = 'Group members.';
$view->tag = 'collabco_group';
$view->base_table = 'users';
$view->human_name = 'collabco_user_list_by_group';
$view->core = 0;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Defaults */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: OG membership: OG membership from User */
$handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
$handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
$handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
$handler->display->display_options['relationships']['og_membership_rel']['label'] = 'Membership';
/* Relationship: OG membership: OG Roles from membership */
$handler->display->display_options['relationships']['og_users_roles']['id'] = 'og_users_roles';
$handler->display->display_options['relationships']['og_users_roles']['table'] = 'og_membership';
$handler->display->display_options['relationships']['og_users_roles']['field'] = 'og_users_roles';
$handler->display->display_options['relationships']['og_users_roles']['label'] = 'Roles';
/* Relationship: User: Profile */
$handler->display->display_options['relationships']['profile']['id'] = 'profile';
$handler->display->display_options['relationships']['profile']['table'] = 'users';
$handler->display->display_options['relationships']['profile']['field'] = 'profile';
$handler->display->display_options['relationships']['profile']['bundle_types'] = array(
  'profile' => 'profile',
);
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
/* Field: User: Picture */
$handler->display->display_options['fields']['picture']['id'] = 'picture';
$handler->display->display_options['fields']['picture']['table'] = 'users';
$handler->display->display_options['fields']['picture']['field'] = 'picture';
$handler->display->display_options['fields']['picture']['label'] = '';
$handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
/* Field: Profile: Business Position */
$handler->display->display_options['fields']['field_business_position']['id'] = 'field_business_position';
$handler->display->display_options['fields']['field_business_position']['table'] = 'field_data_field_business_position';
$handler->display->display_options['fields']['field_business_position']['field'] = 'field_business_position';
$handler->display->display_options['fields']['field_business_position']['relationship'] = 'profile';
$handler->display->display_options['fields']['field_business_position']['label'] = '';
$handler->display->display_options['fields']['field_business_position']['element_label_colon'] = FALSE;
/* Field: Profile: Organisation */
$handler->display->display_options['fields']['field_organisation_ref']['id'] = 'field_organisation_ref';
$handler->display->display_options['fields']['field_organisation_ref']['table'] = 'field_data_field_organisation_ref';
$handler->display->display_options['fields']['field_organisation_ref']['field'] = 'field_organisation_ref';
$handler->display->display_options['fields']['field_organisation_ref']['relationship'] = 'profile';
$handler->display->display_options['fields']['field_organisation_ref']['label'] = '';
$handler->display->display_options['fields']['field_organisation_ref']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_organisation_ref']['settings'] = array(
  'link' => 0,
);
/* Field: OG membership: Og membership ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'og_membership';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['relationship'] = 'og_membership_rel';
$handler->display->display_options['fields']['id']['label'] = '';
$handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
/* Field: OG membership: Group ID */
$handler->display->display_options['fields']['gid']['id'] = 'gid';
$handler->display->display_options['fields']['gid']['table'] = 'og_membership';
$handler->display->display_options['fields']['gid']['field'] = 'gid';
$handler->display->display_options['fields']['gid']['relationship'] = 'og_membership_rel';
$handler->display->display_options['fields']['gid']['label'] = '';
$handler->display->display_options['fields']['gid']['element_label_colon'] = FALSE;

/* Sort criterion: OG membership: Created */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'og_membership';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['relationship'] = 'og_membership_rel';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Contextual filter: OG membership: Group ID */
$handler->display->display_options['arguments']['gid']['id'] = 'gid';
$handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
$handler->display->display_options['arguments']['gid']['field'] = 'gid';
$handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
$handler->display->display_options['arguments']['gid']['default_action'] = 'not found';
$handler->display->display_options['arguments']['gid']['title_enable'] = TRUE;
$handler->display->display_options['arguments']['gid']['title'] = '%1 members';
$handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 1;
/* Filter criterion: OG membership: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'og_membership';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['relationship'] = 'og_membership_rel';
$handler->display->display_options['filters']['state']['value'] = array(
  1 => '1',
);
$handler->display->display_options['filters']['state']['group'] = 1;

/* Display: Block: All Members */
$handler = $view->new_display('block', 'Block: All Members', 'members_all');

/* Display: Block: Co-owners */
$handler = $view->new_display('block', 'Block: Co-owners', 'coowners');
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 1;
/* Filter criterion: OG membership: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'og_membership';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['relationship'] = 'og_membership_rel';
$handler->display->display_options['filters']['state']['value'] = array(
  1 => '1',
);
$handler->display->display_options['filters']['state']['group'] = 1;
/* Filter criterion: OG user roles: Role Name */
$handler->display->display_options['filters']['name']['id'] = 'name';
$handler->display->display_options['filters']['name']['table'] = 'og_role';
$handler->display->display_options['filters']['name']['field'] = 'name';
$handler->display->display_options['filters']['name']['relationship'] = 'og_users_roles';
$handler->display->display_options['filters']['name']['value'] = array(
  'administrator member' => 'administrator member',
);

/* Display: Block: Normal members */
$handler = $view->new_display('block', 'Block: Normal members', 'members');
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
/* Filter criterion: OG membership: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'og_membership';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['relationship'] = 'og_membership_rel';
$handler->display->display_options['filters']['state']['value'] = array(
  1 => '1',
);
/* Filter criterion: OG user roles: Role Name */
$handler->display->display_options['filters']['name']['id'] = 'name';
$handler->display->display_options['filters']['name']['table'] = 'og_role';
$handler->display->display_options['filters']['name']['field'] = 'name';
$handler->display->display_options['filters']['name']['relationship'] = 'og_users_roles';
$handler->display->display_options['filters']['name']['operator'] = 'not';
$handler->display->display_options['filters']['name']['value'] = array(
  'administrator member' => 'administrator member',
);
