/* These are all your keybinds.
 *
 * Example keybind:
 *
 * { MODKEY, -1, XK_1, spawn, SHCMD(TERMINAL "echo "Hello world!") },
 * { MODKEY, XK_F1, XK_1, spawn, SHCMD(TERMINAL "echo "Hello world! Pressing two keys in a row is based!") },
 *
 * Modifiers
 *
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
	/* modifier                     chain key      key            function              argument */

	/* Application keybinds */
	{ MODKEY|ShiftMask,             -1,            XK_semicolon,  spawn,                SHCMD(RUN) },
	{ MODKEY|ShiftMask,             -1,            XK_Return,     spawn,                SHCMD(TERMINAL) },
	{ MODKEY|ShiftMask,             -1,            XK_s,          spawn,                SHCMD(SCREENSHOT) },
	{ MODKEY|ShiftMask,             -1,            XK_f,          spawn,                SHCMD(TERMINAL FILEMANAGER) },
	{ MODKEY|ShiftMask,             -1,            XK_w,          spawn,                SHCMD(BROWSER) },
	{ MODKEY|ShiftMask,             -1,            XK_o,          spawn,                SHCMD("dfmpeg || ~/Scripts/dfmpeg") },
	{ MODKEY|ShiftMask,             -1,            XK_e,          spawn,                SHCMD("dwm-virtualkeyboard || ~/Scripts/dwm-virtualkeyboard") },
	{ MODKEY|ShiftMask,             -1,            XK_t,	      spawn,                SHCMD(TERMINAL EDITOR) },
	{ MODKEY|ShiftMask,             -1,            XK_a,          spawn,                SHCMD(TERMINAL MIXER) },
	{ MODKEY|ShiftMask,             -1,            XK_m,          spawn,                SHCMD(TERMINAL MUSIC) },
	{ SMODKEY,                      -1,            XK_Tab,        spawn,                SHCMD("dwm-winnav") },
    { MODKEY|ShiftMask,             -1,            XK_x,          spawn,                SHCMD(TERMINAL SYSTEMSTAT) },
	{ MODKEY|ShiftMask,             -1,            XK_i,          spawn,                SHCMD(OPENPDF) },
	{ MODKEY|ShiftMask,             -1,            XK_Escape,     spawn,                SHCMD("dwm-shutdown") },
	{ ControlMask|MODKEY,           -1,            XK_Tab,        spawn,                SHCMD("dwm-utils -layout") },
	{ ControlMask|MODKEY,           -1,            XK_h,          spawn,                SHCMD(TERMINAL "dwm-help -3") },
	{ ControlMask|MODKEY,           -1,            XK_s,          spawn,                SHCMD(SCREENSHOT_FULL) },
	{ ControlMask|MODKEY,           -1,            XK_u,          spawn,                SHCMD(TERMINAL RSS) },
    { ControlMask|MODKEY,           -1,            XK_m,          spawn,                SHCMD(KILLMUSIC) },
	{ ControlMask|MODKEY,           -1,            XK_1,          spawn,                SHCMD(VOL_MUTE) },
	{ ControlMask|MODKEY,           -1,            XK_2,          spawn,                SHCMD(VOL_DOWN) },
	{ ControlMask|MODKEY,           -1,            XK_3,          spawn,                SHCMD(VOL_UP) },
	{ ControlMask|MODKEY|ShiftMask, -1,            XK_k,          spawn,                SHCMD(VOL_OUTPUT_SPEAKER) },
	{ ControlMask|MODKEY|ShiftMask, -1,			   XK_Escape,     spawn,                SHCMD("dwm-utils") },
	{ ControlMask|MODKEY|ShiftMask, -1,            XK_s,          spawn,                SHCMD("dwm-swal") },
	{ ControlMask|MODKEY|ShiftMask, -1,            XK_n,          spawn,                SHCMD(NETWORK) },
	{ ControlMask|MODKEY|ShiftMask, -1,            XK_b,          spawn,                SHCMD(BLUETOOTH) },
	{ MODKEY,                       -1,            XK_s,          spawn,                SHCMD("dwm-core -toggle") },
	{ ControlMask|MODKEY|ShiftMask, -1,            XK_m,          spawn,                SHCMD(TERMINAL EMAIL) },

	/* Layout keybinds */
	{ ControlMask|MODKEY|ShiftMask, -1,            XK_a,          cyclelayout,          {.i = -1 } },
	{ ControlMask|MODKEY|ShiftMask, -1,            XK_d,          cyclelayout,          {.i = +1 } },
    { MODKEY|ControlMask,           -1,            XK_y,          setlayout,            {.v = &layouts[4]} },
	{ MODKEY|ControlMask,           -1,            XK_e,          setlayout,            {.v = &layouts[3]} },
	{ MODKEY|ControlMask,           -1,            XK_r,          setlayout,            {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           -1,            XK_t,          setlayout,            {.v = &layouts[0]} },
	{ MODKEY,                       -1,            XK_space,      setlayout,            {0} },
	{ MODKEY,                       -1,            XK_r,          togglermaster,        {0} },

	/* Sticky keybinds */
	{  SMODKEY|MODKEY,              -1,            XK_s,          togglesticky,         {0} },

	/* Scratchpad keybinds */
	{ MODKEY,                       -1,            XK_minus,      scratchpad_show,      {0} },
	{ MODKEY|ShiftMask,             -1,            XK_minus,      scratchpad_hide,      {0} },
	{ MODKEY,                       -1,            XK_equal,      scratchpad_remove,    {0} },
	{ MODKEY|ShiftMask,             -1,            XK_equal,      togglescratch,        {.v = scratchpadcmd } },

	/* dwm general binds */
	{ MODKEY,                       -1,            XK_f,          togglefullscr,        {0} },
	{ MODKEY,                       -1,            XK_b,          togglebar,            {0} },
	{ MODKEY,                       -1,            XK_j,          focusstack,           {.i = +1 } },
	{ MODKEY,                       -1,            XK_k,          focusstack,           {.i = -1 } },
	{ MODKEY,                       -1,            XK_a,          setmfact,             {.f = -0.05} },
	{ MODKEY,                       -1,            XK_d,          setmfact,             {.f = +0.05} },
	{ MODKEY,                       -1,            XK_Return,     zoom,                 {0} },
	{ MODKEY|ShiftMask,             -1,            XK_q,          killclient,           {0} },
	{ MODKEY|ShiftMask,             -1,            XK_space,      togglefloating,       {0} },
	{ MODKEY|ControlMask,           -1,            XK_0,          view,                 {.ui = ~0 } },
	{ MODKEY,                       -1,            XK_d,          focusmon,             {.i = -1 } },
	{ MODKEY,                       -1,            XK_period,     focusmon,             {.i = +1 } },
	{ MODKEY|ShiftMask,             -1,            XK_d,          tagmon,               {.i = -1 } },
	{ MODKEY|ShiftMask,             -1,            XK_period,     tagmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             -1,            XK_Tab,        livereloadxrdb,       {0} },
	{ MODKEY|ShiftMask,             -1,            XK_j,          inplacerotate,        {.i = +1} },
	{ MODKEY|ShiftMask,             -1,            XK_k,          inplacerotate,        {.i = -1} },
	{ MODKEY|ShiftMask,             -1,            XK_h,          inplacerotate,        {.i = +2} },
	{ MODKEY|ShiftMask,             -1,            XK_l,          inplacerotate,        {.i = -2} },

	/* Floating mode keybinds */
	{ MODKEY,                       -1,            XK_Down,       moveresize,           {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       -1,            XK_Up,         moveresize,           {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       -1,            XK_Right,      moveresize,           {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       -1,            XK_Left,       moveresize,           {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,             -1,            XK_Down,       moveresize,           {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ShiftMask,             -1,            XK_Up,         moveresize,           {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ShiftMask,             -1,            XK_Right,      moveresize,           {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ShiftMask,             -1,            XK_Left,       moveresize,           {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           -1,            XK_Up,         moveresizeedge,       {.v = "t"} },
	{ MODKEY|ControlMask,           -1,            XK_Down,       moveresizeedge,       {.v = "b"} },
	{ MODKEY|ControlMask,           -1,            XK_Left,       moveresizeedge,       {.v = "l"} },
	{ MODKEY|ControlMask,           -1,            XK_Right,      moveresizeedge,       {.v = "r"} },
	{ MODKEY|ControlMask|ShiftMask, -1,            XK_Up,         moveresizeedge,       {.v = "T"} },
	{ MODKEY|ControlMask|ShiftMask, -1,            XK_Down,       moveresizeedge,       {.v = "B"} },
	{ MODKEY|ControlMask|ShiftMask, -1,            XK_Left,       moveresizeedge,       {.v = "L"} },
	{ MODKEY|ControlMask|ShiftMask, -1,            XK_Right,      moveresizeedge,       {.v = "R"} },

	/* Tag keybinds */
	TAGKEYS(                        -1,            XK_1,          0)
	TAGKEYS(                        -1,            XK_2,          1)
	TAGKEYS(                        -1,            XK_3,          2)
	TAGKEYS(                        -1,            XK_4,          3)
	TAGKEYS(                        -1,            XK_5,          4)
	TAGKEYS(                        -1,            XK_6,          5)
	TAGKEYS(                        -1,            XK_7,          6)
	TAGKEYS(                        -1,            XK_8,          7)
	TAGKEYS(                        -1,            XK_9,          8)
	{ MODKEY,                       -1,            XK_t,          reorganizetags, {0} },
 
    /* Hide/Show keybinds */
	{ MODKEY,						-1,            XK_o, 	       hidewin, 	   {0} },
    { MODKEY|ControlMask, 			-1,            XK_o, 	       restorewin, 	   {0} },
    { MODKEY, 						-1,            XK_w, 	       hideotherwins,  {0} },
    { MODKEY|ControlMask, 			-1,            XK_w, 	       restoreotherwins, {0} },

    /* Chained keybinds */
	{ MODKEY,                       XK_c,          XK_w,           spawn,           SHCMD(TERMINAL "dwm-core -curl-weather") },

	/* Media buttons */
	{ 0,                            -1,            XF86XK_AudioMute,		    spawn,		                   SHCMD(VOL_MUTE) },
    { 0,                            -1,            XF86XK_AudioRaiseVolume,	    spawn,		                   SHCMD(VOL_UP) },
    { 0,                            -1,            XF86XK_AudioLowerVolume,	    spawn,		                   SHCMD(VOL_DOWN) },
	{ 0,                            -1,            XF86XK_AudioStop,            spawn,                         SHCMD(KILLMUSIC) },
    { 0,                            -1,            XF86XK_WWW,	                spawn,		                   SHCMD(BROWSER) },
    { 0,                            -1,            XF86XK_PowerOff,             spawn,                         SHCMD("dwm-shutdown") },
	{ 0,                            -1,            XF86XK_Sleep,                spawn,                         SHCMD(LOCKER) },
	{ 0,                            -1,            XF86XK_Mail,                 spawn,                         SHCMD(TERMINAL EMAIL) },
	{ 0,                            -1,            XF86XK_TaskPane,             spawn,                         SHCMD(TERMINAL SYSTEMSTAT) },
};
