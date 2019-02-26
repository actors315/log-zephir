
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(twinkle_0__closure) {

	ZEPHIR_REGISTER_CLASS(twinkle, 0__closure, twinkle, 0__closure, twinkle_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(twinkle_0__closure, __invoke) {

	zval *matches, matches_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matches_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &matches);



	zephir_array_fetch_long(&_0, matches, 2, PH_NOISY | PH_READONLY, "twinkle/log/drivers/log.zep", 51 TSRMLS_CC);
	zephir_fast_strtoupper(return_value, &_0);
	return;

}

