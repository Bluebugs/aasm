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

#include "aasm/section.h"
#include "aasm/error.h"
#include "aasm/expr.h"

#include "asm.h"

void
asm_skel_process	(struct instr_s		*instr,
			 struct section_s	*sec)
{
  unsigned int		i;

  /* reduce each operand expression */
  for (i = 0; i < instr->op_count; i++)
    if (expr_reduce(&instr->operands[i]))
      return;

  /* INSTRUCTION ASSEMBLING CODE HERE

  memcpy(instr->val.bin, bin_data, bin_size)
  instr_set_asm(instr, bin_size);

  return;

  */

  error_submsg(error(ERRTYP_ERROR,
		     "asm_skeleton: no matching `%s' form found",
		     instr->location), instr->info->name);
}

