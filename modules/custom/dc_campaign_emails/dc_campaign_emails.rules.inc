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
        'roles' => array(
          'type' => 'list<integer>',
          'label' => t('Roles'),
          'options list' => 'entity_metadata_user_roles',
          'description' => t('Select the roles whose users should receive the mail.'),
        ),
        'subject' => array(
          'type' => 'text',
          'label' => t('Subject'),
          'description' => t("The mail's subject."),
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'description' => t("The mail's message body."),
        ),
        'from' => array(
          'type' => 'text',
          'label' => t('From'),
          'description' => t("The mail's from address. Leave it empty to use the site-wide configured address."),
          'optional' => TRUE,
        ),
      ),
      'base' => 'dc_campaign_emails_rules_action_mail_token_replace',
      'access callback' => 'rules_system_integration_access',
    ),
  );
}

// This callback creates the hashed string by using the parameters provided through rules' UI
function dc_campaign_emails_rules_action_mail_token_replace($settings, RulesState $state, RulesPlugin $element) {

//  $message = token_replace($message, array('redhen-donation' => entity_load('redhen_donation')));

  //rules_action_mail($to, $subject, $message, $from = NULL, $langcode, $settings, $state, $element);

}
