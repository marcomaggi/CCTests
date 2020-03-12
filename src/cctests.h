/*
  Part of: CCTests
  Contents: public header file
  Date: Nov 28, 2017

  Abstract

  This is the public header file for the library CCTests.  It must
  be included  in all the source  files using the features  of the
  library.

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

#ifndef CCTESTS_H
#define CCTESTS_H 1


/** --------------------------------------------------------------------
 ** Preliminary definitions.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

/* The macro CCTESTS_UNUSED indicates  that a function, function argument
   or variable may potentially be unused. Usage examples:

   static int unused_function (char arg) CCTESTS_UNUSED;
   int foo (char unused_argument CCTESTS_UNUSED);
   int unused_variable CCTESTS_UNUSED;
*/
#ifdef __GNUC__
#  define CCTESTS_UNUSED		__attribute__((__unused__))
#else
#  define CCTESTS_UNUSED		/* empty */
#endif

#ifndef __GNUC__
#  define __attribute__(...)	/* empty */
#endif

/* I found  the following chunk on  the Net.  (Marco Maggi;  Sun Feb 26,
   2012) */
#if defined _WIN32 || defined __CYGWIN__
#  ifdef BUILDING_DLL
#    ifdef __GNUC__
#      define cctests_decl		__attribute__((__dllexport__)) extern
#    else
#      define cctests_decl		__declspec(dllexport) extern
#    endif
#  else
#    ifdef __GNUC__
#      define cctests_decl		__attribute__((__dllimport__)) extern
#    else
#      define cctests_decl		__declspec(dllimport) extern
#    endif
#  endif
#  define cctests_private_decl	extern
#else
#  if __GNUC__ >= 4
#    define cctests_decl		__attribute__((__visibility__("default"))) extern
#    define cctests_private_decl	__attribute__((__visibility__("hidden")))  extern
#  else
#    define cctests_decl		extern
#    define cctests_private_decl	extern
#  endif
#endif


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#include <ccexceptions.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>


/** --------------------------------------------------------------------
 ** Constants and preprocessor macros.
 ** ----------------------------------------------------------------- */

#define CCTESTS_PC(POINTER_TYPE, POINTER_NAME, EXPRESSION)	\
  POINTER_TYPE * POINTER_NAME = (POINTER_TYPE *) (EXPRESSION)

#ifndef cce_descriptor_pointer
#  define cce_descriptor_pointer(EXCEPTIONAL_CONDITION_DESCRIPTOR_VARIABLE)	\
  &((EXCEPTIONAL_CONDITION_DESCRIPTOR_VARIABLE).descriptor)
#endif

cctests_decl unsigned char const	CCTESTS_UCHAR_MAX;
cctests_decl unsigned char const	CCTESTS_UCHAR_MIN;
cctests_decl signed char const		CCTESTS_CHAR_MAX;
cctests_decl signed char const		CCTESTS_CHAR_MIN;

cctests_decl unsigned short const	CCTESTS_USHORT_MAX;
cctests_decl unsigned short const	CCTESTS_USHORT_MIN;
cctests_decl signed short const		CCTESTS_SHORT_MAX;
cctests_decl signed short const		CCTESTS_SHORT_MIN;

cctests_decl unsigned int const		CCTESTS_UINT_MAX;
cctests_decl unsigned int const		CCTESTS_UINT_MIN;
cctests_decl signed int const		CCTESTS_INT_MAX;
cctests_decl signed int const		CCTESTS_INT_MIN;

cctests_decl unsigned long const	CCTESTS_ULONG_MAX;
cctests_decl unsigned long const	CCTESTS_ULONG_MIN;
cctests_decl signed long const		CCTESTS_LONG_MAX;
cctests_decl signed long const		CCTESTS_LONG_MIN;

cctests_decl unsigned long long const	CCTESTS_ULLONG_MAX;
cctests_decl unsigned long long const	CCTESTS_ULLONG_MIN;
cctests_decl signed long long const	CCTESTS_LLONG_MAX;
cctests_decl signed long long const	CCTESTS_LLONG_MIN;

cctests_decl uint8_t const		CCTESTS_UINT8_MAX;
cctests_decl uint8_t const		CCTESTS_UINT8_MIN;
cctests_decl int8_t const		CCTESTS_INT8_MAX;
cctests_decl int8_t const		CCTESTS_INT8_MIN;

cctests_decl uint16_t const		CCTESTS_UINT16_MAX;
cctests_decl uint16_t const		CCTESTS_UINT16_MIN;
cctests_decl int16_t const		CCTESTS_INT16_MAX;
cctests_decl int16_t const		CCTESTS_INT16_MIN;

cctests_decl uint32_t const		CCTESTS_UINT32_MAX;
cctests_decl uint32_t const		CCTESTS_UINT32_MIN;
cctests_decl int32_t const		CCTESTS_INT32_MAX;
cctests_decl int32_t const		CCTESTS_INT32_MIN;

cctests_decl uint64_t const		CCTESTS_UINT64_MAX;
cctests_decl uint64_t const		CCTESTS_UINT64_MIN;
cctests_decl int64_t const		CCTESTS_INT64_MAX;
cctests_decl int64_t const		CCTESTS_INT64_MIN;

cctests_decl size_t const		CCTESTS_SIZE_MIN;
cctests_decl size_t const		CCTESTS_SIZE_MAX;

cctests_decl ssize_t const		CCTESTS_SSIZE_MIN;
cctests_decl ssize_t const		CCTESTS_SSIZE_MAX;

cctests_decl ptrdiff_t const		CCTESTS_PTRDIFF_MIN;
cctests_decl ptrdiff_t const		CCTESTS_PTRDIFF_MAX;

cctests_decl intptr_t const		CCTESTS_INTPTR_MIN;
cctests_decl intptr_t const		CCTESTS_INTPTR_MAX;

cctests_decl uintptr_t const		CCTESTS_UINTPTR_MIN;
cctests_decl uintptr_t const		CCTESTS_UINTPTR_MAX;


/** --------------------------------------------------------------------
 ** Type definitions.
 ** ----------------------------------------------------------------- */

typedef void cctests_fun_t (cce_destination_t L);

