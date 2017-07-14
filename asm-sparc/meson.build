instr_opcode = [  ]

instr_perf = custom_target('perl gen_opcode sparc',
    input: ['gen_opcodes.pl',
        'opcodes_v8_arith.list',
        'opcodes_v8_branch.list',
        'opcodes_v8_float.list',
        'opcodes_v8_logical.list',
        'opcodes_v8_misc.list',
        'opcodes_v8_storeload.list',
        'opcodes_v9.list',
        'instr.skel'],
    output: ['instr.perf', 'opcodes_id.h', 'opcodes.h'],
    command: [ perl, '@INPUT@', '@OUTPUT@' ])

instr_option = run_command(gperf_options, '@0@/instr.skel'.format(meson.current_source_dir())).stdout().split(' ')
instr = custom_target('gperf sparc instr.perf',
    input: instr_perf,
    output: 'instr.c',
    command: [ gperf, instr_option, '-k*', '@INPUT0@', '--output-file', '@OUTPUT@' ])

reg_options = run_command(gperf_options, '@0@/reg.perf'.format(meson.current_source_dir())).stdout().split(' ')
reg = custom_target('gperf sparc reg.perf',
    input: 'reg.perf',
    output: 'reg.c',
    command: [ gperf, reg_options, '-k*', '@INPUT@', '--output-file', '@OUTPUT@' ])

asm_directive = custom_target('perl word_lex.pl sparc',
    input: [ word_lex, 'asm_directive.wlex' ],
    output: [ 'asm_directive.c' ],
    command: [ perl, '@INPUT@', '@OUTPUT@' ])

src_lib = [ 'asm.c',
    'asm_help.c',
    'asm_process.c',
    'asm_reloc.c',
    'module.c',
    'asm.h' ]

dep_bin = shared_library('aasm_asm-sparc',
    src_lib, asm_directive, instr, reg,
    link_with: aasm_core,
    c_args: cflags,
    include_directories : [ include_directories('../include') ],
    install: true)
