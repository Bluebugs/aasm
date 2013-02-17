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
**    contact : alexandre.becoulet@free.fr
*/

#include <string.h>
#include <stdio.h>

#include "aasm/types.h"
#include "aasm/memory.h"
#include "aasm/object.h"

#include "out.h"

# ifdef FIXME_HANDLE_SECTIONS

struct out_section_s	*
skel_section_new	(struct out_object_s	*out_obj)
{
  struct out_section_s	*out_section = mem_pop(&out_obj->sec_pool);

  memset(out_section, 0, sizeof (struct out_section_s));

  /* insert section to list */
  if (out_obj->section_first)
    out_obj->section_last->next = out_section;
  else
    out_obj->section_first = out_section;

  out_obj->section_last = out_section;

  return (out_section);
}

struct out_section_s	*
out_skel_newsection	(struct object_s		*obj,
			 struct section_s		*sec)
{
  /* creat skel section */
  return (skel_section_new(obj->out_obj));
}

aasm_u8_t		*
skel_section_alloc	(struct out_section_s	*out_sec,
			 unsigned int		len)
{
  if (!out_sec->data)
    out_sec->data = xmalloc(out_sec->alloc_size =
			      len + OUT_REALLOC_SIZE);
  else
    {
      if (len > (out_sec->alloc_size - out_sec->size))
	out_sec->data = xrealloc(out_sec->data,
				   out_sec->alloc_size =
				   out_sec->size
				   + len + OUT_REALLOC_SIZE);
    }

  out_sec->size += len;

  return (out_sec->data);
}

#endif

