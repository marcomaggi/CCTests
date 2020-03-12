/*
  Part of: CCTests
  Contents: assertion functions
  Date: Nov 28, 2017

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
#include <string.h>
#include <inttypes.h>
#include <stdarg.h>


/** --------------------------------------------------------------------
 ** Preprocessor symbols.
 ** ----------------------------------------------------------------- */

#undef CCTESTS_P_ASSERT_COMMON_SIGNATURE_ARGS
#define CCTESTS_P_ASSERT_COMMON_SIGNATURE_ARGS	\
  char const * const expr, char const * const filename, char const * const funcname, \
    int const linenum, char const * const description_message

#undef CCTESTS_P_ASSERT_COMMON_CALL_ARGS
#define CCTESTS_P_ASSERT_COMMON_CALL_ARGS	\
  expr, filename, funcname, linenum, description_message


/** --------------------------------------------------------------------
 ** Helpers.
 ** ----------------------------------------------------------------- */

char const *
cctests_p_format_message (cce_destination_t L, char const * const template, ...)
{
  if (template) {
    size_t	str_len		= 255;
    char	*str_ptr	= cce_sys_malloc(L, 1+str_len);
    size_t	required_len	= 0;

    {
      va_list	ap;

      va_start(ap, template);
      {
	required_len = vsnprintf(str_ptr, str_len, template, ap);
      }
      va_end(ap);
    }
    if (str_len <= required_len) {
      /* Not enough room in "str_ptr". */
      va_list	ap;

      str_len = required_len;
      str_ptr = cce_sys_realloc(L, str_ptr, 1+str_len);
      va_start(ap, template);
      {
	vsnprintf(str_ptr, str_len, template, ap);
      }
      va_end(ap);
    }
    return str_ptr;
  } else {
    return NULL;
  }
}


/** --------------------------------------------------------------------
 ** Assertions: raw expression.
 ** ----------------------------------------------------------------- */

void
cctests_p_assert_raise (cce_destination_t L, CCTESTS_P_ASSERT_COMMON_SIGNATURE_ARGS)
{
  cce_raise(L, cctests_condition_new_assertion(L, CCTESTS_P_ASSERT_COMMON_CALL_ARGS));
}


/** --------------------------------------------------------------------
 ** Assertions: ASCIIZ string comparison.
 ** ----------------------------------------------------------------- */

bool
cctests_p_assert_asciiz_compare (char const * const expected, char const * const result)
/* Return "false" if "expected" and "result" are equal! */
{
  return ((0 == strcmp(expected, result))? false : true);
}

void
cctests_p_assert_asciiz_raise (cce_destination_t L, char const * const expected, char const * const result,
			       CCTESTS_P_ASSERT_COMMON_SIGNATURE_ARGS)
/* Compare zero-terminated strings. */
{
  cce_raise(L, cctests_condition_new_assertion_expected_asciiz(L, expected, result, CCTESTS_P_ASSERT_COMMON_CALL_ARGS));
}


/** --------------------------------------------------------------------
 ** Assertions: ASCII string comparison.
 ** ----------------------------------------------------------------- */

bool
cctests_p_assert_ascii_compare (char const * const expected, char const * const result, size_t const result_len)
/* Return "false" if "expected" and "result" are equal! */
{
  size_t const	expected_len = strlen(expected);

  return (((expected_len == result_len) && (0 == strncmp(expected, result, result_len)))? false : true);
}

void
cctests_p_assert_ascii_raise (cce_destination_t L, char const * const expected, char const * const result, size_t const result_len,
			      CCTESTS_P_ASSERT_COMMON_SIGNATURE_ARGS)
{
  cce_raise(L, cctests_condition_new_assertion_expected_ascii(L, expected, result, result_len, CCTESTS_P_ASSERT_COMMON_CALL_ARGS));
}


/** --------------------------------------------------------------------
 ** Immediate values comparisons.
 ** ----------------------------------------------------------------- */

#define DECLARE_IMMEDIATE_ASSERT_FUNCS(STEM,TYPE)			\
  bool									\
  cctests_p_assert_ ## STEM ## _compare (TYPE const expected, TYPE const result) \
  {									\
    return ((expected == result)? false : true);			\
  }									\
  void									\
  cctests_p_assert_ ## STEM ## _raise (cce_destination_t L, TYPE const expected, TYPE const result, CCTESTS_P_ASSERT_COMMON_SIGNATURE_ARGS) \
  {									\
    cce_raise(L, cctests_condition_new_assertion_expected_ ## STEM(L, expected, result, CCTESTS_P_ASSERT_COMMON_CALL_ARGS)); \
  }

DECLARE_IMMEDIATE_ASSERT_FUNCS(char,	signed	char)
DECLARE_IMMEDIATE_ASSERT_FUNCS(uchar,	unsigned char)

DECLARE_IMMEDIATE_ASSERT_FUNCS(int,	signed   int)
DECLARE_IMMEDIATE_ASSERT_FUNCS(uint,	unsigned int)

DECLARE_IMMEDIATE_ASSERT_FUNCS(short,	signed   short)
DECLARE_IMMEDIATE_ASSERT_FUNCS(ushort,unsigned short)

DECLARE_IMMEDIATE_ASSERT_FUNCS(long,	signed   long)
DECLARE_IMMEDIATE_ASSERT_FUNCS(ulong,	unsigned long)

DECLARE_IMMEDIATE_ASSERT_FUNCS(llong,	signed   long long)
DECLARE_IMMEDIATE_ASSERT_FUNCS(ullong,unsigned long long)

DECLARE_IMMEDIATE_ASSERT_FUNCS(int8,	int8_t)
DECLARE_IMMEDIATE_ASSERT_FUNCS(uint8,	uint8_t)

DECLARE_IMMEDIATE_ASSERT_FUNCS(int16,	int16_t)
DECLARE_IMMEDIATE_ASSERT_FUNCS(uint16,uint16_t)

DECLARE_IMMEDIATE_ASSERT_FUNCS(int32,	int32_t)
DECLARE_IMMEDIATE_ASSERT_FUNCS(uint32,uint32_t)

DECLARE_IMMEDIATE_ASSERT_FUNCS(int64,	int64_t)
DECLARE_IMMEDIATE_ASSERT_FUNCS(uint64,uint64_t)

DECLARE_IMMEDIATE_ASSERT_FUNCS(float,	float)
DECLARE_IMMEDIATE_ASSERT_FUNCS(double,double)

DECLARE_IMMEDIATE_ASSERT_FUNCS(size,  size_t)
DECLARE_IMMEDIATE_ASSERT_FUNCS(ssize, ssize_t)

DECLARE_IMMEDIATE_ASSERT_FUNCS(ptrdiff, ptrdiff_t)
DECLARE_IMMEDIATE_ASSERT_FUNCS(intptr,  intptr_t)
DECLARE_IMMEDIATE_ASSERT_FUNCS(uintptr, uintptr_t)


/** --------------------------------------------------------------------
 ** More immediate values comparisons.
 ** ----------------------------------------------------------------- */

bool
cctests_p_assert_pointer_compare (void * const expected, void * const result)
{
  return ((expected == result)? false : true);
}
void
cctests_p_assert_pointer_raise (cce_destination_t L, void * const expected, void * const result, CCTESTS_P_ASSERT_COMMON_SIGNATURE_ARGS)
{
  cce_raise(L, cctests_condition_new_assertion_expected_pointer(L, expected, result, CCTESTS_P_ASSERT_COMMON_CALL_ARGS));
}

/* end of file */
