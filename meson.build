project('aasm', 'c', version: '0.9.2' )

### Create config.h

as_name = meson.project_name()
as_version = meson.project_version()

conf = configuration_data()
conf.set_quoted('VERSION', as_version)
conf.set_quoted('PACKAGE', as_name)
configure_file(output : 'config.h',
	       configuration : conf)

### Check dependencies

cc = meson.get_compiler('c')

gperf = find_program('gperf', required : true)
perl = find_program('perl', required : true)
grep = find_program('grep', required : true)
cut = find_program('cut', required : true)
libdl = cc.find_library('dl', required : true)
gperf_options = '@0@/gperf-options.sh'.format(meson.current_source_dir())
word_lex = '@0@/build/word_lex.pl'.format(meson.current_source_dir())

cflags = [ '-Wall', '-Wno-unused-parameter' ]
## FIXME: figure out how to get prefix from command line
cflags_lib = [ '-DHAVE_CONFIG_H', '-DAASM_PREFIX="/usr"', cflags ]

incdir = include_directories('include')

### Libraries

headers = [ 'include/aasm/alloc.h',
    'include/aasm/arch_id.h',
    'include/aasm/color.h',
    'include/aasm/comments.h',
    'include/aasm/disp.h',
    'include/aasm/error.h',
    'include/aasm/expr.h',
    'include/aasm/info.h',
    'include/aasm/instr.h',
    'include/aasm/macro.h',
    'include/aasm/memory.h',
    'include/aasm/memstruct.h',
    'include/aasm/mod_asm_import.h',
    'include/aasm/mod_in_import.h',
    'include/aasm/mod_out_import.h',
    'include/aasm/modules.h',
    'include/aasm/num.h',
    'include/aasm/object.h',
    'include/aasm/proc.h',
    'include/aasm/refcount.h',
    'include/aasm/reloc.h',
    'include/aasm/scope.h',
    'include/aasm/section.h',
    'include/aasm/size.h',
    'include/aasm/symbol.h',
    'include/aasm/types.h' ]

## Core

src_core_lib = [ 'libcore/alloc.c',
    'libcore/comments.c',
    'libcore/disp.c',
    'libcore/error.c',
    'libcore/expr.c',
    'libcore/expr_reduce.c',
    'libcore/instr.c',
    'libcore/location.c',
    'libcore/macro.c',
    'libcore/memory.c',
    'libcore/modules.c',
    'libcore/num.c',
    'libcore/num_add.c',
    'libcore/num_cmp.c',
    'libcore/num_div.c',
    'libcore/num_logical.c',
    'libcore/num_mul.c',
    'libcore/num_neg.c',
    'libcore/num_pow.c',
    'libcore/num_shift.c',
    'libcore/num_sub.c',
    'libcore/object.c',
    'libcore/oper_b_add.c',
    'libcore/oper_b_and.c',
    'libcore/oper_b_div.c',
    'libcore/oper_b_eq.c',
    'libcore/oper_b_mod.c',
    'libcore/oper_b_mul.c',
    'libcore/oper_b_or.c',
    'libcore/oper_b_pow.c',
    'libcore/oper_b_shl.c',
    'libcore/oper_b_shr.c',
    'libcore/oper_b_sub.c',
    'libcore/oper_b_xor.c',
    'libcore/oper_parentheses.c',
    'libcore/oper_u_brack.c',
    'libcore/oper_u_neg.c',
    'libcore/oper_u_not.c',
    'libcore/oper_u_plus.c',
    'libcore/oper_u_size.c',
    'libcore/proc.c',
    'libcore/refcount.c',
    'libcore/reloc.c',
    'libcore/scope.c',
    'libcore/section.c',
    'libcore/size.c',
    'libcore/string.c',
    'libcore/symbol.c' ]

aasm_core = shared_library('aasm_core',
    src_core_lib,
    dependencies: [ libdl ],
    c_args : cflags_lib,
    include_directories : incdir,
    install: true)

subdir('asm-sparc')
