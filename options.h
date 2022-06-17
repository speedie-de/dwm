/* Define
 * You may wanna change a few of these.
 *************************************/
#define TERMINAL                              "st -e " /* Terminal to use */
#define TERMINAL_CLASS                        "St" /* Terminal to use for rules */
#define BROWSER                               "firefox" /* Web browser to use */
#define BROWSER_CLASS                         "firefox" /* Web browser to use for rules */
#define SYSTEMSTAT                            "htop" /* System stat viewer to use */
#define RSS                                   "newsboat" /* RSS reader to use */
#define PDF                                   "zathura" /* PDF reader to use */
#define PDF_CLASS                             "Zathura" /* PDF reader to use for rules */
#define MIXER                                 "alsamixer" /* Audio mixer to use */
#define MUSIC                                 "mocp" /* Music player to use */
#define EMAIL                                 "neomutt" /* Email client to use */
#define EDITOR                                "vim" /* Text editor to use */
#define RUN                                   "dmenu_run -l 1 -p 'Run:'" /* Run launcher */
#define SCREENSHOT                            "bb" /* How to take screenshots (Selection) */
#define SCREENSHOT_FULL                       "bb -f" /* How to take screenshots (Full screen) */
#define FILEMANAGER                           "vifmrun || vifm" /* File manager that will be used */
#define FILEMANAGER_CLASS                     "vifmrun" /* File manager that will be used for rules */
#define LOCKER                                "slock" /* Screen locker that will be used */
#define OPENSCRIPT                            "scriptedit ~/Scripts || ~/Scripts/scriptedit ~/Scripts"
#define OPENPDF                               "pdfopen ~/Documents zathura || ~/Scripts/pdfopen ~/Documents zathura"
#define KILLMUSIC                             "pkill mocp"
#define VOL_DOWN                              "amixer -c 0 set Master 7%-" /* Command to run when decreasing volume */
#define VOL_UP                                "amixer -c 0 set Master 7%+" /* Command to run when increasing volume */
#define VOL_MUTE                              "amixer -c 0 set Master 100%-" /* Command to run when muting volume */
#define VOL_OUTPUT_SPEAKER_ON                 "amixer -c 0 sset 'Auto-Mute Mode' Enabled" /* Command to run when enabling speakers */
#define VOL_OUTPUT_SPEAKER_OFF                "amixer -c 0 sset 'Auto-Mute Mode' Disabled" /* Command to run when disabling speakers */
#define LIVERELOAD                            "xrdb ~/.cache/wal/colors.Xresources" /* Command to run when reloading .Xresources */
#define MODKEY Mod4Mask
#define SMODKEY Mod1Mask
#define STATUSBAR                             status /* Status bar to use, set to dwmblocks if using dwmblocks */
#define ICONSIZE                              sizeicon /* Icon size */
#define ICONSPACING                           spacingicon  /* Space between icon and title */
#define SHCMD(cmd)                            { .v = (const char*[]){ shell, "-c", cmd, NULL } } /* Shell to use */
#define TAGKEYS(KEY,TAG)                      { MODKEY|ShiftMask, KEY, view, {.ui = 1 << TAG} }, \

#define CLIPBOARD                             "xclip" /* Clipboard to use */
#define COMPOSITOR                            "picom" /* Compositor to use */

/* Options
 *
 * If you're going to be using .Xresources then you don't need to change any of these.
 * Otherwise, you can carefully edit them.
 ****************************************/
static unsigned int borderpx                  = 1; /* How big your border is */
static unsigned int snap                      = 32;
static unsigned int gappx                     = 5; /* How big should your gaps be? 0 = No gaps */
static char font[]                            = { "Terminus:size=8" }; /* What font should we use? */
static char font2[]                           = { "JoyPixels:size=8" }; /* Second font */
static char font3[]                           = { "Siji:size=8" }; /* Third font */
static const char *fonts[]                    = { font, font2, font3 };
static char shell[]                           = "/bin/sh"; /* shell to use */ 
static char status[]                          = "status"; /* status bar to use, dwmblocks for dwmblocks, slstatus for slstatus, etc. */
static int sizeicon                           = 10; /* size of the icon */
static int spacingicon                        = 5; /* spacing between the title and icon */
static int showbar                            = 1; /* Show the bar or not? 1 = yes, 0 = no */
static int topbar                             = 1; /* Should the bar be on the top of bottom? 1 = yes, 0 = no */
static int vertpad                            = 0; /* How much padding to have vertically */
static int sidepad                            = 0; /* How much padding to have horizontally */
static char col_background[]                  = "#222222"; /* dwm dark bg & slstatus bg */
static char col_backgroundmid[]               = "#005577"; /* dwm middle background */
static char col_textnorm[]                    = "#bbbbbb"; /* application title bar/font for norm */
static char col_textsel[]                     = "#eeeeee"; /* dwm text/font for selected */
static char col_windowbordernorm[]            = "#000000"; /* dwm norm window border */
static char col_windowbordersel[]             = "#eeeeee"; /* dwm sel window border */
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
static char *scratchpadcmd[]                  = {"s", TERMINAL, "-t", "scratchpad", NULL};
static float mfact                            = 0.50;
static const unsigned int baralpha            = 0xcc;
static const unsigned int borderalpha         = 0xcc;
static int lockfullscreen                     = 1;
static int decorhints                         = 1; /* Respect decoration hints */
static int nmaster                            = 1;
static int resizehints                        = 0;
static int startontag                         = 1; /* Start on a tag or not? 1 = yes, 0 = no */
static int swallowfloating                    = 0; /* Swallow floating windows by default */
static char dmenumon[2]                       = "0";
static const char *dmenucmd[]                 = { NULL };
static const char *tags[]                     = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *alttags[]                  = { "[1]", "[2]", "[3]", "[4]", "[5]", "[6]", "[7]", "[8]", "[9]" };
static char *colors[][3]                      = {
	[SchemeNorm]                              = { col_textnorm, col_background,    col_windowbordernorm },
	[SchemeSel]                               = { col_textsel,  col_backgroundmid, col_windowbordersel }, 
/*                                                text          background         window border */
};
