/*
  Part of: CCTests
  Contents: condition objects
  Date: Nov 28, 2017

  Abstract



  Copyright (C) 2017, 2018 Marco Maggi <marco.maggi-ipsu@poste.it>

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
 ** Base exceptional condition descriptor.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_base;

static cctests_descriptor_base_t cctests_descriptor_base_stru = {
  /* This  "parent" field  is  set below  by  the module  initialisation
     function. */
  .descriptor.parent		= NULL,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_base
};

cctests_descriptor_base_t const * const cctests_descriptor_base_ptr = &cctests_descriptor_base_stru;

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_base (cce_condition_t const * C CCE_UNUSED)
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
  return cce_is_condition(C, &(cctests_descriptor_base_ptr->descriptor));
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: test success.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_success;

static cctests_descriptor_success_t const cctests_descriptor_success_stru = {
  .descriptor.parent		= &cctests_descriptor_base_stru.descriptor,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_success
};

cctests_descriptor_success_t const * const cctests_descriptor_success_ptr = &cctests_descriptor_success_stru;

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_success_t const cctests_condition_success_stru = {
  .base.root.condition.descriptor	= &cctests_descriptor_success_stru.descriptor
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_success (cce_condition_t const * C CCTESTS_UNUSED)
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
  return (cce_condition_t *)&cctests_condition_success_stru;
}

bool
cctests_condition_is_success (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_success_ptr->descriptor));
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: test skipped.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_skipped;

static cctests_descriptor_skipped_t const cctests_descriptor_skipped_stru = {
  .descriptor.parent		= &cctests_descriptor_base_stru.descriptor,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_skipped
};

cctests_descriptor_skipped_t const * const cctests_descriptor_skipped_ptr = &cctests_descriptor_skipped_stru;

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_skipped_t const cctests_condition_skipped_stru = {
  .base.root.condition.descriptor	= &cctests_descriptor_skipped_stru.descriptor
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_skipped (cce_condition_t const * C CCTESTS_UNUSED)
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
  return (cce_condition_t *)&cctests_condition_skipped_stru;
}

bool
cctests_condition_is_skipped (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_skipped_ptr->descriptor));
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: test failure.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_failure;

static cctests_descriptor_failure_t const cctests_descriptor_failure_stru = {
  .descriptor.parent		= &cctests_descriptor_base_stru.descriptor,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_failure
};

cctests_descriptor_failure_t const * const cctests_descriptor_failure_ptr = &cctests_descriptor_failure_stru;

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_failure_t const cctests_condition_failure_stru = {
  .base.root.condition.descriptor	= &cctests_descriptor_failure_stru.descriptor
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_failure (cce_condition_t const * C CCTESTS_UNUSED)
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
  return (cce_condition_t *)&cctests_condition_failure_stru;
}

bool
cctests_condition_is_failure (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_failure_ptr->descriptor));
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: expected failure.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_expected_failure;

static cctests_descriptor_expected_failure_t const cctests_descriptor_expected_failure_stru = {
  .descriptor.parent		= &cctests_descriptor_failure_stru.descriptor,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_expected_failure
};

cctests_descriptor_expected_failure_t const * const cctests_descriptor_expected_failure_ptr = &cctests_descriptor_expected_failure_stru;

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_expected_failure_t const cctests_condition_expected_failure_stru = {
  .failure.base.root.condition.descriptor	= &cctests_descriptor_expected_failure_stru.descriptor
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_expected_failure (cce_condition_t const * C CCTESTS_UNUSED)
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
  return (cce_condition_t *)&cctests_condition_expected_failure_stru;
}

bool
cctests_condition_is_expected_failure (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_expected_failure_ptr->descriptor));
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: failed assertion.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_assertion;
static cce_condition_delete_fun_t		cctests_condition_delete_assertion;
static cctests_condition_print_assertion_fun_t	cctests_condition_print_assertion_fun;

static cctests_descriptor_assertion_t const cctests_descriptor_assertion_stru = {
  .descriptor.parent		= &cctests_descriptor_failure_stru.descriptor,
  .descriptor.delete		= cctests_condition_delete_assertion,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_assertion,
  .print			= cctests_condition_print_assertion_fun
};

