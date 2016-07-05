<?php
/**
 * @file
 * Default theme implementation for thermometer displays.
 *
 * @see template_preprocess_redhen_campaign_thermometer()
 */
?>

<?php if (!($is_front)): ?>
  <style type="text/css">
    .custom-thermometer .redhen-campaign-thermo-percent-bar-wrapper .redhen-campaign-thermo-percent-bar {background: red;}
  </style>
<?php else: ?>
  <style type="text/css">
    .redhen-campaign-thermo-percent-<?php print $id; ?> { width: <?php print $percent; ?>%; }
  </style>
<?php endif; ?>
<div class="redhen-campaign-thermo-percent-bar-wrapper">
  <div class="redhen-campaign-thermo-percent-bar redhen-campaign-thermo-percent-<?php print $id; ?>"></div>
</div>