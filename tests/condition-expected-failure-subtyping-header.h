/*
  Part of: CCTests
  Contents: header definitions for subtyping of "expected failure" conditions
  Date: Mar 23, 2018

  Abstract

	Header definitions for subtyping of "expected failure" conditions.

  Copyright (C) 2018, 2019, 2020 Marco Maggi <mrc.mgg@gmail.com>

  See the COPYING file.
*/

#ifndef CONDITION_EXPECTED_FAILURE_SUBTYPING_HEADER_H
#define CONDITION_EXPECTED_FAILURE_SUBTYPING_HEADER_H 1


/** --------------------------------------------------------------------
 ** Heaaders.
 ** ----------------------------------------------------------------- */

#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>


/** --------------------------------------------------------------------
 ** Module initialisation.
 ** ----------------------------------------------------------------- */

cclib_decl void condition_expected_failure_subtyping_init_module (void);


/** --------------------------------------------------------------------
 ** Header definitions.
 ** ----------------------------------------------------------------- */

typedef struct my_descriptor_expected_failure_subtype_t	my_descriptor_expected_failure_subtype_t;
typedef struct my_condition_expected_failure_subtype_t	my_condition_expected_failure_subtype_t;

struct my_descriptor_expected_failure_subtype_t {
  cce_descriptor_t	descriptor;
};

struct my_condition_expected_failure_subtype_t {
  cctests_condition_expected_failure_t	expected_failure;
  int *				data;
};

cclib_decl void cce_descriptor_set_parent_to(my_descriptor_expected_failure_subtype_t) (cce_descriptor_t * const D)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

/* ------------------------------------------------------------------ */

cclib_decl void my_condition_init_expected_failure_subtype (cce_destination_t L, my_condition_expected_failure_subtype_t * C,
							      int the_data)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1,2);

cclib_decl cce_condition_t const * my_condition_new_expected_failure_subtype (cce_destination_t L, int the_data)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1)
  CCLIB_FUNC_ATTRIBUTE_RETURNS_NONNULL;

cclib_decl bool my_condition_is_expected_failure_subtype (cce_condition_t const * C)
  CCLIB_FUNC_ATTRIBUTE_PURE
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#endif /* CONDITION_EXPECTED_FAILURE_SUBTYPING_HEADER_H */

/* end of file */
