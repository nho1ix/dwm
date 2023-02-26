/* See LICENSE file for copyright and license details. */
/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"
#define BROWSER "chromium"

/* appearance */
static unsigned int borderpx  = 1;        /* border pixel of windows */
static unsigned int snap      = 6;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 5;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const unsigned int systrayiconsize = 25; /* systray icon size in px */
static const int showsystray        = 1;     /* 0 means no systray */
static unsigned int gappih    = 15;       /* horiz inner gap between windows */
static unsigned int gappiv    = 10;       /* vert inner gap between windows */
static unsigned int gappoh    = 20;       /* horiz outer gap between windows and screen edge */
static unsigned int gappov    = 20;       /* vert outer gap between windows and screen edge */
static int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static int showbar            = 1;        /* 0 means no bar */
static int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 0;        /* horizontal padding for statusbar */
static const int vertpadbar         = 15;        /* vertical padding for statusbar */
static const int vertpad = 0;     /* vertical padding of bar */
static const int sidepad = 0;     /* horizontal padding of bar */
static char *fonts[]          = { "Overpass:style=Regular:size=11:antialias=true:autohint=true", 
                                  "JetBrainsMono Nerd Font:style=regular:pixelsize=12" };
static char normbgcolor[]           = "#000000"; // default
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#FFFFFF";
static char selfgcolor[]            = "#FFFFFF";
static char selbordercolor[]            = "#9a9ac1";  // mark-lin mountain
static char selbgcolor[]            = "#212126";  // mark-lin mountain coolar
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  normfgcolor,  selbordercolor  },
       [SchemeStatus] = { selfgcolor, normbgcolor, selbordercolor }, // Statusbar right
       [SchemeTagsSel] = { selfgcolor, selbgcolor, selbordercolor }, // Tagbar left selected
       [SchemeTagsNorm] = { selfgcolor, normbgcolor, selbordercolor }, // Tagbar left unselecte
       [SchemeInfoSel] = { selfgcolor, normbgcolor, selbordercolor }, // infobar middle selected
       [SchemeInfoNorm] = { selbgcolor, normbgcolor, selbordercolor }, // infobar middle unselected
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-g", "120x34", NULL };
// const char *spcmd2[] = {TERMINAL, "-n", "spcalc", "-f", "Hermit:size=11", "-g", "50x20", "-e", "", "-lq", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	// {"spcalc",      spcmd2},
};

/* tagging */
static const char *tags[] = { "sys", "www", "dev", "chat", "game", "tv", "music", "yt", "rec" };
static const char *alttags[] = { "[sys]", "[www]", "[dev]", "[chat]", "[game]", "[tv]", "[music]", "[yt]", "[rec]" };

static char *tagsel[][2] = {
	{ "#84abeb", selbgcolor },
	{ "#e1b56a", selbgcolor },
	{ "#6fb482", selbgcolor },
	{ "#aa71f4", selbgcolor },
	{ "#dc5656", selbgcolor },
	{ "#ca9ee6", selbgcolor },
	{ "#33cc5e", selbgcolor },
	{ "#dc5656", selbgcolor },
	{ "#c2c2c2", selbgcolor },
};


static const unsigned int ulinepad	= 2;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* class    instance      title       	 tags mask    isfloating   isterminal  noswallow  monitor */
	{ "Gimp",     NULL,       NULL,       	    0,            0,           0,         0,         0,        -1 },
	{ TERMCLASS,   NULL,       NULL,       	    0,            0,           0,         1,         0,        -1 },
	{ "Spotify",  NULL,       NULL,             1 << 6,       0,           0,         0,         0,        -1 },
	{ "discord",  NULL,       NULL,             1 << 3,       0,           0,         0,         0,        -1 },
	{ "St",       NULL,       NULL,       	    0,            0,           0,         1,         0,        -1 },
	{ "obs",      NULL,       NULL,       	    1 << 8,       0,           0,         1,         0,        -1 },
	{ NULL,       NULL,       "Event Tester",   0,            0,           0,         1,        -1 },
	{ NULL,       NULL,       "ru-turikhay-tlauncher-bootstrap-Bootstrap",   0,            1,           1,         0,        -1 },
	{ TERMCLASS,      "bg",        NULL,       	    1 << 7,       0,           1,         0,        -1 },
	{ TERMCLASS,      "spterm",    NULL,       	    SPTAG(0),     1,           1,         0,        -1 },
	{ TERMCLASS,      "spcalc",    NULL,       	    SPTAG(1),     1,           1,         0,        -1 },
};

