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
	${CC} -o $@ ${OBJ} ${LDFLAGS} && rm -f config.h drw.o dwm.o util.o ; cp -f dwm-applications ${DWMAPPLICATIONS} ; cp wal.sh ${PREFIX}/bin/wal_dwm.sh ; chmod +x ${PREFIX}/bin/wal_dwm.sh

clean:
	rm -f dwm ${OBJ} dwm-${VERSION}.tar.gz && echo "Cleaned!"

dist: clean
	mkdir -p dwm-${VERSION}
	cp -R LICENSE Makefile README config.def.h config.mk\
		dwm.1 drw.h util.h ${SRC} dwm.png transient.c dwm-${VERSION}
	tar -cf dwm-${VERSION}.tar dwm-${VERSION}
	gzip dwm-${VERSION}.tar
	rm -rf dwm-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f dwm ${DESTDIR}${PREFIX}/bin && cp dwm-applications ${DWMAPPLICATIONS}
	chmod 755 ${DESTDIR}${PREFIX}/bin/dwm
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < dwm.1 > ${DESTDIR}${MANPREFIX}/man1/dwm.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/dwm.1
	rm config.h drw.o dwm.o util.o ; chmod +x wal.sh ; echo "Installed dwm to ${DESTDIR}${PREFIX}/bin"

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/dwm\
		${DESTDIR}${MANPREFIX}/man1/dwm.1

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
	makepkg -si

.PHONY: all options clean dist install uninstall help libxftfix gentoo-libxftfix arch-libxftfix
