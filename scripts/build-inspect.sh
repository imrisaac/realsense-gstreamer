#!/bin/bash
set -e

# meson . build
sudo ninja -C build install
gst-inspect-1.0 build/src/libgstrealsensesrc.so