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
      "REQUIRES" : [ "rules", "redhen_donation" ],
      "ON" : { "redhen_donation_donation_completed" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "redhen-donation:entity" ], "type" : "redhen_campaign" } },
        { "entity_is_of_type" : {
            "entity" : [ "redhen-donation:transaction-entity" ],
            "type" : "commerce_order"
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "date", "value" : [ "commerce-transaction:changed" ] },
            "PROVIDE" : { "variable_added" : { "transaction_time" : "Transaction Time" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : [ "redhen-donation:entity:label" ] },
            "PROVIDE" : { "variable_added" : { "campaign_title" : "Campaign Label" } }
          }
        },
        { "mail" : {
            "to" : [ "redhen-donation:contact:email" ],
            "subject" : [ "redhen-donation:entity:url" ],
            "message" : "\\u003Cp\\u003EDear [redhen-donation:contact:first-name],\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EOn behalf of the Capital Area Food Bank (CAFB) staff, volunteers, community partners and those we serve, I would like to thank you for your generous gift of [redhen-donation:received] in support of the [campaign-title:value] campaign. This is our 34th year of helping to feed those in our community who struggle with hunger. The ability to do so is the direct result of your generous and caring support.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EDuring our past fiscal year, the Capital Area Food Bank distributed 42 million pounds of food, including over 17 million pounds of fruits and vegetables. Working together with out network of over 500 community partners, the CAFB provided 35 million meals to children, seniors and damilies experiencing hunger.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EIn addition to our core mission, we operate a number of direct service programs including Kids Cafe, Weekend Bag and Senior Brown Bag which serve thousands of children and adults every single month.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYour donation has given us a financial boost, but also, a morale boost. We strive every day to help our neighbors help themselves, and we are meeting this need thanks to you. Together, we can solve hunger.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYours sincerely,\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003ENancy E. Roman \\u003Cbr \\/\\u003E\\r\\nPresident \\u0026 CEO \\u003Cbr \\/\\u003E\\r\\nCapital Area Food Bank\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EIn accordance with Internal Revenue Services tax laws, we are acknowledging that you have not received any goods or services in return for this contribution.\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EBelow is a summary of your gift.\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003EAmount:\\u003C\\/strong\\u003E [redhen-donation:received]\\u003Cbr \\/\\u003E\\r\\n\\u003Cstrong\\u003EDate:\\u003C\\/strong\\u003E [transaction-time:value:custom:j\\/n\\/Y]\\u003Cbr \\/\\u003E\\r\\n\\u003Cstrong\\u003EPayment Method:\\u003C\\/strong\\u003E [commerce-transaction:payment-method-short-title]\\u003Cbr \\/\\u003E\\r\\n\\u003Cstrong\\u003ETransaction ID:\\u003C\\/strong\\u003E [commerce-transaction:remote-id] \\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E\\u003Cstrong\\u003EOn behalf of our staff, volunteers, community partners and those we serve, thank you again for your generous gift. Please save or print this receipt for your tax records.\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003ECapital Area Food Bank Tax ID (501(c)(3) # 52-1167581\\u003C\\/p\\u003E",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
