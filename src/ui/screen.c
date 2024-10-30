#include "ui.h"
#include <notcurses/notcurses.h>
#include <string.h>

static struct ncplane *canvas = NULL;
static struct ncplane *box = NULL;
static unsigned int term_rows = 0;
static unsigned int term_cols = 0;
void init_canvas(struct notcurses *nc) {
  struct ncplane_options opts;
  memset(&opts, 0, sizeof(struct ncplane_options));
  notcurses_term_dim_yx(nc, &term_cols, &term_rows);
  opts.y = 1;
  opts.x = 1;
  opts.rows = term_rows;
  opts.cols = term_cols;
  canvas = ncplane_create(notcurses_stdplane(nc), &opts);
}

struct ncplane *get_canvas_plane() { return canvas; }

void init_panel(struct notcurses *nc) {
  /* nccells for creating box */
  struct nccell ul;
  struct nccell ur;
  struct nccell ll;
  struct nccell lr;
  struct nccell hline;
  struct nccell vline;

  nccell_init(&ul);
  nccell_init(&ur);
  nccell_init(&ll);
  nccell_init(&lr);
  nccell_init(&hline);
  nccell_init(&vline);

  nccell_load(box, &ul, "╭");
  nccell_load(box, &ur, "╮");
  nccell_load(box, &ll, "╰");
  nccell_load(box, &lr, "╯");
  nccell_load(box, &hline, "─");
  nccell_load(box, &vline, "│");

  struct ncplane_options opts;
  memset(&opts, 0, sizeof(struct ncplane_options));

  opts.y = 0;
  opts.x = term_cols/ 2 + term_cols/ 4 + 1;
  opts.rows = term_rows;
  opts.cols = term_cols- opts.x;

  box= ncplane_create(notcurses_stdplane(nc), &opts);

  ncplane_box(box, &ul, &ur, &ll, &lr, &hline, &vline,
              opts.rows - 1, opts.cols - 1, 0x100);
  ncplane_putchar(box, 'c');
}
