/* speedie's dynamic window manager configuration
 * https://github.com/speedie-de/dwm
 *
 * You can set most of these options in your .Xresources.
 * Check the 'man' page if you're unsure how it's supposed to be used. 
 *
 * WARNING: Requires libXft-bgra to work properly. Otherwise this will CRASH when viewing a color emoji. 
 * Since I hate this problem just as much as you do, I edited the Makefile so you can easily install it.
 *
 * To install libXft-bgra on Arch Linux, type 'make arch-libxftfix'
 * To install libXft-bgra on Gentoo Linux, type 'make gentoo-libxftfix'
 * To install libXft-bgra on other GNU/Linux distributions, type 'make libxftfix' */

#define VARIABLES                             ". /usr/bin/dwm-applications;" /* Source variables from this file */
#define STATUSBAR                             status /* Status bar to use, set to dwmblocks if using dwmblocks */
#define ICONSIZE                              sizeicon /* Icon size */
#define ICONSPACING                           spacingicon  /* Space between icon and title */
#define SCREENSHOT                            "maim -suB | xclip -selection clipboard -t image/png"
#define SCREENSHOT_FULL                       "maim -uB | xclip -selection clipboard -t image/png"
#define SCREENSHOT                            "maim -suB | xclip -selection clipboard -t image/png"
#define SCREENSHOT_FULL                       "maim -uB | xclip -selection clipboard -t image/png"
#include <X11/XF86keysym.h> /* Enable multimedia button support */
static unsigned int borderpx                  = 1; /* How big your border is */
static unsigned int snap                      = 32;
static unsigned int gappx                     = 5; /* How big should your gaps be? 0 = No gaps */
static int showbar                            = 1; /* Show the bar or not? 1 = yes, 0 = no */
static int topbar                             = 1; /* Should the bar be on the top of bottom? 1 = yes, 0 = no */
static char font[]                            = { "Terminus:size=8" }; /* What font should we use? */
static char font2[]                           = { "JoyPixels:size=8" }; /* Second font */
static char font3[]                           = { "Siji:size=8" }; /* Third font */
static const char *fonts[]                    = { font, font2, font3 };
static char shell[]                           = "/bin/sh"; /* shell to use */
static char status[]                          = "xshbar"; /* status bar to use, dwmblocks for dwmblocks, slstatus for slstatus, etc. */
static int sizeicon                           = 16; /* size of the icon */
static int spacingicon                        = 5; /* spacing between the title and icon */
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
static char *scratchpadcmd[]                  = {"s", VARIABLES "$TERMINAL", "-t", "scratchpad", NULL};
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
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *alttags[] = { "[1]", "[2]", "[3]", "[4]", "[5]", "[6]", "[7]", "[8]", "[9]" };
static char *colors[][3]      = {
	[SchemeNorm] = { col_textnorm, col_background,    col_windowbordernorm },
	[SchemeSel]  = { col_textsel,  col_backgroundmid, col_windowbordersel }, 
/*                       text         background         window border */
};

static const char *const autostart[] = {
   shell, "-c", STATUSBAR,
   shell, "-c", "dwm-autostart.sh",
   NULL
};