/* ------------------------------------------------------------------ */

#define CCTESTS_STRUCT_TYPEDEF(NAME)	typedef struct NAME NAME

CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_base_t);
CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_success_t);
CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_skipped_t);
CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_failure_t);
CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_expected_failure_t);
CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_assertion_t);
CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_assertion_expected_value_t);
CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_assertion_expected_asciiz_t);
CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_assertion_expected_ascii_t);
CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_unreachable_t);

CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_signal_t);
CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_signal_1_t);
CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_signal_2_t);
CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_signal_3_t);

CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_regex_error_t);
CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_regex_compilation_error_t);

CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_child_failure_t);
CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_child_abnormal_termination_t);
CCTESTS_STRUCT_TYPEDEF(cctests_descriptor_child_failure_exit_status_t);

/* ------------------------------------------------------------------ */

CCTESTS_STRUCT_TYPEDEF(cctests_condition_base_t);
CCTESTS_STRUCT_TYPEDEF(cctests_condition_success_t);
CCTESTS_STRUCT_TYPEDEF(cctests_condition_skipped_t);
CCTESTS_STRUCT_TYPEDEF(cctests_condition_failure_t);
CCTESTS_STRUCT_TYPEDEF(cctests_condition_expected_failure_t);
CCTESTS_STRUCT_TYPEDEF(cctests_condition_assertion_t);
CCTESTS_STRUCT_TYPEDEF(cctests_condition_assertion_expected_value_t);
CCTESTS_STRUCT_TYPEDEF(cctests_condition_assertion_expected_asciiz_t);
CCTESTS_STRUCT_TYPEDEF(cctests_condition_assertion_expected_ascii_t);
CCTESTS_STRUCT_TYPEDEF(cctests_condition_unreachable_t);

CCTESTS_STRUCT_TYPEDEF(cctests_condition_signal_t);
CCTESTS_STRUCT_TYPEDEF(cctests_condition_signal_1_t);
CCTESTS_STRUCT_TYPEDEF(cctests_condition_signal_2_t);
CCTESTS_STRUCT_TYPEDEF(cctests_condition_signal_3_t);

CCTESTS_STRUCT_TYPEDEF(cctests_condition_regex_error_t);
CCTESTS_STRUCT_TYPEDEF(cctests_condition_regex_compilation_error_t);

CCTESTS_STRUCT_TYPEDEF(cctests_condition_child_failure_t);
CCTESTS_STRUCT_TYPEDEF(cctests_condition_child_abnormal_termination_t);
CCTESTS_STRUCT_TYPEDEF(cctests_condition_child_failure_exit_status_t);


/** --------------------------------------------------------------------
 ** Library initialisation.
 ** ----------------------------------------------------------------- */

cctests_decl void cctests_init (char const * test_file_name)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_final (void);
cctests_decl void cctests_reset_global_state (void);


/** --------------------------------------------------------------------
 ** Version functions.
 ** ----------------------------------------------------------------- */

cctests_decl char const * cctests_version_string (void);
cctests_decl int	cctests_version_interface_current (void);
cctests_decl int	cctests_version_interface_revision (void);
cctests_decl int	cctests_version_interface_age (void);


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: base.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_base_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_base_t {
  cce_condition_root_t	root;
};

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_base_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_base (cctests_condition_base_t * C)
  __attribute__((__nonnull__(1)));

cctests_decl bool cctests_condition_is_base (cce_condition_t const * C)
  __attribute__((__pure__,__nonnull__(1)));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: test success.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_success_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_success_t {
  cctests_condition_base_t	base;
};

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_success_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_success (cctests_condition_success_t * C)
  __attribute__((__nonnull__(1)));

cctests_decl cce_condition_t const * cctests_condition_new_success (void)
  __attribute__((__const__,__returns_nonnull__));

cctests_decl bool cctests_condition_is_success (cce_condition_t const * C)
  __attribute__((__pure__,__nonnull__(1)));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: test skipped.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_skipped_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_skipped_t {
  cctests_condition_base_t	base;
};

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_skipped_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_skipped (cctests_condition_skipped_t * C)
  __attribute__((__nonnull__(1)));

cctests_decl cce_condition_t const * cctests_condition_new_skipped (void)
  __attribute__((__const__,__returns_nonnull__));

cctests_decl bool cctests_condition_is_skipped (cce_condition_t const * C)
  __attribute__((__pure__,__nonnull__(1)));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: test failure.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_failure_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_failure_t {
  cctests_condition_base_t	base;
};

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_failure_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_failure (cctests_condition_failure_t * C)
  __attribute__((__nonnull__(1)));

cctests_decl cce_condition_t const * cctests_condition_new_failure (void)
  __attribute__((__const__,__returns_nonnull__));

cctests_decl bool cctests_condition_is_failure (cce_condition_t const * C)
  __attribute__((__pure__,__nonnull__(1)));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: test expected failure.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_expected_failure_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_expected_failure_t {
  cctests_condition_failure_t	failure;
};

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_expected_failure_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_expected_failure (cctests_condition_expected_failure_t * C)
  __attribute__((__nonnull__(1)));

cctests_decl cce_condition_t const * cctests_condition_new_expected_failure (void)
  __attribute__((__const__,__returns_nonnull__));

cctests_decl bool cctests_condition_is_expected_failure (cce_condition_t const * C)
  __attribute__((__pure__,__nonnull__(1)));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: assertion failure.
 ** ----------------------------------------------------------------- */

typedef void cctests_condition_print_assertion_fun_t (cce_condition_t const * C);

struct cctests_descriptor_assertion_t {
  cce_descriptor_t	descriptor;
  cctests_condition_print_assertion_fun_t * print;
};

struct cctests_condition_assertion_t {
  cctests_condition_failure_t	failure;
  char const *			expr;
  char const *			filename;
  char const *			funcname;
  int				linenum;
  /* This is either NULL or a pointer to an ASCIIZ message string allocated using the
     standard allocator. */
  char const *			dynamic_string;
};

/* ------------------------------------------------------------------ */