cctests_descriptor_assertion_t const * const cctests_descriptor_assertion_ptr = &cctests_descriptor_assertion_stru;

/* ------------------------------------------------------------------ */

void
cctests_condition_delete_assertion (cce_condition_t * C)
{
  free(C);
}

char const *
cctests_condition_static_message_assertion (cce_condition_t const * C CCTESTS_UNUSED)
{
  return "CCTests assertion failure";
}

void
cctests_condition_print_assertion_fun (cce_condition_t const * C)
{
  CCTESTS_PC(cctests_condition_assertion_t, K, C);

  fprintf(cctests_log_stream, "CCTests: \033[35;1massertion failure\033[0m in test function %s: %s: %s: line %d\n\tcall:     %s\n",
	  cctests_test_func_name,
	  K->filename, K->funcname, K->linenum, K->expr);
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_assertion (cctests_condition_assertion_t * C,
				  char const * const expr,
				  char const * const filename,
				  char const * const funcname,
				  int const linenum)
{
  /* Initialise the parent type. */
  cctests_condition_init_failure(&(C->failure));

  /* Initialise the fields of this type. */
  C->expr			= expr;
  C->filename			= filename;
  C->funcname			= funcname;
  C->linenum			= linenum;
}

cce_condition_t const *
cctests_condition_new_assertion (cce_destination_t L,
				 char const * const expr, char const * const filename, char const * const funcname, int const linenum)
{
  cctests_condition_assertion_t *	C = cce_sys_malloc(L, sizeof(cctests_condition_assertion_t));

  /* Initialise the basic condition fields. */
  cce_condition_init((cce_condition_t *)C, &cctests_descriptor_assertion_stru.descriptor);

  cctests_condition_init_assertion(C, expr, filename, funcname, linenum);

  return (cce_condition_t const *)C;
}

bool
cctests_condition_is_assertion (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_assertion_ptr->descriptor));
}

void
cctests_condition_print_assertion (cce_condition_t const * C)
{
  CCTESTS_PC(cctests_descriptor_assertion_t, D, C->descriptor);

  D->print(C);
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: failed assertion, expected value.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_assertion_expected_value;
static cce_condition_delete_fun_t		cctests_condition_delete_assertion_expected_value;
static cctests_condition_print_assertion_fun_t	cctests_condition_print_assertion_expected_value_fun;

static cctests_descriptor_assertion_expected_value_t const cctests_descriptor_assertion_expected_value_stru = {
  .descriptor.parent		= &cctests_descriptor_assertion_stru.descriptor,
  .descriptor.delete		= cctests_condition_delete_assertion_expected_value,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_assertion_expected_value,
  .print			= cctests_condition_print_assertion_expected_value_fun
};

cctests_descriptor_assertion_expected_value_t const * const cctests_descriptor_assertion_expected_value_ptr =
  &cctests_descriptor_assertion_expected_value_stru;

/* ------------------------------------------------------------------ */

void
cctests_condition_delete_assertion_expected_value (cce_condition_t * C)
{
  free(C);
}

char const *
cctests_condition_static_message_assertion_expected_value (cce_condition_t const * C CCTESTS_UNUSED)
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
						 char const * const expr,
						 char const * const filename,
						 char const * const funcname,
						 int const linenum)
{
  /* Initialise the parent type. */
  cctests_condition_init_assertion(&(C->assertion), expr, filename, funcname, linenum);
}

bool
cctests_condition_is_assertion_expected_value (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_assertion_expected_value_ptr->descriptor));
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: failed assertion, expected immediate value.
 ** ----------------------------------------------------------------- */

