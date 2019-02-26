
extern zend_class_entry *twinkle_log_drivers_file_ce;

ZEPHIR_INIT_CLASS(Twinkle_Log_Drivers_File);

PHP_METHOD(Twinkle_Log_Drivers_File, init);
PHP_METHOD(Twinkle_Log_Drivers_File, process);
PHP_METHOD(Twinkle_Log_Drivers_File, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_twinkle_log_drivers_file_init, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_twinkle_log_drivers_file_process, 0, 0, 4)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, level, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, level)
#endif
	ZEND_ARG_ARRAY_INFO(0, trace, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_twinkle_log_drivers_file_write, 0, 0, 1)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(twinkle_log_drivers_file_method_entry) {
	PHP_ME(Twinkle_Log_Drivers_File, init, arginfo_twinkle_log_drivers_file_init, ZEND_ACC_PUBLIC)
	PHP_ME(Twinkle_Log_Drivers_File, process, arginfo_twinkle_log_drivers_file_process, ZEND_ACC_PUBLIC)
	PHP_ME(Twinkle_Log_Drivers_File, write, arginfo_twinkle_log_drivers_file_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
