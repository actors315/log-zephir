/**
 * Created by PhpStorm.
 * User: xiehuanjin
 * Date: 2019/1/12
 * Time: 17:13
 */
namespace Twinkle\Log;

class Request
{
    protected static instance = null;

    protected static requestId = null;

    protected function __construct() -> void
    {
    }
    
    public static function singleton()
    {
        if self::instance == null {
            let self::instance =  new self();
        }
        return self::instance;
    }
    
    public function getRequestId()
    {
        if !(empty(this->requestId)) {
            return this->requestId;
        }
        if function_exists("session_create_id") {
            let hash =  session_create_id();
        } else {
            let data =  uniqid("", true);
            let data .=  isset _SERVER["REQUEST_TIME"] ? _SERVER["REQUEST_TIME"]  : "";
            let data .=  isset _SERVER["HTTP_USER_AGENT"] ? _SERVER["HTTP_USER_AGENT"]  : "";
            let data .=  isset _SERVER["LOCAL_ADDR"] ? _SERVER["LOCAL_ADDR"]  : "";
            let data .=  isset _SERVER["LOCAL_PORT"] ? _SERVER["LOCAL_PORT"]  : "";
            let data .=  isset _SERVER["REMOTE_ADDR"] ? _SERVER["REMOTE_ADDR"]  : "";
            let data .=  isset _SERVER["REMOTE_PORT"] ? _SERVER["REMOTE_PORT"]  : "";
            let hash =  hash("ripemd128", md5(data));
        }
        let hash =  strtoupper(hash);
        let this->requestId =  substr(hash, 0, 8) . "-" . substr(hash, 8, 4) . "-" . substr(hash, 12, 4) . "-" . substr(hash, 16, 4) . "-";
        return this->requestId;
    }

}