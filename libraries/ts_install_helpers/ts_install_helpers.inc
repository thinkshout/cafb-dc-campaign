<?php

/**
 * Helper to create permissions for each role.
 * @param - $permissions
 *    An associative array of already instantiated Drupal user roles (usually exported via Features)
 *    Each array contains an array called 'permissions' which includes the machine names of each perm.
 *    In addition, because of the Features bug found at: http://drupal.org/node/1265168#comment-5810726,
 *        we pass in a second array called 'permissions_nocache' that contains arrays keyed off the module names of permissions
 *        we need to inject directly into the database.
 * @TODO - Monitor what's happening with this Features bug so that we can get rid of this latter hack.
 */
function ts_install_helpers_create_perms($permissions = array()) {
  $existing_roles = user_roles(); // Grab an array of roles that have been instantiated to this point.
  foreach($permissions as $name => $role) { // Iterate through our $permissions array.
    foreach($existing_roles as $rid => $existing_role) { // Check for matches, keying off human-readable role name.
      if ($name == $existing_role) {
        // Pass in a role ID and an array of permissions to apply to that role.
        user_role_grant_permissions($rid, $role['permissions']);
        // Then deal with our 'buggy' permissions that need to be inserted directly into the DB.
        if (isset($role['permissions_nocache'])) {
          foreach ($role['permissions_nocache'] as $module => $perms) {
            foreach($perms as $perm) {
              db_merge('role_permission')
                ->key(array(
                'rid' => $rid,
                'permission' => $perm,
              ))
                ->fields(array(
                'module' => $module,
              ))
                ->execute();
            }
          }
        }
      }
    }
  }
}

/**
 * Helper function for creating taxonomy terms and vocabularies.
 *
 * @param - $stubbed_vocabs
 *   An associative array of taxonomy vocabularies that contain terms.
 *   Supports nested arrays of hierarchical terms, as well as taxonomy term weighting.
 */
function ts_install_helpers_create_terms($stubbed_vocabs = array()) {
  $return_terms = array();
  foreach ($stubbed_vocabs as $vocab => $terms) {
    $vocabulary = taxonomy_vocabulary_machine_name_load($vocab);
    if (!$vocabulary) {
      $edit = array(
        'name' => $vocab,
        'machine_name' => $vocab,
        'module' => 'taxonomy',
      );
      $vocabulary = (object) $edit;
      taxonomy_vocabulary_save($vocabulary);
    }
    $return_terms[$vocab] = array();
    foreach ($terms as $new_term) {
      $return_terms[$vocab][] = ts_install_helpers_create_term($vocabulary, $new_term); // Create new terms, recursively.
    }
  }
  return $return_terms;
}

/**
 * Helper function for creating a single taxonomy term and its children, grandchildren, etc.
 */
function ts_install_helpers_create_term($vocabulary, $new_term, $parent_tid = 0) {
  $term = new stdClass();
  $term->name = $new_term['name'];
  $term->vid = $vocabulary->vid;
  $term->format = filter_fallback_format();
  $term->weight = (isset($new_term['weight'])) ? $new_term['weight'] : 0;
  $term->description = (isset($new_term['description'])) ? $new_term['description'] : NULL;
  $term->parent = $parent_tid;
  if (!empty($new_term['custom_fields'])) {
    foreach ($new_term['custom_fields'] as $field_id => $field_val) {
      // Handle single-cardinality:
      if (!isset($field_val[0])) {
        $field_val = array(0 => $field_val);
      }
      $term->{$field_id} = array(
        LANGUAGE_NONE => $field_val,
      );
    }
  }
  taxonomy_term_save($term);

  // If the current term has children defined, create them recursively.
  if (isset($new_term['children'])) {
    $term->children = array();
    foreach ($new_term['children'] as $child_term) {
      $term->children[] = ts_install_helpers_create_term($vocabulary, $child_term, $term->tid);
    }
  }
  return $term;
}


/**
 * Helper function for creating placeholder content.
 *
 * Returns an associative array of menu link items.
 *
 * @param - $stubbed_nodes
 *   An associative array of nodes to be created, keyed off the path of each new node.
 *
 */
