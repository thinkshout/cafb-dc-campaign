;======================================
; Capital Area Foodbank of DC Campaigns
; An implementation of
; RedHen Raiser Distribution
;
; by ThinkShout
;======================================
api = 2
core = 7.x

; Download the RedHen Raiser install profile and recursively build all its dependencies:
projects[redhen_raiser][type] = profile
projects[redhen_raiser][version] = '1.11'
projects[redhen_raiser][patch][] = https://www.drupal.org/files/issues/redhen_raiser-add-billing-address-2542948.patch
projects[redhen_raiser][patch][] = https://www.drupal.org/files/issues/allow_for_blank_address_input-2726781-2.patch
projects[redhen_raiser][patch][] = https://www.drupal.org/files/issues/allow_donation_editing-2726807-2.patch

; redhen_donation
; Add patches to donation for product support
; Note that we replace the version of redhen_donation provided by raiser.
; Use the latest version of redhen_donation from the github dev branch
projects[redhen_donation][download][type] = git
projects[redhen_donation][download][url] = git@github.com:thinkshout/redhen_donation.git
projects[redhen_donation][download][branch] = donation_edit
projects[redhen_donation][version] = "1.2"
projects[redhen_donation][subdir] = "contrib"
; Keep using this patch that adds a drupal_alter until we switch to the invoke all that got committed as part of 2640726
projects[redhen_donation][patch][] = https://www.drupal.org/files/issues/redhen_donation-add-order-alter-2557497.patch

; Add the ability to re-allocate donations to different campaign pages.
projects[redhen_campaign][patch][] = "https://www.drupal.org/files/issues/redhen_campaign-2708871-6-campaign_add_edit_recalculate.patch"

; Fix bug in $contact->upsert() function
projects[redhen][patch][] = https://www.drupal.org/files/issues/redhen-2711981-2-redhen_contact_upsert_get_existing.patch

;======================================
; Use standard drush make syntax
; to customize your site. Take a
; close look at the redhen_raiser.make
; to avoid downloading duplicate or
; conflicting modules, libraries, or
; themes.
;
; These items will be placed in
; sites/all/. Make sure to include the
; [destination] as in the examples.
;
; A couple of recommended modules are
; included as examples: feel free to
; remove them.
;======================================

;======================================
; Modules
;======================================

; commerce_iats
projects[commerce_iats][subdir] = 'contrib'
projects[commerce_iats][version] = '2.11'

; google_analytics
projects[google_analytics][subdir] = 'contrib'
projects[google_analytics][version] = '2.1'

; ga_push
projects[ga_push][subdir] = 'contrib'
projects[ga_push][version] = '1.0'

; commerce_google_analytics
projects[commerce_google_analytics][subdir] = 'contrib'
projects[commerce_google_analytics][version] = '2.0-beta2'

; hybridauth
projects[hybridauth][subdir] = 'contrib'
projects[hybridauth][version] = '2.13'

; mailsystem
projects[mailsystem][subdir] = 'contrib'
projects[mailsystem][version] = '2.34'

; mandrill
projects[mandrill][subdir] = 'contrib'
projects[mandrill][version] = '2.2'

;======================================
; Libraries
;======================================

; ts_install_helpers
libraries[ts_install_helpers][download][type] = git
libraries[ts_install_helpers][download][url] = git@github.com:thinkshout/ts_install_helpers.git
libraries[ts_install_helpers][directory_name] = "ts_install_helpers"
libraries[ts_install_helpers][type] = "library"

; IATS Payment library
libraries[iatspayments][destination] = "libraries"
libraries[iatspayments][download][type] = "get"
libraries[iatspayments][download][url] = "https://github.com/iATSPayments/PHP/archive/v1.3.tar.gz"
libraries[iatspayments][directory_name] = "iatspayments"

; mandrill library
libraries[mandrill][destination] = "libraries"
libraries[mandrill][download][type] = "get"
libraries[mandrill][download][url] = "https://bitbucket.org/mailchimp/mandrill-api-php/get/1.0.52.tar.gz"
libraries[mandrill][directory_name] = "mandrill"

; hybridauth library
libraries[hybridauth][destination] = "libraries"
libraries[hybridauth][download][type] = "get"
libraries[hybridauth][download][url] = "https://github.com/hybridauth/hybridauth/archive/v2.3.0.tar.gz"
libraries[hybridauth][directory_name] = "hybridauth"

;-----------------------------------------
; Themes
;-----------------------------------------
