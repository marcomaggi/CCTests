/*
  Part of: CCTests
  Contents: test for condition objects
  Date: Nov 28, 2017

  Abstract

	Test file for version functions.

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
 ** Condition object: signal one.
 ** ----------------------------------------------------------------- */

void
test_1_1 (void)
/* Tests that signal_1 is a base condition. */
{
  test_assert(true == cctests_condition_is_base(cctests_condition_new_signal_1()));
}

void
test_1_2 (void)
/* Tests that signal_1 is a signal_1 condition. */
{
  test_assert(true == cctests_condition_is_signal_1(cctests_condition_new_signal_1()));
}


/** --------------------------------------------------------------------
 ** Condition object: signal two.
 ** ----------------------------------------------------------------- */

void
test_2_1 (void)
/* Tests that signal_2 is a base condition. */
{
  test_assert(true == cctests_condition_is_base(cctests_condition_new_signal_2()));
}

void
test_2_2 (void)
/* Tests that signal_2 is a signal_2 condition. */
{
  test_assert(true == cctests_condition_is_signal_2(cctests_condition_new_signal_2()));
}


/** --------------------------------------------------------------------
 ** Condition object: signal three.
 ** ----------------------------------------------------------------- */

void
test_3_1 (void)
/* Tests that signal_3 is a base condition. */
{
  test_assert(true == cctests_condition_is_base(cctests_condition_new_signal_3()));
}

void
test_3_2 (void)
/* Tests that signal_3 is a signal_3 condition. */
{
  test_assert(true == cctests_condition_is_signal_3(cctests_condition_new_signal_3()));
}


/** --------------------------------------------------------------------
 ** Condition object: test failure.
 ** ----------------------------------------------------------------- */

void
test_4_1 (void)
/* Tests that "test_failure" is a base condition. */
{
  test_assert(true == cctests_condition_is_base(cctests_condition_new_test_failure()));
}

void
test_4_2 (void)
/* Tests that "test_failure" is a "test_failure" condition. */
{
  test_assert(true == cctests_condition_is_test_failure(cctests_condition_new_test_failure()));
}


int
main (void)
{
  cctests_init();

  /* Condition signal one. */
  if (1) { test_1_1(); }
  if (1) { test_1_2(); }

  /* Condition signal two. */
  if (1) { test_2_1(); }
  if (1) { test_2_2(); }

  /* Condition signal three. */
  if (1) { test_3_1(); }
  if (1) { test_3_2(); }

  /* Condition test failure. */
  if (1) { test_4_1(); }
  if (1) { test_4_2(); }

  exit(EXIT_SUCCESS);
}

/* end of file */
