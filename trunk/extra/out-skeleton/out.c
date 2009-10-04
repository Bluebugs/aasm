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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "aasm/disp.h"
#include "aasm/error.h"
#include "aasm/object.h"
#include "aasm/reloc.h"
#include "aasm/info.h"
#include "aasm/memory.h"
#include "aasm/alloc.h"

#include "out.h"

#ifdef FIXME_HANDLE_OBJECT

struct out_object_s	*
out_skel_newobject	(struct object_s	*obj)
{
  struct out_object_s	*out_obj;

  /* creat out object on first call */
  out_obj = xzalloc(sizeof (struct out_object_s));

  /* init out_section & out_symbol alloc pools */

# ifdef FIXME_HANDLE_SECTIONS
  mem_init(&out_obj->sec_pool, sizeof (struct out_section_s));
# endif

# ifdef FIXME_HANDLE_SYMBOLS
  mem_init(&out_obj->sym_pool, sizeof (struct out_symbol_s));
# endif

  return (out_obj);
}

void
out_skel_clean		(struct object_s	*obj)
{
  struct out_section_s		*out_sec;

# ifdef FIXME_HANDLE_SECTIONS
  for (out_sec = obj->out_obj->section_first;
       out_sec; out_sec = out_sec->next)
    {
      if (out_sec->data)
	free(out_sec->data);
    }
# endif

  mem_clean(&obj->out_obj->sec_pool);

# ifdef FIXME_HANDLE_SYMBOLS
  mem_clean(&obj->out_obj->sym_pool);
# endif

  free(obj->out_obj);
}

#endif

static int
skel_write		(struct object_s	*obj,
			 FILE			*file)
{

#ifdef FIXME_IS_ARCH_DEPENDANT
# ifdef FIXME_HANDLE_OBJECT

  /* get architecture specific elf information */
  if (!(obj->out_obj->arch = skel_get_arch(obj->arch_id)))
    {
      error(ERRTYP_ERROR, "skel: unknown target architecture", 0);
      return (1);
    }

# endif
#endif

  /* INSERT CODE HERE */

  if (error_count_g)
    return (1);

# ifdef FIXME_NOTFLAT_BINARY
  if (obj->flag & OBJECT_BASEADDR)
    error(ERRTYP_WARN, "skel: object base address ignored", NULL);
# endif

  /* INSERT CODE HERE */

  return (0);
}

int
out_skel_write		(struct object_s	*obj)
{
  char		filename[512];
  FILE		*file;
  int		res = -1;

  sprintf(filename, "%s.o", obj->name);
  disp_info(stdout, "writing", filename);

  if ((file = fopen(filename, "w+b")))
    {
      if (!(res = skel_write(obj, file)))
	{
	  fclose(file);
	  return (0);
	}
      unlink(filename);
      fclose(file);
    }

  if (res < 0)
    error_submsg(error(ERRTYP_ERROR,
		       "skel: output error, can't write `%s'",
		       NULL), filename);

  return (-1);
}

void
out_skel_directive	(struct object_s	*obj,
			 const char		*param)
{
  error(ERRTYP_ERROR, "skel: unknown .mod_out directive", 0);
}

