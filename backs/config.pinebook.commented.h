
/* appearance */

// static unsigned int snap      = 32;       /* snap pixel */
//static unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
//static unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */

//--------------------------------------------------------------------------------------------------------//

/* static char *fonts[] */

//                                        "Roboto Mono=11:antialias=true:autohint=true",
//                                        "JetBrainsMonoNL-Bold:size=9:antialias=true:autohint=true",
//                                        "NotoColorEmoji:pixelsize=11:antialias=true:autohint=true",
//                                        "JoyPixels:pixelsize=11:antialias=true:autohint=true", 
//                                        "Hermit:pixelsize=12:antialias=true:autohint=true" 

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

/*
 * Xresources preferences to load at startup
 */

// ResourcePref resources[] = {
		// { "color0",		STRING,	&normbordercolor },
		// { "color8",		STRING,	&selbordercolor },
		// { "color0",		STRING,	&normbgcolor },
		// { "color4",		STRING,	&normfgcolor },
		// { "color0",		STRING,	&selfgcolor },
		// { "color4",		STRING,	&selbgcolor },

//--------------------------------------------------------------------------------------------------------//

	/* modifier                     key        function        argument */

	/* { MODKEY|ShiftMask,		XK_Escape,	spawn,	SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_grave,	togglescratch,	SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_Tab,		spawn,		SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_c,		killclient,	{0} }, */
	/* { MODKEY,			XK_e,		spawn,          SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks; rmdir ~/.abook") }, */
	/* { MODKEY|ShiftMask,		XK_e,		spawn,		SHCMD(TERMINAL " -e vim ~/vimwiki/index.wiki") }, */
	/* { MODKEY|ShiftMask,		XK_e,		spawn,		SHCMD(TERMINAL " -e sh ~/.config/gitpush.sh") }, */
	/* { MODKEY|ShiftMask,		XK_e,		spawn,          SHCMD(TERMINAL " -e abook -C ~/.config/abook/abookrc --datafile ~/.config/abook/addressbook") }, */
	/* { MODKEY,			XK_r,		spawn,          SHCMD(TERMINAL " -e lf") }, */
	/* { MODKEY,			XK_p,			spawn,          SHCMD("mpc toggle") }, */
	/* { MODKEY|ShiftMask,		XK_p,			spawn,          SHCMD("mpc pause ; pauseallmpv") }, */
	/* { MODKEY|ShiftMask,		XK_backslash,		spawn,		SHCMD("") }, */


	/* { MODKEY|ShiftMask,		XK_s,		spawn,		SHCMD("") }, */
	/* { MODKEY,			XK_d,		spawn,		SHCMD("") } }, */
	/* J and K are automatically bound above in STACKEYS */
	/* { MODKEY|ShiftMask,		XK_apostrophe,	spawn,		SHCMD("") }, */

	/* { MODKEY|ShiftMask,		XK_z,		spawn,		SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_x,		spawn,		SHCMD("") }, */
	/* { MODKEY,			XK_c,		spawn,		SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_c,		spawn,		SHCMD("") }, */
	/* V is automatically bound above in STACKKEYS */
	/* { MODKEY|ShiftMask,		XK_b,		spawn,		SHCMD("") }, */

//	{ MODKEY,			XK_Page_Up,	shiftview,	{ .i = -1 } },
//      { MODKEY,			XK_Page_Up,	spawn,   	SHCMD("maim ~/Pictures/Screenshots/Temporary/$(date +%m%d%y-%I:%M%p).png") },
//	{ MODKEY|ShiftMask,		XK_Page_Up,	shifttag,	{ .i = -1 } },
//	{ MODKEY,			XK_Page_Down,	shiftview,	{ .i = +1 } },
//	{ MODKEY,			XK_Page_Down,	spawn,   	SHCMD("maim -s ~/Pictures/Screenshots/Temporary/$(date +%m%d%y-%I:%M%p).png") },
//	{ MODKEY|ShiftMask,		XK_Page_Down,	shifttag,	{ .i = +1 } },
//      { MODKEY,			XK_Insert,	spawn,		SHCMD("notify-send \"📋 Clipboard contents:\" \"$(xclip -o -selection clipboard)\"") },
//        { MODKEY,			XK_F2,		spawn,		SHCMD("spotify") },
//        { MODKEY,			XK_F3,		spawn,		SHCMD("displayselect") },
	//{ MODKEY,			XK_F3,		spawn,          SHCMD("signal-desktop-beta") },
	/* { MODKEY,			XK_F4,		spawn,          SHCMD(TERMINAL " -e pulsemixer; kill -44 $(pidof dwmblocks)") }, */
	/* { MODKEY,			XK_F5,		xrdb,		{.v = NULL } }, */
	/* { MODKEY,			XK_F5,		spawn,		SHCMD("discord") }, */
	/* { MODKEY,			XK_F6,		spawn,		SHCMD("torwrap") }, */
	/* { MODKEY,			XK_F7,		spawn,		SHCMD("td-toggle") }, */
	/* { MODKEY,			XK_F8,		spawn,		SHCMD("mailsync") }, */
	/* { MODKEY,			XK_F9,		spawn,		SHCMD("dmenumount") }, */
//	{ MODKEY,			XK_F10,		spawn,		SHCMD("betterlockscreen -s") },
	/* { MODKEY,			XK_F10,		spawn,		SHCMD("sudo systemctl suspend && slock") }, */
	/* { MODKEY,			XK_F10,		spawn,		SHCMD("dmenuumount") }, */
	/* { MODKEY,			XK_F11,		spawn,
        ** SHCMD("mpv --no-cache --no-osc --no-input-default-bindings
        ** --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] |
        ** tail -n 1)") }, */
	/* { MODKEY,			XK_F12,		xrdb,		{.v = NULL } }, */
	/* { MODKEY,			XK_F12,		spawn,           SHCMD("slock") }, */

//      { 0,				XK_Print,	spawn,		SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png") },
//      { ShiftMask,			XK_Print,	spawn,		SHCMD("maimpick") },
//      { MODKEY,			XK_Print,	spawn,		SHCMD("dmenurecord") },
//      { MODKEY|ShiftMask,		XK_Print,	spawn,		SHCMD("dmenurecord kill") },
//      { MODKEY,			XK_Delete,	spawn,		SHCMD("dmenurecord kill") },
//      { MODKEY,			XK_Scroll_Lock,	spawn,		SHCMD("killall screenkey || screenkey &") },

	/* { 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("pamixer --allow-boost -i 2; pkill -RTMIN+2 goblocks") }, */
	/* { 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("pamixer --allow-boost -d 2; pkill -RTMIN+2 goblocks") }, */
	/* { 0, XF86XK_PowerOff,		spawn,		SHCMD("sysact") }, */
	/* { 0, XF86XK_Battery,		spawn,		SHCMD("") }, */

	/* { MODKEY|Mod4Mask,              XK_h,      incrgaps,       {.i = +1 } }, */
	/* { MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } }, */
	/* { MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } }, */
	/* { MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } }, */
	/* { MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } }, */
	/* { MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } }, */
	/* { MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } }, */
	/* { MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } }, */
