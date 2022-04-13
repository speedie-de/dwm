/* speedie's dynamic window manager configuration
 * https://github.com/speedie-de/dwm */

/* You can set most of these options in your .Xresources.
 * Check the 'man' page if you're unsure how it's supposed to be used. */

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } } /* Shell to use */
#define STATUSBAR                               "xshbar" /* Status bar to use, set to dwmblocks if using dwmblocks */
#define ICONSIZE                                16 /* Icon size */
#define ICONSPACING                             5  /* Space between icon and title */
static unsigned int borderpx                  = 1; /* How big your border is */
static unsigned int snap                      = 32;
static unsigned int gappx                     = 5; /* How big should your gaps be? 0 = No gaps */
static int showbar                            = 1; /* Show the bar or not? 1 = yes, 0 = no */
static int topbar                             = 1; /* Should the bar be on the top of bottom? 1 = yes, 0 = no */
static char font[]                            = { "Terminus:size=8" }; /* What font should we use? */
static char font2[]                           = { "siji:size=8" }; /* Second font */
static const char *fonts[]                    = { font, font2 };
static char col_background[]                  = "#222222"; /* dwm dark bg & slstatus bg */
static char col_backgroundmid[]               = "#222222"; /* dwm middle background */
static char col_textnorm[]                    = "#bbbbbb"; /* application title bar/font for norm */
static char col_textsel[]                     = "#eeeeee"; /* dwm text/font for selected */
static char col_windowbordernorm[]            = "#5757ff"; /* dwm norm window border */
static char col_windowbordersel[]             = "#5757ff"; /* dwm sel window border */
static char col_tag1[]                        = "#ff0000"; /* tag 1 background */
static char col_tag1_text[]                   = "#ffffff"; /* tag 1 text (fg) */
static char col_tag2[]                        = "#ff7f00"; /* tag 2 background */
static char col_tag2_text[]                   = "#ffffff"; /* tag 2 text (fg) */
static char col_tag3[]                        = "#ffff00"; /* tag 3 background */
static char col_tag3_text[]                   = "#000000"; /* tag 3 text (fg) */
static char col_tag4[]                        = "#00ff00"; /* tag 4 background */
static char col_tag4_text[]                   = "#000000"; /* tag 4 text (fg) */
static char col_tag5[]                        = "#0000ff"; /* tag 5 background */
static char col_tag5_text[]                   = "#ffffff"; /* tag 5 text (fg) */
static char col_tag6[]                        = "#0000ff"; /* tag 6 background */
static char col_tag6_text[]                   = "#ffffff"; /* tag 6 text (fg) */
static char col_tag7[]                        = "#9400d3"; /* tag 7 background */
static char col_tag7_text[]                   = "#ffffff"; /* tag 7 text (fg) */
static char col_tag8[]                        = "#ffffff"; /* tag 8 background */
static char col_tag8_text[]                   = "#000000"; /* tag 8 text (fg) */
static char col_tag9[]                        = "#000000"; /* tag 9 background */
static char col_tag9_text[]                   = "#ffffff"; /* tag 9 text (fg) */
static const unsigned int baralpha            = 0xd0;
static const unsigned int borderalpha         = OPAQUE;
static int lockfullscreen                     = 1;
static float mfact                            = 0.50;
static int nmaster                            = 1;
static int resizehints                        = 0;
static int startontag                         = 0; /* Start on a tag or not? 1 = yes, 0 = no */
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
   "sh", "-c", STATUSBAR, NULL,
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
    	/* class       instance    title       tags mask     CenterFirst   isfloating   monitor */
        { "st",        NULL,       NULL,       3 << 9,       0,            0,           -1 },
	    { "Firefox",   NULL,       NULL,       2 << 9,       0,            0,           -1 },
		{ "Librewolf", NULL,       NULL,       2 << 9,       0,            0,           -1 },
		{ "urxvt",     NULL,       NULL,       3 << 9,       0,            0,           -1 },
};

#include "layouts.c"
static const Layout layouts[] = {
    { "",          tile },
	{ "",          NULL },
	{ "",          monocle },
	{ "",          grid },
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
       { "lockfullscreen",       INTEGER, &lockfullscreen },
	   { "borderpx",             INTEGER, &borderpx }, 
       { "snap",                 INTEGER, &snap },
       { "showbar",              INTEGER, &showbar },
       { "topbar",               INTEGER, &topbar },
       { "nmaster",              INTEGER, &nmaster },
       { "resizehints",          INTEGER, &resizehints },
       { "mfact",                FLOAT,   &mfact },
       { "startontag",           INTEGER, &startontag },
	   { "gappx",                INTEGER, &gappx },
};

