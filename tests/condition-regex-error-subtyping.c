/*
  Part of: CCTests
  Contents: test for subtyping of "regex error" conditions
  Date: Dec  8, 2017

  Abstract

	Test file for subtyping of "regex error" conditions.

  Copyright (C) 2017 Marco Maggi <marco.maggi-ipsu@poste.it>

  See the COPYING file.
*/


/** --------------------------------------------------------------------
 ** Heaaders.
 ** ----------------------------------------------------------------- */

#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>
#include "condition-regex-error-subtyping-header.h"


int
main (void)
{
  condition_regex_error_subtyping_init_module();

  {
    cce_location_t	L[1];

    if (cce_location(L)) {
      fprintf(stderr, "%s: static message: %s\n", __func__, cce_condition_static_message(cce_condition(L)));

      if (my_condition_is_regex_error_subtype(cce_condition(L))) {
	CCE_PC(my_condition_regex_error_subtype_t, C, cce_condition(L));
	fprintf(stderr, "%s: is regex_error subtype, data=%d\n", __func__, *(C->data));
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_FAILURE);
      }

      if (cctests_condition_is_regex_error(cce_condition(L))) {
	fprintf(stderr, "%s: is CCTests test regex_error condition\n", __func__);
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_FAILURE);
      }

      if (cce_condition_is_runtime_error(cce_condition(L))) {
	fprintf(stderr, "%s: is CCExceptions runtime error condition\n", __func__);
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_FAILURE);
      }

      if (cce_condition_is_error(cce_condition(L))) {
	fprintf(stderr, "%s: is CCExceptions error condition\n", __func__);
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
      cce_raise(L, my_condition_new_regex_error_subtype(L, REG_NOMATCH, NULL, 123));
      cce_run_cleanup_handlers(L);
    }
  }

  exit(EXIT_SUCCESS);
}

/* end of file */
