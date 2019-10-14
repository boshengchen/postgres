#-------------------------------------------------------------------------
#
# Makefile for backend/catalog
#
# Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
# Portions Copyright (c) 1994, Regents of the University of California
#
# src/backend/catalog/Makefile
#
#-------------------------------------------------------------------------

subdir = src/backend/catalog
top_builddir = ../../..
include $(top_builddir)/src/Makefile.global

OBJS = catalog.o dependency.o heap.o index.o indexing.o namespace.o aclchk.o \
       objectaccess.o objectaddress.o partition.o kmd_aggregate.o kmd_collation.o \
       kmd_constraint.o kmd_conversion.o \
       kmd_depend.o kmd_enum.o kmd_inherits.o kmd_largeobject.o kmd_namespace.o \
       kmd_operator.o kmd_proc.o kmd_publication.o kmd_range.o \
	   kmd_db_role_setting.o kmd_shdepend.o kmd_subscription.o kmd_type.o \
	   storage.o toasting.o

BKIFILES = postgres.bki postgres.description postgres.shdescription

include $(top_srcdir)/src/backend/common.mk

# Note: the order of this list determines the order in which the catalog
# header files are assembled into postgres.bki.  BKI_BOOTSTRAP catalogs
# must appear first, and there are reputedly other, undocumented ordering
# dependencies.
CATALOG_HEADERS := \
	kmd_proc.h kmd_type.h kmd_attribute.h kmd_class.h \
	kmd_attrdef.h kmd_constraint.h kmd_inherits.h kmd_index.h kmd_operator.h \
	kmd_opfamily.h kmd_opclass.h kmd_am.h kmd_amop.h kmd_amproc.h \
	kmd_language.h kmd_largeobject_metadata.h kmd_largeobject.h kmd_aggregate.h \
	kmd_statistic_ext.h kmd_statistic_ext_data.h \
	kmd_statistic.h kmd_rewrite.h kmd_trigger.h kmd_event_trigger.h kmd_description.h \
	kmd_cast.h kmd_enum.h kmd_namespace.h kmd_conversion.h kmd_depend.h \
	kmd_database.h kmd_db_role_setting.h kmd_tablespace.h kmd_pltemplate.h \
	kmd_authid.h kmd_auth_members.h kmd_shdepend.h kmd_shdescription.h \
	kmd_ts_config.h kmd_ts_config_map.h kmd_ts_dict.h \
	kmd_ts_parser.h kmd_ts_template.h kmd_extension.h \
	kmd_foreign_data_wrapper.h kmd_foreign_server.h kmd_user_mapping.h \
	kmd_foreign_table.h kmd_policy.h kmd_replication_origin.h \
	kmd_default_acl.h kmd_init_privs.h kmd_seclabel.h kmd_shseclabel.h \
	kmd_collation.h kmd_partitioned_table.h kmd_range.h kmd_transform.h \
	kmd_sequence.h kmd_publication.h kmd_publication_rel.h kmd_subscription.h \
	kmd_subscription_rel.h

GENERATED_HEADERS := $(CATALOG_HEADERS:%.h=%_d.h) schemapg.h

# In the list of headers used to assemble postgres.bki, indexing.h needs
# be last, and toasting.h just before it.  This ensures we don't try to
# create indexes or toast tables before their catalogs exist.
POSTGRES_BKI_SRCS := $(addprefix $(top_srcdir)/src/include/catalog/,\
	$(CATALOG_HEADERS) toasting.h indexing.h \
	)

# The .dat files we need can just be listed alphabetically.
POSTGRES_BKI_DATA = $(addprefix $(top_srcdir)/src/include/catalog/,\
	kmd_aggregate.dat kmd_am.dat kmd_amop.dat kmd_amproc.dat kmd_authid.dat \
	kmd_cast.dat kmd_class.dat kmd_collation.dat kmd_conversion.dat \
	kmd_database.dat kmd_language.dat \
	kmd_namespace.dat kmd_opclass.dat kmd_operator.dat kmd_opfamily.dat \
	kmd_pltemplate.dat kmd_proc.dat kmd_range.dat kmd_tablespace.dat \
	kmd_ts_config.dat kmd_ts_config_map.dat kmd_ts_dict.dat kmd_ts_parser.dat \
	kmd_ts_template.dat kmd_type.dat \
	)

all: distprep generated-header-symlinks

distprep: bki-stamp

.PHONY: generated-header-symlinks

generated-header-symlinks: $(top_builddir)/src/include/catalog/header-stamp

# bki-stamp records the last time we ran genbki.pl.  We don't rely on
# the timestamps of the individual output files, because the Perl script
# won't update them if they didn't change (to avoid unnecessary recompiles).
# Technically, this should depend on Makefile.global which supplies
# $(MAJORVERSION); but then genbki.pl would need to be re-run after every
# configure run, even in distribution tarballs.  So depending on configure.in
# instead is cheating a bit, but it will achieve the goal of updating the
# version number when it changes.
bki-stamp: genbki.pl Catalog.pm $(POSTGRES_BKI_SRCS) $(POSTGRES_BKI_DATA) $(top_srcdir)/configure.in
	$(PERL) $< --include-path=$(top_srcdir)/src/include/ \
		--set-version=$(MAJORVERSION) $(POSTGRES_BKI_SRCS)
	touch $@

# The generated headers must all be symlinked into builddir/src/include/,
# using absolute links for the reasons explained in src/backend/Makefile.
# We use header-stamp to record that we've done this because the symlinks
# themselves may appear older than bki-stamp.
$(top_builddir)/src/include/catalog/header-stamp: bki-stamp
	prereqdir=`cd '$(dir $<)' >/dev/null && pwd` && \
	cd '$(dir $@)' && for file in $(GENERATED_HEADERS); do \
	  rm -f $$file && $(LN_S) "$$prereqdir/$$file" . ; \
	done
	touch $@

# Note: installation of generated headers is handled elsewhere
.PHONY: install-data
install-data: bki-stamp installdirs
	$(INSTALL_DATA) $(call vpathsearch,postgres.bki) '$(DESTDIR)$(datadir)/postgres.bki'
	$(INSTALL_DATA) $(call vpathsearch,postgres.description) '$(DESTDIR)$(datadir)/postgres.description'
	$(INSTALL_DATA) $(call vpathsearch,postgres.shdescription) '$(DESTDIR)$(datadir)/postgres.shdescription'
	$(INSTALL_DATA) $(srcdir)/system_views.sql '$(DESTDIR)$(datadir)/system_views.sql'
	$(INSTALL_DATA) $(srcdir)/information_schema.sql '$(DESTDIR)$(datadir)/information_schema.sql'
	$(INSTALL_DATA) $(srcdir)/sql_features.txt '$(DESTDIR)$(datadir)/sql_features.txt'

installdirs:
	$(MKDIR_P) '$(DESTDIR)$(datadir)'

.PHONY: uninstall-data
uninstall-data:
	rm -f $(addprefix '$(DESTDIR)$(datadir)'/, $(BKIFILES) system_views.sql information_schema.sql sql_features.txt)

# postgres.bki, postgres.description, postgres.shdescription,
# and the generated headers are in the distribution tarball,
# so they are not cleaned here.
clean:

maintainer-clean: clean
	rm -f bki-stamp $(BKIFILES) $(GENERATED_HEADERS)
