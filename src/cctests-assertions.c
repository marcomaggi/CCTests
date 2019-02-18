/*
  Part of: CCTests
  Contents: assertion functions
  Date: Nov 28, 2017

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
#include <inttypes.h>
#include <stdarg.h>


/** --------------------------------------------------------------------
 ** Raw assertions.
 ** ----------------------------------------------------------------- */

void
cctests_p_assert (cce_destination_t L, char const * const expr, bool const result,
		  char const * const filename, char const * const funcname, int const linenum)
{
  if (false == result) {
    if (0) {
      fprintf(cctests_log_stream, "CCTests: %s: %s: line %d: assertion failure: %s\n",
	      filename, funcname, linenum, expr);
    }
    cce_raise(L, cctests_condition_new_assertion(L, expr, filename, funcname, linenum));
  }
}

void
cctests_p_assert_msg (cce_destination_t L, char const * expr, bool result,
		      char const * filename, char const * funcname, int linenum,
		      char const * template, ...)
{
  if (false == result) {
    if (0) {
      fprintf(cctests_log_stream, "CCTests: %s: %s: line %d: assertion failure: %s\n",
	      filename, funcname, linenum, expr);
      {
	va_list		ap;

	va_start(ap, template);
	{
	  vfprintf(cctests_log_stream, template, ap);
	  fprintf(cctests_log_stream, "\n");
	  fflush(cctests_log_stream);
	}
	va_end(ap);
      }
    }

    /* Build the dynamic string representing the message. */
    {
      size_t	str_len  = 255;
      char	*str_ptr = cce_sys_malloc(L, 1+str_len);
      size_t	required_len = 0;

      {
	va_list	ap;
	va_start(ap, template);
	{
	  required_len = vsnprintf(str_ptr, str_len, template, ap);
	}
	va_end(ap);
      }
      if (str_len <= required_len) {
	/* Not enough room in "str_buf". */
	va_list	ap;
	str_len = required_len;
	str_ptr = cce_sys_realloc(L, str_ptr, 1+str_len);
	va_start(ap, template);
	{
	  vsnprintf(str_ptr, str_len, template, ap);
	}
	va_end(ap);
      }
      cce_raise(L, cctests_condition_new_assertion_msg(L, expr, filename, funcname, linenum, str_ptr));
    }
  }
}


/** --------------------------------------------------------------------
 ** String comparison.
 ** ----------------------------------------------------------------- */

void
cctests_p_assert_asciiz (cce_destination_t L, char const * expected, char const * result,
			 char const * const expr,
			 char const * const filename, char const * const funcname, int const linenum)
/* Compare zero-terminated strings. */
{
  if (0 != strcmp(expected, result)) {
    cce_raise(L, cctests_condition_new_assertion_expected_asciiz(L, expr, filename, funcname, linenum,
								 expected, result));
  }
}

void
cctests_p_assert_ascii (cce_destination_t L, char const * expected, char const * result, size_t result_len,
			char const * const expr,
			char const * const filename, char const * const funcname, int const linenum)
/* Compare non-zero terminated strings. */
{
  size_t	expected_len = strlen(expected);

  if ((expected_len != result_len) || (0 != strncmp(expected, result, result_len))) {
    cce_raise(L, cctests_condition_new_assertion_expected_ascii(L, expr, filename, funcname, linenum,
								expected, result, result_len));
  }
}


/** --------------------------------------------------------------------
 ** Immediate values comparisons.
 ** ----------------------------------------------------------------- */

#define DECLARE_IMMEDIATE_ASSERT(STEM,TYPE)				\
  void									\
  cctests_p_assert_equal_ ## STEM (cce_destination_t L, TYPE const expected, TYPE const result, \
				   char const * const expr,		\
				   char const * const filename, char const * const funcname, int const linenum) \
  {									\
    if (expected != result) {						\
      cce_raise(L, cctests_condition_new_assertion_expected_ ## STEM(L, expr, filename, funcname, linenum, expected, result)); \
    }									\
  }

DECLARE_IMMEDIATE_ASSERT(char,	signed	char)
DECLARE_IMMEDIATE_ASSERT(uchar,	unsigned char)

DECLARE_IMMEDIATE_ASSERT(int,	signed   int)
DECLARE_IMMEDIATE_ASSERT(uint,	unsigned int)

DECLARE_IMMEDIATE_ASSERT(short,	signed   short)
DECLARE_IMMEDIATE_ASSERT(ushort,unsigned short)

DECLARE_IMMEDIATE_ASSERT(long,	signed   long)
DECLARE_IMMEDIATE_ASSERT(ulong,	unsigned long)

DECLARE_IMMEDIATE_ASSERT(llong,	signed   long long)
DECLARE_IMMEDIATE_ASSERT(ullong,unsigned long long)

DECLARE_IMMEDIATE_ASSERT(int8,	int8_t)
DECLARE_IMMEDIATE_ASSERT(uint8,	uint8_t)

DECLARE_IMMEDIATE_ASSERT(int16,	int16_t)
DECLARE_IMMEDIATE_ASSERT(uint16,uint16_t)

DECLARE_IMMEDIATE_ASSERT(int32,	int32_t)
DECLARE_IMMEDIATE_ASSERT(uint32,uint32_t)

DECLARE_IMMEDIATE_ASSERT(int64,	int64_t)
DECLARE_IMMEDIATE_ASSERT(uint64,uint64_t)

DECLARE_IMMEDIATE_ASSERT(float,	float)
DECLARE_IMMEDIATE_ASSERT(double,double)

DECLARE_IMMEDIATE_ASSERT(size,  size_t)
DECLARE_IMMEDIATE_ASSERT(ssize, ssize_t)

DECLARE_IMMEDIATE_ASSERT(ptrdiff, ptrdiff_t)
DECLARE_IMMEDIATE_ASSERT(intptr,  intptr_t)
DECLARE_IMMEDIATE_ASSERT(uintptr, uintptr_t)

/* ------------------------------------------------------------------ */

void
cctests_p_assert_equal_pointer (cce_destination_t L, void * expected, void * result,
				char const * const expr,
				char const * const filename, char const * const funcname, int const linenum)
{
  if (expected != result) {
    cce_raise(L, cctests_condition_new_assertion_expected_pointer(L, expr, filename, funcname, linenum, expected, result));
  }
}

/* end of file */
