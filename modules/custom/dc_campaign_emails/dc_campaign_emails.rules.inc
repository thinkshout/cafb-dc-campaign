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

function dc_campaign_emails_rules_action_mail_token_replace($message, $settings, RulesState $state, RulesPlugin $element) {
  $message_body = $message;

  $new_body = token_replace($message_body, array(
    'redhen_donation' => $state->variables['redhen_donation']->value(),
    'transaction-time' => format_date($state->variables['transaction_time'], 'custom', 'n/j/Y', NULL),
    'commerce_transaction' => $state->variables['commerce_transaction'],
  ));
  $subtoken = array(
    'subtoken' => $new_body,
  );
  return $subtoken;
}
