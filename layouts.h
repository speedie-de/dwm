/* These are all available layouts in this build of dwm.
 * Any new layouts should be added in the exact same way as existing layouts.
 * Layouts that are added through patches should be in layouts.c
 *
 * Once you're done with your edits, run 'make clean install'. */

static const Layout layouts[]                 = {
    { "(L1)",          tile },
	{ "(L2)",          NULL },
	{ "(L3)",          monocle },
	{ "(L3)",          grid },
    { "(L4)",          deck },
    { "(L5)",          centeredmaster },
	{ "(L6)",          centeredfloatingmaster },
	{ "(L7)",          spiral },
	{ "(L8)",          dwindle },
	{ "(L9)",          tcl },
	{ "(L10)",         bstack },
	{ "(L11)",         bstackhoriz },
	{ "(L12)",         horizgrid },
	{ "(L13)",         tatami },
	{ "(L14)",	     tilewide },
	{ "(L15)",         stairs },
	{ "(L16)",         tile54 },
	{ NULL,              NULL },
};
