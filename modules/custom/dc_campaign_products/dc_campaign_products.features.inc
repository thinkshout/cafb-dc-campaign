<?php
/**
 * @file
 * dc_campaign_products.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function dc_campaign_products_commerce_product_default_types() {
  $items = array(
    'product' => array(
      'type' => 'product',
      'name' => 'Product',
      'description' => 'A basic product type.',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_default_redhen_donation_type().
 */
function dc_campaign_products_default_redhen_donation_type() {
  $items = array();
  $items['redhen_raiser_donation'] = entity_import('redhen_donation_type', '{
    "name" : "redhen_raiser_donation",
    "label" : "RedHen Raiser Donation",
    "locked" : "0",
    "weight" : "0",
    "data" : null,
    "settings" : {
      "contact_settings" : {
        "contact_type" : "contact",
        "update_fields" : 1,
        "fields" : { "field_organization" : "field_organization", "middle_name" : 0 },
        "profile_selector" : "field_billing_address"
      },
      "commerce_settings" : {
        "one_time_product_type" : "donation",
        "line_item_type" : "redhen_raiser_donation",
        "product_options" : {
          "product_select_label" : "",
          "one_time_product" : "1",
          "recurring" : []
        },
        "payment_methods" : [
          {
            "payment_method" : "iats_credit_card|rules_iats_payments_credit_card_payment_cafb",
            "label" : "",
            "currency" : "USD",
            "delete" : "Delete"
          }
        ]
      }
    }
  }');
  return $items;
}
