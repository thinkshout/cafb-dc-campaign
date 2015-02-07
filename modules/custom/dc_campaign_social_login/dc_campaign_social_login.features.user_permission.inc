<?php
/**
 * @file
 * dc_campaign_social_login.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dc_campaign_social_login_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use hybridauth'.
  $permissions['use hybridauth'] = array(
    'name' => 'use hybridauth',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'hybridauth',
  );

  return $permissions;
}
