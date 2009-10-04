
ACLOCAL_AMFLAGS = -I build

SUBDIRS = libcore aasm asm-sparc asm-x86 out-binary out-coff out-elf out-intelhex out-src in-parser tests include doc

EXTRA_DIST = bootstrap build/word_lex.pl

test:
	$(MAKE) -C tests test
