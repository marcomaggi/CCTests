/*
  Part of: CCTests
  Contents: test driver functions
  Date: Nov 29, 2017

  Abstract



  Copyright (C) 2017, 2018, 2019 Marco Maggi <marco.maggi-ipsu@poste.it>

  This program is free  software: you can redistribute it and/or  modify it under the
  terms of the  GNU Lesser General Public  License as published by  the Free Software
  Foundation, either version 3 of the License, or (at your option) any later version.

  This program  is distributed in the  hope that it  will be useful, but  WITHOUT ANY
  WARRANTY; without  even the implied  warranty of  MERCHANTABILITY or FITNESS  FOR A
  PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License along with
  this program.  If not, see <http://www.gnu.org/licenses/>.
*/


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#include "cctests-internals.h"
#include <string.h>

static bool test_file_matches_user_selection (cce_destination_t L, char const * const groupname);
static bool test_group_matches_user_selection (cce_destination_t L, char const * const groupname);
static bool test_func_matches_user_selection  (cce_destination_t L, char const * const funcname);

static void acquire_environment_test_file  (cce_destination_t L);
static void acquire_environment_test_group (cce_destination_t L);
static void acquire_environment_test_name  (cce_destination_t L);


/** --------------------------------------------------------------------
 ** Global variables.
 ** ----------------------------------------------------------------- */

static regex_t	cctests_test_program_selection;
static regex_t	cctests_test_group_selection;
static regex_t	cctests_test_name_selection;

static bool	cctests_test_program_selection_used;
static bool	cctests_test_group_selection_used;
static bool	cctests_test_name_selection_used;

FILE *	cctests_log_stream;

/* This  variable is  true  if all  the  test  functions run  so  far have  completed
   successfully.  When a test function fails: this variable is set to false. */
static bool cctests_all_test_passed;

/* This  variable is  initialised by  "cctests_begin_group()"  and it  is mutated  by
   "cctests_p_run()".   It is  set to  true  if all  the  test functions  in a  group
   succeed; otherwise it is set to false. */
static bool cctests_successful_group;

/* This variable  is mutated  by "cctests_p_run()".  It  is set to  true if  the test
   function succeeds; otherwise it is set to false. */
static bool cctests_successful_func;

/* The test program name selected with  the argument of "cctests_init()".  It is used
   to compose test log messages. */
static char const * cctests_test_program_name;

/* While the code runs the block:
 *
 *   cctests_begin_group("the group");
 *   {
 *     ...
 *   }
 *   cctests_end_group();
 *
 * this variable  holds a pointer to  an ASCIIZ string representing  the current test
 * group name.
 */
static char const *	cctests_test_group_name;

/* While the code  runs a test function:  this variable holds a pointer  to an ASCIIZ
 * string representing the current test function name.
 */
char const *	cctests_test_func_name;

/* While the code runs the block:
 *
 *   cctests_begin_group();
 *   {
 *     ...
 *   }
 *   cctests_end_group();
 *
 * this  variable  is true  if  the  function  "cctests_p_run()"  must run  the  test
 * function; this variable  is false if all  the test functions in the  group must be
 * skipped.
 */
static bool	run_tests_in_group;

cce_destination_t	cctests_location;


/** --------------------------------------------------------------------
 ** Terminal colors.
 ** ----------------------------------------------------------------- */

char const * cctests_terminal_directive_color	= "\033[33;1m";
char const * cctests_terminal_success_color	= "\033[32;1m";
char const * cctests_terminal_failure_color	= "\033[35;1m";
char const * cctests_terminal_skipping_color	= "\033[36;1m";
char const * cctests_terminal_default_color	= "\033[0m";

void
cctests_terminal_configure_colors (void)
{
  if (! cctests_log_stream_isatty()) {
    cctests_terminal_directive_color	= "";
    cctests_terminal_success_color	= "";
    cctests_terminal_failure_color	= "";
    cctests_terminal_skipping_color	= "";
    cctests_terminal_default_color	= "";
  }
}


/** --------------------------------------------------------------------
 ** Tests counters.
 ** ----------------------------------------------------------------- */

