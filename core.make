api = 2
core = 7.x
; Pull in the recommended core version:
;includes[] = "drupal-org-core.make"

projects[drupal][download][type] = "git"
projects[drupal][download][url] = "https://github.com/pantheon-systems/drops-7.git"
projects[drupal][download][revision] = "89c51bb3b84ef4fc6160282a2863e379aa345d9f"
projects[drupal][patch][] = "https://www.drupal.org/files/issues/format_interval_add_rounding_option.patch"
