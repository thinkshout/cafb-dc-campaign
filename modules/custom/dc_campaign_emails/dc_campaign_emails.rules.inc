<?php
/**
 * @file
 * Code for the DC Campaign Emails feature rules.
 */

/**
 * Implement hook_rules_action_info().
 */
function dc_campaign_emails_rules_action_info() {
  return array(
    'dc_campaign_emails_rules_mail_token_replace' => array(
      'label' => t('Replace tokens in email body'),
      'group' => t('Custom'),
      'parameter' => array(
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'description' => t("The mail's message body."),
        ),
      ),
      'base' => 'dc_campaign_emails_rules_action_mail_token_replace',
      'access callback' => 'rules_system_integration_access',
    ),
  );
}

// This callback creates the hashed string by using the parameters provided through rules' UI
function dc_campaign_emails_rules_action_mail_token_replace($message, $settings, RulesState $state, RulesPlugin $element) {

  $message = token_replace(token_replace($message), array('entity' => $state->variables['redhen_donation']->data));
echo "";
  //rules_action_mail($to, $subject, $message, $from = NULL, $langcode, $settings, $state, $element);

}