typedef struct cctests_counters_tuple_t		cctests_counters_tuple_t;

struct cctests_counters_tuple_t {
  unsigned	number_of_tests;
  unsigned	number_of_successful_tests;
  unsigned	number_of_failed_tests;
  unsigned	number_of_skipped_tests;
};

static void
cctests_counters_tuple_reset (cctests_counters_tuple_t * const tuple)
{
  tuple->number_of_tests		= 0;
  tuple->number_of_successful_tests	= 0;
  tuple->number_of_failed_tests		= 0;
  tuple->number_of_skipped_tests	= 0;
}

/* ------------------------------------------------------------------ */

typedef struct cctests_counters_t		cctests_counters_t;

struct cctests_counters_t {
  cctests_counters_tuple_t	file;
  cctests_counters_tuple_t	group;
};

static cctests_counters_t	cctests_counters;

static void
cctests_counters_reset_file (void)
{
  cctests_counters_tuple_reset(&cctests_counters.file);
}

static void
cctests_counters_reset_group (void)
{
  cctests_counters_tuple_reset(&cctests_counters.group);
}

static void
cctests_counters_reset_all (void)
{
  cctests_counters_reset_file();
  cctests_counters_reset_group();
}

static void
cctests_counters_register_test (void)
{
  ++cctests_counters.file.number_of_tests;
  ++cctests_counters.group.number_of_tests;
}

static void
cctests_counters_register_successful_test (void)
{
  ++cctests_counters.file.number_of_successful_tests;
  ++cctests_counters.group.number_of_successful_tests;
}

static void
cctests_counters_register_failed_test (void)
{
  ++cctests_counters.file.number_of_failed_tests;
  ++cctests_counters.group.number_of_failed_tests;
}

static void
cctests_counters_register_skipped_test (void)
{
  ++cctests_counters.file.number_of_skipped_tests;
  ++cctests_counters.group.number_of_skipped_tests;
}


/** --------------------------------------------------------------------
 ** Initialisation.
 ** ----------------------------------------------------------------- */

void
cctests_init (char const * const test_program_name)
{
  static bool	to_be_initialised = true;

  if (to_be_initialised) {
    to_be_initialised  = false;
    cctests_log_stream = stderr;
    cctests_test_program_selection_used = false;
    cctests_test_group_selection_used   = false;
    cctests_test_name_selection_used    = false;
    cctests_conditions_module_initialisation();

    cctests_test_program_name	= test_program_name;
    cctests_all_test_passed	= true;

    /* Acquire  the values  of the  environment variables:  "file", "group",  "name";
       handle them as POSIX regular expressions. */
    {
      cce_location_t	L[1];

      if (cce_location(L)) {
	cce_run_catch_handlers_final(L);
	exit(CCTESTS_AUTOMAKE_TEST_HARNESS_CODE_HARD_ERROR);
      } else {
	acquire_environment_test_file(L);
	acquire_environment_test_group(L);
	acquire_environment_test_name(L);
      }
    }

    cctests_terminal_configure_colors();

    /* Check that the string "test_program_name"  matches the regular expression from
       the environment variable "file". */
    {
      cce_location_t	L[1];

      if (cce_location(L)) {
	cce_run_catch_handlers_final(L);
	exit(CCTESTS_AUTOMAKE_TEST_HARNESS_CODE_HARD_ERROR);
      } else {
	if (test_file_matches_user_selection(L, test_program_name)) {
	  fprintf(cctests_log_stream, "CCTests: %senter test program%s: %s\n\n",
		  cctests_terminal_directive_color, cctests_terminal_default_color, test_program_name);
	  cce_run_body_handlers(L);
	} else {
	  fprintf(cctests_log_stream, "CCTests: %sskip test program%s: %s\n\n",
		  cctests_terminal_skipping_color, cctests_terminal_default_color, test_program_name);
	  cce_run_body_handlers(L);
	  exit(CCTESTS_AUTOMAKE_TEST_HARNESS_CODE_SKIP_TEST);
	}
      }
    }

    cctests_counters_reset_file();
  }
}


/** --------------------------------------------------------------------
 ** Finalisation.
 ** ----------------------------------------------------------------- */

