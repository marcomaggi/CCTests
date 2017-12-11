/*
  Part of: CCTests
  Contents: tests for driver
  Date: Nov 30, 2017

  Abstract

	Test file for driver functions.

  Copyright (C) 2017 Marco Maggi <marco.maggi-ipsu@poste.it>

  See the COPYING file.
*/


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>
#include "test-utils.h"


/** --------------------------------------------------------------------
 ** Test functions.
 ** ----------------------------------------------------------------- */

void
test_fun_successful (cce_destination_t L CCTESTS_UNUSED)
{
  cctests_assert(true);
}

void
test_fun_failing (cce_destination_t L CCTESTS_UNUSED)
{
  cctests_assert(false);
}


/** --------------------------------------------------------------------
 ** Test groups.
 ** ----------------------------------------------------------------- */

void
test_1_1 (void)
/* Begin  and end  a  group.  Verify  that the  current  test suite  has
   completed successfully. */
{
  cctests_begin_group(__func__);
  {
    /* Do nothing. */
  }
  cctests_end_group();
  test_assert(true == cctests_latest_group_completed_successfully());
}

void
test_1_2 (void)
/* Begin and end a group.  Run  a successful test function.  Verify that
   the current test suite has completed successfully. */
{
  cctests_begin_group(__func__);
  {
    cctests_run(test_fun_successful);
  }
  cctests_end_group();
  test_assert(true == cctests_latest_group_completed_successfully());
}

void
test_1_3 (void)
/* Begin and end a group.  Run a failing test function.  Verify that the
   current test suite has completed successfully. */
{
  cctests_begin_group(__func__);
  {
    cctests_run(test_fun_failing);
  }
  cctests_end_group();
  test_assert(false == cctests_latest_group_completed_successfully());
}


int
main (void)
{
  cctests_init("driver");

  if (1) { test_1_1(); }
  if (1) { test_1_2(); }
  if (1) { test_1_3(); }

  exit(EXIT_SUCCESS);
}

/* end of file */
