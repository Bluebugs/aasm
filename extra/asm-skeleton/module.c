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
**    Copyright:
**    contact  :
*/

#include "aasm/modules.h"
#include "aasm/arch_id.h"

#ifdef AASM_STATIC
static const struct module_info_s	asm_skel_module_info =
#else
const struct module_info_s		module_info =
#endif
{
  1,
  "asm-skel",
  "Alexandre Becoulet 2002",
  "Asm module skeleton",
  {0, 9, 0},
  ARCH_ID_NONE,
  MODULE_CLASS_ASM,
  0
};

#ifdef AASM_STATIC

#include "asm.h"

struct module_s				asm_skel_module =
{
  &asm_skel_module_info,
  0,
  0,
  NULL,
  NULL,
  {
    {
      (void*)&asm_skel_get_instr_perf,
      (void*)&asm_skel_get_reg,
      (void*)&asm_skel_process,
      (void*)&asm_skel_reg_size,
      (void*)&asm_skel_reg_name,
      (void*)&asm_skel_instr_name,
      (void*)&asm_skel_max_binary_size,
      (void*)&asm_skel_instr_help,	/* optional */
      (void*)&asm_skel_directive,	/* optional */
      (void*)&asm_skel_endian_permut,
    }
  }
};

#endif

