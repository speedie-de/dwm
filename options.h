/* Define This build comes with defines for common software such as your web
 * browser or terminal.
 * If you wish to use a different browser for example, simply change the values.
 *
 * You do not need to edit 'keybinds.h' or 'rules.h' because that's where these are used.
 * Once you're done with your edits, run 'make clean install'.
 *************************************/

#define TERMINAL                              "st -e " /* Terminal to use */
#define TERMINAL_CLASS                        "St" /* Terminal to use for rules */
#define BROWSER                               "firefox" /* Web browser to use */
#define BROWSER_CLASS                         "firefox" /* Web browser to use for rules */
#define SYSTEMSTAT                            "htop" /* System stat viewer to use */
#define RSS                                   "newsboat" /* RSS reader to use */
#define PDF                                   "zathura" /* PDF reader to use */
#define PDF_CLASS                             "Zathura" /* PDF reader to use for rules */
#define MUSIC                                 "mocp" /* Music player to use */
#define EMAIL                                 "neomutt" /* Email client to use */
#define EDITOR                                "vim" /* Text editor to use */
#define RUN                                   "dmenu_run -l 1 -p 'Run:'" /* Run launcher */
#define SCREENSHOT                            "dwm-screenshotutil" /* How to take screenshots (Selection) */
#define SCREENSHOT_FULL                       "dwm-screenshotutil -f" /* How to take screenshots (Full screen) */
#define FILEMANAGER                           "vifmrun || vifm" /* File manager that will be used */
#define FILEMANAGER_CLASS                     "vifmrun" /* File manager that will be used for rules */
#define LOCKER                                "slock" /* Screen locker that will be used */
#define OPENPDF                               "dwm-pdfopen ~/Documents zathura || ~/Scripts/dwm-pdfopen ~/Documents zathura"
#define KILLMUSIC                             "pkill mocp" /* Command to run when killing the music player */
#define MIXER                                 "dwm-audioctrl -runmixer" /* Audio mixer to use */
#define VOL_DOWN                              "dwm-audioctrl -lower" /* Command to run when decreasing volume */
#define VOL_UP                                "dwm-audioctrl -raise" /* Command to run when increasing volume */
#define VOL_MUTE                              "dwm-audioctrl -mute" /* Command to run when muting volume */
#define VOL_OUTPUT_SPEAKER                    "dwm-audioctrl -switch" /* Command to run when enabling speakers */
#define MODKEY Mod1Mask
#define SMODKEY Mod4Mask
#define STATUSBAR                             status /* Status bar to use, set to dwmblocks if using dwmblocks, status for other value */
#define ICONSIZE                              sizeicon /* Icon size */
#define ICONSPACING                           spacingicon  /* Space between icon and title */
#define CLIPBOARD                             "xclip" /* Clipboard to use */
#define COMPOSITOR                            "picom" /* Compositor to use */
#define NETWORK                               "dwm-netctrl" /* Network manager to use */
#define BLUETOOTH                             "dwm-btctrl" /* Bluetooth manager to use */
#define NOTIFICATION                          "dunst" /* Notification daemon to use */

#define SESSION_FILE                          "/tmp/dwm-session"
#define SHCMD(cmd)                            { .v = (const char*[]){ shell, "-c", cmd, NULL } } /* Shell to use */
#define TAGKEYS(CHAIN,KEY,TAG)                { MODKEY, CHAIN, KEY, view, {.ui = 1 << TAG} },	\
										      { MODKEY|ShiftMask, CHAIN, KEY, previewtag, {.ui = TAG} },

/* Options
 *
 * If xrdb is installed, you can simply edit ~/.config/dwm-de/dwmrc instead of recompiling.
 *
 * Once you're done with your edits, run 'make clean install'.
 ****************************************/

