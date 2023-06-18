/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "kitty"
#define TERMCLASS "St"
#define BROWSER "firefox"
/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 3;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 12;        /* horizontal padding for statusbar */
static const int vertpadbar         = 12;        /* vertical padding for statusbar */
static const char *fonts[]          = { "Ubuntu:weight=bold:size=11:antialas=true:hinting=true"}; //ttf-joypixels, ttf-ubuntu-font-family
																					
//static const char norm_fg[] = "#ff6e67";
//static const char norm_bg[] = "#282a36";
//static const char norm_border[] = "#dfdfdd";
//
//static const char sel_fg[] = "#bfbfbf";
//static const char sel_bg[] = "#282a36";
//static const char sel_border[] = "#bfbfbf";


static const char norm_bg[] = "#222222";
static const char norm_fg[] = "#bbbbbb";
static const char norm_border[] = "#444444";

static const char sel_bg[] = "#005577";
static const char sel_fg[] = "#eeeeee";
static const char sel_border[] = "#770000";

static const char urg_fg[] = "#f7f7fb";
static const char urg_bg[] = "#5af78e";
static const char urg_border[] = "#5af78e";

static const char title_fg[] = "#8AFF80";
static const char title_bg[] = "#282a36";
static const char col_borderbar[]   = "#bfbfbf";


static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
};
static const char dmenufont[]       = "Ubuntu:weight=bold:size=8:antialas=true:hinting=true";
static const char col_1[]       = "#b80f0f"; //background color of bar
static const char col_2[]       = "#444444"; //border color unfocesed windows
static const char col_3[]       = "#bbbbbb";
static const char col_4[]       = "#eeeeee"; //border color focused windows and tags
/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title                   tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",               NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "Navigator",            NULL,     NULL,           0,         0,          0,           -1,        -1 },
	{ "virtualbox",         NULL,     NULL,           0,         0,          0,           -1,        -1 },
	{ "St",                 NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ "Kitty",              NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,                 NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask  //set mod key to super
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_1, "-nf", col_3, "-sb", col_3, "-sf", col_4, NULL};
static const char *termcmd[]  = { TERMINAL, NULL };
static const char *musiccmd[]  = { "spotify", NULL };
static const char *notescmd[] = {TERMINAL, "-e", "nvim", "todolist"};

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_s,      spawn,          {.v = musiccmd } },
  { MODKEY,			                  XK_r,		   spawn,		       {.v = (const char*[]){ TERMINAL, "-e", "lfub", NULL } } },
  { MODKEY,			                  XK_w,		   spawn,		       {.v = (const char*[]){ BROWSER, NULL } } },
  { MODKEY,			                  XK_n,		   spawn,		       {.v = notescmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_p,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, //tiling
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} }, //floating
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} }, //monocycle
	{ MODKEY,                       XK_y,      setlayout,      {0} },
  { MODKEY|ShiftMask,			        XK_f,		   togglefullscr,	 {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

