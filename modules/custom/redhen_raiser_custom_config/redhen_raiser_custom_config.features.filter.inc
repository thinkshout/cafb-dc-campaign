<?php
/**
 * @file
 * redhen_raiser_custom_config.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function redhen_raiser_custom_config_filter_default_formats() {
  $formats = array();

  // Exported format: Email.
  $formats['email'] = array(
    'format' => 'email',
    'name' => 'Email',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_autop' => array(
        'weight' => -50,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd><br><p><img>',
          'filter_html_help' => 0,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_url' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
    ),
  );

  return $formats;
}
