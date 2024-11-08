#!/bin/sh

set -xe

gcc -o client client.c xdg-shell-protocol.c -lwayland-client -lrt -lxkbcommon -Wall -Wextra -std=c99 -pedantic -fsanitize=address