/* These are your keybinds. Unless you wanna add more you won't need to recompile.
 * Instead just edit ~/.config/dwm-applications
 *
 * If you have any questions read the man page. */

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_comma,  spawn,          SHCMD(". ~/.config/dwm-applications && $DMENU_RUN") },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          SHCMD(". ~/.config/dwm-applications && $TERMINAL") },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD(". ~/.config/dwm-applications && maim -sB ~/Screenshot.png && xclip -selection clipboard -t image/png ~/Screenshot.png") },
	{ MODKEY|ShiftMask,             XK_f,      spawn,          SHCMD(". ~/.config/dwm-applications && $TERMINAL $FILEMANAGER") },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          SHCMD(". ~/.config/dwm-applications && $BROWSER") },
	{ MODKEY|ShiftMask,             XK_o,      spawn,          SHCMD(". ~/.config/dwm-applications && dfmpeg || ~/Scripts/dfmpeg") },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD(". ~/.config/dwm-applications && genpkg || ~/Scripts/genpkg") },
	{ MODKEY|ShiftMask,             XK_c,      spawn,          SHCMD(". ~/.config/dwm-applications && copyout || ~/Scripts/copyout") },
	{ MODKEY|ShiftMask,             XK_v,      spawn,          SHCMD(". ~/.config/dwm-applications && dsearch || ~/Scripts/dsearch") },
	{ MODKEY|ShiftMask,             XK_j,      spawn,          SHCMD(". ~/.config/dwm-applications && cfgedit || ~/Scripts/cfgedit") }, 
	{ ControlMask|ShiftMask,        XK_m,      spawn,          SHCMD(". ~/.config/dwm-applications && $TERMINAL $EMAIL") },
	{ MODKEY|ShiftMask,             XK_t,	   spawn,          SHCMD(". ~/.config/dwm-applications && $TERMINAL $EDITOR") },
    { MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD(". ~/.config/dwm-applications && pkill $BROWSER") },
    { MODKEY|ControlMask,           XK_m,      spawn,          SHCMD(". ~/.config/dwm-applications && pkill $PLAYER_BIN") },
	{ MODKEY|ShiftMask,             XK_d,      spawn,          SHCMD(". ~/.config/dwm-applications && $BROWSER --new-window https://discord.com/channels/@me") },      
	{ MODKEY|ShiftMask,             XK_y,      spawn,          SHCMD(". ~/.config/dwm-applications && $BROWSER --new-window $INV_INSTANCE") },
	{ ControlMask|MODKEY,           XK_y,      spawn,          SHCMD(". ~/.config/dwm-applications && $TERMINAL $RSS") },
    { ControlMask|ShiftMask,        XK_4,      spawn,          SHCMD(". ~/.config/dwm-applications && $BROWSER --new-window $CHAN") },
	{ MODKEY|ShiftMask,             XK_a,      spawn,          SHCMD(". ~/.config/dwm-applications && $TERMINAL $MIXER") },
	{ MODKEY|ShiftMask,             XK_m,      spawn,          SHCMD(". ~/.config/dwm-applications && $TERMINAL $PLAYER") }, 
    { MODKEY|ShiftMask,             XK_x,      spawn,          SHCMD(". ~/.config/dwm-applications && $TERMINAL $STAT") },
	{ MODKEY|ControlMask,           XK_1,      spawn,          SHCMD("amixer -c 0 set Master 100%-") },
	{ MODKEY|ControlMask,           XK_2,      spawn,          SHCMD("amixer -c 0 set Master 7%-") },
	{ MODKEY|ControlMask,           XK_3,      spawn,          SHCMD("amixer -c 0 set Master 7%+") },
	{ ShiftMask|ControlMask,        XK_k,      spawn,          SHCMD("amixer -c 0 sset 'Auto-Mute Mode' Enabled") },
	{ ShiftMask|ControlMask,        XK_k,      spawn,          SHCMD("amixer -c 0 sset 'Auto-Mute Mode' Disabled") },
	{ ControlMask|ShiftMask,        XK_a,      cyclelayout,    {.i = -1 } },
	{ ControlMask|ShiftMask,        XK_d,      cyclelayout,    {.i = +1 } },
	{ MODKEY,                       XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } }, 
	{ MODKEY,                       XK_a,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_d,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ControlMask,           XK_e,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ControlMask,           XK_r,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ControlMask,           XK_0,      view,           {.ui = ~0 } },
	{ MODKEY,                       XK_d,      focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_d,      tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Tab,    spawn,          SHCMD("wal_dwm.sh && xrdb -merge $HOME/.cache/wal/colors.Xresources") },
	{ MODKEY|ShiftMask,             XK_Tab,    livereloadxrdb, {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};
