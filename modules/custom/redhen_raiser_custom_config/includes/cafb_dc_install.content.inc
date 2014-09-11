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
