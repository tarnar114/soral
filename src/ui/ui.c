#include "ui.h"
#include <notcurses/notcurses.h>
#include <stdio.h>
#include <string.h>
static struct notcurses *nc = NULL;
static bool running = false;
void init() {
  // init notcurses instance
  nc = notcurses_init(NULL, stdout);
  if (NULL == nc) {
    printf("Could not initialize notcurses.\n");
  }
  init_canvas(nc);
  init_panel(nc);
  notcurses_render(nc);
  running = true;
}
void run() {
  struct ncinput input;
  memset(&input, 0, sizeof(struct ncinput));
  while (running) {
    notcurses_get_blocking(nc, &input);
  }
}
static void process_input(const ncinput *input) {
  switch (input->id) {
  case 'q':
    running = false;
    break;
  }
}
void quit() { printf("quit"); }
