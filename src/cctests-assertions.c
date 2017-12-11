/*
  Part of: CCTests
  Contents: assertion functions
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
cctests_p_assert (char const * const expr, bool const result,
		  char const * const filename, char const * const funcname, int const linenum)
{
  if (false == result) {
    fprintf(stderr, "CCTests: %s: %s: line %d: assertion failure: %s\n",
	    filename, funcname, linenum, expr);
    cce_raise(cctests_location, cctests_condition_new_assertion(cctests_location, expr, filename, funcname, linenum));
  }
}

/* end of file */
