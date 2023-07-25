AC_INIT([ThorsLogging], [0.1], [Loki.Astari+ThorsLogging@gmail.com])
AC_PREREQ([2.65])

AC_CONFIG_MACRO_DIR([build/autotools/m4])
AC_CONFIG_AUX_DIR([build/autotools/build])

AX_THOR_FUNC_INIT_BUILD([ThorsLogging], [src/ThorsLogging/ThorsLogging.h])

AX_THOR_FEATURE_HEADER_ONLY_VARIANT([THORS_LOGGING])

AC_CHECK_LIB([dl],    [dlopen], [], [AC_MSG_ERROR([The build tools needs libdl. Please install it.])])

LT_INIT

AX_THOR_FUNC_TERM_BUILD([LOGGING], [src/ThorsLogging/ThorsLoggingConfig.h])

AC_OUTPUT
