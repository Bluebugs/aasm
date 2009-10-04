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

#include <stdlib.h>

#include "aasm/error.h"
#include "aasm/reloc.h"
#include "aasm/section.h"
#include "aasm/object.h"

#include "out.h"

void
skel_process_relocs	(struct object_s		*obj,
			 struct out_object_s		*out_obj)
{
  struct section_s	*sec;

  for (sec = obj->section_first; sec; sec = sec->next)
    {
      struct reloc_s	*reloc;

      for (reloc = sec->reloc; reloc; reloc = reloc->next)
	{

	  /* INSERT CODE HERE */

	}
    }
}

