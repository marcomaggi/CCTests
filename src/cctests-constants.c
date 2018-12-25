/*
  Part of: CCTests
  Contents: constants definitions
  Date: Thu Apr 19, 2018

  Abstract



  Copyright (C) 2018 Marco Maggi <marco.maggi-ipsu@poste.it>

  This is free software; you can  redistribute it and/or modify it under
  the terms of the GNU Lesser General Public License as published by the
  Free Software  Foundation; either version  3.0 of the License,  or (at
  your option) any later version.

  This library  is distributed in the  hope that it will  be useful, but
  WITHOUT   ANY  WARRANTY;   without  even   the  implied   warranty  of
  MERCHANTABILITY  or FITNESS  FOR A  PARTICULAR PURPOSE.   See  the GNU
  Lesser General Public License for more details.

  You  should have  received a  copy of  the GNU  Lesser  General Public
  License along  with this library; if  not, write to  the Free Software
  Foundation, Inc.,  59 Temple Place,  Suite 330, Boston,  MA 02111-1307
  USA.
*/


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#include "cctests-internals.h"
#include <limits.h>


/** --------------------------------------------------------------------
 ** Limits.
 ** ----------------------------------------------------------------- */

unsigned char const		CCTESTS_UCHAR_MAX	= UCHAR_MAX;
unsigned char const		CCTESTS_UCHAR_MIN	= 0;
signed char const		CCTESTS_CHAR_MAX	= SCHAR_MAX;
signed char const		CCTESTS_CHAR_MIN	= SCHAR_MIN;

unsigned int const		CCTESTS_UINT_MAX	= UINT_MAX;
unsigned int const		CCTESTS_UINT_MIN	= 0;
signed int const		CCTESTS_INT_MAX		= INT_MAX;
signed int const		CCTESTS_INT_MIN		= INT_MIN;

unsigned short const		CCTESTS_USHORT_MAX	= USHRT_MAX;
unsigned short const		CCTESTS_USHORT_MIN	= 0;
signed short const		CCTESTS_SHORT_MAX	= SHRT_MAX;
signed short const		CCTESTS_SHORT_MIN	= SHRT_MIN;

unsigned long const		CCTESTS_ULONG_MAX	= ULONG_MAX;
unsigned long const		CCTESTS_ULONG_MIN	= 0L;
signed long const		CCTESTS_LONG_MAX	= LONG_MAX;
signed long const		CCTESTS_LONG_MIN	= LONG_MIN;

unsigned long long const	CCTESTS_ULLONG_MAX	= ULLONG_MAX;
unsigned long long const	CCTESTS_ULLONG_MIN	= 0;
signed long long const		CCTESTS_LLONG_MAX	= LLONG_MAX;
signed long long const		CCTESTS_LLONG_MIN	= LLONG_MIN;

/* ------------------------------------------------------------------ */

#define CCTESTS_UINT32_MAX_VAL		4294967295
#define CCTESTS_UINT32_MIN_VAL		0
#if (4 == MMUX_SIZEOF_LONG)
#  define CCTESTS_UINT64_MAX_VAL	ULLONG_MAX
#  define CCTESTS_UINT64_MIN_VAL	0uLL
#else
#  define CCTESTS_UINT64_MAX_VAL	ULONG_MAX
#  define CCTESTS_UINT64_MIN_VAL	0uL
#endif

#define CCTESTS_INT32_MAX_VAL		+2147483647
#define CCTESTS_INT32_MIN_VAL		-2147483648
#if (4 == MMUX_SIZEOF_LONG)
#  define CCTESTS_INT64_MAX_VAL		LLONG_MAX
#  define CCTESTS_INT64_MIN_VAL		LLONG_MIN
#else
#  define CCTESTS_INT64_MAX_VAL		LONG_MAX
#  define CCTESTS_INT64_MIN_VAL		LONG_MIN
#endif

/* ------------------------------------------------------------------ */

uint8_t	const	CCTESTS_UINT8_MAX	= 255;
uint8_t	const	CCTESTS_UINT8_MIN	= 0;
int8_t	const	CCTESTS_INT8_MAX	= +127;
int8_t	const	CCTESTS_INT8_MIN	= -128;

