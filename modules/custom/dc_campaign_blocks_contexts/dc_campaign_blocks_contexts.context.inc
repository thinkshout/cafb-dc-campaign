<?php
/**
 * @file
 * dc_campaign_blocks_contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dc_campaign_blocks_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_dc';
  $context->description = 'Context applied to all non-admin pages (DC site specific)';
  $context->tag = 'Food Bank of DC';
  $context->conditions = array(
    'admin_theme' => array(
      'values' => array(
        'non_admin' => 'non_admin',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'redhen_raiser_blocks-tax_exempt_status' => array(
          'module' => 'redhen_raiser_blocks',
          'delta' => 'tax_exempt_status',
          'region' => 'navigation',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context applied to all non-admin pages (DC site specific)');
  t('Food Bank of DC');
  $export['sitewide_dc'] = $context;

  return $export;
}
