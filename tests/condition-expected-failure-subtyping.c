/*
  Part of: CCTests
  Contents: test for subtyping of "expected_failure" conditions
  Date: Mar 23, 2018

  Abstract

	Test file for subtyping of "expected_failure" conditions.

  Copyright (C) 2018 Marco Maggi <mrc.mgg@gmail.com>

  See the COPYING file.
*/


/** --------------------------------------------------------------------
 ** Heaaders.
 ** ----------------------------------------------------------------- */

#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>
#include "condition-expected-failure-subtyping-header.h"


int
main (void)
{
  cctests_init(__FILE__);
  condition_expected_failure_subtyping_init_module();

  {
    cce_location_t	L[1];

    if (cce_location(L)) {
      fprintf(stderr, "%s: static message: %s\n", __func__, cce_condition_static_message(cce_condition(L)));

      if (my_condition_is_expected_failure_subtype(cce_condition(L))) {
	CCE_PC(my_condition_expected_failure_subtype_t, C, cce_condition(L));
	fprintf(stderr, "%s: is expected_failure subtype, data=%d\n", __func__, *(C->data));
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_FAILURE);
      }

      if (cctests_condition_is_expected_failure(cce_condition(L))) {
	fprintf(stderr, "%s: is CCTests test expected_failure condition\n", __func__);
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_FAILURE);
      }

      if (cctests_condition_is_failure(cce_condition(L))) {
	fprintf(stderr, "%s: is CCTests test failure condition\n", __func__);
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_FAILURE);
      }

      if (cctests_condition_is_base(cce_condition(L))) {
	fprintf(stderr, "%s: is CCTests base condition\n", __func__);
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_FAILURE);
      }

      if (cce_condition_is_root(cce_condition(L))) {
	fprintf(stderr, "%s: is CCExceptions root condition\n", __func__);
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_FAILURE);
      }

      cce_run_catch_handlers_final(L);
    } else {
      cce_raise(L, my_condition_new_expected_failure_subtype(L, 123));
      cce_run_body_handlers(L);
    }
  }

  cctests_final();
}

/* end of file */
