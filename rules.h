/* Rules
 * Any applications defined here must follow the rules specified.
 * The user can get the class by running a program like xprop (must be installed by the user) and then selecting the software.
 *
 * - tags mask: Disable tags where the CLASS, INSTANCE or TITLE will spawn. (X << Y)
 * - isfloating: Choose whether a CLASS, INSTANCE or TITLE will spawn as floating. (1/0)
 * - ispermanent: Whether or not you can kill a client
 * - canfocus: Whether or not the CLASS, INSTANCE or TITLE can be focused or not. (1/0)
 * - isterminal: Whether or not the CLASS, INSTANCE or TITLE is a terminal or not (1/0)
 * - noswallow: Whether or not the CLASS, INSTANCE or TITLE gets swallowed by a terminal or not (1/0)
 * - centerfirst: Whether or not the CLASS, INSTANCE or TITLE gets centered if it's the first window on a tag (1/0)
 * - ignoretransient: Whether or not to ignore transient windows for CLASS, INSTANCE or TITLE (1/0)
 *
 * For the rest, leave as they currently are and copy them for new rules.
 * Once you're done with your edits, run 'make clean install'.
 * 
 ***************************************************************/
static const Rule rules[]                     = {
    	/* class                instance    title                             tags mask isfloating ispermanent canfocus isterminal noswallow centerfirst monitor ignoretransient scratch key */
		{ TERMINAL_CLASS,       NULL,       NULL,                             0,        0,         0,          1,       1,         0,        0,          -1,     0,              0  },
        { TERMINAL_CLASS,       NULL,       "sxiv",                           0,        0,         0,          1,       0,         1,        0,          -1,     0,              0  },
        { TERMINAL_CLASS,       NULL,       FILEMANAGER_CLASS,                0,        0,         0,          1,       1,         0,        0,          -1,     0,              0  },
        { PDF_CLASS,            NULL,       NULL,                             0,        0,         0,          1,       0,         0,        0,          -1,     0,              0  },
        { TERMINAL_CLASS,       NULL,       EDITOR,                           0,        0,         0,          1,       0,         0,        0,          -1,     0,              0  },
        { TERMINAL_CLASS,       NULL,       MUSIC,                            0,        0,         0,          1,       0,         1,        0,          -1,     0,              0  },
        { TERMINAL_CLASS,       NULL,       "dwm",                            0,        0,         0,          1,       0,         1,        0,          -1,     0,              0  },
        { TERMINAL_CLASS,       NULL,       MIXER,                            0,	    1,		   0,          1,       0,         1,        1,          -1,     0,              0  },
	    { BROWSER_CLASS,        NULL,       NULL,                             0,        0,         0,          1,       0,         1,        0,          -1,     0,              0  },
		{ "dolphin-emu",        NULL,       NULL,                             0,        1,         0,          1,       1,         0,        1,          -1,     0,              0  },
        { "mpv",                NULL,       NULL,                             0,        0,         0,          1,       0,         0,        0,          -1,     0,              0  },
        { "tabbed",             NULL,       NULL,                             0,        0,         0,          1,       0,         0,        0,          -1,     0,              0  },
        { "trayer",             NULL,       NULL,                             0,        1,         1,          0,       0,         1,        0,          -1,     0,              0  },
		{ NULL,                 NULL,       "CustomizeMii 3.11 by Leathl",    0,        1,         0,          1,       0,         1,        1,          -1,     0,              0  },
	    { NULL,                 NULL,       "Picture-in-Picture",             0,        1,         0,          1,       0,         1,        0,          -1,     0,              0  },
	    { NULL,                 NULL,       "About GNU IceCat",               0,        1,         0,          1,       0,         1,        0,          -1,     0,              0  },
	    { NULL,                 NULL,       "About LibreWolf",                0,        1,         0,          1,       0,         1,        0,          -1,     0,              0  },
	    { NULL,                 NULL,       "About Mozilla Firefox",          0,        1,         0,          1,       0,         1,        0,          -1,     0,              0  },
		{ NULL,                 NULL,       "scratchpad",                     0,                   0,       0,                               -1,                    's' },
};

