project('btop', 'cpp',
  default_options : [
    'cpp_std=c++23',
    'warning_level=3',
    'b_lto=true',
  ],
  version : '1.4.5',
  meson_version : '>= 1.0.0',
)

cpp = meson.get_compiler('cpp')

foreach symbol : [
  '__cpp_fold_expressions',
  '__cpp_lib_constexpr_string',
  '__cpp_lib_constexpr_string_view',
  '__cpp_lib_ranges_contains',
  '__cpp_lib_ranges_enumerate',
  '__cpp_lib_ranges_fold',
  '__cpp_lib_ranges_to_container',
  '__cpp_lib_span',
  '__cpp_lib_starts_ends_with',
  '__cpp_lib_to_chars',
  '__cpp_range_based_for',
  '__cpp_variadic_templates',
]
  cpp.has_header_symbol('version', symbol, required : true)
endforeach

cpp_args = cpp.get_supported_arguments(
  '-Wcast-qual',
  '-Wconversion-null',
  '-Wmissing-declarations',
  '-Woverlength-strings',
  '-Wpointer-arith',
  '-Wunused-local-typedefs',
  '-Wunused-result',
  '-Wvarargs',
  '-Wvla',
  '-Wwrite-strings',
)

target_sources = []

subdir('src')

fmt = subproject('fmt', default_options : ['header-only=true'])
fmt_dep = fmt.get_variable('fmt_header_only_dep')

widecharwidth = subproject('widecharwidth')
widecharwidth_dep = widecharwidth.get_variable('widecharwidth_dep')

executable('btop',
  sources : target_sources,
  cpp_args : cpp_args,
  include_directories : include_directories('src'),
  dependencies : [fmt_dep, widecharwidth_dep],
)
