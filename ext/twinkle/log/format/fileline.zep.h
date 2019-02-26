
extern zend_class_entry *twinkle_log_format_fileline_ce;

ZEPHIR_INIT_CLASS(Twinkle_Log_Format_FileLine);

PHP_METHOD(Twinkle_Log_Format_FileLine, format);
PHP_METHOD(Twinkle_Log_Format_FileLine, __toString);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_twinkle_log_format_fileline_format, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_twinkle_log_format_fileline_format, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(twinkle_log_format_fileline_method_entry) {
	PHP_ME(Twinkle_Log_Format_FileLine, format, arginfo_twinkle_log_format_fileline_format, ZEND_ACC_PUBLIC)
	PHP_ME(Twinkle_Log_Format_FileLine, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
