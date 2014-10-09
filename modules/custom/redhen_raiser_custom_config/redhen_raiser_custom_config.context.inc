<?php
/**
 * @file
 * redhen_raiser_custom_config.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function redhen_raiser_custom_config_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cafb_campaign_home';
  $context->description = 'Blocks for campaigns on CAFB';
  $context->tag = 'CAFB';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'campaigns/*' => 'campaigns/*',
        '~campaigns/*/*' => '~campaigns/*/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-donation-matching' => array(
          'module' => 'bean',
          'delta' => 'donation-matching',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks for campaigns on CAFB');
  t('CAFB');
  $export['cafb_campaign_home'] = $context;

  return $export;
}
