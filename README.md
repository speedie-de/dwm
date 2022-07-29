# speedie's fork of dynamic window manager
   https://speedie.gq/dwm
  https://speedie.gq/donate

## What is dwm?
dwm or dynamic window manager is a window manager. It manages the user's open windows and tiles them according to a set layout (dynamic). 
This fork has more features and keybinds.

Tiling window managers (unlike floating window managers that you may be used to) tile windows based on a set layout making them easy to get productive on. 
They also encourage the user to use their keyboard instead of the mouse so that the user doesn't have to move their hands much.

## Installation
In order to install this build of dwm, all dependencies must be installed.
You can see (Dependencies) for a list of all dependencies required to use this fork.

  - git clone https://github.com/speedie-de/dwm
  - cd dwm
  - make clean install
    - If any warnings show up, fix it by installing the missing dependency.
  - If a .xinitrc is used, add 'dwm_run' to the end.
    - NOTE: Your .xinitrc should ONLY contain 'dwm_run'. dwm will automatically start everything else. If not, edit autostart.h and 'make clean install'. If a .xinitrc is not used then you don't need to worry. A .desktop file is automatically created when you run 'make clean install'.

## Layouts
This fork of dwm comes with the following layouts:

  - Tile
  - Monocle
  - Grid
  - Deck
  - Centered Master
  - Centered Floating Master
  - Spiral
  - Dwindle
  - Three Column
  - Bottom Stack
  - Horizontal Bottom Stack
  - Horizonal Grid
  - Tatami
  - Tilewide
  - Stairs

They can be switched between using a little menu (See Keybinds for more information)
The more commonly used layouts can be switched between using a quick keybind.

