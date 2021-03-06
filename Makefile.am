## Process this file with automake to produce Makefile.in

ACLOCAL_AMFLAGS		= -I meta/autotools
AUTOMAKE_OPTIONS	= foreign
EXTRA_DIST		= INSTALL			\
			  meta/slackware/slack-desc.in
dist_doc_DATA		= README COPYING
AM_CFLAGS		= $(MMUX_CFLAGS)
AM_CPPFLAGS		= -I$(srcdir)/src
CLEANFILES		=

## --------------------------------------------------------------------

nodist_pkgconfig_DATA	= meta/scripts/cctests.pc


#### documentation

EXTRA_DIST		+= doc/cclibraries.style.css
CLEANFILES		+= doc/cclibraries.css

AM_MAKEINFOFLAGS	= --no-split
AM_MAKEINFOHTMLFLAGS	= --split=node -c WORDS_IN_PAGE=0 --css-ref=cclibraries.css \
	-c PRE_BODY_CLOSE="<p>This document describes version <tt>$(PACKAGE_VERSION)</tt> of <em>$(PACKAGE_NAME)</em>.</p>"

info_TEXINFOS		= doc/cctests.texi
doc_cctests_TEXINFOS	= \
	doc/overview-linking.texi	\
	doc/overview-ccexceptions.texi	\
	doc/macros.texi			\
	doc/lgpl-3.0.texi		\
	doc/fdl-1.3.texi

## --------------------------------------------------------------------

doc/cctests.html/$(am__dirstamp): doc/$(am__dirstamp)
	@$(MKDIR_P) doc/cctests.html/
	@: > doc/cctests.html/$(am__dirstamp)

doc/cctests.html/cclibraries.css: doc/cclibraries.style.css doc/cctests.html/$(am__dirstamp)
	$(INSTALL) -m 0444 "$(top_srcdir)/doc/cclibraries.style.css" "$(builddir)/doc/cctests.html/cclibraries.css"

## --------------------------------------------------------------------

html-local: doc/cctests.html/cclibraries.css

install-html-local:
	$(MKDIR_P) "$(DESTDIR)$(htmldir)/cctests.html/"
	$(INSTALL) -m 0444 $(builddir)/doc/cctests.html/cclibraries.css "$(DESTDIR)$(htmldir)/cctests.html/"


#### libraries

cctests_CURRENT		= @cctests_VERSION_INTERFACE_CURRENT@
cctests_REVISION	= @cctests_VERSION_INTERFACE_REVISION@
cctests_AGE		= @cctests_VERSION_INTERFACE_AGE@
cctests_LINKER_VERSION	= -version-info $(cctests_CURRENT):$(cctests_REVISION):$(cctests_AGE)

include_HEADERS		= src/cctests.h

lib_LTLIBRARIES		= libcctests.la
libcctests_la_CPPFLAGS	= $(AM_CPPFLAGS)
libcctests_la_CFLAGS	= $(AM_CFLAGS) $(CCEXCEPTIONS_CFLAGS)
libcctests_la_LDFLAGS	= $(cctests_LINKER_VERSION) $(AM_LDFLAGS) $(CCEXCEPTIONS_LIBS)
libcctests_la_SOURCES	= \
	src/cctests.h				\
	src/cctests-internals.h			\
	src/cctests-version.c			\
	src/cctests-constants.c			\
	src/cctests-conditions.c		\
	src/cctests-system.c			\
	src/cctests-driver.c			\
	src/cctests-assertions.c		\
	src/cctests-process.c			\
	src/cctests-debugging.c			\
	src/cctests-helpers.c


#### tests

EXTRA_DIST	+= tests/test-utils.h

check_PROGRAMS	= \
	tests/version						\
	tests/assert-conditions					\
	tests/condition-base-subtyping				\
	tests/condition-success-subtyping			\
	tests/condition-skipped-subtyping			\
	tests/condition-failure-subtyping			\
	tests/condition-expected-failure-subtyping		\
	tests/condition-assertion-subtyping			\
	tests/condition-unreachable-subtyping			\
	tests/condition-signal-subtyping			\
	tests/condition-signal-1-subtyping			\
	tests/condition-signal-2-subtyping			\
	tests/condition-signal-3-subtyping			\
	tests/condition-regex-error-subtyping			\
	tests/condition-regex-compilation-error-subtyping	\
	tests/driver						\
	tests/assertions					\
	tests/processes						\
	tests/expected-failure

