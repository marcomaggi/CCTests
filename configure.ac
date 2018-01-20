dnl @configure_input@
dnl

AC_PREREQ([2.69])
AC_INIT([CCTests],[0.1.0-devel.1],
  [marco.maggi-ipsu@poste.it],
  [cctests],[http://marcomaggi.github.com/cctests])
dnl This is the revision number of this configure.ac
AC_REVISION([0.1])
AC_COPYRIGHT([Copyright (c) 2017, 2018 Marco Maggi <marco.maggi-ipsu@poste.it>

This program is free software: you  can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free  Software Foundation, either version  3 of the License,  or (at
your option) any later version.

This program  is distributed  in the  hope that it  will be  useful, but
WITHOUT   ANY   WARRANTY;  without   even   the   implied  warranty   of
MERCHANTABILITY  or  FITNESS FOR  A  PARTICULAR  PURPOSE.  See  the  GNU
General Public License for more details.

You should have received a copy  of the GNU General Public License along
with this program.  If not, see <http://www.gnu.org/licenses/>.
])
AC_CONFIG_SRCDIR([src/])
AC_CONFIG_MACRO_DIR([meta/autotools])
AC_CONFIG_AUX_DIR([meta/autotools])
AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([foreign dist-xz no-dist-gzip subdir-objects])
AM_MAINTAINER_MODE

AM_PROG_AR
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_MKDIR_P

LT_PREREQ([2.4])
LT_INIT

dnl page
#### libraries interface version

AS_VAR_SET([SLACKSTUFF_PACKAGE_VERSION],[0.1d0.1])
AC_SUBST([SLACKSTUFF_PACKAGE_VERSION])

dnl This is the version stored in the pkg-config data file.
AC_SUBST([CCTESTS_PKG_CONFIG_VERSION],[0.1])

MM_LIBTOOL_LIBRARY_VERSIONS([cctests],1,0,0)

dnl page
#### basic system inspection

AC_LANG([C])
AC_PROG_CC_C99
AX_CHECK_COMPILE_FLAG([-std=c11],[],[AC_MSG_ERROR([*** Compiler does not support -std=c11])],[-pedantic])

AS_VAR_SET(AX_CFLAGS,[-std=c11])
AS_VAR_APPEND(AX_CFLAGS,[" -Wall -Wextra"])
AX_GCC_VERSION
AS_IF([test "x$GCC" = "xyes"],
  [AS_CASE("$GCC_VERSION",
     [7.*],[AS_VAR_APPEND(AX_CFLAGS,[" -pedantic -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wrestrict -Wnull-dereference -Wjump-misses-init -Wdouble-promotion -Wshadow -Wformat=2 -Wmisleading-indentation"])])])
AC_SUBST(AX_CFLAGS)

AM_PROG_AS
AM_PROG_CC_C_O
AC_HEADER_STDC
AC_CHECK_HEADERS([regex.h])
dnl AC_CHECK_SIZEOF(void *)

AC_CACHE_SAVE

dnl page
#### checks for library functions

dnl AC_FUNC_MALLOC
dnl AC_FUNC_MEMCMP
dnl AC_CHECK_FUNCS([memmove memset strerror])
dnl AC_CHECK_FUNCS([mmap munmap msync mremap madvise mlock munlock mlockall munlockall mprotect])
AC_CHECK_FUNCS([getenv])

AC_CACHE_SAVE

dnl page
#### external libraries

PKG_CHECK_MODULES([CCEXCEPTIONS],[ccexceptions >= 0.6.2])
PKG_CHECK_MODULES([CCSYS],[ccsys >= 0.1.0])

AC_CACHE_SAVE

dnl page
#### operating system specific configuration

dnl AS_CASE("$target_os",
dnl   [*linux*],[],
dnl   [*bsd*],[],
dnl   [*cygwin*],[],
dnl   [*darwin*],[cctests_OS_DARWIN=yes])
dnl AM_CONDITIONAL([WANT_LINUX], [test "x$cctests_OS_LINUX"  = xyes])
dnl AM_CONDITIONAL([WANT_BSD],   [test "x$cctests_OS_BSD"    = xyes])
dnl AM_CONDITIONAL([WANT_CYGWIN],[test "x$cctests_OS_CYGWIN" = xyes])
dnl AM_CONDITIONAL([WANT_DARWIN],[test "x$cctests_OS_DARWIN" = xyes])

dnl page
#### finish

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile]
   [meta/scripts/cctests.pc]
   [meta/slackstuff/config]
   [meta/slackware/slack-desc])
AC_OUTPUT

### end of file
# Local Variables:
# mode: autoconf
# page-delimiter: "^dnl page"
# End:
