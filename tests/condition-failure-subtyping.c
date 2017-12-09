/*
  Part of: CCTests
  Contents: test for subtyping of "test failure" conditions
  Date: Dec  6, 2017

  Abstract

	Test file for subtyping of "test failure" conditions.

  Copyright (C) 2017 Marco Maggi <marco.maggi-ipsu@poste.it>

  See the COPYING file.
*/


/** --------------------------------------------------------------------
 ** Heaaders.
 ** ----------------------------------------------------------------- */

#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>
#include "condition-failure-subtyping-header.h"


int
main (void)
{
  condition_failure_subtyping_init_module();

  {
    cce_location_t	L[1];

    if (cce_location(L)) {
      fprintf(stderr, "%s: static message: %s\n", __func__, cce_condition_static_message(cce_condition(L)));

      if (my_condition_is_failure_subtype(cce_condition(L))) {
	CCE_PC(my_condition_failure_subtype_t, C, cce_condition(L));
	fprintf(stderr, "%s: is failure subtype, data=%d\n", __func__, *(C->data));
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

      cce_run_error_handlers_final(L);
    } else {
      cce_raise(L, my_condition_new_failure_subtype(L, 123));
      cce_run_cleanup_handlers(L);
    }
  }

  exit(EXIT_SUCCESS);
}

/* end of file */