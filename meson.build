project('ytEmbeds','c')

deps=[
  dependency('notcurses')
]
include=include_directories('include')
executable('ytEmbeds','src/main.c',
'src/ui/ui.c','src/ui/screen.c',  dependencies:deps,
  include_directories:include)
