<?php
/**
 * @file
 * redhen_raiser_custom_config.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function redhen_raiser_custom_config_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'redhen_campaign-general-field_donation_acknowledgement'.
  $field_instances['redhen_campaign-general-field_donation_acknowledgement'] = array(
    'bundle' => 'general',
    'default_value' => array(
      0 => array(
        'value' => 'Dear [redhen_donation:contact:first-name],

On behalf of the Capital Area Food Bank (CAFB) staff, volunteers, community partners and those we serve, I would like to thank you for your generous gift of [redhen_donation:received] in support of the [redhen_donation:redhen-campaign-context:label] campaign. This is our 35th year of helping to feed those in our community who struggle with hunger. The ability to do so is the direct result of your generous and caring support.

Last year, the Capital Area Food Bank distributed 42 million pounds of food &#8212; a third of which are fruits and vegetables. Working together with out network of over 500 community partners, the CAFB provided 35 million meals to children, seniors and families experiencing hunger.

In addition to our core mission, we operate a number of direct service programs including Kids Cafe, Weekend Bag and Senior Brown Bag which serve thousands of children and adults every single month.

Your donation has given us a financial boost, but also, a morale boost. We strive every day to help our neighbors help themselves, and we are meeting this need thanks to you. Together, we can solve hunger.

Yours sincerely,
Nancy E. Roman
President & CEO
Capital Area Food Bank

In accordance with Internal Revenue Services tax laws, we are acknowledging that you have not received any goods or services in return for this contribution.

Below is a summary of your gift.
Amount: [redhen_donation:received]
Tax Deductible Amount: [redhen_donation:field_tax_deductible_amount]
Date: [dc_campaign_donation:transaction_date]
Payment Method: [dc_campaign_donation:transaction_payment_method]
Transaction ID: [dc_campaign_donation:transaction_remote_id]

On behalf of our staff, volunteers, community partners and those we serve, thank you again for your generous gift. Please save or print this receipt for your tax records.

Capital Area Food Bank Tax ID (501(c)(3) # 52-1167581',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'contextual_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'progress' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'promotion' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'redhen_campaign',
    'field_name' => 'field_donation_acknowledgement',
    'label' => 'Donation Acknowledgement Message',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'email' => 'email',
          'plain_text' => 'plain_text',
          'rich_text' => 'rich_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'email' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
            'rich_text' => array(
              'weight' => 0,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 35,
    ),
  );

  // Exported field_instance: 'redhen_campaign-general-field_thermometer'.
  $field_instances['redhen_campaign-general-field_thermometer'] = array(
    'bundle' => 'general',
    'deleted' => 0,
    'description' => 'The custom thermometer image. Should be 1375 px high and 225 px wide.',
    'display' => array(
      'banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'contextual_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'progress' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'promotion' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'redhen_campaign',
    'field_name' => 'field_thermometer',
    'label' => 'Thermometer',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '225x1375',
      'min_resolution' => '225x1375',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
          'vimeo' => 0,
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'default' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 36,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Donation Acknowledgement Message');
  t('The custom thermometer image. Should be 1375 px high and 225 px wide.');
  t('Thermometer');

  return $field_instances;
}
