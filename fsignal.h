/* Signal definitions
 * Signum must be greater than 0
 * Trigger signals using `dwm-utils -exec <signum>"` 
 * 
 * Once you're done with your edits, run 'make clean install'. */
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
	{ 25,           self_restart,   {0} },
    { 26,           togglermaster,  {0} },
	{ 27,           setlayout,      {.v = &layouts[15]} },
};
