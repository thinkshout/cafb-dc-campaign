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
  cp -r profiles/$PROJECT/libraries/ sites/all/libraries/
  cp -r profiles/$PROJECT/themes/ sites/all/themes/

  #not sure how this is getting here
  rm -f profiles/redhen_raiser/.gitignore

  #remove this directory, as it is not actually a profile.
  rm -rf profiles/$PROJECT
}