/*
  Part of: CCTests
  Contents: header definitions for subtyping of "test unreachable" conditions
  Date: Dec 13, 2017

  Abstract

	Header definitions for subtyping of "test unreachable" conditions.

  Copyright (C) 2017, 2018, 2019, 2020 Marco Maggi <mrc.mgg@gmail.com>

  See the COPYING file.
*/

#ifndef CONDITION_UNREACHABLE_SUBTYPING_HEADER_H
#define CONDITION_UNREACHABLE_SUBTYPING_HEADER_H 1


/** --------------------------------------------------------------------
 ** Heaaders.
 ** ----------------------------------------------------------------- */

#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>


/** --------------------------------------------------------------------
 ** Module initialisation.
 ** ----------------------------------------------------------------- */

cclib_decl void condition_unreachable_subtyping_init_module (void);


/** --------------------------------------------------------------------
 ** Header definitions.
 ** ----------------------------------------------------------------- */

typedef struct my_descriptor_unreachable_subtype_t	my_descriptor_unreachable_subtype_t;
typedef struct my_condition_unreachable_subtype_t	my_condition_unreachable_subtype_t;

struct my_descriptor_unreachable_subtype_t {
  cce_descriptor_t	descriptor;
};

struct my_condition_unreachable_subtype_t {
  cctests_condition_unreachable_t	unreachable;
  int *				data;
};

cclib_decl void cce_descriptor_set_parent_to(my_descriptor_unreachable_subtype_t) (cce_descriptor_t * const D)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

/* ------------------------------------------------------------------ */

cclib_decl void my_condition_init_unreachable_subtype (cce_destination_t L, my_condition_unreachable_subtype_t * C,
							 char const * const filename,
							 char const * const funcname,
							 int const linenum,
							 int the_data)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1,2,3,4);

cclib_decl cce_condition_t const * my_condition_new_unreachable_subtype (cce_destination_t L,
									   char const * const filename,
									   char const * const funcname,
									   int const linenum,
									   int the_data)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1,2,3)
  CCLIB_FUNC_ATTRIBUTE_RETURNS_NONNULL;

cclib_decl bool my_condition_is_unreachable_subtype (cce_condition_t const * C)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1)
  CCLIB_FUNC_ATTRIBUTE_PURE;


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#endif /* CONDITION_UNREACHABLE_SUBTYPING_HEADER_H */

/* end of file */
