#include "Logger.h"
#include <filesystem>
namespace utils {

Logger::Logger(const char* filePath, int line, Priority priority)
{
    std::string priorityName = GetPriorityName(priority);
    auto baseName = std::filesystem::path(filePath).filename();
    stream() << std::endl;
    stream() << priorityName << "/" << baseName << "(" << line << ")";
    stream() << " > ";
}
Logger::~Logger()
{

}
std::ostream& Logger::stream()
{
    return std::clog;
}

std::string Logger::GetPriorityName(Priority priority)
{
    std::string str;
    switch (priority) {
    case Priority::Debug:
        str = "D";
        break;
    case Priority::Info:
        str = "I";
        break;
    case Priority::Warn:
        str = "W";
        break;
    case Priority::Error:
        str = "E";
        break;
    }
    return str;
}

}