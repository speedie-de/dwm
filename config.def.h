/* speedie's dynamic window manager configuration
 * https://speedie.gq/dwm.html
 * 
 * Report issues here: https://github.com/speedie-de/dwm
 *
 * You can set most of these options in your .Xresources.
 * Check the 'man' page if you're unsure how it's supposed to be used. 
 *
 * Before using, please read the readme file (not .md) and install the dependencies
 * Some aren't necessary. If they're not, you can change them by changing the defined values below and recompiling.
 *
 * WARNING: Requires libXft-bgra to work properly. Otherwise this will crash when viewing a color emoji. 
 * Since I hate this problem just as much as you do, I edited the Makefile so you can easily install it.
 *
 * To install libXft-bgra on Arch Linux, type 'make arch-libxftfix'
 * To install libXft-bgra on Gentoo Linux, type 'make gentoo-libxftfix'
 *
 * You can also 'emerge' it on Gentoo if you add my overlay.
 * Add here: https://github.com/spoverlay/splay
 *
 * To install libXft-bgra on other Linux distributions, type 'make libxftfix' */

/* Include */
#include <X11/XF86keysym.h> /* Enable multimedia button support */
#include "layouts.c" /* Enable patched layouts */

/* Define
 * You may wanna change a few of these.
 *************************************/
#define TERMINAL                              "st -e " /* Terminal to use */
#define TERMINAL_CLASS                        "St" /* Terminal to use for rules */
#define BROWSER                               "tabbed -c vimb -e" /* Web browser to use */
#define BROWSER_CLASS                         "vimb" /* Web browser to use for rules */
#define SYSTEMSTAT                            "htop" /* System stat viewer to use */
#define RSS                                   "newsboat" /* RSS reader to use */
#define PDF                                   "zathura" /* PDF reader to use */
#define PDF_CLASS                             "Zathura" /* PDF reader to use for rules */
#define MIXER                                 "alsamixer" /* Audio mixer to use */
#define MUSIC                                 "mocp" /* Music player to use */
#define EMAIL                                 "neomutt" /* Email client to use */
#define EDITOR                                "vim" /* Text editor to use */
#define RUN                                   "dmenu_run -l 1 -p Run:"
#define SCREENSHOT                            "maim -suB | xclip -selection clipboard -t image/png" /* How to take screenshots (Selection) */
#define SCREENSHOT_FULL                       "maim -uB | xclip -selection clipboard -t image/png" /* How to take screenshots (Full screen) */
#define FILEMANAGER                           "vifmrun || vifm" /* File manager that will be used */
#define FILEMANAGER_CLASS                     "vifmrun" /* File manager that will be used for rules */
#define LOCKER                                "slock" /* Screen locker that will be used */
#define OPENSCRIPT                            "vim /home/$(logname)/Scripts/$(ls -Apf1 /home/$(logname)/Scripts | dmenu -p 'Which script do you want to edit?' -l 50)"
#define OPENDOC                               "zathura /home/$(logname)/Documents/$(ls -Apf1 /home/$(logname)/Documents/*.pdf | dmenu -p 'Which pdf do you wanna view?' -l 50)"
#define KILLMUSIC                             "pkill mocp"
#define IRC                                   "tmux -c weechat"
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
static char status[]                          = "xshbar"; /* status bar to use, dwmblocks for dwmblocks, slstatus for slstatus, etc. */
static int sizeicon                           = 16; /* size of the icon */
static int spacingicon                        = 5; /* spacing between the title and icon */
static int showbar                            = 1; /* Show the bar or not? 1 = yes, 0 = no */
static int topbar                             = 1; /* Should the bar be on the top of bottom? 1 = yes, 0 = no */
static int vertpad                            = 0; /* How much padding to have vertically */
static int sidepad                            = 0; /* How much padding to have horizontally */
static char col_background[]                  = "#222222"; /* dwm dark bg & slstatus bg */
static char col_backgroundmid[]               = "#222222"; /* dwm middle background */
static char col_textnorm[]                    = "#bbbbbb"; /* application title bar/font for norm */
static char col_textsel[]                     = "#eeeeee"; /* dwm text/font for selected */
static char col_windowbordernorm[]            = "#eeeeee"; /* dwm norm window border */
static char col_windowbordersel[]             = "#000000"; /* dwm sel window border */
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
static const unsigned int baralpha            = 0xd0;
static const unsigned int borderalpha         = OPAQUE;
static int lockfullscreen                     = 1;
static int decorhints                         = 1; /* Respect decoration hints */
static int nmaster                            = 1;
static int resizehints                        = 0;
static int startontag                         = 0; /* Start on a tag or not? 1 = yes, 0 = no */
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

