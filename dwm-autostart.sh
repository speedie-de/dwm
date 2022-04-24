#!/bin/sh
# This file will run immediately before dwm runs.
# I still recommend using your .xinitrc if possible, though.

dwm_wal.sh # Enable wal support, comment if you will not be using it.
xrdb -merge ~/.cache/wal/colors.Xresources
