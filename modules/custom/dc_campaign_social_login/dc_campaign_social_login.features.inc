<?php
/**
 * @file
 * dc_campaign_social_login.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dc_campaign_social_login_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
