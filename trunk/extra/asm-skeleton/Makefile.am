
NAME = mycpu

lib_LTLIBRARIES = aasm_asm-$(NAME).la

aasm_asm_$(NAME)_la_SOURCES = asm.c asm_help.c asm_process.c	\
module.c instr.c reg.c asm.h opcodes_id.h

aasm_asm_$(NAME)_la_LDFLAGS  = -module -avoid-version
aasm_asm_$(NAME)_la_LIBADD   = $(top_builddir)/libcore/libaasm_core.la
aasm_asm_$(NAME)_la_CFLAGS = -I$(top_srcdir)/include

CLEANFILES = opcodes_id.h instr.c reg.c
BUILT_SOURCES = opcodes_id.h instr.c reg.c
OPCOD_LISTS = opcodes.list

EXTRA_DIST = gen_opcodes.pl $(OPCOD_LISTS) instr.skel reg.perf

%.c: %.perf
	if $(GPERF) `grep +options+ $< | cut -f 3- -d + ` \
	   $< >$@t; then \
	  mv $@t $@; \
	elif $(GPERF) --version >/dev/null 2>&1; then \
	  rm $@t; \
	  exit 1; \
	else \
	  rm $@t; \
	  touch $@; \
	fi

instr.perf opcodes_id.h: $(srcdir)/gen_opcodes.pl $(OPCOD_LISTS) instr.skel
	test -r instr.skel || cp $(filter %.skel,$^) .
	perl $< $(filter %.list,$^)

