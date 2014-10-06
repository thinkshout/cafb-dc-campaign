<?php


/**
 * Helper for defining stubbed content and menu items.
 */
function cafb_dc_stubbed_nodes() {

  // Optionally, add the nodes to create on install here.
  // Include a 'link_title' to create a menu link for a given node.
  // Note: if this array references menus that do not exist yet, they will be created in ts_install_helpers_crud_menu_items().
  // Note: if setting a 'parent_path' make sure that your menu item has the same 'menu_name.'

  $stubbed_nodes = array(
    'home' => array(
      'title' => 'Welcome to Capital Area Food Bank',
      'format' => 'rich_text',
      'weight' => 1,
      'body' => "Ethnic Odd Future salvia, sriracha keffiyeh art party craft beer polaroid normcore selfies chillwave sustainable semiotics Marfa letterpress. Chambray mumblecore food truck Shoreditch mustache actually. Drinking vinegar mixtape cliche, ethnic keytar stumptown Pitchfork retro Banksy mustache cardigan scenester Godard ethical. Leggings pour-over biodiesel yr chillwave quinoa plaid Portland banh mi selvage. Wolf flannel gentrify asymmetrical, Tonx authentic retro. Godard scenester Carles, PBR slow-carb gluten-free hella. Mumblecore biodiesel sustainable Carles letterpress YOLO.",
    ),
    // top-level menus:
    'About' => array(
      'title' => 'About Capital Area Food Bank',
      'link_title' => 'About',
      'menu_name' => 'main-menu',
      'format' => 'full_html',
      'weight' => 2,
    ),
    'Privacy' => array(
      'title' => 'Privacy Policy',
      'link_title' => 'Privacy',
      'menu_name' => 'main-menu',
      'format' => 'full_html',
      'weight' => 3,
    ),
    'Terms' => array(
      'title' => 'Terms & Conditions',
      'link_title' => 'Terms',
      'menu_name' => 'main-menu',
      'format' => 'full_html',
      'weight' => 4,
    ),
  );

  return $stubbed_nodes;
}

/**
 * Helper for creating stubbed contacts.
 *
 * @return array
 *   Array of sample contacts.
 */
function cafb_dc_stubbed_contacts($number = 20) {
  $stubs = array();

  $default = array(
    'type' => 'redhen_contact',
    'bundle' => 'contact',
  );

  for ($i = 0; $i < $number; $i++) {
    $first_name = random_data_first_name();
    $middle_name = random_data_first_name();
    $last_name = random_data_last_name();
    $org = random_data_organization();
    $state = random_data_state();
    $city = random_data_city();
    $postal_code = random_data_postal_code();
    $street = random_data_street();
    $street2 = random_data_street2();

    $stubs[$i] = array();

    $stubs[$i]['properties'] = array(
      'redhen_state' => 1,
      'first_name' => $first_name,
      'middle_name' => $middle_name,
      'last_name' => $last_name,
    );

    $stubs[$i]['fields'] = array(
      'field_organization' => array(
        'value' => $org,
      ),
      'redhen_contact_email' => array(
        array(
          'value' => $first_name . '.' . $last_name . '@example.com',
          'default' => 1,
        ),
        array(
          'value' => $first_name . '@example.org',
        ),
      ),
      'field_billing_address' => array(
        'country' => 'US',
        'administrative_area' => $state,
        'locality' => $city,
        'postal_code' => $postal_code,
        'thoroughfare' => $street,
        'premise' => $street2,
      ),
    );

    $stubs[$i] = array_merge($default, $stubs[$i]);
  }

  return $stubs;
}

/**
 * Create users and link them to contacts. Updates contact entities.
 *
 * @param array $contacts
 *   Array of redhen_contact entities.
 */
