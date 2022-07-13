/* These are all your keybinds.
 *
 * Modifiers
 * MODKEY is what you defined (in options.h, default is Super)
 * SMODKEY is what you defined (in options.h, default is Alt)
 * ShiftMask is unless changed going to be your Shift key.
 * ControlMask is unless changed going to be your Control key.
 * 
 * It is recommended that you avoid using 'SMODKEY' (Mod1Mask) by itself because it can break software defined shortcuts. 
 *
 * If you need help, see dwm-help.
 * Once you're done with your edits, run 'make clean install'.
 */

static Key keys[] = {
	/* modifier                     key            function              argument */

	/* Application keybinds */
	{ MODKEY|ShiftMask,             XK_semicolon,  spawn,                SHCMD(RUN) },
	{ MODKEY|ShiftMask,             XK_Return,     spawn,                SHCMD(TERMINAL) },
	{ MODKEY|ShiftMask,             XK_s,          spawn,                SHCMD(SCREENSHOT) },
	{ MODKEY|ShiftMask,             XK_f,          spawn,                SHCMD(TERMINAL FILEMANAGER) },
	{ MODKEY|ShiftMask,             XK_w,          spawn,                SHCMD(BROWSER) },
	{ MODKEY|ShiftMask,             XK_o,          spawn,                SHCMD("dfmpeg || ~/Scripts/dfmpeg") },
	{ MODKEY|ShiftMask,             XK_e,          spawn,                SHCMD("dwm-virtualkeyboard || ~/Scripts/dwm-virtualkeyboard") },
	{ MODKEY|ShiftMask,             XK_t,	       spawn,                SHCMD(TERMINAL EDITOR) },
	{ MODKEY|ShiftMask,             XK_a,          spawn,                SHCMD(TERMINAL MIXER) },
	{ MODKEY|ShiftMask,             XK_m,          spawn,                SHCMD(TERMINAL MUSIC) },
	{ SMODKEY,                      XK_Tab,        spawn,                SHCMD("dwm-winnav") },
    { MODKEY|ShiftMask,             XK_x,          spawn,                SHCMD(TERMINAL SYSTEMSTAT) },
	{ MODKEY|ShiftMask,             XK_i,          spawn,                SHCMD(OPENPDF) },
	{ MODKEY|ShiftMask,             XK_Escape,     spawn,                SHCMD("dwm-shutdown") },
	{ ControlMask|MODKEY,           XK_Tab,        spawn,                SHCMD("dwm-utils -layout") },
	{ ControlMask|MODKEY,           XK_h,          spawn,                SHCMD(TERMINAL "dwm-help -a") },
	{ ControlMask|MODKEY,           XK_s,          spawn,                SHCMD(SCREENSHOT_FULL) },
    { ControlMask|MODKEY,           XK_m,          spawn,                SHCMD(KILLMUSIC) },
	{ ControlMask|MODKEY,           XK_u,          spawn,                SHCMD(TERMINAL RSS) },
    { ControlMask|MODKEY,           XK_m,          spawn,                SHCMD(KILLMUSIC) },
	{ ControlMask|MODKEY,           XK_1,          spawn,                SHCMD(VOL_MUTE) },
	{ ControlMask|MODKEY,           XK_2,          spawn,                SHCMD(VOL_DOWN) },
	{ ControlMask|MODKEY,           XK_3,          spawn,                SHCMD(VOL_UP) },
	{ ControlMask|MODKEY|ShiftMask, XK_k,          spawn,                SHCMD(VOL_OUTPUT_SPEAKER) },
	{ ControlMask|MODKEY|ShiftMask, XK_Escape,     spawn,                SHCMD("dwm-utils") },
	{ ControlMask|MODKEY|ShiftMask, XK_s,          spawn,                SHCMD("dwm-swal") },
	{ ControlMask|MODKEY|ShiftMask, XK_n,          spawn,                SHCMD("dwm-netctrl") },
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
	{  SMODKEY|MODKEY,              XK_s,          togglesticky,         {0} },

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
	{ MODKEY|ShiftMask,             XK_j,          inplacerotate,        {.i = +1} },
	{ MODKEY|ShiftMask,             XK_k,          inplacerotate,        {.i = -1} },
	{ MODKEY|ShiftMask,             XK_h,          inplacerotate,        {.i = +2} },
	{ MODKEY|ShiftMask,             XK_l,          inplacerotate,        {.i = -2} },


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
    { 0, XF86XK_PowerOff,           spawn,                         SHCMD("dwm-shutdown") },
	{ 0, XF86XK_Sleep,              spawn,                         SHCMD(LOCKER) },
	{ 0, XF86XK_Mail,               spawn,                         SHCMD(TERMINAL EMAIL) },
	{ 0, XF86XK_TaskPane,           spawn,                         SHCMD(TERMINAL SYSTEMSTAT) },
};
