/*
  Part of: CCTests
  Contents: test for subtyping of "test signal-1" conditions
  Date: Dec  6, 2017

  Abstract

	Test file for subtyping of "test signal-1" conditions.

  Copyright (C) 2017, 2018, 2020 Marco Maggi <mrc.mgg@gmail.com>

  See the COPYING file.
*/


/** --------------------------------------------------------------------
 ** Heaaders.
 ** ----------------------------------------------------------------- */

#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>
#include "condition-signal-1-subtyping-header.h"


int
main (void)
{
  cctests_init(__FILE__);
  condition_signal_1_subtyping_init_module();

  {
    cce_location_t	L[1];

    if (cce_location(L)) {
      fprintf(stderr, "%s: static message: %s\n", __func__, cce_condition_static_message(cce_condition(L)));

      if (my_condition_is_signal_1_subtype(cce_condition(L))) {
	CCLIB_PC(my_condition_signal_1_subtype_t, C, cce_condition(L));
	fprintf(stderr, "%s: is signal-1 subtype, data=%d\n", __func__, *(C->data));
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_FAILURE);
      }

      if (cctests_condition_is_signal_1(cce_condition(L))) {
	fprintf(stderr, "%s: is CCTests test signal-1 condition\n", __func__);
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_FAILURE);
      }

      if (cctests_condition_is_signal(cce_condition(L))) {
	fprintf(stderr, "%s: is CCTests test signal condition\n", __func__);
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
      cce_raise(L, my_condition_new_signal_1_subtype(L, 123));
      cce_run_body_handlers(L);
    }
  }

  cctests_final();
}

/* end of file */
