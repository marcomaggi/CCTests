/*
  Part of: CCTests
  Contents: tests for assertions
  Date: Apr 14, 2018

  Abstract

	Test file for assertions.

  Copyright (C) 2018, 2019 Marco Maggi <mrc.mgg@gmail.com>

  See the COPYING file.
*/


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#include <cctests.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/** --------------------------------------------------------------------
 ** Expression assertions.
 ** ----------------------------------------------------------------- */

static void
test_1_1_1 (cce_destination_t L)
{
  cctests_assert(L, true);
}

static void
test_1_1_2 (cce_destination_t L)
{
  cctests_assert(L, false);
}

/* ------------------------------------------------------------------ */

static void
test_1_2_1 (cce_destination_t L)
{
  cctests_assert_true(L, true);
}

static void
test_1_2_2 (cce_destination_t L)
{
  cctests_assert_true(L, false);
}

/* ------------------------------------------------------------------ */

static void
test_1_3_1 (cce_destination_t L)
{
  cctests_assert_false(L, true);
}

static void
test_1_3_2 (cce_destination_t L)
{
  cctests_assert_false(L, false);
}

/* ------------------------------------------------------------------ */

static void
test_1_4_1 (cce_destination_t L)
{
  cctests_assert(L, true, "the expression is: %d", true);
}

static void
test_1_4_2 (cce_destination_t L)
{
  cctests_assert(L, false, "the expression is: %d", false);
}

static void
test_1_4_3 (cce_destination_t L)
/* Test the macro without optional arguments. */
{
  cctests_assert(L, true, "the expression is: true");
}

static void
test_1_4_4 (cce_destination_t L)
/* Test the macro without optional arguments. */
{
  cctests_assert(L, false, "the expression is: false");
}

/* ------------------------------------------------------------------ */

static void
test_1_5_1 (cce_destination_t L)
{
  cctests_assert_true(L, true, "the expression is: %d", true);
}

static void
test_1_5_2 (cce_destination_t L)
{
  cctests_assert_true(L, false, "the expression is: %d", false);
}

static void
test_1_5_3 (cce_destination_t L)
/* Test the macro without optional arguments. */
{
  cctests_assert_true(L, true, "the expression is: true");
}

static void
test_1_5_4 (cce_destination_t L)
/* Test the macro without optional arguments. */
{
  cctests_assert_true(L, false, "the expression is: false");
}

/* ------------------------------------------------------------------ */

static void
test_1_6_1 (cce_destination_t L)
{
  cctests_assert_false(L, true, "the expression is: %d", true);
}

static void
test_1_6_2 (cce_destination_t L)
{
  cctests_assert_false(L, false, "the expression is: %d", false);
}

static void
test_1_6_3 (cce_destination_t L)
/* Test the macro without optional arguments. */
{
  cctests_assert_false(L, true, "the expression is: true");
}

static void
test_1_6_4 (cce_destination_t L)
/* Test the macro without optional arguments. */
{
  cctests_assert_false(L, false, "the expression is: false");
}


/** --------------------------------------------------------------------
 ** ASCIIZ string assertions.
 ** ----------------------------------------------------------------- */

static void
test_2_1 (cce_destination_t L)
{
  cctests_assert_asciiz(L, "ciao", "ciao");
}

static void
test_2_2 (cce_destination_t L)
{
  cctests_assert_asciiz(L, "ciao", "hello");
}

static void
test_2_3 (cce_destination_t L)
{
  cctests_assert_asciiz(L, "ciao", "ciao", "the static message");
}

static void
test_2_4 (cce_destination_t L)
{
  cctests_assert_asciiz(L, "ciao", "hello", "the static message");
}

static void
test_2_5 (cce_destination_t L)
{
  cctests_assert_asciiz(L, "ciao", "ciao", "the %s message", "dynamic");
}

static void
test_2_6 (cce_destination_t L)
{
  cctests_assert_asciiz(L, "ciao", "hello", "the %s message", "dynamic");
}


/** --------------------------------------------------------------------
 ** ASCII string assertions.
 ** ----------------------------------------------------------------- */

static void
test_3_1 (cce_destination_t L)
{
  cctests_assert_ascii(L, "ciao", "ciao", strlen("ciao"));
}

static void
test_3_2 (cce_destination_t L)
{
  cctests_assert_ascii(L, "ciao", "hello", strlen("hello"));
}

static void
test_3_3 (cce_destination_t L)
{
  cctests_assert_ascii(L, "ciao", "ciao", strlen("ciao"), "the static message");
}

static void
test_3_4 (cce_destination_t L)
{
  cctests_assert_ascii(L, "ciao", "hello", strlen("hello"), "the static message");
}

