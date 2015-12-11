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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_strdumper.h"

/* True global resources - no need for thread safety here */
static int le_strdumper;

#define Z_IS_INTERNED_STR_P(zp) z_is_interned_str_p(zp)

static inline int z_is_interned_str_p(zval *zp)
{
	if (Z_TYPE_P(zp) != IS_STRING) {
		return 0;
	}
#if PHP_VERSION_ID >= 70000
	if (!ZSTR_IS_INTERNED(Z_STR_P(zp))) {
		return 0;
	}
#else
	if (!IS_INTERNED(Z_STRVAL_P(zp))) {
		return 0;
	}
#endif
	return 1;
}

/* {{{ proto void str_dump(mixed var) */
PHP_FUNCTION(str_dump)
{
	zval *var;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &var) == FAILURE) {
		RETURN_TRUE;
	}
	if (Z_TYPE_P(var) != IS_STRING) {
		php_printf("not string\n");
		RETURN_TRUE;
	}
	php_printf("string(%d) \"", Z_STRLEN_P(var));
	PHPWRITE(Z_STRVAL_P(var), Z_STRLEN_P(var));
	php_printf("\"(%p) ", Z_STRVAL_P(var));
#if PHP_VERSION_ID >= 70000
	php_printf("refcount(%u)", Z_REFCOUNTED_P(var) ? Z_REFCOUNT_P(var) : 1);
#else
	php_printf("refcount(%u)", Z_REFCOUNT_P(var));
#endif
	if (Z_IS_INTERNED_STR_P(var)) {
		php_printf(" interned");
	}
	php_printf("\n");
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool is_interned(mixed var) */
PHP_FUNCTION(is_interned)
{
	zval *var;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &var) == FAILURE) {
		RETURN_FALSE;
	}
	if (Z_IS_INTERNED_STR_P(var)) {
		RETURN_TRUE;
	}
	RETURN_FALSE;
}
/* }}} */

/* {{{ proto array interned_strings() */
PHP_FUNCTION(interned_strings)
{
#if PHP_VERSION_ID >= 70000
	zend_string *entry;

	array_init(return_value);
	ZEND_HASH_FOREACH_STR_KEY(&CG(interned_strings), entry) {
		add_next_index_str(return_value, entry);
	} ZEND_HASH_FOREACH_END();
#else
	Bucket *p;

	array_init(return_value);

	p = CG(interned_strings).pListHead;
	while (p != NULL) {
		add_next_index_stringl(return_value, p->arKey, p->nKeyLength-1, 0);
		p = p->pListNext;
	}
#endif
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(strdumper)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(strdumper)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(strdumper)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(strdumper)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(strdumper)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "strdumper support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ strdumper_functions[]
 *
 * Every user visible function must have an entry in strdumper_functions[].
 */
const zend_function_entry strdumper_functions[] = {
	PHP_FE(str_dump, NULL)
	PHP_FE(is_interned, NULL)
	PHP_FE(interned_strings, NULL)
	PHP_FE_END	/* Must be the last line in strdumper_functions[] */
};
/* }}} */

/* {{{ strdumper_module_entry
 */
zend_module_entry strdumper_module_entry = {
	STANDARD_MODULE_HEADER,
	"strdumper",
	strdumper_functions,
	PHP_MINIT(strdumper),
	PHP_MSHUTDOWN(strdumper),
	PHP_RINIT(strdumper),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(strdumper),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(strdumper),
	PHP_STRDUMPER_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_STRDUMPER
ZEND_GET_MODULE(strdumper)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
