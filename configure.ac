dnl @configure_input@
dnl

AC_PREREQ([2.69])
MMUX_PKG_VERSIONS([0],[3],[0],[devel.7])
AC_INIT([CCTests],[MMUX_PACKAGE_VERSION],
  [marco.maggi-ipsu@poste.it],
  [cctests],[https://github.com/marcomaggi/cctests])
MMUX_INIT
MMUX_LIBTOOL_LIBRARY_VERSIONS([cctests],3,0,0)
AC_REVISION([0.1])
AC_COPYRIGHT([Copyright (c) 2017, 2018, 2019 Marco Maggi <marco.maggi-ipsu@poste.it>

This program is free software: you  can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free  Software Foundation, either version  3 of the License,  or (at
your option) any later version.

This program  is distributed  in the  hope that it  will be  useful, but
WITHOUT   ANY   WARRANTY;  without   even   the   implied  warranty   of
MERCHANTABILITY  or  FITNESS FOR  A  PARTICULAR  PURPOSE.  See  the  GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
])
AC_CONFIG_SRCDIR([src/])
AC_CONFIG_MACRO_DIR([meta/autotools])
AC_CONFIG_AUX_DIR([meta/autotools])
AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([foreign subdir-objects])
AM_MAINTAINER_MODE

AM_PROG_AR
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_MKDIR_P

LT_PREREQ([2.4])
LT_INIT


#### basic system inspection

MMUX_CHECK_TARGET_OS
AX_IS_RELEASE([git-directory])

AC_LANG([C])
MMUX_LANG_C11

AM_PROG_AS
AM_PROG_CC_C_O
AC_HEADER_STDC
AC_HEADER_STDBOOL
AC_CHECK_HEADERS([stddef.h regex.h unistd.h sys/types.h sys/wait.h])

MMUX_DETERMINE_SIZEOF([LONG],      [long])
MMUX_DETERMINE_SIZEOF([SIZE_T],    [size_t],    [MMUX_INCLUDE_STDDEF_H])
MMUX_DETERMINE_SIZEOF([SSIZE_T],   [ssize_t],   [MMUX_INCLUDE_UNISTD_H])
MMUX_DETERMINE_SIZEOF([PTRDIFF_T], [ptrdiff_t], [MMUX_INCLUDE_STDINT_H])
MMUX_DETERMINE_SIZEOF([INTPTR_T],  [intptr_t],  [MMUX_INCLUDE_STDINT_H])
MMUX_DETERMINE_SIZEOF([UINTPTR_T], [uintptr_t], [MMUX_INCLUDE_STDINT_H])

AC_CACHE_SAVE


#### checks for library functions

AC_CHECK_FUNCS([fork waitpid])
AC_CHECK_FUNCS([getenv isatty])

AC_CACHE_SAVE


#### external libraries

MMUX_CHECK_PKG_CONFIG_MACROS
PKG_INSTALLDIR
PKG_CHECK_MODULES([CCEXCEPTIONS],[ccexceptions >= 0.8.0])

MMUX_PKG_CONFIG_FIND_INCLUDE_FILE([ccexceptions],[ccexceptions.h])

AC_CACHE_SAVE


#### finish

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile]
   [meta/scripts/cctests.pc]
   [meta/slackware/slack-desc])
MMUX_OUTPUT
AC_OUTPUT

### end of file
