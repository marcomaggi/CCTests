/*
  Part of: CCTests
  Contents: initialisation functions
  Date: Nov 28, 2017

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


void
cctests_init (void)
{
  static bool	to_be_initialised = true;

  if (to_be_initialised) {
    cctests_conditions_module_initialisation();
  }
}

void
acquire_environment_test_name (cce_destination_t upper_L)
{
  cce_location_t	L[1];

  if (cce_location(L)) {
    cce_run_error_handlers_raise(L, upper_L);
  } else {
    static int const	cflags = REG_NOSUB;
    char const *	name_str = getenv("name");
    regex_t		name_rex;
    int			rv;

    if (NULL == name_str) {
      name_str = ".*";
    }

    rv = regcomp(&name_rex, name_str, cflags);
    if (0 != rv) {
      cce_raise(L, cctests_condition_new_regex_error(L, rv));
    }
    cce_run_cleanup_handlers(L);
  }
}

/* end of file */
