/*
  Part of: CCTests
  Contents: public header file
  Date: Nov 28, 2017

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
#include <stdbool.h>


/** --------------------------------------------------------------------
 ** Constants.
 ** ----------------------------------------------------------------- */



/** --------------------------------------------------------------------
 ** Type definitions.
 ** ----------------------------------------------------------------- */

typedef void cctests_fun_t (cce_destination_t L);

/* ------------------------------------------------------------------ */

typedef struct cctests_descriptor_base_t		cctests_descriptor_base_t;
typedef struct cctests_descriptor_test_failure_t	cctests_descriptor_test_failure_t;
typedef struct cctests_descriptor_assertion_failure_t	cctests_descriptor_assertion_failure_t;

typedef struct cctests_descriptor_signal_1_t		cctests_descriptor_signal_1_t;
typedef struct cctests_descriptor_signal_2_t		cctests_descriptor_signal_2_t;
typedef struct cctests_descriptor_signal_3_t		cctests_descriptor_signal_3_t;

/* ------------------------------------------------------------------ */

typedef struct cctests_condition_base_t			cctests_condition_base_t;
typedef struct cctests_condition_test_failure_t		cctests_condition_test_failure_t;
typedef struct cctests_condition_assertion_failure_t	cctests_condition_assertion_failure_t;

typedef struct cctests_condition_signal_1_t		cctests_condition_signal_1_t;
typedef struct cctests_condition_signal_2_t		cctests_condition_signal_2_t;
typedef struct cctests_condition_signal_3_t		cctests_condition_signal_3_t;


/** --------------------------------------------------------------------
 ** Library initialisation.
 ** ----------------------------------------------------------------- */

cctests_decl void cctests_init (void)
  __attribute__((__constructor__));


/** --------------------------------------------------------------------
 ** Version functions.
 ** ----------------------------------------------------------------- */

cctests_decl char const * cctests_version_string (void);
cctests_decl int	cctests_version_interface_current (void);
cctests_decl int	cctests_version_interface_revision (void);
cctests_decl int	cctests_version_interface_age (void);


/** --------------------------------------------------------------------
 ** Condition objects.
 ** ----------------------------------------------------------------- */

struct cctests_descriptor_base_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_base_t {
  cce_condition_t	condition;
};

cctests_decl const cctests_descriptor_base_t * const cctests_descriptor_base;

__attribute__((__pure__,__nonnull__(1),__always_inline__))
static inline bool
cctests_condition_is_base (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_base->descriptor));
}

/* ------------------------------------------------------------------ */

struct cctests_descriptor_test_failure_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_test_failure_t {
  cctests_condition_base_t	base;
};

cctests_decl const cctests_descriptor_test_failure_t * const cctests_descriptor_test_failure;

cctests_decl cce_condition_t const * cctests_condition_new_test_failure (void)
  __attribute__((__leaf__,__pure__,__returns_nonnull__));

__attribute__((__pure__,__nonnull__(1),__always_inline__))
static inline bool
cctests_condition_is_test_failure (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_test_failure->descriptor));
}

/* ------------------------------------------------------------------ */

struct cctests_descriptor_assertion_failure_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_assertion_failure_t {
  cctests_condition_base_t	base;
  char const *			expr;
  char const *			filename;
  char const *			funcname;
  int				linenum;
};

cctests_decl const cctests_descriptor_assertion_failure_t * const cctests_descriptor_assertion_failure;

cctests_decl cce_condition_t const * cctests_condition_new_assertion_failure (char const * const expr,
									      char const * const filename,
									      char const * const funcname,
									      int const linenum)
  __attribute__((__leaf__,__nonnull__(1,2,3),__returns_nonnull__));

__attribute__((__pure__,__nonnull__(1),__always_inline__))
static inline bool
cctests_condition_is_assertion_failure (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_assertion_failure->descriptor));
}

/* ------------------------------------------------------------------ */

struct cctests_descriptor_signal_1_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_signal_1_t {
  cctests_condition_base_t	base;
};

cctests_decl const cctests_descriptor_signal_1_t * const cctests_descriptor_signal_1;

cctests_decl cce_condition_t const * cctests_condition_new_signal_1 (void)
  __attribute__((__leaf__,__pure__,__returns_nonnull__));

__attribute__((__pure__,__nonnull__(1),__always_inline__))
static inline bool
cctests_condition_is_signal_1 (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_signal_1->descriptor));
}

/* ------------------------------------------------------------------ */

struct cctests_descriptor_signal_2_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_signal_2_t {
  cctests_condition_base_t	base;
};

cctests_decl const cctests_descriptor_signal_2_t * const cctests_descriptor_signal_2;

cctests_decl cce_condition_t const * cctests_condition_new_signal_2 (void)
  __attribute__((__leaf__,__pure__,__returns_nonnull__));

__attribute__((__pure__,__nonnull__(1),__always_inline__))
static inline bool
cctests_condition_is_signal_2 (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_signal_2->descriptor));
}

/* ------------------------------------------------------------------ */

struct cctests_descriptor_signal_3_t {
  cce_descriptor_t	descriptor;
};

struct cctests_condition_signal_3_t {
  cctests_condition_base_t	base;
};

cctests_decl const cctests_descriptor_signal_3_t * const cctests_descriptor_signal_3;

cctests_decl cce_condition_t const * cctests_condition_new_signal_3 (void)
  __attribute__((__leaf__,__pure__,__returns_nonnull__));

__attribute__((__pure__,__nonnull__(1),__always_inline__))
static inline bool
cctests_condition_is_signal_3 (cce_condition_t const * C)
{
  return cce_is_condition(C, &(cctests_descriptor_signal_3->descriptor));
}


/** --------------------------------------------------------------------
 ** System interface.
 ** ----------------------------------------------------------------- */

cce_decl void * cctests_sys_malloc (cce_destination_t L, size_t size)
  __attribute__((__nonnull__(1),__returns_nonnull__));

cce_decl void * cctests_sys_realloc (cce_destination_t L, void * ptr, size_t newsize)
  __attribute__((__nonnull__(1),__returns_nonnull__));

cce_decl void * cctests_sys_calloc (cce_destination_t L, size_t count, size_t eltsize)
  __attribute__((__nonnull__(1),__returns_nonnull__));


/** --------------------------------------------------------------------
 ** Predefined POSIX exception handler: malloc pointer.
 ** ----------------------------------------------------------------- */

cce_decl void cctests_cleanup_handler_malloc_init (cce_destination_t L, cce_handler_t * H, void * pointer)
  __attribute__((__nonnull__(1,2,3)));

cce_decl void cctests_error_handler_malloc_init (cce_destination_t L, cce_handler_t * H, void * pointer)
  __attribute__((__nonnull__(1,2,3)));


/** --------------------------------------------------------------------
 ** Test driver.
 ** ----------------------------------------------------------------- */

cctests_decl void cctests_begin_group (char const * const test_group_name);
cctests_decl void cctests_end_group   (void);

cctests_decl void cctests_p_run (char const * funcname, cctests_fun_t * fun);
#define cctests_run(FUNCNAME)	cctests_p_run(#FUNCNAME, FUNCNAME)

cctests_decl bool cctests_latest_group_completed_successfully (void);


/** --------------------------------------------------------------------
 ** Assertions API.
 ** ----------------------------------------------------------------- */

#define cctests_assert(EXPR)	cctests_p_assert(#EXPR, EXPR, __FILE__, __func__, __LINE__)

cctests_decl void cctests_p_assert (char const * const expr, bool result,
				    char const * const filename, char const * const funcname, int const linenum);


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* CCTESTS_H */

/* end of file */