/* Anything in here will automatically start before dwm
 * I use it to start my status bar and some other stuff, though.
 *****************************************/
static const char *const autostart[]          = {
   /* Run the status bar defined */
   shell, "-c", STATUSBAR, NULL,

   /* Set the wallpaper using bundled script */
   shell, "-c", "/home/$(logname)/.config/swal/swal_wm", NULL,

   /* Set colors from .Xresources if present */
   shell, "-c", "xrdb /home/$(logname)/.Xresources", NULL,
   shell, "-c", "xrdb /home/$(logname)/.config/.Xresources", NULL,

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
   NULL
};

/* Colors to use for alpha */
static const unsigned int alphas[][3]         = {
       /*                                         fg      bg        border     */
       [SchemeNorm]                           = { OPAQUE, baralpha, borderalpha },
       [SchemeSel]                            = { OPAQUE, baralpha, borderalpha },
};

/* Colors to use for tags */
static char *tagsel[][2]                      = {
	{ col_tag1_text, col_tag1 }, 
	{ col_tag2_text, col_tag2 },
	{ col_tag3_text, col_tag3 },
	{ col_tag4_text, col_tag4 },
	{ col_tag5_text, col_tag5 },
	{ col_tag6_text, col_tag6 },
	{ col_tag7_text, col_tag7 },
	{ col_tag8_text, col_tag8 },
	{ col_tag9_text, col_tag9 },
	/* Text       Background */
};

/* Alpha for tags */
static const unsigned int tagalpha[]          = { OPAQUE, baralpha };

/* Rules
 * Any applications defined here must follow the rules specified.
 ***************************************************************/
static const Rule rules[]                     = {
    	/* class                instance    title                             tags mask   isfloating    isterminal   noswallow   CenterFirst    monitor     scratch key */
        { TERMINAL_CLASS,       NULL,       NULL,                             0,          0,            1,           0,          0,             -1,         0  },
        { TERMINAL_CLASS,       NULL,       FILEMANAGER_CLASS,                0,          0,            1,           0,          1,             -1,         0  },
        { PDF_CLASS,            NULL,       NULL,                             0,          0,            0,           0,          0,             -1,         0  },
        { TERMINAL_CLASS,       NULL,       EDITOR,                           0,          0,            0,           0,          0,             -1,         0  },
        { TERMINAL_CLASS,       NULL,       MUSIC,                            0,          1,            0,           0,          1,             -1,         0  },
        { TERMINAL_CLASS,       NULL,       MIXER,                            0,          1,            0,           1,          1,             -1,         0  },
        { TERMINAL_CLASS,       NULL,       "cordless",                       0,          0,            0,           0,          1,             -1,         0  },
	    { BROWSER_CLASS,        NULL,       NULL,                             0,          0,            0,           1,          1,             -1,         0  },
        { "mpv",                NULL,       NULL,                             0,          0,            0,           0,          0,             -1,         0  },
        { "tabbed",             NULL,       NULL,                             0,          0,            0,           0,          0,             -1,         0  },
		{ NULL,                 NULL,       "CustomizeMii 3.11 by Leathl",    0,          1,            0,           1,          1,             -1,         0  },
	    { NULL,                 NULL,       "Picture-in-Picture",             0,          1,            0,           1,          0,             -1,         0  },
        { NULL,                 NULL,       "dwm",                            0,          1,            0,           0,          1,             -1,         0  },
		{ NULL,                 NULL,       "tmux",                           0,          1,            0,           1,          1,             -1,         0  },
		{ NULL,                 NULL,       "scratchpad",                     0,          0,            0,                                      -1,        's' },
};

