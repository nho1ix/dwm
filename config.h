/* See LICENSE file for copyright and license details. */
/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"
#define STATUSBAR "dwmblocks"
static const char *discord[] = { "/usr/bin/vesktop" };
static const char *email[]   = { "/usr/bin/thunderbird" };
static const char *music[]   = { "/usr/bin/spotify" };

/* appearance */
static const unsigned int borderpx           = 1;        /* border pixel of windows */
static const unsigned int snap               = 6;       /* snap pixel */
static const unsigned int systraypinning     = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft      = 0;  	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing     = 5;   /* systray spacing */
static const unsigned int systrayiconsize    = 25;  /* systray icon size in px */
static const unsigned int systraypinningfailfirst   = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const unsigned int showsystray        = 1;       /* 0 means no systray */
static const unsigned int gappih             = 0;       /* horiz inner gap between windows. default=15 */
static const unsigned int gappiv             = 0;       /* vert inner gap between windows. default=10 */
static const unsigned int gappoh             = 0;       /* horiz outer gap between windows and screen edge. default=20 */
static const unsigned int gappov             = 0;       /* vert outer gap between windows and screen edge. default=20 */
static const unsigned int swallowfloating    = 0;       /* 1 means swallow floating windows by default */
static const unsigned int showbar            = 1;       /* 0 means no bar */
static const unsigned int topbar             = 1;       /* 0 means bottom bar */
static const unsigned int mon_refresh        = 165;     /* monitor refresh rate */
static const unsigned int horizpadbar        = 0;       /* horizontal padding for statusbar */
static const unsigned int vertpadbar         = 15;      /* vertical padding for statusbar */
static const unsigned int vertpad            = 0;       /* vertical padding of bar */
static const unsigned int sidepad            = 0;       /* horizontal padding of bar */
static const unsigned int markup             = 1;       /* process status2d text */
static unsigned int smartgaps                = 0;       /* 1 means no outer gap when there is only one window */
static char *fonts[]     = { "Overpass:style=Regular:size=11:antialias=true:autohint=true", 
                             "JetBrainsMono NFM:style=Regular:size=18:antialias=true:autohint=true" };
static char normbgcolor[]           = "#000000"; // default
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#FFFFFF";
static char selfgcolor[]            = "#FFFFFF";
static char selbordercolor[]        = "#8eacbd";  // mark-lin mountain
static char selbgcolor[]            = "#212126";  // selected bg tag color
static char textbgcolor[]           = "#b3b3b3";  // unselected monitor text
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] 		= { normfgcolor, normbgcolor,  normbordercolor },
       [SchemeSel]  		= { selfgcolor,  normfgcolor,  selbordercolor  },
       [SchemeStatus] 	= { selfgcolor,  normbgcolor,  selbordercolor }, // Statusbar right
       [SchemeTagsSel] 	= { selfgcolor,  selbgcolor,   selbordercolor }, // Tagbar left selected
       [SchemeTagsNorm] = { selfgcolor,  normbgcolor,  selbordercolor }, // Tagbar left unselected
       [SchemeInfoSel] 	= { selfgcolor,  normbgcolor,  selbordercolor }, // infobar middle selected
       [SchemeInfoNorm] = { textbgcolor, normbgcolor,  selbordercolor }, // infobar middle unselected
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-g", "120x34", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
};

/* tagging */
static const char *tags[] = { 
	"", // 1st
	"", // 2nd
	"󰆩", // 3rd
	"", // 4th
	"󰍡", // 5th
	"", // 6th
	"", // 7th
	"", // 8th
	""  // 9th
};

static const char *alttags[] = { 
	"", // 1st
	"", // 2nd 
	"󰆩", // 3rd 
	"", // 4th 
	"󰍡", // 5th 
	"", // 6th 
	"", // 7th 
	"", // 8th 
	""  // 9th
};

static char *tagsel[][2] = {
	{ "#84abeb", selbgcolor },
	{ "#df6c2a", selbgcolor },
	{ "#e1b56a", selbgcolor },
	{ "#aa71f4", selbgcolor },
	{ "#ca9ee6", selbgcolor },
	{ "#6fb482", selbgcolor },
	{ "#33cc5e", selbgcolor },
	{ "#dc5656", selbgcolor },
	{ "#c2c2c2", selbgcolor },
};