/* Window alignment options */
static unsigned int borderpx                  = 1; /* How big your border is */
static unsigned int snap                      = 20; /* Snap pixel */
static unsigned int gappx                     = 10; /* How big should your gaps be? */
static int rmaster                            = 0; /* 0 means master area is initially on the right */
static int nmaster                            = 1;
static int resizehints                        = 0;
static int decorhints                         = 1; /* Respect decoration hints */
static int savefloat                          = 1; /* Save position of floating windows */
static int refreshrules                       = 1; /* Refresh rules when a CLASS or TITLE changes */
static int i3nmaster                          = 0; /* Enable i3-gaps like nmaster (1/0) */
static float mfact                            = 0.50;

/* Window aesthetic options */
static int fadeinactive                       = 1; /* Fade inactive windows */
static double activeopacity				      = 1.0f; /* Window opacity when it's focused (0 <= opacity <= 1) */
static double inactiveopacity                 = 0.875f; /* Window opacity when it's inactive (0 <= opacity <= 1) */
static Bool bUseOpacity                       = True; /* Starts with opacity on any unfocused windows */

/* Tag preview options */
static int tagpreview                         = 1; /* Enable tag previews */
static int mousepreview                       = 1; /* Display tag previews if hovering over a tag */
static int scalepreview                       = 4; /* Size of tag preview */

/* Window spawning options */
static int spawncd                            = 1; /* Spawn clients in the working directory of the focused client */
static int attachdirection                    = 3; /* 0 default, 1 above, 2 aside, 3 below, 4 bottom, 5 top */
static int swallowfloating                    = 0; /* Swallow floating windows by default */
static int centerfloating                     = 1; /* Center floating windows by default */
static int firstwindowsize                    = 0; /* Size of first centered window */
static int startontag                         = 1; /* Start on a tag or not? */

/* Font options */
static char font[]                            = { "fontawesome:size=8" }; /* What font should we use? */
static char font2[]                           = { "NotoSans-Regular:size=8:antialiasing=true" }; /* Second font */
static char font3[]                           = { "Noto Emoji:size=8" }; /* Third font */
static const char *fonts[]                    = { font, font2, font3 };
static char defaultname[]                     = ""; /* What to print when a status bar is not running */

/* Misc */
static char shell[]                           = "/bin/sh"; /* shell to use */ 
static char status[]                          = "status"; /* status bar to use, dwmblocks for dwmblocks, slstatus for slstatus, etc. */
static char *scratchpadcmd[]                  = {"s", TERMINAL, "-t", "scratchpad", NULL};
static int lockfullscreen                     = 1;
static int warpcursor                         = 1; /* Warp cursor when switching client/monitor */
static int pertag                             = 1; /* Use different mfact and layout for each layout */

/* Icon options */
static int sizeicon                           = 10; /* size of the icon */
static int spacingicon                        = 5; /* spacing between the title and icon */

/* Bar options */
static int barheight                          = 5; /* Bar height in px, 0 = calculate automatically */
static int topbar                             = 1; /* Should the bar be on the top of bottom? */
static int vertpad                            = 0; /* How much padding to have vertically */
static int sidepad                            = 0; /* How much padding to have horizontally */
static int leftlayout                         = 1; /* Layout indicator on the left (1) or on the right (0) */

/* Bar item options */
static int showbar                            = 1; /* Show the bar or not? */
static int hidelayout                         = 0; /* Hide layout indicator (1) or show (0) */
static int hidetitle                          = 0; /* Hide title (1) or show (0) */
static int hidestatus                         = 0; /* Hide status bar (1) or show (0) */
static int hidetags                           = 0; /* Hide status bar (1) or show (0) */

/* Status options */
static int statusallmons                      = 1; /* Draw status bar on all monitors */

/* Layout options */
static unsigned int monocleclientcount        = 0; /* Display client count in the Monocle layout */
static unsigned int stairpx                   = 20; /* depth of the stairs layout */
static int stairdirection                     = 1; /* 0: left-aligned, 1: right-aligned */
static int stairsamesize                      = 1; /* 1 means shrink all the staired windows to the same size */

