/*
  Part of: CCTests
  Contents: test for condition objects
  Date: Nov 28, 2017

  Abstract

	Test file for version functions.

  Copyright (C) 2017, 2018 Marco Maggi <marco.maggi-ipsu@poste.it>

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
/* Tests that "failure" is a base condition. */
{
  test_assert(true == cctests_condition_is_base(cctests_condition_new_failure()));
}

void
test_4_2 (void)
/* Tests that "failure" is a "failure" condition. */
{
  test_assert(true == cctests_condition_is_failure(cctests_condition_new_failure()));
}


/** --------------------------------------------------------------------
 ** Condition object: assertion failure.
 ** ----------------------------------------------------------------- */

void
test_5_1 (void)
/* Tests that "assertion" is a base condition. */
{
  cce_location_t	L[1];
  cce_condition_t *	C = cctests_condition_new_assertion(L, "1+2", __FILE__, __func__, __LINE__);

  test_assert(true == cctests_condition_is_base(C));
  cce_condition_delete(C);
}

void
test_5_2 (void)
/* Tests that "assertion" is a "failure" condition. */
{
  cce_location_t	L[1];
  cce_condition_t *	C = cctests_condition_new_assertion(L, "1+2", __FILE__, __func__, __LINE__);

  test_assert(true == cctests_condition_is_failure(C));
  cce_condition_delete(C);
}

void
test_5_3 (void)
/* Tests that "assertion" is a "assertion" condition. */
{
  cce_location_t	L[1];
  cce_condition_t *	C = cctests_condition_new_assertion(L, "1+2", __FILE__, __func__, __LINE__);

  test_assert(true == cctests_condition_is_assertion(C));
  cce_condition_delete(C);
}


int
main (void)
{
  cctests_init(__FILE__);

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

  /* Condition assertion failure. */
  if (1) { test_5_1(); }
  if (1) { test_5_2(); }
  if (1) { test_5_3(); }

  cctests_final();
}

/* end of file */
