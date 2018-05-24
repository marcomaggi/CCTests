## Process this file with automake to produce Makefile.in

ACLOCAL_AMFLAGS		= -I meta/autotools
AUTOMAKE_OPTIONS	= foreign
EXTRA_DIST		= INSTALL			\
			  meta/slackstuff/config.in	\
			  meta/slackware/slack-desc.in
dist_doc_DATA		= README COPYING
AM_CFLAGS		= -I$(srcdir)/src $(AX_CFLAGS)

## --------------------------------------------------------------------

EXTRA_DIST		+= meta/scripts/cctests.pc.in
pkgconfigdir		= $(libdir)/pkgconfig
nodist_pkgconfig_DATA	= meta/scripts/cctests.pc

## --------------------------------------------------------------------

AM_MAKEINFOFLAGS	= --no-split

info_TEXINFOS		= doc/cctests.texi
doc_cctests_TEXINFOS	= \
	doc/macros.texi		\
	doc/lgpl-3.0.texi	\
	doc/fdl-1.3.texi

#page
#### libraries

cctests_CURRENT		= @cctests_VERSION_INTERFACE_CURRENT@
cctests_REVISION	= @cctests_VERSION_INTERFACE_REVISION@
cctests_AGE		= @cctests_VERSION_INTERFACE_AGE@

include_HEADERS		= src/cctests.h

lib_LTLIBRARIES		= libcctests.la
libcctests_la_CPPFLAGS	= $(CCEXCEPTIONS_CFLAGS)
libcctests_la_LDFLAGS	= -version-info $(cctests_CURRENT):$(cctests_REVISION):$(cctests_AGE) \
			  $(CCEXCEPTIONS_LIBS)
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
	src/cctests-helpers.c

#page
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

cctests_tests_cppflags		= -I$(srcdir)/src -I$(srcdir)/tests $(CCEXCEPTIONS_CFLAGS)
cctests_tests_ldadd		= $(CCEXCEPTIONS_LIBS) libcctests.la

## --------------------------------------------------------------------

tests_version_CPPFLAGS		= $(cctests_tests_cppflags)
tests_version_LDADD		= $(cctests_tests_ldadd)

## --------------------------------------------------------------------

tests_assert_conditions_CPPFLAGS= $(cctests_tests_cppflags)
tests_assert_conditions_LDADD	= $(cctests_tests_ldadd)

tests/assert_conditions.$(OBJEXT):	tests/test-utils.h

## --------------------------------------------------------------------

tests_condition_base_subtyping_CPPFLAGS		= $(cctests_tests_cppflags)
tests_condition_base_subtyping_LDADD		= $(cctests_tests_ldadd)
tests_condition_base_subtyping_SOURCES		= \
	tests/condition-base-subtyping.c	\
	tests/condition-base-subtyping-body.c	\
	tests/condition-base-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_success_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_success_subtyping_LDADD		= $(cctests_tests_ldadd)
tests_condition_success_subtyping_SOURCES	= \
	tests/condition-success-subtyping.c		\
	tests/condition-success-subtyping-body.c	\
	tests/condition-success-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_skipped_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_skipped_subtyping_LDADD		= $(cctests_tests_ldadd)
tests_condition_skipped_subtyping_SOURCES	= \
	tests/condition-skipped-subtyping.c		\
	tests/condition-skipped-subtyping-body.c	\
	tests/condition-skipped-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_failure_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_failure_subtyping_LDADD		= $(cctests_tests_ldadd)
tests_condition_failure_subtyping_SOURCES	= \
	tests/condition-failure-subtyping.c		\
	tests/condition-failure-subtyping-body.c	\
	tests/condition-failure-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_expected_failure_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_expected_failure_subtyping_LDADD	= $(cctests_tests_ldadd)
tests_condition_expected_failure_subtyping_SOURCES	= \
	tests/condition-expected-failure-subtyping.c		\
	tests/condition-expected-failure-subtyping-body.c	\
	tests/condition-expected-failure-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_assertion_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_assertion_subtyping_LDADD	= $(cctests_tests_ldadd)
tests_condition_assertion_subtyping_SOURCES	= \
	tests/condition-assertion-subtyping.c		\
	tests/condition-assertion-subtyping-body.c	\
	tests/condition-assertion-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_unreachable_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_unreachable_subtyping_LDADD	= $(cctests_tests_ldadd)