#define DECLARE_CONDITION_ASSERTION_EXPECTED(STEM, TYPE, PRINTF_FORMAT)		\
  static cce_condition_static_message_fun_t	cctests_condition_static_message_assertion_expected_ ## STEM; \
  static cce_condition_delete_fun_t		cctests_condition_delete_assertion_expected_ ## STEM; \
  static cctests_condition_print_assertion_fun_t cctests_condition_print_assertion_expected_ ## STEM ## _fun; \
									\
  static cctests_descriptor_assertion_expected_ ## STEM ## _t const cctests_descriptor_assertion_expected_ ## STEM ## _stru = { \
    .descriptor.parent		= &cctests_descriptor_assertion_expected_value_stru.descriptor, \
    .descriptor.delete		= cctests_condition_delete_assertion_expected_ ## STEM, \
    .descriptor.final		= NULL,					\
    .descriptor.static_message	= cctests_condition_static_message_assertion_expected_ ## STEM, \
    .print			= cctests_condition_print_assertion_expected_ ## STEM ## _fun \
  };									\
									\
  cctests_descriptor_assertion_expected_ ## STEM ## _t const * const cctests_descriptor_assertion_expected_ ## STEM ## _ptr = \
    &cctests_descriptor_assertion_expected_ ## STEM ## _stru;		\
									\
  void									\
  cctests_condition_delete_assertion_expected_ ## STEM (cce_condition_t * C) \
  {									\
    free(C);								\
  }									\
									\
  char const *								\
  cctests_condition_static_message_assertion_expected_ ## STEM (cce_condition_t const * C CCTESTS_UNUSED) \
  {									\
    return "CCTests assertion failure, expected " #TYPE " value";	\
  }									\
									\
  void									\
  cctests_condition_print_assertion_expected_ ## STEM ## _fun (cce_condition_t const * C) \
  {									\
    cctests_condition_print_assertion_fun(C);				\
    {									\
      CCTESTS_PC(cctests_condition_assertion_expected_ ## STEM ## _t, K, C); \
									\
      fprintf(cctests_log_stream, "\texpected: ");			\
      fprintf(cctests_log_stream, "%" PRINTF_FORMAT, K->expected);	\
      fprintf(cctests_log_stream, "\n");				\
      fprintf(cctests_log_stream, "\tresult:   ");			\
      fprintf(cctests_log_stream, "%" PRINTF_FORMAT, K->result);	\
      fprintf(cctests_log_stream, "\n");				\
    }									\
  }									\
									\
  void									\
  cctests_condition_init_assertion_expected_ ## STEM (cctests_condition_assertion_expected_ ## STEM ## _t * C, \
						      char const * const expr, \
						      char const * const filename, \
						      char const * const funcname, \
						      int const linenum, \
						      TYPE expected, TYPE result) \
  {									\
    /* Initialise the parent type. */					\
    cctests_condition_init_assertion_expected_value(&(C->assertion_expected_value), expr, filename, funcname, linenum); \
									\
    /* Initialise the fields of this type. */				\
    C->expected			= expected;				\
    C->result			= result;				\
  }									\
									\
  cce_condition_t const *						\
  cctests_condition_new_assertion_expected_ ## STEM (cce_destination_t L, \
						     char const * const expr, \
						     char const * const filename, \
						     char const * const funcname, \
						     int const linenum, \
						     TYPE expected, TYPE result) \
  {									\
    cctests_condition_assertion_expected_ ## STEM ## _t *	C =	\
      cce_sys_malloc(L, sizeof(cctests_condition_assertion_expected_ ## STEM ## _t)); \
									\
    /* Initialise the basic condition fields. */			\
    cce_condition_init((cce_condition_t *)C, &cctests_descriptor_assertion_expected_ ## STEM ## _stru.descriptor); \
									\
    cctests_condition_init_assertion_expected_ ## STEM(C, expr, filename, funcname, linenum, expected, result); \
									\
    return (cce_condition_t const *)C;					\
  }									\
									\
  bool									\
  cctests_condition_is_assertion_expected_ ## STEM (cce_condition_t const * C) \
  {									\
    return cce_is_condition(C, &(cctests_descriptor_assertion_expected_ ## STEM ## _ptr->descriptor)); \
  }

/* ------------------------------------------------------------------ */

DECLARE_CONDITION_ASSERTION_EXPECTED(char,	signed char,	"c")
DECLARE_CONDITION_ASSERTION_EXPECTED(uchar,	unsigned char,	"c")

DECLARE_CONDITION_ASSERTION_EXPECTED(int,	signed int,	"d")
DECLARE_CONDITION_ASSERTION_EXPECTED(uint,	unsigned int,	"u")

DECLARE_CONDITION_ASSERTION_EXPECTED(short,	signed short,	"d")
DECLARE_CONDITION_ASSERTION_EXPECTED(ushort,	unsigned short,	"u")

DECLARE_CONDITION_ASSERTION_EXPECTED(long,	signed long,	"ld")
DECLARE_CONDITION_ASSERTION_EXPECTED(ulong,	unsigned long,	"lu")

DECLARE_CONDITION_ASSERTION_EXPECTED(llong,	signed long long,	"lld")
DECLARE_CONDITION_ASSERTION_EXPECTED(ullong,	unsigned long long,	"llu")

DECLARE_CONDITION_ASSERTION_EXPECTED(int8,	int8_t,		PRId8)
DECLARE_CONDITION_ASSERTION_EXPECTED(int16,	int16_t,	PRId16)
DECLARE_CONDITION_ASSERTION_EXPECTED(int32,	int32_t,	PRId32)
DECLARE_CONDITION_ASSERTION_EXPECTED(int64,	int64_t,	PRId64)

DECLARE_CONDITION_ASSERTION_EXPECTED(uint8,	uint8_t,	PRIu8)
DECLARE_CONDITION_ASSERTION_EXPECTED(uint16,	uint16_t,	PRIu16)
DECLARE_CONDITION_ASSERTION_EXPECTED(uint32,	uint32_t,	PRIu32)
DECLARE_CONDITION_ASSERTION_EXPECTED(uint64,	uint64_t,	PRIu64)

DECLARE_CONDITION_ASSERTION_EXPECTED(float,	float,		"f")
DECLARE_CONDITION_ASSERTION_EXPECTED(double,	double,		"f")

#if (4 == CCTESTS_SIZEOF_SIZE_T)
DECLARE_CONDITION_ASSERTION_EXPECTED(size,	size_t,		PRIu32)
#else
DECLARE_CONDITION_ASSERTION_EXPECTED(size,	size_t,		PRIu64)
#endif

#if (4 == CCTESTS_SIZEOF_SSIZE_T)
DECLARE_CONDITION_ASSERTION_EXPECTED(ssize,	ssize_t,	PRId32)
#else
DECLARE_CONDITION_ASSERTION_EXPECTED(ssize,	ssize_t,	PRId64)
#endif

DECLARE_CONDITION_ASSERTION_EXPECTED(pointer,	void *,		"p")
DECLARE_CONDITION_ASSERTION_EXPECTED(ptrdiff,	ptrdiff_t,	PRIdPTR)
DECLARE_CONDITION_ASSERTION_EXPECTED(intptr,	intptr_t,	PRIdPTR)
DECLARE_CONDITION_ASSERTION_EXPECTED(uintptr,	uintptr_t,	PRIuPTR)


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: failed assertion, expected ASCIIZ.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_assertion_expected_asciiz;
static cce_condition_delete_fun_t		cctests_condition_delete_assertion_expected_asciiz;
static cce_condition_final_fun_t		cctests_condition_final_assertion_expected_asciiz;
static cctests_condition_print_assertion_fun_t	cctests_condition_print_assertion_expected_asciiz_fun;

static cctests_descriptor_assertion_expected_asciiz_t const cctests_descriptor_assertion_expected_asciiz_stru = {
  .descriptor.parent		= &cctests_descriptor_assertion_expected_value_stru.descriptor,
  .descriptor.delete		= cctests_condition_delete_assertion_expected_asciiz,
  .descriptor.final		= cctests_condition_final_assertion_expected_asciiz,
  .descriptor.static_message	= cctests_condition_static_message_assertion_expected_asciiz,
  .print			= cctests_condition_print_assertion_expected_asciiz_fun
};

cctests_descriptor_assertion_expected_asciiz_t const * const cctests_descriptor_assertion_expected_asciiz_ptr =
  &cctests_descriptor_assertion_expected_asciiz_stru;

/* ------------------------------------------------------------------ */

void
cctests_condition_delete_assertion_expected_asciiz (cce_condition_t * C)
{
  free(C);
}

void
cctests_condition_final_assertion_expected_asciiz (cce_condition_t * C)
{
  CCTESTS_PC(cctests_condition_assertion_expected_asciiz_t, K, C);

  free(K->expected);
  free(K->result);
}

char const *
cctests_condition_static_message_assertion_expected_asciiz (cce_condition_t const * C CCTESTS_UNUSED)
{
  return "CCTests assertion failure, expected ASCIIZ value";
}

void
cctests_condition_print_assertion_expected_asciiz_fun (cce_condition_t const * C)
{
  cctests_condition_print_assertion_fun(C);
  {
    CCTESTS_PC(cctests_condition_assertion_expected_asciiz_t, K, C);

    fprintf(cctests_log_stream, "\texpected: '%s'\n", K->expected);
    fprintf(cctests_log_stream, "\tresult:   '%s'\n", K->result);
  }
}

void
cctests_condition_init_assertion_expected_asciiz (cce_destination_t L,
						  cctests_condition_assertion_expected_asciiz_t * C,
						  char const * const expr,
						  char const * const filename,
						  char const * const funcname,
						  int const linenum,
						  char const * expected, char const * result)
{
  /* Initialise the parent type. */
  cctests_condition_init_assertion_expected_value(&(C->assertion_expected_value), expr, filename, funcname, linenum);

  /* Initialise the fields of this type. */
  {
    size_t	expected_len	= strlen(expected);

    C->expected	= cce_sys_malloc(L, 1+expected_len);
    strncpy(C->expected, expected, expected_len);
    C->expected[expected_len] = '\0';
  }
  {
    size_t	result_len	= strlen(result);

    C->result	= cce_sys_malloc(L, 1+result_len);
    strncpy(C->result, result, result_len);
    C->result[result_len] = '\0';
  }
}

cce_condition_t const *
cctests_condition_new_assertion_expected_asciiz (cce_destination_t L,
						 char const * const expr,
						 char const * const filename,
						 char const * const funcname,
						 int const linenum,
						 char const * expected, char const * result)
{
  cctests_condition_assertion_expected_asciiz_t *	C =
    cce_sys_malloc(L, sizeof(cctests_condition_assertion_expected_asciiz_t));

  /* Initialise the basic condition fields. */
  cce_condition_init((cce_condition_t *)C, &cctests_descriptor_assertion_expected_asciiz_stru.descriptor);

  cctests_condition_init_assertion_expected_asciiz(L, C, expr, filename, funcname, linenum, expected, result);

  return (cce_condition_t const *)C;
}

bool
cctests_condition_is_assertion_expected_asciiz (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_assertion_expected_asciiz_ptr->descriptor));
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: failed assertion, expected ASCII.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_assertion_expected_ascii;
static cce_condition_delete_fun_t		cctests_condition_delete_assertion_expected_ascii;
static cce_condition_final_fun_t		cctests_condition_final_assertion_expected_ascii;
static cctests_condition_print_assertion_fun_t	cctests_condition_print_assertion_expected_ascii_fun;

static cctests_descriptor_assertion_expected_ascii_t const cctests_descriptor_assertion_expected_ascii_stru = {
  .descriptor.parent		= &cctests_descriptor_assertion_expected_value_stru.descriptor,
  .descriptor.delete		= cctests_condition_delete_assertion_expected_ascii,
  .descriptor.final		= cctests_condition_final_assertion_expected_ascii,
  .descriptor.static_message	= cctests_condition_static_message_assertion_expected_ascii,
  .print			= cctests_condition_print_assertion_expected_ascii_fun
};

cctests_descriptor_assertion_expected_ascii_t const * const cctests_descriptor_assertion_expected_ascii_ptr =
  &cctests_descriptor_assertion_expected_ascii_stru;

/* ------------------------------------------------------------------ */

void
cctests_condition_delete_assertion_expected_ascii (cce_condition_t * C)
{
  free(C);
}

void
cctests_condition_final_assertion_expected_ascii (cce_condition_t * C)
{
  CCTESTS_PC(cctests_condition_assertion_expected_ascii_t, K, C);

  free(K->expected);
  free(K->result);
}

char const *
cctests_condition_static_message_assertion_expected_ascii (cce_condition_t const * C CCTESTS_UNUSED)
{
  return "CCTests assertion failure, expected ASCII value";
}

void
cctests_condition_print_assertion_expected_ascii_fun (cce_condition_t const * C)
{
  cctests_condition_print_assertion_fun(C);
  {
    CCTESTS_PC(cctests_condition_assertion_expected_ascii_t, K, C);
    size_t	expected_len = strlen(K->expected);

    fprintf(cctests_log_stream, "\texpected: '%s' (len=%" PRIuSIZE ")\n", K->expected, expected_len);
    fprintf(cctests_log_stream, "\tresult:   '");
    fwrite(K->result, sizeof(char), K->result_len, cctests_log_stream);
    fprintf(cctests_log_stream, "' (len=%" PRIuSIZE ")\n", K->result_len);
  }
}

/* ------------------------------------------------------------------ */

void
cctests_condition_init_assertion_expected_ascii (cce_destination_t L,
						 cctests_condition_assertion_expected_ascii_t * C,
						 char const * const expr,
						 char const * const filename,
						 char const * const funcname,
						 int const linenum,
						 char const * expected, char const * result, size_t result_len)
{
  /* Initialise the parent type. */
  cctests_condition_init_assertion_expected_value(&(C->assertion_expected_value), expr, filename, funcname, linenum);

  /* Initialise the fields of this type. */
  {
    size_t	expected_len	= strlen(expected);

    C->expected	= cce_sys_malloc(L, 1+expected_len);
    strncpy(C->expected, expected, expected_len);
    C->expected[expected_len] = '\0';
  }
  {
    C->result	= cce_sys_malloc(L, result_len);
    strncpy(C->result, result, result_len);
    C->result_len = result_len;
  }
}

cce_condition_t const *
cctests_condition_new_assertion_expected_ascii (cce_destination_t L,
						char const * const expr,
						char const * const filename,
						char const * const funcname,
						int const linenum,
						char const * expected, char const * result, size_t result_len)
{
  cctests_condition_assertion_expected_ascii_t *	C =
    cce_sys_malloc(L, sizeof(cctests_condition_assertion_expected_ascii_t));

  /* Initialise the basic condition fields. */
  cce_condition_init((cce_condition_t *)C, &cctests_descriptor_assertion_expected_ascii_stru.descriptor);

  cctests_condition_init_assertion_expected_ascii(L, C, expr, filename, funcname, linenum, expected, result, result_len);

  return (cce_condition_t const *)C;
}

bool
cctests_condition_is_assertion_expected_ascii (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_assertion_expected_ascii_ptr->descriptor));
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: unreachable code.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_unreachable;
static cce_condition_delete_fun_t		cctests_condition_delete_unreachable;

static cctests_descriptor_unreachable_t const cctests_descriptor_unreachable_stru = {
  .descriptor.parent		= &cctests_descriptor_failure_stru.descriptor,
  .descriptor.delete		= cctests_condition_delete_unreachable,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_unreachable
};

cctests_descriptor_unreachable_t const * const cctests_descriptor_unreachable_ptr = &cctests_descriptor_unreachable_stru;

/* ------------------------------------------------------------------ */

void
cctests_condition_delete_unreachable (cce_condition_t * C)
{
  free(C);
}

char const *
cctests_condition_static_message_unreachable (cce_condition_t const * C CCTESTS_UNUSED)
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
  cce_condition_init((cce_condition_t *)C, &cctests_descriptor_unreachable_stru.descriptor);

  cctests_condition_init_unreachable(C, filename, funcname, linenum);

  return (cce_condition_t const *)C;
}

bool
cctests_condition_is_unreachable (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_unreachable_ptr->descriptor));
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: signal.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_signal;

static cctests_descriptor_signal_t const cctests_descriptor_signal_stru = {
  .descriptor.parent		= &cctests_descriptor_base_stru.descriptor,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_signal
};

cctests_descriptor_signal_t const * const cctests_descriptor_signal_ptr = &cctests_descriptor_signal_stru;

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_signal_t const cctests_condition_signal_stru = {
  .base.root.condition.descriptor	= &cctests_descriptor_signal_stru.descriptor
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_signal (cce_condition_t const * C CCTESTS_UNUSED)
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
  return (cce_condition_t *)&cctests_condition_signal_stru;
}

bool
cctests_condition_is_signal (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_signal_ptr->descriptor));
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: signal one.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_signal_1;

