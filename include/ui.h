#pragma once

#include <notcurses/notcurses.h>

typedef struct ui_box {
  unsigned int begx;
  unsigned int begy;
  unsigned int endx;
  unsigned int endy;
} ui_box;

void init(void);
void run(void);
void quit(void);
void init_canvas(struct notcurses *nc);
static void process_input(const ncinput *input);
struct ncplane *get_canvas_plane(void);
void init_panel(struct notcurses *nc);

