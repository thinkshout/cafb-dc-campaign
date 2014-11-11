<?php
/**
 * @file
 * dc_campaign_emails.features.inc
 */

/**
 * Implements hook_default_mandrill_template_map().
 */
function dc_campaign_emails_default_mandrill_template_map() {
  $items = array();
  $items['standard'] = entity_import('mandrill_template_map', '{
    "name" : "standard",
    "label" : "Standard",
    "mailsystem_key" : "default-system",
    "template_id" : "standard",
    "main_section" : "content",
    "sections" : null,
    "author_uid" : "0",
    "created" : "0",
    "updated" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