/* Bar colors */
static char col_background[]                  = "#222222"; /* dwm dark bg & slstatus bg */
static char col_backgroundmid[]               = "#222222"; /* dwm middle background */

/* General text colors */
static char col_textnorm[]                    = "#bbbbbb"; /* application title bar/font for norm */
static char col_textsel[]                     = "#eeeeee"; /* dwm text/font for selected */

/* Window border colors */
static char col_windowbordernorm[]            = "#000000"; /* dwm norm window border */
static char col_windowbordersel[]             = "#eeeeee"; /* dwm sel window border */

/* Tag text/background colors */
static char col_tag1[]                        = "#333333"; /* tag 1 background */
static char col_tag1_text[]                   = "#eeeeee"; /* tag 1 text (fg) */
static char col_tag2[]                        = "#333333"; /* tag 2 background */
static char col_tag2_text[]                   = "#eeeeee"; /* tag 2 text (fg) */
static char col_tag3[]                        = "#333333"; /* tag 3 background */
static char col_tag3_text[]                   = "#eeeeee"; /* tag 3 text (fg) */
static char col_tag4[]                        = "#333333"; /* tag 4 background */
static char col_tag4_text[]                   = "#eeeeee"; /* tag 4 text (fg) */
static char col_tag5[]                        = "#333333"; /* tag 5 background */
static char col_tag5_text[]                   = "#eeeeee"; /* tag 5 text (fg) */
static char col_tag6[]                        = "#333333"; /* tag 6 background */
static char col_tag6_text[]                   = "#eeeeee"; /* tag 6 text (fg) */
static char col_tag7[]                        = "#333333"; /* tag 7 background */
static char col_tag7_text[]                   = "#eeeeee"; /* tag 7 text (fg) */
static char col_tag8[]                        = "#333333"; /* tag 8 background */
static char col_tag8_text[]                   = "#eeeeee"; /* tag 8 text (fg) */
static char col_tag9[]                        = "#333333"; /* tag 9 background */
static char col_tag9_text[]                   = "#eeeeee"; /* tag 9 text (fg) */

/* Layout indicator colors */
static char col_layouttext[]                  = "#000000"; /* Layout indicator text (fg) */
static char col_layoutbgnorm[]                = "#222222"; /* Layout indicator background (norm) */
static char col_layoutbgsel[]                 = "#bbbbbb"; /* Layout indicator background (norm) */

/* status2d colors */
static char termcol0[]                        = "#000000";
static char termcol1[]                        = "#ff0000";
static char termcol2[]                        = "#33ff00";
static char termcol3[]                        = "#ff0099";
static char termcol4[]                        = "#0066ff";
static char termcol5[]                        = "#cc00ff";
static char termcol6[]                        = "#00ffff";
static char termcol7[]                        = "#d0d0d0";
static char termcol8[]                        = "#808080";
static char termcol9[]                        = "#ff0000";
static char termcol10[]                       = "#33ff00";
static char termcol11[]                       = "#ff0099";
static char termcol12[]                       = "#0066ff";
static char termcol13[]                       = "#cc00ff";
static char termcol14[]                       = "#00ffff";
static char termcol15[]                       = "#ffffff";

/* Alpha settings */
static const unsigned int baralpha            = 0xcc;
static const unsigned int borderalpha         = 0xcc;

/* Tag text options */
static const char *tags[]                     = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *alttags[]                  = { "[1]", "[2]", "[3]", "[4]", "[5]", "[6]", "[7]", "[8]", "[9]" };

/* Icon misc */
static XPoint stickyicon[]                    = { {0,0}, {4,0}, {4,8}, {2,6}, {0,8}, {0,0} }; /* represents the icon as an array of vertices */
static XPoint stickyiconbb                    = {4,8};	/* defines the bottom right corner of the polygon's bounding box (speeds up scaling) */