function cafb_dc_create_users_link_contacts(&$contacts) {
  /* @var $contact RedhenContact */
  foreach ($contacts as $contact) {
    // Create user.
    $edit = array();
    $edit['name'] = $contact->first_name . ' ' . $contact->last_name;
    $edit['mail'] = $contact->email();
    $edit['init'] = $edit['mail'];
    $edit['pass'] = $edit['name'];
    $edit['status'] = 1;

    $image_name = $contact->first_name . $contact->last_name;
    $image_destination = "public://$image_name.png";
    $image_source = 'http://hhhhold.com/180-220/png';

    $image_file_id = ts_install_helpers_copy_file($image_name, $image_destination, $image_source);
    $edit['picture'] = $image_file_id;

    $user = user_save('', $edit);

    // Link user to contact.
    if ($user) {
      $contact->uid = $user->uid;
      $contact->save();
    }
  }
}

/**
 * Helper for creating stubbed campaigns.
 *
 * @return array
 *   Array of sample campaigns.
 */
function cafb_dc_stubbed_campaigns($number = 10) {
  $stubs = array();

  for ($i = 0; $i < $number; $i++) {
    $stubs[$i] = array(
      'type' => 'redhen_campaign',
      'bundle' => 'general',
    );

    $stubs[$i]['properties'] = array(
      'label' => random_data_campaign_name(),
      'redhen_state' => 1,
    );

    $stubs[$i]['fields'] = array(
      'redhen_campaign_donation_type' => array(
        'redhen_donation_type' => 'redhen_raiser_donation',
      ),
      'redhen_campaign_goal' => array(
        'value' => rand(100, 800000),
      ),
      'field_teaser' => array(
        'value' => devel_create_greeking(rand(3, 7)),
        'format' => 'rich_text',
      ),
      'field_start_date' => array(
        'value' => date('Y-m-d'),
      ),
      'field_end_date' => array(
        // 7-60 days from now.
        'value' => date('Y-m-d', time() + (rand(7, 60) * 24 * 60 * 60)),
      ),
    );

    // Story field.
    $stubs[$i]['fields']['field_story']['format'] = 'rich_text';
    $stubs[$i]['fields']['field_story']['value'] = '';
    $paragraphs = rand(2, 5);
    for ($p = 0; $p < $paragraphs; $p++) {
      $stubs[$i]['fields']['field_story']['value'] .= devel_create_greeking(rand(20, 100)) . "\n\n";
    }

    // Banner image field.
    $image_name = 'campaign-' . (string) rand(1, 999999) . '.png';
    $image_destination = "public://$image_name.png";
    $image_source = 'http://hhhhold.com/900x400/png';
    $image_file_id = ts_install_helpers_copy_file($image_name, $image_destination, $image_source);
    $image_file = file_load($image_file_id);
    $stubs[$i]['fields']['field_banner_image'] = (array) $image_file;

    // Story media field.
    $image_name = 'campaign-' . (string) rand(1, 999999) . '.png';
    $image_destination = "public://$image_name.png";
    $image_source = 'http://hhhhold.com/350-700/png';
    $image_file_id = ts_install_helpers_copy_file($image_name, $image_destination, $image_source);
    $image_file = file_load($image_file_id);
    $stubs[$i]['fields']['field_story_media'] = (array) $image_file;
  }

  return $stubs;
}

/**
 * Helper for creating stubbed campaign pages.
 *
 * @param array $campaigns
 *   Array of RedhenCampaign objects.
 * @param array $contacts
 *   Array of RedhenContact objects.
 * @param int $number
 *   How many campaign pages to create.
 * @param string $type
 *   Type of page to create. 'individual' or 'team'.
 * @param array $team_pages
 *   Team pages to reference, if making individual pages.
 *
 * @return array
 *   Array of campaign pages.
 */