#undef CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS
#define CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS				\
  char const * expr, char const * filename, char const * funcname, int const linenum, char const * description_message

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_assertion_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_assertion (cctests_condition_assertion_t * C, CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,2,3,4)));

cctests_decl cce_condition_t const * cctests_condition_new_assertion (cce_destination_t L, CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,2,3,4),__returns_nonnull__));

cctests_decl bool cctests_condition_is_assertion (cce_condition_t const * C)
  __attribute__((__nonnull__(1),__pure__));

cctests_decl void cctests_condition_print_assertion (cce_condition_t const * C)
  __attribute__((__nonnull__(1)));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: assertion failure, expected value.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_assertion_expected_value_t {
  cce_descriptor_t	descriptor;
  cctests_condition_print_assertion_fun_t * print;
};

struct cctests_condition_assertion_expected_value_t {
  cctests_condition_assertion_t	assertion;
};

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_expected_value_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_assertion_expected_value (cctests_condition_assertion_expected_value_t * C,
								   CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,2,3,4)));

/* This condition object type cannot be instantiated, only subtyped. */

cctests_decl bool cctests_condition_is_assertion_expected_value (cce_condition_t const * C)
  __attribute__((__nonnull__(1),__pure__));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: assertion failure, expected immediate value.
 ** ----------------------------------------------------------------- */

#define CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(STEM, TYPE)	\
  typedef struct cctests_descriptor_assertion_expected_ ## STEM ## _t	\
  cctests_descriptor_assertion_expected_ ## STEM ## _t;			\
  typedef struct cctests_condition_assertion_expected_ ## STEM ## _t	\
  cctests_condition_assertion_expected_ ## STEM ## _t;			\
									\
  struct cctests_descriptor_assertion_expected_ ## STEM ## _t {		\
    cce_descriptor_t	descriptor;					\
    cctests_condition_print_assertion_fun_t * print;			\
  };									\
									\
  struct cctests_condition_assertion_expected_ ## STEM ## _t {		\
    cctests_condition_assertion_expected_value_t assertion_expected_value; \
    TYPE		expected;					\
    TYPE		result;						\
  };									\
									\
  cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_assertion_expected_ ## STEM ## _t) (cce_descriptor_t * const D) \
    __attribute__((__nonnull__(1)));					\
									\
  cctests_decl void cctests_condition_init_assertion_expected_ ## STEM	\
  (cctests_condition_assertion_expected_ ## STEM ## _t * C, TYPE expected, TYPE result, CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS) \
    __attribute__((__nonnull__(1,4,5,6)));				\
									\
  cctests_decl cce_condition_t const * cctests_condition_new_assertion_expected_ ## STEM \
  (cce_destination_t L, TYPE expected, TYPE result, CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS) \
    __attribute__((__nonnull__(1,4,5,6),__returns_nonnull__));		\
									\
  cctests_decl bool cctests_condition_is_assertion_expected_ ## STEM (cce_condition_t const * C) \
    __attribute__((__nonnull__(1),__pure__));

/* ------------------------------------------------------------------ */

CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(char,	signed char)
CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(uchar,	unsigned char)

CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(int,	signed int)
CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(uint,	unsigned int)

CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(short,	signed short)
CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(ushort,	unsigned short)

CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(long,	signed long)
CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(ulong,	unsigned long)

CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(llong,	signed long long)
CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(ullong,	unsigned long long)

CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(int8,	int8_t)
CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(int16,	int16_t)
CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(int32,	int32_t)
CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(int64,	int64_t)

CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(uint8,	uint8_t)
CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(uint16,	uint16_t)
CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(uint32,	uint32_t)
CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(uint64,	uint64_t)

CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(float,	float)
CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(double,	double)

CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(size,	size_t)
CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(ssize,	ssize_t)

CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(pointer,	void *)
CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(ptrdiff,	ptrdiff_t)
CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(intptr,	intptr_t)
CCTESTS_DECLARE_CONDITION_ASSERTION_EXPECTED(uintptr,	uintptr_t)


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: assertion failure, expected ASCIIZ value.
 ** ----------------------------------------------------------------- */

typedef struct cctests_descriptor_assertion_expected_asciiz_t	cctests_descriptor_assertion_expected_asciiz_t;
typedef struct cctests_condition_assertion_expected_asciiz_t	cctests_condition_assertion_expected_asciiz_t;

struct cctests_descriptor_assertion_expected_asciiz_t {
  cce_descriptor_t	descriptor;
  cctests_condition_print_assertion_fun_t * print;
};

struct cctests_condition_assertion_expected_asciiz_t {
  cctests_condition_assertion_expected_value_t assertion_expected_value;
  char *			expected;
  char *			result;
};

/* ------------------------------------------------------------------ */

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_expected_asciiz_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_assertion_expected_asciiz (cce_destination_t L,
								    cctests_condition_assertion_expected_asciiz_t * C,
								    char const * expected, char const * result,
								    CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,2,3,4,5,6,7)));

cctests_decl cce_condition_t const * cctests_condition_new_assertion_expected_asciiz (cce_destination_t L,
										      char const * expected, char const * result,
										      CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,2,3,4,5,6),__returns_nonnull__));

cctests_decl bool cctests_condition_is_assertion_expected_asciiz (cce_condition_t const * C)
  __attribute__((__nonnull__(1),__pure__));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: assertion failure, expected ASCII value.
 ** ----------------------------------------------------------------- */

typedef struct cctests_descriptor_assertion_expected_ascii_t	cctests_descriptor_assertion_expected_ascii_t;
typedef struct cctests_condition_assertion_expected_ascii_t	cctests_condition_assertion_expected_ascii_t;

struct cctests_descriptor_assertion_expected_ascii_t {
  cce_descriptor_t	descriptor;
  cctests_condition_print_assertion_fun_t * print;
};

struct cctests_condition_assertion_expected_ascii_t {
  cctests_condition_assertion_expected_value_t assertion_expected_value;
  char *			expected;
  char *			result;
  size_t			result_len;
};

/* ------------------------------------------------------------------ */

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_expected_ascii_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_assertion_expected_ascii (cce_destination_t L,
								   cctests_condition_assertion_expected_ascii_t * C,
								   char const * expected, char const * result,
								   size_t result_len,
								   CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,2,3,4,6,7,8)));

