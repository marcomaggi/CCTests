/*
  Part of: CCTests
  Contents: test for subtyping of "regex compilation error" conditions
  Date: Dec  8, 2017

  Abstract

	Test file for subtyping of "regex compilation error" conditions.

  Copyright (C) 2017 Marco Maggi <marco.maggi-ipsu@poste.it>

  See the COPYING file.
*/


/** --------------------------------------------------------------------
 ** Heaaders.
 ** ----------------------------------------------------------------- */

#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "condition-regex-compilation-error-subtyping-header.h"


int
main (void)
{
  cctests_init(__FILE__);
  condition_regex_compilation_error_subtyping_init_module();

  {
    cce_location_t	L[1];

    if (cce_location(L)) {
      fprintf(stderr, "%s: static message: %s\n", __func__, cce_condition_static_message(cce_condition(L)));

      if (my_condition_is_regex_compilation_error_subtype(cce_condition(L))) {
	CCE_PC(my_condition_regex_compilation_error_subtype_t, C, cce_condition(L));
	fprintf(stderr, "%s: is regex compilation error subtype, message='%s', data=%d\n", __func__,
		C->regex_compilation_error.regex_error.error_message, *(C->data));
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_FAILURE);
      }

      if (cctests_condition_is_regex_compilation_error(cce_condition(L))) {
	fprintf(stderr, "%s: is CCTests test regex error condition\n", __func__);
      } else {
	fprintf(stderr, "%s: wrong condition-object type\n", __func__);
	exit(EXIT_FAILURE);
      }

      if (cctests_condition_is_regex_error(cce_condition(L))) {
	fprintf(stderr, "%s: is CCTests test regex error condition\n", __func__);
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
      cce_raise(L, my_condition_new_regex_compilation_error_subtype(L, REG_BADRPT, 123));
      cce_run_cleanup_handlers(L);
    }
  }

  cctests_final();
}

/* end of file */