void
cctests_release_resources (void)
{
  if (cctests_test_program_selection_used) {
    cctests_sys_regfree(&cctests_test_program_selection);
  }
  if (cctests_test_group_selection_used) {
    cctests_sys_regfree(&cctests_test_group_selection);
  }
  if (cctests_test_name_selection_used) {
    cctests_sys_regfree(&cctests_test_name_selection);
  }
}

void
cctests_final (void)
{
  int	status;

  fprintf(cctests_log_stream, "CCTests: %sexit test program%s: %s\n",
	  cctests_terminal_directive_color, cctests_terminal_default_color, cctests_test_program_name);
  fprintf(cctests_log_stream, "   number of tests: %u, %ssuccessful %u%s, %sfailed %u%s, %sskipped %u%s\n\n",
	  cctests_counters.file.number_of_tests,
	  cctests_terminal_success_color,  cctests_counters.file.number_of_successful_tests, cctests_terminal_default_color,
	  cctests_terminal_failure_color,  cctests_counters.file.number_of_failed_tests,     cctests_terminal_default_color,
	  cctests_terminal_skipping_color, cctests_counters.file.number_of_skipped_tests,    cctests_terminal_default_color);

  if (cctests_all_test_passed) {
    status = CCTESTS_AUTOMAKE_TEST_HARNESS_CODE_SUCCESS;
  } else {
    status = CCTESTS_AUTOMAKE_TEST_HARNESS_CODE_FAILURE;
  }

  cctests_release_resources();
  exit(status);
}

void
cctests_reset_global_state (void)
{
  fprintf(cctests_log_stream, "CCTests: %sresetting global state%s\n",
	  cctests_terminal_directive_color, cctests_terminal_default_color);

  cctests_all_test_passed	= true;
  cctests_successful_group	= true;
  cctests_successful_func	= true;

  cctests_counters_reset_all();
}


/** --------------------------------------------------------------------
 ** Test groups.
 ** ----------------------------------------------------------------- */

void
cctests_begin_group (char const * const test_group_name)
{
  cce_location_t	L[1];

  cctests_test_group_name	= test_group_name;
  cctests_successful_group	= true;
  cctests_counters_reset_group();

  if (cce_location(L)) {
    run_tests_in_group = false;
    cce_run_catch_handlers_final(L);
  } else {
    if (test_group_matches_user_selection(L, test_group_name)) {
      fprintf(cctests_log_stream, "CCTests: %sbegin group%s: %s\n",
	      cctests_terminal_directive_color, cctests_terminal_default_color, cctests_test_group_name);
      run_tests_in_group	= true;
    } else {
      fprintf(cctests_log_stream, "CCTests: %sskip group%s: %s\n",
	      cctests_terminal_directive_color, cctests_terminal_default_color, cctests_test_group_name);
      run_tests_in_group	= false;
    }
    cce_run_body_handlers(L);
  }
}

void
cctests_end_group (void)
{
  fprintf(cctests_log_stream, "CCTests: %send group%s: %s\n",
	  cctests_terminal_directive_color, cctests_terminal_default_color, cctests_test_group_name);
  fprintf(cctests_log_stream, "   number of tests: %u, %ssuccessful %u%s, %sfailed %u%s, %sskipped %u%s\n\n",
	  cctests_counters.group.number_of_tests,
	  cctests_terminal_success_color,  cctests_counters.group.number_of_successful_tests, cctests_terminal_default_color,
	  cctests_terminal_failure_color,  cctests_counters.group.number_of_failed_tests,     cctests_terminal_default_color,
	  cctests_terminal_skipping_color, cctests_counters.group.number_of_skipped_tests,    cctests_terminal_default_color);
  cctests_test_group_name = NULL;
}

bool
cctests_latest_group_completed_successfully (void)
{
  return cctests_successful_group;
}


/** --------------------------------------------------------------------
 ** Running test functions.
 ** ----------------------------------------------------------------- */