cctests_decl cce_condition_t const * cctests_condition_new_assertion_expected_ascii (cce_destination_t L,
										     char const * expected, char const * result,
										     size_t result_len,
										     CCTESTS_CONDITION_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,2,3,5,6,7),__returns_nonnull__));

cctests_decl bool cctests_condition_is_assertion_expected_ascii (cce_condition_t const * C)
  __attribute__((__nonnull__(1),__pure__));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: unreachable code.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_unreachable_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_unreachable_t {
  cctests_condition_failure_t	failure;
  char const *			filename;
  char const *			funcname;
  int				linenum;
};

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_unreachable_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_unreachable (cctests_condition_unreachable_t * C,
						      char const * filename,
						      char const * funcname,
						      int const linenum)
  __attribute__((__nonnull__(1,2,3)));

cctests_decl cce_condition_t const * cctests_condition_new_unreachable (cce_destination_t L,
									char const * filename,
									char const * funcname,
									int const linenum)
  __attribute__((__nonnull__(1,2,3),__returns_nonnull__));

#define cctests_raise_unreachable(L)					\
  cce_raise((L), cctests_condition_new_unreachable((L), __FILE__, __func__, __LINE__))

cctests_decl bool cctests_condition_is_unreachable (cce_condition_t const * C)
  __attribute__((__nonnull__(1),__pure__));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: signal.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_signal_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_signal_t {
  cctests_condition_base_t	base;
};

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_signal_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_signal (cctests_condition_signal_t * C)
  __attribute__((__nonnull__(1)));

cctests_decl cce_condition_t const * cctests_condition_new_signal (void)
  __attribute__((__leaf__,__const__,__returns_nonnull__));

cctests_decl bool cctests_condition_is_signal (cce_condition_t const * C)
  __attribute__((__nonnull__(1),__pure__));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: signal one.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_signal_1_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_signal_1_t {
  cctests_condition_signal_t	signal;
};

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_signal_1_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_signal_1 (cctests_condition_signal_1_t * C)
  __attribute__((__nonnull__(1)));

cctests_decl cce_condition_t const * cctests_condition_new_signal_1 (void)
  __attribute__((__leaf__,__const__,__returns_nonnull__));

cctests_decl bool cctests_condition_is_signal_1 (cce_condition_t const * C)
  __attribute__((__nonnull__(1),__pure__));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: signal two.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_signal_2_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_signal_2_t {
  cctests_condition_signal_t	signal;
};

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_signal_2_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_signal_2 (cctests_condition_signal_2_t * C)
  __attribute__((__nonnull__(1)));

cctests_decl cce_condition_t const * cctests_condition_new_signal_2 (void)
  __attribute__((__leaf__,__const__,__returns_nonnull__));

cctests_decl bool cctests_condition_is_signal_2 (cce_condition_t const * C)
  __attribute__((__nonnull__(1),__pure__));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: signal three.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_signal_3_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_signal_3_t {
  cctests_condition_signal_t	signal;
};

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_signal_3_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_signal_3 (cctests_condition_signal_3_t * C)
  __attribute__((__nonnull__(1)));

cctests_decl cce_condition_t const * cctests_condition_new_signal_3 (void)
  __attribute__((__leaf__,__const__,__returns_nonnull__));

cctests_decl bool cctests_condition_is_signal_3 (cce_condition_t const * C)
  __attribute__((__nonnull__(1),__pure__));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: regular expression error.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_regex_error_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_regex_error_t {
  cce_condition_runtime_error_t	runtime_error;
  int	errcode;
  char	error_message[1024];
};

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_regex_error_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_regex_error (cctests_condition_regex_error_t * C, int errcode)
  __attribute__((__nonnull__(1)));

cctests_decl cce_condition_t const * cctests_condition_new_regex_error (cce_destination_t L, int errcode)
  __attribute__((__nonnull__(1),__returns_nonnull__));

cctests_decl bool cctests_condition_is_regex_error (cce_condition_t const * C)
  __attribute__((__nonnull__(1),__pure__));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: regular expression compilation error.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_regex_compilation_error_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_regex_compilation_error_t {
  cctests_condition_regex_error_t	regex_error;
};

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_regex_compilation_error_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_regex_compilation_error (cctests_condition_regex_compilation_error_t * C, int errcode)
  __attribute__((__nonnull__(1)));

cctests_decl cce_condition_t const * cctests_condition_new_regex_compilation_error (cce_destination_t L, int errcode)
  __attribute__((__nonnull__(1),__returns_nonnull__));

cctests_decl bool cctests_condition_is_regex_compilation_error (cce_condition_t const * C)
  __attribute__((__nonnull__(1),__pure__));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: child process failure.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_child_failure_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_child_failure_t {
  cctests_condition_failure_t	failure;
};

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_child_failure_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_child_failure (cctests_condition_child_failure_t * C)
  __attribute__((__nonnull__(1)));

cctests_decl cce_condition_t const * cctests_condition_new_child_failure (void)
  __attribute__((__returns_nonnull__));

cctests_decl bool cctests_condition_is_child_failure (cce_condition_t const * C)
  __attribute__((__nonnull__(1),__pure__));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: child process abnormal termination.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_child_abnormal_termination_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_child_abnormal_termination_t {
  cctests_condition_child_failure_t	child_failure;
};

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_child_abnormal_termination_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_child_abnormal_termination (cctests_condition_child_abnormal_termination_t * C)
  __attribute__((__nonnull__(1)));

cctests_decl cce_condition_t const * cctests_condition_new_child_abnormal_termination (void)
  __attribute__((__returns_nonnull__));

cctests_decl bool cctests_condition_is_child_abnormal_termination (cce_condition_t const * C)
  __attribute__((__nonnull__(1),__pure__));