tests_condition_unreachable_subtyping_SOURCES	= \
	tests/condition-unreachable-subtyping.c		\
	tests/condition-unreachable-subtyping-body.c	\
	tests/condition-unreachable-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_signal_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_signal_subtyping_LDADD		= $(cctests_tests_ldadd)
tests_condition_signal_subtyping_SOURCES	= \
	tests/condition-signal-subtyping.c		\
	tests/condition-signal-subtyping-body.c		\
	tests/condition-signal-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_signal_1_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_signal_1_subtyping_LDADD	= $(cctests_tests_ldadd)
tests_condition_signal_1_subtyping_SOURCES	= \
	tests/condition-signal-1-subtyping.c		\
	tests/condition-signal-1-subtyping-body.c	\
	tests/condition-signal-1-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_signal_2_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_signal_2_subtyping_LDADD	= $(cctests_tests_ldadd)
tests_condition_signal_2_subtyping_SOURCES	= \
	tests/condition-signal-2-subtyping.c		\
	tests/condition-signal-2-subtyping-body.c	\
	tests/condition-signal-2-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_signal_3_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_signal_3_subtyping_LDADD	= $(cctests_tests_ldadd)
tests_condition_signal_3_subtyping_SOURCES	= \
	tests/condition-signal-3-subtyping.c		\
	tests/condition-signal-3-subtyping-body.c	\
	tests/condition-signal-3-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_regex_error_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_regex_error_subtyping_LDADD	= $(cctests_tests_ldadd)
tests_condition_regex_error_subtyping_SOURCES	= \
	tests/condition-regex-error-subtyping.c		\
	tests/condition-regex-error-subtyping-body.c	\
	tests/condition-regex-error-subtyping-header.h

## --------------------------------------------------------------------

tests_condition_regex_compilation_error_subtyping_CPPFLAGS	= $(cctests_tests_cppflags)
tests_condition_regex_compilation_error_subtyping_LDADD		= $(cctests_tests_ldadd)
tests_condition_regex_compilation_error_subtyping_SOURCES	= \
	tests/condition-regex-compilation-error-subtyping.c		\
	tests/condition-regex-compilation-error-subtyping-body.c	\
	tests/condition-regex-compilation-error-subtyping-header.h

## --------------------------------------------------------------------

tests_driver_CPPFLAGS		= $(cctests_tests_cppflags)
tests_driver_LDADD		= $(cctests_tests_ldadd)

tests/driver.$(OBJEXT):		tests/test-utils.h

## --------------------------------------------------------------------

tests_assertions_CPPFLAGS	= $(cctests_tests_cppflags)
tests_assertions_LDADD		= $(cctests_tests_ldadd)

## --------------------------------------------------------------------

tests_processes_CPPFLAGS	= $(cctests_tests_cppflags)
tests_processes_LDADD		= $(cctests_tests_ldadd)

## --------------------------------------------------------------------

tests_expected_failure_CPPFLAGS	= $(cctests_tests_cppflags)
tests_expected_failure_LDADD	= $(cctests_tests_ldadd)

## --------------------------------------------------------------------

installcheck-local: $(TESTS)
	@for f in $(TESTS); do $(builddir)/$$f; done

#page
#### testing under GDB

$(builddir)/.gdbinit:
	ln -sv "$(top_srcdir)/gdbinit" "$(builddir)/.gdbinit"

# This rule is meant to be used as:
#
#   $ make all gdb-test FILE=tests/inspection CFLAGS='-g'
#
# after having created an appropriate file "$(top_srcdir)/.gdbinit".
#
gdb-test: $(builddir)/.gdbinit
	libtool --mode=execute gdb $$FILE

#page
#### Static analysis with Clang's Static Analyzer
#
# See the documentation for the command line tool at:
#
#    <http://clang-analyzer.llvm.org/scan-build.html>
#
# To run the tool we must do:
#
#    $ make clean
#    $ make clang-static-analysis
#
# The  program  "scan-build"  works  by  overriding  the  CC  and  CXX
# environment variables.  Automake defines CXX as:
#
#    CXX = g++ -std=c++11
#
# so we override CXXFLAGS to include the language specification.
#

.PHONY: clang-static-analysis

clang-static-analysis:
	scan-build make CXXFLAGS='-std=c++11'

### end of file
