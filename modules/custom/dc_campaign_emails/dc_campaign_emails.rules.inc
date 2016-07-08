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
      'provides' => array(
        'subtoken' => array(
          'type' => 'text',
          'label' => t('Subtoken'),
        ),
      ),
      'base' => 'dc_campaign_emails_rules_action_mail_token_replace',
      'access callback' => 'rules_system_integration_access',
    ),
  );
}

/**
 * Runs an addition token_replace so that the campaign can pass a custom email
 * token to the donation with tokens in it.
 */
function dc_campaign_emails_rules_action_mail_token_replace($message, $settings, RulesState $state, RulesPlugin $element) {
  $message_body = $message;

  $datetime = new DateTime();
  $datetime->setTimestamp($state->variables['transaction_time']);
  $new_body = token_replace($message_body, array(
    'redhen_donation' => $state->variables['redhen_donation']->value(),
    'transaction_time' => $datetime,
    'commerce_transaction' => $state->variables['commerce_transaction']->value(),
  ));
  $subtoken = array(
    'subtoken' => $new_body,
  );
  return $subtoken;
}
