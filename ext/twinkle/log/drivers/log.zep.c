
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * Created by PhpStorm.
 * User: xiehuanjin
 * Date: 2019/1/12
 * Time: 16:19
 */
ZEPHIR_INIT_CLASS(Twinkle_Log_Drivers_Log) {

	ZEPHIR_REGISTER_CLASS(Twinkle\\Log\\Drivers, Log, twinkle, log_drivers_log, twinkle_log_drivers_log_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_bool(twinkle_log_drivers_log_ce, SL("useBuffer"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(twinkle_log_drivers_log_ce, SL("logQueue"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_long(twinkle_log_drivers_log_ce, SL("bufferSize"), 100, ZEND_ACC_PUBLIC TSRMLS_CC);

	twinkle_log_drivers_log_ce->create_object = zephir_init_properties_Twinkle_Log_Drivers_Log;

	zend_class_implements(twinkle_log_drivers_log_ce TSRMLS_CC, 1, twinkle_log_storageinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Twinkle_Log_Drivers_Log, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config);

	if (!config) {
		config = &config_sub;
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, config);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Twinkle_Log_Drivers_Log, init) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, config_sub, r, ex, p, v, method, *_0, _3$$3, _5$$3, _7$$3, _8$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&r);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&p);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(&r);
	object_init_ex(&r, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &r, "__construct", NULL, 1, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&ex, this_ptr, "getexcludeinitproperty", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(config, 0, "twinkle/log/drivers/log.zep", 44);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(config), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&p);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&p, _2);
		} else {
			ZVAL_LONG(&p, _1);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _0);
		if (zephir_fast_in_array(&p, &ex TSRMLS_CC)) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&_3$$3, &r, "getproperty", &_4, 2, &p);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$3, &_3$$3, "ispublic", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$3)) {
			zephir_update_property_zval_zval(this_ptr, &p, &v TSRMLS_CC);
			continue;
		}
		ZEPHIR_CALL_METHOD(&method, this_ptr, "hasset", &_6, 0, &p);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&method)) {
			ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &method, NULL, 0, &p, &v);
			zephir_check_call_status();
			continue;
		}
		ZEPHIR_INIT_NVAR(&_7$$3);
		object_init_ex(&_7$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_LNVAR(_8$$3);
		ZEPHIR_CONCAT_SVS(&_8$$3, "Property `", &p, "` not exists");
		ZEPHIR_CALL_METHOD(NULL, &_7$$3, "__construct", &_9, 3, &_8$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$3, "twinkle/log/drivers/log.zep", 42 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&p);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Twinkle_Log_Drivers_Log, hasSet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, method, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);

	ZEPHIR_SEPARATE_PARAM(key);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, twinkle_0__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/([-_]+([a-z]{1}))/i");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace_callback", NULL, 4, &_1, &_0, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(key, &_2);
	ZEPHIR_INIT_VAR(&method);
	ZVAL_STRING(&method, "set{key}");
	if ((zephir_method_exists(this_ptr, &method TSRMLS_CC)  == SUCCESS)) {
		RETURN_CCTOR(&method);
	}
	RETURN_MM_BOOL(0);

}

/**
 * 非构函数传入的参数
 * @return array
 */
PHP_METHOD(Twinkle_Log_Drivers_Log, getExcludeInitProperty) {

	zval tmpArray40cd750bba9870f18aada2478b24840a;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmpArray40cd750bba9870f18aada2478b24840a);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&tmpArray40cd750bba9870f18aada2478b24840a);
	array_init(&tmpArray40cd750bba9870f18aada2478b24840a);
	RETURN_CCTOR(&tmpArray40cd750bba9870f18aada2478b24840a);

}

PHP_METHOD(Twinkle_Log_Drivers_Log, flushLogs) {

	zval content, line, _0, _1$$3, *_2$$3, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("logQueue"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_STRING(&content, "");
		zephir_read_property(&_1$$3, this_ptr, SL("logQueue"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "twinkle/log/drivers/log.zep", 81);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1$$3), _2$$3)
		{
			ZEPHIR_INIT_NVAR(&line);
			ZVAL_COPY(&line, _2$$3);
			zephir_concat_self(&content, &line TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&line);
		ZEPHIR_INIT_VAR(&_3$$3);
		array_init(&_3$$3);
		zephir_update_property_zval(this_ptr, SL("logQueue"), &_3$$3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &content);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Twinkle_Log_Drivers_Log(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("logQueue"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("logQueue"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

