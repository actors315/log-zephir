
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/fcall.h"


/**
 * Created by PhpStorm.
 * User: xiehuanjin
 * Date: 2019/1/12
 * Time: 16:41
 */
ZEPHIR_INIT_CLASS(Twinkle_Log_Format_FileLine) {

	ZEPHIR_REGISTER_CLASS_EX(Twinkle\\Log\\Format, FileLine, twinkle, log_format_fileline, twinkle_log_format_base_ce, twinkle_log_format_fileline_method_entry, 0);

	return SUCCESS;

}

/**
 * 格式化日志
 * @return string
 */
PHP_METHOD(Twinkle_Log_Format_FileLine, format) {

	zval data, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 6, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("requestId"), PH_NOISY_CC);
	zephir_array_fast_append(&data, &_0);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("createTime"), PH_NOISY_CC);
	zephir_array_fast_append(&data, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("location"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "");
	} else {
		zephir_read_property(&_2, this_ptr, SL("location"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_3, &_2, SL("file"), PH_NOISY | PH_READONLY, "twinkle/log/format/fileline.zep", 22 TSRMLS_CC);
		zephir_read_property(&_4, this_ptr, SL("location"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_5, &_4, SL("line"), PH_NOISY | PH_READONLY, "twinkle/log/format/fileline.zep", 22 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_1);
		ZEPHIR_CONCAT_SVSVS(&_1, "file[", &_3, "]  line[", &_5, "]");
	}
	zephir_array_fast_append(&data, &_1);
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_property(&_6, this_ptr, SL("level"), PH_NOISY_CC);
	zephir_array_fast_append(&data, &_6);
	ZEPHIR_OBS_NVAR(&_6);
	zephir_read_property(&_6, this_ptr, SL("message"), PH_NOISY_CC);
	zephir_array_fast_append(&data, &_6);
	ZEPHIR_INIT_VAR(&_7);
	zephir_read_property(&_8, this_ptr, SL("content"), PH_NOISY_CC | PH_READONLY);
	zephir_json_encode(&_7, &_8, 0 );
	zephir_array_fast_append(&data, &_7);
	ZEPHIR_INIT_NVAR(&_7);
	ZEPHIR_GET_CONSTANT(&_7, "PHP_EOL");
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SV(&_1, "[%s] [%s] %s [%s] %s %s", &_7);
	ZEPHIR_RETURN_CALL_FUNCTION("vsprintf", NULL, 12, &_1, &data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Twinkle_Log_Format_FileLine, __toString) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "format", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

