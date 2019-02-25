
extern zend_class_entry *twinkle_log_logger_ce;

ZEPHIR_INIT_CLASS(Twinkle_Log_Logger);

PHP_METHOD(Twinkle_Log_Logger, __construct);
PHP_METHOD(Twinkle_Log_Logger, log);
PHP_METHOD(Twinkle_Log_Logger, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_twinkle_log_logger___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, storage, Twinkle\\Log\\StorageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_twinkle_log_logger_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(twinkle_log_logger_method_entry) {
	PHP_ME(Twinkle_Log_Logger, __construct, arginfo_twinkle_log_logger___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Twinkle_Log_Logger, log, arginfo_twinkle_log_logger_log, ZEND_ACC_PUBLIC)
	PHP_ME(Twinkle_Log_Logger, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};
