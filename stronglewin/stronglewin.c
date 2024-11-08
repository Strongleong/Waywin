#include <stdbool.h>
#include <stdint.h>

#define PLATFORM_XORG 0
#define PLATFORM_WAYLAND 1
#define PLATFORM_WINDOWS 2

typedef struct Window {
  void *platform_window;
} Window;

static uint8_t detect_platform(void) {
  return PLATFORM_XORG;
}

Window *strw_window_open(void) {
  switch (detect_platform()) {
  }
}

bool strw_window_should_close(Window *window) {
}

void strw_window_close(Window *window) {
}
