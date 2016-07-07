<?php
/**
 * @file
 * Default theme implementation for thermometer displays.
 *
 * @see redhen_campaign_preprocess_redhen_campaign_thermometer()
 */
?>
<style type="text/css">
  .redhen-campaign-thermo-percent-<?php print $id; ?> { width: <?php print $percent; ?>%; }
  #block-bean-campaign-progress .custom-thermometer .redhen-campaign-thermo-percent-<?php print $id; ?> { width: 100%; background-position: center <?php print round($percent, -1) ?>%; }
</style>
<div class="redhen-campaign-thermo-percent-bar-wrapper">
  <div class="redhen-campaign-thermo-percent-bar redhen-campaign-thermo-percent-<?php print $id; ?>"></div>
</div>
