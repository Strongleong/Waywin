#!/bin/sh

WCLIBS="-lwayland-client"
XCLIBS="-lX11"
CFLAGS="-Wall -Wextra -std=c11 -pedantic"

set -e
set -x

clang -o wwin $CFLAGS $WCLIBS wwin.c
clang -o xwin $CFLAGS $XCLIBS xwin.c
