/*
  Part of: CCTests
  Contents: private header file
  Date: Nov 28, 2017

  Abstract

	This  header  file is  for  internal  definitions.  It  must  be
	included by all the source files in this package.

  Copyright (C) 2017, 2018 Marco Maggi <marco.maggi-ipsu@poste.it>

  This program is  free software: you can redistribute  it and/or modify
  it under the  terms of the GNU General Public  License as published by
  the Free Software Foundation, either  version 3 of the License, or (at
  your option) any later version.

  This program  is distributed in the  hope that it will  be useful, but
  WITHOUT   ANY  WARRANTY;   without  even   the  implied   warranty  of
  MERCHANTABILITY  or FITNESS  FOR A  PARTICULAR PURPOSE.   See  the GNU
  General Public License for more details.

  You  should have received  a copy  of the  GNU General  Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CCTESTS_INTERNALS_H
#define CCTESTS_INTERNALS_H 1


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include "cctests.h"
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>


/** --------------------------------------------------------------------
 ** Preprocessor macros.
 ** ----------------------------------------------------------------- */

#define CCTESTS_ENVIRONMENT_VARIABLE_FILE	"cctests_file"
#define CCTESTS_ENVIRONMENT_VARIABLE_GROUP	"cctests_group"
#define CCTESTS_ENVIRONMENT_VARIABLE_NAME	"cctests_name"

#define CCTESTS_AUTOMAKE_TEST_HARNESS_CODE_SUCCESS	0
#define CCTESTS_AUTOMAKE_TEST_HARNESS_CODE_FAILURE	1
#define CCTESTS_AUTOMAKE_TEST_HARNESS_CODE_SKIP_TEST	77
#define CCTESTS_AUTOMAKE_TEST_HARNESS_CODE_HARD_ERROR	99


/** --------------------------------------------------------------------
 ** Constants.
 ** ----------------------------------------------------------------- */

/* Define the "printf()" code to print "size_t" values. */
#if (4 == MMUX_SIZEOF_SIZE_T)
#  define PRIuSIZE	"u"
#else
#  define PRIuSIZE	"lu"
#endif

/* Define the "printf()" code to print "ssize_t" values. */
#if (4 == MMUX_SIZEOF_SSIZE_T)
#  define PRIdSIZE	"d"
#else
#  define PRIdSIZE	"ld"
#endif


/** --------------------------------------------------------------------
 ** Library variables.
 ** ----------------------------------------------------------------- */

/* While the code runs a test function: this variable holds a pointer to
 * an ASCIIZ string representing the current test function name.
 */
cctests_private_decl char const *	cctests_test_func_name;


/** --------------------------------------------------------------------
 ** Function prototypes.
 ** ----------------------------------------------------------------- */

cctests_private_decl void cctests_release_resources (void);

cctests_private_decl void cctests_conditions_module_initialisation (void);

cctests_private_decl void cctests_sys_regcomp (cce_destination_t L, regex_t * rex, char const * pattern, int cflags)
  __attribute__((__nonnull__(1,2,3)));

cctests_private_decl void cctests_sys_regfree (regex_t * rex)
  __attribute__((__nonnull__(1)));


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* CCTESTS_INTERNALS_H */

/* end of file */
