<?php

/**
 * Implement hook_install_tasks().
 * We hook into the install process to add our own tasks prior to Drupal's final step in the default install process.
 */

function cafb_dc_install_tasks(){
  $taskset = array(
    'cafb_dc_custom_install' => array(
      'display_name' => st('Thinkshout Site Setup'),
    ),
  );
  return $taskset;
}


/**
 * Post install tasks
 */
function cafb_dc_custom_install(&$install_state) {
  include_once 'libraries/ts_install_helpers/ts_install_helpers.inc'; // Load helper functions.
  // Disable DB blocks so we can use context to place everything.
  if (module_exists('block')) {
    db_update('block')
      ->fields(array(
        'status' => 0,
        'region' => ''))
      ->execute();
  }
  drupal_flush_all_caches();
  features_revert();
}