/* These are all available layouts
 * You can add more although I suggest
 * adding them to layouts.c. */
static const Layout layouts[]                 = {
    { "",          tile },
	{ "",          NULL },
	{ "",          monocle },
	{ "",          grid },
    { "",          deck },
    { "",          centeredmaster },
	{ "",          centeredfloatingmaster },
	{ "",          spiral },
	{ "",          dwindle },
	{ "",          tcl },
	{ "",          bstack },
	{ "",          bstackhoriz },
	{ "",          horizgrid },
	{ "",          tatami },
	{ NULL,        NULL },
};

/*
* Xresources preferences to load at startup
* You can add more if you know what you're doing.
*/
ResourcePref resources[]                      = {
       { "font",                 STRING,  &font },
       { "font2",                STRING,  &font2 },
	   { "font3",                STRING,  &font3 },
	   { "col_background",       STRING,  &col_background },
       { "col_backgroundmid",    STRING,  &col_backgroundmid },
       { "col_textnorm",         STRING,  &col_textnorm },
       { "col_windowbordersel",  STRING,  &col_windowbordersel },
       { "col_windowbordernorm", STRING,  &col_windowbordernorm },
	   { "col_textsel",          STRING,  &col_textsel },
	   { "col_tag1",             STRING,  &col_tag1 },
	   { "col_tag1_text",        STRING,  &col_tag1_text },
	   { "col_tag2",             STRING,  &col_tag2 },
	   { "col_tag2_text",        STRING,  &col_tag2_text },
	   { "col_tag3",             STRING,  &col_tag3 },
	   { "col_tag3_text",        STRING,  &col_tag3_text },
	   { "col_tag4",             STRING,  &col_tag4 },
	   { "col_tag4_text",        STRING,  &col_tag4_text },
	   { "col_tag5",             STRING,  &col_tag5 },
	   { "col_tag5_text",        STRING,  &col_tag5_text },
	   { "col_tag6",             STRING,  &col_tag6 },
	   { "col_tag6_text",        STRING,  &col_tag6_text },
	   { "col_tag7",             STRING,  &col_tag7 },
	   { "col_tag7_text",        STRING,  &col_tag7_text },
	   { "col_tag8",             STRING,  &col_tag8 },
	   { "col_tag8_text",        STRING,  &col_tag8_text },
	   { "col_tag9",             STRING,  &col_tag9 },
	   { "col_tag9_text",        STRING,  &col_tag9_text },

       /* pywal support */
	   { "color0",               STRING,  &col_background },
	   { "color4",               STRING,  &col_backgroundmid },
	   { "color4",               STRING,  &col_textnorm },
	   { "color0",               STRING,  &col_windowbordersel },
	   { "color8",               STRING,  &col_windowbordernorm },
	   { "color0",               STRING,  &col_textsel },
	   { "color1",               STRING,  &col_tag1 },
	   { "color0",               STRING,  &col_tag1_text },
       { "color2",               STRING,  &col_tag2 },
	   { "color0",               STRING,  &col_tag2_text },
	   { "color3",               STRING,  &col_tag3 },
	   { "color0",               STRING,  &col_tag3_text },
	   { "color4",               STRING,  &col_tag4 },
	   { "color0",               STRING,  &col_tag4_text },
	   { "color5",               STRING,  &col_tag5 },
       { "color0",               STRING,  &col_tag5_text },
	   { "color6",               STRING,  &col_tag6 },
       { "color0",               STRING,  &col_tag6_text },
       { "color7",               STRING,  &col_tag7 },
	   { "color0",               STRING,  &col_tag7_text },
	   { "color8",               STRING,  &col_tag8 },
	   { "color0",               STRING,  &col_tag8_text },
	   { "color9",               STRING,  &col_tag9 },
	   { "color0",               STRING,  &col_tag9_text },

	   { "shell",                STRING,  &shell },
       { "status",               STRING,  &status },
       { "lockfullscreen",       INTEGER, &lockfullscreen },
	   { "borderpx",             INTEGER, &borderpx }, 
       { "snap",                 INTEGER, &snap },
       { "showbar",              INTEGER, &showbar },
       { "topbar",               INTEGER, &topbar },
       { "nmaster",              INTEGER, &nmaster },
       { "resizehints",          INTEGER, &resizehints },
       { "startontag",           INTEGER, &startontag },
	   { "gappx",                INTEGER, &gappx },
       { "sizeicon",             INTEGER, &sizeicon },
	   { "decorhints",           INTEGER, &decorhints },
       { "swallowfloating",      INTEGER, &swallowfloating },
	   { "vertpad",              INTEGER, &vertpad },
	   { "sidepad",              INTEGER, &sidepad },
	   { "mfact",                FLOAT,   &mfact },
/*       value in .Xresources    type     value in dwm */
};

