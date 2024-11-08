#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int main(void) {
  Display *main_display = XOpenDisplay(0);
  Window root_window = XDefaultRootWindow(main_display);

  printf("1\n");

  XSetWindowAttributes attributes = {
    .backing_pixel = 0X00AADE87,
    .event_mask = StructureNotifyMask | KeyPressMask | KeyReleaseMask | ExposureMask,
  };

  printf("2\n");
  Window main_window = XCreateWindow(
    main_display,
    root_window,
    0,
    0,
    800,
    600,
    0,
    CopyFromParent,
    CopyFromParent,
    CopyFromParent,
    CWBackPixel | CWEventMask,
    &attributes
  );

  printf("3\n");
  XMapWindow(main_display, main_window);
  XFlush(main_display);

  bool is_window_open = true;

  printf("4\n");
  while (is_window_open) {
    XEvent general_event = {0};
    XNextEvent(main_display, &general_event);

    switch (general_event.type) {
      case KeyPress:
      case KeyRelease:
        {
          XKeyPressedEvent *event = (XKeyPressedEvent *)&general_event;

          printf("%s\n", XKeysymToString(event->keycode));
          if (event->keycode == XKeysymToKeycode(main_display, XK_Escape)) {
            is_window_open = true;
          }
        }
      break;
    }
  }

  return 0;
}
