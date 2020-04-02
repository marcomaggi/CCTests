/*
  Part of: CCTests
  Contents: header definitions for subtyping of "test skipped" conditions
  Date: Feb  7, 2018

  Abstract

	Header definitions for subtyping of "test skipped" conditions.

  Copyright (C) 2018, 2019, 2020 Marco Maggi <mrc.mgg@gmail.com>

  See the COPYING file.
*/

#ifndef CONDITION_SKIPPED_SUBTYPING_HEADER_H
#define CONDITION_SKIPPED_SUBTYPING_HEADER_H 1


/** --------------------------------------------------------------------
 ** Heaaders.
 ** ----------------------------------------------------------------- */

#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>


/** --------------------------------------------------------------------
 ** Module initialisation.
 ** ----------------------------------------------------------------- */

cclib_decl void condition_skipped_subtyping_init_module (void);


/** --------------------------------------------------------------------
 ** Header definitions.
 ** ----------------------------------------------------------------- */

typedef struct my_descriptor_skipped_subtype_t	my_descriptor_skipped_subtype_t;
typedef struct my_condition_skipped_subtype_t	my_condition_skipped_subtype_t;

struct my_descriptor_skipped_subtype_t {
  cce_descriptor_t	descriptor;
};

struct my_condition_skipped_subtype_t {
  cctests_condition_skipped_t	skipped;
  int *				data;
};

cclib_decl void cce_descriptor_set_parent_to(my_descriptor_skipped_subtype_t) (cce_descriptor_t * const D)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

/* ------------------------------------------------------------------ */

cclib_decl void my_condition_init_skipped_subtype (cce_destination_t L, my_condition_skipped_subtype_t * C, int the_data)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1,2);

cclib_decl cce_condition_t const * my_condition_new_skipped_subtype (cce_destination_t L, int the_data)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1)
  CCLIB_FUNC_ATTRIBUTE_RETURNS_NONNULL;

cclib_decl bool my_condition_is_skipped_subtype (cce_condition_t const * C)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1)
  CCLIB_FUNC_ATTRIBUTE_PURE;


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#endif /* CONDITION_SKIPPED_SUBTYPING_HEADER_H */

/* end of file */
