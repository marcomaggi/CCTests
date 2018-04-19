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

unsigned char const		CCTESTS_UNSIGNED_CHAR_MAX	= UCHAR_MAX;
unsigned char const		CCTESTS_UNSIGNED_CHAR_MIN	= 0;
signed char const		CCTESTS_SIGNED_CHAR_MAX		= SCHAR_MAX;
signed char const		CCTESTS_SIGNED_CHAR_MIN		= SCHAR_MIN;

unsigned int const		CCTESTS_UNSIGNED_INT_MAX	= UINT_MAX;
unsigned int const		CCTESTS_UNSIGNED_INT_MIN	= 0;
signed int const		CCTESTS_SIGNED_INT_MAX		= INT_MAX;
signed int const		CCTESTS_SIGNED_INT_MIN		= INT_MIN;

unsigned short const		CCTESTS_UNSIGNED_SHORT_MAX	= USHRT_MAX;
unsigned short const		CCTESTS_UNSIGNED_SHORT_MIN	= 0;
signed short const		CCTESTS_SIGNED_SHORT_MAX	= SHRT_MAX;
signed short const		CCTESTS_SIGNED_SHORT_MIN	= SHRT_MIN;

unsigned long const		CCTESTS_UNSIGNED_LONG_MAX	= ULONG_MAX;
unsigned long const		CCTESTS_UNSIGNED_LONG_MIN	= 0L;
signed long const		CCTESTS_SIGNED_LONG_MAX		= LONG_MAX;
signed long const		CCTESTS_SIGNED_LONG_MIN		= LONG_MIN;

unsigned long long const	CCTESTS_UNSIGNED_LONG_LONG_MAX	= ULLONG_MAX;
unsigned long long const	CCTESTS_UNSIGNED_LONG_LONG_MIN	= 0;
signed long long const		CCTESTS_SIGNED_LONG_LONG_MAX	= LLONG_MAX;
signed long long const		CCTESTS_SIGNED_LONG_LONG_MIN	= LLONG_MIN;

/* ------------------------------------------------------------------ */

uint8_t	const	CCTESTS_UINT8_MAX	= 255;
uint8_t	const	CCTESTS_UINT8_MIN	= 0;
int8_t	const	CCTESTS_INT8_MAX	= +127;
int8_t	const	CCTESTS_INT8_MIN	= -128;

uint16_t const	CCTESTS_UINT16_MAX	= 65535;
uint16_t const	CCTESTS_UINT16_MIN	= 0;
int16_t  const	CCTESTS_INT16_MAX	= +32767;
int16_t  const	CCTESTS_INT16_MIN	= -32768;

uint32_t const	CCTESTS_UINT32_MAX	= 4294967295;
uint32_t const	CCTESTS_UINT32_MIN	= 0;
int32_t  const	CCTESTS_INT32_MAX	= +2147483647;
int32_t  const	CCTESTS_INT32_MIN	= -2147483648;

uint64_t const	CCTESTS_UINT64_MAX	= 18446744073709551615;
uint64_t const	CCTESTS_UINT64_MIN	= 0;
int64_t  const	CCTESTS_INT64_MAX	= +9223372036854775807;
int64_t  const	CCTESTS_INT64_MIN	= -9223372036854775808;

/* end of file */
