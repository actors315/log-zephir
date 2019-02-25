
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Created by PhpStorm.
 * User: xiehuanjin
 * Date: 2019/1/12
 * Time: 16:09
 */
ZEPHIR_INIT_CLASS(Twinkle_Log_StorageInterface) {

	ZEPHIR_REGISTER_INTERFACE(Twinkle\\Log, StorageInterface, twinkle, log_storageinterface, twinkle_log_storageinterface_method_entry);

	return SUCCESS;

}

/**
 * @desc  调度方法
 * @param string $level 日志级别
 * @param array $trace 日志发生位置
 * @param string $message 日志信息
 * @param array $context 日志额外信息
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Twinkle_Log_StorageInterface, process);

/**
 * @desc  日志写入方法
 * @param string $log 日志信息
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Twinkle_Log_StorageInterface, write);

ZEPHIR_DOC_METHOD(Twinkle_Log_StorageInterface, flushLogs);

