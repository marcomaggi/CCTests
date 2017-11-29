/*
  Part of: CCTests
  Contents: system interface functions
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


/** --------------------------------------------------------------------
 ** System wrappers: memory allocation.
 ** ----------------------------------------------------------------- */

void *
cctests_sys_malloc (cce_destination_t  L, size_t size)
{
  void *	rv;
  errno = 0;
  rv = malloc (size);
  if (NULL != rv) {
    return rv;
  } else {
    cce_raise(L, cce_condition_new_errno_clear());
  }
}

void *
cctests_sys_realloc (cce_destination_t  L, void * ptr, size_t newsize)
{
  void *	rv;
  errno = 0;
  rv = realloc(ptr, newsize);
  if (NULL != rv) {
    return rv;
  } else {
    cce_raise(L, cce_condition_new_errno_clear());
  }
}

void *
cctests_sys_calloc (cce_destination_t  L, size_t count, size_t eltsize)
{
  void *	rv;
  errno = 0;
  rv = calloc(count, eltsize);
  if (NULL != rv) {
    return rv;
  } else {
    cce_raise(L, cce_condition_new_errno_clear());
  }
}


/** --------------------------------------------------------------------
 ** Predefined POSIX exception handler: malloc pointer.
 ** ----------------------------------------------------------------- */

__attribute__((__nonnull__(1,2)))
static void
cce_handler_malloc_function (cce_condition_t const * C CCE_UNUSED, cce_handler_t * H)
{
  free(H->pointer);
  if (0) { fprintf(stderr, "%s: done\n", __func__); }
}

void
cctests_sys_cleanup_handler_malloc_init (cce_location_t * L, cce_handler_t * H, void * pointer)
{
  H->function	= cce_handler_malloc_function;
  H->pointer	= pointer;
  cce_register_cleanup_handler(L, H);
}

void
cctests_sys_error_handler_malloc_init (cce_location_t * L, cce_handler_t * H, void * pointer)
{
  H->function	= cce_handler_malloc_function;
  H->pointer	= pointer;
  cce_register_error_handler(L, H);
}

/* end of file */
