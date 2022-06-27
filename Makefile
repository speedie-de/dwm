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

${OBJ}: config.mk

dwm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS} ; rm -f drw.o dwm.o util.o

clean:
	rm -f dwm ${OBJ} dwm-${VERSION}.tar.gz && echo "Cleaned!"

dist: clean
	mkdir -p dwm-spde-${VERSION}
	cp -R config.mk docs drw.c xresources.h fsignal.h drw.h dwm.c keybinds.h options.h autostart.h colors.h rules.h layouts.h layouts.c status selfrestart.c LICENSE Makefile scripts transient.c util.c util.h dwm-spde-${VERSION}
	tar -cf dwm-spde-${VERSION}.tar dwm-spde-${VERSION}
	gzip dwm-spde-${VERSION}.tar
	rm -rf dwm-spde-${VERSION} dwm

install: all
	touch drw.o dwm.o util.o
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f dwm ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/dwm
	cp -f docs/bindlist ${DESTDIR}${PREFIX}/share/dwm-bindlist
	cp -f docs/deplist ${DESTDIR}${PREFIX}/share/dwm-deplist
	cp -f docs/about ${DESTDIR}${PREFIX}/share/dwm-about
	cp -f docs/about2 ${DESTDIR}${PREFIX}/share/dwm-about-2
	cp -f docs/about3 ${DESTDIR}${PREFIX}/share/dwm-about-3
	cp -f docs/about4 ${DESTDIR}${PREFIX}/share/dwm-about-4
	cp -f docs/about5 ${DESTDIR}${PREFIX}/share/dwm-about-5
	cp -f docs/patchlist ${DESTDIR}${PREFIX}/share/dwm-patchlist
	cp -f docs/example.Xresources ${DESTDIR}${PREFIX}/share/dwm-xresources
	cp -f docs/example.fsignal ${DESTDIR}${PREFIX}/share/dwm-fsignal
	cp -f scripts/dwm-help ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/dwm-help
	cp -f scripts/dwmshutdown ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/dwmshutdown
	cp -f scripts/switch ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/switch
	cp -f scripts/dwmutils ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/dwmutils
	cp -f scripts/swal ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/swal
	cp -f scripts/bb ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/bb
	cp -f scripts/dboard ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/dboard
	cp -f scripts/pdfopen ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/pdfopen
	cp -f scripts/scriptedit ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/scriptedit
	cp -f scripts/audioctrl ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/audioctrl
	cp -f scripts/netctrl ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/netctrl
	cp -f scripts/dwm_run ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/dwm_run
	cp -f status ${DESTDIR}${PREFIX}/bin ; chmod +x ${DESTDIR}${PREFIX}/bin/status
	chmod +x ./scripts/compatcheck
	chmod +x ./scripts/dwmdm
	./scripts/compatcheck
	./scripts/dwmdm
	rm drw.o dwm.o util.o ; echo "Installed dwm to ${DESTDIR}${PREFIX}/bin"
   
uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/dwm\
		${DESTDIR}${PREFIX}/bin/dwmutils \
		${DESTDIR}${PREFIX}/bin/switch \
		${DESTDIR}${PREFIX}/bin/dwmshutdown \
		${DESTDIR}${PREFIX}/bin/swal \

help:
	@echo install: Installs dwm. You may need to run this as root.
	@echo uninstall: Uninstalls dwm. You may need to run this as root.
	@echo libxftfix: This option compiles and installs libXft-bgra which is necessary to prevent dwm from crashing.
	@echo gentoo-libxftfix: This option installs libXft-bgra by patching it for Gentoo only.
	@echo arch-libxftfix: This option installs libXft-bgra using the AUR on Arch Linux only.
	@echo help: Displays this help sheet.

libxftfix:
		chmod +x scripts/libxftfix
		./scripts/libxft -source

gentoo-libxftfix:
		chmod +x scripts/libxftfix
		./scripts/libxftfix -gentoo

arch-libxftfix:
		chmod +x scripts/libxftfix
		./scripts/libxftfix -arch

.PHONY: all options clean dist install uninstall help libxftfix gentoo-libxftfix arch-libxftfix