/* These are your keybinds.
 * If you have any questions read the man page. */

static Key keys[] = {
	/* modifier                     key            function              argument */
	/* Application keybinds */
	{ MODKEY|ShiftMask,             XK_semicolon,  spawn,                SHCMD(RUN) },
	{ MODKEY|ShiftMask,             XK_Return,     spawn,                SHCMD(TERMINAL) },
	{ MODKEY|ShiftMask,             XK_s,          spawn,                SHCMD(SCREENSHOT) },
	{ MODKEY|ShiftMask,             XK_f,          spawn,                SHCMD(TERMINAL FILEMANAGER) },
	{ MODKEY|ShiftMask,             XK_w,          spawn,                SHCMD(BROWSER) },
	{ MODKEY|ShiftMask,             XK_d,          spawn,                SHCMD(TERMINAL IRC) },
	{ MODKEY|ShiftMask,             XK_o,          spawn,                SHCMD("dfmpeg") },
	{ MODKEY|ShiftMask,             XK_p,          spawn,                SHCMD("genpkg") },
	{ MODKEY|ShiftMask,             XK_c,          spawn,                SHCMD("copyout") },
	{ MODKEY|ShiftMask,             XK_v,          spawn,                SHCMD("dsearch") },
	{ MODKEY|ShiftMask,             XK_j,          spawn,                SHCMD("cfgedit") }, 
	{ MODKEY|ShiftMask,             XK_e,          spawn,                SHCMD("emojilist") },
	{ MODKEY|ShiftMask,             XK_comma,      spawn,                SHCMD("dscratchpad") },
	{ MODKEY|ShiftMask,             XK_t,	       spawn,                SHCMD(TERMINAL EDITOR) },
	{ MODKEY|ShiftMask,             XK_a,          spawn,                SHCMD(TERMINAL MIXER) },
	{ MODKEY|ShiftMask,             XK_m,          spawn,                SHCMD(TERMINAL MUSIC) }, 
	{ SMODKEY,                     XK_Tab,        spawn,                SHCMD("switch") },
    { MODKEY|ShiftMask,             XK_x,          spawn,                SHCMD(TERMINAL SYSTEMSTAT) },
	{ MODKEY|ShiftMask,             XK_k,          spawn,                SHCMD(TERMINAL OPENSCRIPT) },
	{ MODKEY|ShiftMask,             XK_i,          spawn,                SHCMD(TERMINAL OPENDOC) },
	{ MODKEY|ShiftMask,             XK_Escape,     spawn,                SHCMD("shutdown") },
	{ ControlMask|MODKEY,           XK_Tab,        spawn,                SHCMD("dwmutils -layout") },
	{ ControlMask|MODKEY,           XK_comma,      spawn,                SHCMD("via") },
	{ ControlMask|MODKEY,           XK_h,          spawn,                SHCMD(TERMINAL "dwm-keybinds") },
	{ ControlMask|MODKEY,           XK_s,          spawn,                SHCMD(SCREENSHOT_FULL) },
    { ControlMask|MODKEY,           XK_m,          spawn,                SHCMD(KILLMUSIC) },
	{ ControlMask|MODKEY,           XK_u,          spawn,                SHCMD(TERMINAL RSS) },
    { ControlMask|MODKEY,           XK_m,          spawn,                SHCMD(KILLMUSIC) },
	{ ControlMask|MODKEY,           XK_1,          spawn,                SHCMD(VOL_MUTE) },
	{ ControlMask|MODKEY,           XK_2,          spawn,                SHCMD(VOL_DOWN) },
	{ ControlMask|MODKEY,           XK_3,          spawn,                SHCMD(VOL_UP) },
	{ ControlMask|MODKEY|ShiftMask, XK_k,          spawn,                SHCMD(VOL_OUTPUT_SPEAKER_ON) },
	{ ControlMask|MODKEY|ShiftMask, XK_k,          spawn,                SHCMD(VOL_OUTPUT_SPEAKER_OFF) },
	{ ControlMask|MODKEY|ShiftMask, XK_Tab,        spawn,                SHCMD(LIVERELOAD) },
	{ ControlMask|MODKEY|ShiftMask, XK_Escape,     spawn,                SHCMD("dwmutils") },
	{ ControlMask|MODKEY|ShiftMask, XK_s,          spawn,                SHCMD("swal") },
	{ ControlMask|MODKEY|ShiftMask, XK_m,          spawn,                SHCMD(TERMINAL EMAIL) },

	/* Layout keybinds */
	{ ControlMask|MODKEY|ShiftMask, XK_a,          cyclelayout,          {.i = -1 } },
	{ ControlMask|MODKEY|ShiftMask, XK_d,          cyclelayout,          {.i = +1 } },
    { MODKEY|ControlMask,           XK_y,          setlayout,            {.v = &layouts[4]} },
	{ MODKEY|ControlMask,           XK_e,          setlayout,            {.v = &layouts[3]} },
	{ MODKEY|ControlMask,           XK_r,          setlayout,            {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           XK_t,          setlayout,            {.v = &layouts[0]} },
	{ MODKEY,                       XK_space,      setlayout,            {0} },

	/* Sticky keybinds */
	{ ControlMask|MODKEY|ShiftMask, XK_s,          togglesticky,         {0} },

	/* Scratchpad keybinds */
	{ MODKEY,                       XK_minus,      scratchpad_show,      {0} },
	{ MODKEY|ShiftMask,             XK_minus,      scratchpad_hide,      {0} },
	{ MODKEY,                       XK_equal,      scratchpad_remove,    {0} },
	{ MODKEY|ShiftMask,             XK_equal,      togglescratch,        {.v = scratchpadcmd } },

	/* dwm general binds */
	{ MODKEY,                       XK_f,          togglefullscr,        {0} },
	{ MODKEY,                       XK_b,          togglebar,            {0} },
	{ MODKEY,                       XK_j,          focusstack,           {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,           {.i = -1 } }, 
	{ MODKEY,                       XK_a,          setmfact,             {.f = -0.05} },
	{ MODKEY,                       XK_d,          setmfact,             {.f = +0.05} },
	{ MODKEY,                       XK_Return,     zoom,                 {0} },
	{ MODKEY|ShiftMask,             XK_q,          killclient,           {0} },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,       {0} },
	{ MODKEY|ControlMask,           XK_0,          view,                 {.ui = ~0 } },
	{ MODKEY,                       XK_d,          focusmon,             {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,             {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_d,          tagmon,               {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Tab,        livereloadxrdb,       {0} },

	/* Floating mode keybinds */
	{ MODKEY,                       XK_Down,       moveresize,           {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       XK_Up,         moveresize,           {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       XK_Right,      moveresize,           {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       XK_Left,       moveresize,           {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,             XK_Down,       moveresize,           {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ShiftMask,             XK_Up,         moveresize,           {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ShiftMask,             XK_Right,      moveresize,           {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ShiftMask,             XK_Left,       moveresize,           {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_Up,         moveresizeedge,       {.v = "t"} },
	{ MODKEY|ControlMask,           XK_Down,       moveresizeedge,       {.v = "b"} },
	{ MODKEY|ControlMask,           XK_Left,       moveresizeedge,       {.v = "l"} },
	{ MODKEY|ControlMask,           XK_Right,      moveresizeedge,       {.v = "r"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Up,         moveresizeedge,       {.v = "T"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Down,       moveresizeedge,       {.v = "B"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Left,       moveresizeedge,       {.v = "L"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Right,      moveresizeedge,       {.v = "R"} },

	/* Tag keybinds */
	TAGKEYS(                        XK_1,          0)
	TAGKEYS(                        XK_2,          1)
	TAGKEYS(                        XK_3,          2)
	TAGKEYS(                        XK_4,          3)
	TAGKEYS(                        XK_5,          4)
	TAGKEYS(                        XK_6,          5)
	TAGKEYS(                        XK_7,          6)
	TAGKEYS(                        XK_8,          7)
	TAGKEYS(                        XK_9,          8)
	
	/* Media buttons */
	{ 0, XF86XK_AudioMute,		    spawn,		                   SHCMD(VOL_MUTE) },    
    { 0, XF86XK_AudioRaiseVolume,	spawn,		                   SHCMD(VOL_UP) },    
    { 0, XF86XK_AudioLowerVolume,	spawn,		                   SHCMD(VOL_DOWN) },    
	{ 0, XF86XK_AudioStop,          spawn,                         SHCMD(KILLMUSIC) },
    { 0, XF86XK_WWW,	            spawn,		                   SHCMD(BROWSER) },    
    { 0, XF86XK_PowerOff,           spawn,                         SHCMD("shutdown.sh") },
	{ 0, XF86XK_Sleep,              spawn,                         SHCMD(LOCKER) },
	{ 0, XF86XK_Mail,               spawn,                         SHCMD(TERMINAL EMAIL) },
	{ 0, XF86XK_TaskPane,           spawn,                         SHCMD(TERMINAL SYSTEMSTAT) },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signum>"` */
static Signal signals[] = {
	/* signum       function        argument  */
	{ 1,            setlayout,      {.v = &layouts[0]} },
	{ 2,            setlayout,      {.v = &layouts[1]} },
	{ 3,            setlayout,      {.v = &layouts[2]} },
	{ 4,            setlayout,      {.v = &layouts[3]} },
	{ 5,            setlayout,      {.v = &layouts[4]} },
	{ 6,            setlayout,      {.v = &layouts[5]} },
	{ 7,            setlayout,      {.v = &layouts[6]} },
	{ 8,            setlayout,      {.v = &layouts[7]} },
	{ 9,            setlayout,      {.v = &layouts[8]} },
	{ 10,           setlayout,      {.v = &layouts[9]} },
	{ 11,           setlayout,      {.v = &layouts[10]} },
	{ 12,           setlayout,      {.v = &layouts[11]} },
	{ 13,           setlayout,      {.v = &layouts[12]} },
	{ 14,           setlayout,      {.v = &layouts[13]} },
	{ 15,           setlayout,      {.v = &layouts[14]} },
	{ 16,           cyclelayout,    {.i = -1 } },
	{ 17,           cyclelayout,    {.i = +1 } },
	{ 18,           livereloadxrdb, {0} },
	{ 19,           setmfact,       {.f = -0.05} },
	{ 20,           setmfact,       {.f = +0.05} },
	{ 21,           togglescratch,  {.v = scratchpadcmd } },
	{ 22,           togglesticky,   {0} },          
	{ 23,           togglebar,      {0} },
	{ 24,           togglefullscr,  {0} },
};
