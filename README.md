# Capital Area Food Bank DC - Campaign 

To set up a local build, run:
`composer install`

Create a new local MySQL database.

Then run:
`scripts/build.sh ~/Sites/<LOCAL FOLDER NAME YOU WANT> <LOCAL DATABASE USERNAME> <LOCAL DATABASE PASSWORD> <LOCAL DATABASE NAME>` to build the complete site in the ~/Sites/<LOCAL FOLDER NAME YOU WANT>
directory.

`scripts/deploy.sh` to deploy the site to its destination host, such as Pantheon
or Acquia (more information: https://github.com/thinkshout/ts_build_scripts/blob/master/README.md).

Donation links will not appear until you enable donations for at least one
Campaign, and you can't do that until you enable at least one payment processor.

Go to admin/commerce/config/payment-methods and enable the "iATS Payments:
Credit card payment" processor. You can then edit the Action in this rule and
set the Agent Code/Password both to "TEST88".

You can then visit your Campaign, click the "Manage Donations" tab, then click
"Settings". You'll want to Enable donations, select "Donation" as the one-time
product type, and select "Billing Address" for the billing profile.

This will enable you to process test payments using the CC# 4222222222222220.
The other values (date, etc) don't matter.

## Site structure notes ##
Manage and create Campaigns:
admin/content/redhen_campaign

Manage Campaign Pages/Fundraisers:
admin/content/redhen_campaign_page

Create Campaign types: 
admin/structure/redhen/campaign_types

Create Campaign page types: 
admin/structure/redhen/page_types