static const unsigned int alphas[][3]      = {
       /*               fg      bg        border     */
       [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
       [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

static char *tagsel[][2] = {
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

static const unsigned int tagalpha[] = { OPAQUE, baralpha };
static const Rule rules[] = {
    	/* class         instance    title       tags mask     isfloating    isterminal   noswallow   CenterFirst    monitor     scratch key */
        { "St",          NULL,       NULL,       3 << 9,       0,            1,           0,          0,             -1,         0  },
        { "alacritty",   NULL,       NULL,       3 << 9,       0,            1,           0,          0,             -1,         0  },
        { "kitty",       NULL,       NULL,       3 << 9,       0,            1,           0,          0,             -1,         0  },
	    { "qutebrowser", NULL,       NULL,       2 << 9,       0,            0,           1,          0,             -1,         0  },
	    { "vimb",        NULL,       NULL,       2 << 9,       0,            0,           1,          1,             -1,         0  },
		{ "Chromium",    NULL,       NULL,       2 << 9,       0,            0,           1,          0,             -1,         0  },
	    { "Firefox",     NULL,       NULL,       2 << 9,       0,            0,           1,          0,             -1,         0  },
		{ "Librewolf",   NULL,       NULL,       2 << 9,       0,            0,           1,          0,             -1,         0  },
		{ "urxvt",       NULL,       NULL,       3 << 9,       0,            0,           0,          0,             -1,         0  },
        { "surf",        NULL,       NULL,       2 << 9,       1,            0,           1,          0,             -1,         0  },
        { "tabbed",      NULL,       NULL,       2 << 9,       0,            0,           0,          0,             -1,         0  },
		{ NULL,          NULL,     "scratchpad", 0,            0,            0,                                      -1,        's' },
/* You can add more, I just added some popular software. */
};

#include "layouts.c"
static const Layout layouts[] = {
    { "",          tile },
	{ "",          NULL },
	{ "",          monocle },
	{ "",          grid },
    { "",          deck },
    { NULL,        NULL },
};

#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY|ShiftMask,             KEY,      view,           {.ui = 1 << TAG} }, \

/*
* Xresources preferences to load at startup
* You can add more if you know what you're doing.
*/
ResourcePref resources[] = {
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
	   { "mfact",                FLOAT,   &mfact },
};

#define SHCMD(cmd) { .v = (const char*[]){ shell, "-c", cmd, NULL } } /* Shell to use */

/* These are your keybinds. Unless you wanna add more you won't need to recompile.
 * Instead just edit ~/.config/dwm-applications
 *
 * If you have any questions read the man page. */

static Key keys[] = {
	/* modifier                     key            function        argument */
	{ MODKEY|ShiftMask,             XK_semicolon,  spawn,          SHCMD(VARIABLES "$DMENU_RUN -l 1 -p Run: $BOTTOM") },
	{ MODKEY|ShiftMask,             XK_Return,     spawn,          SHCMD(VARIABLES "$TERMINAL") },
	{ MODKEY|ShiftMask,             XK_s,          spawn,          SHCMD(VARIABLES SCREENSHOT) },
	{ ControlMask|MODKEY,           XK_s,          spawn,          SHCMD(VARIABLES SCREENSHOT_FULL) },
	{ MODKEY|ShiftMask,             XK_f,          spawn,          SHCMD(VARIABLES "$TERMINAL $FILEMANAGER") },
	{ MODKEY|ShiftMask,             XK_w,          spawn,          SHCMD(VARIABLES "$BROWSER") },
	{ MODKEY|ShiftMask,             XK_o,          spawn,          SHCMD(VARIABLES "dfmpeg || ~/Scripts/dfmpeg") },
	{ MODKEY|ShiftMask,             XK_p,          spawn,          SHCMD(VARIABLES "genpkg || ~/Scripts/genpkg") },
	{ MODKEY|ShiftMask,             XK_c,          spawn,          SHCMD(VARIABLES "copyout || ~/Scripts/copyout") },
	{ MODKEY|ShiftMask,             XK_v,          spawn,          SHCMD(VARIABLES "dsearch || ~/Scripts/dsearch") },
	{ MODKEY|ShiftMask,             XK_j,          spawn,          SHCMD(VARIABLES "cfgedit || ~/Scripts/cfgedit") }, 
	{ MODKEY|ShiftMask,             XK_e,          spawn,          SHCMD(VARIABLES "emojilist || ~/Scripts/emojilist") },
	{ ControlMask|ShiftMask,        XK_m,          spawn,          SHCMD(VARIABLES "$TERMINAL $EMAIL") },
	{ MODKEY|ShiftMask,             XK_t,	       spawn,          SHCMD(VARIABLES "$TERMINAL $EDITOR") },
    { MODKEY|ShiftMask,             XK_p,          spawn,          SHCMD(VARIABLES "pkill $BROWSER") },
    { MODKEY|ControlMask,           XK_m,          spawn,          SHCMD(VARIABLES "pkill $PLAYER_BIN") },
	{ ControlMask|MODKEY,           XK_u,          spawn,          SHCMD(VARIABLES "$TERMINAL $RSS") },
	{ MODKEY|ShiftMask,             XK_a,          spawn,          SHCMD(VARIABLES "$TERMINAL $MIXER") },
	{ MODKEY|ShiftMask,             XK_m,          spawn,          SHCMD(VARIABLES "$TERMINAL $PLAYER") }, 
    { MODKEY|ShiftMask,             XK_x,          spawn,          SHCMD(VARIABLES "$TERMINAL $STAT") },
	{ MODKEY|ControlMask,           XK_1,          spawn,          SHCMD(VARIABLES "amixer -c 0 set Master 100%-") },
	{ MODKEY|ControlMask,           XK_2,          spawn,          SHCMD(VARIABLES "amixer -c 0 set Master 7%-") },
	{ MODKEY|ControlMask,           XK_3,          spawn,          SHCMD(VARIABLES "amixer -c 0 set Master 7%+") },
	{ ShiftMask|ControlMask,        XK_k,          spawn,          SHCMD(VARIABLES "amixer -c 0 sset 'Auto-Mute Mode' Enabled") },
	{ ShiftMask|ControlMask,        XK_k,          spawn,          SHCMD(VARIABLES "amixer -c 0 sset 'Auto-Mute Mode' Disabled") },
	{ MODKEY|ShiftMask,             XK_k,          spawn,          SHCMD(VARIABLES "$TERMINAL $EDITOR $SCRIPTDIR/$(ls -Apf1 $SCRIPTDIR | $DMENU)") },
	{ MODKEY|ShiftMask,             XK_Tab,        spawn,          SHCMD(VARIABLES "switch") },
	{ ControlMask|ShiftMask,        XK_Tab,        spawn,          SHCMD(VARIABLES "wal_dwm.sh && xrdb -merge ~/.cache/wal/colors.Xresources") },
	{ MODKEY|ShiftMask,             XK_Escape,     spawn,          SHCMD(VARIABLES "shutdown.sh") },
	{ ControlMask|ShiftMask,        XK_a,          cyclelayout,    {.i = -1 } },
	{ ControlMask|ShiftMask,        XK_d,          cyclelayout,    {.i = +1 } },
	{ ControlMask|ShiftMask,        XK_s,          togglesticky,   {0} },
	{ MODKEY,                       XK_minus,      scratchpad_show, {0} },
	{ MODKEY|ShiftMask,             XK_minus,      scratchpad_hide, {0} },
	{ MODKEY,                       XK_equal,      scratchpad_remove, {0} },
	{ MODKEY|ShiftMask,             XK_equal,      togglescratch,   {.v = scratchpadcmd } },
	{ MODKEY,                       XK_f,          togglefullscr,  {0} },
	{ MODKEY,                       XK_b,          togglebar,      {0} },
	{ MODKEY,                       XK_j,          focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,     {.i = -1 } }, 
	{ MODKEY,                       XK_a,          setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_d,          setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return,     zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_q,          killclient,     {0} },
	{ MODKEY,                       XK_space,      setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating, {0} },
    { MODKEY|ControlMask,           XK_y,          setlayout,      {.v = &layouts[4]} },
	{ MODKEY|ControlMask,           XK_e,          setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ControlMask,           XK_r,          setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           XK_t,          setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ControlMask,           XK_0,          view,           {.ui = ~0 } },
	{ MODKEY,                       XK_d,          focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_d,          tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Tab,        livereloadxrdb, {0} },
	{ MODKEY,                       XK_Down,       moveresize,     {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       XK_Up,         moveresize,     {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       XK_Right,      moveresize,     {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       XK_Left,       moveresize,     {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,             XK_Down,       moveresize,     {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ShiftMask,             XK_Up,         moveresize,     {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ShiftMask,             XK_Right,      moveresize,     {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ShiftMask,             XK_Left,       moveresize,     {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_Up,         moveresizeedge, {.v = "t"} },
	{ MODKEY|ControlMask,           XK_Down,       moveresizeedge, {.v = "b"} },
	{ MODKEY|ControlMask,           XK_Left,       moveresizeedge, {.v = "l"} },
	{ MODKEY|ControlMask,           XK_Right,      moveresizeedge, {.v = "r"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Up,         moveresizeedge, {.v = "T"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Down,       moveresizeedge, {.v = "B"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Left,       moveresizeedge, {.v = "L"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Right,      moveresizeedge, {.v = "R"} },
	TAGKEYS(                        XK_1,          0)
	TAGKEYS(                        XK_2,          1)
	TAGKEYS(                        XK_3,          2)
	TAGKEYS(                        XK_4,          3)
	TAGKEYS(                        XK_5,          4)
	TAGKEYS(                        XK_6,          5)
	TAGKEYS(                        XK_7,          6)
	TAGKEYS(                        XK_8,          7)
	TAGKEYS(                        XK_9,          8)
	{ 0, XF86XK_AudioMute,		    spawn,		                   SHCMD("amixer -c 0 set Master 100%-") },    
    { 0, XF86XK_AudioRaiseVolume,	spawn,		                   SHCMD("amixer -c 0 set Master 7%+") },    
    { 0, XF86XK_AudioLowerVolume,	spawn,		                   SHCMD("amixer -c 0 set Master 7%-") },    
	{ 0, XF86XK_AudioStop,          spawn,                         SHCMD(VARIABLES "pkill $PLAYER_BIN") },
    { 0, XF86XK_WWW,	            spawn,		                   SHCMD(VARIABLES "$BROWSER") },    
    { 0, XF86XK_PowerOff,           spawn,                         SHCMD("shutdown.sh") },
	{ 0, XF86XK_Sleep,              spawn,                         SHCMD(VARIABLES "$LOCKER") },
	{ 0, XF86XK_Mail,               spawn,                         SHCMD(VARIABLES "$TERMINAL $EMAIL") },
	{ 0, XF86XK_TaskPane,           spawn,                         SHCMD(VARIABLES "$TERMINAL $STAT") },
};
