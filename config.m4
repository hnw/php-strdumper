dnl $Id$
dnl config.m4 for extension strdumper

PHP_ARG_ENABLE(strdumper, whether to enable strdumper support,
Make sure that the comment is aligned:
[  --enable-strdumper           Enable strdumper support])

if test "$PHP_STRDUMPER" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-strdumper -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/strdumper.h"  # you most likely want to change this
  dnl if test -r $PHP_STRDUMPER/$SEARCH_FOR; then # path given as parameter
  dnl   STRDUMPER_DIR=$PHP_STRDUMPER
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for strdumper files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       STRDUMPER_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$STRDUMPER_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the strdumper distribution])
  dnl fi

  dnl # --with-strdumper -> add include path
  dnl PHP_ADD_INCLUDE($STRDUMPER_DIR/include)

  dnl # --with-strdumper -> check for lib and symbol presence
  dnl LIBNAME=strdumper # you may want to change this
  dnl LIBSYMBOL=strdumper # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $STRDUMPER_DIR/$PHP_LIBDIR, STRDUMPER_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_STRDUMPERLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong strdumper lib version or lib not found])
  dnl ],[
  dnl   -L$STRDUMPER_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(STRDUMPER_SHARED_LIBADD)

  PHP_NEW_EXTENSION(strdumper, strdumper.c, $ext_shared)
fi
