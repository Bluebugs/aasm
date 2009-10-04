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

#include "aasm/size.h"
#include "aasm/object.h"
#include "aasm/error.h"

#include "asm.h"

/*
** EXPORTED FUNCTION
** Return CPU endian permutation table
*/

const unsigned int	*
asm_skel_endian_permut	(unsigned int			byte_size)
{
  /* little endian table
  static const unsigned int	little_endian[AASM_MAX_VAL_SIZE] =
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

  return (little_endian);
  */

  /* big endian table */
  static const unsigned int	big_endian[AASM_MAX_VAL_SIZE] =
    {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

  return (&big_endian[AASM_MAX_VAL_SIZE - byte_size]);
}

/*
** EXPORTED FUNCTION
** Return instruction name from info structure
*/

const char		*
asm_skel_instr_name	(const struct instr_info_s	*instr)
{
  return (instr->name);
}

/*
** EXPORTED FUNCTION
** Return instruction max binary size (used for memory allocation)
*/

unsigned int
asm_skel_max_binary_size(const struct instr_info_s	*instr)
{
  return (1);			/* UPDATE THIS LINE */
}

/*
** EXPORTED FUNCTION (Optional)
** Asm module directive callback function
*/

void
asm_skel_directive	(struct object_s		*obj,
			 const char			*param)
{
  if (!obj->cur_section)
    {
      error(ERRTYP_ERROR, "x86: no section defined before .mod_asm directive", 0);
      return;
    }

  /* ASM MODULE DIRECTIVES CODE HERE */

  error(ERRTYP_ERROR, "asm_skeleton: unknown .mod_asm directive for skeleton module", 0);
}

