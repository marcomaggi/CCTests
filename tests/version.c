/*
  Part of: CCTests
  Contents: test for version functions
  Date: Nov 28, 2017

  Abstract

	Test file for version functions.

  Copyright (C) 2017 Marco Maggi <marco.maggi-ipsu@poste.it>

  See the COPYING file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <cctests.h>

int
main (int argc CCTESTS_UNUSED, const char *const argv[] CCTESTS_UNUSED)
{
  printf("version number string: %s\n", cctest_version_string());
  printf("libtool version number: %d:%d:%d\n",
	 cctest_version_interface_current(),
	 cctest_version_interface_revision(),
	 cctest_version_interface_age());
  exit(EXIT_SUCCESS);
}

/* end of file */
