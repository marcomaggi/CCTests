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

static cce_location_t	the_location;
cce_destination_t	cctests_location = &the_location;

static bool		test_group_successful;
static char const *	current_test_group_name;



void
cctests_begin_group (char const * const test_group_name)
{
  current_test_group_name = test_group_name;
  fprintf(stderr, "CCTests: beg group: %s\n", current_test_group_name);
  test_group_successful = true;
}

void
cctests_end_group (void)
{
  fprintf(stderr, "CCTests: end group: %s\n", current_test_group_name);
  current_test_group_name = NULL;
}

void
cctests_p_run (char const * const funcname, cctests_fun_t * const fun)
{
  if (cce_location(cctests_location)) {
    cce_run_error_handlers_final(cctests_location);
    test_group_successful = false;
    fprintf(stderr, "CCTests: exception in test function: %s\n", funcname);
  } else {
    fun(cctests_location);
    cce_run_cleanup_handlers(cctests_location);
    fprintf(stderr, "CCTests: successful test function: %s\n", funcname);
  }
}

bool
cctests_latest_group_completed_successfully (void)
{
  return test_group_successful;
}

/* end of file */
