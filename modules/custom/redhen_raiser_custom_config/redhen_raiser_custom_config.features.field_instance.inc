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
        'value' => 'Dear [redhen-donation:contact:first-name],

On behalf of the Capital Area Food Bank (CAFB) staff, volunteers, community partners and those we serve, I would like to thank you for your generous gift of [redhen-donation:received] in support of the [redhen-donation:redhen-campaign-context:label] campaign. This is our 35th year of helping to feed those in our community who struggle with hunger. The ability to do so is the direct result of your generous and caring support.\\\\u003C\\\\/p\\\\u003E\\\\r\\\\n\\\\r\\\\n\\\\u003Cp\\\\u003ELast year, the Capital Area Food Bank distributed 42 million pounds of food \\\\u2014 a third of which are fruits and vegetables. Working together with out network of over 500 community partners, the CAFB provided 35 million meals to children, seniors and families experiencing hunger.\\\\u003C\\\\/p\\\\u003E\\\\r\\\\n\\\\r\\\\n\\\\u003Cp\\\\u003EIn addition to our core mission, we operate a number of direct service programs including Kids Cafe, Weekend Bag and Senior Brown Bag which serve thousands of children and adults every single month.\\\\u003C\\\\/p\\\\u003E\\\\r\\\\n\\\\r\\\\n\\\\u003Cp\\\\u003EYour donation has given us a financial boost, but also, a morale boost. We strive every day to help our neighbors help themselves, and we are meeting this need thanks to you. Together, we can solve hunger.\\\\u003C\\\\/p\\\\u003E\\\\r\\\\n\\\\r\\\\n\\\\u003Cp\\\\u003EYours sincerely,\\\\u003C\\\\/p\\\\u003E\\\\r\\\\n\\\\u003Cp\\\\u003ENancy E. Roman \\\\u003Cbr \\\\/\\\\u003E\\\\r\\\\nPresident \\\\u0026 CEO \\\\u003Cbr \\\\/\\\\u003E\\\\r\\\\nCapital Area Food Bank\\\\u003C\\\\/p\\\\u003E\\\\r\\\\n\\\\u003Cp\\\\u003EIn accordance with Internal Revenue Services tax laws, we are acknowledging that you have not received any goods or services in return for this contribution.\\\\u003C\\\\/p\\\\u003E\\\\r\\\\n\\\\u003Cp\\\\u003EBelow is a summary of your gift.\\\\u003C\\\\/p\\\\u003E\\\\r\\\\n\\\\u003Cp\\\\u003E\\\\u003Cstrong\\\\u003EAmount:\\\\u003C\\\\/strong\\\\u003E [redhen-donation:received]\\\\u003Cbr \\\\/\\\\u003E\\\\r\\\\n\\\\u003Cstrong\\\\u003ETax Deductible Amount:\\\\u003C\\\\/strong\\\\u003E[redhen-donation:field_tax_deductible_amount]\\\\u003Cbr \\\\/\\\\u003E\\\\r\\\\n\\\\u003Cstrong\\\\u003EDate:\\\\u003C\\\\/strong\\\\u003E [transaction-time:value:custom:n\\\\/j\\\\/Y]\\\\u003Cbr \\\\/\\\\u003E\\\\r\\\\n\\\\u003Cstrong\\\\u003EPayment Method:\\\\u003C\\\\/strong\\\\u003E [commerce-transaction:payment-method-short-title]\\\\u003Cbr \\\\/\\\\u003E\\\\r\\\\n\\\\u003Cstrong\\\\u003ETransaction ID:\\\\u003C\\\\/strong\\\\u003E [commerce-transaction:remote-id] \\\\u003C\\\\/p\\\\u003E\\\\r\\\\n\\\\u003Cp\\\\u003E\\\\u003Cstrong\\\\u003EOn behalf of our staff, volunteers, community partners and those we serve, thank you again for your generous gift. Please save or print this receipt for your tax records.\\\\u003C\\\\/strong\\\\u003E\\\\u003C\\\\/p\\\\u003E\\\\r\\\\n\\\\u003Cp\\\\u003ECapital Area Food Bank Tax ID (501(c)(3) # 52-1167581\\\\u003C\\\\/p\\\\u003E',
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
