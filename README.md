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
- See "Installing libXft-bgra"

### Installing libXft-bgra
This has to be done because this build of dwm supports Color emojis. Now the only problem is that libXft will crash dwm because it doesn't support this. Therefore libXft has to be patched. This is pretty painful so I built this into the Makefile.
- For Gentoo: make gentoo-libxftfix
- For Arch: make arch-libxftfix
- For other GNU/Linux distributions: make libxftfix

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
- dwm.moveresize

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
- dwm.shell
- dwm.sizeicon
- dwm.spacingicon

I know that seems like a lot but if you're unsure, there's an example file.
To use a .Xresources file, simply install xrdb and add xrdb /path/to/.Xresources to .xinitrc
Or if you're using a display manager, add it to the autostart function in config.def.h.

It also has a configuration file which after compiling should be in ~/.config/dwm-applications.
This file is sourced by the SHCMD function in dwm and MUST be POSIX compliant.
  
This file does not allow you to add any more keybinds but it does allow you to change what applications to use or change arguments.

### Important
This build does not keep object files or config.h. Those are automatically deleted after a successful compile. If a compile is not successful, they will not be deleted. If that's the case, do NOT edit config.h because if you do and it compiles successfully then your changes will be lost.
  
### Keybinds
NOTE: These are case-sensitive. This means "s" and "S" for example will NOT do the same thing.
  
Application binds
- Alt+Shift+Enter | Opens a terminal
- Alt+Shift+Comma | Opens a dmenu prompt
- Alt+Shift+s     | Opens 'maim' to take a screenshot and copies it to the clipboard using 'xclip'
- Alt+Shift+f     | Opens the defined file manager
- Alt+Shift+w     | Opens the defined web browser
- Alt+Shift+o     | Opens the [dfmpeg](https;//github.com/speediegamer/dfmpeg) dmenu script in dmenu which can record your screen (Only if manually installed)
- Alt+Shift+p     | Opens the [genpkg](https://github.com/speediegamer/genpkg) dmenu script in dmenu which can look up ebuilds
- Alt+Shift+c     | Opens the [copyout](https://github.com/speediegamer/copyout) dmenu script in dmenu which can copy the output of a command.
- Alt+Shift+v     | Opens the [dsearch](https://github.com/speediegamer/dsearch) dmenu script in dmenu which can search the web using many different search engines using dmenu and open the results in the defined web browser
- Alt+Shift+j     | Opens the [cfgedit](https://github.com/speediegamer/cfgedit) dmenu script in dmenu which can open configuration files in your editor
- Alt+Shift+e     | Opens the emoji picker dmenu script in dmenu which can copy an emoji to your clipboard.
- Alt+Shift+t     | Opens the defined editor in your terminal
- Alt+Shift+p     | pkills the defined web browser
- Alt+Shift+m     | pkills the defined music player
- Alt+Shift+d     | Opens https://discord.com/channels/@me in the defined web browser
- Alt+Shift+y     | Opens the defined Invidious instance in the defined web browser
- Alt+Shift+a     | Opens the defined mixer in your terminal
- Alt+Shift+m     | Opens the defined music player
- Alt+Shift+x     | Opens the defined system process viewer in your terminal
- Control+Shift+m | Opens the defined email client
- Control+Shift+4 | Opens the defined "chan" in your defined web browser
- Control+Alt+y   | Opens the defined RSS reader

### Navigation
- Alt+Arrow         | Moves a window around in floating mode
- Alt+f             | Full-screen the selected window
- Alt+b             | Show/hide the dwm bar
- Alt+j/k           | Move focus between windows
- Alt+a/d           | Increase/decrease size of each window
- Alt+Enter         | Switch order of windows
- Alt+Shift+q       | Close the current window
- Alt+Space         | Set layout
- Alt+Shift+Space   | Unfloat floating windows
- Alt+Shift+Arrow   | Resizes a window in floating mode
- Alt+Shift+Tab     | Read .Xresources again without reloading dwm
- Alt+Shift+1       | Move to tag 1
- Alt+Shift+2       | Move to tag 2
- Alt+Shift+3       | Move to tag 3
- Alt+Shift+4       | Move to tag 4
- Alt+Shift+5       | Move to tag 5
- Alt+Shift+6       | Move to tag 6
- Alt+Shift+7       | Move to tag 7
- Alt+Shift+8       | Move to tag 8
- Alt+Shift+9       | Move to tag 9
- Control+Alt+e     | Switch to layout 3 (Grid)
- Control+Alt+r     | Switch to layout 1 (Monocle)
- Control+Alt+t     | Switch to layout 0 (Master & stack)
- Control+Alt+0     | Set all windows to use the same tag
- Control+Alt+1     | Mute ALSA volume
- Control+Alt+2     | Decrease ALSA volume
- Control+Alt+3     | Increse ALSA volume
- Control+Alt+Arrow | Moves a windows to the top right, top left, bottom right and bottom left corner of the screen.
- Control+Shift+a/d | Move between available layouts
- Control+Alt+Shift+Arrow | Resize the window to the screen size.

### Status bars
As for status bars, this build of dwm has been patched with extrabar and therefore supports dwmblocks. Here are a few status bars I use or have used in the past
- [xshbar](https://github.com/speediegamer/xshbar) (most based option)
- [xshbar](https://github.com/speedie-de/xshbar) (my build)
- [slstatus](https://github.com/speedie-de/slstatus) (my build)
- [slstatus](https://tools.suckless.org/slstatus)
- [dwmbar](https://github.com/joestandring/dwm-bar)
- [candybar](https://github.com/jornmann/candybar)

### Expanding
You can easily expand this build of dwm by simply adding keybinds or patching it. That's the nice thing about suckless software.

As for adding keybinds, just copy the existing binds and change a few things.
