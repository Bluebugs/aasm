
EXTRA_DIST=aasm asm-sparc asm-x86 in-parser out-coff out-elf

all:

test: $(foreach d,$(subdirs),$(d)/test)

%/test:
	$(MAKE) -C $* test
