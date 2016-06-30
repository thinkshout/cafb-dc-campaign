<?php
/**
 * @file
 * redhen_raiser_custom_config.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function redhen_raiser_custom_config_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_donation_acknowledgement'.
  $field_bases['field_donation_acknowledgement'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_donation_acknowledgement',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
