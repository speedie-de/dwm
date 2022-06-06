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
- xsetroot (Sometimes also named xorg-xsetroot)
The rest are not mandatory but are very much recommended since they provide additional features.

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
This build of dwm has been patched pretty heavily.

See docs/patchlist if you want to know what patches are included.

### .Xresources
This build has full compatibility with .Xresources. You can see a full list of options in docs/example.Xresources

To use a .Xresources file, simply put it in ~ or ~/.config and restart dwm. You do not need to add it to .xinitrc.

### Important
- This build does not keep object files or config.h. Those are automatically deleted after a successful compile. If a compile is not successful, they will not be deleted. If that's the case, do NOT edit config.h because if you do and it compiles successfully then your changes will be lost.
- This build REQUIRES libXft-bgra. If you don't know what that is, it's a patched build of libXft which fixes a bug which causes dmenu to crash when displaying certain characters. That can be installed through make <distro>-libxftfix
  
### Keybinds
Press Super+Control+h to see a list of all keybinds.
  
### Status bars
As for status bars, this build of dwm has been patched with extrabar and therefore supports dwmblocks. Here are a few status bars I use or have used in the past!
To use these, install one, rice it, edit #define STATUSBAR in config.def.h and recompile dwm.
- [xshbar](https://github.com/speediegamer/xshbar) (most based option)
- [xshbar](https://github.com/speedie-de/xshbar) (my build)
- [slstatus](https://github.com/speedie-de/slstatus) (my build)
- [slstatus](https://tools.suckless.org/slstatus)
- [dwmbar](https://github.com/joestandring/dwm-bar)
- [candybar](https://github.com/jornmann/candybar)

### Fsignal
This build of dwm has been patched with fsignal meaning you can control dwm using shell commands. There's a shell script included that I wrote (dwmutils) which allows you to control many features of dwm through dmenu. A full list can be found in docs/example.fsignal

### Expanding
You can easily expand this build of dwm by simply adding keybinds or patching it. That's the nice thing about suckless software.

As for adding keybinds, just copy the existing binds and change a few things.
