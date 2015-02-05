<?php
/**
 * @file
 * redhen_raiser_custom_config.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function redhen_raiser_custom_config_default_rules_configuration() {
  $items = array();
  $items['rules_donation_complete'] = entity_import('rules_config', '{ "rules_donation_complete" : {
      "LABEL" : "Donation complete",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_google_analytics", "redhen_donation" ],
      "ON" : { "redhen_donation_donation_completed" : [] },
      "DO" : [
        { "commerce_google_analytics_save_ga_session_to_order" : { "commerce_order" : [ "commerce-transaction:order" ] } },
        { "commerce_google_analytics_send_order" : {
            "commerce_order" : [ "commerce-transaction:order" ],
            "method" : "default"
          }
        }
      ]
    }
  }');
  return $items;
}
