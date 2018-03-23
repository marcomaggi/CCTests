/*
  Part of: CCTests
  Contents: tests for expected failure
  Date: Mar 23, 2018

  Abstract

	Test file for expected failures.

  Copyright (C) 2018 Marco Maggi <marco.maggi-ipsu@poste.it>

  See the COPYING file.
*/


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>


/** --------------------------------------------------------------------
 ** Expected failure.
 ** ----------------------------------------------------------------- */

void
test_1_1 (cce_destination_t upper_L)
{
  cce_raise(upper_L, cctests_condition_new_expected_failure());
}


int
main (void)
{
  cctests_init("Expected failure");
  {
    cctests_begin_group("Expected failure");
    {
      cctests_run(test_1_1);
    }
    cctests_end_group();
  }
  cctests_final();
}

/* end of file */