function ts_install_helpers_create_content($stubbed_nodes = array(), $return_type = 'menus') {
  module_load_include('inc', 'devel_generate');
  module_load_include('inc', 'devel_generate', 'image.devel_generate');
  module_load_include('inc', 'devel_generate', 'devel_generate.fields');

  // Default node definition - stuff not captured added the way we want in node_object_prepare().
  $default_node = array(
    'type' => 'page',
    'language' => LANGUAGE_NONE,
    'format' => filter_fallback_format(),
    'uid' => 1,
    'body' => devel_create_greeking(120),
    'link_title' => '',
    'menu_name' => 'main-menu',
    'weight' => 0,
    'parent_path' => '',
    'expanded' => 0,
  );

  $prepared_nodes = array();
  foreach ($stubbed_nodes as $path => $stub) {
    // Merge nodes parameters defined in this install profile with some default values.
    $prepared_nodes[$path] = array_merge($default_node, $stub);
  }

  // Generate page nodes, optionally adding to an array of menu items to be created.
  $node_menu_items = array();
  $nodes_created = array();
  foreach ($prepared_nodes as $path => $prepared_node) {
    $node = new stdClass();
    $node->type = $prepared_node['type'];
    node_object_prepare($node);
    $node->title = $prepared_node['title'];
    $node->uid = $prepared_node['uid'];
    $node->language = $prepared_node['language'];
    if (isset($prepared_node['promote'])) {
      $node->promote = $prepared_node['promote'];
    }
    if (isset($prepared_node['status'])) {
      $node->status = $prepared_node['status'];
    }    $node->body[$node->language][0]['value'] = $prepared_node['body'];
    $node->body[$node->language][0]['summary'] = text_summary($node->body[$node->language][0]['value']);
    $node->body[$node->language][0]['format'] = $prepared_node['format'];
    $node->pathauto_perform_alias = FALSE;
    $node->path = array('alias' => $path, 'pathauto' => FALSE);
    if (!empty($prepared_node['custom_fields'])) {
      foreach ($prepared_node['custom_fields'] as $field_id => $field_val) {
        // Handle single-cardinality:
        if (!isset($field_val[0])) {
          $field_val = array(0 => $field_val);
        }
        $node->{$field_id} = array(
          $node->language => $field_val,
        );
      }
    }
    node_save($node);

    // Handle field_collection items.
    // @todo Abstract this into a method that takes an entity and an array of
    // field collection items definitions to add to the entity.
    if (!empty($prepared_node['field_collections'])) {
      foreach ($prepared_node['field_collections'] as $item_definition) {
        $field_collection_item = entity_create(
          'field_collection_item',
          array('field_name' => $item_definition['field_name'])
        );
        foreach ($item_definition['properties'] as $fc_prop => $fc_value) {
          $field_collection_item->{$fc_prop} = $fc_value;
        }
        $field_collection_item->setHostEntity('node', $node);
        $field_collection_item->save();
      }
    }

    $nodes_created[] = $node;

    // If a 'link title' has been set for the node, prep menu link creation.
    if (!empty($prepared_node['link_title'])) {
      $node_menu_items[$path] = array(
        'type' => 'node',
        'link_title' => $prepared_node['link_title'],
        'menu_name' => $prepared_node['menu_name'],
        'language' => $prepared_node['language'],
        'weight' => $prepared_node['weight'],
        'parent_path' => $prepared_node['parent_path'],
        'expanded' => $prepared_node['expanded'],
      );
    }
  }
  switch ($return_type) {
    case 'nodes':
      return $nodes_created;

    case 'both':
      return array('nodes' => $nodes_created, 'menus' => $node_menu_items);

    case 'menus':
  }

  return $node_menu_items;
}

/**
 * Helper function for creating menu items.
 *
 * @param - $stubbed_menu_items
 *   An associative array of menu items to be created, keyed off the path of each new menu item.
 *
 */
function ts_install_helpers_create_menu_items($stubbed_menu_items = array()) {

  // Reset the ctools exportables cache in case any of the router items are contained in exportables
  // Specifically needed for links to custom apachesolr_search pages
  if (module_exists('ctools')) {
    ctools_export_load_object_reset();
  }

  // Rebuild prior to starting menu creation to capture menu items built by other modules, like the contact module.
  menu_rebuild();

  $default_item = array(
    'type' => 'codefied', // Nodes created in the install profile have 'node' type. Otherwise, assume 'codefied' as default.
    'menu_name' => 'main-menu',
    'weight' => 0,
    'parent_path' => '',
  );

  $prepared_menu_items = array();
  $new_menus = array();
  $existing_menus = array_keys(menu_get_menus());
  foreach ($stubbed_menu_items as $path => $stubbed_item) {
    // Merge menu parameters defined in the install profile with some default values.
    $prepared_menu_items[$path] = array_merge($default_item, $stubbed_item);
    // Check if referenced menu exists - if not, we'll create it.
    if (!empty($stubbed_item['menu_name'])) {
      if (!in_array($stubbed_item['menu_name'], $existing_menus)) {
        $new_menus[] = array('menu_name' => $stubbed_item['menu_name']);
      }
    }
  }

  // Create new menus.
  foreach ($new_menus as $menu) {
    if (isset($menu['menu_name'])) {
      $menu['title'] = ucwords(str_replace('-', ' ', $menu['menu_name']));
      $menu['description'] = $menu['title'];
      menu_save($menu);
    }
  }

  // Start creating menu items. @TODO - Debug certain menu item creating steps that require passing in 'module' parameter.
  foreach ($prepared_menu_items as $path => $item) { // First time around the horn, save menu links.
    $prepared_menu_items[$path]['link_path'] = drupal_get_normal_path($path);
    $prepared_menu_items[$path]['mlid'] = menu_link_save($prepared_menu_items[$path]);
  }

  foreach ($prepared_menu_items as $item) { // Second time around the horn, set an parent link ids need for menu hierarchy.
    if (!empty($item['parent_path'])) {
      $item['parent_path'] = drupal_get_normal_path($item['parent_path']);
      $plid = db_query("SELECT mlid FROM {menu_links} WHERE menu_name = :menu_name AND link_path = :link_path",
        array(
          ':menu_name' => $item['menu_name'],
          ':link_path' => $item['parent_path'],
        )
      )->fetchfield();
      $item['plid'] = $plid;
      menu_link_save($item);
    }
  }

  // Clear the menu cache to get rid of any funkiness.
  menu_cache_clear_all();
}
/**
 * Helper to create beans.
 * @TODO - Add validation and error handling..
 */
