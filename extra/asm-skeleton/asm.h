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

#ifndef ASM_H_
# define ASM_H_

#include "aasm/types.h"
#include "aasm/mod_asm_import.h"

/*** regsiter descriptor struct ***/

struct				register_s
{
  const char			*name;		/* register name */
  unsigned int			size_flag;	/* register size flag */

  /* MISC DATA FIELDS ABOUT REGISTER HERE */
};

/*** opcode descriptor struct ***/

struct				instr_info_s
{
  const char			*name;		/* instruction name */
  unsigned int			id;

  aasm_u8_t			fix[4];		/* fixed binary data */

  /* MISC DATA FIELDS ABOUT INSTRUCTION HERE */
};

/*** exported fonction prototypes ***/

asm_get_instr_perf_t	asm_skel_get_instr_perf;
asm_get_reg_t		asm_skel_get_reg;
asm_process_t		asm_skel_process;
asm_reg_size_t		asm_skel_reg_size;
asm_reg_name_t		asm_skel_reg_name;
asm_instr_name_t	asm_skel_instr_name;
asm_max_binary_size_t	asm_skel_max_binary_size;
asm_instr_help_t	asm_skel_instr_help;
asm_directive_t		asm_skel_directive;
asm_endian_permut_t	asm_skel_endian_permut;

#endif

