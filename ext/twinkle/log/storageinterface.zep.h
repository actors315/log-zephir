
extern zend_class_entry *twinkle_log_storageinterface_ce;

ZEPHIR_INIT_CLASS(Twinkle_Log_StorageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_twinkle_log_storageinterface_process, 0, 0, 4)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_twinkle_log_storageinterface_write, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, log, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, log)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(twinkle_log_storageinterface_method_entry) {
	PHP_ABSTRACT_ME(Twinkle_Log_StorageInterface, process, arginfo_twinkle_log_storageinterface_process)
	PHP_ABSTRACT_ME(Twinkle_Log_StorageInterface, write, arginfo_twinkle_log_storageinterface_write)
	PHP_ABSTRACT_ME(Twinkle_Log_StorageInterface, flushLogs, NULL)
	PHP_FE_END
};
