/* appearance */

// static unsigned int snap      = 32;       /* snap pixel */
//static unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
//static unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */
//static int usealtbar          = 0;        /* 1 means use non-dwm status bar */
//static char *altbarclass      = "Polybar"; /* Alternate bar class name */
//static char *altbarcmd        = "$HOME/.config/polybar/launch.sh"; /* Alternate bar launch command */

//--------------------------------------------------------------------------------------------------------//

/* static char *fonts[] */

//                                        "Roboto Mono=11:antialias=true:autohint=true",
//                                        "JetBrainsMonoNL-Bold:size=9:antialias=true:autohint=true",
//                                        "NotoColorEmoji:pixelsize=11:antialias=true:autohint=true",
//                                        "JoyPixels:pixelsize=11:antialias=true:autohint=true", 

//--------------------------------------------------------------------------------------------------------//

// static char normbgcolor[]           = "#222222"; // default
// static char normbgcolor[]           = "#000000"; // default

// static char selfgcolor[]            = "#eeeeee"; // default
// static char selbordercolor[]        = "#d1ac3e"; // gold border
// static char selbordercolor[]        = "#febca7"; // peach border
// static char selbordercolor[]        = "#45B3BE"; // Theme Teal
// static char selbordercolor[]        = "#66e3c6"; // My teal border color
// static char selbordercolor[]        = "#324c8d"; // My teal border color
// static char selbordercolor[]        = "#d4aa9d"; // pywal peach
// static char selbordercolor[]        = "#bd6069"; // nord red 
// static char selbordercolor[]        = "#e9c989"; // nord yellow 
//static char selbordercolor[]            = "#5dd386";  // tianshu green border

//static char selbordercolor[]        = "#88c0d0"; // nord blue
// static char selbordercolor[]        = "#770000"; // Luke Smith's red border color
//static char selbgcolor[]            = "#7d0202";  // red 
// static char selbgcolor[]            = "#6b4635";  // brown
// static char selbgcolor[]            = "#575b7f";  // reddit color
//static char selbgcolor[]            = "#57707f";  // tianshu green (also reddit color with green shift hue)

// static char selbgcolor[]            = "#c58f8d";  // pywal peach
// static char selbgcolor[]            = "#996863";  // pywal brown
//static char selbgcolor[]            = "#027d4c";  // green 
// static char selbgcolor[]            = "#005577";  // default 
// static char selbgcolor[]            = "#212121";  // gray 

//--------------------------------------------------------------------------------------------------------//

       /*               fg           bg           border   */

//       [SchemeNorm] = { normfgcolor, "#212121", normbordercolor },
//       [SchemeStatus] = { selfgcolor, "#212121", selbordercolor }, // Statusbar right
//       [SchemeTagsNorm] = { selfgcolor, "#212121", selbordercolor}, // Tagbar left unselected
//       [SchemeInfoSel] = { selfgcolor, "#212121", selbordercolor }, // infobar middle selected
//       [SchemeInfoNorm] = { selbgcolor, "#212121", selbordercolor }, // infobar middle unselected
//       [SchemeTagsSel] = { selfgcolor, selbgcolor, selbordercolor }, // Tagbar left selected
//       [SchemeTagsNorm] = { selfgcolor, selbgcolor, selbordercolor}, // Tagbar left unselected
//       [SchemeInfoSel] = { selbgcolor, selbgcolor, selbordercolor }, // infobar middle selected
//       [SchemeInfoNorm] = { selbgcolor, selbgcolor, selbordercolor }, // infobar middle unselected

//--------------------------------------------------------------------------------------------------------//

/* tagging */

// Firefox Icon: 
// Terminal Icon: 

//--------------------------------------------------------------------------------------------------------//

	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	*/
	/* class    instance      title       	 tags mask    isfloating   isterminal  noswallow  monitor */

	/* { "firefox",  NULL,       NULL,       	    1 << 1,       0,           0,         0,         0,        -1 }, */
	//{ "Brave",    NULL,       NULL,       	    1 << 3,       0,           0,         0,         0,        -1 },
	/* { TERMCLASS,  NULL,       NULL,       	    0,            0,           1,         0,        -1 }, */

//--------------------------------------------------------------------------------------------------------//

