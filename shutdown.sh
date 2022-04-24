#!/bin/sh
# This simple script uses dmenu to ask the user what they wanna do.
. /usr/bin/dwm-applications
USER_OPT1=$(printf "Shutdown\nReboot\nExit\nLock" | $DMENU -l 4 -p "What do you wanna do?" -nb "#DC143C")

case "$USER_OPT1" in
"Shutdown") sudo shutdown now || doas shutdown now ;;
"Reboot") reboot ;;
"Exit") exit 0 ;;
"Lock") slock ;;
"") exit 0 ;;
esac
