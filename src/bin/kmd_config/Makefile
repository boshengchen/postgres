#-------------------------------------------------------------------------
#
# Makefile for src/bin/kmd_config
#
# Copyright (c) 1998-2019, PostgreSQL Global Development Group
#
# src/bin/kmd_config/Makefile
#
#-------------------------------------------------------------------------

PGFILEDESC = "kmd_config - report configuration information"
PGAPPICON=win32

subdir = src/bin/kmd_config
top_builddir = ../../..
include $(top_builddir)/src/Makefile.global

OBJS=   kmd_config.o $(WIN32RES)

all: kmd_config

kmd_config: $(OBJS) | submake-libpgport
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDFLAGS_EX) $(LIBS) -o $@$(X)

install: all installdirs
	$(INSTALL_SCRIPT) kmd_config$(X) '$(DESTDIR)$(bindir)/kmd_config$(X)'

installdirs:
	$(MKDIR_P) '$(DESTDIR)$(bindir)'

uninstall:
	rm -f '$(DESTDIR)$(bindir)/kmd_config$(X)'

clean distclean maintainer-clean:
	rm -f kmd_config$(X) $(OBJS)
	rm -rf tmp_check

check:
	$(prove_check)

installcheck:
	$(prove_installcheck)
