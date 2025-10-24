target_sources += files(
  'btop.cpp',
  'btop_cli.cpp',
  'btop_config.cpp',
  'btop_draw.cpp',
  'btop_input.cpp',
  'btop_menu.cpp',
  'btop_shared.cpp',
  'btop_theme.cpp',
  'btop_tools.cpp',
)

system = host_machine.system()
if system == 'linux'
  subdir('linux')
elif system == 'openbsd'
  subdir('openbsd')
endif

conf = configuration_data()

conf.set('COMPILER', cpp.get_id())
conf.set('COMPILER_VERSION', cpp.version())
conf.set('CONFIGURE_COMMAND', '')
conf.set('GIT_COMMIT', '')

configure_file(
  configuration : conf,
  input : 'config.h.in',
  output : 'config.h',
)