## Patches
My build of dwm has been patched with the following patches:
  - dwm-actualfullscreen      | Add support for fullscreen applications
  - dwm-alpha                 | Provides transparency to dwm
  - dwm-alttags               | Adds different tags if a tag has a window open.
  - dwm-centeredtitle         | Centers the window title
  - dwm-centerfirstwindow     | Adds a rule that allows you to center the first window on a tag.
  - dwm-cool-autostart        | Adds a function that allows you to autostart stuff.
  - dwm-cyclelayouts          | Allows you to cycle between layouts using simple keybinds (or fsignal).
  - dwm-emptyview             | Allows you to view dwm without a tag.
  - dwm-fullgaps              | Adds gaps to dwm.
  - dwm-gridmode              | Adds a grid mode layout to dwm.
  - dwm-hide_vacant_tags      | Hides tags that don't have any windows open.
  - dwm-no-mouse-support      | Removes mouse support (no clicking on tags)
  - dwm-pertag                | Allows you to have different layouts for different tags.
  - dwm-rainbowtags           | Allows you to define different colors for each tag
  - dwm-statuscmd             | Allows you to use dwmblocks (if that's something you want to do)
  - dwm-steam                 | Fixes a bug with Steam games.
  - dwm-upgrade-6.3           | Patch upgrading dwm 6.2 to 6.3 (Used to upgrade to 6.3 as per https://speedie.gq/guide03)
  - dwm-warp                  | Warp your mouse when switching between windows
  - dwm-winicon               | Display the window icon next to the window title
  - dwm-xresources            | Add .Xresources (and pywal support)
  - dwm-moveresize            | Allows you to move around and resize windows in floating mode using keybinds.
  - dwm-autoresize            | Move/Resize windows that are not visible
  - dwm-deck                  | Adds a deck layout to dwm.
  - dwm-deck-tilegap          | Adds gaps to the deck layout.
  - dwm-ewmhtags              | Adds EWMH support.
  - dwm-focusonnetactive      | Enables wmctrl support (Required for Alt+Tab script) 
  - dwm-sticky                | Allows you to set a window as sticky (Follows you around tags)
  - dwm-dynamicscratchpads    | Adds scratchpads (Windows that can be pulled up at any time on any tag)
  - dwm-namedscratchpads      | Allows you to create named scratchpads (On top of other scratchpad patch)
  - dwm-decorhints            | With this patch, dwm will respect decoration hints if enabled.
  - dwm-swallow               | Add an option for dwm to swallow windows (Useful if you use.. for example mpv or sxiv)
  - dwm-fibonacci             | Adds a fibonacci layout to dwm.
  - dwm-centeredmaster        | Adds a centered master layout to dwm.
  - dwm-barpadding            | Adds bar padding to dwm.
  - dwm-threecolumn           | Adds a three column layout to dwm.
  - dwm-bottomstack           | Adds a bottom stack layout to dwm.
  - dwm-horizgrid             | Adds a horizontal grid layout to dwm.
  - dwm-alwayscenter          | Always center floating windows. (Slightly modified to add alwayscenter int)
  - dwm-rulerefresher         | Refresh rules if window title/class changes.
  - dwm-alpha-monocle         | Alpha for monocle layout.
  - dwm-tatami                | Adds a tatami layout to dwm.
  - dwm-fsignal               | Allows you to interact with dwm through shell scripts (such as included swal, dwmshutdown or dwmutils)
  - dwm-selfrestart           | Allows dwm to restart without killing your X server.
  - dwm-awesomebar            | Display window title for all windows open on a tag.
  - dwm-inplacerotate         | Allows you to 'rotate' windows.
  - dwm-ignore-transient      | This patch adds an option to ignore transient windows, fixing issues with certain applications.
  - dwm-status2d              | This patch allows you to draw stuff (and colored text) on your status bar.
  - dwm-swap-save-restore     | This patch extends status2d.
  - dwm-statusallmons         | This patch makes dwm print the status bar on all monitors
  - dwm-rmaster               | This patch adds an option to have the master area on the right
  - dwm-tilewide              | This patch adds a tilewide layout (14)
  - dwm-stickyindicator       | Adds an indicator if your window is sticky.
  - dwm-stairs                | This patch adds a stair layout (15)
  - dwm-resetlayout           | This patch adds a keybind to reset layout and mfact
  - dwm-monoclesymbol         | This patch always displays the monocle symbol instead of open clients
  - dwm-barheight             | This patch adds in customizable bar height
  - dwm-savefloats            | This patch saves the position of floating windows and restores them (Modified to add a toggle)
  - dwm-reorganizetags        | This patch adds a keybind to reorganize tags
  - dwm-restartsig            | This patch adds an option to restart dwm
  - dwm-restoreafterestart    | This patch keeps windows open on the right tags when restarting
  - dwm-canfocusrule          | This patch adds a rule for being able to focus on a client (Used for systray)
  - dwm-showhide              | This patch allows you to show/hide (or in this build minimize) clients.
  - dwm-spawnwd               | This patch (with some modifications) allows you to spawn clients in the working directory of the focused client
  - dwm-keychain              | This patch allows you to create keybinds using multiple keys
  - dwm-focusadjacenttag      | This patch allows you to move to the next/previous tag
  - dwm-fadeinactive          | This patch adds an option to fade inactive clients
  - dwm-i3nmaster             | This patch adds i3-like nmaster as an option
  - dwm-tagpreviews           | This patch adds tag previews (hover over tags)
  - dwm-attachdirection       | This patch allows you to attach clients to any direction
  - dwm-ispermanent           | This patch allows you to make clients permanent (used for systray)
  - dwm-leftlayout            | This patch allows you to move the layout indicator to the left

## Keybinds
Below is a list of all dwm keybinds.

  ### Applications
  Keybinds for regular applications
  - Super+Shift+Enter         | Opens a terminal
  - Super+Shift+Colon         | Opens a dmenu prompt
  - Super+Shift+s             | Opens 'maim' to take a screenshot and copies it to the clipboard using 'xclip'
  - Super+Shift+f             | Opens the defined file manager
  - Super+Shift+w             | Opens the defined web browser
  - Super+Shift+o             | Opens the dfmpeg dmenu script in dmenu which can record your screen (Only if manually installed)
  - Super+Shift+e             | Opens the dboard dmenu script in dmenu which can copy text to your clipboard
  - Super+Shift+t             | Opens the defined editor in your terminal
  - Super+Shift+p             | pkills the defined web browser
  - Super+Shift+m             | pkills the defined music player
  - Super+Shift+a             | Opens the defined mixer in your terminal
  - Super+Shift+m             | Opens the defined music player
  - Super+Shift+x             | Opens the defined system process viewer in your terminal
  - Super+Control+Shift+m     | Opens the defined email client
  - Super+Control+u           | Opens the defined RSS reader

  ### Navigation
  These keybinds are for navigating dwm
  - Super+r                   | Toggle master on the left/right
  - Super+t                   | Reorganize tags and move clients
  - Super+f                   | Full-screen the selected window
  - Super+b                   | Show/hide the dwm bar
  - Super+s                   | Show/hide the systray (If trayer is installed)
  - Super+j/k                 | Move focus between visible windows
  - Super+Shift+j/k           | Move focus between hidden windows
  - Super+a/d                 | Increase/decrease size of each window
  - Super+o                   | Hide a window
  - Super+Control+o           | Show a window
  - Super+w                   | Hide all windows except focused
  - Super+Control+w           | Show all windows except focused
  - Alt+Arrow                 | Move to the next/previous tag
  - Super+Minus               | Show the scratchpad
  - Super+Equal               | Remove the scratchpad
  - Super+Enter               | Switch order of windows
  - Super+Shift+q             | Close the current window
  - Super+Space               | Set layout
  - Super+t                   | Disable inactive fade
  - Super+Shift+Equal         | Toggle scratchpads
  - Super+Shift+Minus         | Hide the scratchpad
  - Super+Shift+Space         | Unfloat floating windows
  - Super+Shift+Arrow         | Resizes a window in floating mode
  - Super+1                   | Move to tag 1
  - Super+2					  | Move to tag 2
  - Super+3					  | Move to tag 3
  - Super+4					  | Move to tag 4
  - Super+5					  | Move to tag 5
  - Super+6					  | Move to tag 6
  - Super+7					  | Move to tag 7
  - Super+8					  | Move to tag 8
  - Super+9					  | Move to tag 9
  - Super+Shift+1             | Preview tag 1
  - Super+Shift+2             | Preview tag 2
  - Super+Shift+3             | Preview tag 3
  - Super+Shift+4             | Preview tag 4
  - Super+Shift+5             | Preview tag 5
  - Super+Shift+6             | Preview tag 6
  - Super+Shift+7             | Preview tag 7
  - Super+Shift+8             | Preview tag 8
  - Super+Shift+9             | Preview tag 9
  - Super+Shift+h/j/k/l       | Rotates a stack.
  - Super+Shift+Escape        | Ask the user if they want to shutdown or reboot or nothing
  - Super+Shift+i             | Open a dmenu prompt and open the file the user picks in Zathura
  - Super+Shift+p             | Open a dmenu prompt and open the file the user picks in Vim
  - Super+Control+e           | Switch to layout 3 (Grid)
  - Super+Control+r           | Switch to layout 1 (Monocle)
  - Super+Control+t           | Switch to layout 0 (Master & stack)
  - Super+Control+y           | Switch to layout 4 (Deck)
  - Super+Control+0           | Set all windows to use the same tag
  - Super+Control+Arrow       | Moves a window to any corner of your screen (Arrow key)
  - Super+Control+Tab         | Open a dmenu prompt asking the user what layout to switch to
  - Super+Control+h           | Open a list of all keybinds in your terminal using less
  - Super+Control+Shift+a/d   | Move between available layouts
  - Super+Alt+s               | Make the current selected window sticky
  - Super+Control+Shift+Esc   | Open dwmutils (Main menu)
  - Super+Control+Shift+Arrow | Resize the window to the screen size.
  - Super+Control+Shift+s     | Set a wallpaper
  - Super+Control+Shift+n     | Connect to wifi (Requires iwd)
  - Super+Control+Shift+b     | Connect to a bluetooth device (Requires bluez and bluez-utils)
  - Alt+Tab                   | Switch windows quickly and easily 
  
  ### Chained keybinds
  - Super+c & w               | Curl wttr.in and open in less

  ### Extras
  These will only work if your keyboard has special multimedia buttons.
  - Mute button               | Mutes your audio
  - Up Volume button          | Increases your volume
  - Down Volume button        | Decreases your volume
  - Stop button               | Stops your defined music player
  - Browser button            | Opens your defined web browser
  - Power button              | Ask if you wanna shut down, restart or lock your computer.
  - Email button              | Open your defined email client
  - System button             | Open your defined status viewer in a terminal
## Dependencies
  These are absolutely necessary, dwm will NOT compile without them
  - libxft-bgra (Can be installed through 'make <distro>-libxftfix')
    - NOTE: libXft will do but will cause dwm and as such all your applications to crash if a colored emoji is displayed in the status bar.
  - libXinerama
    - Can be disabled through editing config.mk if you're not interested in multiple monitors.
  - imlib2
  
  ## Features
  These are dependencies if you wanna use certain features
  NOTE: Do not add any of these to .xinitrc or similar. They are going to be autostarted by dwm.
  If you want to use an alternative, change it in options.h.
  - dmenu
    - NOTE: dmenu is required for most scripts included with this build of dwm. My build is required for Pywal support.
	- NOTE 2: The build must have the 'grid' patch. If yours does not have this, you can patch it in or get my build here: https://github.com/speedie-de/dmenu
  - picom
  - xclip (Required for clipboard support by a few scripts, will start automatically)
  - xwallpaper (Required to set wallpapers automatically)
  - xmodmap (Install if you want Escape instead of Caps Lock and Right Super+hjkl for arrow keys)
  - xrdb (Install if you want .Xresources support)
  - pywal (Install if you want pywal support. Requires swal aka the default way to set wallpapers)
  - wmctrl (Needed for proper window management)
  - xsetroot (Needed for most scripts including Pywal support)
  - slock (Required for screen locking)
  - maim (Required for built in 'dwm-screenshotutil' script)
  
  ## Software
  This build of dwm comes with binds for software. 
  These must be installed by default but you can change what software is required by editing 'options.h' and running 'make clean install'.
  You can also remove keybinds by editing 'keybinds.h' and running 'make clean install'.
  - st (Terminal)
  - firefox (Web browser)
  - htop (Status monitor)
  - newsboat (RSS reader)
  - zathura (PDF reader)
  - alsa-utils (Required for audio controls)
  - mocp (Default music player)
  - vim (Text editor)
  - neomutt (Email client)
  - maim (Screenshot tool, automatically copies to clipboard using xclip)
  - vifm (File manager)
  - slock (Lock screen)
  And everything under 'Features'.
  
## Important
If you're used to dwm, this build might be a little bit unfamiliar to you. This is because this build doesn't use config.h (or config.def.h).
Instead, config.h is split into different parts to make it easier to edit. Instead of editing config.h you'll want to edit:

  - autostart.h for starting stuff right before dwm (For example xclip, pywal, etc.)
  - options.h for changing colors and applications to use with keybinds.
  - fsignal.h for adding fake signals
  - colors.h for changing alpha options, most users won't need to edit it.
  - xresources.h for adding .Xresources options
  - rules.h for adding rules
  - keybinds.h for adding/removing keybinds.

After you've edited one of the files, you need to run 'make clean install' to reinstall dwm.
Remember that you can change colors through your .Xresources file (see .Xresources and Pywal) meaning you do not need to recompile dwm.

Another important detail you must keep in mind is that this build comes with a status bar simply named 'status'.
It can be found in the dwm source code directory. It is just a shell script which adds stuff to your status bar. It will automatically be started when dwm starts.

You can edit the status bar simply by editing 'status' and running 'make clean install'.
Please note that most status bars including the built in 'status' depends on xsetroot which must be installed.

If you want to change status bar, edit options.h and set 'static char status' to your status bar binary (must be in $PATH).
Alternatively, you can also set dwm.status: <statusbar> in .Xresources (See .Xresources and Pywal)


## .Xresources and Pywal
This fork of dwm has .Xresources support thanks to the .Xresources patch.
It also has pywal support (tool which grabs colors based on your wallpaper).

Colors reload automagically because of a reloadxresources function this build has combined with fsignal and a wallpaper script I wrote.
Therefore, if you want colors to reload instantly, you're unfortunately forced to use the bundled wallpaper script.

If you want to use another script, you can open up dwmutils and select 'Reload .Xresources' to reload .Xresources.
Alternatively, you can write a script yourself (18 reloads the colors)

Below is a list of all .Xresources values you can define. The .Xresources file should be placed in ~ or ~/.config by the user.
If it is not or you want it somewhere else, you can edit 'autostart.h' and 'make clean install'.

Note that the 'xrdb' dependency is required for both pywal and .Xresources support and 'xsetroot' is required for automatic reloading of colors.

  - dwm.nmaster:              1
  - dwm.rmaster:              0
  - dwm.font:                 fontawesome:size=8
  - dwm.font2:				  NotoSans-Regular:size=8:antialiasing=true
  - dwm.font3:                Noto Emoji:size=8
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
  - dwm.col_layouttext:       #000000
  - dwm.col_layoutbgnorm:     #222222
  - dwm.col_layoutbgsel:      #bbbbbb
  - dwm.col_status0:          #000000
  - dwm.col_status1:          #ff0000
  - dwm.col_status2:          #33ff00
  - dwm.col_status3:          #ff0099
  - dwm.col_status4:          #0066ff
  - dwm.col_status5:          #cc00ff
  - dwm.col_status6:          #00ffff
  - dwm.col_status7:          #d0d0d0
  - dwm.col_status8:          #808080
  - dwm.col_status9:          #ff0000
  - dwm.col_status10:         #33ff00
  - dwm.col_status11:         #ff0099
  - dwm.col_status12:         #0066ff
  - dwm.col_status13:         #cc00ff
  - dwm.col_status14:         #00ffff
  - dwm.col_status15:         #ffffff
  - dwm.borderpx:             1
  - dwm.snap:                 20
  - dwm.showbar:              1
  - dwm.resizehints:          0
  - dwm.mfact:                0.50
  - dwm.startontag:           1
  - dwm.gappx:                10
  - dwm.attachdirection:      3
  - dwm.shell:                /bin/sh
  - dwm.sizeicon:             10
  - dwm.spacingicon:          5
  - dwm.status:               status
  - dwm.defaultname:          
  - dwm.refreshrules:         1
  - dwm.decorhints:           1
  - dwm.vertpad:              0
  - dwm.sidepad:              0  
  - dwm.barheight:            5
  - dwm.centerfloating:       1
  - dwm.firstwindowsize:      0
  - dwm.savefloat:            1
  - dwm.warpcursor:           1
  - dwm.pertag:               1
  - dwm.i3nmaster:            0
  - dwm.scalepreview:         4
  - dwm.tagpreview:           1
  - dwm.mousepreview:         1
  - dwm.monocleclientcount:   0
  - dwm.statusallmons:        1
  - dwm.hidelayout:           0
  - dwm.leftlayout:           1
  - dwm.fadeinactive:         1
  - dwm.stairpx:              20
  - dwm.stairdirection:       1
  - dwm.stairsamesize:        1


## Fsignal
Thanks to the 'fsignal' patch available on suckless.org's website, we can easily write shell scripts to interact with dwm.
This is exactly what I did and dwm-utils, dwm-swal, dwm-shutdown and more take advantage of it.

In order to use 'fsignal', your system must have 'xsetroot' installed.
Then simply use the dwm-utils script. Syntax is dwm-utils -exec <signum>

Below is a list of all signums and what they do.

  - 1  | Switch to the Tiling layout
  - 2  | Switch to the Floating layout
  - 3  | Switch to the Monocle layout
  - 4  | Switch to the Grid layout
  - 5  | Switch to the Deck layout
  - 6  | Switch to the Centered Master layout
  - 7  | Switch to the Centered Floating Master layout
  - 8  | Switch to the Fibonacci Spiral layout
  - 9  | Switch to the Fibonacci Dwindle layout
  - 10 | Switch to the Three Column layout
  - 11 | Switch to the Bottom Stack Vertical layout
  - 12 | Switch to the Bottom Stack Horizontal layout
  - 13 | Switch to the Horizontal Grid layout
  - 14 | Switch to the Tatami layout
  - 15 | To be added
  - 16 | Cycle layout (Previous)
  - 17 | Cycle layout (Next)
  - 18 | Reload colors from .Xresources
  - 19 | Set mfact (-0.05)
  - 20 | Set mfact (+0.05)
  - 21 | Toggle Scratchpad
  - 22 | Toggle Sticky
  - 23 | Toggle Bar
  - 24 | Toggle Fullscreen
  - 25 | Restart dwm keeping all your applications open.
  - 26 | Toggle right master
  - 27 | Switch to the Stairs layout
  - 28 | Reset layout and mfact
  - 29 | Reorganize tags
  - 30 | Restart dwm
  - 31 | Shutdown dwm
  - 32 | dwmblocks signum 1
  - 33 | dwmblocks signum 2
  - 34 | dwmblocks signum 3
  - 35 | Switch to the Tiling (5:4) layout

## Switching run launcher
Some users may prefer to use a different run launcher than dmenu.
Previously all scripts bundled would only run dmenu from $PATH but you can now switch run launcher very easily.
  - Edit options.h and change RUN to your run launcher
  - Add export RUNLAUNCHER=<runlauncher> to your .<shell>rc

Run launchers must support dmenu arguments because otherwise scripts are going to be incompatible.
It must also support the additional '-g' argument that the dmenu grid patch provides unless you modify the scripts bundled.
Keep in mind that if you use a different run launcher, it may not support Pywal/.Xresources.