/** --------------------------------------------------------------------
 ** Exceptional-condition objects: child process abnormal termination.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_child_failure_exit_status_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_child_failure_exit_status_t {
  cctests_condition_child_failure_t	child_failure;
};

cctests_decl void cce_descriptor_set_parent_to(cctests_descriptor_child_failure_exit_status_t) (cce_descriptor_t * const D)
  __attribute__((__nonnull__(1)));

cctests_decl void cctests_condition_init_child_failure_exit_status (cctests_condition_child_failure_exit_status_t * C)
  __attribute__((__nonnull__(1)));

cctests_decl cce_condition_t const * cctests_condition_new_child_failure_exit_status (void)
  __attribute__((__returns_nonnull__));

cctests_decl bool cctests_condition_is_child_failure_exit_status (cce_condition_t const * C)
  __attribute__((__nonnull__(1),__pure__));


/** --------------------------------------------------------------------
 ** Test driver.
 ** ----------------------------------------------------------------- */

cctests_decl void cctests_begin_group (char const * test_group_name)
  __attribute__((__nonnull__(1)));
cctests_decl void cctests_end_group   (void);

#define cctests_run(TEST_FUNC_NAME)	cctests_p_run(#TEST_FUNC_NAME, TEST_FUNC_NAME)
cctests_decl void cctests_p_run (char const * test_func_name, cctests_fun_t * fun)
  __attribute__((__nonnull__(1,2)));

cctests_decl bool cctests_latest_group_completed_successfully (void);
cctests_decl bool cctests_latest_func_completed_successfully (void);


/** --------------------------------------------------------------------
 ** Assertions API: common definitions.
 ** ----------------------------------------------------------------- */

cctests_decl cce_destination_t	cctests_location;

__attribute__((__always_inline__))
static inline void
cctests_skip (void)
{
  cce_raise(cctests_location, cctests_condition_new_skipped());
}

cctests_decl char const * cctests_p_format_message (cce_destination_t L, char const * template, ...)
  __attribute__((__nonnull__(1)));


/** --------------------------------------------------------------------
 ** Assertions: basic expressions.
 ** ----------------------------------------------------------------- */

#undef CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS
#define CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS				\
  char const * expr, char const * filename, char const * funcname, int linenum, char const * description_message

#undef CCTESTS_ASSERT_COMMON_CALL_ARGS
#define CCTESTS_ASSERT_COMMON_CALL_ARGS(LOCATION, ...)				\
  cctests_p_expr, __FILE__, __func__, cctests_p_linenum, cctests_p_format_message((LOCATION), __VA_ARGS__, NULL)

/* ------------------------------------------------------------------ */

cctests_decl void cctests_p_assert_raise (cce_destination_t L, CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS);

#define cctests_assert(L,...)		cctests_assert_1(L,__VA_ARGS__,NULL)
#define cctests_assert_1(L,EXPR,...)					\
  { size_t	cctests_p_linenum  = __LINE__;				\
    if (!(EXPR)) {							\
      cctests_p_assert_raise(L,						\
			     "cctests_assert(" #L ", " #EXPR ")",	\
			     __FILE__, __func__, cctests_p_linenum,	\
			     cctests_p_format_message(L, __VA_ARGS__, NULL)); \
    }									\
  }

#define cctests_assert_true(L,...)	cctests_assert_true_1(L,__VA_ARGS__,NULL)
#define cctests_assert_true_1(L,EXPR,...)				\
  { size_t	cctests_p_linenum  = __LINE__;				\
    if (!(EXPR)) {							\
      cctests_p_assert_raise(L,						\
			     "cctests_assert_true(" #L ", " #EXPR ")",	\
			     __FILE__, __func__, cctests_p_linenum,	\
			     cctests_p_format_message(L, __VA_ARGS__, NULL)); \
    }									\
  }