/* key definitions */

	/* { MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \ */
	/* { MOD, XK_a,     ACTION##stack, {.i = 1 } }, \ */
	/* { MOD, XK_z,     ACTION##stack, {.i = 2 } }, \ */
	/* { MOD, XK_x,     ACTION##stack, {.i = -1 } }, */

//--------------------------------------------------------------------------------------------------------//

	/* modifier                     key        function        argument */

	/* { MODKEY|ShiftMask,		XK_Escape,	spawn,	SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_grave,	togglescratch,	SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_Tab,		spawn,		SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_c,		killclient,	{0} }, */
	// { MODKEY,			XK_w,		spawn,		{.v = (const char*[]){ BROWSER, NULL } } },
	// { MODKEY|ShiftMask,		XK_w,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "sudo", "nmtui", NULL } } },
	// { MODKEY,			XK_e,		spawn,		SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks; rmdir ~/.abook") },
	/* { MODKEY|ShiftMask,		XK_e,		spawn,		SHCMD(TERMINAL " -e vim ~/vimwiki/index.wiki") }, */
	/* { MODKEY|ShiftMask,		XK_e,		spawn,		SHCMD(TERMINAL " -e sh ~/.config/gitpush.sh") }, */
	// { MODKEY|ShiftMask,		XK_e,		spawn,		SHCMD(TERMINAL " -e abook -C ~/.config/abook/abookrc --datafile ~/.config/abook/addressbook") },
	// { MODKEY,			XK_r,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "ytop", NULL } } },
	/* { MODKEY,			XK_r,		spawn,          SHCMD(TERMINAL " -e lf") }, */
	// { MODKEY|ShiftMask,		XK_r,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "htop", NULL } } },
	// { MODKEY,			XK_p,			spawn,		{.v = (const char*[]){ "mpc", "toggle", NULL } } },
	// { MODKEY|ShiftMask,		XK_p,			spawn,		SHCMD("mpc pause; pauseallmpv") },
	// { MODKEY,			XK_bracketleft,		spawn,		{.v = (const char*[]){ "mocp", "-k", "-10", NULL } } },
	// { MODKEY|ShiftMask,		XK_bracketleft,		spawn,		{.v = (const char*[]){ "mocp", "-k", "-60", NULL } } },
	// { MODKEY,			XK_bracketright,	spawn,		{.v = (const char*[]){ "mocp", "-k", "+10", NULL } } },
	// { MODKEY|ShiftMask,		XK_bracketright,	spawn,		{.v = (const char*[]){ "mpc", "-k", "+60", NULL } } },
	/* { MODKEY|ShiftMask,		XK_backslash,		spawn,		SHCMD("") }, */

	/* { MODKEY|ShiftMask,		XK_s,		spawn,		SHCMD("") }, */
	// { MODKEY,			XK_p,		spawn,          {.v = (const char*[]){ "dmenu_run", NULL } } },

	/* J and K are automatically bound above in STACKEYS */

	/* { MODKEY|ShiftMask,		XK_apostrophe,	spawn,		SHCMD("") }, */

	/* { MODKEY|ShiftMask,		XK_z,		spawn,		SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_x,		spawn,		SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_c,		spawn,		SHCMD("") }, */

	/* V is automatically bound above in STACKKEYS */

	/* { MODKEY|ShiftMask,		XK_b,		spawn,		SHCMD("") }, */
	// { MODKEY,			XK_n,		spawn,		SHCMD(TERMINAL " -e nvim ~/vimwiki/index.wiki") },
	// { MODKEY,			XK_m,		spawn,		SHCMD(TERMINAL " -e mocp") },

//--------------------------------------------------------------------------------------------------------//

	// { MODKEY,			XK_Insert,	spawn,		SHCMD("xdotool type $(grep -v '^#' ~/.local/share/larbs/snippets | dmenu -i -l 50 | cut -d' ' -f1)") },

//--------------------------------------------------------------------------------------------------------//

	/* { 0, XF86XK_Battery,		spawn,		SHCMD("") }, */

//--------------------------------------------------------------------------------------------------------//

	/* { MODKEY|Mod4Mask,              XK_h,      incrgaps,       {.i = +1 } }, */
	/* { MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } }, */
	/* { MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } }, */
	/* { MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } }, */
	/* { MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } }, */
	/* { MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } }, */
	/* { MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } }, */
	/* { MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } }, */