static cctests_descriptor_signal_1_t const cctests_descriptor_signal_1_stru = {
  .descriptor.parent		= &cctests_descriptor_signal_stru.descriptor,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_signal_1
};

cctests_descriptor_signal_1_t const * const cctests_descriptor_signal_1_ptr = &cctests_descriptor_signal_1_stru;

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_signal_1_t const cctests_condition_signal_1_stru = {
  .signal.base.root.condition.descriptor	= &cctests_descriptor_signal_1_stru.descriptor
};

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_signal_1 (cce_condition_t const * C CCTESTS_UNUSED)
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
  return (cce_condition_t *)&cctests_condition_signal_1_stru;
}

bool
cctests_condition_is_signal_1 (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_signal_1_ptr->descriptor));
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: signal two.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_signal_2;

static cctests_descriptor_signal_2_t const cctests_descriptor_signal_2_stru = {
  .descriptor.parent		= &cctests_descriptor_signal_stru.descriptor,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_signal_2
};

cctests_descriptor_signal_2_t const * const cctests_descriptor_signal_2_ptr = &cctests_descriptor_signal_2_stru;

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_signal_2_t const cctests_condition_signal_2_stru = {
  .signal.base.root.condition.descriptor	= &cctests_descriptor_signal_2_stru.descriptor
};