TESTS				= $(check_PROGRAMS)
XFAIL_TESTS			= tests/assertions

cctests_tests_cppflags		= $(AM_CPPFLAGS) -I$(srcdir)/tests
cctests_tests_cflags		= $(AM_CFLAGS) $(CCEXCEPTIONS_CFLAGS)
cctests_tests_ldadd		= $(AM_LDFLAGS) libcctests.la $(CCEXCEPTIONS_LIBS)

## --------------------------------------------------------------------

tests_version_CFLAGS		= $(cctests_tests_cflags)
tests_version_CPPFLAGS		= $(cctests_tests_cppflags)
tests_version_LDADD		= $(cctests_tests_ldadd)

## --------------------------------------------------------------------

tests_assert_conditions_CFLAGS	= $(cctests_tests_cflags)
tests_assert_conditions_CPPFLAGS= $(cctests_tests_cppflags)
tests_assert_conditions_LDADD	= $(cctests_tests_ldadd)

tests/assert_conditions.$(OBJEXT):	tests/test-utils.h

## --------------------------------------------------------------------

tests_condition_base_subtyping_CFLAGS		= $(cctests_tests_cflags)
tests_condition_base_subtyping_CPPFLAGS		= $(cctests_tests_cppflags)
tests_condition_base_subtyping_LDADD		= $(cctests_tests_ldadd)
tests_condition_base_subtyping_SOURCES		= \
	tests/condition-base-subtyping.c	\
	tests/condition-base-subtyping-body.c	\
	tests/condition-base-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_success_subtyping_CFLAGS	= $(cctests_tests_cflags)
tests_condition_success_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_success_subtyping_LDADD		= $(cctests_tests_ldadd)
tests_condition_success_subtyping_SOURCES	= \
	tests/condition-success-subtyping.c		\
	tests/condition-success-subtyping-body.c	\
	tests/condition-success-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_skipped_subtyping_CFLAGS	= $(cctests_tests_cflags)
tests_condition_skipped_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_skipped_subtyping_LDADD		= $(cctests_tests_ldadd)
tests_condition_skipped_subtyping_SOURCES	= \
	tests/condition-skipped-subtyping.c		\
	tests/condition-skipped-subtyping-body.c	\
	tests/condition-skipped-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_failure_subtyping_CFLAGS	= $(cctests_tests_cflags)
tests_condition_failure_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_failure_subtyping_LDADD		= $(cctests_tests_ldadd)
tests_condition_failure_subtyping_SOURCES	= \
	tests/condition-failure-subtyping.c		\
	tests/condition-failure-subtyping-body.c	\
	tests/condition-failure-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_expected_failure_subtyping_CFLAGS	= $(cctests_tests_cflags)
tests_condition_expected_failure_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_expected_failure_subtyping_LDADD	= $(cctests_tests_ldadd)
tests_condition_expected_failure_subtyping_SOURCES	= \
	tests/condition-expected-failure-subtyping.c		\
	tests/condition-expected-failure-subtyping-body.c	\
	tests/condition-expected-failure-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_assertion_subtyping_CFLAGS	= $(cctests_tests_cflags)
tests_condition_assertion_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_assertion_subtyping_LDADD	= $(cctests_tests_ldadd)
tests_condition_assertion_subtyping_SOURCES	= \
	tests/condition-assertion-subtyping.c		\
	tests/condition-assertion-subtyping-body.c	\
	tests/condition-assertion-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_unreachable_subtyping_CFLAGS	= $(cctests_tests_cflags)
tests_condition_unreachable_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_unreachable_subtyping_LDADD	= $(cctests_tests_ldadd)
tests_condition_unreachable_subtyping_SOURCES	= \
	tests/condition-unreachable-subtyping.c		\
	tests/condition-unreachable-subtyping-body.c	\
	tests/condition-unreachable-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_signal_subtyping_CFLAGS		= $(cctests_tests_cflags)
