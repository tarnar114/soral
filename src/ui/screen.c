#include "ui.h"
#include <notcurses/notcurses.h>
#include <string.h>

static struct ncplane *canvas = NULL;
static unsigned int term_rows = 0;
static unsigned int term_cols = 0;
void init_canvas(struct notcurses *nc) {
  struct ncplane_options opts;
  memset(&opts, 0, sizeof(struct ncplane_options));
  notcurses_term_dim_yx(nc, &term_rows, &term_cols);
  opts.y = 1;
  opts.x = 1;
  opts.rows = term_rows;
  opts.cols = term_cols;
  canvas = ncplane_create(notcurses_stdplane(nc), &opts);
  draw_box(canvas, opts.rows - 3, opts.cols - 3, 0x100);
}
