
extern zend_class_entry *twinkle_log_format_base_ce;

ZEPHIR_INIT_CLASS(Twinkle_Log_Format_Base);

PHP_METHOD(Twinkle_Log_Format_Base, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_twinkle_log_format_base___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, createTime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(twinkle_log_format_base_method_entry) {
	PHP_ME(Twinkle_Log_Format_Base, __construct, arginfo_twinkle_log_format_base___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