static void
test_3_5 (cce_destination_t L)
{
  cctests_assert_ascii(L, "ciao", "ciao", strlen("ciao"), "the %s message", "dynamic");
}

static void
test_3_6 (cce_destination_t L)
{
  cctests_assert_ascii(L, "ciao", "hello", strlen("hello"), "the %s message", "dynamic");
}


/** --------------------------------------------------------------------
 ** Immediate value equality assertions.
 ** ----------------------------------------------------------------- */

#define DECLARE_IMMEDIATE_TEST_SUCC(FUNCNAME,ASSERT_NAME,VALUE)	\
  static void							\
  FUNCNAME (cce_destination_t L)				\
  {								\
    ASSERT_NAME(L, VALUE, VALUE);				\
  }

#define DECLARE_IMMEDIATE_TEST_FAIL(FUNCNAME,ASSERT_NAME,EXPECTED,RESULT,VERBOSE)	\
  static void								\
  FUNCNAME (cce_destination_t L)					\
  {									\
    ASSERT_NAME(L, EXPECTED, RESULT);					\
  }

/* ------------------------------------------------------------------ */

DECLARE_IMMEDIATE_TEST_SUCC(test_4_1_1_1, cctests_assert_equal_char,  'A')
DECLARE_IMMEDIATE_TEST_FAIL(test_4_1_1_2, cctests_assert_equal_char,  'A', 'B', false)
DECLARE_IMMEDIATE_TEST_SUCC(test_4_1_2_1, cctests_assert_equal_uchar, 'A')
DECLARE_IMMEDIATE_TEST_FAIL(test_4_1_2_2, cctests_assert_equal_uchar, 'A', 'B', false)

DECLARE_IMMEDIATE_TEST_SUCC(test_4_2_1_1, cctests_assert_equal_int,  123)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_2_1_2, cctests_assert_equal_int,  123, 456, false)
DECLARE_IMMEDIATE_TEST_SUCC(test_4_2_2_1, cctests_assert_equal_uint, 123)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_2_2_2, cctests_assert_equal_uint, 123, 456, false)

DECLARE_IMMEDIATE_TEST_SUCC(test_4_14_1_1, cctests_assert_equal_short,  123)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_14_1_2, cctests_assert_equal_short,  123, 456, false)
DECLARE_IMMEDIATE_TEST_SUCC(test_4_14_2_1, cctests_assert_equal_ushort, 123)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_14_2_2, cctests_assert_equal_ushort, 123, 456, false)

DECLARE_IMMEDIATE_TEST_SUCC(test_4_3_1_1, cctests_assert_equal_long,  (CCTESTS_LONG_MAX - 123))
DECLARE_IMMEDIATE_TEST_FAIL(test_4_3_1_2, cctests_assert_equal_long,  (CCTESTS_LONG_MAX - 123), (CCTESTS_LONG_MAX - 456), false)
DECLARE_IMMEDIATE_TEST_SUCC(test_4_3_2_1, cctests_assert_equal_ulong, (CCTESTS_ULONG_MAX - 123))
DECLARE_IMMEDIATE_TEST_FAIL(test_4_3_2_2, cctests_assert_equal_ulong, (CCTESTS_ULONG_MAX - 123), (CCTESTS_ULONG_MAX - 456), false)

DECLARE_IMMEDIATE_TEST_SUCC(test_4_15_1_1, cctests_assert_equal_llong,  (CCTESTS_LLONG_MAX - 123))
DECLARE_IMMEDIATE_TEST_FAIL(test_4_15_1_2, cctests_assert_equal_llong,  (CCTESTS_LLONG_MAX - 123), (CCTESTS_LLONG_MAX - 456), false)
DECLARE_IMMEDIATE_TEST_SUCC(test_4_15_2_1, cctests_assert_equal_ullong, (CCTESTS_ULLONG_MAX - 123))
DECLARE_IMMEDIATE_TEST_FAIL(test_4_15_2_2, cctests_assert_equal_ullong, (CCTESTS_ULLONG_MAX - 123), (CCTESTS_ULLONG_MAX - 456), false)

/* ------------------------------------------------------------------ */

DECLARE_IMMEDIATE_TEST_SUCC(test_4_4_1_1, cctests_assert_equal_int8, CCTESTS_INT8_MAX)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_4_1_2, cctests_assert_equal_int8, CCTESTS_INT8_MAX, 123, false)
DECLARE_IMMEDIATE_TEST_SUCC(test_4_4_2_1, cctests_assert_equal_int8, CCTESTS_INT8_MAX)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_4_2_2, cctests_assert_equal_int8, CCTESTS_INT8_MAX, 123, false)

