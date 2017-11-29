/*
  Part of: CCTests
  Contents: utility definitions for tests
  Date: Nov 29, 2017

  Abstract

	Test file for version functions.

  Copyright (C) 2017 Marco Maggi <marco.maggi-ipsu@poste.it>

  See the COPYING file.
*/

#include <stdio.h>
#include <stdlib.h>

#define test_assert(EXPR)	test_p_assert(#EXPR, EXPR,__FILE__,  __func__, __LINE__)

static void
test_p_assert (char const * const expr, bool result, char const * const filename, char const * const funcname, int const linenum)
{
  if (false == result) {
    fprintf(stderr, "%s: %s: line %d: assertion failure: %s\n",
	    filename, funcname, linenum, expr);
    exit(EXIT_FAILURE);
  }
}

/* end of file */
