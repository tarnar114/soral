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
  notcurses_render(nc);
  running = true;
}
void run() {
  struct ncinput input;
  memset(&input, 0, sizeof(struct ncinput));
  while (running) {
    notcurses_get_blocking(nc, &input);
    if (input.id == 'q') {
      running = false;
    }
    notcurses_render(nc);
  }
}
void quit() {
  if (running == false) {
    notcurses_stop(nc);
  }
}