DECLARE_IMMEDIATE_TEST_SUCC(test_4_5_1_1, cctests_assert_equal_uint8, CCTESTS_UINT8_MAX)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_5_1_2, cctests_assert_equal_uint8, CCTESTS_UINT8_MAX, 123, false)
DECLARE_IMMEDIATE_TEST_SUCC(test_4_5_2_1, cctests_assert_equal_uint8, CCTESTS_UINT8_MAX)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_5_2_2, cctests_assert_equal_uint8, CCTESTS_UINT8_MAX, 123, false)

/* ------------------------------------------------------------------ */

DECLARE_IMMEDIATE_TEST_SUCC(test_4_6_1_1, cctests_assert_equal_int16, CCTESTS_INT16_MAX)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_6_1_2, cctests_assert_equal_int16, CCTESTS_INT16_MAX, 123, false)
DECLARE_IMMEDIATE_TEST_SUCC(test_4_6_2_1, cctests_assert_equal_int16, CCTESTS_INT16_MAX)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_6_2_2, cctests_assert_equal_int16, CCTESTS_INT16_MAX, 123, false)

DECLARE_IMMEDIATE_TEST_SUCC(test_4_7_1_1, cctests_assert_equal_uint16, CCTESTS_UINT16_MAX)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_7_1_2, cctests_assert_equal_uint16, CCTESTS_UINT16_MAX, 123, false)
DECLARE_IMMEDIATE_TEST_SUCC(test_4_7_2_1, cctests_assert_equal_uint16, CCTESTS_UINT16_MAX)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_7_2_2, cctests_assert_equal_uint16, CCTESTS_UINT16_MAX, 123, false)

/* ------------------------------------------------------------------ */

DECLARE_IMMEDIATE_TEST_SUCC(test_4_8_1_1, cctests_assert_equal_int32, CCTESTS_INT32_MAX)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_8_1_2, cctests_assert_equal_int32, CCTESTS_INT32_MAX, 123, false)
DECLARE_IMMEDIATE_TEST_SUCC(test_4_8_2_1, cctests_assert_equal_int32, CCTESTS_INT32_MAX)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_8_2_2, cctests_assert_equal_int32, CCTESTS_INT32_MAX, 123, false)

DECLARE_IMMEDIATE_TEST_SUCC(test_4_9_1_1, cctests_assert_equal_uint32, CCTESTS_UINT32_MAX)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_9_1_2, cctests_assert_equal_uint32, CCTESTS_UINT32_MAX, 123, false)
DECLARE_IMMEDIATE_TEST_SUCC(test_4_9_2_1, cctests_assert_equal_uint32, CCTESTS_UINT32_MAX)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_9_2_2, cctests_assert_equal_uint32, CCTESTS_UINT32_MAX, 123, false)

/* ------------------------------------------------------------------ */

DECLARE_IMMEDIATE_TEST_SUCC(test_4_10_1_1, cctests_assert_equal_int64, CCTESTS_INT64_MAX)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_10_1_2, cctests_assert_equal_int64, CCTESTS_INT64_MAX, 123, false)
DECLARE_IMMEDIATE_TEST_SUCC(test_4_10_2_1, cctests_assert_equal_int64, CCTESTS_INT64_MAX)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_10_2_2, cctests_assert_equal_int64, CCTESTS_INT64_MAX, 123, false)

DECLARE_IMMEDIATE_TEST_SUCC(test_4_11_1_1, cctests_assert_equal_uint64, CCTESTS_UINT64_MAX)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_11_1_2, cctests_assert_equal_uint64, CCTESTS_UINT64_MAX, 123, false)
DECLARE_IMMEDIATE_TEST_SUCC(test_4_11_2_1, cctests_assert_equal_uint64, CCTESTS_UINT64_MAX)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_11_2_2, cctests_assert_equal_uint64, CCTESTS_UINT64_MAX, 123, false)

/* ------------------------------------------------------------------ */

DECLARE_IMMEDIATE_TEST_SUCC(test_4_12_1_1, cctests_assert_equal_float, 123.45)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_12_1_2, cctests_assert_equal_float, 123.45, 89.0, false)
DECLARE_IMMEDIATE_TEST_SUCC(test_4_12_2_1, cctests_assert_equal_float, 123.45)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_12_2_2, cctests_assert_equal_float, 123.45, 89.0, false)

