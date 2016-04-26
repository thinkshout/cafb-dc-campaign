#!/bin/bash

# match your install profile name
PROJECT=cafb_dc

# pantheon, acquia, generic
HOSTTYPE=pantheon

SITENAME="Capital Area Food Bank"

GITREPO="ssh://codeserver.dev.308a884d-477e-45e0-b3aa-1f5cc90eb30a@codeserver.dev.308a884d-477e-45e0-b3aa-1f5cc90eb30a.drush.in:2222/~/repository.git"
#!/bin/bash

MULTIDEV=true

postbuild () {
  cp -r profiles/$PROJECT/modules/ sites/all/modules/
  rm -rf profiles/$PROJECT/modules
  cp -r profiles/$PROJECT/libraries/ sites/all/libraries/
  rm -rf profiles/$PROJECT/libraries
  cp -r profiles/$PROJECT/themes/ sites/all/themes/
  rm -rf profiles/$PROJECT/themes

  # keep modules from moving outside of redhen_raiser profile after we patch them
  mv sites/all/modules/redhen_campaign profiles/redhen_raiser/modules/contrib/
  mv sites/all/modules/redhen profiles/redhen_raiser/modules/contrib/

  #not sure how this is getting here
  rm -f profiles/redhen_raiser/.gitignore
}