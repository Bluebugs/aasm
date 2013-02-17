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

#include "aasm/modules.h"
#include "aasm/arch_id.h"

#ifdef AASM_STATIC
static const struct module_info_s	out_skel_module_info =
#else
const struct module_info_s		module_info =
#endif
{
  1,
  "out-skel",
  "Alexandre Becoulet 2002",
  "Output module skeleton",
  {0, 9, 1},
  ARCH_ID_NONE,
  MODULE_CLASS_OUT,
  0
};

#ifdef AASM_STATIC

#include "out.h"

struct module_s				out_skel_module =
{
  &out_skel_module_info,
  0,
  0,
  NULL,
  NULL,
  {
    {
      (void*)&out_skel_write,
      (void*)&out_skel_directive,

# ifdef FIXME_HANDLE_OBJECT
      (void*)&out_skel_newobject,
# else
      NULL,
# endif

# ifdef FIXME_HANDLE_SECTIONS
      (void*)&out_skel_newsection,
# else
      NULL,
# endif

# ifdef FIXME_HANDLE_SYMBOLS
      (void*)&out_skel_newsymbol,
# else
      NULL,
# endif

# ifdef FIXME_HANDLE_OBJECT
      (void*)&out_skel_clean,
# else
      NULL,
# endif
    }
  }
};

#endif

