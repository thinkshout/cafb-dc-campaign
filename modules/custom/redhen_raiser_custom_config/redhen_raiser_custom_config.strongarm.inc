<?php
/**
 * @file
 * redhen_raiser_custom_config.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function redhen_raiser_custom_config_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mail_system';
  $strongarm->value = array(
    'default-system' => 'MandrillMailSystem',
    'mandrill_test' => 'MandrillMailSystem',
    'rules_rules_action_mail_rules_donation_acknowledgement_4' => 'MandrillMailSystem',
    'redhen_campaign_invite' => 'MandrillMailSystem',
  );
  $export['mail_system'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mandrill_from';
  $strongarm->value = 'support@capitalareafoodbank.org';
  $export['mandrill_from'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mandrill_from_name';
  $strongarm->value = 'Capital Area Food Bank of DC';
  $export['mandrill_from_name'] = $strongarm;

  return $export;
}
