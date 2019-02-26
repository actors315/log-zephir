/**
 * Created by PhpStorm.
 * User: xiehuanjin
 * Date: 2019/1/12
 * Time: 16:09
 */
namespace Twinkle\Log;

use Psr\Log\AbstractLogger;
use Psr\Log\LoggerTrait;
class Logger extends AbstractLogger
{
    protected logger;
    
    public function __construct(<StorageInterface> storage) -> void
    {
        let this->logger = storage;
    }
    
    public function log(level, message, array context = []) -> void
    {
        var trace;
    
        if isset context["trace"] {
            let trace = context["trace"];
            unset context["trace"];
        } else {
            let trace =  debug_backtrace(DEBUG_BACKTRACE_IGNORE_ARGS, 2);
        }
        let trace =  !(empty(trace)) ? trace[1]  : [];
        this->logger->process(level, trace, message, context);
    }
    
    public function __destruct() -> void
    {
        this->logger->flushLogs();
    }

}