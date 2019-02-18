/*
  Part of: CCTests
  Contents: debugging facilities
  Date: Mon Feb 18, 2019

  Abstract

	This module  defines the debugging  facilities of CCTests.  Mostly  these are
	special printing functions calls.

  Copyright (C) 2019 Marco Maggi <marco.maggi-ipsu@poste.it>

  This is free software; you can redistribute  it and/or modify it under the terms of
  the GNU Lesser General Public License as published by the Free Software Foundation;
  either version 3.0 of the License, or (at your option) any later version.

  This library  is distributed in the  hope that it  will be useful, but  WITHOUT ANY
  WARRANTY; without  even the implied  warranty of  MERCHANTABILITY or FITNESS  FOR A
  PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License along with
  this library; if not, write to the Free Software Foundation, Inc., 59 Temple Place,
  Suite 330, Boston, MA 02111-1307 USA.
*/


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#include "cctests-internals.h"
#include <stdarg.h>


/** --------------------------------------------------------------------
 ** Printing.
 ** ----------------------------------------------------------------- */

void
cctests_p_debug_print (const char * file, const char * function, int line, const char * template, ...)
{
  va_list	ap;
  int		len, i;

  /* Move "file" to the last '/' char, so  that we print file's tail name but not the
     directory part. */
  len = strlen(file);
  for (i=len-1; ((i>=0) && ('/' != file[i])); --i);
  if ('/' == file[i]) {
    ++i;
  }
  file += i;
  /*   CCTESTS_FPRINTF(stderr, "%s:%-25s (%d) *** ", file, function, line); */
  CCTESTS_FPRINTF(stderr, "%-30s(%s:%d) *** ", function, file, line);
  va_start(ap, template);
  {
    CCTESTS_VFPRINTF(stderr, template, ap);
    CCTESTS_FPRINTF(stderr, "\n");
    fflush(stderr);
  }
  va_end(ap);
}

/* end of file */
