<?php
/**
 * @file
 * dc_campaign_products.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dc_campaign_products_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'purchase_reports';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'redhen_donation';
  $view->human_name = 'Purchase Reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Purchase Reports';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view redhen_raiser_donation redhen donation';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'donation_id' => 'donation_id',
    'received_1' => 'received_1',
    'expression' => 'expression',
    'received' => 'received',
    'label' => 'label',
    'label_1' => 'label_1',
    'created' => 'created',
    'field_billing_address_postal_code' => 'field_billing_address_postal_code',
    'first_name' => 'first_name',
    'last_name' => 'last_name',
    'email' => 'email',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'donation_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'received_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expression' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'received' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'label' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'label_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_billing_address_postal_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'email' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Donation: RedHen Contact contact_id */
  $handler->display->display_options['relationships']['contact']['id'] = 'contact';
  $handler->display->display_options['relationships']['contact']['table'] = 'redhen_donation';
  $handler->display->display_options['relationships']['contact']['field'] = 'contact';
  /* Relationship: Donation: RedHen Campaign Context */
  $handler->display->display_options['relationships']['redhen_campaign_context']['id'] = 'redhen_campaign_context';
  $handler->display->display_options['relationships']['redhen_campaign_context']['table'] = 'redhen_donation';
  $handler->display->display_options['relationships']['redhen_campaign_context']['field'] = 'redhen_campaign_context';
  /* Relationship: Donation: RedHen Campaign Page Context */
  $handler->display->display_options['relationships']['redhen_campaign_page_context']['id'] = 'redhen_campaign_page_context';
  $handler->display->display_options['relationships']['redhen_campaign_page_context']['table'] = 'redhen_donation';
  $handler->display->display_options['relationships']['redhen_campaign_page_context']['field'] = 'redhen_campaign_page_context';
  /* Field: Donation: URL */
  $handler->display->display_options['fields']['url_1']['id'] = 'url_1';
  $handler->display->display_options['fields']['url_1']['table'] = 'views_entity_redhen_donation';
  $handler->display->display_options['fields']['url_1']['field'] = 'url';
  $handler->display->display_options['fields']['url_1']['label'] = '';
  $handler->display->display_options['fields']['url_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url_1']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url_1']['link_to_entity'] = 0;
  /* Field: Donation: Donation ID */
  $handler->display->display_options['fields']['donation_id']['id'] = 'donation_id';
  $handler->display->display_options['fields']['donation_id']['table'] = 'redhen_donation';
  $handler->display->display_options['fields']['donation_id']['field'] = 'donation_id';
  $handler->display->display_options['fields']['donation_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['donation_id']['alter']['path'] = '[url_1] ';
  $handler->display->display_options['fields']['donation_id']['separator'] = '';
  /* Field: Donation: Amount received. */
  $handler->display->display_options['fields']['received_1']['id'] = 'received_1';
  $handler->display->display_options['fields']['received_1']['table'] = 'redhen_donation';
  $handler->display->display_options['fields']['received_1']['field'] = 'received';
  $handler->display->display_options['fields']['received_1']['label'] = 'Raw Amount';
  $handler->display->display_options['fields']['received_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['received_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['received_1']['separator'] = '';
  /* Field: Global: Math expression */
  $handler->display->display_options['fields']['expression']['id'] = 'expression';
  $handler->display->display_options['fields']['expression']['table'] = 'views';
  $handler->display->display_options['fields']['expression']['field'] = 'expression';
  $handler->display->display_options['fields']['expression']['label'] = 'Amount';
  $handler->display->display_options['fields']['expression']['exclude'] = TRUE;
  $handler->display->display_options['fields']['expression']['precision'] = '0';
  $handler->display->display_options['fields']['expression']['separator'] = '';
  $handler->display->display_options['fields']['expression']['expression'] = '[received_1]/100';
  /* Field: Donation: I prefer to make this donation anonymously */
  $handler->display->display_options['fields']['field_anonymous']['id'] = 'field_anonymous';
  $handler->display->display_options['fields']['field_anonymous']['table'] = 'field_data_field_anonymous';
  $handler->display->display_options['fields']['field_anonymous']['field'] = 'field_anonymous';
  $handler->display->display_options['fields']['field_anonymous']['label'] = 'Anonymous';
  /* Field: Donation: Card Type */
  $handler->display->display_options['fields']['field_card_type']['id'] = 'field_card_type';
  $handler->display->display_options['fields']['field_card_type']['table'] = 'field_data_field_card_type';
  $handler->display->display_options['fields']['field_card_type']['field'] = 'field_card_type';
  /* Field: Donation: Amount received. */
  $handler->display->display_options['fields']['received']['id'] = 'received';
  $handler->display->display_options['fields']['received']['table'] = 'redhen_donation';
  $handler->display->display_options['fields']['received']['field'] = 'received';
  $handler->display->display_options['fields']['received']['label'] = 'Amount received';
  $handler->display->display_options['fields']['received']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['received']['alter']['text'] = '$[expression]';
  $handler->display->display_options['fields']['received']['separator'] = '';
  /* Field: RedHen Campaign Page: URL */
  $handler->display->display_options['fields']['url_3']['id'] = 'url_3';
  $handler->display->display_options['fields']['url_3']['table'] = 'views_entity_redhen_campaign_page';
  $handler->display->display_options['fields']['url_3']['field'] = 'url';
  $handler->display->display_options['fields']['url_3']['relationship'] = 'redhen_campaign_page_context';
  $handler->display->display_options['fields']['url_3']['label'] = '';
  $handler->display->display_options['fields']['url_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url_3']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url_3']['link_to_entity'] = 0;
  /* Field: RedHen Campaign: URL */
  $handler->display->display_options['fields']['url_2']['id'] = 'url_2';
  $handler->display->display_options['fields']['url_2']['table'] = 'views_entity_redhen_campaign';
  $handler->display->display_options['fields']['url_2']['field'] = 'url';
  $handler->display->display_options['fields']['url_2']['relationship'] = 'redhen_campaign_context';
  $handler->display->display_options['fields']['url_2']['label'] = '';
  $handler->display->display_options['fields']['url_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url_2']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url_2']['link_to_entity'] = 0;
  /* Field: RedHen Campaign: Campaign Name */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'redhen_campaign';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['relationship'] = 'redhen_campaign_context';
  $handler->display->display_options['fields']['label']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['path'] = '[url_2] ';
  /* Field: RedHen Campaign Page: Campaign Page Name */
  $handler->display->display_options['fields']['label_1']['id'] = 'label_1';
  $handler->display->display_options['fields']['label_1']['table'] = 'redhen_campaign_page';
  $handler->display->display_options['fields']['label_1']['field'] = 'label';
  $handler->display->display_options['fields']['label_1']['relationship'] = 'redhen_campaign_page_context';
  $handler->display->display_options['fields']['label_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['label_1']['alter']['path'] = '[url_3]';
  /* Field: Contact: Billing Address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_billing_address_thoroughfare']['id'] = 'field_billing_address_thoroughfare';
  $handler->display->display_options['fields']['field_billing_address_thoroughfare']['table'] = 'field_data_field_billing_address';
  $handler->display->display_options['fields']['field_billing_address_thoroughfare']['field'] = 'field_billing_address_thoroughfare';
  /* Field: Contact: Billing Address - Premise (i.e. Apartment / Suite number) */
  $handler->display->display_options['fields']['field_billing_address_premise']['id'] = 'field_billing_address_premise';
  $handler->display->display_options['fields']['field_billing_address_premise']['table'] = 'field_data_field_billing_address';
  $handler->display->display_options['fields']['field_billing_address_premise']['field'] = 'field_billing_address_premise';
  /* Field: Contact: Billing Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_billing_address_locality']['id'] = 'field_billing_address_locality';
  $handler->display->display_options['fields']['field_billing_address_locality']['table'] = 'field_data_field_billing_address';
  $handler->display->display_options['fields']['field_billing_address_locality']['field'] = 'field_billing_address_locality';
  /* Field: Contact: Billing Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['field_billing_address_administrative_area']['id'] = 'field_billing_address_administrative_area';
  $handler->display->display_options['fields']['field_billing_address_administrative_area']['table'] = 'field_data_field_billing_address';
  $handler->display->display_options['fields']['field_billing_address_administrative_area']['field'] = 'field_billing_address_administrative_area';
  $handler->display->display_options['fields']['field_billing_address_administrative_area']['relationship'] = 'contact';
  /* Field: Contact: Billing Address - Country */
  $handler->display->display_options['fields']['field_billing_address_country']['id'] = 'field_billing_address_country';
  $handler->display->display_options['fields']['field_billing_address_country']['table'] = 'field_data_field_billing_address';
  $handler->display->display_options['fields']['field_billing_address_country']['field'] = 'field_billing_address_country';
  $handler->display->display_options['fields']['field_billing_address_country']['relationship'] = 'contact';
  $handler->display->display_options['fields']['field_billing_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_billing_address_country']['display_name'] = 1;
  /* Field: Contact: Billing Address - Postal code */
  $handler->display->display_options['fields']['field_billing_address_postal_code']['id'] = 'field_billing_address_postal_code';
  $handler->display->display_options['fields']['field_billing_address_postal_code']['table'] = 'field_data_field_billing_address';
  $handler->display->display_options['fields']['field_billing_address_postal_code']['field'] = 'field_billing_address_postal_code';
  $handler->display->display_options['fields']['field_billing_address_postal_code']['relationship'] = 'contact';
  $handler->display->display_options['fields']['field_billing_address_postal_code']['label'] = 'Zip Code';
  /* Field: Contact: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_redhen_contact';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['relationship'] = 'contact';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Contact: Full name */
  $handler->display->display_options['fields']['full_name']['id'] = 'full_name';
  $handler->display->display_options['fields']['full_name']['table'] = 'views_entity_redhen_contact';
  $handler->display->display_options['fields']['full_name']['field'] = 'full_name';
  $handler->display->display_options['fields']['full_name']['relationship'] = 'contact';
  $handler->display->display_options['fields']['full_name']['label'] = 'Contact';
  $handler->display->display_options['fields']['full_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['full_name']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['full_name']['link_to_entity'] = 0;
  /* Field: Contact: Default email */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'views_entity_redhen_contact';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  $handler->display->display_options['fields']['email']['relationship'] = 'contact';
  $handler->display->display_options['fields']['email']['label'] = 'Email';
  $handler->display->display_options['fields']['email']['link_to_entity'] = 0;
  /* Field: Donation: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'redhen_donation';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
  /* Field: Donation: Type */
  $handler->display->display_options['fields']['field_tribute_type']['id'] = 'field_tribute_type';
  $handler->display->display_options['fields']['field_tribute_type']['table'] = 'field_data_field_tribute_type';
  $handler->display->display_options['fields']['field_tribute_type']['field'] = 'field_tribute_type';
  $handler->display->display_options['fields']['field_tribute_type']['label'] = 'Tribute Type';
  /* Field: Donation: A tribute to (Name) */
  $handler->display->display_options['fields']['field_dedication']['id'] = 'field_dedication';
  $handler->display->display_options['fields']['field_dedication']['table'] = 'field_data_field_dedication';
  $handler->display->display_options['fields']['field_dedication']['field'] = 'field_dedication';
  $handler->display->display_options['fields']['field_dedication']['label'] = 'Tribute to';
  /* Field: Donation: Please mail a letter on my behalf */
  $handler->display->display_options['fields']['field_letter_request']['id'] = 'field_letter_request';
  $handler->display->display_options['fields']['field_letter_request']['table'] = 'field_data_field_letter_request';
  $handler->display->display_options['fields']['field_letter_request']['field'] = 'field_letter_request';
  $handler->display->display_options['fields']['field_letter_request']['label'] = 'Tribute Letter';
  /* Field: Donation: Tribute address - Full name */
  $handler->display->display_options['fields']['field_tribute_address_name_line']['id'] = 'field_tribute_address_name_line';
  $handler->display->display_options['fields']['field_tribute_address_name_line']['table'] = 'field_data_field_tribute_address';
  $handler->display->display_options['fields']['field_tribute_address_name_line']['field'] = 'field_tribute_address_name_line';
  $handler->display->display_options['fields']['field_tribute_address_name_line']['label'] = 'Tribute address - Name';
  /* Field: Donation: Tribute address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_tribute_address_thoroughfare']['id'] = 'field_tribute_address_thoroughfare';
  $handler->display->display_options['fields']['field_tribute_address_thoroughfare']['table'] = 'field_data_field_tribute_address';
  $handler->display->display_options['fields']['field_tribute_address_thoroughfare']['field'] = 'field_tribute_address_thoroughfare';
  $handler->display->display_options['fields']['field_tribute_address_thoroughfare']['label'] = 'Tribute address - Street 1';
  /* Field: Donation: Tribute address - Premise (i.e. Apartment / Suite number) */
  $handler->display->display_options['fields']['field_tribute_address_premise']['id'] = 'field_tribute_address_premise';
  $handler->display->display_options['fields']['field_tribute_address_premise']['table'] = 'field_data_field_tribute_address';
  $handler->display->display_options['fields']['field_tribute_address_premise']['field'] = 'field_tribute_address_premise';
  $handler->display->display_options['fields']['field_tribute_address_premise']['label'] = 'Tribute address - Street 2';
  /* Field: Donation: Tribute address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_tribute_address_locality']['id'] = 'field_tribute_address_locality';
  $handler->display->display_options['fields']['field_tribute_address_locality']['table'] = 'field_data_field_tribute_address';
  $handler->display->display_options['fields']['field_tribute_address_locality']['field'] = 'field_tribute_address_locality';
  $handler->display->display_options['fields']['field_tribute_address_locality']['label'] = 'Tribute address - City';
  /* Field: Donation: Tribute address - Postal code */
  $handler->display->display_options['fields']['field_tribute_address_postal_code']['id'] = 'field_tribute_address_postal_code';
  $handler->display->display_options['fields']['field_tribute_address_postal_code']['table'] = 'field_data_field_tribute_address';
  $handler->display->display_options['fields']['field_tribute_address_postal_code']['field'] = 'field_tribute_address_postal_code';
  $handler->display->display_options['fields']['field_tribute_address_postal_code']['label'] = 'Tribute address - Zip';
  /* Filter criterion: Date: Date (redhen_donation) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'redhen_donation';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'Start Date';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-10:+1';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'redhen_donation.created' => 'redhen_donation.created',
  );
  $handler->display->display_options['filters']['date_filter_1']['date_method'] = 'AND';
  /* Filter criterion: Date: Date (redhen_donation) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'redhen_donation';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'End Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-10:+1';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'redhen_donation.created' => 'redhen_donation.created',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'AND';
  /* Filter criterion: RedHen Campaign: Campaign Name */
  $handler->display->display_options['filters']['label']['id'] = 'label';
  $handler->display->display_options['filters']['label']['table'] = 'redhen_campaign';
  $handler->display->display_options['filters']['label']['field'] = 'label';
  $handler->display->display_options['filters']['label']['relationship'] = 'redhen_campaign_context';
  $handler->display->display_options['filters']['label']['operator'] = 'contains';
  $handler->display->display_options['filters']['label']['group'] = 1;
  $handler->display->display_options['filters']['label']['exposed'] = TRUE;
  $handler->display->display_options['filters']['label']['expose']['operator_id'] = 'label_op';
  $handler->display->display_options['filters']['label']['expose']['label'] = 'Campaign Name';
  $handler->display->display_options['filters']['label']['expose']['operator'] = 'label_op';
  $handler->display->display_options['filters']['label']['expose']['identifier'] = 'label';
  $handler->display->display_options['filters']['label']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: RedHen Campaign Page: Campaign Page Name */
  $handler->display->display_options['filters']['label_1']['id'] = 'label_1';
  $handler->display->display_options['filters']['label_1']['table'] = 'redhen_campaign_page';
  $handler->display->display_options['filters']['label_1']['field'] = 'label';
  $handler->display->display_options['filters']['label_1']['relationship'] = 'redhen_campaign_page_context';
  $handler->display->display_options['filters']['label_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['label_1']['group'] = 1;
  $handler->display->display_options['filters']['label_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['label_1']['expose']['operator_id'] = 'label_1_op';
  $handler->display->display_options['filters']['label_1']['expose']['label'] = 'Team or Donor';
  $handler->display->display_options['filters']['label_1']['expose']['operator'] = 'label_1_op';
  $handler->display->display_options['filters']['label_1']['expose']['identifier'] = 'label_1';
  $handler->display->display_options['filters']['label_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: RedHen Campaign: Product (field_product) */
  $handler->display->display_options['filters']['field_product_product_id']['id'] = 'field_product_product_id';
  $handler->display->display_options['filters']['field_product_product_id']['table'] = 'field_data_field_product';
  $handler->display->display_options['filters']['field_product_product_id']['field'] = 'field_product_product_id';
  $handler->display->display_options['filters']['field_product_product_id']['relationship'] = 'redhen_campaign_context';
  $handler->display->display_options['filters']['field_product_product_id']['operator'] = 'not empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'redhen/purchases';
  $handler->display->display_options['menu']['title'] = 'Donation Reports';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: CSV export */
  $handler = $view->new_display('views_data_export', 'CSV export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'redhen/purchases/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: XLS export */
  $handler = $view->new_display('views_data_export', 'XLS export', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'purchases/excel';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['purchase_reports'] = $view;

  return $export;
}
