#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <iostream>

namespace utils {

class Logger {
public:
    enum class Priority {
        Debug,
        Info,
        Warn,
        Error
    };

public:
    Logger(const char* filePath, int line, Priority priority);
    ~Logger();
    std::ostream& stream();
private:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
private:
    std::string GetPriorityName(Priority priority);
};

}

#define COMPACT_LOG_INFO utils::Logger(__FILE__, __LINE__, utils::Logger::Priority::Info)
#define COMPACT_LOG_DEBUG utils::Logger(__FILE__, __LINE__, utils::Logger::Priority::Debug)
#define COMPACT_LOG_WARN utils::Logger(__FILE__, __LINE__, utils::Logger::Priority::Warn)
#define COMPACT_LOG_ERROR utils::Logger(__FILE__, __LINE__, utils::Logger::Priority::Error)

#define LOG(severity) COMPACT_LOG_ ## severity.stream()

#endif // LOGGER_H