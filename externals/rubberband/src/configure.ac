
AC_INIT(RubberBand, 1.7, cannam@all-day-breakfast.com)

AC_CONFIG_SRCDIR(src/StretcherImpl.h)
AC_PROG_CXX
AC_HEADER_STDC
AC_C_BIGENDIAN

PKG_CHECK_MODULES([SNDFILE],[sndfile])
AC_SUBST(SNDFILE_CFLAGS)
AC_SUBST(SNDFILE_LIBS)

AC_CHECK_HEADERS(pthread.h)

changequote(,)dnl
if test "x$GCC" = "xyes"; then
  case " $CFLAGS " in
    *[\ \	]-fPIC\ -Wall[\ \	]*) ;;
    *) CFLAGS="$CFLAGS -fPIC -Wall" ;;
  esac
  case " $CXXFLAGS " in
    *[\ \	]-fPIC\ -Wall[\ \	]*) ;;
    *) CXXFLAGS="$CXXFLAGS -fPIC -Wall" ;;
  esac
fi
changequote([,])dnl

AC_OUTPUT([Makefile])

