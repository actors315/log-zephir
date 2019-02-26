
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Created by PhpStorm.
 * User: xiehuanjin
 * Date: 2019/1/12
 * Time: 17:13
 */
ZEPHIR_INIT_CLASS(Twinkle_Log_Request) {

	ZEPHIR_REGISTER_CLASS(Twinkle\\Log, Request, twinkle, log_request, twinkle_log_request_method_entry, 0);

	zend_declare_property_null(twinkle_log_request_ce, SL("instance"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(twinkle_log_request_ce, SL("requestId"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Twinkle_Log_Request, __construct) {

	zval *this_ptr = getThis();



}

PHP_METHOD(Twinkle_Log_Request, singleton) {

	zval _0, _2, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, twinkle_log_request_ce, SL("instance"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, twinkle_log_request_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 13);
		zephir_check_call_status();
		zend_update_static_property(twinkle_log_request_ce, ZEND_STRL("instance"), &_1$$3);
	}
	zephir_read_static_property_ce(&_2, twinkle_log_request_ce, SL("instance"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_2);

}

PHP_METHOD(Twinkle_Log_Request, getRequestId) {

	zval __$true, _SERVER, hash, data, _0, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _1$$3, _2$$5, _3$$5, _4$$5, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, twinkle_log_request_ce, SL("requestId"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_0))) {
		zephir_read_static_property_ce(&_1$$3, twinkle_log_request_ce, SL("requestId"), PH_NOISY_CC | PH_READONLY);
		RETURN_CTOR(&_1$$3);
	}
	if ((zephir_function_exists_ex(SL("session_create_id") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&hash, "session_create_id", NULL, 14);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "");
		ZEPHIR_CALL_FUNCTION(&data, "uniqid", NULL, 15, &_2$$5, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$5);
		if (zephir_array_isset_string(&_SERVER, SL("REQUEST_TIME"))) {
			ZEPHIR_OBS_NVAR(&_3$$5);
			zephir_array_fetch_string(&_3$$5, &_SERVER, SL("REQUEST_TIME"), PH_NOISY, "twinkle/log/request.zep", 38 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_3$$5);
			ZVAL_STRING(&_3$$5, "");
		}
		zephir_concat_self(&data, &_3$$5 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_4$$5);
		if (zephir_array_isset_string(&_SERVER, SL("HTTP_USER_AGENT"))) {
			ZEPHIR_OBS_NVAR(&_4$$5);
			zephir_array_fetch_string(&_4$$5, &_SERVER, SL("HTTP_USER_AGENT"), PH_NOISY, "twinkle/log/request.zep", 39 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "");
		}
		zephir_concat_self(&data, &_4$$5 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_5$$5);
		if (zephir_array_isset_string(&_SERVER, SL("LOCAL_ADDR"))) {
			ZEPHIR_OBS_NVAR(&_5$$5);
			zephir_array_fetch_string(&_5$$5, &_SERVER, SL("LOCAL_ADDR"), PH_NOISY, "twinkle/log/request.zep", 40 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "");
		}
		zephir_concat_self(&data, &_5$$5 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_6$$5);
		if (zephir_array_isset_string(&_SERVER, SL("LOCAL_PORT"))) {
			ZEPHIR_OBS_NVAR(&_6$$5);
			zephir_array_fetch_string(&_6$$5, &_SERVER, SL("LOCAL_PORT"), PH_NOISY, "twinkle/log/request.zep", 41 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_6$$5);
			ZVAL_STRING(&_6$$5, "");
		}
		zephir_concat_self(&data, &_6$$5 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_7$$5);
		if (zephir_array_isset_string(&_SERVER, SL("REMOTE_ADDR"))) {
			ZEPHIR_OBS_NVAR(&_7$$5);
			zephir_array_fetch_string(&_7$$5, &_SERVER, SL("REMOTE_ADDR"), PH_NOISY, "twinkle/log/request.zep", 42 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "");
		}
		zephir_concat_self(&data, &_7$$5 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_8$$5);
		if (zephir_array_isset_string(&_SERVER, SL("REMOTE_PORT"))) {
			ZEPHIR_OBS_NVAR(&_8$$5);
			zephir_array_fetch_string(&_8$$5, &_SERVER, SL("REMOTE_PORT"), PH_NOISY, "twinkle/log/request.zep", 43 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_8$$5);
			ZVAL_STRING(&_8$$5, "");
		}
		zephir_concat_self(&data, &_8$$5 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_2$$5);
		zephir_md5(&_2$$5, &data);
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "ripemd128");
		ZEPHIR_CALL_FUNCTION(&hash, "hash", NULL, 16, &_9$$5, &_2$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_10);
	zephir_fast_strtoupper(&_10, &hash);
	ZEPHIR_CPY_WRT(&hash, &_10);
	ZVAL_LONG(&_11, 0);
	ZVAL_LONG(&_12, 8);
	ZEPHIR_INIT_NVAR(&_10);
	zephir_substr(&_10, &hash, 0 , 8 , 0);
	ZVAL_LONG(&_13, 8);
	ZVAL_LONG(&_14, 4);
	ZEPHIR_INIT_VAR(&_15);
	zephir_substr(&_15, &hash, 8 , 4 , 0);
	ZVAL_LONG(&_16, 12);
	ZVAL_LONG(&_17, 4);
	ZEPHIR_INIT_VAR(&_18);
	zephir_substr(&_18, &hash, 12 , 4 , 0);
	ZVAL_LONG(&_19, 16);
	ZVAL_LONG(&_20, 4);
	ZEPHIR_INIT_VAR(&_21);
	zephir_substr(&_21, &hash, 16 , 4 , 0);
	ZEPHIR_INIT_VAR(&_22);
	ZEPHIR_CONCAT_VSVSVSVS(&_22, &_10, "-", &_15, "-", &_18, "-", &_21, "-");
	zend_update_static_property(twinkle_log_request_ce, ZEND_STRL("requestId"), &_22);
	zephir_read_static_property_ce(&_23, twinkle_log_request_ce, SL("requestId"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_23);

}