static const unsigned int ulinepad			= 2;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke		= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const unsigned int ulineall 			= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* class    instance      title       	 tags mask    isfloating   isterminal  noswallow  monitor */
	{ TERMCLASS,   NULL,       NULL,       	    0,            0,           0,         1,         0,       -1 },
	{ "Spotify",  NULL,       NULL,             1 << 6,       0,           0,         1,         0,        1 },
	{ "discord",  NULL,       NULL,             1 << 3,       0,           0,         0,         0,        1 },
	{ "vesktop",  NULL,       NULL,             1 << 3,       0,           0,         0,         0,        1 },
	{ "obs",      NULL,       NULL,       	    1 << 8,       0,           0,         1,         0,        1 },
	{ "St",       NULL,       "weechat",       	1 << 4,       0,           0,         1,         0,        1 },
	{ "St",       NULL,       NULL,       	    0,            0,           0,         1,         0,       -1 },
	{ NULL,       NULL,       "Event Tester",   0,            0,           0,         1,        -1 },
	{ TERMCLASS,      "bg",        NULL,       	1 << 7,       0,           1,         0,        -1 },
	{ TERMCLASS,      "spterm",    NULL,       	SPTAG(0),     1,           1,         0,        -1 },
	{ NULL,       NULL,       "ru-turikhay-tlauncher-bootstrap-Bootstrap",   0,            1,           1,         0,        -1 },
};

/* layout(s) */
static float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static unsigned int nmaster     = 1;    /* number of clients in master area */
static unsigned int resizehints = 0;    /* 1 means respect program default minimum window size. Default = 0 */

static unsigned int lpm[] = {
        /* Index of preferred layout], if LENGTH(lpm)<#monitors -> default layout */
        0, 1
};

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",	tile },			/* Default: Master on left, slaves on right */
	{ "TTT",	bstack },		/* Master on top, slaves on bottom */

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
#define SHCMD(cmd) {.v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define STCMD(cmd) {.v = (const char*[]){ TERMINAL, "-e", cmd, NULL } }

/* helper for 1-liner commands */
#define STRAIGHT(cmd) {.v = (const char*[]){ cmd, NULL } }

/* commands */
static const char *termcmd[]  = { TERMINAL, NULL };
static const char *dmenucmd[] = { "dmenu_run", NULL };

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "color17",		STRING,	&normbgcolor },
		{ "color18",		STRING,	&normfgcolor },
		{ "color18",		STRING,	&selfgcolor },
		{ "nmaster",		INTEGER, &nmaster },
		{ "resizehints",	INTEGER, &resizehints },
		{ "smartgaps",		INTEGER, &smartgaps },
		{ "mfact",		FLOAT,	&mfact },
};

#include <X11/XF86keysym.h>
#include "shiftview.c"

