/*
  Part of: CCTests
  Contents: system interface functions
  Date: Nov 29, 2017

  Abstract



  Copyright (C) 2017, 2018 Marco Maggi <marco.maggi-ipsu@poste.it>

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


/** --------------------------------------------------------------------
 ** System wrappers: POSIX regular expressions.
 ** ----------------------------------------------------------------- */

void
cctests_sys_regcomp (cce_destination_t L, regex_t * rex, char const * pattern, int cflags)
{
  int	rv;

  rv = regcomp(rex, pattern, cflags);
  if (0 != rv) {
    cce_raise(L, cctests_condition_new_regex_compilation_error(L, rv));
  }
}

void
cctests_sys_regfree (regex_t * rex)
{
  regfree(rex);
}

/* end of file */