uint16_t const	CCTESTS_UINT16_MAX	= 65535;
uint16_t const	CCTESTS_UINT16_MIN	= 0;
int16_t  const	CCTESTS_INT16_MAX	= +32767;
int16_t  const	CCTESTS_INT16_MIN	= -32768;

uint32_t const	CCTESTS_UINT32_MAX	= CCTESTS_UINT32_MAX_VAL;
uint32_t const	CCTESTS_UINT32_MIN	= CCTESTS_UINT32_MIN_VAL;
int32_t  const	CCTESTS_INT32_MAX	= CCTESTS_INT32_MAX_VAL;
int32_t  const	CCTESTS_INT32_MIN	= CCTESTS_INT32_MIN_VAL;

uint64_t const	CCTESTS_UINT64_MAX	= CCTESTS_UINT64_MAX_VAL;
uint64_t const	CCTESTS_UINT64_MIN	= CCTESTS_UINT64_MIN_VAL;
int64_t  const	CCTESTS_INT64_MAX	= CCTESTS_INT64_MAX_VAL;
int64_t  const	CCTESTS_INT64_MIN	= CCTESTS_INT64_MIN_VAL;

#if (4 == MMUX_SIZEOF_SIZE_T)
size_t  const	CCTESTS_SIZE_MAX	= CCTESTS_UINT32_MAX_VAL;
size_t  const	CCTESTS_SIZE_MIN	= CCTESTS_UINT32_MIN_VAL;
#else
size_t  const	CCTESTS_SIZE_MAX	= CCTESTS_UINT64_MAX_VAL;
size_t  const	CCTESTS_SIZE_MIN	= CCTESTS_UINT64_MIN_VAL;
#endif

#if (4 == MMUX_SIZEOF_SSIZE_T)
ssize_t  const	CCTESTS_SSIZE_MAX	= CCTESTS_INT32_MAX_VAL;
ssize_t  const	CCTESTS_SSIZE_MIN	= CCTESTS_INT32_MIN_VAL;
#else
ssize_t  const	CCTESTS_SSIZE_MAX	= CCTESTS_INT64_MAX_VAL;
ssize_t  const	CCTESTS_SSIZE_MIN	= CCTESTS_INT64_MIN_VAL;
#endif

#if (4 == MMUX_SIZEOF_PTRDIFF_T)
ptrdiff_t const	CCTESTS_PTRDIFF_MAX	= CCTESTS_INT32_MAX_VAL;
ptrdiff_t const	CCTESTS_PTRDIFF_MIN	= CCTESTS_INT32_MIN_VAL;
#else
ptrdiff_t const	CCTESTS_PTRDIFF_MAX	= CCTESTS_INT64_MAX_VAL;
ptrdiff_t const	CCTESTS_PTRDIFF_MIN	= CCTESTS_INT64_MIN_VAL;
#endif

#if (4 == MMUX_SIZEOF_INTPTR_T)
intptr_t const	CCTESTS_INTPTR_MAX	= CCTESTS_INT32_MAX_VAL;
intptr_t const	CCTESTS_INTPTR_MIN	= CCTESTS_INT32_MIN_VAL;
#else
intptr_t const	CCTESTS_INTPTR_MAX	= CCTESTS_INT64_MAX_VAL;
intptr_t const	CCTESTS_INTPTR_MIN	= CCTESTS_INT64_MIN_VAL;
#endif

#if (4 == MMUX_SIZEOF_UINTPTR_T)
uintptr_t const	CCTESTS_UINTPTR_MAX	= CCTESTS_INT32_MAX_VAL;
uintptr_t const	CCTESTS_UINTPTR_MIN	= CCTESTS_INT32_MIN_VAL;
#else
uintptr_t const	CCTESTS_UINTPTR_MAX	= CCTESTS_UINT64_MAX_VAL;
uintptr_t const	CCTESTS_UINTPTR_MIN	= CCTESTS_UINT64_MIN_VAL;
#endif

/* end of file */
