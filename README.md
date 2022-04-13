# dwm
speedie's dynamic window manager configuration

![image](https://user-images.githubusercontent.com/71722170/163281764-a55b6600-5830-4161-a4ac-61e41df67613.png)

This is my personal always-changing build of [suckless.org](https://suckless.org)'s dynamic window manager or [dwm](https://dwm.suckless.org).
It features many different patches which enhances the user experience and has keybinds for everything.

I recommend using my builds of [st](https://github.com/speedie-de/st) and [dmenu](https://github.com/speedie-de/dmenu) with this as they provide more features which can work together with this build of dwm such as copying the output of a command. It is not strictly necessary though

### Installation
- Install dev-vcs/git using your favorite package manager
- git clone <this-url>
- cd dwm
- sudo make install
- echo "dwm" > ~/.xinitrc # If you're using a display manager, select it in your menu.

### Features
This build of dwm has been patched pretty heavily with the following patches
- dwm-actualfullscreen
- dwm-alpha
- dwm-alttags
- dwm-centeredtitle
- dwm-centerfirstwindow
- dwm-cool-autostart
- dwm-cyclelayouts
- dwm-emptyview
- dwm-fullgaps
- dwm-gridmode
- dwm-hide_vacant_tags
- dwm-no-mouse-support
- dwm-pertag
- dwm-rainbowtags # Not actually rainbow but that's the defaults.
- dwm-statuscmd # For status bars like dwmblocks
- dwm-steam
- dwm-upgrade-6.3 # Patch which upgrades dwm 6.2 to 6.3
- dwm-warp
- dwm-winicon
- dwm-xresources
- dwm-pywal # Script which makes this compatible with pywal

This build of dwm has full compatibility with .Xresources and allows defining these options
- dwm.nmaster
- dwm.font
- dwm.background
- dwm.backgroundmid
- dwm.textnorm
- dwm.textsel
- dwm.windowbordersel
- dwm.windowbordernorm
- dwm.col_tag1
- dwm.col_tag1_text
- dwm.col_tag2
- dwm.col_tag2_text
- dwm.col_tag3
- dwm.col_tag3_text
- dwm.col_tag4
- dwm.col_tag4_text
- dwm.col_tag5
- dwm.col_tag5_text
- dwm.col_tag6
- dwm.col_tag6_text
- dwm.col_tag7
- dwm.col_tag7_text
- dwm.col_tag8
- dwm.col_tag8_text
- dwm.col_tag9
- dwm.col_tag9_text
- dwm.borderpx
- dwm.snap
- dwm.showbar
- dwm.topbar
- dwm.resizehints
- dwm.mfact
- dwm.startontag
- dwm.gappx
- dwm.rmaster