function ts_install_helpers_create_beans($stubbed_beans) {
  foreach ($stubbed_beans as $name => $stubbed_bean) {
    $new_bean = bean_create(array('type' => $stubbed_bean['type']));
    $new_bean->label = $stubbed_bean['label'];
    $new_bean->title = $stubbed_bean['title'];
    $new_bean->delta = $name;
    if (!empty($stubbed_bean['data'])) {
      $new_bean->data = $stubbed_bean['data'];
    }
    foreach ($stubbed_bean['properties'] as $prop => $value) {
      $new_bean->{$prop} = $value;
    }
    $new_bean->save();

    // Handle field_collection items.
    if (!empty($stubbed_bean['field_collections'])) {
      foreach ($stubbed_bean['field_collections'] as $item_definition) {
        $field_collection_item = entity_create(
          'field_collection_item',
          array('field_name' => $item_definition['field_name'])
        );
        foreach ($item_definition['properties'] as $fc_prop => $fc_value) {
          $field_collection_item->{$fc_prop} = $fc_value;
        }
        $field_collection_item->setHostEntity('bean', $new_bean);
        $field_collection_item->save();
      }
    }
  }
}

/**
 * Helper to create a test user account for each logged-in role.
 * @param - $gmail_user
 *     A gmail user name for creating placeholder email. Generally, TS creates a Google group for each project,
 *     such as example@thinkshout.com. We use this address to create an account per address, such as example+admin@thinkshout.com.
 * @param - $gmail_domain
 *     Defaults to 'thinkshout.com.', though optionally a different domain can be passed into this helper.
 */
function ts_install_helpers_create_test_users($gmail_user = 'example', $gmail_domain = 'thinkshout.com') {
  $roles = user_roles(TRUE);
  foreach($roles as $rid => $role) {
    $edit = array(); // Collection of parameters to pass to new user account.
    $edit['name'] = $role;
    $edit['mail'] = $gmail_user . '+' . str_replace(" ","_",$role) . '@' . $gmail_domain; // Google test email account.
    $edit['init'] = $edit['mail'];
    $edit['pass'] = $role; // Set the password to the role human-readable name.
    $edit['roles'] = array($rid => $role); // Provide associated role.
    $edit['status'] = 1; // Activate account.
    user_save('', $edit);
  }
}
/**
 * Helper function for creating commerce products, including recurring types.
 *
 * @param - $stubbed_products
 *  associative array of products to be created, keying off the machine name
 *  and containing these values (required unless noted):
 *  'type' (an existing product type like 'product')
 *  'sku'
 *  'title'
 *  'price'
 *  'recurrence' (not required unless 'type' is 'recurring': can be 'day'
 *                'month', 'year', etc. See commerce_recurring module)
 *
 */
function ts_install_helpers_create_products($stubbed_products = array()) {
  foreach($stubbed_products as $machine_name => $values) {
    if (!variable_get($machine_name, FALSE)) {
      $form_state = array();
      $form_state['values'] = array();
      $form = array();
      $form['#parents'] = array();
      // Generate a new product object
      $new_product = commerce_product_new($values['type']);
      $new_product->status = TRUE;
      $new_product->uid = 1;
      $new_product->sku = $values['sku'];
      $new_product->title = t($values['title']);
      $new_product->created = $new_product->changed = time();

      //commerce_price[und][0][amount]
      $price = array(LANGUAGE_NONE => array(0 => array(
        'amount' => $values['price'],
        'currency_code' => commerce_default_currency(),
      )));
      $form_state['values']['commerce_price'] = $price;
      //allow for an array of custom field values to be passed in:
      //(this needs work)
      //if (isset($values['custom_fields']))
      //  foreach($values['custom_fields'] as $field => $val) {
      //    $new_product->$field = $val;
      //    $form_state['values'][$field] = $val;
      //  };
      //commerce_recurring_interval[und][0][interval]
      if ($values['type'] == 'recurring') {
        $interval = 1;
        if ($values['recurrence'] == 'year'){
          $values['recurrence'] = 'month';
          $interval = 12;
        }
        $recurrence = array(LANGUAGE_NONE => array(0 => array(
          'interval' => $interval,
          'period' => $values['recurrence'],
        )));
        $form_state['values']['commerce_recurring_interval'] = $recurrence;
      }
      // Notify field widgets to save their field data
      field_attach_submit('commerce_product', $new_product, $form, $form_state);

      commerce_product_save($new_product);

      variable_set($machine_name, $new_product->product_id);
    }
  }
}

