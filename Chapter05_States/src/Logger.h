#ifndef LOGGER_H
#define LOGGER_H
#include <string>

class Logger {
public:
    static void WriteLog(const std::string& logMessage);
private:
    Logger();
    ~Logger();
    Logger(const Logger&);
    Logger& operator=(const Logger&);
};

//#define LOGMSG(msg) do { std::cout <<__FILE__<<"("<<__LINE__<<"): "<<msg<<std::endl;} while(false)
#endif // LOGGER_H