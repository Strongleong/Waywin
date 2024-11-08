#include "./stronglewin/stronglewin.h"

void window_update(Window *w) {
  (void) w;
}

int main(void) {
  Window *w = strw_window_open();

  while (!strw_window_should_close(w)) {
    window_update(w);
  }

  strw_window_close(w);
}
