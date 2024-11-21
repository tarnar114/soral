project('ytEmbeds','c')

deps=[
  dependency('notcurses')
]
include=include_directories('include')
ui_sources = run_command('find', 'src/ui', '-name', '*.c', check: true).stdout().strip().split('\n')
# Alternatively, to include ALL .c files in the ui folder:
executable('ytEmbeds','src/main.c',
ui_sources,  dependencies:deps,
  include_directories:include)
