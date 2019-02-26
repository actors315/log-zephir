/**
 * Created by PhpStorm.
 * User: xiehuanjin
 * Date: 2019/1/12
 * Time: 16:41
 */
namespace Twinkle\Log\Format;

use Twinkle\Log\Request;
class Base
{
    // 额外信息
    protected content;
    // 创建时间
    protected createTime;
    // 日志级别
    protected level;
    // 日志信息
    protected message;
    // 位置
    protected location;
    // 请求标识
    protected requestId;
    public function __construct(message, location, level, content = "", createTime = null) -> void
    {
        let this->content = content;
        let this->createTime =  createTime === null ? date("Y-m-d H:i:s")  : createTime;
        let this->level = level;
        let this->message = message;
        let this->location = location;
        let this->requestId =  Request::singleton()->getRequestId();
    }

}