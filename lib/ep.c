/* $Id: $ */

/* Copyright (C) 1997 Sverre Hvammen Johansen and Terje Mjoes,
 * Department of Informatics, University of Oslo.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "cim.h"
#include "align.h"
#include "config.h"

#if STDC_HEADERS || HAVE_STRING_H
#include <string.h>
#else
#include <strings.h>
#endif

/******************************************************************************
                                                        RutineEndProcedure   */

void __rep (void)
{
  __dhp x;
  long size;
  __goto.ent = __pb->ex.ent;
  __goto.ment = __pb->ex.ment;
  x = __pb;
  size = __pb->pp->size;
  __pb = __pb->dl;
  if (__pb->pp == (__pty) __ACTS)
    __rrs ();
  __lb = __pb;
  while (__lb->pm || __lb->pp == (__pty) __ACTS)
    __lb = __lb->dl;
  /* Frigj|r memory */
  if ((char *) __fri == (((char *) x) + align (size)) 
      || __roa ((__dhp) ((char *) x + align (size))))
    {
      memset ((char *) x, 0, (char *) __fri - (char *) x);
      __fri = x;
    }
}
