/*
  Part of: CCTests
  Contents: header definitions for subtyping of "test signal-3" conditions
  Date: Dec  6, 2017

  Abstract

	Header definitions for subtyping of "test signal-3" conditions.

  Copyright (C) 2017, 2018, 2019 Marco Maggi <marco.maggi-ipsu@poste.it>

  See the COPYING file.
*/

#ifndef CONDITION_SIGNAL_3_SUBTYPING_HEADER_H
#define CONDITION_SIGNAL_3_SUBTYPING_HEADER_H 1


/** --------------------------------------------------------------------
 ** Heaaders.
 ** ----------------------------------------------------------------- */

#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>


/** --------------------------------------------------------------------
 ** Module initialisation.
 ** ----------------------------------------------------------------- */

cctests_decl void condition_signal_3_subtyping_init_module (void);


/** --------------------------------------------------------------------
 ** Header definitions.
 ** ----------------------------------------------------------------- */

typedef struct my_descriptor_signal_3_subtype_t	my_descriptor_signal_3_subtype_t;
typedef struct my_condition_signal_3_subtype_t	my_condition_signal_3_subtype_t;

struct my_descriptor_signal_3_subtype_t {
  cce_descriptor_t	descriptor;
};

struct my_condition_signal_3_subtype_t {
  cctests_condition_signal_3_t	signal_3;
  int *				data;
};

cctests_decl void cce_descriptor_set_parent_to(my_descriptor_signal_3_subtype_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

/* ------------------------------------------------------------------ */

cctests_decl void my_condition_init_signal_3_subtype (cce_destination_t L, my_condition_signal_3_subtype_t * C, int the_data)
  __attribute__((__nonnull__(1,2)));

cctests_decl cce_condition_t const * my_condition_new_signal_3_subtype (cce_destination_t L, int the_data)
  __attribute__((__nonnull__(1),__returns_nonnull__));

cctests_decl bool my_condition_is_signal_3_subtype (cce_condition_t const * C)
  __attribute__((__pure__,__nonnull__(1)));


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#endif /* CONDITION_SIGNAL_3_SUBTYPING_HEADER_H */

/* end of file */
