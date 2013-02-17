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

#include <stdlib.h>

#include "aasm/error.h"
#include "aasm/expr.h"
#include "aasm/reloc.h"
#include "aasm/arch_id.h"

#include "out.h"

# ifdef FIXME_IS_ARCH_DEPENDANT

static unsigned int
skel_reltype_foo	(struct reloc_s		*rel)
{
  return (0);
}

static unsigned int
skel_reltype_bar	(struct reloc_s		*rel)
{
  return (0);
}

const struct out_arch_s	*
skel_get_arch		(unsigned int		arch_id)
{
  static const struct out_arch_s	archs[2] =
    {
      /* little endian target example */
      {&skel_write_ulsb16, &skel_write_ulsb32,
       &skel_write_ulsb64, &skel_reltype_foo},

      /* big endian target example */
      {&skel_write_umsb16, &skel_write_umsb32,
       &skel_write_umsb64, &skel_reltype_bar},
    };

  switch (arch_id)
    {
    case (ARCH_ID_X86):
      return (&archs[0]);

    default:
      return (NULL);
    }
}

#endif

