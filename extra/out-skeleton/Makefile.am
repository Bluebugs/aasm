
NAME = myformat

lib_LTLIBRARIES = aasm_out-$(NAME).la

aasm_out_$(NAME)_la_SOURCES = module.c out_arch.c out.c out_endian.c	\
out_reloc.c out_sections.c out_symbols.c out.h

aasm_out_$(NAME)_la_LDFLAGS  = -module -avoid-version
aasm_out_$(NAME)_la_LIBADD   = $(top_builddir)/libcore/libaasm_core.la

aasm_out_$(NAME)_la_CFLAGS = -I$(top_srcdir)/include

