# dwm - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c dwm.c util.c
OBJ = ${SRC:.c=.o}

all: options dwm

options:
	@echo dwm build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

config.h:
	cp config.def.h $@

dwm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS} ; rm -f config.h drw.o dwm.o util.o

clean:
	rm -f dwm ${OBJ} dwm-${VERSION}.tar.gz && echo "Cleaned!"

dist: clean
	mkdir -p dwm-spde-${VERSION}
	cp -R config.def.h config.mk docs drw.c drw.h dwm.c layouts.c LICENSE Makefile scripts transient.c util.c util.h dwm-spde-${VERSION}
	tar -cf dwm-spde-${VERSION}.tar dwm-spde-${VERSION}
	gzip dwm-spde-${VERSION}.tar
	rm -rf dwm-spde-${VERSION}

install: all
	touch config.h drw.o dwm.o util.o
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f dwm ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/dwm
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < docs/dwm.1 > ${DESTDIR}${MANPREFIX}/man1/dwm.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/dwm.1
	cp -f docs/bindlist ${DESTDIR}${PREFIX}/bin
	cp -f scripts/dwm-keybinds ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/dwm-keybinds
	cp -f scripts/shutdown ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/shutdown
	cp -f scripts/switch ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/switch
	cp -f scripts/dwmutils ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/dwmutils
	cp -f scripts/swal ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/swal
	rm config.h drw.o dwm.o util.o ; echo "Installed dwm to ${DESTDIR}${PREFIX}/bin"
   
uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/dwm\
		${DESTDIR}${MANPREFIX}/man1/dwm.1 \
		${DESTDIR}${PREFIX}/bin/dwmutils \
		${DESTDIR}${PREFIX}/bin/switch \
		${DESTDIR}${PREFIX}/bin/shutdown \
		${DESTDIR}${PREFIX}/bin/swal \

help:
	@echo install: Installs dwm. You may need to run this as root.
	@echo uninstall: Uninstalls dwm. You may need to run this as root.
	@echo libxftfix: This option compiles and installs libXft-bgra which is necessary to prevent dwm from crashing.
	@echo gentoo-libxftfix: This option installs libXft-bgra by patching it for Gentoo only.
	@echo arch-libxftfix: This option installs libXft-bgra using the AUR on Arch Linux only.
	@echo help: Displays this help sheet.

libxftfix:
	git clone https://github.com/uditkarode/libxft-bgra && cd libxft-bgra
	sh autogen.sh --sysconfdir=/etc --prefix=/usr --mandir=/usr/share/man
	make install
	cd .. && rm -r libxft-bgra

gentoo-libxftfix:
	mkdir -pv /etc/portage/patches/x11-libs/libXft
	curl -o /etc/portage/patches/x11-libs/libXft/bgra.diff https://gitlab.freedesktop.org/xorg/lib/libXft/-/merge_requests/1.diff
	emerge x11-libs/libXft

arch-libxftfix:
	git clone https://aur.archlinux.org/libxft-bgra
	cd libxft-bgra
	makepkg -i

.PHONY: all options clean dist install uninstall help libxftfix gentoo-libxftfix arch-libxftfix
