#include "Application.h"
#include <stdexcept>
#include "Logger.h"
int main()
{
    try {
        Application app;
        app.Run();
    } catch(std::exception& e) {
        LOG(ERROR) << "Exception: " << e.what();
    }
    return 0;
}