static const Key keys[] = {
	/* modifier                     key        function        argument */
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
	{ MODKEY,			XK_grave,	spawn,	STRAIGHT("dmenuunicode") },
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

	/* Application Keybinds */
	{ MODKEY,			XK_w,		spawn,		STRAIGHT("firefox") },
	{ MODKEY,			XK_d,		spawn,		{.v = discord } },  
	{ MODKEY,			XK_e,		spawn,		{.v = email } },  
	{ MODKEY,			XK_n,		spawn,		STCMD("nvim") },
	{ MODKEY,			XK_m,		spawn,		{.v = music } },  
	{ MODKEY|ShiftMask,		XK_b,		spawn,	  STRAIGHT("ebook-viewer") },
	{ MODKEY|ShiftMask,		XK_c,		spawn,		STRAIGHT("chromium") },
	{ MODKEY|ShiftMask,			XK_m,		spawn,		STRAIGHT("obsidian") },
	{ MODKEY|ShiftMask,			XK_n,		spawn,		STRAIGHT("davinci") },
	{ MODKEY|ShiftMask,	  	XK_p,		spawn,    STCMD(".config/vifm/scripts/vifmrun") },
	
	/* DWM Layouts */
	{ MODKEY,			XK_t,		setlayout,	{.v = &layouts[0]} }, /* tile */
	{ MODKEY|ShiftMask,		XK_t,		setlayout,	{.v = &layouts[1]} }, /* bstack */
	{ MODKEY,			XK_u,		setlayout,	{.v = &layouts[2]} }, /* deck */
	{ MODKEY|ShiftMask,		XK_u,		setlayout,	{.v = &layouts[3]} }, /* monocle */
	{ MODKEY,			XK_i,		setlayout,	{.v = &layouts[4]} }, /* centeredmaster */
	{ MODKEY|ShiftMask,		XK_i,		setlayout,	{.v = &layouts[5]} }, /* centeredfloatingmaster */
	{ MODKEY|ShiftMask,		XK_f,		setlayout,	{.v = &layouts[6]} }, /* fullscreen */

	/* Console / Terminal Programs */
	{ MODKEY,			XK_Return,	spawn,		{.v = termcmd } },
	{ MODKEY,			XK_p,		spawn,        {.v = dmenucmd} },
	{ MODKEY,			XK_r,		spawn,				STCMD("") },
	{ MODKEY|ShiftMask,		XK_Return,				togglescratch,	{.ui = 0} },
	{ MODKEY|ShiftMask,		XK_w,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "sudo", "nmtui", NULL } } },
	{ MODKEY|ShiftMask,		XK_r,		spawn,		STCMD("htop") },

	/* Spotify Keybinds */
	{ MODKEY,			XK_apostrophe,	spawn,		SHCMD("playerctl play-pause -p spotify && ~/.config/scripts/play-pause-spotify.sh") },
	{ MODKEY,			XK_comma,				spawn,		SHCMD("playerctl -p spotify previous && ~/.local/bin/statusbar/sb-music_name; pkill -RTMIN+22 dwmblocks") },
	{ MODKEY,			XK_period,			spawn,		SHCMD("playerctl -p spotify next && ~/.local/bin/statusbar/sb-music_name; pkill -RTMIN+22 dwmblocks") },
	{ MODKEY|ShiftMask,			XK_apostrophe,	spawn,		SHCMD("playerctl play-pause -p $(playerctl -l | rg firefox) && sh ~/.config/scripts/play-pause.sh") },
	{ MODKEY|ShiftMask,			XK_comma,				spawn,		SHCMD("mpc prev; pkill -RTMIN+12 dwmblocks") },
	{ MODKEY|ShiftMask,			XK_period,			spawn,		SHCMD("mpc next; pkill -RTMIN+12 dwmblocks") },

	/* Master Volume Controls */
	{ MODKEY,			XK_minus,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%-; pkill -RTMIN+10 dwmblocks") },
	{ MODKEY,			XK_equal,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+; pkill -RTMIN+10 dwmblocks") },
	{ MODKEY|ShiftMask,		XK_minus,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%-; pkill -RTMIN+10 dwmblocks") },
	{ MODKEY|ShiftMask,		XK_equal,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%+; pkill -RTMIN+10 dwmblocks") },

	/* Music / Playback Controls */
	{ MODKEY,			XK_bracketleft,		spawn,		SHCMD("playerctl position 10- && ~/.config/scripts/skip-spotify.sh -b") },
	{ MODKEY,			XK_bracketright,		spawn,		SHCMD("playerctl position 10+ && ~/.config/scripts/skip-spotify.sh -f") },
	{ MODKEY|ShiftMask,		XK_bracketleft,		spawn,		SHCMD("mpc seekthrough -00:00:10; pkill -RTMIN+12 dwmblocks") }, 
	{ MODKEY|ShiftMask,		XK_bracketright,	spawn,		SHCMD("mpc seekthrough +00:00:10; pkill -RTMIN+12 dwmblocks") }, 

	/* Navigational Keybinds */
	{ MODKEY,			XK_s,		togglesticky,	{0} },
	{ MODKEY,			XK_f,		togglefullscr,	{0} },
	{ MODKEY,			XK_b,		togglebar,	{0} },
	{ MODKEY,			XK_a,		togglegaps,	{0} },
	{ MODKEY,			XK_z,		incrgaps,	{.i = +3 } },
	{ MODKEY,			XK_x,		incrgaps,	{.i = -3 } },
	{ MODKEY,			XK_g,		shiftview,	{ .i = -1 } },
	{ MODKEY,			XK_semicolon,	shiftview,	{ .i = 1 } },
	{ MODKEY,			XK_BackSpace,	quit,		{1} },
	{ MODKEY,			XK_Tab,		view,		{0} },
	{ MODKEY,			XK_backslash,		view,		{0} },
	{ MODKEY,			XK_o,		incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,		XK_o,		incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,		XK_a,		defaultgaps,	{0} },
	{ MODKEY|ShiftMask,		XK_g,		shifttag,	{ .i = -1 } },
	{ MODKEY|ShiftMask,		XK_semicolon,	shifttag,	{ .i = 1 } },
	{ MODKEY|ShiftMask,		XK_q,		killclient,		{0} },

	/* Monitor Related Keybinds */
	{ MODKEY|ControlMask,			XK_comma,		focusmon,	{.i = -1 } },
	{ MODKEY|ControlMask,			XK_period,	focusmon,	{.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,		XK_comma,		tagmon,		{.i = -1 } },
	{ MODKEY|ControlMask|ShiftMask,		XK_period,	tagmon,		{.i = +1 } },

	/* J and K are automatically bound above in STACKEYS */
	{ MODKEY,			XK_l,		setmfact,      	{.f = +0.01} },
	{ MODKEY,			XK_h,		setmfact,				{.f = -0.01} },
	{ MODKEY|ShiftMask,			XK_h,		setcfact,      	{.f = +0.05} },
	{ MODKEY|ShiftMask,			XK_l,		setcfact,      	{.f = -0.05} },
	{ MODKEY,								XK_q,		setcfact,      	{.f =  0.00} },
	{ MODKEY|ShiftMask,		XK_apostrophe,	togglesmartgaps,	{0} },

	/* V is automatically bound above in STACKKEYS */
	{ MODKEY,			XK_Page_Up,					spawn,   	SHCMD("escrotum -s $f ~/Pictures/Screenshots/Temporary/'%Y-%m-%d-%H%M%S_$wx$h_escrotum.png'") },
	{ MODKEY,			XK_Page_Down,				spawn,   	SHCMD("~/.config/scripts/ipbat.sh") },
	{ MODKEY,			XK_End,	  					spawn,		{.v = (const char*[]){ "killall", "xinit", NULL } } },

	/* F1-F12 Keybinds */
	{ MODKEY,			XK_F1,							spawn,		SHCMD("sudo sync; echo 3 | sudo tee /proc/sys/vm/drop_caches && ~/.config/scripts/dcram.sh") }, // RAM Refresh
	{ MODKEY,			XK_F2,							spawn,		SHCMD("~/Documents/Important Files/Crontabs/Pacman Auto-Download.sh") }, // Pacupg
	{ MODKEY,			XK_F3,							spawn,		SHCMD("sct 3000 && xsct -c 1 3300 && ~/.config/scripts/sct.sh -f") }, // Set WB to 4500k
	{ MODKEY|ShiftMask,			XK_F3,		spawn,		SHCMD("sct && xsct -c 1 5489 && ~/.config/scripts/sct.sh -r") }, // Set WB to 6500k
	{ MODKEY,			XK_F4,							spawn,		SHCMD("sct && sh ~/.config/scripts/sct.sh -r") },
	{ MODKEY,			XK_F5,  						spawn,		STRAIGHT("kodi") },
	{ MODKEY,			XK_F6,							spawn,		{.v = (const char*[]){ "feh", "--bg-fill", "/home/victor/.config/wall/_DSF3129e.JPG", "--bg-fill", "/home/victor/.config/wall/IMG_5683.jpg", NULL } } }, // wall_1 choice
	{ MODKEY|ShiftMask,			XK_F6,		spawn,		{.v = (const char*[]){ "feh", "--bg-fill", "/home/victor/.config/wall/_DSF3129e.JPG", "--bg-fill", "/home/victor/.config/wall/_DSF2004.JPG", NULL } } }, // wall_2 choice
	{ MODKEY,			XK_F7,							spawn,		SHCMD("nmcli con down dank && nmcli con up dank && sh ~/.config/scripts/refresh_wifi.sh") },
	{ MODKEY,			XK_F8,							spawn,		SHCMD("xrandr --output DisplayPort-0 --primary --mode 3840x2160_165 --pos 1920x-700 --rotate normal --output HDMI-A-0 --mode 1920x1080_74 --scale 1x1 --rotate normal; ~/.config/wired/reset_wired_3840.sh") }, // 4k 1080 horiz
	{ MODKEY,			XK_F9,							spawn,		SHCMD("xrandr --output DisplayPort-0 --primary --mode 1920x1080_165 --rotate normal --output HDMI-A-0 --left-of DisplayPort-0 --mode 1920x1080_74 --scale 1x1 --rotate normal; ~/.config/wired/reset_wired_1920.sh") }, // 1080 1080 horiz
	{ MODKEY,			XK_F10,							spawn,		{.v = (const char*[]){ "sudo", "systemctl", "suspend", NULL } } }, // sleep
	{ MODKEY,			XK_F11,							spawn,		SHCMD("killall -9 dwmblocks && dwmblocks") }, // refresh status bar
	{ MODKEY,			XK_F12,							spawn,		STRAIGHT("picom") }, // refresh compositor
	{ MODKEY,			XK_space,						zoom,		  {0} },
	{ WINKEY,			XK_space,						spawn,		{.v = (const char*[]){ "wired", "-d", "latest", NULL } } },
	{ MODKEY|ShiftMask,		XK_space,		togglefloating,	{0} },
	{ MODKEY, XF86XK_AudioRaiseVolume,	spawn,		{.v = (const char*[]){ "~/.config/scripts/volume.sh", "-i", NULL } } },
	{ MODKEY, XF86XK_AudioLowerVolume,	spawn,		{.v = (const char*[]){ "~/.config/scripts/volume.sh", "-d", NULL } } },

	/* Fn Keybinds */
	{ 0, XF86XK_AudioMute,				spawn,		SHCMD("pamixer -t; pkill -RTMIN+10 dwmblocks") },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("playerctl -p spotify volume 0.02+ && zsh ~/.config/scripts/volume.sh -S") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("playerctl -p spotify volume 0.02- && zsh ~/.config/scripts/volume.sh -S") },
	{ 0, XF86XK_AudioPause,		spawn,		{.v = (const char*[]){ "playerctl", "pause", NULL } } },
	{ 0, XF86XK_AudioPlay,		spawn,		{.v = (const char*[]){ "playerctl", "play-pause", NULL } } },
	{ 0, XF86XK_AudioStop,		spawn,		{.v = (const char*[]){ "playerctl", "stop", NULL } } },
	{ 0, XF86XK_AudioRewind,	spawn,		{.v = (const char*[]){ "playerctl", "position 5-", NULL } } },
	{ 0, XF86XK_AudioForward,	spawn,		{.v = (const char*[]){ "playerctl", "position 5+", NULL } } },
	{ 0, XF86XK_AudioMedia,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "ncmpcpp", NULL } } },
	{ 0, XF86XK_AudioMicMute,	spawn,		SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
	{ 0, XF86XK_Calculator,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "weechat", NULL } } },
	{ 0, XF86XK_Explorer,			spawn,		{.v = (const char*[]){ "obs", NULL } } },
	{ 0, XF86XK_Sleep,				spawn,		{.v = (const char*[]){ "sudo", "systemctl", "suspend", NULL } } },
	{ 0, XF86XK_WWW,		 			spawn,		{.v = (const char*[]){ "firefox", NULL } } },  
	{ 0, XF86XK_DOS,		 			spawn,		{.v = termcmd } },
	{ 0, XF86XK_ScreenSaver,	spawn,		SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
	{ 0, XF86XK_TaskPane,			spawn,		{.v = (const char*[]){ TERMINAL, "-e", "htop", NULL } } },
	{ 0, XF86XK_Mail,					spawn,		STRAIGHT("xev") },
	{ 0, XF86XK_MyComputer,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "lfub /", NULL } } },
	{ 0, XF86XK_Launch1,			spawn,		{.v = (const char*[]){ "xset", "dpms", "force", "off", NULL } } },
	{ 0, XF86XK_TouchpadToggle,			spawn,		SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
	{ 0, XF86XK_TouchpadOff,				spawn,		{.v = (const char*[]){ "synclient", "TouchpadOff=1", NULL } } },
	{ 0, XF86XK_TouchpadOn,					spawn,		{.v = (const char*[]){ "synclient", "TouchpadOff=0", NULL } } },
	{ 0, XF86XK_MonBrightnessUp,		spawn,		SHCMD("xbacklight -inc 2 && sh ~/.config/scripts/xbacklight.sh") },
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
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkStatusText,        ShiftMask,      Button3,        spawn,          {.v = (const char*[]){ TERMINAL, "-e", "nvim", "/home/victor/.config/suckless/dwm/config.h", NULL } } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        defaultgaps,	  {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	// Scroll wheel gaps
	// { ClkClientWin,		MODKEY,		Button4,	incrgaps,	{.i = +1} },
	// { ClkClientWin,		MODKEY,		Button5,	incrgaps,	{.i = -1} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,						0,							Button4,				shiftview,			{.i = -1} },
	{ ClkTagBar,						0,							Button5,				shiftview,			{.i = 1} },
	{ ClkRootWin,						0,							Button2,				togglebar,			{0} },

	{ ClkClientWin,		0,            7,        spawn,        SHCMD("playerctl -p spotify next; pkill -RTMIN+22 dwmblocks") },
	{ ClkRootWin,			0,            7,        spawn,        SHCMD("playerctl -p spotify next; pkill -RTMIN+22 dwmblocks") },
	{ ClkClientWin,		0,            6,        spawn,        SHCMD("playerctl -p spotify previous; pkill -RTMIN+22 dwmblocks") },
	{ ClkRootWin,			0,            6,        spawn,        SHCMD("playerctl -p spotify previous; pkill -RTMIN+22 dwmblocks") },
	{ ClkClientWin,		0,            10,       spawn,        SHCMD("playerctl -p spotify play-pause; sh ~/.config/scripts/play-pause-spotify.sh") },
	{ ClkRootWin,			0,            10,       spawn,        SHCMD("playerctl -p spotify play-pause; sh ~/.config/scripts/play-pause-spotify.sh") },
};
