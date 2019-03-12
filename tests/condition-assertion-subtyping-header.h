/*
  Part of: CCTests
  Contents: header definitions for subtyping of "test assertion" conditions
  Date: Dec  6, 2017

  Abstract

	Header definitions for subtyping of "test assertion" conditions.

  Copyright (C) 2017, 2018, 2019 Marco Maggi <marco.maggi-ipsu@poste.it>

  See the COPYING file.
*/

#ifndef CONDITION_ASSERTION_SUBTYPING_HEADER_H
#define CONDITION_ASSERTION_SUBTYPING_HEADER_H 1


/** --------------------------------------------------------------------
 ** Heaaders.
 ** ----------------------------------------------------------------- */

#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>


/** --------------------------------------------------------------------
 ** Header definitions.
 ** ----------------------------------------------------------------- */

typedef struct my_descriptor_assertion_subtype_t	my_descriptor_assertion_subtype_t;
typedef struct my_condition_assertion_subtype_t		my_condition_assertion_subtype_t;

struct my_descriptor_assertion_subtype_t {
  cce_descriptor_t	descriptor;
};

struct my_condition_assertion_subtype_t {
  cctests_condition_assertion_t	assertion;
  int *				data;
};

cctests_decl void cce_descriptor_set_parent_to(my_descriptor_assertion_subtype_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

/* ------------------------------------------------------------------ */

cctests_decl void my_condition_init_assertion_subtype (cce_destination_t L, my_condition_assertion_subtype_t * C,
						       char const * const expr,
						       char const * const filename,
						       char const * const funcname,
						       int const linenum,
						       char const * const description_message,
						       int the_data)
  __attribute__((__nonnull__(1,2,3,4,5)));

cctests_decl cce_condition_t const * my_condition_new_assertion_subtype (cce_destination_t L,
									 char const * const expr,
									 char const * const filename,
									 char const * const funcname,
									 int const linenum,
									 char const * const description_message,
									 int the_data)
  __attribute__((__nonnull__(1,2,3,4),__returns_nonnull__));

cctests_decl bool my_condition_is_assertion_subtype (cce_condition_t const * C)
  __attribute__((__pure__,__nonnull__(1)));

cctests_decl void condition_assertion_subtyping_init_module (void);


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#endif /* CONDITION_ASSERTION_SUBTYPING_HEADER_H */

/* end of file */
