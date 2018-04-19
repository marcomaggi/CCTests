/*
  Part of: CCTests
  Contents: assertion functions
  Date: Nov 28, 2017

  Abstract



  Copyright (C) 2017, 2018 Marco Maggi <marco.maggi-ipsu@poste.it>

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
#include <inttypes.h>


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
    if (0) {
      fprintf(cctests_log_stream, "CCTests: %s: %s: line %d: assertion failure: %s\n",
	      filename, funcname, linenum, expr);
      fprintf(cctests_log_stream, "\texpected: %s\n", expected);
      fprintf(cctests_log_stream, "\tresult:   %s\n", result);
    }
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
    if (0) {
      fprintf(cctests_log_stream, "CCTests: %s: %s: line %d: assertion failure: %s\n",
	      filename, funcname, linenum, expr);
      fprintf(cctests_log_stream, "\texpected: %s (len=%lu)\n", expected, expected_len);
      fprintf(cctests_log_stream, "\tresult:   ");
      fwrite(result, sizeof(char), result_len, cctests_log_stream);
      fprintf(cctests_log_stream, " (len=%lu)\n", result_len);
    }
    cce_raise(L, cctests_condition_new_assertion_expected_ascii(L, expr, filename, funcname, linenum,
								expected, result, result_len));
  }
}


/** --------------------------------------------------------------------
 ** Immediate values comparisons.
 ** ----------------------------------------------------------------- */

#define DECLARE_IMMEDIATE_ASSERT(STEM,TYPE,PRINTF_FORMAT)		\
  void									\
  cctests_p_assert_equal_ ## STEM (cce_destination_t L, TYPE const expected, TYPE const result, \
				   char const * const expr,		\
				   char const * const filename, char const * const funcname, int const linenum) \
  {									\
    if (expected != result) {						\
      if (0) {								\
	fprintf(cctests_log_stream, "CCTests: %s: %s: line %d: assertion failure: %s\n", \
		filename, funcname, linenum, expr);			\
	fprintf(cctests_log_stream, "\texpected: ");			\
	fprintf(cctests_log_stream, PRINTF_FORMAT, expected);		\
	fprintf(cctests_log_stream, "\n");				\
	fprintf(cctests_log_stream, "\tresult:   ");			\
	fprintf(cctests_log_stream, PRINTF_FORMAT, result);		\
	fprintf(cctests_log_stream, "\n");				\
      }									\
      cce_raise(L, cctests_condition_new_assertion_expected_ ## STEM(L, expr, filename, funcname, linenum, expected, result)); \
    }									\
  }

DECLARE_IMMEDIATE_ASSERT(char_signed,	signed	char,	"%c")
DECLARE_IMMEDIATE_ASSERT(char_unsigned,	unsigned char,	"%c")

DECLARE_IMMEDIATE_ASSERT(int_signed,	signed   int,	"%d")
DECLARE_IMMEDIATE_ASSERT(int_unsigned,	unsigned int,	"%u")

DECLARE_IMMEDIATE_ASSERT(long_signed,	signed   long,	"%ld")
DECLARE_IMMEDIATE_ASSERT(long_unsigned,	unsigned long,	"%lu")

DECLARE_IMMEDIATE_ASSERT(int8,		int8_t,		"%" PRId8)
DECLARE_IMMEDIATE_ASSERT(uint8,		uint8_t,	"%" PRIu8)

DECLARE_IMMEDIATE_ASSERT(int16,		int16_t,	"%" PRId16)
DECLARE_IMMEDIATE_ASSERT(uint16,	uint16_t,	"%" PRIu16)

DECLARE_IMMEDIATE_ASSERT(int32,		int32_t,	"%" PRId32)
DECLARE_IMMEDIATE_ASSERT(uint32,	uint32_t,	"%" PRIu32)

DECLARE_IMMEDIATE_ASSERT(int64,		int64_t,	"%" PRId64)
DECLARE_IMMEDIATE_ASSERT(uint64,	uint64_t,	"%" PRIu64)

DECLARE_IMMEDIATE_ASSERT(float,		float,		"%f")
DECLARE_IMMEDIATE_ASSERT(double,	double,		"%f")

/* end of file */
