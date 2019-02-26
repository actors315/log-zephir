
extern zend_class_entry *twinkle_log_drivers_log_ce;

ZEPHIR_INIT_CLASS(Twinkle_Log_Drivers_Log);

PHP_METHOD(Twinkle_Log_Drivers_Log, __construct);
PHP_METHOD(Twinkle_Log_Drivers_Log, init);
PHP_METHOD(Twinkle_Log_Drivers_Log, hasSet);
PHP_METHOD(Twinkle_Log_Drivers_Log, getExcludeInitProperty);
PHP_METHOD(Twinkle_Log_Drivers_Log, flushLogs);
zend_object *zephir_init_properties_Twinkle_Log_Drivers_Log(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_twinkle_log_drivers_log___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_twinkle_log_drivers_log_init, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_twinkle_log_drivers_log_hasset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_twinkle_log_drivers_log_getexcludeinitproperty, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_twinkle_log_drivers_log_getexcludeinitproperty, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(twinkle_log_drivers_log_method_entry) {
	PHP_ME(Twinkle_Log_Drivers_Log, __construct, arginfo_twinkle_log_drivers_log___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Twinkle_Log_Drivers_Log, init, arginfo_twinkle_log_drivers_log_init, ZEND_ACC_PUBLIC)
	PHP_ME(Twinkle_Log_Drivers_Log, hasSet, arginfo_twinkle_log_drivers_log_hasset, ZEND_ACC_PROTECTED)
	PHP_ME(Twinkle_Log_Drivers_Log, getExcludeInitProperty, arginfo_twinkle_log_drivers_log_getexcludeinitproperty, ZEND_ACC_PROTECTED)
	PHP_ME(Twinkle_Log_Drivers_Log, flushLogs, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
