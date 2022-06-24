/* Color/Alpha settings
 * You probably don't need to change these unless you want special alpha settings.
 *
 * Once you're done with your edits, run 'make clean install'. */

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
