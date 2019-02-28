/**
 * Created by PhpStorm.
 * User: xiehuanjin
 * Date: 2019/1/12
 * Time: 16:41
 */
namespace Twinkle\Log\Format;

class FileLine extends Base
{
    /**
     * 格式化日志
     * @return string
     */
    public function format() -> string
    {
        var data;
    
        let data = [
            this->requestId,
            this->createTime,
            empty(this->location) ? ""  : "file[".this->location["file"]."]  line[".this->location["line"]."]",
            this->level,
            this->message,
            json_encode(this->content)
        ];
        return vsprintf("[%s] [%s] %s [%s] %s %s" . PHP_EOL, data);
    }
    
    public function __toString()
    {
        return this->format();
    }

}