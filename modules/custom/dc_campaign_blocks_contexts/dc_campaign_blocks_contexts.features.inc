<?php
/**
 * @file
 * dc_campaign_blocks_contexts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dc_campaign_blocks_contexts_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
