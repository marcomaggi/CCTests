/*
  Part of: CCTests
  Contents: helper functions
  Date: Thu Feb  1, 2018

  Abstract



  Copyright (C) 2017, 2018, 2019 Marco Maggi <mrc.mgg@gmail.com>

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
#include <stdio.h>
#include <string.h>
#ifdef HAVE_UNISTD_H
#  include <unistd.h>
#endif


/** --------------------------------------------------------------------
 ** Input/output devices.
 ** ----------------------------------------------------------------- */

bool
cctests_isatty (FILE * stream)
/* Return  true if  the  "stream"  is on  a  terminal; otherwise  return
   false. */
{
#ifdef HAVE_ISATTY
  return isatty(fileno(stream));
#else
  return false;
#endif
}

bool
cctests_log_stream_isatty (void)
/* Return true if CCTests' log stream is on a terminal; otherwise return
   false. */
{
  return cctests_isatty(cctests_log_stream);
}


/** --------------------------------------------------------------------
 ** Miscellaneous.
 ** ----------------------------------------------------------------- */

char const *
cctests_new_dynamic_string (cce_destination_t L, char const * in_str)
{
  size_t	in_len	= strlen(in_str);
  char		*ou_str = cce_sys_malloc(L, 1+in_len);

  memcpy(ou_str, in_str, in_len);
  return (char const *)ou_str;
}

/* end of file */
