<?php
/**
 * @file
 * campaigns_report.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function campaigns_report_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'campaign_contacts_report';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'redhen_campaign_page';
  $view->human_name = 'Campaign Contacts Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Campaign Contacts Report';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access redhen contacts';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'label' => 'label',
    'full_name' => 'full_name',
    'redhen_contact_email' => 'redhen_contact_email',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'label' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'full_name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'redhen_contact_email' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: RedHen Campaign Page: Creator author_uid */
  $handler->display->display_options['relationships']['author']['id'] = 'author';
  $handler->display->display_options['relationships']['author']['table'] = 'redhen_campaign_page';
  $handler->display->display_options['relationships']['author']['field'] = 'author';
  $handler->display->display_options['relationships']['author']['required'] = TRUE;
  /* Relationship: Contact: User Contact */
  $handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['relationships']['contact_id']['table'] = 'redhen_contact_user';
  $handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['relationships']['contact_id']['relationship'] = 'author';
  $handler->display->display_options['relationships']['contact_id']['required'] = TRUE;
  /* Field: RedHen Campaign Page: Campaign Page Name */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'redhen_campaign_page';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  /* Field: Contact: Full name */
  $handler->display->display_options['fields']['full_name']['id'] = 'full_name';
  $handler->display->display_options['fields']['full_name']['table'] = 'views_entity_redhen_contact';
  $handler->display->display_options['fields']['full_name']['field'] = 'full_name';
  $handler->display->display_options['fields']['full_name']['relationship'] = 'contact_id';
  $handler->display->display_options['fields']['full_name']['link_to_entity'] = 0;
  /* Field: Contact: Email */
  $handler->display->display_options['fields']['redhen_contact_email']['id'] = 'redhen_contact_email';
  $handler->display->display_options['fields']['redhen_contact_email']['table'] = 'field_data_redhen_contact_email';
  $handler->display->display_options['fields']['redhen_contact_email']['field'] = 'redhen_contact_email';
  $handler->display->display_options['fields']['redhen_contact_email']['relationship'] = 'contact_id';
  $handler->display->display_options['fields']['redhen_contact_email']['type'] = 'redhen_email_primary';
  $handler->display->display_options['fields']['redhen_contact_email']['delta_offset'] = '0';
  /* Filter criterion: Contact: First name */
  $handler->display->display_options['filters']['first_name']['id'] = 'first_name';
  $handler->display->display_options['filters']['first_name']['table'] = 'redhen_contact';
  $handler->display->display_options['filters']['first_name']['field'] = 'first_name';
  $handler->display->display_options['filters']['first_name']['relationship'] = 'contact_id';
  $handler->display->display_options['filters']['first_name']['operator'] = 'contains';
  $handler->display->display_options['filters']['first_name']['group'] = 1;
  $handler->display->display_options['filters']['first_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['first_name']['expose']['operator_id'] = 'first_name_op';
  $handler->display->display_options['filters']['first_name']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['first_name']['expose']['operator'] = 'first_name_op';
  $handler->display->display_options['filters']['first_name']['expose']['identifier'] = 'first_name';
  $handler->display->display_options['filters']['first_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: Contact: Last name */
  $handler->display->display_options['filters']['last_name']['id'] = 'last_name';
  $handler->display->display_options['filters']['last_name']['table'] = 'redhen_contact';
  $handler->display->display_options['filters']['last_name']['field'] = 'last_name';
  $handler->display->display_options['filters']['last_name']['relationship'] = 'contact_id';
  $handler->display->display_options['filters']['last_name']['operator'] = 'contains';
  $handler->display->display_options['filters']['last_name']['group'] = 1;
  $handler->display->display_options['filters']['last_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['last_name']['expose']['operator_id'] = 'last_name_op';
  $handler->display->display_options['filters']['last_name']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['last_name']['expose']['operator'] = 'last_name_op';
  $handler->display->display_options['filters']['last_name']['expose']['identifier'] = 'last_name';
  $handler->display->display_options['filters']['last_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: RedHen Campaign Page: Campaign Page Name */
  $handler->display->display_options['filters']['label']['id'] = 'label';
  $handler->display->display_options['filters']['label']['table'] = 'redhen_campaign_page';
  $handler->display->display_options['filters']['label']['field'] = 'label';
  $handler->display->display_options['filters']['label']['operator'] = 'contains';
  $handler->display->display_options['filters']['label']['group'] = 1;
  $handler->display->display_options['filters']['label']['exposed'] = TRUE;
  $handler->display->display_options['filters']['label']['expose']['operator_id'] = 'label_op';
  $handler->display->display_options['filters']['label']['expose']['label'] = 'Campaign Page Name';
  $handler->display->display_options['filters']['label']['expose']['operator'] = 'label_op';
  $handler->display->display_options['filters']['label']['expose']['identifier'] = 'label';
  $handler->display->display_options['filters']['label']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'redhen/campaign-contacts-report';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Campaign Contacts Report';
  $handler->display->display_options['menu']['weight'] = '-99';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['campaign_contacts_report'] = $view;

  return $export;
}
