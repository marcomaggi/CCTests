/*
  Part of: CCTests
  Contents: header definitions for subtyping of "regex compilation error" conditions
  Date: Dec  8, 2017

  Abstract

	Header definitions for subtyping of "regex compilation error" conditions.

  Copyright (C) 2017, 2018 Marco Maggi <marco.maggi-ipsu@poste.it>

  See the COPYING file.
*/

#ifndef CONDITION_REGEX_COMPILATION_ERROR_SUBTYPING_HEADER_H
#define CONDITION_REGEX_COMPILATION_ERROR_SUBTYPING_HEADER_H 1


/** --------------------------------------------------------------------
 ** Heaaders.
 ** ----------------------------------------------------------------- */

#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>


/** --------------------------------------------------------------------
 ** Header definitions.
 ** ----------------------------------------------------------------- */

typedef struct my_descriptor_regex_compilation_error_subtype_t	my_descriptor_regex_compilation_error_subtype_t;
typedef struct my_condition_regex_compilation_error_subtype_t	my_condition_regex_compilation_error_subtype_t;

struct my_descriptor_regex_compilation_error_subtype_t {
  cce_descriptor_t	descriptor;
};

struct my_condition_regex_compilation_error_subtype_t {
  cctests_condition_regex_compilation_error_t	regex_compilation_error;
  int *					data;
};

cctests_decl my_descriptor_regex_compilation_error_subtype_t const * const	my_descriptor_regex_compilation_error_subtype_ptr;

cctests_decl void my_condition_init_regex_compilation_error_subtype (cce_destination_t L, my_condition_regex_compilation_error_subtype_t * C,
								     int errcode, int the_data)
  __attribute__((__nonnull__(1,2)));

cctests_decl cce_condition_t const * my_condition_new_regex_compilation_error_subtype (cce_destination_t L,
										       int errcode, int the_data)
  __attribute__((__nonnull__(1),__returns_nonnull__));

__attribute__((__pure__,__nonnull__(1),__always_inline__))
static inline bool
my_condition_is_regex_compilation_error_subtype (cce_condition_t const * C)
{
  return cce_condition_is(C, &(my_descriptor_regex_compilation_error_subtype_ptr->descriptor));
}

cctests_decl void condition_regex_compilation_error_subtyping_init_module (void);


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#endif /* CONDITION_REGEX_COMPILATION_ERROR_SUBTYPING_HEADER_H */

/* end of file */
