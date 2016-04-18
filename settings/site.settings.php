<?php

/**
 * @file site.settings.php
 * Add site-wide settings here, which will be included from settings.php
 */

$conf['install_profile'] = 'redhen_raiser';

// Require SSL for all pantheon environments
if (isset($_SERVER['PANTHEON_ENVIRONMENT'])) {
  if (!isset($_SERVER['HTTP_X_SSL']) || (isset($_SERVER['HTTP_X_SSL']) && $_SERVER['HTTP_X_SSL'] != 'ON')) {
    header('HTTP/1.0 301 Moved Permanently');
    header('Location: https://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);
    exit();
  }
}