function cafb_dc_stubbed_campaign_pages($campaigns, $contacts, $number = 10, $type = 'individual', $team_pages = array()) {
  $stubs = array();

  for ($i = 0; $i < $number; $i++) {
    $stubs[$i] = array(
      'type' => 'redhen_campaign_page',
    );

    $stubs[$i]['properties']['redhen_state'] = 1;
    if ($type == 'team') {
      $stubs[$i]['bundle'] = 'team';
      $stubs[$i]['properties']['label'] = random_data_campaign_team_name();
    }
    if ($type == 'individual') {
      $stubs[$i]['bundle'] = 'individual';
      $stubs[$i]['properties']['label'] = random_data_first_name() . ' ' . random_data_last_name();
      if ($team_pages) {
        $team_page = random_data_array_item($team_pages);
        $stubs[$i]['properties']['team'] = $team_page->page_id;
      }
    }

    $contact = random_data_array_item($contacts);
    $stubs[$i]['properties']['author_uid'] = $contact->contact_id;

    $stubs[$i]['fields'] = array(
      'redhen_campaign_goal' => array(
        'value' => rand(50, 8000),
      ),
      'field_end_date' => array(
        // 7-60 days from now.
        'value' => date('Y-m-d', time() + (rand(7, 60) * 24 * 60 * 60)),
      ),
    );

    $campaign = random_data_array_item($campaigns);
    $stubs[$i]['properties']['campaign'] = $campaign->campaign_id;
    $stubs[$i]['properties']['campaign_page_type'] = 2;

    // Story field.
    $stubs[$i]['fields']['field_story']['format'] = 'rich_text';
    $stubs[$i]['fields']['field_story']['value'] = '';
    $stubs[$i]['fields']['field_story']['value'] .= devel_create_greeking(rand(20, 100));

    // Logo field.
    $image_name = 'campaign-page-' . (string) rand(1, 999999) . '.png';
    $image_destination = "public://$image_name.png";
    $image_source = 'http://hhhhold.com/900x400/png';
    $image_file_id = ts_install_helpers_copy_file($image_name, $image_destination, $image_source);
    $image_file = file_load($image_file_id);
    $stubs[$i]['fields']['field_logo'] = (array) $image_file;

    // Story media field.
    $image_name = 'campaign-page-' . (string) rand(1, 999999) . '.png';
    $image_destination = "public://$image_name.png";
    $image_source = 'http://hhhhold.com/350-700/png';
    $image_file_id = ts_install_helpers_copy_file($image_name, $image_destination, $image_source);
    $image_file = file_load($image_file_id);
    $stubs[$i]['fields']['field_story_media'] = (array) $image_file;
  }

  return $stubs;
}

/**
 * Create sample campaign updates.
 *
 * @param array $campaigns
 *   Array of RedhenCampaign objects.
 * @param array $team_campaign_pages
 *   Array of RedhenCampaignPage objects, team bundle.
 * @param array $individual_campaign_pages
 *   Array of RedhenCampaignPage objects, individual bundle.
 * @param int $number
 *   How many campaign updates to create.
 *
 * @return array
 *   Array of created nodes.
 */
function cafb_dc_stubbed_campaign_updates($campaigns, $team_campaign_pages, $individual_campaign_pages, $number = 10) {
  $stubs = array();

  for ($i = 0; $i < $number; $i++) {
    $campaign = random_data_array_item($campaigns);

    $stubs[$i] = array(
      'type' => 'campaign_update',
      'body' => devel_create_para(rand(2, 5), 1),
      'format' => 'rich_text',
      'title' => devel_create_greeking(5, TRUE),
    );
    $stubs[$i]['custom_fields'] = array(
      'field_campaign_context' => array(
        'target_id' => $campaign->campaign_id,
      ),
    );

    // Sometimes leave the team context field empty.
    if (rand(0, 1)) {
      $team_campaign_page = random_data_array_item($team_campaign_pages);
      $stubs[$i]['custom_fields']['field_team_context']['target_id'] = $team_campaign_page->page_id;
    }

    // Use both individual and team pages. And sometimes leave it empty.
    $rand = rand(1, 3);
    if ($rand == 1) {
      $page_for_context = random_data_array_item($individual_campaign_pages);
      $stubs[$i]['custom_fields']['field_page_context']['target_id'] = $page_for_context->page_id;
    }
    if ($rand == 2) {
      $page_for_context = random_data_array_item($team_campaign_pages);
      $stubs[$i]['custom_fields']['field_page_context']['target_id'] = $page_for_context->page_id;
    }
  }

  return $stubs;
}
