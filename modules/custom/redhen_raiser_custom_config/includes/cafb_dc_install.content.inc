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
 * Create users and link them to contacts.
 *
 * @param array $contacts
 *   Array of redhen_contact entities.
 *
 * @return array
 *   Array of updated redhen contact entities.
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
