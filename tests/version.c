/*
  Part of: CCTests
  Contents: test for version functions
  Date: Nov 28, 2017

  Abstract

	Test file for version functions.

  Copyright (C) 2017, 2020 Marco Maggi <mrc.mgg@gmail.com>

  See the COPYING file.
*/

#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc CCLIB_UNUSED, const char *const argv[] CCLIB_UNUSED)
{
  cctests_init(__FILE__);
  printf("version number string: %s\n", cctests_version_string());
  printf("libtool version number: %d:%d:%d\n",
	 cctests_version_interface_current(),
	 cctests_version_interface_revision(),
	 cctests_version_interface_age());
  cctests_final();
}

/* end of file */
