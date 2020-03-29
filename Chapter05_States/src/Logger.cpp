#include "Logger.h"
#include <iostream>

void Logger::WriteLog(const std::string& logMessage)
{
    std::cout << logMessage << std::endl;
}