DECLARE_IMMEDIATE_TEST_SUCC(test_4_13_1_1, cctests_assert_equal_double, 123.45)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_13_1_2, cctests_assert_equal_double, 123.45, 89.0, false)
DECLARE_IMMEDIATE_TEST_SUCC(test_4_13_2_1, cctests_assert_equal_double, 123.45)
DECLARE_IMMEDIATE_TEST_FAIL(test_4_13_2_2, cctests_assert_equal_double, 123.45, 89.0, false)


int
main (void)
{
  cctests_init("assertions");
  {
    cctests_begin_group("Expression assertions");
    {
      cctests_run(test_1_1_1);
      cctests_run(test_1_1_2);

      cctests_run(test_1_2_1);
      cctests_run(test_1_2_2);

      cctests_run(test_1_3_1);
      cctests_run(test_1_3_2);

      cctests_run(test_1_4_1);
      cctests_run(test_1_4_2);
      cctests_run(test_1_4_3);
      cctests_run(test_1_4_4);

      cctests_run(test_1_5_1);
      cctests_run(test_1_5_2);
      cctests_run(test_1_5_3);
      cctests_run(test_1_5_4);

      cctests_run(test_1_6_1);
      cctests_run(test_1_6_2);
      cctests_run(test_1_6_3);
      cctests_run(test_1_6_4);
    }
    cctests_end_group();

    cctests_begin_group("ASCIIZ string assertions");
    {
      cctests_run(test_2_1);
      cctests_run(test_2_2);
      cctests_run(test_2_3);
      cctests_run(test_2_4);
      cctests_run(test_2_5);
      cctests_run(test_2_6);
    }
    cctests_end_group();

    cctests_begin_group("ASCII string assertions");
    {
      cctests_run(test_3_1);
      cctests_run(test_3_2);
      cctests_run(test_3_3);
      cctests_run(test_3_4);
      cctests_run(test_3_5);
      cctests_run(test_3_6);
    }
    cctests_end_group();

    cctests_begin_group("Immediate value equality assertions");
    {
      cctests_run(test_4_1_1_1);
      cctests_run(test_4_1_1_2);
      cctests_run(test_4_1_2_1);
      cctests_run(test_4_1_2_2);

      cctests_run(test_4_2_1_1);
      cctests_run(test_4_2_1_2);
      cctests_run(test_4_2_2_1);
      cctests_run(test_4_2_2_2);

      cctests_run(test_4_3_1_1);
      cctests_run(test_4_3_1_2);
      cctests_run(test_4_3_2_1);
      cctests_run(test_4_3_2_2);

      cctests_run(test_4_4_1_1);
      cctests_run(test_4_4_1_2);
      cctests_run(test_4_4_2_1);
      cctests_run(test_4_4_2_2);

      cctests_run(test_4_5_1_1);
      cctests_run(test_4_5_1_2);
      cctests_run(test_4_5_2_1);
      cctests_run(test_4_5_2_2);

      cctests_run(test_4_6_1_1);
      cctests_run(test_4_6_1_2);
      cctests_run(test_4_6_2_1);
      cctests_run(test_4_6_2_2);

      cctests_run(test_4_7_1_1);
      cctests_run(test_4_7_1_2);
      cctests_run(test_4_7_2_1);
      cctests_run(test_4_7_2_2);

      cctests_run(test_4_8_1_1);
      cctests_run(test_4_8_1_2);
      cctests_run(test_4_8_2_1);
      cctests_run(test_4_8_2_2);

      cctests_run(test_4_9_1_1);
      cctests_run(test_4_9_1_2);
      cctests_run(test_4_9_2_1);
      cctests_run(test_4_9_2_2);

      cctests_run(test_4_10_1_1);
      cctests_run(test_4_10_1_2);
      cctests_run(test_4_10_2_1);
      cctests_run(test_4_10_2_2);

      cctests_run(test_4_11_1_1);
      cctests_run(test_4_11_1_2);
      cctests_run(test_4_11_2_1);
      cctests_run(test_4_11_2_2);

      cctests_run(test_4_12_1_1);
      cctests_run(test_4_12_1_2);
      cctests_run(test_4_12_2_1);
      cctests_run(test_4_12_2_2);

      cctests_run(test_4_13_1_1);
      cctests_run(test_4_13_1_2);
      cctests_run(test_4_13_2_1);
      cctests_run(test_4_13_2_2);

      cctests_run(test_4_14_1_1);
      cctests_run(test_4_14_1_2);
      cctests_run(test_4_14_2_1);
      cctests_run(test_4_14_2_2);

      cctests_run(test_4_15_1_1);
      cctests_run(test_4_15_1_2);
      cctests_run(test_4_15_2_1);
      cctests_run(test_4_15_2_2);
    }
    cctests_end_group();
  }
  cctests_final();
}

/* end of file */