void
cctests_p_run (char const * const test_func_name, cctests_fun_t * const fun)
{
  cctests_test_func_name = test_func_name;
  cctests_counters_register_test();

  if (run_tests_in_group) {
    cce_location_t	L[1];

    if (cce_location(L)) {
      /* Handle an exception raised by the body below. */
      if (cctests_condition_is_skipped(cce_condition(L))) {
	cctests_successful_func = true;
	cctests_counters_register_skipped_test();
	fprintf(cctests_log_stream, "CCTests: %sskipped%s test function: %s\n",
		cctests_terminal_skipping_color, cctests_terminal_default_color,
		test_func_name);
      } else if (cctests_condition_is_success(cce_condition(L))) {
	cctests_successful_func = true;
	cctests_counters_register_successful_test();
      } else if (cctests_condition_is_expected_failure(cce_condition(L))) {
	cctests_successful_func = true;
	cctests_counters_register_successful_test();
	fprintf(cctests_log_stream, "CCTests: %sexpected failure%s in test function: %s\n",
		cctests_terminal_failure_color, cctests_terminal_default_color,
		test_func_name);
      } else if (cctests_condition_is_signal(cce_condition(L))) {
	cctests_all_test_passed  = false;
	cctests_successful_group = false;
	cctests_successful_func  = false;
	cctests_counters_register_failed_test();
	fprintf(cctests_log_stream,
		"CCTests: %serror%s: unexpected signal exception raised by test function: %s\n",
		cctests_terminal_failure_color, cctests_terminal_default_color,
		test_func_name);
      } else if (cctests_condition_is_unreachable(cce_condition(L))) {
	cctests_all_test_passed  = false;
	cctests_successful_group = false;
	cctests_successful_func  = false;
	cctests_counters_register_failed_test();
	{
	  CCTESTS_PC(cctests_condition_unreachable_t, C, cce_condition(L));
	  fprintf(cctests_log_stream,
		  "CCTests: %serror%s in test function %s: exception raised, "
		  "unreachable code was executed in file=%s, function=%s, line number=%d\n",
		  cctests_terminal_failure_color, cctests_terminal_default_color,
		  test_func_name, C->filename, C->funcname, C->linenum);
	}
      } else if (cctests_condition_is_assertion(cce_condition(L))) {
	cctests_all_test_passed  = false;
	cctests_successful_group = false;
	cctests_successful_func  = false;
	cctests_counters_register_failed_test();
	{
	  /* CCTESTS_PC(cctests_condition_assertion_t, C, cce_condition(L)); */
	  cctests_condition_print_assertion(cce_condition(L));
	}
      } else {
	cctests_all_test_passed  = false;
	cctests_successful_group = false;
	cctests_successful_func  = false;
	fprintf(cctests_log_stream, "CCTests: %serror%s in test function: %s, exception raised\n",
		cctests_terminal_failure_color, cctests_terminal_default_color,
		test_func_name);
      }

      /* Release the raised condition object. */
      if (cce_condition(L)) {
	cce_condition_delete(cce_condition(L));
      }
    } else {
      /* Run the test function, if it matches the selection. */
      if (test_func_matches_user_selection(L, test_func_name)) {
	cctests_location = L;
	fun(L);
	cctests_successful_func  = true;
	cctests_counters_register_successful_test();
	fprintf(cctests_log_stream, "CCTests: %ssuccessful%s test function: %s\n",
		cctests_terminal_success_color, cctests_terminal_default_color,
		test_func_name);
      } else {
	cctests_successful_func  = true;
	cctests_counters_register_skipped_test();
	fprintf(cctests_log_stream, "CCTests: %sskipped%s test function: %s\n",
		cctests_terminal_skipping_color, cctests_terminal_default_color,
		test_func_name);
      }
    }
    cce_run_body_handlers(L);
  } else {
    cctests_counters_register_skipped_test();
  }
}

