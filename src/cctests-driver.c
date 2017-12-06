/*
  Part of: CCTests
  Contents: test driver functions
  Date: Nov 29, 2017

  Abstract



  Copyright (C) 2017 Marco Maggi <marco.maggi-ipsu@poste.it>

  This program is  free software: you can redistribute  it and/or modify
  it  under the  terms  of  the GNU  Lesser  General  Public License  as
  published by  the Free  Software Foundation, either  version 3  of the
  License, or (at your option) any later version.

  This program  is distributed in the  hope that it will  be useful, but
  WITHOUT   ANY  WARRANTY;   without  even   the  implied   warranty  of
  MERCHANTABILITY  or FITNESS  FOR A  PARTICULAR PURPOSE.   See  the GNU
  General Public License for more details.

  You  should have received  a copy  of the  GNU General  Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#include "cctests-internals.h"
#include <string.h>

static cce_location_t	the_location;
cce_destination_t	cctests_group_location = &the_location;

/* While the code runs the block:
 *
 *   cctests_begin_group();
 *   {
 *     ...
 *   }
 *   cctests_end_group();
 *
 * this variable holds a pointer to a statically allocated ASCIIZ string
 * representing the current test group name.
 */
static char const *	current_test_group_name;

/* While the code runs the block:
 *
 *   cctests_begin_group();
 *   {
 *     ...
 *   }
 *   cctests_end_group();
 *
 * this variable  contains true if  all the tests  run have so  far have
 * succeeded; if one test fails: this variable is set to false.
 */
static bool		test_group_successful;

/* While the code runs the block:
 *
 *   cctests_begin_group();
 *   {
 *     ...
 *   }
 *   cctests_end_group();
 *
 * this buffer will hold the first  4095 characters of the string in the
 * environment variable  "name"; the  variable will  hold the  number of
 * characters.  A character is left  available for the trailing null, so
 * that this buffer is always an ASCIIZ string.
 */
static char		selected_test_name[4096];
static size_t		selected_test_name_len;

static bool matching_selected_test (char const * const funcname);


/** --------------------------------------------------------------------
 ** Test groups.
 ** ----------------------------------------------------------------- */

void
cctests_begin_group (char const * const test_group_name)
{
  char const *	name_ptr;

  /* Store the group name until the call to "cctests_end_group()". */
  current_test_group_name = test_group_name;

  /* Copy the  first 4095  characters of the  string in  the environment
     variable "name"  in the local buffer  "selected_test_name", and its
     length in  the local variable "selected_test_name_len".

     If the environment variable is not  set: the local buffer is set to
     the empty string and its length to zero.

     The local buffer  is interpreted as an ASCIIZ string;  we make sure
     here that it is zero terminated. */
  {
    name_ptr = getenv("name");
    if (NULL != name_ptr) {
      selected_test_name_len = strlen(name_ptr);
      selected_test_name_len = (selected_test_name_len >= 4095)? 4095 : selected_test_name_len;
      strncpy(selected_test_name, name_ptr, selected_test_name_len);
    } else {
      selected_test_name_len = 0;
    }
    selected_test_name[selected_test_name_len] = '\0';
  }

  fprintf(stderr, "CCTests: beg group: %s\n", current_test_group_name);
  test_group_successful = true;
}

void
cctests_end_group (void)
{
  fprintf(stderr, "CCTests: end group: %s\n", current_test_group_name);
  current_test_group_name = NULL;
}

bool
cctests_latest_group_completed_successfully (void)
{
  return test_group_successful;
}


/** --------------------------------------------------------------------
 ** Running test functions.
 ** ----------------------------------------------------------------- */

void
cctests_p_run (char const * const funcname, cctests_fun_t * const fun)
{
  if (cce_location(cctests_group_location)) {
    if (cctests_condition_is_success(cce_condition(cctests_group_location))) {
      test_group_successful = true;
    } else if (cctests_condition_is_signal(cce_condition(cctests_group_location))) {
      test_group_successful = false;
      fprintf(stderr, "CCTests: unexpected signal exception raised by test function: %s\n", funcname);
    } else {
      test_group_successful = false;
      fprintf(stderr, "CCTests: exception in test function: %s\n", funcname);
    }
  } else {
    if (matching_selected_test(funcname)) {
      fun(cctests_group_location);
      fprintf(stderr, "CCTests: successful test function: %s\n", funcname);
    } else {
      fprintf(stderr, "CCTests: skipped test function: %s\n", funcname);
    }
  }
  cce_run_cleanup_handlers(cctests_group_location);
}


/** --------------------------------------------------------------------
 ** Helpers.
 ** ----------------------------------------------------------------- */

bool
matching_selected_test (char const * const funcname)
/* The  argument FUNCNAME  is meant  to be  a pointer  to ASCIIZ  string
   representing the name of a test  function.  If the test function name
   matches the  regular expression  in the environment  variable "name":
   this function returns true; otherwise it returns false. */
{
  size_t	funcname_len	= strlen(funcname);
  size_t	compar_len	= (funcname_len < selected_test_name_len)? funcname_len : selected_test_name_len;

  if (0 == selected_test_name_len) {
    return true;
  } else if (0 == strncmp(funcname, selected_test_name, compar_len)) {
    return true;
  } else {
    return false;
  }
}

/* end of file */
