<?php
/**
 * @file
 * dc_campaign_emails.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function dc_campaign_emails_default_rules_configuration() {
  $items = array();
  $items['rules_donation_acknowledgement'] = entity_import('rules_config', '{ "rules_donation_acknowledgement" : {
      "LABEL" : "Donation Acknowledgement",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "dc_campaign_emails", "redhen_donation" ],
      "ON" : { "redhen_donation_donation_completed" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "redhen-donation:entity" ], "type" : "redhen_campaign" } },
        { "entity_is_of_type" : {
            "entity" : [ "redhen-donation:transaction-entity" ],
            "type" : "commerce_order"
          }
        },
        { "entity_is_of_bundle" : {
            "entity" : [ "redhen-donation:redhen-campaign-context" ],
            "type" : "redhen_campaign",
            "bundle" : { "value" : { "general" : "general" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "date", "value" : [ "commerce-transaction:changed" ] },
            "PROVIDE" : { "variable_added" : { "transaction_time" : "Transaction Time" } }
          }
        },
        { "dc_campaign_emails_rules_mail_token_replace" : {
            "USING" : { "message" : [
                "redhen-donation:redhen-campaign-context:field-donation-acknowledgement"
              ]
            },
            "PROVIDE" : { "subtoken" : { "subtoken" : "Subtoken" } }
          }
        },
        { "mail" : {
            "to" : [ "redhen-donation:contact:email" ],
            "subject" : "thax",
            "message" : "[subtoken:value]\\r\\n\\u003Cdiv data-row=\\u0022[transaction_time:value:custom:n\\/j\\/Y][commerce_transaction:payment-method-short-title][commerce_transaction:remote-id]\\u0022\\u003E\\u003C\\/div\\u003E",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
