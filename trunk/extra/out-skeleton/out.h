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

#ifndef ELF32_H_
# define ELF32_H_

#include "aasm/types.h"
#include "aasm/arch_id.h"
#include "aasm/mod_out_import.h"
#include "aasm/memory.h"

#define FIXME_IS_ARCH_DEPENDANT
#define FIXME_HANDLE_OBJECT
#define FIXME_HANDLE_SECTIONS
#define FIXME_HANDLE_SYMBOLS
#define FIXME_HANDLE_RELOCS

struct					object_s;
struct					reloc_s;

/*
** Architecture specific informations and functions
** provide write function with correct endian and
** relocation ID.
**
** These functions depend on target architecture and
** have to be set on object creation or before processing
*/

# ifdef FIXME_IS_ARCH_DEPENDANT

struct					out_arch_s
{
  /* endian dependant write funstions */
  void					(*write_16)(void		*ptr,
						    aasm_u32_t		val);
  void					(*write_32)(void		*ptr,
						    aasm_u32_t		val);
  void					(*write_64)(void		*ptr,
						    aasm_u32_t		val);

#  ifdef FIXME_HANDLE_RELOCS

  /* return output format relocations type from relocation */
  unsigned int				(*get_rtype)(struct reloc_s	*rel);

#  endif /* FIXME_HANDLE_RELOCS */
};

# endif /* FIXME_IS_ARCH_DEPENDANT */




# ifdef FIXME_HANDLE_SYMBOLS

struct					out_symbol_s
{
  struct symbol_s			*next;

  /* ADD MORE FIELD HERE */

};

# define OUT_SYMBOL_HASH_SIZE		1024

# endif /* FIXME_HANDLE_SYMBOLS */




/*
** Output section descriptor
*/

# ifdef FIXME_HANDLE_SECTIONS

struct					out_section_s
{
  aasm_u8_t				*data;
  unsigned int				alloc_size;
  unsigned int				size;

  struct out_section_s			*next;

  /* ADD MORE FIELD HERE */
};

# define OUT_REALLOC_SIZE		4096

# endif /* FIXME_HANDLE_SECTIONS */





/*
** Output object descriptor
*/

# ifdef FIXME_HANDLE_OBJECT

struct					out_object_s
{
#  ifdef FIXME_HANDLE_SECTIONS

  /* output sections allocation pool*/
  struct mem_s				sec_pool;

  struct out_section_s			*section_first;
  struct out_section_s			*section_last;

  unsigned int				section_count;

#  endif /* FIXME_HANDLE_SECTIONS */

#  ifdef FIXME_HANDLE_SYMBOLS

  /* output symbols allocation pool */
  struct mem_s				sym_pool;

  unsigned int				symbol_count;

# endif /* FIXME_HANDLE_SYMBOLS */

  /* pointer to architecture specific structure */
  const struct out_arch_s		*arch;

  /* ADD MORE FIELD HERE */
};

# endif /* FIXME_HANDLE_OBJECT */



/*
** functions declarations
*/

# ifdef FIXME_HANDLE_RELOCS

/* skel_reloc.c */

void
skel_process_relocs	(struct object_s	*obj,
			 struct out_object_s	*out_obj);

# endif /* FIXME_HANDLE_RELOCS */


# ifdef FIXME_HANDLE_SYMBOLS

/* skel_symbols.c file */

void
skel_process_symbols	(struct object_s	*obj,
			 struct out_object_s	*out_obj);

# endif /* FIXME_HANDLE_SYMBOLS */



# ifdef FIXME_HANDLE_SECTIONS

/* skel_sections.c file */

struct out_section_s	*
skel_section_new	(struct out_object_s	*out_obj);

aasm_u8_t		*
skel_section_alloc	(struct out_section_s	*out_sec,
			 unsigned int		len);

# endif /* FIXME_HANDLE_SECTIONS */



/* skel_arch.c file */

const struct out_arch_s	*
skel_get_arch		(unsigned int		arch_id);

/* skel_endian.c file */

void
skel_write_ulsb64	(void			*ptr,
			 aasm_u32_t		val);

void
skel_write_umsb64	(void			*ptr,
			 aasm_u32_t		val);

void
skel_write_ulsb32	(void			*ptr,
			 aasm_u32_t		val);

void
skel_write_umsb32	(void			*ptr,
			 aasm_u32_t		val);

void
skel_write_ulsb16	(void			*ptr,
			 aasm_u32_t		val);

void
skel_write_umsb16	(void			*ptr,
			 aasm_u32_t		val);


/*
** exported module functions declaration
*/

out_write_t		out_skel_write;
out_directive_t		out_skel_directive;
out_newobject_t		out_skel_newobject;
out_newsection_t	out_skel_newsection;
out_newsymbol_t		out_skel_newsymbol;
out_clean_t		out_skel_clean;

#endif

