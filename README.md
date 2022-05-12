# dwm
speedie's dynamic window manager configuration

![image](https://user-images.githubusercontent.com/71722170/163281764-a55b6600-5830-4161-a4ac-61e41df67613.png)

This is my personal always-changing build of [suckless.org](https://suckless.org)'s dynamic window manager or [dwm](https://dwm.suckless.org).
It features many different patches which enhances the user experience and has keybinds for everything.

I recommend using my builds of [st](https://github.com/speedie-de/st) and [dmenu](https://github.com/speedie-de/dmenu) with this as they provide more features which can work together with this build of dwm such as copying the output of a command. It is not strictly necessary though

### Dependencies
This build of dwm has the following dependencies:
- libXft-bgra (See Installing libXft-bgra)
- libXinerama (Can be disabled if you don't need multiple monitors)
- imlib2
- dmenu (Any build should work, can be replaced with rofi with some effort)

### Installation
- See dependencies
- Install dev-vcs/git using your favorite package manager
- git clone <this-url>
- cd dwm
- sudo make install
- echo "dwm" > ~/.xinitrc # If you're using a display manager, select it in your menu.
- See "Installing libXft-bgra"

### Installation (Package manager)
If you're running (currently only) Gentoo then you can install my build of dwm using Portage.
- emerge layman
- layman -o https://raw.githubusercontent.com/spoverlay/splay/main/splay.xml -f -a splay
- layman -S
- emerge dwm-spde
- Optional: emerge st-spde dmenu-spde

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
- dwm-rainbowtags
- dwm-statuscmd
- dwm-steam
- dwm-upgrade-6.3
- dwm-warp
- dwm-winicon
- dwm-xresources
- dwm-pywal
- dwm-moveresize
- dwm-autoresize
- dwm-deck
- dwm-deck-tilegap
- dwm-ewmhtags
- dwm-focusonnetactive
- dwm-sticky
- dwm-dynamicscratchpads
- dwm-namedscratchpads
- dwm-decorhints
- dwm-swallow
- dwm-fibonacci
- dwm-centeredmaster
- dwm-barpadding
- dwm-threecolumn
- dwm-bottomstack
- dwm-horizgrid
- dwm-alwayscenter
- dwm-rulerefresher
- dwm-alpha-monocle
- dwm-tatami
- dwm-fsignal

This build of dwm has full compatibility with .Xresources and allows defining these options
- dwm.nmaster:              1
- dwm.font:                 Terminus:size=8
- dwm.font2:                JoyPixels:size=8
- dwm.font3:                Siji:size=8
- dwm.col_background:       #222222
- dwm.col_backgroundmid:    #222222
- dwm.col_textnorm:         #bbbbbb
- dwm.col_textsel:          #eeeeee
- dwm.col_windowbordersel:  #eeeeee
- dwm.col_windowbordernorm: #000000
- dwm.col_tag1:             #333333
- dwm.col_tag1_text:        #eeeeee
- dwm.col_tag2:             #333333
- dwm.col_tag2_text:        #eeeeee
- dwm.col_tag3:             #333333
- dwm.col_tag3_text:        #eeeeee
- dwm.col_tag4:             #333333
- dwm.col_tag4_text:        #eeeeee
- dwm.col_tag5:             #333333
- dwm.col_tag5_text:        #eeeeee
- dwm.col_tag6:             #333333
- dwm.col_tag6_text:        #eeeeee
- dwm.col_tag7:             #333333
- dwm.col_tag7_text:        #eeeeee
- dwm.col_tag8:             #333333
- dwm.col_tag8_text:        #eeeeee
- dwm.col_tag9:             #333333
- dwm.col_tag9_text:        #eeeeee
- dwm.borderpx:             1
- dwm.snap:                 32
- dwm.showbar:              1
- dwm.topbar:               1
- dwm.resizehints:          0
- dwm.mfact:                0.50
- dwm.startontag:           1
- dwm.gappx:                10
- dwm.rmaster:              0
- dwm.shell:                /bin/sh
- dwm.sizeicon:             16
- dwm.spacingicon:          5
- dwm.status:               xshbar
- dwm.decorhints:           1
- dwm.vertpad:              0
- dwm.sidepad:              0  

I know that seems like a lot but if you're unsure, there's an example file.
To use a .Xresources file, simply install xrdb and add xrdb /path/to/.Xresources to .xinitrc
Or if you're using a display manager, add it to the autostart function in config.def.h.

### Important
- This build does not keep object files or config.h. Those are automatically deleted after a successful compile. If a compile is not successful, they will not be deleted. If that's the case, do NOT edit config.h because if you do and it compiles successfully then your changes will be lost.
- This build REQUIRES libXft-bgra. If you don't know what that is, it's a patched build of libXft which fixes a bug which causes dmenu to crash when displaying certain characters. That can be installed through make <distro>-libxftfix
  
### Keybinds
NOTE: These are case-sensitive. This means "s" and "S" for example will NOT do the same thing.

#### Applications
- Alt+Shift+Enter   | Opens a terminal
- Alt+Shift+Colon   | Opens a dmenu prompt
- Alt+Shift+d       | Opens 'cordless' in a terminal
- Alt+Shift+s       | Opens 'maim' to take a screenshot and copies it to the clipboard using 'xclip'
- Alt+Shift+f       | Opens the defined file manager
- Alt+Shift+w       | Opens the defined web browser
- Alt+Shift+o       | Opens the dfmpeg dmenu script in dmenu which can record your screen (Only if manually installed)
- Alt+Shift+p       | Opens the genpkg dmenu script in dmenu which can look up ebuilds
- Alt+Shift+c       | Opens the copyout dmenu script in dmenu which can copy the output of a command.
- Alt+Shift+v       | Opens the dsearch dmenu script in dmenu which can search the web using many different search engines using dmenu and open the results in the defined web browser
- Alt+Shift+j       | Opens the cfgedit dmenu script in dmenu which can open configuration files in your editor
- Alt+Shift+e       | Opens the emoji picker dmenu script in dmenu which can copy an emoji to your clipboard
- Alt+Shift+comma   | Opens the dscratchpad dmenu script
- Alt+Shift+t       | Opens the defined editor in your terminal
- Alt+Shift+p       | pkills the defined web browser
- Alt+Shift+m       | pkills the defined music player
- Alt+Shift+a       | Opens the defined mixer in your terminal
- Alt+Shift+m       | Opens the defined music player
- Alt+Shift+x       | Opens the defined system process viewer in your terminal
- Control+Shift+m   | Opens the defined email client
- Control+Alt+u     | Opens the defined RSS reader

#### Navigation

- Alt+f             | Full-screen the selected window
- Alt+b             | Show/hide the dwm bar
- Alt+j/k           | Move focus between windows
- Alt+a/d           | Increase/decrease size of each window
- Alt+Minus         | Show the scratchpad
- Alt+Equal         | Remove the scratchpad
- Alt+Enter         | Switch order of windows
- Alt+Shift+q       | Close the current window
- Alt+Space         | Set layout
- Alt+Shift+Equal   | Toggle scratchpads
- Alt+Shift+Minus   | Hide the scratchpad
- Alt+Shift+Space   | Unfloat floating windows
- Alt+Shift+Arrow   | Resizes a window in floating mode
- Alt+Shift+Tab     | Switch windows quickly and easily
- Alt+Shift+1       | Move to tag 1
- Alt+Shift+2       | Move to tag 2
- Alt+Shift+3       | Move to tag 3
- Alt+Shift+4       | Move to tag 4
- Alt+Shift+5       | Move to tag 5
- Alt+Shift+6       | Move to tag 6
- Alt+Shift+7       | Move to tag 7
- Alt+Shift+8       | Move to tag 8
- Alt+Shift+9       | Move to tag 9
- Alt+Shift+Escape  | Ask the user if they want to shutdown or reboot or nothing
- Alt+Shift+i       | Open a dmenu prompt and open the file the user picks in Zathura
- Alt+Shift+k       | Open a dmenu prompt and open the file the user picks in Vim
- Control+Alt+e     | Switch to layout 3 (Grid)
- Control+Alt+r     | Switch to layout 1 (Monocle)
- Control+Alt+t     | Switch to layout 0 (Master & stack)
- Control+Alt+y     | Switch to layout 4 (Deck)
- NOTE: The rest of the layouts can be used using Ctrl+Shift+A/D or Ctrl+Alt+Escape
- Control+Alt+0     | Set all windows to use the same tag
- Control+Alt+Arrow | Moves a window to any corner of your screen
- Control+Alt+Comma | Run via if present.
- Control+Alt+Tab   | Open a dmenu prompt asking the user what layout to switch to
- Control+Shift+a/d | Move between available layouts
- Control+Shift+Tab | Read .Xresources again without reloading dwm
- Control+Shift+s   | Make the current selected window sticky
- Control+Alt+Shift+Escape | Open dwmutils (Main menu)
- Control+Alt+Shift+Arrow  | Resize the window to the screen size.

#### Extras (These will only work if your keyboard has special multimedia buttons)

- Mute button       | Mutes your audio
- Up Volume button  | Increases your volume
- Down Volume button| Decreases your volume
- Stop button       | Stops your defined music player
- Browser button    | Opens your defined web browser
- Power button      | Ask if you wanna shut down, restart or lock your computer.
- Email button      | Open your defined email client
- System button     | Open your defined status viewer in a terminal

### Status bars
As for status bars, this build of dwm has been patched with extrabar and therefore supports dwmblocks. Here are a few status bars I use or have used in the past
- [xshbar](https://github.com/speediegamer/xshbar) (most based option)
- [xshbar](https://github.com/speedie-de/xshbar) (my build)
- [slstatus](https://github.com/speedie-de/slstatus) (my build)
- [slstatus](https://tools.suckless.org/slstatus)
- [dwmbar](https://github.com/joestandring/dwm-bar)
- [candybar](https://github.com/jornmann/candybar)

### Fsignal
This build of dwm has been patched with fsignal meaning you can control dwm using shell commands. There's a shell script included that I wrote (dwmutils) which allows you to control many features of dwm through dmenu.

- xsetroot -name "fsignal:1"  | Tiling
- xsetroot -name "fsignal:2"  | Floating
- xsetroot -name "fsignal:3"  | Monocle
- xsetroot -name "fsignal:4"  | Grid
- xsetroot -name "fsignal:5"  | Deck
- xsetroot -name "fsignal:6"  | Centered Master
- xsetroot -name "fsignal:7"  | Centered Floating Master
- xsetroot -name "fsignal:8"  | Fibonacci Spiral
- xsetroot -name "fsignal:9"  | Fibonacci Dwindle
- xsetroot -name "fsignal:10" | Three Column
- xsetroot -name "fsignal:11" | Bottom Stack Vertical
- xsetroot -name "fsignal:12" | Bottom Stack Horizontal
- xsetroot -name "fsignal:13" | Horizontal Grid
- xsetroot -name "fsignal:14" | Tatami
- xsetroot -name "fsignal:15" | To be added
- xsetroot -name "fsignal:16" | Cycle layout (Previous)
- xsetroot -name "fsignal:17" | Cycle layout (Next)
- xsetroot -name "fsignal:18" | Reload colors from .Xresources (livereloadxrdb)
- xsetroot -name "fsignal:19" | Set mfact (-0.05)
- xsetroot -name "fsignal:20" | Set mfact (+0.05)
- xsetroot -name "fsignal:21" | Toggle Scratchpad
- xsetroot -name "fsignal:22" | Toggle Sticky

### Expanding
You can easily expand this build of dwm by simply adding keybinds or patching it. That's the nice thing about suckless software.

As for adding keybinds, just copy the existing binds and change a few things.
