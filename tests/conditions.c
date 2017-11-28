/*
  Part of: CCTests
  Contents: test for condition objects
  Date: Nov 28, 2017

  Abstract

	Test file for version functions.

  Copyright (C) 2017 Marco Maggi <marco.maggi-ipsu@poste.it>

  See the COPYING file.
*/

#include <cctests.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


/** --------------------------------------------------------------------
 ** Condition object: signal one.
 ** ----------------------------------------------------------------- */

void
test_1_1 (void)
/* Tests that signal_1 is a base condition. */
{
  assert(true == cctests_condition_is_base(cctests_condition_new_signal_1()));
}

void
test_1_2 (void)
/* Tests that signal_1 is a signal_1 condition. */
{
  assert(true == cctests_condition_is_signal_1(cctests_condition_new_signal_1()));
}


int
main (void)
{
  if (1) { test_1_1(); }
  if (1) { test_1_2(); }

  exit(EXIT_SUCCESS);
}

/* end of file */
