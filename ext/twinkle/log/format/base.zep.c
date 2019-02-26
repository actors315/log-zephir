
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * Created by PhpStorm.
 * User: xiehuanjin
 * Date: 2019/1/12
 * Time: 16:41
 */
ZEPHIR_INIT_CLASS(Twinkle_Log_Format_Base) {

	ZEPHIR_REGISTER_CLASS(Twinkle\\Log\\Format, Base, twinkle, log_format_base, twinkle_log_format_base_method_entry, 0);

	zend_declare_property_null(twinkle_log_format_base_ce, SL("content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(twinkle_log_format_base_ce, SL("createTime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(twinkle_log_format_base_ce, SL("level"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(twinkle_log_format_base_ce, SL("message"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(twinkle_log_format_base_ce, SL("location"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(twinkle_log_format_base_ce, SL("requestId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Twinkle_Log_Format_Base, __construct) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, *location, location_sub, *level, level_sub, *content = NULL, content_sub, *createTime = NULL, createTime_sub, __$null, _0, _1, _2, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&location_sub);
	ZVAL_UNDEF(&level_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&createTime_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &message, &location, &level, &content, &createTime);

	if (!content) {
		content = &content_sub;
		ZEPHIR_INIT_VAR(content);
		ZVAL_STRING(content, "");
	}
	if (!createTime) {
		createTime = &createTime_sub;
		createTime = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("content"), content);
	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(createTime) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_STRING(&_1, "Y-m-d H:i:s");
		ZEPHIR_CALL_FUNCTION(&_0, "date", NULL, 5, &_1);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&_0, createTime);
	}
	zephir_update_property_zval(this_ptr, SL("createTime"), &_0);
	zephir_update_property_zval(this_ptr, SL("level"), level);
	zephir_update_property_zval(this_ptr, SL("message"), message);
	zephir_update_property_zval(this_ptr, SL("location"), location);
	ZEPHIR_CALL_CE_STATIC(&_2, twinkle_log_request_ce, "singleton", &_3, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &_2, "getrequestid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("requestId"), &_4);
	ZEPHIR_MM_RESTORE();

}

