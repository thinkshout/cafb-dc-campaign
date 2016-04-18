<?php

/**
 * @file site.settings.php
 * Add site-wide settings here, which will be included from settings.php
 */

$conf['install_profile'] = 'redhen_raiser';

// Require SSL.
if (isset($_SERVER['PANTHEON_ENVIRONMENT'])) {
  if (!isset($_SERVER['HTTP_X_SSL']) || (isset($_SERVER['HTTP_X_SSL']) && $_SERVER['HTTP_X_SSL'] != 'ON')) {
    // The pantheon environments that allow ssl connections
    $dests = array(
      'live' => 'give.capitalareafoodbank.org',
      'test' => 'test-dc-campaign.pantheon.io',
      'dev' => 'dev-dc-campaign.pantheon.io',
    );
    // Only redirect to ssl if it is one of the environments that supports it
    if(isset($dests[$_SERVER['PANTHEON_ENVIRONMENT']])) {
     header('HTTP/1.0 301 Moved Permanently');
      header('Location: https://' . $dests[$_SERVER['PANTHEON_ENVIRONMENT']] . $_SERVER['REQUEST_URI']);
      exit();
    }
  }
}