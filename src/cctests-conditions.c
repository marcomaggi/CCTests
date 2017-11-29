/*
  Part of: CCTests
  Contents: condition objects
  Date: Nov 28, 2017

  Abstract



  Copyright (C) 2017 Marco Maggi <marco.maggi-ipsu@poste.it>

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


/** --------------------------------------------------------------------
 ** Base exceptional condition descriptor.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	descriptor_base_static_message;

static cctests_descriptor_base_t descriptor_base = {
  /* This "parent" field is set by the initialisation function. */
  .descriptor.parent		= NULL,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= descriptor_base_static_message
};

cctests_descriptor_base_t const * const cctests_descriptor_base = &descriptor_base;

const char *
descriptor_base_static_message (cce_condition_t const * C CCTESTS_UNUSED)
{
  return "CCTests exceptional condition";
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: test failure.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	condition_test_failure_static_message;

static cctests_descriptor_test_failure_t descriptor_test_failure = {
  .descriptor.parent		= &descriptor_base.descriptor,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= condition_test_failure_static_message
};

cctests_descriptor_test_failure_t const * const cctests_descriptor_test_failure = &descriptor_test_failure;

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_test_failure_t const condition_test_failure = {
  .base.condition.descriptor	= &descriptor_test_failure.descriptor
};

cce_condition_t const *
cctests_condition_new_test_failure (void)
{
  return (cce_condition_t *)&condition_test_failure;
}

char const *
condition_test_failure_static_message (cce_condition_t const * C CCTESTS_UNUSED)
{
  return "CCTests assertion failure";
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: failed assertion.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	condition_assertion_failure_static_message;
static cce_condition_delete_fun_t		condition_assertion_failure_delete;

static cctests_descriptor_assertion_failure_t descriptor_assertion_failure = {
  .descriptor.parent		= &descriptor_base.descriptor,
  .descriptor.delete		= condition_assertion_failure_delete,
  .descriptor.final		= NULL,
  .descriptor.static_message	= condition_assertion_failure_static_message
};

cctests_descriptor_assertion_failure_t const * const cctests_descriptor_assertion_failure = &descriptor_assertion_failure;

cce_condition_t const *
cctests_condition_new_assertion_failure (char const * const expr,
					 char const * const filename,
					 char const * const funcname,
					 int const linenum)
{
  cctests_condition_assertion_failure_t *	C = malloc(sizeof(cctests_condition_assertion_failure_t));
  C->base.condition.descriptor	= &descriptor_assertion_failure.descriptor;
  C->expr			= expr;
  C->filename			= filename;
  C->funcname			= funcname;
  C->linenum			= linenum;
  return (cce_condition_t *)C;
}

void
condition_assertion_failure_delete (cce_condition_t * C)
{
  free(C);
}

char const *
condition_assertion_failure_static_message (cce_condition_t const * C CCTESTS_UNUSED)
{
  return "CCTests assertion failure";
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: signal one.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	condition_signal_1_static_message;

static cctests_descriptor_signal_1_t descriptor_signal_1 = {
  .descriptor.parent		= &descriptor_base.descriptor,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= condition_signal_1_static_message
};

cctests_descriptor_signal_1_t const * const cctests_descriptor_signal_1 = &descriptor_signal_1;

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_signal_1_t const condition_signal_1 = {
  .base.condition.descriptor	= &descriptor_signal_1.descriptor
};

cce_condition_t const *
cctests_condition_new_signal_1 (void)
{
  return (cce_condition_t *)&condition_signal_1;
}

char const *
condition_signal_1_static_message (cce_condition_t const * C CCTESTS_UNUSED)
{
  return "CCTests exception signal 1";
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: signal two.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	condition_signal_2_static_message;

static cctests_descriptor_signal_2_t descriptor_signal_2 = {
  .descriptor.parent		= &descriptor_base.descriptor,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= condition_signal_2_static_message
};

cctests_descriptor_signal_2_t const * const cctests_descriptor_signal_2 = &descriptor_signal_2;

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_signal_2_t const condition_signal_2 = {
  .base.condition.descriptor	= &descriptor_signal_2.descriptor
};

cce_condition_t const *
cctests_condition_new_signal_2 (void)
{
  return (cce_condition_t *)&condition_signal_2;
}

char const *
condition_signal_2_static_message (cce_condition_t const * C CCTESTS_UNUSED)
{
  return "CCTests exception signal 2";
}


/** --------------------------------------------------------------------
 ** Exceptional condition descriptor: signal three.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	condition_signal_3_static_message;

static cctests_descriptor_signal_3_t descriptor_signal_3 = {
  .descriptor.parent		= &descriptor_base.descriptor,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= condition_signal_3_static_message
};

cctests_descriptor_signal_3_t const * const cctests_descriptor_signal_3 = &descriptor_signal_3;

/* This struct type has no dynamic fields, so there is only one instance
   of this struct type.  We allocate it statically. */
static cctests_condition_signal_3_t const condition_signal_3 = {
  .base.condition.descriptor	= &descriptor_signal_3.descriptor
};

cce_condition_t const *
cctests_condition_new_signal_3 (void)
{
  return (cce_condition_t *)&condition_signal_3;
}

char const *
condition_signal_3_static_message (cce_condition_t const * C CCTESTS_UNUSED)
{
  return "CCTests exception signal 3";
}


/** --------------------------------------------------------------------
 ** Module initialisation.
 ** ----------------------------------------------------------------- */

void
cctests_conditions_module_initialisation (void)
{
  cce_descriptor_set_root_parent(&descriptor_base.descriptor);
}

/* end of file */
