#include "ui.h"
void draw_box(struct ncplane *nc, int rows, int cols, unsigned int mask) {

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

  nccell_load(nc, &ul, "╭");
  nccell_load(nc, &ur, "╮");

  nccell_load(nc, &ll, "╰");
  nccell_load(nc, &lr, "╯");
  nccell_load(nc, &hline, "─");
  nccell_load(nc, &vline, "│");

  ncplane_box(nc, &ul, &ur, &ll, &lr, &hline, &vline, rows, cols, mask);
}
