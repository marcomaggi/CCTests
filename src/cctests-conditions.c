/*
  Part of: CCTests
  Contents: condition objects
  Date: Nov 28, 2017

  Abstract



  Copyright (C) 2017, 2018, 2019, 2020 Marco Maggi <mrc.mgg@gmail.com>

  This is free software; you  can redistribute it and/or modify it under
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
#include <string.h>
#include <inttypes.h>


/** --------------------------------------------------------------------
 ** Preprocessor symbols.
 ** ----------------------------------------------------------------- */

#undef CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS
#define CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS	\
  char const * const expr, char const * const filename, char const * const funcname, \
    int const linenum, char const * const description_message

#undef CCTESTS_CONDITION_COMMON_CALL_ARGS
#define CCTESTS_CONDITION_COMMON_CALL_ARGS	\
  expr, filename, funcname, linenum, description_message


/** --------------------------------------------------------------------
 ** Base exceptional condition descriptor.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_base;

static cctests_descriptor_base_t cctests_descriptor_base = {
  /* This  "parent" field  is  set below  by  the module  initialisation
     function. */
  .descriptor.parent		= NULL,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_base
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_base (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests base exceptional condition";
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_base (cctests_condition_base_t * C)
{
  cce_condition_init_root(&(C->root));
}

bool
cctests_condition_is_base (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_base.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_base_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_base);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: test success.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_success;

static cctests_descriptor_success_t const cctests_descriptor_success = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_base),
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_success
};

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_success_t const cctests_condition_success = {
  .base.root.condition.descriptor	= cce_descriptor_pointer(cctests_descriptor_success)
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_success (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests test success";
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_success (cctests_condition_success_t * C)
{
  cctests_condition_init_base(&(C->base));
}

cce_condition_t const *
cctests_condition_new_success (void)
{
  return (cce_condition_t *)&cctests_condition_success;
}

bool
cctests_condition_is_success (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_success.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_success_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_success);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: test skipped.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_skipped;

static cctests_descriptor_skipped_t const cctests_descriptor_skipped = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_base),
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_skipped
};

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_skipped_t const cctests_condition_skipped = {
  .base.root.condition.descriptor	= cce_descriptor_pointer(cctests_descriptor_skipped)
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_skipped (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests test skipped";
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_skipped (cctests_condition_skipped_t * C)
{
  cctests_condition_init_base(&(C->base));
}

cce_condition_t const *
cctests_condition_new_skipped (void)
{
  return (cce_condition_t *)&cctests_condition_skipped;
}

bool
cctests_condition_is_skipped (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_skipped.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_skipped_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_skipped);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: test failure.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_failure;

static cctests_descriptor_failure_t const cctests_descriptor_failure = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_base),
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_failure
};

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_failure_t const cctests_condition_failure = {
  .base.root.condition.descriptor	= cce_descriptor_pointer(cctests_descriptor_failure)
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_failure (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests test failure";
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_failure (cctests_condition_failure_t * C)
{
  cctests_condition_init_base(&(C->base));
}

cce_condition_t const *
cctests_condition_new_failure (void)
{
  return (cce_condition_t *)&cctests_condition_failure;
}

bool
cctests_condition_is_failure (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_failure.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_failure_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_failure);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: expected failure.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_expected_failure;

static cctests_descriptor_expected_failure_t const cctests_descriptor_expected_failure = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_failure),
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_expected_failure
};

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_expected_failure_t const cctests_condition_expected_failure = {
  .failure.base.root.condition.descriptor	= cce_descriptor_pointer(cctests_descriptor_expected_failure)
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_expected_failure (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests exception expected failure";
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_expected_failure (cctests_condition_expected_failure_t * C)
{
  cctests_condition_init_failure(&(C->failure));
}

cce_condition_t const *
cctests_condition_new_expected_failure (void)
{
  return (cce_condition_t *)&cctests_condition_expected_failure;
}

bool
cctests_condition_is_expected_failure (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_expected_failure.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_expected_failure_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_expected_failure);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: failed assertion.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_assertion;
static cce_condition_delete_fun_t		cctests_condition_delete_assertion;
static cctests_condition_print_assertion_fun_t	cctests_condition_print_assertion_fun;

static cctests_descriptor_assertion_t const cctests_descriptor_assertion = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_failure),
  .descriptor.delete		= cctests_condition_delete_assertion,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_assertion,
  .print			= cctests_condition_print_assertion_fun
};

