/*
**    This file is part of AASM.
**
**    AASM is free software; you can redistribute it and/or modify
**    it under the terms of the GNU General Public License as published by
**    the Free Software Foundation; either version 2 of the License, or
**    (at your option) any later version.
**
**    AASM is distributed in the hope that it will be useful,
**    but WITHOUT ANY WARRANTY; without even the implied warranty of
**    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**    GNU General Public License for more details.
**
**    You should have received a copy of the GNU General Public License
**    along with AASM; if not, write to the Free Software
**    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
**
**    Copyright Alexandre Becoulet, 2002
**    contact : alexandre.becoulet@epita.fr
*/

#include <string.h>

#include "aasm/symbol.h"
#include "aasm/scope.h"
#include "aasm/section.h"
#include "aasm/proc.h"
#include "aasm/object.h"
#include "aasm/memory.h"
#include "aasm/alloc.h"

#include "out.h"

# ifdef FIXME_HANDLE_SYMBOLS

static void
skel_process_scope	(struct scope_s			*scope)
{
  unsigned int		i;

  for (i = 0; i < scope->symbol_hash_size; i++)
    {
      struct symbol_s	*sym;

      for (sym = scope->symbols[i]; sym; sym = sym->next)
	{
	  switch (sym->flag & (SYMBOL_TYPE_LABEL | SYMBOL_TYPE_PROC | SYMBOL_TYPE_EXTERN))
	    {
	    case (SYMBOL_TYPE_LABEL):
	      /* INSERT CORE HERE */
	      break;

	    case (SYMBOL_TYPE_PROC):
	      /* INSERT CORE HERE */
	      break;

	    case (SYMBOL_TYPE_EXTERN):
	      /* INSERT CORE HERE */
	      break;

	    default:
	      break;
	    }
	}
    }
}

void
skel_process_symbols	(struct object_s		*obj,
			 struct out_object_s		*out_obj)
{
  struct section_s	*sec;

  /* walk thru object symbols */

  skel_process_scope(&obj->global);

  for (sec = obj->section_first; sec; sec = sec->next)
    {
      struct proc_s	*proc;

      skel_process_scope(&sec->scope);

      for (proc = sec->proc_first; proc; proc = proc->next)
	skel_process_scope(&proc->scope);
    }
}

struct out_symbol_s	*
out_skel_newsymbol	(struct object_s		*obj,
			 struct scope_s			*sc,
			 struct symbol_s		*sym)
{
  if (sym->flag & (SYMBOL_TYPE_LABEL | SYMBOL_TYPE_PROC | SYMBOL_TYPE_EXTERN))
    {
      struct out_symbol_s	*out_sym = mem_pop(&obj->out_obj->sym_pool);

      memset(out_sym, 0, sizeof (struct out_symbol_s));
      return (out_sym);
    }

  return (NULL);
}

#endif

