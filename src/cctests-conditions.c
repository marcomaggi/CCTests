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
 ** Exceptional condition descriptor: not enough items in list.
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
  return "not enough items in list";
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