/* layout(s) */
static float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static int lpm[] = {
        /* Index of preferred layout], if LENGTH(lpm)<#monitors -> default layout */
        0, 1
};


#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",	tile },			/* Default: Master on left, slaves on right */
	{ "TTT",	bstack },		/* Master on top, slaves on bottom */

	{ "[@]",	spiral },		/* Fibonacci spiral */
	{ "[\\]",	dwindle },		/* Decreasing in size right and leftward */

	{ "[D]",	deck },			/* Master on left, slaves in monocle-like mode on right */
	{ "[M]",	monocle },		/* All windows on top of eachother */

	{ "|M|",	centeredmaster },		/* Master in middle, slaves on sides */
	{ ">M>",	centeredfloatingmaster },	/* Same but master floats */

	{ "><>",	NULL },			/* no layout function means floating behavior */
	{ NULL,		NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define WINKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD,	XK_j,	ACTION##stack,	{.i = INC(+1) } }, \
	{ MOD,	XK_k,	ACTION##stack,	{.i = INC(-1) } }, \
	{ MOD,  XK_v,   ACTION##stack,  {.i = 0 } }, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { TERMINAL, NULL };

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		// { "color0",		STRING,	&normbordercolor },
		// { "color8",		STRING,	&selbordercolor },
		{ "color17",		STRING,	&normbgcolor },
		{ "color18",		STRING,	&normfgcolor },
		{ "color18",		STRING,	&selfgcolor },
		{ "color19",		STRING,	&selbgcolor },
		{ "borderpx",		INTEGER, &borderpx },
		{ "snap",		INTEGER, &snap },
		{ "showbar",		INTEGER, &showbar },
		{ "topbar",		INTEGER, &topbar },
		{ "nmaster",		INTEGER, &nmaster },
		{ "resizehints",	INTEGER, &resizehints },
		{ "mfact",		FLOAT,	&mfact },
		{ "gappih",		INTEGER, &gappih },
		{ "gappiv",		INTEGER, &gappiv },
		{ "gappoh",		INTEGER, &gappoh },
		{ "gappov",		INTEGER, &gappov },
		{ "swallowfloating",	INTEGER, &swallowfloating },
		{ "smartgaps",		INTEGER, &smartgaps },
};

#include <X11/XF86keysym.h>
#include "shiftview.c"

static const Key keys[] = {
	/* modifier                     key        function        argument */
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
	{ MODKEY,			XK_grave,	spawn,	{.v = (const char*[]){ "dmenuunicode", NULL } } },
	{ False|ControlMask,		XK_grave,	spawn,	{.v = (const char*[]){ "wired", "-s", "1", NULL } } },
	TAGKEYS(			XK_1,		0)
	TAGKEYS(			XK_2,		1)
	TAGKEYS(			XK_3,		2)
	TAGKEYS(			XK_4,		3)
	TAGKEYS(			XK_5,		4)
	TAGKEYS(			XK_6,		5)
	TAGKEYS(			XK_7,		6)
	TAGKEYS(			XK_8,		7)
	TAGKEYS(			XK_9,		8)
	{ MODKEY,			XK_0,		view,		{.ui = ~0 } },
	{ MODKEY|ShiftMask,		XK_0,		tag,		{.ui = ~0 } },
	{ MODKEY,			XK_minus,	spawn,		SHCMD("pamixer --allow-boost -d 5; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		XK_minus,	spawn,		SHCMD("pamixer --allow-boost -d 15; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			XK_equal,	spawn,		SHCMD("pamixer --allow-boost -i 5; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		XK_equal,	spawn,		SHCMD("pamixer --allow-boost -i 15; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			XK_BackSpace,	quit,		{1} },
	{ MODKEY,			XK_Tab,		view,		{0} },
	{ MODKEY|ShiftMask,		XK_q,		killclient,		{0} },
	{ MODKEY,			XK_w,		spawn,		{.v = (const char*[]){ "chromium", NULL } } },
	{ MODKEY|ShiftMask,		XK_w,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "sudo", "nmtui", NULL } } },
	{ MODKEY,			XK_e,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "thunderbird", NULL } } },
	{ MODKEY,			XK_r,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "ytop", NULL } } },
	{ MODKEY|ShiftMask,		XK_r,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "htop", NULL } } },
	{ MODKEY,			XK_t,		setlayout,	{.v = &layouts[0]} }, /* tile */
	{ MODKEY|ShiftMask,		XK_t,		setlayout,	{.v = &layouts[1]} }, /* bstack */
	{ MODKEY,			XK_y,		setlayout,	{.v = &layouts[2]} }, /* spiral */
	{ MODKEY|ShiftMask,		XK_y,		setlayout,	{.v = &layouts[3]} }, /* dwindle */
	{ MODKEY,			XK_u,		setlayout,	{.v = &layouts[4]} }, /* deck */
	{ MODKEY|ShiftMask,		XK_u,		setlayout,	{.v = &layouts[5]} }, /* monocle */
	{ MODKEY,			XK_i,		setlayout,	{.v = &layouts[6]} }, /* centeredmaster */
	{ MODKEY|ShiftMask,		XK_i,		setlayout,	{.v = &layouts[7]} }, /* centeredfloatingmaster */
	{ MODKEY,			XK_o,		incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,		XK_o,		incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,		XK_p,			spawn,          {.v = (const char*[]){ TERMINAL, "-e", ".config/vifm/scripts/vifmrun", NULL } } }, 
	{ MODKEY,			XK_bracketleft,		spawn,		{.v = (const char*[]){ "playerctl", "position", "10-", NULL } } },
	{ MODKEY|ShiftMask,		XK_bracketleft,		spawn,		{.v = (const char*[]){ "playerctl", "position", "60-", NULL } } },
	{ MODKEY,			XK_bracketright,	spawn,		{.v = (const char*[]){ "playerctl", "position", "10+", NULL } } },
	{ MODKEY|ShiftMask,		XK_bracketright,	spawn,		{.v = (const char*[]){ "playerctl", "position", "60+", NULL } } }, 
	{ MODKEY,			XK_backslash,		view,		{0} },

	{ MODKEY,			XK_a,		togglegaps,	{0} },
	{ MODKEY|ShiftMask,		XK_a,		defaultgaps,	{0} },
	{ MODKEY,			XK_s,		togglesticky,	{0} },
	{ MODKEY,			XK_p,		spawn,          {.v = (const char*[]){ "dmenu_run", NULL } } },
	{ MODKEY,			XK_f,		togglefullscr,	{0} },
	{ MODKEY|ShiftMask,		XK_f,		setlayout,	{.v = &layouts[8]} },
	{ MODKEY,			XK_g,		shiftview,	{ .i = -1 } },
	{ MODKEY|ShiftMask,		XK_g,		shifttag,	{ .i = -1 } },
	{ MODKEY,			XK_h,		setmfact,	{.f = -0.01} },

	/* J and K are automatically bound above in STACKEYS */
	{ MODKEY,			XK_l,		setmfact,      	{.f = +0.01} },
	{ MODKEY|ShiftMask,			XK_h,		setcfact,      	{.f = +0.05} },
	{ MODKEY|ShiftMask,			XK_l,		setcfact,      	{.f = -0.05} },
	{ MODKEY,			XK_q,		setcfact,      	{.f =  0.00} },
	// { MODKEY,			XK_d,		spawn,		SHCMD(TERMINAL " -e ikhal") },
	{ MODKEY,			XK_d,		spawn,		{.v = (const char*[]){ "discord", "--disable-frame-rate-limit", NULL } } },
	{ MODKEY,			XK_semicolon,	shiftview,	{ .i = 1 } },
	{ MODKEY|ShiftMask,		XK_semicolon,	shifttag,	{ .i = 1 } },
	{ MODKEY,			XK_apostrophe,	spawn,		SHCMD("playerctl -p spotify play-pause && sh ~/.config/scripts/play-pause.sh") },
	{ MODKEY|ShiftMask,		XK_apostrophe,	togglesmartgaps,	{0} },
	{ MODKEY,			XK_Return,	spawn,		{.v = termcmd } },
	{ MODKEY|ShiftMask,		XK_Return,	togglescratch,	{.ui = 0} },

	{ MODKEY,			XK_z,		incrgaps,	{.i = +3 } },
	{ MODKEY,			XK_x,		incrgaps,	{.i = -3 } },
	// { MODKEY,			XK_c,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "profanity", NULL } } },
	{ MODKEY|ShiftMask,		XK_c,		spawn,		{.v = (const char*[]){ "firefox", NULL } } }, 
	/* V is automatically bound above in STACKKEYS */
	{ MODKEY,			XK_b,		togglebar,	{0} },
	{ MODKEY|ShiftMask,		XK_b,		spawn,	        {.v = (const char*[]){ "brave", NULL } } },
	{ MODKEY,			XK_n,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "nvim", "-c", "VimwikiIndex", NULL } } },
	{ MODKEY|ShiftMask,		XK_n,		spawn,		SHCMD(TERMINAL " -e newsboat ; pkill -RTMIN+6 dwmblocks") },
	{ MODKEY,			XK_m,		spawn,		{.v = (const char*[]){ "spotify", NULL } } },
	{ MODKEY|ShiftMask,		XK_m,		spawn,		SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			XK_comma,	spawn,		{.v = (const char*[]){ "playerctl", "-p", "spotify", "previous", NULL } } },
	{ MODKEY|ShiftMask,		XK_comma,	spawn,		{.v = (const char*[]){ "mocp", "-j", "N{%,0}", NULL } } },
	{ MODKEY,			XK_period,	spawn,		{.v = (const char*[]){ "playerctl", "-p", "spotify", "next", NULL } } },
	{ MODKEY|ShiftMask,		XK_period,	spawn,		{.v = (const char*[]){ "mocp", "-t", "repeat", NULL } } },

	{ MODKEY,			XK_Left,	focusmon,	{.i = -1 } },
	{ MODKEY|ShiftMask,		XK_Left,	tagmon,		{.i = -1 } },
	{ MODKEY,			XK_Right,	focusmon,	{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_Right,	tagmon,		{.i = +1 } },

	{ MODKEY,			XK_Page_Up,	spawn,   	{.v = (const char*[]){ "xfce4-screenshooter", "-f", "-s", "Pictures/Screenshots/Temporary", NULL } } },
	{ MODKEY,			XK_Page_Down,	spawn,   	{.v = (const char*[]){ "xfce4-screenshooter", "-r", "-s", "Pictures/Screenshots/Temporary", NULL } } },
	{ MODKEY,			XK_Insert, 	spawn,		SHCMD("setxkbmap dvorak -option capslock:backspace && sh ~/.config/scripts/setxkbmap_dvorak.sh") },
	{ MODKEY,			XK_End,	  	spawn,		{.v = (const char*[]){ "killall", "xinit", NULL } } },

	{ MODKEY,			XK_F1,		spawn,		SHCMD("sudo sync; echo 3 | sudo tee /proc/sys/vm/drop_caches && sh ~/.config/scripts/dcram.sh") },
	{ MODKEY,			XK_F2,		spawn,		{.v = (const char*[]){ "sh", "Documents/Important Files/Crontabs/Pacman Auto-Download.sh", NULL } } },
	{ MODKEY,			XK_F3,		spawn,		SHCMD("sct 4500 && xsct -c 1 3800 && sh ~/.config/scripts/sct.sh") },
	{ MODKEY,			XK_F4,		spawn,		SHCMD("sct 3000 && sh ~/.config/scripts/sct.sh") },
	{ MODKEY,			XK_F5,  	spawn,		{.v = (const char*[]){ "sh", ".local/bin/dmenu-change-mode", NULL } } },
	{ MODKEY,			XK_F6,		spawn,		SHCMD("feh --bg-fill ~/.config/wall/cloudy_mountains.jpg --bg-fill ~/.config/wall/DSCF0180.JPG") },
	{ MODKEY,			XK_F7,		spawn,		SHCMD("feh --bg-fill ~/.config/wall/latest.png --bg-fill ~/.config/wall/DSCF0180.JPG") },
	{ MODKEY,			XK_F8,		spawn,		SHCMD("xrandr --output DisplayPort-0 --primary --mode 3840x2160_100 --pos 1512x490 --rotate normal --output HDMI-A-0 --mode 1920x1080_74 --pos 0x0 --rotate left --scale 1.4x1.4") },
	{ MODKEY,			XK_F10,		spawn,		{.v = (const char*[]){ "sudo", "systemctl", "suspend", NULL } } },
	{ MODKEY,			XK_F11,		spawn,		SHCMD("killall -9 dwmblocks && dwmblocks") },
	{ MODKEY,			XK_F12,		spawn,		{.v = (const char*[]){ "picom", NULL } } }, 
	{ MODKEY,			XK_space,	zoom,		{0} },
	{ WINKEY,			XK_space,	spawn,		{.v = (const char*[]){ "wired", "-d", "latest", NULL } } },
	{ MODKEY|ShiftMask,		XK_space,	togglefloating,	{0} },

	{ 0, XF86XK_AudioMute,		spawn,		SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("playerctl -p spotify volume 0.02+ && sh ~/.config/scripts/volume.sh") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("playerctl -p spotify volume 0.02- && sh ~/.config/scripts/volume.sh") },
	{ 0, XF86XK_AudioPause,		spawn,		{.v = (const char*[]){ "playerctl", "pause", NULL } } },
	{ 0, XF86XK_AudioPlay,		spawn,		{.v = (const char*[]){ "playerctl", "play-pause", NULL } } },
	{ 0, XF86XK_AudioStop,		spawn,		{.v = (const char*[]){ "playerctl", "stop", NULL } } },
	{ 0, XF86XK_AudioRewind,	spawn,		{.v = (const char*[]){ "playerctl", "position 10-", NULL } } },
	{ 0, XF86XK_AudioForward,	spawn,		{.v = (const char*[]){ "playerctl", "position 10+", NULL } } },
	{ 0, XF86XK_AudioMedia,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "ncmpcpp", NULL } } },
	{ 0, XF86XK_AudioMicMute,	spawn,		SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
	{ 0, XF86XK_Calculator,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "qalc", NULL } } },
	{ 0, XF86XK_Explorer,		spawn,		{.v = (const char*[]){ "obs", NULL } } },
	{ 0, XF86XK_Sleep,		spawn,		{.v = (const char*[]){ "sudo", "-A", "zzz", NULL } } },
	{ 0, XF86XK_WWW,		spawn,		{.v = (const char*[]){ BROWSER, NULL } } },
	{ 0, XF86XK_DOS,		spawn,		{.v = termcmd } },
	{ 0, XF86XK_ScreenSaver,	spawn,		SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
	{ 0, XF86XK_TaskPane,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "htop", NULL } } },
	{ 0, XF86XK_Mail,		spawn,		{.v = (const char*[]){ "xev", NULL } } },
	{ 0, XF86XK_MyComputer,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "lfub /", NULL } } },
	{ 0, XF86XK_Launch1,		spawn,		{.v = (const char*[]){ "xset", "dpms", "force", "off", NULL } } },
	{ 0, XF86XK_TouchpadToggle,	spawn,		SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
	{ 0, XF86XK_TouchpadOff,	spawn,		{.v = (const char*[]){ "synclient", "TouchpadOff=1", NULL } } },
	{ 0, XF86XK_TouchpadOn,		spawn,		{.v = (const char*[]){ "synclient", "TouchpadOff=0", NULL } } },
	{ 0, XF86XK_MonBrightnessUp,	spawn,		SHCMD("xbacklight -inc 2 && sh ~/.config/scripts/xbacklight.sh") },
	{ 0, XF86XK_MonBrightnessDown,	spawn,		SHCMD("xbacklight -dec 2 && sh ~/.config/scripts/xbacklight.sh") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
#ifndef __OpenBSD__
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
#endif
	{ ClkStatusText,        ShiftMask,      Button3,        spawn,          {.v = (const char*[]){ TERMINAL, "-e", "vim", ".local/src/dwmblocks/config.h", NULL } } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        defaultgaps,	{0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,		MODKEY,		Button4,	incrgaps,	{.i = +1} },
	{ ClkClientWin,		MODKEY,		Button5,	incrgaps,	{.i = -1} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,		0,		Button4,	shiftview,	{.i = -1} },
	{ ClkTagBar,		0,		Button5,	shiftview,	{.i = 1} },
	{ ClkRootWin,		0,		Button2,	togglebar,	{0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};

