/**
 * Created by PhpStorm.
 * User: xiehuanjin
 * Date: 2019/1/12
 * Time: 16:09
 */
namespace Twinkle\Log;

interface StorageInterface
{
    /**
     * @desc  调度方法
     * @param string $level 日志级别
     * @param array $trace 日志发生位置
     * @param string $message 日志信息
     * @param array $context 日志额外信息
     * @return mixed
     */
    public function process(string level, array trace, string message, array context);
    
    /**
     * @desc  日志写入方法
     * @param string $log 日志信息
     * @return mixed
     */
    public function write(string log);
    
    public function flushLogs() -> void;

}