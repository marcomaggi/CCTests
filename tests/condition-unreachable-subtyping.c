/*
  Part of: CCTests
  Contents: test for subtyping of "test unreachable" conditions
  Date: Dec 13, 2017

  Abstract

	Test file for subtyping of "test unreachable" conditions.

  Copyright (C) 2017, 2018, 2020 Marco Maggi <mrc.mgg@gmail.com>

  See the COPYING file.
*/


/** --------------------------------------------------------------------
 ** Heaaders.
 ** ----------------------------------------------------------------- */

#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>
#include "condition-unreachable-subtyping-header.h"


int
main (void)
{
  cctests_init(__FILE__);
  condition_unreachable_subtyping_init_module();

  {
    cce_location_t	L[1];

    if (cce_location(L)) {
      fprintf(stderr, "%s: static message: %s\n", __func__, cce_condition_static_message(cce_condition(L)));

      if (my_condition_is_unreachable_subtype(cce_condition(L))) {
	CCLIB_PC(my_condition_unreachable_subtype_t, C, cce_condition(L));
	fprintf(stderr, "%s: is unreachable subtype, filename=%s, funcname=%s, linenum=%u, data=%d\n", __func__,
		C->unreachable.filename, C->unreachable.funcname, C->unreachable.linenum,
		*(C->data));
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_FAILURE);
      }

      if (cctests_condition_is_unreachable(cce_condition(L))) {
	fprintf(stderr, "%s: is CCTests test unreachable condition\n", __func__);
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
      cce_raise(L, my_condition_new_unreachable_subtype(L, __FILE__, __func__, __LINE__, 123));
      cce_run_body_handlers(L);
    }
  }

  cctests_final();
}

/* end of file */
