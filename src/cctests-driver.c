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

regex_t		cctests_test_file;
regex_t		cctests_test_name;
regex_t		cctests_test_group;

static bool test_file_matches_user_selection (cce_destination_t L, char const * const groupname);
static bool test_group_matches_user_selection (cce_destination_t L, char const * const groupname);
static bool test_func_matches_user_selection  (cce_destination_t L, char const * const funcname);

static void acquire_environment_test_file  (cce_destination_t L);
static void acquire_environment_test_group (cce_destination_t L);
static void acquire_environment_test_name  (cce_destination_t L);

cce_destination_t	cctests_location;

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
 * this variable is true if  the function "cctests_p_run()" must run the
 * test function;  this variable is false  if all the test  functions in
 * the group must be skipped.
 */
static bool	run_tests_in_group;

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


/** --------------------------------------------------------------------
 ** Initialisation.
 ** ----------------------------------------------------------------- */

void
cctests_init (char const * const test_file_name)
{
  static bool	to_be_initialised = true;

  if (to_be_initialised) {
    to_be_initialised = false;
    cctests_conditions_module_initialisation();

    /* Acquire the values of the environment variables: "file", "group",
       "name"; handle them as POSIX regular expressions. */
    {
      cce_location_t	L[1];

      if (cce_location(L)) {
	cce_run_error_handlers_final(L);
	exit(CCTESTS_AUTOMAKE_TEST_HARNESS_HARD_ERROR);
      } else {
	acquire_environment_test_file(L);
	acquire_environment_test_group(L);
	acquire_environment_test_name(L);
      }
    }

    /* Check  that  the  string  "test_file_name"  matches  the  regular
       expression from the environment variable "file". */
    {
      cce_location_t	L[1];

      if (cce_location(L)) {
	cce_run_error_handlers_final(L);
	exit(CCTESTS_AUTOMAKE_TEST_HARNESS_HARD_ERROR);
      } else {
	if (test_file_matches_user_selection(L, test_file_name)) {
	  fprintf(stderr, "CCTests: enter file: %s\n", test_file_name);
	  cce_run_cleanup_handlers(L);
	} else {
	  fprintf(stderr, "CCTests: skip file: %s\n", test_file_name);
	  cce_run_cleanup_handlers(L);
	  exit(CCTESTS_AUTOMAKE_TEST_HARNESS_SKIP_CODE);
	}
      }
    }
  }
}


/** --------------------------------------------------------------------
 ** Test groups.
 ** ----------------------------------------------------------------- */

void
cctests_begin_group (char const * const test_group_name)
{
  cce_location_t	L[1];

  /* Store the group name until the call to "cctests_end_group()". */
  current_test_group_name = test_group_name;

  if (cce_location(L)) {
    run_tests_in_group = false;
    cce_run_error_handlers_final(L);
  } else {
    if (test_group_matches_user_selection(L, test_group_name)) {
      fprintf(stderr, "CCTests: beg group: %s\n", current_test_group_name);
      test_group_successful	= true;
      run_tests_in_group	= true;
    } else {
      run_tests_in_group	= false;
    }
    cce_run_cleanup_handlers(L);
  }
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
  if (run_tests_in_group) {
    cce_location_t	L[1];

    if (cce_location(L)) {
      if (cctests_condition_is_success(cce_condition(L))) {
	test_group_successful = true;
      } else if (cctests_condition_is_signal(cce_condition(L))) {
	test_group_successful = false;
	fprintf(stderr, "CCTests: unexpected signal exception raised by test function: %s\n", funcname);
      } else {
	test_group_successful = false;
	fprintf(stderr, "CCTests: exception in test function: %s\n", funcname);
      }
    } else {
      if (test_func_matches_user_selection(L, funcname)) {
	cctests_location = L;
	fun(L);
	fprintf(stderr, "CCTests: successful test function: %s\n", funcname);
      } else {
	fprintf(stderr, "CCTests: skipped test function: %s\n", funcname);
      }
    }
    cce_run_cleanup_handlers(L);
  }
}


/** --------------------------------------------------------------------
 ** Initialisation: regular expressions.
 ** ----------------------------------------------------------------- */

void
acquire_environment_test_file (cce_destination_t upper_L)
{
  cce_location_t	L[1];

  if (cce_location(L)) {
    if (cctests_condition_is_regex_compilation_error(cce_condition(L))) {
      CCE_PC(cctests_condition_regex_compilation_error_t, C, cce_condition(L));
      fprintf(stderr, "CCTests: error acquiring environment variable \"" CCTESTS_ENVIRONMENT_VARIABLE_FILE "\": %s\n",
	      C->regex_error.error_message);
    } else {
      fprintf(stderr, "CCTests: error: %s\n", cce_condition_static_message(cce_condition(L)));
    }
    cce_run_error_handlers_raise(L, upper_L);
  } else {
    static int const	cflags = REG_NOSUB;
    char const *	file_str = getenv(CCTESTS_ENVIRONMENT_VARIABLE_FILE);
    int			rv;

    if (NULL == file_str) {
      file_str = ".*";
    }
    rv = regcomp(&cctests_test_file, file_str, cflags);
    if (0 != rv) {
      cce_raise(L, cctests_condition_new_regex_compilation_error(L, rv));
    }
    cce_run_cleanup_handlers(L);
  }
}