/* ------------------------------------------------------------------ */

void
cctests_condition_delete_assertion (cce_condition_t * C)
{
  CCLIB_PC(cctests_condition_assertion_t, K, C);

  if (K->dynamic_string) {
    free((void *)K->dynamic_string);
  }
  free(K);
}

char const *
cctests_condition_static_message_assertion (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests assertion failure";
}

void
cctests_condition_print_assertion_fun (cce_condition_t const * C)
{
  CCLIB_PC(cctests_condition_assertion_t, K, C);

  fprintf(cctests_log_stream, "CCTests: %sassertion failure%s in test function %s: %s: %s: line %d\n",
	  cctests_terminal_failure_color, cctests_terminal_default_color,
	  cctests_test_func_name,
	  K->filename, K->funcname, K->linenum);
  if (K->dynamic_string) {
    fprintf(cctests_log_stream, "   description:  %s\n", K->dynamic_string);
  }
  fprintf(cctests_log_stream,   "   call:         %s\n", K->expr);
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_assertion (cctests_condition_assertion_t * C, CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS)
{
  /* Initialise the parent type. */
  cctests_condition_init_failure(&(C->failure));

  /* Initialise the fields of this type. */
  C->expr			= expr;
  C->filename			= filename;
  C->funcname			= funcname;
  C->linenum			= linenum;
  C->dynamic_string		= description_message;
}

cce_condition_t const *
cctests_condition_new_assertion (cce_destination_t L, CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS)
{
  cctests_condition_assertion_t	*C = cce_sys_malloc(L, sizeof(cctests_condition_assertion_t));

  /* Initialise the basic condition fields. */
  cce_condition_init((cce_condition_t *)C, cce_descriptor_pointer(cctests_descriptor_assertion));
  cctests_condition_init_assertion(C, CCTESTS_CONDITION_COMMON_CALL_ARGS);
  return (cce_condition_t const *)C;
}

/* ------------------------------------------------------------------ */

bool
cctests_condition_is_assertion (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_assertion.descriptor));
}

void
cctests_condition_print_assertion (cce_condition_t const * C)
{
  CCLIB_PC(cctests_descriptor_assertion_t, D, C->descriptor);

  D->print(C);
}

void
cce_descriptor_set_parent_to(cctests_descriptor_assertion_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_assertion);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: failed assertion, expected value.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_assertion_expected_value;
static cce_condition_delete_fun_t		cctests_condition_delete_assertion_expected_value;
static cctests_condition_print_assertion_fun_t	cctests_condition_print_assertion_expected_value_fun;

static cctests_descriptor_assertion_expected_value_t const cctests_descriptor_assertion_expected_value = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_assertion),
  .descriptor.delete		= cctests_condition_delete_assertion_expected_value,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_assertion_expected_value,
  .print			= cctests_condition_print_assertion_expected_value_fun
};

/* ------------------------------------------------------------------ */

void
cctests_condition_delete_assertion_expected_value (cce_condition_t * C)
{
  free(C);
}

char const *
cctests_condition_static_message_assertion_expected_value (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests assertion failure: expected a value, got another";
}