bool
cctests_latest_func_completed_successfully (void)
{
  return cctests_successful_func;
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
      fprintf(cctests_log_stream,
	      "CCTests: %serror%s acquiring environment variable \"" CCTESTS_ENVIRONMENT_VARIABLE_FILE "\": %s\n",
	      cctests_terminal_failure_color, cctests_terminal_default_color,
	      C->regex_error.error_message);
    } else {
      fprintf(cctests_log_stream, "CCTests: %serror%s: %s\n",
	      cctests_terminal_failure_color, cctests_terminal_default_color,
	      cce_condition_static_message(cce_condition(L)));
    }
    cce_run_catch_handlers_raise(L, upper_L);
  } else {
    static int const	cflags = REG_NOSUB;
    char const *	file_str = getenv(CCTESTS_ENVIRONMENT_VARIABLE_FILE);

    if (NULL == file_str) {
      file_str = ".*";
    }
    cctests_sys_regcomp(L, &cctests_test_program_selection, file_str, cflags);
    cctests_test_program_selection_used = true;
    cce_run_body_handlers(L);
  }
}

void
acquire_environment_test_group (cce_destination_t upper_L)
{
  cce_location_t	L[1];

  if (cce_location(L)) {
    if (cctests_condition_is_regex_compilation_error(cce_condition(L))) {
      CCE_PC(cctests_condition_regex_compilation_error_t, C, cce_condition(L));
      fprintf(cctests_log_stream,
	      "CCTests: %serror%s acquiring environment variable \"" CCTESTS_ENVIRONMENT_VARIABLE_GROUP "\": %s\n",
	      cctests_terminal_failure_color, cctests_terminal_default_color,
	      C->regex_error.error_message);
    } else {
      fprintf(cctests_log_stream, "CCTests: %serror%s: %s\n",
	      cctests_terminal_failure_color, cctests_terminal_default_color,
	      cce_condition_static_message(cce_condition(L)));
    }
    cce_run_catch_handlers_raise(L, upper_L);
  } else {
    static int const	cflags = REG_NOSUB;
    char const *	group_str = getenv(CCTESTS_ENVIRONMENT_VARIABLE_GROUP);

    if (NULL == group_str) {
      group_str = ".*";
    }
    cctests_sys_regcomp(L, &cctests_test_group_selection, group_str, cflags);
    cctests_test_group_selection_used = true;
    cce_run_body_handlers(L);
  }
}

void
acquire_environment_test_name (cce_destination_t upper_L)
{
  cce_location_t	L[1];

  if (cce_location(L)) {
    if (cctests_condition_is_regex_compilation_error(cce_condition(L))) {
      CCE_PC(cctests_condition_regex_compilation_error_t, C, cce_condition(L));
      fprintf(cctests_log_stream,
	      "CCTests: %serror%ss acquiring environment variable \"" CCTESTS_ENVIRONMENT_VARIABLE_NAME "\": %s\n",
	      cctests_terminal_failure_color, cctests_terminal_default_color,
	      C->regex_error.error_message);
    } else {
      fprintf(cctests_log_stream, "CCTests: %serror%s: %s\n",
	      cctests_terminal_failure_color, cctests_terminal_default_color,
	      cce_condition_static_message(cce_condition(L)));
    }
    cce_run_catch_handlers_raise(L, upper_L);
  } else {
    static int const	cflags = REG_NOSUB;
    char const *	name_str = getenv(CCTESTS_ENVIRONMENT_VARIABLE_NAME);

    if (NULL == name_str) {
      name_str = ".*";
    }
    cctests_sys_regcomp(L, &cctests_test_name_selection, name_str, cflags);
    cctests_test_name_selection_used = true;
    cce_run_body_handlers(L);
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
   "cctests_test_program_selection":   this   function   returns   true;
   otherwise it returns false. */
{
  int	rv = regexec(&cctests_test_program_selection, test_file_name, 0, NULL, 0);
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
   "cctests_test_group_selection": this function returns true; otherwise
   it returns false. */
{
  int	rv = regexec(&cctests_test_group_selection, test_group_name, 0, NULL, 0);
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
   regular       expression      in       the      global       variable
   "cctests_test_name_selection": this function  returns true; otherwise
   it returns false. */
{
  int	rv = regexec(&cctests_test_name_selection, test_func_name, 0, NULL, 0);
  if (0 == rv) {
    return true;
  } else if (REG_NOMATCH == rv) {
    return false;
  } else {
    cce_raise(L, cctests_condition_new_regex_compilation_error(L, rv));
  }
}

/* end of file */
