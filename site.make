;======================================
; Charlotte's Web
; A sample implementation of
; RedHen Raiser Distribution
;
; by ThinkShout
;======================================
api = 2
core = 7.x

; Download the RedHen Raiser install profile and recursively build all its dependencies:
projects[redhen_raiser][type] = profile
projects[redhen_raiser][download][type] = git
projects[redhen_raiser][download][url] = "git@git.drupal.org:project/redhen_raiser.git"
projects[redhen_raiser][download][branch] = '7.x-1.x'
projects[redhen_raiser][download][revision] = '429ea44'


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
projects[commerce_iats][version] = '2.9'

; google_analytics
projects[google_analytics][subdir] = 'contrib'
projects[google_analytics][version] = '2.1'

; commerce_google_analytics
projects[commerce_google_analytics][subdir] = 'contrib'
projects[commerce_google_analytics][version] = '1.1'

; mailsystem
projects[mailsystem][subdir] = 'contrib'
projects[mailsystem][version] = '2.34'

; mandrill
projects[mandrill][subdir] = 'contrib'
projects[mandrill][version] = '2.0'

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

;-----------------------------------------
; Themes
;-----------------------------------------
