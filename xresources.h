/*
* Xresources preferences to load at startup
* You can add more if you know what you're doing.
* 
* When you're done with your edits, run 'make clean install'.
* 
*      Value in .Xresources      Type     Value in dwm */         
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
	   { "col_status0",          STRING,  &termcol0 },
	   { "col_status1",          STRING,  &termcol1 },
	   { "col_status2",          STRING,  &termcol2 },
	   { "col_status3",          STRING,  &termcol3 },
	   { "col_status4",          STRING,  &termcol4 },
	   { "col_status5",          STRING,  &termcol5 },
	   { "col_status6",          STRING,  &termcol6 },
	   { "col_status7",          STRING,  &termcol7 },
	   { "col_status8",          STRING,  &termcol8 },
	   { "col_status9",          STRING,  &termcol9 },
	   { "col_status10",         STRING,  &termcol10 },
	   { "col_status11",         STRING,  &termcol11 },
	   { "col_status12",         STRING,  &termcol12 },
	   { "col_status13",         STRING,  &termcol13 },
	   { "col_status14",         STRING,  &termcol14 },
	   { "col_status15",         STRING,  &termcol15 },

       /* pywal support */
	   { "color0",               STRING,  &col_background },
	   { "color4",               STRING,  &col_backgroundmid },
	   { "color4",               STRING,  &col_textnorm },
	   { "color8",               STRING,  &col_windowbordersel },
	   { "color0",               STRING,  &col_windowbordernorm },
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
	   { "color0",               STRING,  &termcol0 },
	   { "color1",               STRING,  &termcol1 },
	   { "color2",               STRING,  &termcol2 },
	   { "color3",               STRING,  &termcol3 },
	   { "color4",               STRING,  &termcol4 },
	   { "color5",               STRING,  &termcol5 },
	   { "color6",               STRING,  &termcol6 },
	   { "color7",               STRING,  &termcol7 },
	   { "color8",               STRING,  &termcol8 },
	   { "color9",               STRING,  &termcol9 },
	   { "color10",              STRING,  &termcol10 },
	   { "color11",              STRING,  &termcol11 },
	   { "color12",              STRING,  &termcol12 },
	   { "color13",              STRING,  &termcol13 },
	   { "color14",              STRING,  &termcol14 },
	   { "color15",              STRING,  &termcol15 },
	   { "shell",                STRING,  &shell },
       { "status",               STRING,  &status },
       { "defaultname",          STRING,  &defaultname },
	   { "activeopacity",        STRING,  &activeopacity },
	   { "inactiveopacity",      STRING,  &inactiveopacity },
       { "lockfullscreen",       INTEGER, &lockfullscreen },
	   { "refreshrules",         INTEGER, &refreshrules },
	   { "borderpx",             INTEGER, &borderpx }, 
       { "snap",                 INTEGER, &snap },
       { "showbar",              INTEGER, &showbar },
       { "nmaster",              INTEGER, &nmaster },
	   { "rmaster",              INTEGER, &rmaster },
       { "resizehints",          INTEGER, &resizehints },
       { "startontag",           INTEGER, &startontag },
	   { "gappx",                INTEGER, &gappx },
       { "sizeicon",             INTEGER, &sizeicon },
	   { "decorhints",           INTEGER, &decorhints },
       { "swallowfloating",      INTEGER, &swallowfloating },
	   { "vertpad",              INTEGER, &vertpad },
	   { "sidepad",              INTEGER, &sidepad },
	   { "barheight",            INTEGER, &barheight },
	   { "centerfloating",       INTEGER, &centerfloating },
	   { "firstwindowsize",      INTEGER, &firstwindowsize },
	   { "savefloat",			 INTEGER, &savefloat },
	   { "warpcursor",			 INTEGER, &warpcursor },
	   { "pertag",			     INTEGER, &pertag },
	   { "i3nmaster",			 INTEGER, &i3nmaster },
	   { "monocleclientcount",	 INTEGER, &monocleclientcount },
	   { "mfact",                FLOAT,   &mfact },
/*       value in .Xresources    type     value in dwm */
};
