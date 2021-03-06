/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_STRDUMPER_H
#define PHP_STRDUMPER_H

extern zend_module_entry strdumper_module_entry;
#define phpext_strdumper_ptr &strdumper_module_entry

#define PHP_STRDUMPER_VERSION "0.1.0"

#ifdef PHP_WIN32
#	define PHP_STRDUMPER_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_STRDUMPER_API __attribute__ ((visibility("default")))
#else
#	define PHP_STRDUMPER_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#if PHP_VERSION_ID >= 70000
#  define STRDUMPER_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(strdumper, v)
#  if defined(ZTS) && defined(COMPILE_DL_STRDUMPER)
     ZEND_TSRMLS_CACHE_EXTERN();
#  endif
#else
#  ifdef ZTS
#    define STRDUMPER_G(v) TSRMG(strdumper_globals_id, zend_strdumper_globals *, v)
#  else
#    define STRDUMPER_G(v) (strdumper_globals.v)
#  endif
#endif

#endif	/* PHP_STRDUMPER_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