#define cctests_assert_false(L,...)	cctests_assert_false_1(L,__VA_ARGS__,NULL)
#define cctests_assert_false_1(L,EXPR,...)				\
  { size_t	cctests_p_linenum  = __LINE__;				\
    if (EXPR) {								\
      cctests_p_assert_raise(L,						\
			     "cctests_assert_false(" #L ", " #EXPR ")",	\
			     __FILE__, __func__, cctests_p_linenum,	\
			     cctests_p_format_message(L, __VA_ARGS__, NULL)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Assertions: ASCIIZ strings.
 ** ----------------------------------------------------------------- */

cctests_decl bool cctests_p_assert_asciiz_compare (char const * expected, char const * result)
  __attribute__((__nonnull__(1,2),__pure__));

cctests_decl void cctests_p_assert_asciiz_raise (cce_destination_t L, char const * expected, char const * result,
						 char const * expr,
						 char const * filename, char const * funcname, int linenum,
						 char const * description_message)
  __attribute__((__nonnull__(1,2,3,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_asciiz(L,EXPECTED,...)		\
  cctests_assert_asciiz_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_asciiz_1(L,EXPECTED,RESULT,...)			\
  { size_t		cctests_p_linenum  = __LINE__;			\
    char const *	cctests_p_expected = (EXPECTED);		\
    char const *	cctests_p_result   = (RESULT);			\
    static char const *	cctests_p_expr     = "cctests_assert_asciiz(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_asciiz_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_asciiz_raise(L, cctests_p_expected, cctests_p_result, \
				    CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Assertions: ASCII strings.
 ** ----------------------------------------------------------------- */

cctests_decl bool cctests_p_assert_ascii_compare (char const * expected, char const * result, size_t result_len)
  __attribute__((__nonnull__(1,2),__pure__));

cctests_decl void cctests_p_assert_ascii_raise (cce_destination_t L, char const * expected, char const * result, size_t result_len,
						CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,2,3,5,6,7)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So  we use  "RESULT_LEN" as  such argument  and add  a NULL  for the  other, true,
   macro. */
#define cctests_assert_ascii(L,EXPECTED,RESULT,...)		\
  cctests_assert_ascii_1(L,EXPECTED,RESULT,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_ascii_1(L,EXPECTED,RESULT,RESULT_LEN,...)	\
  { size_t		cctests_p_linenum    = __LINE__;		\
    char const *	cctests_p_expected   = (EXPECTED);		\
    char const *	cctests_p_result     = (RESULT);		\
    size_t		cctests_p_result_len = (RESULT_LEN);		\
    static char const *	cctests_p_expr       = "cctests_assert_ascii(" #L ", " #EXPECTED ", " #RESULT ", " #RESULT_LEN ")"; \
    if (cctests_p_assert_ascii_compare(cctests_p_expected, cctests_p_result, cctests_p_result_len)) { \
      cctests_p_assert_ascii_raise(L, cctests_p_expected, cctests_p_result, cctests_p_result_len, \
				   CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Assertions: standalone characters.
 ** ----------------------------------------------------------------- */

cctests_decl bool cctests_p_assert_char_compare (signed char expected, signed char result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_char_raise (cce_destination_t L, signed char expected, signed char result,
					       CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_char(L,EXPECTED,...)		\
  cctests_assert_equal_char_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_char_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    signed char const	cctests_p_expected = (EXPECTED);		\
    signed char	const	cctests_p_result   = (RESULT);			\
    static char const *	cctests_p_expr     = "cctests_assert_equal_char(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_char_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_char_raise(L, cctests_p_expected, cctests_p_result, \
				  CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }

/* ------------------------------------------------------------------ */

cctests_decl bool cctests_p_assert_uchar_compare (unsigned char expected, unsigned char result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_uchar_raise (cce_destination_t L, unsigned char expected, unsigned char result,
						CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_uchar(L,EXPECTED,...)		\
  cctests_assert_equal_uchar_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_uchar_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    unsigned char const	cctests_p_expected = (EXPECTED);		\
    unsigned char const	cctests_p_result   = (RESULT);			\
    static char const *	cctests_p_expr     = "cctests_assert_equal_uchar(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_uchar_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_uchar_raise(L, cctests_p_expected, cctests_p_result, \
				   CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Assertions: short integers.
 ** ----------------------------------------------------------------- */

cctests_decl bool cctests_p_assert_short_compare (signed short int expected, signed short int result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_short_raise (cce_destination_t L, signed short int expected, signed short int result,
						CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_short(L,EXPECTED,...)		\
  cctests_assert_equal_short_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_short_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    signed short int const	cctests_p_expected = (EXPECTED);	\
    signed short int const	cctests_p_result   = (RESULT);		\
    static char const *cctests_p_expr     = "cctests_assert_equal_short(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_short_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_short_raise(L, cctests_p_expected, cctests_p_result, \
				   CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }

/* ------------------------------------------------------------------ */

cctests_decl bool cctests_p_assert_ushort_compare (unsigned short int expected, unsigned short int result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_ushort_raise (cce_destination_t L, unsigned short int expected, unsigned short int result,
						 CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_ushort(L,EXPECTED,...)		\
  cctests_assert_equal_ushort_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_ushort_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    unsigned short int const	cctests_p_expected = (EXPECTED);	\
    unsigned short int const	cctests_p_result   = (RESULT);		\
    static char const *cctests_p_expr     = "cctests_assert_equal_ushort(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_ushort_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_ushort_raise(L, cctests_p_expected, cctests_p_result, \
				    CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Assertions: integers.
 ** ----------------------------------------------------------------- */

cctests_decl bool cctests_p_assert_int_compare (signed int expected, signed int result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_int_raise (cce_destination_t L, signed int expected, signed int result,
					      CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_int(L,EXPECTED,...)		\
  cctests_assert_equal_int_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_int_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    signed int const	cctests_p_expected = (EXPECTED);		\
    signed int const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_int(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_int_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_int_raise(L, cctests_p_expected, cctests_p_result, \
				 CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }

/* ------------------------------------------------------------------ */

cctests_decl bool cctests_p_assert_uint_compare (unsigned int expected, unsigned int result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_uint_raise (cce_destination_t L, unsigned int expected, unsigned int result,
					       CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_uint(L,EXPECTED,...)		\
  cctests_assert_equal_uint_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_uint_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    unsigned int const	cctests_p_expected = (EXPECTED);		\
    unsigned int const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_uint(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_uint_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_uint_raise(L, cctests_p_expected, cctests_p_result, \
				  CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Assertions: long integers.
 ** ----------------------------------------------------------------- */

cctests_decl bool cctests_p_assert_long_compare (signed long expected, signed long result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_long_raise (cce_destination_t L, signed long expected, signed long result,
					       CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_long(L,EXPECTED,...)		\
  cctests_assert_equal_long_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_long_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    signed long const	cctests_p_expected = (EXPECTED);		\
    signed long const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_long(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_long_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_long_raise(L, cctests_p_expected, cctests_p_result, \
				  CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }

/* ------------------------------------------------------------------ */

cctests_decl bool cctests_p_assert_ulong_compare (unsigned long expected, unsigned long result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_ulong_raise (cce_destination_t L, unsigned long expected, unsigned long result,
						CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_ulong(L,EXPECTED,...)		\
  cctests_assert_equal_ulong_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_ulong_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    unsigned long const	cctests_p_expected = (EXPECTED);		\
    unsigned long const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_ulong(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_ulong_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_ulong_raise(L, cctests_p_expected, cctests_p_result, \
				   CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Assertions: long long integers.
 ** ----------------------------------------------------------------- */

cctests_decl bool cctests_p_assert_llong_compare (signed long long expected, signed long long result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_llong_raise (cce_destination_t L, signed long long expected, signed long long result,
						CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_llong(L,EXPECTED,...)		\
  cctests_assert_equal_llong_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_llong_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    signed long long const	cctests_p_expected = (EXPECTED);	\
    signed long long const	cctests_p_result   = (RESULT);		\
    static char const *cctests_p_expr     = "cctests_assert_equal_llong(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_llong_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_llong_raise(L, cctests_p_expected, cctests_p_result, \
				   CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }

/* ------------------------------------------------------------------ */

cctests_decl bool cctests_p_assert_ullong_compare (unsigned long long expected, unsigned long long result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_ullong_raise (cce_destination_t L, unsigned long long expected, unsigned long long result,
						 CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_ullong(L,EXPECTED,...)		\
  cctests_assert_equal_ullong_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_ullong_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    unsigned long long const	cctests_p_expected = (EXPECTED);	\
    unsigned long long const	cctests_p_result   = (RESULT);		\
    static char const *cctests_p_expr     = "cctests_assert_equal_ullong(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_ullong_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_ullong_raise(L, cctests_p_expected, cctests_p_result, \
				    CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Assertions: 8-bit integers.
 ** ----------------------------------------------------------------- */

cctests_decl bool cctests_p_assert_int8_compare (int8_t expected, int8_t result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_int8_raise (cce_destination_t L, int8_t expected, int8_t result,
					       CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_int8(L,EXPECTED,...)		\
  cctests_assert_equal_int8_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_int8_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    int8_t const	cctests_p_expected = (EXPECTED);		\
    int8_t const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_int8(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_int8_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_int8_raise(L, cctests_p_expected, cctests_p_result, \
				  CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }

/* ------------------------------------------------------------------ */

cctests_decl bool cctests_p_assert_uint8_compare (uint8_t expected, uint8_t result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_uint8_raise (cce_destination_t L, uint8_t expected, uint8_t result,
						CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_uint8(L,EXPECTED,...)		\
  cctests_assert_equal_uint8_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_uint8_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    uint8_t const	cctests_p_expected = (EXPECTED);		\
    uint8_t const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_uint8(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_uint8_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_uint8_raise(L, cctests_p_expected, cctests_p_result, \
				   CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Assertions: 16-bit integers.
 ** ----------------------------------------------------------------- */

cctests_decl bool cctests_p_assert_int16_compare (int16_t expected, int16_t result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_int16_raise (cce_destination_t L, int16_t expected, int16_t result,
						CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_int16(L,EXPECTED,...)		\
  cctests_assert_equal_int16_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_int16_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    int16_t const	cctests_p_expected = (EXPECTED);		\
    int16_t const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_int16(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_int16_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_int16_raise(L, cctests_p_expected, cctests_p_result, \
				   CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }

/* ------------------------------------------------------------------ */

cctests_decl bool cctests_p_assert_uint16_compare (uint16_t expected, uint16_t result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_uint16_raise (cce_destination_t L, uint16_t expected, uint16_t result,
						 CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_uint16(L,EXPECTED,...)		\
  cctests_assert_equal_uint16_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_uint16_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    uint16_t const	cctests_p_expected = (EXPECTED);		\
    uint16_t const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_uint16(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_uint16_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_uint16_raise(L, cctests_p_expected, cctests_p_result, \
				    CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Assertions: 32-bit integers.
 ** ----------------------------------------------------------------- */

cctests_decl bool cctests_p_assert_int32_compare (int32_t expected, int32_t result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_int32_raise (cce_destination_t L, int32_t expected, int32_t result,
						CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_int32(L,EXPECTED,...)		\
  cctests_assert_equal_int32_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_int32_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    int32_t const	cctests_p_expected = (EXPECTED);		\
    int32_t const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_int32(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_int32_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_int32_raise(L, cctests_p_expected, cctests_p_result, \
				   CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }

/* ------------------------------------------------------------------ */

cctests_decl bool cctests_p_assert_uint32_compare (uint32_t expected, uint32_t result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_uint32_raise (cce_destination_t L, uint32_t expected, uint32_t result,
						 CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_uint32(L,EXPECTED,...)		\
  cctests_assert_equal_uint32_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_uint32_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    uint32_t const	cctests_p_expected = (EXPECTED);		\
    uint32_t const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_uint32(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_uint32_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_uint32_raise(L, cctests_p_expected, cctests_p_result, \
				    CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Assertions: 64-bit integers.
 ** ----------------------------------------------------------------- */

cctests_decl bool cctests_p_assert_int64_compare (int64_t expected, int64_t result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_int64_raise (cce_destination_t L, int64_t expected, int64_t result,
						CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_int64(L,EXPECTED,...)		\
  cctests_assert_equal_int64_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_int64_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    int64_t const	cctests_p_expected = (EXPECTED);		\
    int64_t const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_int64(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_int64_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_int64_raise(L, cctests_p_expected, cctests_p_result, \
				   CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }

/* ------------------------------------------------------------------ */

cctests_decl bool cctests_p_assert_uint64_compare (uint64_t expected, uint64_t result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_uint64_raise (cce_destination_t L, uint64_t expected, uint64_t result,
						 CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_uint64(L,EXPECTED,...)		\
  cctests_assert_equal_uint64_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_uint64_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    uint64_t const	cctests_p_expected = (EXPECTED);		\
    uint64_t const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_uint64(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_uint64_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_uint64_raise(L, cctests_p_expected, cctests_p_result, \
				    CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Assertions: floating point numbers.
 ** ----------------------------------------------------------------- */

cctests_decl bool cctests_p_assert_float_compare (float expected, float result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_float_raise (cce_destination_t L, float expected, float result,
						CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_float(L,EXPECTED,...)		\
  cctests_assert_equal_float_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_float_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    float const	cctests_p_expected = (EXPECTED);			\
    float const	cctests_p_result   = (RESULT);				\
    static char const *cctests_p_expr     = "cctests_assert_equal_float(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_float_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_float_raise(L, cctests_p_expected, cctests_p_result, \
				   CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }

/* ------------------------------------------------------------------ */

cctests_decl bool cctests_p_assert_double_compare (double expected, double result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_double_raise (cce_destination_t L, double expected, double result,
						 CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_double(L,EXPECTED,...)		\
  cctests_assert_equal_double_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_double_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    double const	cctests_p_expected = (EXPECTED);		\
    double const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_double(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_double_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_double_raise(L, cctests_p_expected, cctests_p_result, \
				    CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Assertions: memory pointers.
 ** ----------------------------------------------------------------- */

cctests_decl bool cctests_p_assert_pointer_compare (void * expected, void * result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_pointer_raise (cce_destination_t L, void * expected, void * result,
						  CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_pointer(L,EXPECTED,...)		\
  cctests_assert_equal_pointer_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_pointer_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    void * const	cctests_p_expected = (EXPECTED);		\
    void * const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_pointer(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_pointer_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_pointer_raise(L, cctests_p_expected, cctests_p_result, \
				     CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Assertions: size integers.
 ** ----------------------------------------------------------------- */

cctests_decl bool cctests_p_assert_size_compare (size_t expected, size_t result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_size_raise (cce_destination_t L, size_t expected, size_t result,
					       CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_size(L,EXPECTED,...)		\
  cctests_assert_equal_size_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_size_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    size_t const	cctests_p_expected = (EXPECTED);		\
    size_t const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_size(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_size_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_size_raise(L, cctests_p_expected, cctests_p_result, \
				  CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }

/* ------------------------------------------------------------------ */

cctests_decl bool cctests_p_assert_ssize_compare (ssize_t expected, ssize_t result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_ssize_raise (cce_destination_t L, ssize_t expected, ssize_t result,
						CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_ssize(L,EXPECTED,...)		\
  cctests_assert_equal_ssize_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_ssize_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    ssize_t const	cctests_p_expected = (EXPECTED);		\
    ssize_t const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_ssize(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_ssize_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_ssize_raise(L, cctests_p_expected, cctests_p_result, \
				   CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Assertions: mmemory pointer differences.
 ** ----------------------------------------------------------------- */

cctests_decl bool cctests_p_assert_ptrdiff_compare (ptrdiff_t expected, ptrdiff_t result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_ptrdiff_raise (cce_destination_t L, ptrdiff_t expected, ptrdiff_t result,
						  CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_ptrdiff(L,EXPECTED,...)		\
  cctests_assert_equal_ptrdiff_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_ptrdiff_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    ptrdiff_t const	cctests_p_expected = (EXPECTED);		\
    ptrdiff_t const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_ptrdiff(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_ptrdiff_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_ptrdiff_raise(L, cctests_p_expected, cctests_p_result, \
				     CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Assertions: pointer integers.
 ** ----------------------------------------------------------------- */

cctests_decl bool cctests_p_assert_intptr_compare (intptr_t expected, intptr_t result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_intptr_raise (cce_destination_t L, intptr_t expected, intptr_t result,
						 CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_intptr(L,EXPECTED,...)		\
  cctests_assert_equal_intptr_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_intptr_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    intptr_t const	cctests_p_expected = (EXPECTED);		\
    intptr_t const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_intptr(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_intptr_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_intptr_raise(L, cctests_p_expected, cctests_p_result, \
				    CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }

/* ------------------------------------------------------------------ */

cctests_decl bool cctests_p_assert_uintptr_compare (uintptr_t expected, uintptr_t result)
  __attribute__((__pure__));

cctests_decl void cctests_p_assert_uintptr_raise (cce_destination_t L, uintptr_t expected, uintptr_t result,
						  CCTESTS_ASSERT_COMMON_SIGNATURE_ARGS)
  __attribute__((__nonnull__(1,4,5,6)));

/* This trick  with "__VA_ARGS__, NULL"  exists because  some C standard  requires at
   least one argument  to be present in  the optional arguments of  a variadic macro.
   So we use "RESULT" as such argument and add a NULL for the other, true, macro. */
#define cctests_assert_equal_uintptr(L,EXPECTED,...)		\
  cctests_assert_equal_uintptr_1(L,EXPECTED,__VA_ARGS__,NULL)

/* In the  expansion of this  macro: the symbol "__LINE__"  must appear in  the first
   line. */
#define cctests_assert_equal_uintptr_1(L,EXPECTED,RESULT,...)		\
  { size_t const	cctests_p_linenum  = __LINE__;			\
    uintptr_t const	cctests_p_expected = (EXPECTED);		\
    uintptr_t const	cctests_p_result   = (RESULT);			\
    static char const *cctests_p_expr     = "cctests_assert_equal_uintptr(" #L ", " #EXPECTED ", " #RESULT ")"; \
    if (cctests_p_assert_uintptr_compare(cctests_p_expected, cctests_p_result)) { \
      cctests_p_assert_uintptr_raise(L, cctests_p_expected, cctests_p_result, \
				     CCTESTS_ASSERT_COMMON_CALL_ARGS(L, __VA_ARGS__)); \
    }									\
  }


/** --------------------------------------------------------------------
 ** Calling a function in a subprocess.
 ** ----------------------------------------------------------------- */

typedef void cctests_parent_process_function_t (cce_destination_t L, int64_t child_pid);
typedef void cctests_child_process_function_t (cce_destination_t L);

cctests_decl void cctests_call_in_forked_process (cce_destination_t L, cctests_child_process_function_t * child_function)
  __attribute__((__nonnull__(1,2)));

cctests_decl void cctests_with_parent_and_child_process (cce_destination_t L,
							 cctests_parent_process_function_t * parent_function,
							 cctests_child_process_function_t * child_function)
  __attribute__((__nonnull__(1,2,3)));


/** --------------------------------------------------------------------
 ** Debugging facilities.
 ** ----------------------------------------------------------------- */

#ifndef CCTESTS_DEBUGGING
#  define CCTESTS_DEBUGGING		0
#endif
#ifndef CCTESTS_DEBUGGING_HERE
#  define CCTESTS_DEBUGGING_HERE	1
#endif

#if (CCTESTS_DEBUGGING == 1)

#  define cctests_debug_question(EXPR)		((EXPR)?"yes":"no")
#  define cctests_debug_mark()			cctests_debug_print("mark")

#  define cctests_debug_print(...)					\
  if (CCTESTS_DEBUGGING_HERE) { cctests_p_debug_print(__FILE__,__func__,__LINE__,__VA_ARGS__); }

cctests_decl void cctests_p_debug_print (const char * file, const char * function, int line, const char * template, ...)
__attribute__((__unused__,__nonnull__(1,2,4)));

#else
#  define cctests_debug_print(...)	/* empty */
#  define cctests_debug_mark()		/* empty */
#  define cctests_debug_question(...)	/* empty */
#endif


/** --------------------------------------------------------------------
 ** Helpers.
 ** ----------------------------------------------------------------- */

cctests_decl FILE * cctests_log_stream;

cctests_decl bool cctests_isatty (FILE * stream)
  __attribute__((__nonnull__(1)));

cctests_decl bool cctests_log_stream_isatty (void);

cctests_decl char const * cctests_new_dynamic_string (cce_destination_t L, char const * in_str)
  __attribute__((__nonnull__(1,2)));


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* CCTESTS_H */

/* end of file */
