
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"


/**
 * Created by PhpStorm.
 * User: xiehuanjin
 * Date: 2019/1/12
 * Time: 16:19
 */
ZEPHIR_INIT_CLASS(Twinkle_Log_Drivers_File) {

	ZEPHIR_REGISTER_CLASS_EX(Twinkle\\Log\\Drivers, File, twinkle, log_drivers_file, twinkle_log_drivers_log_ce, twinkle_log_drivers_file_method_entry, 0);

	zend_declare_property_string(twinkle_log_drivers_file_ce, SL("logFile"), "error.log", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(twinkle_log_drivers_file_ce, SL("logPath"), ".", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(twinkle_log_drivers_file_ce, SL("rotate"), "day", ZEND_ACC_PUBLIC TSRMLS_CC);

	zephir_declare_class_constant_string(twinkle_log_drivers_file_ce, SL("ROTATE_HOUR"), "hour");

	zephir_declare_class_constant_string(twinkle_log_drivers_file_ce, SL("ROTATE_DAY"), "day");

	zephir_declare_class_constant_string(twinkle_log_drivers_file_ce, SL("ROTATE_MONTH"), "month");

	zephir_declare_class_constant_string(twinkle_log_drivers_file_ce, SL("ROTATE_YEAR"), "year");

	return SUCCESS;

}

PHP_METHOD(Twinkle_Log_Drivers_File, init) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_9 = NULL;
	zval *config, config_sub, __$true, prefix, path, rotateMap, _1, _3, _20, _21, _24, _25, _26, _4$$3, _5$$3, _15$$3, _16$$3, _17$$3, _18$$3, _19$$3, _6$$4, _7$$4, _8$$4, _10$$4, _11$$4, _12$$4, _13$$5, _14$$5, _22$$6, _23$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&rotateMap);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(&rotateMap);
	zephir_create_array(&rotateMap, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Y/m/d");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "H_");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&rotateMap, SL("hour"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&rotateMap, SL("day"), SL("Y/m/d"));
	add_assoc_stringl_ex(&rotateMap, SL("month"), SL("Y/m"));
	add_assoc_stringl_ex(&rotateMap, SL("year"), SL("Y"));
	ZEPHIR_CALL_PARENT(NULL, twinkle_log_drivers_file_ce, getThis(), "init", &_2, 0, config);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&prefix);
	ZVAL_STRING(&prefix, "");
	zephir_read_property(&_3, this_ptr, SL("rotate"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&rotateMap, &_3)) {
		ZEPHIR_OBS_VAR(&_5$$3);
		zephir_read_property(&_5$$3, this_ptr, SL("rotate"), PH_NOISY_CC);
		zephir_array_fetch(&_4$$3, &rotateMap, &_5$$3, PH_NOISY | PH_READONLY, "twinkle/log/drivers/file.zep", 28 TSRMLS_CC);
		if (Z_TYPE_P(&_4$$3) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(&_7$$4);
			zephir_read_property(&_7$$4, this_ptr, SL("rotate"), PH_NOISY_CC);
			zephir_array_fetch(&_6$$4, &rotateMap, &_7$$4, PH_NOISY | PH_READONLY, "twinkle/log/drivers/file.zep", 29 TSRMLS_CC);
			zephir_array_fetch_long(&_8$$4, &_6$$4, 1, PH_NOISY | PH_READONLY, "twinkle/log/drivers/file.zep", 29 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&prefix, "date", &_9, 5, &_8$$4);
			zephir_check_call_status();
			ZEPHIR_OBS_VAR(&_11$$4);
			zephir_read_property(&_11$$4, this_ptr, SL("rotate"), PH_NOISY_CC);
			zephir_array_fetch(&_10$$4, &rotateMap, &_11$$4, PH_NOISY | PH_READONLY, "twinkle/log/drivers/file.zep", 30 TSRMLS_CC);
			zephir_array_fetch_long(&_12$$4, &_10$$4, 0, PH_NOISY | PH_READONLY, "twinkle/log/drivers/file.zep", 30 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&path, "date", &_9, 5, &_12$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_VAR(&_14$$5);
			zephir_read_property(&_14$$5, this_ptr, SL("rotate"), PH_NOISY_CC);
			zephir_array_fetch(&_13$$5, &rotateMap, &_14$$5, PH_NOISY | PH_READONLY, "twinkle/log/drivers/file.zep", 32 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&path, "date", &_9, 5, &_13$$5);
			zephir_check_call_status();
		}
		zephir_read_property(&_15$$3, this_ptr, SL("logPath"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_16$$3);
		ZEPHIR_INIT_VAR(&_17$$3);
		ZVAL_STRING(&_17$$3, "/");
		ZEPHIR_INIT_VAR(&_18$$3);
		ZVAL_STRING(&_18$$3, "/");
		zephir_fast_str_replace(&_16$$3, &_17$$3, &_18$$3, &path TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_19$$3);
		ZEPHIR_CONCAT_VSV(&_19$$3, &_15$$3, "/", &_16$$3);
		zephir_update_property_zval(this_ptr, SL("logPath"), &_19$$3);
	}
	zephir_read_property(&_20, this_ptr, SL("logPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_21, "is_dir", NULL, 7, &_20);
	zephir_check_call_status();
	if (!(zephir_is_true(&_21))) {
		zephir_read_property(&_22$$6, this_ptr, SL("logPath"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_23$$6, 0766);
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 8, &_22$$6, &_23$$6, &__$true);
		zephir_check_call_status();
	}
	zephir_read_property(&_24, this_ptr, SL("logPath"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_25, this_ptr, SL("logFile"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_26);
	ZEPHIR_CONCAT_VSVV(&_26, &_24, "/", &prefix, &_25);
	zephir_update_property_zval(this_ptr, SL("logFile"), &_26);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Twinkle_Log_Drivers_File, process) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval trace, context;
	zval *level_param = NULL, *trace_param = NULL, *message_param = NULL, *context_param = NULL, log, _0, _1$$3, _2$$3, _3$$3;
	zval level, message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&log);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &level_param, &trace_param, &message_param, &context_param);

	zephir_get_strval(&level, level_param);
	zephir_get_arrval(&trace, trace_param);
	zephir_get_strval(&message, message_param);
	zephir_get_arrval(&context, context_param);


	ZEPHIR_INIT_VAR(&log);
	object_init_ex(&log, twinkle_log_format_fileline_ce);
	ZEPHIR_CALL_METHOD(NULL, &log, "__construct", NULL, 9, &message, &trace, &level, &context);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("useBuffer"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$3, &log, "format", NULL, 10);
		zephir_check_call_status();
		zephir_update_property_array_append(this_ptr, SL("logQueue"), &_1$$3 TSRMLS_CC);
		zephir_read_property(&_2$$3, this_ptr, SL("logQueue"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_3$$3, this_ptr, SL("bufferSize"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_LE_LONG(&_3$$3, zephir_fast_count_int(&_2$$3 TSRMLS_CC))) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "flushlogs", NULL, 0);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &log);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Twinkle_Log_Drivers_File, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *line, line_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &line);



	zephir_read_property(&_0, this_ptr, SL("logFile"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 8);
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 11, &_0, line, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