/**
 * Creates an entity instance of any type. Useful for custom entity types.
 *
 * @param array of $stubbed_entities
 *    Each should have 3 or 4 fields:
 *    'type' => entity type
 *    'bundle' => entity bundle
 *    'properties' => entity built-in fields. 'label', often, etc.
 *    'fields' => for fields added to the entity through the Drupal interface,
 *      for "fieldable entities." Not required.
 *
 * @return array
 *   Array of created entities.
 */
function ts_install_helpers_create_entities($stubbed_entities) {
  $new_entities = array();

  foreach ($stubbed_entities as $entity) {
    $new_entity = entity_create($entity['type'], array('type' => $entity['bundle']));
    $language = isset($entity['language']) ? $entity['language'] : LANGUAGE_NONE;
    // Note: If no properties are set, no entity is created!
    foreach ($entity['properties'] as $prop => $value) {
      $new_entity->{$prop} = $value;
    }
    if (isset($entity['fields'])) {
      foreach ($entity['fields'] as $prop => $value) {
        // Handle single-cardinality:
        if (!isset($value[0])) {
          $value = array(0 => $value);
        }
        $new_entity->{$prop} = array($language => $value);
      }
    }
    $new_entity->save();
    $new_entities[] = $new_entity;
  }

  return $new_entities;
}

/**
 * Helper function for saving placeholder file fields.
 *
 * @param string $filename
 *   Name that file should have after being saved.
 * @param string $filepath
 *   Place to put the saved file.
 * @param string $url
 *   Source of file, e.g. http://lorempixel.com/800/600/.
 *
 * @return int
 *   The fid of the newly saved file.
 */
function ts_install_helpers_copy_file($filename, $filepath, $url) {
  if (file_put_contents($filepath, file_get_contents($url))) {
    $file = new StdClass();
    $file->uid = 1;
    $file->uri = $filepath;
    $file->filename = $filename;
    $file->filemime = file_get_mimetype($file->uri);
    $file->status = 1;

    $file = file_save($file);

    return $file->fid;
  }
  return FALSE;
}


/**
 * Return an image from a random generator.
 *
 * @param $width
 * @param $height
 */
function ts_install_helpers_image_source($width, $height) {
  $generators = array(
    "http://lorempixel.com/$width/$height/",
    "http://hhhhold.com/{$width}x{$height}/",
    "http://placeimg.com/$width/$height/any",
    "http://placekitten.com/g/$width/$height",
    "http://placecreature.com/$width/$height",
  );

  $index = rand(0, count($generators) - 1);

  return $generators[$index];
}

/** Create an image file and return the file object.
 *
 * Includes logic for discontinuing use of slow image providers.
 */
function ts_install_helpers_generate_image($width, $height, $image_name, $image_destination) {
  global $generators;
  if (is_null($generators)) {
    $generators = array(
      "http://lorempixel.com/$width/$height/",
      "http://hhhhold.com/{$width}x{$height}/",
      "http://placeimg.com/$width/$height/any",
      "http://placekitten.com/g/$width/$height",
      "http://placecreature.com/$width/$height",
    );
  }
  $image_file_id = 0;
  while (!$image_file_id) {
    $start = time();
    $index = array_rand($generators);
    $image_source = $generators[$index];
    $image_file_id = ts_install_helpers_copy_file($image_name, $image_destination, $image_source);
    if ((time() - 10) > $start || !$image_file_id) {
      // This service is taking too long. Remove it from the options.
      if (count($generators) == 1) {
        // Oops! we ran out. Maybe one of the other ones has stopped sucking:
        $generators = array(
          "http://lorempixel.com/$width/$height/",
          "http://hhhhold.com/{$width}x{$height}/",
          "http://placeimg.com/$width/$height/any",
          "http://placekitten.com/g/$width/$height",
          "http://placecreature.com/$width/$height",
        );
      }
      else {
        unset($generators[$index]);
      }
    }
  }
  $image_file = file_load($image_file_id);
  return $image_file;
}
