#include "MyLogger.h"
#include <iostream>

void MyLogger::printMessage(std::string msg, int logLevel)
{
    if (this->logLevel == logLevel)
    {
        std::cout << msg << std::endl;
    }
}