tests_condition_signal_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_signal_subtyping_LDADD		= $(cctests_tests_ldadd)
tests_condition_signal_subtyping_SOURCES	= \
	tests/condition-signal-subtyping.c		\
	tests/condition-signal-subtyping-body.c		\
	tests/condition-signal-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_signal_1_subtyping_CFLAGS	= $(cctests_tests_cflags)
tests_condition_signal_1_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_signal_1_subtyping_LDADD	= $(cctests_tests_ldadd)
tests_condition_signal_1_subtyping_SOURCES	= \
	tests/condition-signal-1-subtyping.c		\
	tests/condition-signal-1-subtyping-body.c	\
	tests/condition-signal-1-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_signal_2_subtyping_CFLAGS	= $(cctests_tests_cflags)
tests_condition_signal_2_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_signal_2_subtyping_LDADD	= $(cctests_tests_ldadd)
tests_condition_signal_2_subtyping_SOURCES	= \
	tests/condition-signal-2-subtyping.c		\
	tests/condition-signal-2-subtyping-body.c	\
	tests/condition-signal-2-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_signal_3_subtyping_CFLAGS	= $(cctests_tests_cflags)
tests_condition_signal_3_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_signal_3_subtyping_LDADD	= $(cctests_tests_ldadd)
tests_condition_signal_3_subtyping_SOURCES	= \
	tests/condition-signal-3-subtyping.c		\
	tests/condition-signal-3-subtyping-body.c	\
	tests/condition-signal-3-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_regex_error_subtyping_CFLAGS	= $(cctests_tests_cflags)
tests_condition_regex_error_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_regex_error_subtyping_LDADD	= $(cctests_tests_ldadd)
tests_condition_regex_error_subtyping_SOURCES	= \
	tests/condition-regex-error-subtyping.c		\
	tests/condition-regex-error-subtyping-body.c	\
	tests/condition-regex-error-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_regex_compilation_error_subtyping_CFLAGS	= $(cctests_tests_cflags)
tests_condition_regex_compilation_error_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_regex_compilation_error_subtyping_LDADD		= $(cctests_tests_ldadd)
tests_condition_regex_compilation_error_subtyping_SOURCES	= \
	tests/condition-regex-compilation-error-subtyping.c		\
	tests/condition-regex-compilation-error-subtyping-body.c	\
	tests/condition-regex-compilation-error-subtyping-header.h

## --------------------------------------------------------------------

tests_driver_CFLAGS		= $(cctests_tests_cflags)
tests_driver_CPPFLAGS		= $(cctests_tests_cppflags)
tests_driver_LDADD		= $(cctests_tests_ldadd)

tests/driver.$(OBJEXT):		tests/test-utils.h

## --------------------------------------------------------------------

tests_assertions_CFLAGS		= $(cctests_tests_cflags)
tests_assertions_CPPFLAGS	= $(cctests_tests_cppflags)
tests_assertions_LDADD		= $(cctests_tests_ldadd)

## --------------------------------------------------------------------

tests_processes_CFLAGS		= $(cctests_tests_cflags)
tests_processes_CPPFLAGS	= $(cctests_tests_cppflags)
tests_processes_LDADD		= $(cctests_tests_ldadd)

## --------------------------------------------------------------------

tests_expected_failure_CFLAGS	= $(cctests_tests_cflags)
tests_expected_failure_CPPFLAGS	= $(cctests_tests_cppflags)
tests_expected_failure_LDADD	= $(cctests_tests_ldadd)

## --------------------------------------------------------------------

.PHONY: test

test:
	for f in ./tests/$(file) ; do $(MAKE) $$f ; $$f ; done

## --------------------------------------------------------------------

installcheck-local: $(TESTS)
	@for f in $(TESTS); do $(builddir)/$$f; done


#### common rules

include $(top_srcdir)/meta/automake/mmux-makefile-rules

### end of file
