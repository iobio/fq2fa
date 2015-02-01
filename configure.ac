#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([fq2fa], [0.1.0], [atrusqiao@gmail.com])
AC_CONFIG_SRCDIR([src/main.cc])
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])

# Fixing file creation time
find ${srcdir} -name aclocal.m4 -exec touch {} \;
find ${srcdir} -name \*.in -exec touch {} \;
find ${srcdir} -name configure -exec touch {} \;

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AM_PROG_AR
LT_PREREQ([2.2])
LT_INIT()
AC_LANG([C++])
AX_CXX_COMPILE_STDCXX_11([noext], [mandatory])
AX_GCC_ARCHFLAG

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([ctypes.h string.h stdlib.h memory string])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC

AC_CONFIG_SUBDIRS([vendor/YiCppLib/KSeqCpp])

AC_CONFIG_FILES([Makefile
				 src/Makefile
				 ])
AC_OUTPUT