void
acquire_environment_test_group (cce_destination_t upper_L)
{
  cce_location_t	L[1];

  if (cce_location(L)) {
    if (cctests_condition_is_regex_compilation_error(cce_condition(L))) {
      CCE_PC(cctests_condition_regex_compilation_error_t, C, cce_condition(L));
      fprintf(stderr, "CCTests: error acquiring environment variable \"" CCTESTS_ENVIRONMENT_VARIABLE_GROUP "\": %s\n",
	      C->regex_error.error_message);
    } else {
      fprintf(stderr, "CCTests: error: %s\n", cce_condition_static_message(cce_condition(L)));
    }
    cce_run_error_handlers_raise(L, upper_L);
  } else {
    static int const	cflags = REG_NOSUB;
    char const *	group_str = getenv(CCTESTS_ENVIRONMENT_VARIABLE_GROUP);
    int			rv;

    if (NULL == group_str) {
      group_str = ".*";
    }

    rv = regcomp(&cctests_test_group, group_str, cflags);
    if (0 != rv) {
      cce_raise(L, cctests_condition_new_regex_compilation_error(L, rv));
    }
    cce_run_cleanup_handlers(L);
  }
}

void
acquire_environment_test_name (cce_destination_t upper_L)
{
  cce_location_t	L[1];

  if (cce_location(L)) {
    if (cctests_condition_is_regex_compilation_error(cce_condition(L))) {
      CCE_PC(cctests_condition_regex_compilation_error_t, C, cce_condition(L));
      fprintf(stderr, "CCTests: error acquiring environment variable \"" CCTESTS_ENVIRONMENT_VARIABLE_NAME "\": %s\n",
	      C->regex_error.error_message);
    } else {
      fprintf(stderr, "CCTests: error: %s\n", cce_condition_static_message(cce_condition(L)));
    }
    cce_run_error_handlers_raise(L, upper_L);
  } else {
    static int const	cflags = REG_NOSUB;
    char const *	name_str = getenv(CCTESTS_ENVIRONMENT_VARIABLE_NAME);
    int			rv;

    if (NULL == name_str) {
      name_str = ".*";
    }

    rv = regcomp(&cctests_test_name, name_str, cflags);
    if (0 != rv) {
      cce_raise(L, cctests_condition_new_regex_compilation_error(L, rv));
    }
    cce_run_cleanup_handlers(L);
  }
}


/** --------------------------------------------------------------------
 ** Matching regular expressions.
 ** ----------------------------------------------------------------- */

bool
test_file_matches_user_selection (cce_destination_t L, char const * const test_file_name)
/* The argument TEST_FILE_NAME is meant to be a pointer to ASCIIZ string
   representing the  name of a proram  file of tests.  If  the file name
   matches   the    regular   expression   in   the    global   variable
   "cctests_test_file": this function returns true; otherwise it returns
   false. */
{
  int	rv = regexec(&cctests_test_file, test_file_name, 0, NULL, 0);
  if (0 == rv) {
    return true;
  } else if (REG_NOMATCH == rv) {
    return false;
  } else {
    cce_raise(L, cctests_condition_new_regex_compilation_error(L, rv));
  }
}

bool
test_group_matches_user_selection (cce_destination_t L, char const * const test_group_name)
/* The  argument TEST_GROUP_NAME  is meant  to  be a  pointer to  ASCIIZ
   string representing  the name of a  group of test functions.   If the
   group  name matches  the regular  expression in  the global  variable
   "cctests_test_group":  this  function   returns  true;  otherwise  it
   returns false. */
{
  int	rv = regexec(&cctests_test_group, test_group_name, 0, NULL, 0);
  if (0 == rv) {
    return true;
  } else if (REG_NOMATCH == rv) {
    return false;
  } else {
    cce_raise(L, cctests_condition_new_regex_compilation_error(L, rv));
  }
}

bool
test_func_matches_user_selection (cce_destination_t L, char const * const test_func_name)
/* The argument TEST_FUNC_NAME is meant to be a pointer to ASCIIZ string
   representing the  name of a test  function.  If the name  matches the
   regular expression  in the global variable  "cctests_test_name": this
   function returns true; otherwise it returns false. */
{
  int	rv = regexec(&cctests_test_name, test_func_name, 0, NULL, 0);
  if (0 == rv) {
    return true;
  } else if (REG_NOMATCH == rv) {
    return false;
  } else {
    cce_raise(L, cctests_condition_new_regex_compilation_error(L, rv));
  }
}

/* end of file */
