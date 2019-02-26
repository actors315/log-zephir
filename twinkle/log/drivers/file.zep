/**
 * Created by PhpStorm.
 * User: xiehuanjin
 * Date: 2019/1/12
 * Time: 16:19
 */
namespace Twinkle\Log\Drivers;

use Twinkle\Log\Format\FileLine;
class File extends Log
{
    const ROTATE_HOUR = "hour";
    const ROTATE_DAY = "day";
    const ROTATE_MONTH = "month";
    const ROTATE_YEAR = "year";
    public logFile = "error.log";
    public logPath = ".";
    public rotate = self::ROTATE_DAY;
    public function init(config) -> void
    {
        var prefix, path;

        var rotateMap = [self::ROTATE_HOUR : ["Y/m/d", "H_"], self::ROTATE_DAY : "Y/m/d", self::ROTATE_MONTH : "Y/m", self::ROTATE_YEAR : "Y"];
    
        parent::init(config);
        let prefix = "";
        if isset rotateMap[this->rotate] {
            if is_array(rotateMap[this->rotate]) {
                let prefix =  date(rotateMap[this->rotate][1]);
                let path =  date(rotateMap[this->rotate][0]);
            } else {
                let path =  date(rotateMap[this->rotate]);
            }
            let this->logPath =  this->logPath . DIRECTORY_SEPARATOR . str_replace("/", DIRECTORY_SEPARATOR, path);
        }
        if !(is_dir(this->logPath)) {
            mkdir(this->logPath, 511, true);
        }
        let this->logFile =  this->logPath . DIRECTORY_SEPARATOR . prefix . this->logFile;
    }
    
    public function process(string level, array trace, string message, array context) -> void
    {
        var log;
    
        let log =  new FileLine(message, trace, level, context);
        if this->useBuffer {
            let this->logQueue[] =  log->format();
            if count(this->logQueue) >= this->bufferSize {
                this->flushLogs();
            }
        } else {
            this->write(log);
        }
    }
    
    public function write(line)
    {
        return file_put_contents(this->logFile, line, FILE_APPEND);
    }

}