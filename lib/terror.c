/* $Id: $ */

/* Copyright (C) 1997 Sverre Hvammen Johansen,
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
#include "config.h"

#include <stdio.h>
#if STDC_HEADERS
#include <stdlib.h>
#endif

/******************************************************************************
                                                      PROCEDURE TERROR	     */

void __rterror (__txtvp t)
{
  long i;
  __rprintfilline ();
  (void) fprintf (stderr, "RUNTIME-ERROR: ");
  for (i = t->start; i < t->start + t->length; i++)
    (void) putc (t->obj->string[i - 1], stderr);
  (void) putc ('\n', stderr);
#ifndef lint
  exit (1);
#endif
}
