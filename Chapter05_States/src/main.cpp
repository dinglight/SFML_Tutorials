#include "Application.h"
#include <stdexcept>
#include "Logger.h"
int main()
{
    try {
        Application app;
        app.Run();
    } catch(std::exception& e) {
        Logger::WriteLog(std::string("Exception: ") + e.what());
    }
    return 0;
}