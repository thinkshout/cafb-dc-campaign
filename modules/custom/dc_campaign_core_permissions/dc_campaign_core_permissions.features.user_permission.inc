<?php
/**
 * @file
 * dc_campaign_core_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dc_campaign_core_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer google analytics'.
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'administer mailsystem'.
  $permissions['administer mailsystem'] = array(
    'name' => 'administer mailsystem',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'mailsystem',
  );

  // Exported permission: 'administer mandrill'.
  $permissions['administer mandrill'] = array(
    'name' => 'administer mandrill',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'mandrill',
  );

  // Exported permission: 'configure mandrill templates'.
  $permissions['configure mandrill templates'] = array(
    'name' => 'configure mandrill templates',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'mandrill_template',
  );

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'use text format email'.
  $permissions['use text format email'] = array(
    'name' => 'use text format email',
    'roles' => array(),
    'module' => 'filter',
  );

  return $permissions;
}