cce_condition_t const *
cctests_condition_new_signal_2 (void)
{
  return (cce_condition_t *)&cctests_condition_signal_2_stru;
}

char const *
cctests_condition_static_message_signal_2 (cce_condition_t const * C CCTESTS_UNUSED)
{
  return "CCTests exception signal 2";
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: signal three.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_signal_3;

static cctests_descriptor_signal_3_t const cctests_descriptor_signal_3_stru = {
  .descriptor.parent		= &cctests_descriptor_signal_stru.descriptor,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_signal_3
};

cctests_descriptor_signal_3_t const * const cctests_descriptor_signal_3_ptr = &cctests_descriptor_signal_3_stru;

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_signal_3_t const cctests_condition_signal_3_stru = {
  .signal.base.root.condition.descriptor	= &cctests_descriptor_signal_3_stru.descriptor
};

cce_condition_t const *
cctests_condition_new_signal_3 (void)
{
  return (cce_condition_t *)&cctests_condition_signal_3_stru;
}

char const *
cctests_condition_static_message_signal_3 (cce_condition_t const * C CCTESTS_UNUSED)
{
  return "CCTests exception signal 2";
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: regular expression error.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_regex_error;

static cctests_descriptor_regex_error_t cctests_descriptor_regex_error_stru = {
  /* This field is set by the initialisation function to the pointer:
   *
   *	&(cce_descriptor_runtime_error_ptr->descriptor)
   */
  .descriptor.parent		= NULL,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_regex_error
};

cctests_descriptor_regex_error_t const * const cctests_descriptor_regex_error_ptr = &cctests_descriptor_regex_error_stru;

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_regex_error (cce_condition_t const * C CCTESTS_UNUSED)
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

  cce_condition_init((cce_condition_t *)C, &cctests_descriptor_regex_error_stru.descriptor);
  cctests_condition_init_regex_error(C, errcode);
  return (cce_condition_t *)C;
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: regular expression compilation error.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_regex_compilation_error;

static cctests_descriptor_regex_compilation_error_t const cctests_descriptor_regex_compilation_error_stru = {
  .descriptor.parent		= &cctests_descriptor_regex_error_stru.descriptor,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_regex_compilation_error
};

cctests_descriptor_regex_compilation_error_t const * const cctests_descriptor_regex_compilation_error_ptr =
  &cctests_descriptor_regex_compilation_error_stru;

/* ------------------------------------------------------------------ */

char const *
cctests_condition_static_message_regex_compilation_error (cce_condition_t const * C CCTESTS_UNUSED)
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

  cce_condition_init((cce_condition_t *)C, &cctests_descriptor_regex_compilation_error_stru.descriptor);
  cctests_condition_init_regex_compilation_error(C, errcode);
  return (cce_condition_t *)C;
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: child failure.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_child_failure;

static cctests_descriptor_child_failure_t const cctests_descriptor_child_failure_stru = {
  .descriptor.parent		= &cctests_descriptor_failure_stru.descriptor,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_child_failure
};

cctests_descriptor_child_failure_t const * const cctests_descriptor_child_failure_ptr = &cctests_descriptor_child_failure_stru;

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_child_failure_t const cctests_condition_child_failure_stru = {
  .failure.base.root.condition.descriptor	= &cctests_descriptor_child_failure_stru.descriptor
};

void
cctests_condition_init_child_failure (cctests_condition_child_failure_t * C)
{
  cctests_condition_init_failure(&(C->failure));
}

cce_condition_t const *
cctests_condition_new_child_failure (void)
{
  return (cce_condition_t *)&cctests_condition_child_failure_stru;
}

char const *
cctests_condition_static_message_child_failure (cce_condition_t const * C CCTESTS_UNUSED)
{
  return "CCTests exception child failure";
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: child failure, abnormal termination.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_child_abnormal_termination;

static cctests_descriptor_child_abnormal_termination_t const cctests_descriptor_child_abnormal_termination_stru = {
  .descriptor.parent		= &cctests_descriptor_child_failure_stru.descriptor,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_child_abnormal_termination
};

cctests_descriptor_child_abnormal_termination_t const * const cctests_descriptor_child_abnormal_termination_ptr =
  &cctests_descriptor_child_abnormal_termination_stru;

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_child_abnormal_termination_t const cctests_condition_child_abnormal_termination_stru = {
  .child_failure.failure.base.root.condition.descriptor	= &cctests_descriptor_child_abnormal_termination_stru.descriptor
};

void
cctests_condition_init_child_abnormal_termination (cctests_condition_child_abnormal_termination_t * C)
{
  cctests_condition_init_child_failure(&(C->child_failure));
}

cce_condition_t const *
cctests_condition_new_child_abnormal_termination (void)
{
  return (cce_condition_t *)&cctests_condition_child_abnormal_termination_stru;
}

char const *
cctests_condition_static_message_child_abnormal_termination (cce_condition_t const * C CCTESTS_UNUSED)
{
  return "CCTests exception child failure: abnormal termination";
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: child failure, failure exit status.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cctests_condition_static_message_child_failure_exit_status;

static cctests_descriptor_child_failure_exit_status_t const cctests_descriptor_child_failure_exit_status_stru = {
  .descriptor.parent		= &cctests_descriptor_child_failure_stru.descriptor,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cctests_condition_static_message_child_failure_exit_status
};

cctests_descriptor_child_failure_exit_status_t const * const cctests_descriptor_child_failure_exit_status_ptr =
  &cctests_descriptor_child_failure_exit_status_stru;

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_child_failure_exit_status_t const cctests_condition_child_failure_exit_status_stru = {
  .child_failure.failure.base.root.condition.descriptor	= &cctests_descriptor_child_failure_exit_status_stru.descriptor
};

void
cctests_condition_init_child_failure_exit_status (cctests_condition_child_failure_exit_status_t * C)
{
  cctests_condition_init_child_failure(&(C->child_failure));
}

cce_condition_t const *
cctests_condition_new_child_failure_exit_status (void)
{
  return (cce_condition_t *)&cctests_condition_child_failure_exit_status_stru;
}

char const *
cctests_condition_static_message_child_failure_exit_status (cce_condition_t const * C CCTESTS_UNUSED)
{
  return "CCTests exception child failure: failure exit status";
}


/** --------------------------------------------------------------------
 ** Module initialisation.
 ** ----------------------------------------------------------------- */

void
cctests_conditions_module_initialisation (void)
{
  cce_descriptor_set_root_parent(&cctests_descriptor_base_stru.descriptor);
  cctests_descriptor_regex_error_stru.descriptor.parent = &(cce_descriptor_runtime_error_ptr->descriptor);
}

/* end of file */
