# Capital Area Food Bank DC - Campaign 

Run:

`scripts/build.sh ../drupal` to build the complete site in a sibling "drupal"
directory.

`scripts/deploy.sh` to deploy the site to its destination host, such as Pantheon
or Acquia.

Donation links will not appear until you enable donations for at least one
Campaign, and you can't do that until you enable at least one payment processor.

Go to admin/commerce/config/payment-methods and enable the "iATS Payments:
Credit card payment" processor. You can then edit the Action in this rule and
set the login/password both to "TEST88".

You can then visit your Campaign, click the "Manage Donations" tab, then click
"Settings". You'll want to Enable donations, select "Donation" as the one-time
product type, and select "Billing Address" for the billing profile.

This will enable you to process test payments using the CC# 4222222222222220.
The other values (date, etc) don't matter.
