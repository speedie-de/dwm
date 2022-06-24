/* Anything in here will automatically start before dwm
 * I use it to start my status bar and some other stuff, though.
 *
 * If you wish to run more commands, add a line below.
 *
 * Syntax: "shell, "-c", "<command>", NULL,"
 *
 * "shell" is automatically defined as your shell.
 *
 * If you need help, run dwm-keybinds.
 * Once you're done with your edits, run 'make clean install'.
 *************************************************************/
static const char *const autostart[]          = {

   /* Bind Right Super+hjkl to arrow keys */
   shell, "-c", "xmodmap -e 'keycode 134 = Mode_switch'", NULL,
   shell, "-c", "xmodmap -e 'keycode 43 = h H Left H'", NULL,
   shell, "-c", "xmodmap -e 'keycode 44 = j J Down J'", NULL,
   shell, "-c", "xmodmap -e 'keycode 45 = k K Up K", NULL,
   shell, "-c", "xmodmap -e 'keycode 46 = l L Right L", NULL,

   /* Caps Lock = Escape */
   shell, "-c", "xmodmap -e 'clear Lock'", NULL,
   shell, "-c", "xmodmap -e 'keycode 66 = Escape NoSymbol Escape'", NULL,

   /* Run the defined clipboard manager */
   shell, "-c", CLIPBOARD "&", NULL,

   /* Run the defined compositor */
   shell, "-c", COMPOSITOR "&", NULL,

   /* Run the status bar defined */
   shell, "-c", STATUSBAR, NULL,

   /* zsh */
   shell, "-c", "zsh", NULL,

   NULL
};

