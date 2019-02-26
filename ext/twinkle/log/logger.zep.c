
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * Created by PhpStorm.
 * User: xiehuanjin
 * Date: 2019/1/12
 * Time: 16:09
 */
ZEPHIR_INIT_CLASS(Twinkle_Log_Logger) {

	ZEPHIR_REGISTER_CLASS_EX(Twinkle\\Log, Logger, twinkle, log_logger, zephir_get_internal_ce(SL("psr\\log\\abstractlogger")), twinkle_log_logger_method_entry, 0);

	zend_declare_property_null(twinkle_log_logger_ce, SL("logger"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Twinkle_Log_Logger, __construct) {

	zval *storage, storage_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&storage_sub);

	zephir_fetch_params(0, 1, 0, &storage);



	zephir_update_property_zval(this_ptr, SL("logger"), storage);

}

PHP_METHOD(Twinkle_Log_Logger, log) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *level, level_sub, *message, message_sub, *context_param = NULL, trace, _2, _3, _0$$4, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level, &message, &context_param);

	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	if (zephir_array_isset_string(&context, SL("trace"))) {
		ZEPHIR_OBS_VAR(&trace);
		zephir_array_fetch_string(&trace, &context, SL("trace"), PH_NOISY, "twinkle/log/logger.zep", 25 TSRMLS_CC);
		zephir_array_unset_string(&context, SL("trace"), PH_SEPARATE);
	} else {
		ZVAL_LONG(&_0$$4, 2);
		ZVAL_LONG(&_1$$4, 2);
		ZEPHIR_CALL_FUNCTION(&trace, "debug_backtrace", NULL, 12, &_0$$4, &_1$$4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_2);
	if (!(ZEPHIR_IS_EMPTY(&trace))) {
		ZEPHIR_OBS_NVAR(&_2);
		zephir_array_fetch_long(&_2, &trace, 1, PH_NOISY, "twinkle/log/logger.zep", 30 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_2);
		array_init(&_2);
	}
	ZEPHIR_CPY_WRT(&trace, &_2);
	zephir_read_property(&_3, this_ptr, SL("logger"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "process", NULL, 0, level, &trace, message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Twinkle_Log_Logger, __destruct) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("logger"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "flushlogs", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

