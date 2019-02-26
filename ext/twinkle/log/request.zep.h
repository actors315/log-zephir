
extern zend_class_entry *twinkle_log_request_ce;

ZEPHIR_INIT_CLASS(Twinkle_Log_Request);

PHP_METHOD(Twinkle_Log_Request, __construct);
PHP_METHOD(Twinkle_Log_Request, singleton);
PHP_METHOD(Twinkle_Log_Request, getRequestId);

ZEPHIR_INIT_FUNCS(twinkle_log_request_method_entry) {
	PHP_ME(Twinkle_Log_Request, __construct, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_CTOR)
	PHP_ME(Twinkle_Log_Request, singleton, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Twinkle_Log_Request, getRequestId, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
