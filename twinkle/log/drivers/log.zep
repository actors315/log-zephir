/**
 * Created by PhpStorm.
 * User: xiehuanjin
 * Date: 2019/1/12
 * Time: 16:19
 */
namespace Twinkle\Log\Drivers;

use Twinkle\Log\StorageInterface;
abstract class Log implements StorageInterface
{
    //是否批量写入
    public useBuffer = false;
    //缓冲数组
    public logQueue = [];
    //缓冲日志记录条数大小
    public bufferSize = 100;
    public function __construct(config = []) -> void
    {
        this->init(config);
    }
    
    public function init(config) -> void
    {
        var r, ex, p, v, method;
    
        let r =  new \ReflectionClass(this);
        let ex =  this->getExcludeInitProperty();
        for p, v in config {
            if in_array(p, ex) {
                continue;
            }
            if r->getProperty(p)->isPublic() {
                let this->{p} = v;
                continue;
            }
            let method =  this->hasSet(p);
            if method !== false {
                this->{method}(p, v);
                continue;
            }
            throw new \Exception("Property `" . p . "` not exists");
        }
    }
    
    protected function hasSet(key)
    {
        var method;
    
        let key =  preg_replace_callback("/([-_]+([a-z]{1}))/i", function ($matches) {
            return strtoupper(matches[2]);
        }, key);
        let method = "set{key}";
        if method_exists(this, method) {
            return method;
        }
        return false;
    }
    
    /**
     * 非构函数传入的参数
     * @return array
     */
    protected function getExcludeInitProperty() -> array
    {
        var tmpArray40cd750bba9870f18aada2478b24840a;
    
        let tmpArray40cd750bba9870f18aada2478b24840a = [];
        return tmpArray40cd750bba9870f18aada2478b24840a;
    }
    
    public function flushLogs() -> void
    {
        var content, line;
    
        if count(this->logQueue) {
            let content = "";
            for line in this->logQueue {
                let content .= line;
            }
            let this->logQueue =  [];
            this->write(content);
        }
    }

}