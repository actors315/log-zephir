
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "twinkle.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *twinkle_log_storageinterface_ce;
zend_class_entry *twinkle_log_drivers_log_ce;
zend_class_entry *twinkle_log_format_base_ce;
zend_class_entry *twinkle_0__closure_ce;
zend_class_entry *twinkle_log_drivers_file_ce;
zend_class_entry *twinkle_log_format_fileline_ce;
zend_class_entry *twinkle_log_logger_ce;
zend_class_entry *twinkle_log_request_ce;

ZEND_DECLARE_MODULE_GLOBALS(twinkle)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(twinkle)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Twinkle_Log_StorageInterface);
	ZEPHIR_INIT(Twinkle_Log_Drivers_Log);
	ZEPHIR_INIT(Twinkle_Log_Format_Base);
	ZEPHIR_INIT(Twinkle_Log_Drivers_File);
	ZEPHIR_INIT(Twinkle_Log_Format_FileLine);
	ZEPHIR_INIT(Twinkle_Log_Logger);
	ZEPHIR_INIT(Twinkle_Log_Request);
	ZEPHIR_INIT(twinkle_0__closure);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(twinkle)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_twinkle_globals *twinkle_globals TSRMLS_DC)
{
	twinkle_globals->initialized = 0;

	/* Memory options */
	twinkle_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	twinkle_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	twinkle_globals->cache_enabled = 1;

	/* Recursive Lock */
	twinkle_globals->recursive_lock = 0;

	/* Static cache */
	memset(twinkle_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_twinkle_globals *twinkle_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(twinkle)
{
	zend_twinkle_globals *twinkle_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	twinkle_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(twinkle_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(twinkle_globals_ptr TSRMLS_CC);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(twinkle)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(twinkle)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_TWINKLE_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_TWINKLE_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_TWINKLE_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_TWINKLE_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_TWINKLE_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(twinkle)
{
	php_zephir_init_globals(twinkle_globals TSRMLS_CC);
	php_zephir_init_module_globals(twinkle_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(twinkle)
{
	
}


zend_function_entry php_twinkle_functions[] = {
	ZEND_FE_END

};

zend_module_entry twinkle_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_TWINKLE_EXTNAME,
	php_twinkle_functions,
	PHP_MINIT(twinkle),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(twinkle),
#else
	NULL,
#endif
	PHP_RINIT(twinkle),
	PHP_RSHUTDOWN(twinkle),
	PHP_MINFO(twinkle),
	PHP_TWINKLE_VERSION,
	ZEND_MODULE_GLOBALS(twinkle),
	PHP_GINIT(twinkle),
	PHP_GSHUTDOWN(twinkle),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(twinkle),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_TWINKLE
ZEND_GET_MODULE(twinkle)
#endif
