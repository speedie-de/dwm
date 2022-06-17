/* Rules
 * Any applications defined here must follow the rules specified.
 ***************************************************************/
static const Rule rules[]                     = {
    	/* class                instance    title                             tags mask   isfloating    isterminal   noswallow   CenterFirst    monitor     scratch key */
		{ TERMINAL_CLASS,       NULL,       NULL,                             0,          0,            1,           0,          0,             -1,         0  },
        { TERMINAL_CLASS,       NULL,       "sxiv",                           0,          0,            0,           1,          0,             -1,         0  },
        { TERMINAL_CLASS,       NULL,       FILEMANAGER_CLASS,                0,          1,            1,           0,          1,             -1,         0  },
        { PDF_CLASS,            NULL,       NULL,                             0,          0,            0,           0,          0,             -1,         0  },
        { TERMINAL_CLASS,       NULL,       EDITOR,                           0,          0,            0,           0,          0,             -1,         0  },
        { TERMINAL_CLASS,       NULL,       MUSIC,                            0,          0,            0,           1,          0,             -1,         0  },
        { TERMINAL_CLASS,       NULL,       "dwm",                            0,          0,            0,           1,          0,             -1,         0  },
        { TERMINAL_CLASS,       NULL,       MIXER,                            0,          1,            0,           1,          1,             -1,         0  },
        { TERMINAL_CLASS,       NULL,       "cordless",                       0,          0,            0,           0,          1,             -1,         0  },
	    { BROWSER_CLASS,        NULL,       NULL,                             0,          0,            0,           1,          0,             -1,         0  },
		{ "dolphin-emu",        NULL,       NULL,                             0,          1,            1,           0,          1,             -1,         0  },
        { "mpv",                NULL,       NULL,                             0,          0,            0,           0,          0,             -1,         0  },
        { "tabbed",             NULL,       NULL,                             0,          0,            0,           0,          0,             -1,         0  },
		{ NULL,                 NULL,       "CustomizeMii 3.11 by Leathl",    0,          1,            0,           1,          1,             -1,         0  },
	    { NULL,                 NULL,       "Picture-in-Picture",             0,          1,            0,           1,          0,             -1,         0  },
	    { NULL,                 NULL,       "About GNU IceCat",               0,          1,            0,           1,          0,             -1,         0  },
	    { NULL,                 NULL,       "About LibreWolf",                0,          1,            0,           1,          0,             -1,         0  },
	    { NULL,                 NULL,       "About Mozilla Firefox",          0,          1,            0,           1,          0,             -1,         0  },
		{ NULL,                 NULL,       "scratchpad",                     0,          0,            0,                                      -1,        's' },
};

