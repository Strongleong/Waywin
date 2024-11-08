#ifndef STRONGLEWIN_H
#define STRONGLEWIN_H

#include <stdbool.h>

typedef void Window;

Window *strw_window_open(void);
bool strw_window_should_close(Window *window);
void strw_window_close(Window *window);

#endif /* end of include guard: STRONGLEWIN_H */
