/*
  Part of: CCTests
  Contents: test for subtyping of "test skipped" conditions
  Date: Feb  7, 2018

  Abstract

	Test file for subtyping of "test skipped" conditions.

  Copyright (C) 2018 Marco Maggi <mrc.mgg@gmail.com>

  See the COPYING file.
*/


/** --------------------------------------------------------------------
 ** Heaaders.
 ** ----------------------------------------------------------------- */

#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>
#include "condition-skipped-subtyping-header.h"


int
main (void)
{
  cctests_init(__FILE__);
  condition_skipped_subtyping_init_module();

  {
    cce_location_t	L[1];

    if (cce_location(L)) {
      fprintf(stderr, "%s: static message: %s\n", __func__, cce_condition_static_message(cce_condition(L)));

      if (my_condition_is_skipped_subtype(cce_condition(L))) {
	CCE_PC(my_condition_skipped_subtype_t, C, cce_condition(L));
	fprintf(stderr, "%s: is skipped subtype, data=%d\n", __func__, *(C->data));
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_SUCCESS);
      }

      if (cctests_condition_is_skipped(cce_condition(L))) {
	fprintf(stderr, "%s: is CCTests test skipped condition\n", __func__);
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_SUCCESS);
      }

      if (cctests_condition_is_base(cce_condition(L))) {
	fprintf(stderr, "%s: is CCTests base condition\n", __func__);
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_SUCCESS);
      }

      if (cce_condition_is_root(cce_condition(L))) {
	fprintf(stderr, "%s: is CCExceptions root condition\n", __func__);
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_SUCCESS);
      }

      cce_run_catch_handlers_final(L);
    } else {
      cce_raise(L, my_condition_new_skipped_subtype(L, 123));
      cce_run_body_handlers(L);
    }
  }

  cctests_final();
}

/* end of file */
