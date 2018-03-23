/*
  Part of: CCTests
  Contents: tests for subprocesses
  Date: Mar 23, 2018

  Abstract

	Test file for running tests in a subprocess.

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
 ** Child only tests.
 ** ----------------------------------------------------------------- */

static void
test_1_1_child_function (cce_destination_t L)
{
  cctests_assert(L, true);
}

void
test_1_1 (cce_destination_t upper_L)
/* Successful child function. */
{
  cctests_call_in_forked_process(upper_L, test_1_1_child_function);
}

/* ------------------------------------------------------------------ */

static void
test_1_2_child_function (cce_destination_t L)
{
  cctests_assert(L, false);
}

void
test_1_2 (cce_destination_t upper_L)
/* Failing child function. */
{
  cce_location_t	L[1];

  if (cce_location(L)) {
    if (cctests_condition_is_child_failure_exit_status(cce_condition(L))) {
      cce_run_error_handlers_final(L);
    } else {
      cce_run_error_handlers_raise(L, upper_L);
    }
  } else {
    cctests_call_in_forked_process(L, test_1_2_child_function);
    cce_run_cleanup_handlers(L);
  }
}


/** --------------------------------------------------------------------
 ** Parent and child tests.
 ** ----------------------------------------------------------------- */

static void
test_2_1_parent_function (cce_destination_t L, int64_t child_pid CCTESTS_UNUSED)
{
  cctests_assert(L, true);
}

static void
test_2_1_child_function (cce_destination_t L)
{
  cctests_assert(L, true);
}

void
test_2_1 (cce_destination_t upper_L)
/* Successful parent and child functions. */
{
  cctests_with_parent_and_child_process(upper_L, test_2_1_parent_function, test_2_1_child_function);
}

/* ------------------------------------------------------------------ */

static void
test_2_2_parent_function (cce_destination_t L, int64_t child_pid CCTESTS_UNUSED)
{
  cctests_assert(L, true);
}

static void
test_2_2_child_function (cce_destination_t L)
{
  cctests_assert(L, false);
}

void
test_2_2 (cce_destination_t upper_L)
/* Successful parent and failing child functions. */
{
  cce_location_t	L[1];

  if (cce_location(L)) {
    if (0) { fprintf(stderr, "%s: %s\n", __func__, cce_condition_static_message(cce_condition(L))); };

    if (cctests_condition_is_child_failure_exit_status(cce_condition(L))) {
      cce_run_error_handlers_final(L);
    } else {
      cce_run_error_handlers_raise(L, upper_L);
    }
  } else {
    cctests_with_parent_and_child_process(L, test_2_2_parent_function, test_2_2_child_function);
    cce_run_cleanup_handlers(L);
  }
}


int
main (void)
{
  cctests_init("driver");
  {
    cctests_begin_group("Child only tests");
    {
      cctests_run(test_1_1);
      cctests_run(test_1_2);
    }
    cctests_end_group();

    cctests_begin_group("Parent and child tests");
    {
      cctests_run(test_2_1);
      cctests_run(test_2_2);
    }
    cctests_end_group();
  }
  cctests_final();
}

/* end of file */
