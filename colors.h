/* Color/Alpha settings
 * You probably don't need to change these unless you want special alpha settings.
 *
 * Once you're done with your edits, run 'make clean install'. */

/* Define
 * This build comes with defines for common software such as your web browser or terminal.
 * If you wish to use a different browser for example, simply change the values.
 *
 * You do not need to edit 'keybinds.h' or 'rules.h' because that's where these are used.
 * Once you're done with your edits, run 'make clean install'.
 *************************************/

/* Misc color options */
static char *colors[][3]                      = {
	[SchemeNorm]                              = { col_textnorm, col_background,    col_windowbordernorm },
	[SchemeSel]                               = { col_textsel,  col_backgroundmid, col_windowbordersel }, 
	[SchemeHid]                               = { col_backgroundmid, col_background, col_backgroundmid  },
	[SchemeLIndicator]                        = { col_layouttext, col_layoutbgnorm, col_layoutbgsel },
/*                                                text          background         window border */
};

/* Colors for the status bar (.Xresources) */
static char *termcolor[]                      = {
  termcol0,
  termcol1,
  termcol2,
  termcol3,
  termcol4,
  termcol5,
  termcol6,
  termcol7,
  termcol8,
  termcol9,
  termcol10,
  termcol11,
  termcol12,
  termcol13,
  termcol14,
  termcol15,
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
static const unsigned int tagalpha[]          = { baralpha, baralpha };