void
cctests_condition_print_assertion_expected_value_fun (cce_condition_t const * C)
{
  cctests_condition_print_assertion_fun(C);
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_assertion_expected_value (cctests_condition_assertion_expected_value_t * C,
						 CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS)
{
  /* Initialise the parent type. */
  cctests_condition_init_assertion(&(C->assertion), CCTESTS_CONDITION_COMMON_CALL_ARGS);
}

bool
cctests_condition_is_assertion_expected_value (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_assertion_expected_value.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_assertion_expected_value_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_assertion_expected_value);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: failed assertion, expected immediate value.
 ** ----------------------------------------------------------------- */

#define DECLARE_CONDITION_ASSERTION_EXPECTED(STEM, TYPE, PRINTF_FORMAT, PRINTF_CAST) \
  static cce_condition_static_message_fun_t	cctests_condition_static_message_assertion_expected_ ## STEM; \
  static cce_condition_delete_fun_t		cctests_condition_delete_assertion_expected_ ## STEM; \
  static cctests_condition_print_assertion_fun_t cctests_condition_print_assertion_expected_ ## STEM ## _fun; \
									\
  static cctests_descriptor_assertion_expected_ ## STEM ## _t const cctests_descriptor_assertion_expected_ ## STEM = { \
    .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_assertion_expected_value), \
    .descriptor.delete		= cctests_condition_delete_assertion_expected_ ## STEM, \
    .descriptor.final		= NULL,					\
    .descriptor.static_message	= cctests_condition_static_message_assertion_expected_ ## STEM, \
    .print			= cctests_condition_print_assertion_expected_ ## STEM ## _fun \
  };									\
									\
  void									\
  cctests_condition_delete_assertion_expected_ ## STEM (cce_condition_t * C) \
  {									\
    free(C);								\
  }									\
									\
  char const *								\
  cctests_condition_static_message_assertion_expected_ ## STEM (cce_condition_t const * C CCLIB_UNUSED) \
  {									\
    return "CCTests assertion failure, expected " #TYPE " value";	\
  }									\
									\
  void									\
  cctests_condition_print_assertion_expected_ ## STEM ## _fun (cce_condition_t const * C) \
  {									\
    cctests_condition_print_assertion_fun(C);				\
    {									\
      CCLIB_PC(cctests_condition_assertion_expected_ ## STEM ## _t, K, C); \
									\
      fprintf(cctests_log_stream, "   expected: ");			\
      fprintf(cctests_log_stream, "%" PRINTF_FORMAT, PRINTF_CAST K->expected); \
      fprintf(cctests_log_stream, "\n");				\
      fprintf(cctests_log_stream, "   result:   ");			\
      fprintf(cctests_log_stream, "%" PRINTF_FORMAT, PRINTF_CAST K->result); \
      fprintf(cctests_log_stream, "\n");				\
    }									\
  }									\
									\
  void									\
  cctests_condition_init_assertion_expected_ ## STEM			\
  (cctests_condition_assertion_expected_ ## STEM ## _t * C,		\
   TYPE expected, TYPE result, CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS) \
  {									\
    /* Initialise the parent type. */					\
    cctests_condition_init_assertion_expected_value(&(C->assertion_expected_value), CCTESTS_CONDITION_COMMON_CALL_ARGS); \
									\
    /* Initialise the fields of this type. */				\
    C->expected			= expected;				\
    C->result			= result;				\
  }									\
									\
  cce_condition_t const *						\
  cctests_condition_new_assertion_expected_ ## STEM			\
  (cce_destination_t L, TYPE expected, TYPE result, CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS) \
  {									\
    cctests_condition_assertion_expected_ ## STEM ## _t *	C =	\
      cce_sys_malloc(L, sizeof(cctests_condition_assertion_expected_ ## STEM ## _t)); \
									\
    /* Initialise the basic condition fields. */			\
    cce_condition_init((cce_condition_t *)C, &cctests_descriptor_assertion_expected_ ## STEM .descriptor); \
    cctests_condition_init_assertion_expected_ ## STEM(C, expected, result, CCTESTS_CONDITION_COMMON_CALL_ARGS); \
    return (cce_condition_t const *)C;					\
  }									\
									\
  bool									\
  cctests_condition_is_assertion_expected_ ## STEM (cce_condition_t const * C) \
  {									\
    return cce_condition_is(C, &(cctests_descriptor_assertion_expected_ ## STEM .descriptor)); \
  }									\
									\
  void									\
  cce_descriptor_set_parent_to(cctests_descriptor_assertion_expected_ ## STEM ## _t) (cce_descriptor_t * const D) \
  {									\
    D->parent = &cctests_descriptor_assertion_expected_ ## STEM .descriptor;	\
  }

/* ------------------------------------------------------------------ */

DECLARE_CONDITION_ASSERTION_EXPECTED(char,	signed char,	"c",)
DECLARE_CONDITION_ASSERTION_EXPECTED(uchar,	unsigned char,	"c",)

DECLARE_CONDITION_ASSERTION_EXPECTED(int,	signed int,	"d",)
DECLARE_CONDITION_ASSERTION_EXPECTED(uint,	unsigned int,	"u",)

DECLARE_CONDITION_ASSERTION_EXPECTED(short,	signed short,	"d",)
DECLARE_CONDITION_ASSERTION_EXPECTED(ushort,	unsigned short,	"u",)

DECLARE_CONDITION_ASSERTION_EXPECTED(long,	signed long,	"ld",)
DECLARE_CONDITION_ASSERTION_EXPECTED(ulong,	unsigned long,	"lu",)

DECLARE_CONDITION_ASSERTION_EXPECTED(llong,	signed long long,	"lld",)
DECLARE_CONDITION_ASSERTION_EXPECTED(ullong,	unsigned long long,	"llu",)

DECLARE_CONDITION_ASSERTION_EXPECTED(int8,	int8_t,		PRId8,)
DECLARE_CONDITION_ASSERTION_EXPECTED(int16,	int16_t,	PRId16,)
DECLARE_CONDITION_ASSERTION_EXPECTED(int32,	int32_t,	PRId32,)
DECLARE_CONDITION_ASSERTION_EXPECTED(int64,	int64_t,	PRId64,)

DECLARE_CONDITION_ASSERTION_EXPECTED(uint8,	uint8_t,	PRIu8,)
DECLARE_CONDITION_ASSERTION_EXPECTED(uint16,	uint16_t,	PRIu16,)
DECLARE_CONDITION_ASSERTION_EXPECTED(uint32,	uint32_t,	PRIu32,)
DECLARE_CONDITION_ASSERTION_EXPECTED(uint64,	uint64_t,	PRIu64,)

DECLARE_CONDITION_ASSERTION_EXPECTED(float,	float,		"f", (double))
DECLARE_CONDITION_ASSERTION_EXPECTED(double,	double,		"f",)

#if (4 == CCTESTS_SIZEOF_SIZE_T)
DECLARE_CONDITION_ASSERTION_EXPECTED(size,	size_t,		PRIu32,)
#else
DECLARE_CONDITION_ASSERTION_EXPECTED(size,	size_t,		PRIu64,)
#endif

#if (4 == CCTESTS_SIZEOF_SSIZE_T)
DECLARE_CONDITION_ASSERTION_EXPECTED(ssize,	ssize_t,	PRId32,)
#else
DECLARE_CONDITION_ASSERTION_EXPECTED(ssize,	ssize_t,	PRId64,)
#endif

DECLARE_CONDITION_ASSERTION_EXPECTED(pointer,	void *,		"p",)
DECLARE_CONDITION_ASSERTION_EXPECTED(ptrdiff,	ptrdiff_t,	PRIdPTR,)
DECLARE_CONDITION_ASSERTION_EXPECTED(intptr,	intptr_t,	PRIdPTR,)
DECLARE_CONDITION_ASSERTION_EXPECTED(uintptr,	uintptr_t,	PRIuPTR,)


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: failed assertion, expected ASCIIZ.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_assertion_expected_asciiz;
static cce_condition_delete_fun_t		cctests_condition_delete_assertion_expected_asciiz;
static cce_condition_final_fun_t		cctests_condition_final_assertion_expected_asciiz;
static cctests_condition_print_assertion_fun_t	cctests_condition_print_assertion_expected_asciiz_fun;

static cctests_descriptor_assertion_expected_asciiz_t const cctests_descriptor_assertion_expected_asciiz = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_assertion_expected_value),
  .descriptor.delete		= cctests_condition_delete_assertion_expected_asciiz,
  .descriptor.final		= cctests_condition_final_assertion_expected_asciiz,
  .descriptor.static_message	= cctests_condition_static_message_assertion_expected_asciiz,
  .print			= cctests_condition_print_assertion_expected_asciiz_fun
};

/* ------------------------------------------------------------------ */

void
cctests_condition_delete_assertion_expected_asciiz (cce_condition_t * C)
{
  free(C);
}

void
cctests_condition_final_assertion_expected_asciiz (cce_condition_t * C)
{
  CCLIB_PC(cctests_condition_assertion_expected_asciiz_t, K, C);

  free(K->expected);
  free(K->result);
}

char const *
cctests_condition_static_message_assertion_expected_asciiz (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests assertion failure, expected ASCIIZ value";
}

void
cctests_condition_print_assertion_expected_asciiz_fun (cce_condition_t const * C)
{
  cctests_condition_print_assertion_fun(C);
  {
    CCLIB_PC(cctests_condition_assertion_expected_asciiz_t, K, C);

    fprintf(cctests_log_stream, "   expected:     '%s'\n", K->expected);
    fprintf(cctests_log_stream, "   result:       '%s'\n", K->result);
  }
}

void
cctests_condition_init_assertion_expected_asciiz (cce_destination_t L,
						  cctests_condition_assertion_expected_asciiz_t * C,
						  char const * const expected, char const * const result,
						  CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS)
{
  /* Initialise the parent type. */
  cctests_condition_init_assertion_expected_value(&(C->assertion_expected_value), CCTESTS_CONDITION_COMMON_CALL_ARGS);

  /* Initialise the fields of this type. */
  {
    size_t	expected_len	= strlen(expected);

    C->expected	= cce_sys_malloc(L, 1+expected_len);
    strncpy(C->expected, expected, 1+expected_len);
  }
  {
    size_t	result_len	= strlen(result);

    C->result	= cce_sys_malloc(L, 1+result_len);
    strncpy(C->result, result, 1+result_len);
  }
}

cce_condition_t const *
cctests_condition_new_assertion_expected_asciiz (cce_destination_t L,
						 char const * const expected, char const * const result,
						 CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS)
{
  cctests_condition_assertion_expected_asciiz_t *	C =
    cce_sys_malloc(L, sizeof(cctests_condition_assertion_expected_asciiz_t));

  /* Initialise the basic condition fields. */
  cce_condition_init((cce_condition_t *)C, cce_descriptor_pointer(cctests_descriptor_assertion_expected_asciiz));
  cctests_condition_init_assertion_expected_asciiz(L, C, expected, result, CCTESTS_CONDITION_COMMON_CALL_ARGS);
  return (cce_condition_t const *)C;
}

/* ------------------------------------------------------------------ */

bool
cctests_condition_is_assertion_expected_asciiz (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_assertion_expected_asciiz.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_assertion_expected_asciiz_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_assertion_expected_asciiz);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: failed assertion, expected ASCII.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_assertion_expected_ascii;
static cce_condition_delete_fun_t		cctests_condition_delete_assertion_expected_ascii;
static cce_condition_final_fun_t		cctests_condition_final_assertion_expected_ascii;
static cctests_condition_print_assertion_fun_t	cctests_condition_print_assertion_expected_ascii_fun;

static cctests_descriptor_assertion_expected_ascii_t const cctests_descriptor_assertion_expected_ascii = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_assertion_expected_value),
  .descriptor.delete		= cctests_condition_delete_assertion_expected_ascii,
  .descriptor.final		= cctests_condition_final_assertion_expected_ascii,
  .descriptor.static_message	= cctests_condition_static_message_assertion_expected_ascii,
  .print			= cctests_condition_print_assertion_expected_ascii_fun
};

/* ------------------------------------------------------------------ */

void
cctests_condition_delete_assertion_expected_ascii (cce_condition_t * C)
{
  free(C);
}

void
cctests_condition_final_assertion_expected_ascii (cce_condition_t * C)
{
  CCLIB_PC(cctests_condition_assertion_expected_ascii_t, K, C);

  free(K->expected);
  free(K->result);
}

char const *
cctests_condition_static_message_assertion_expected_ascii (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests assertion failure, expected ASCII value";
}

void
cctests_condition_print_assertion_expected_ascii_fun (cce_condition_t const * C)
{
  cctests_condition_print_assertion_fun(C);
  {
    CCLIB_PC(cctests_condition_assertion_expected_ascii_t, K, C);
    size_t	expected_len = strlen(K->expected);

    fprintf(cctests_log_stream, "   expected:     '%s' (len=%" PRIuSIZE ")\n", K->expected, expected_len);
    fprintf(cctests_log_stream, "   result:       '");
    fwrite(K->result, sizeof(char), K->result_len, cctests_log_stream);
    fprintf(cctests_log_stream, "' (len=%" PRIuSIZE ")\n", K->result_len);
  }
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_assertion_expected_ascii (cce_destination_t L,
						 cctests_condition_assertion_expected_ascii_t * C,
						 char const * const expected, char const * const result, size_t result_len,
						 CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS)
{
  /* Initialise the parent type. */
  cctests_condition_init_assertion_expected_value(&(C->assertion_expected_value), CCTESTS_CONDITION_COMMON_CALL_ARGS);

  /* Initialise the fields of this type. */
  {
    size_t	expected_len	= strlen(expected);

    C->expected	= cce_sys_malloc(L, 1+expected_len);
    strncpy(C->expected, expected, 1+expected_len);
  }
  {
    C->result	= cce_sys_malloc(L, result_len);
    strncpy(C->result, result, result_len);
    C->result_len = result_len;
  }
}

cce_condition_t const *
cctests_condition_new_assertion_expected_ascii (cce_destination_t L,
						char const * const expected, char const * const result, size_t result_len,
						CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS)
{
  cctests_condition_assertion_expected_ascii_t *	C =
    cce_sys_malloc(L, sizeof(cctests_condition_assertion_expected_ascii_t));

  /* Initialise the basic condition fields. */
  cce_condition_init((cce_condition_t *)C, cce_descriptor_pointer(cctests_descriptor_assertion_expected_ascii));
  cctests_condition_init_assertion_expected_ascii(L, C, expected, result, result_len, CCTESTS_CONDITION_COMMON_CALL_ARGS);
  return (cce_condition_t const *)C;
}

/* ------------------------------------------------------------------ */

bool
cctests_condition_is_assertion_expected_ascii (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_assertion_expected_ascii.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_assertion_expected_ascii_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_assertion_expected_ascii);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: unreachable code.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_unreachable;
static cce_condition_delete_fun_t		cctests_condition_delete_unreachable;

static cctests_descriptor_unreachable_t const cctests_descriptor_unreachable = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_failure),
  .descriptor.delete		= cctests_condition_delete_unreachable,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_unreachable
};

/* ------------------------------------------------------------------ */

void
cctests_condition_delete_unreachable (cce_condition_t * C)
{
  free(C);
}

char const *
cctests_condition_static_message_unreachable (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests unreachable code was executed";
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_unreachable (cctests_condition_unreachable_t * C,
				    char const * const filename,
				    char const * const funcname,
				    int const linenum)
{
  /* Initialise the parent type. */
  cctests_condition_init_failure(&(C->failure));

  /* Initialise the fields of this type. */
  C->filename			= filename;
  C->funcname			= funcname;
  C->linenum			= linenum;
}

cce_condition_t const *
cctests_condition_new_unreachable (cce_destination_t L,
				   char const * const filename, char const * const funcname, int const linenum)
{
  cctests_condition_unreachable_t *	C = cce_sys_malloc(L, sizeof(cctests_condition_unreachable_t));

  /* Initialise the basic condition fields. */
  cce_condition_init((cce_condition_t *)C, cce_descriptor_pointer(cctests_descriptor_unreachable));

  cctests_condition_init_unreachable(C, filename, funcname, linenum);

  return (cce_condition_t const *)C;
}

bool
cctests_condition_is_unreachable (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_unreachable.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_unreachable_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_unreachable);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: signal.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_signal;

static cctests_descriptor_signal_t const cctests_descriptor_signal = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_base),
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_signal
};

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_signal_t const cctests_condition_signal = {
  .base.root.condition.descriptor	= cce_descriptor_pointer(cctests_descriptor_signal)
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_signal (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests exception signal";
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_signal (cctests_condition_signal_t * C)
{
  cctests_condition_init_base(&(C->base));
}

cce_condition_t const *
cctests_condition_new_signal (void)
{
  return (cce_condition_t *)&cctests_condition_signal;
}

bool
cctests_condition_is_signal (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_signal.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_signal_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_signal);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: signal one.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_signal_1;

static cctests_descriptor_signal_1_t const cctests_descriptor_signal_1 = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_signal),
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_signal_1
};

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_signal_1_t const cctests_condition_signal_1 = {
  .signal.base.root.condition.descriptor	= cce_descriptor_pointer(cctests_descriptor_signal_1)
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_signal_1 (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests exception signal 1";
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_signal_1 (cctests_condition_signal_1_t * C)
{
  cctests_condition_init_signal(&(C->signal));
}

cce_condition_t const *
cctests_condition_new_signal_1 (void)
{
  return (cce_condition_t *)&cctests_condition_signal_1;
}

bool
cctests_condition_is_signal_1 (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_signal_1.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_signal_1_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_signal_1);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: signal two.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_signal_2;

static cctests_descriptor_signal_2_t const cctests_descriptor_signal_2 = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_signal),
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_signal_2
};

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_signal_2_t const cctests_condition_signal_2 = {
  .signal.base.root.condition.descriptor	= cce_descriptor_pointer(cctests_descriptor_signal_2)
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_signal_2 (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests exception signal 2";
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_signal_2 (cctests_condition_signal_2_t * C)
{
  cctests_condition_init_signal(&(C->signal));
}

cce_condition_t const *
cctests_condition_new_signal_2 (void)
{
  return (cce_condition_t *)&cctests_condition_signal_2;
}

bool
cctests_condition_is_signal_2 (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_signal_2.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_signal_2_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_signal_2);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: signal three.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_signal_3;

static cctests_descriptor_signal_3_t const cctests_descriptor_signal_3 = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_signal),
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_signal_3
};

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_signal_3_t const cctests_condition_signal_3 = {
  .signal.base.root.condition.descriptor	= cce_descriptor_pointer(cctests_descriptor_signal_3)
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_signal_3 (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests exception signal 3";
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_signal_3 (cctests_condition_signal_3_t * C)
{
  cctests_condition_init_signal(&(C->signal));
}

cce_condition_t const *
cctests_condition_new_signal_3 (void)
{
  return (cce_condition_t *)&cctests_condition_signal_3;
}

bool
cctests_condition_is_signal_3 (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_signal_3.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_signal_3_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_signal_3);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: regular expression error.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_regex_error;

static cctests_descriptor_regex_error_t cctests_descriptor_regex_error = {
  /* This field is set by the initialisation function to the pointer:
   *
   *	&(cce_descriptor_runtime_error.descriptor)
   */
  .descriptor.parent		= NULL,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_regex_error
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_regex_error (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests regular expression error";
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_regex_error (cctests_condition_regex_error_t * C, int errcode)
{
  cce_condition_init_runtime_error(&(C->runtime_error));
  C->errcode = errcode;
  /* For a compilation error we have  no valid "regex_t" argument, so we
     set it to NULL as described in the specification. */
  regerror(errcode, NULL, C->error_message, 1024);
}

cce_condition_t const *
cctests_condition_new_regex_error (cce_destination_t L, int errcode)
{
  cctests_condition_regex_error_t *	C = cce_sys_malloc(L, sizeof(cctests_condition_regex_error_t));

  cce_condition_init((cce_condition_t *)C, cce_descriptor_pointer(cctests_descriptor_regex_error));
  cctests_condition_init_regex_error(C, errcode);
  return (cce_condition_t *)C;
}

bool
cctests_condition_is_regex_error (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_regex_error.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_regex_error_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_regex_error);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: regular expression compilation error.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_regex_compilation_error;

static cctests_descriptor_regex_compilation_error_t const cctests_descriptor_regex_compilation_error = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_regex_error),
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_regex_compilation_error
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_regex_compilation_error (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests regular expression compilation error";
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_regex_compilation_error (cctests_condition_regex_compilation_error_t * C, int errcode)
{
  cctests_condition_init_regex_error(&(C->regex_error), errcode);
}

cce_condition_t const *
cctests_condition_new_regex_compilation_error (cce_destination_t L, int errcode)
{
  cctests_condition_regex_compilation_error_t *	C = \
    cce_sys_malloc(L, sizeof(cctests_condition_regex_compilation_error_t));

  cce_condition_init((cce_condition_t *)C, cce_descriptor_pointer(cctests_descriptor_regex_compilation_error));
  cctests_condition_init_regex_compilation_error(C, errcode);
  return (cce_condition_t *)C;
}

bool
cctests_condition_is_regex_compilation_error (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_regex_compilation_error.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_regex_compilation_error_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_regex_compilation_error);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: child failure.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_child_failure;

static cctests_descriptor_child_failure_t const cctests_descriptor_child_failure = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_failure),
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_child_failure
};

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_child_failure_t const cctests_condition_child_failure = {
  .failure.base.root.condition.descriptor	= cce_descriptor_pointer(cctests_descriptor_child_failure)
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_child_failure (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests exception child failure";
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_child_failure (cctests_condition_child_failure_t * C)
{
  cctests_condition_init_failure(&(C->failure));
}

cce_condition_t const *
cctests_condition_new_child_failure (void)
{
  return (cce_condition_t *)&cctests_condition_child_failure;
}

bool
cctests_condition_is_child_failure (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_child_failure.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_child_failure_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_child_failure);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: child failure, abnormal termination.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_child_abnormal_termination;

static cctests_descriptor_child_abnormal_termination_t const cctests_descriptor_child_abnormal_termination = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_child_failure),
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_child_abnormal_termination
};

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_child_abnormal_termination_t const cctests_condition_child_abnormal_termination = {
  .child_failure.failure.base.root.condition.descriptor	= cce_descriptor_pointer(cctests_descriptor_child_abnormal_termination)
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_child_abnormal_termination (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests exception child failure: abnormal termination";
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_child_abnormal_termination (cctests_condition_child_abnormal_termination_t * C)
{
  cctests_condition_init_child_failure(&(C->child_failure));
}

cce_condition_t const *
cctests_condition_new_child_abnormal_termination (void)
{
  return (cce_condition_t *)&cctests_condition_child_abnormal_termination;
}

bool
cctests_condition_is_child_abnormal_termination (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_child_abnormal_termination.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_child_abnormal_termination_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_child_abnormal_termination);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: child failure, failure exit status.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_child_failure_exit_status;

static cctests_descriptor_child_failure_exit_status_t const cctests_descriptor_child_failure_exit_status = {
  .descriptor.parent		= cce_descriptor_pointer(cctests_descriptor_child_failure),
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_child_failure_exit_status
};

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_child_failure_exit_status_t const cctests_condition_child_failure_exit_status = {
  .child_failure.failure.base.root.condition.descriptor	= cce_descriptor_pointer(cctests_descriptor_child_failure_exit_status)
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_child_failure_exit_status (cce_condition_t const * C CCLIB_UNUSED)
{
  return "CCTests exception child failure: failure exit status";
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_child_failure_exit_status (cctests_condition_child_failure_exit_status_t * C)
{
  cctests_condition_init_child_failure(&(C->child_failure));
}

cce_condition_t const *
cctests_condition_new_child_failure_exit_status (void)
{
  return (cce_condition_t *)&cctests_condition_child_failure_exit_status;
}

bool
cctests_condition_is_child_failure_exit_status (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cctests_descriptor_child_failure_exit_status.descriptor));
}

void
cce_descriptor_set_parent_to(cctests_descriptor_child_failure_exit_status_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cctests_descriptor_child_failure_exit_status);
}


/** --------------------------------------------------------------------
 ** Module initialisation.
 ** ----------------------------------------------------------------- */

void
cctests_conditions_module_initialisation (void)
{
  cce_descriptor_set_parent_to(cce_descriptor_root_t)(cce_descriptor_pointer(cctests_descriptor_base));
  cce_descriptor_set_parent_to(cce_descriptor_runtime_error_t)(cce_descriptor_pointer(cctests_descriptor_regex_error));
}

/* end of file */
