#include <iostream>
#include "MyLogger.h"

int main(int argc, char *argv[])
{
    MyLogger logger;

    logger.printMessage("One more message", 0);
    std::cout << "Hello CMake" << std::endl;
    return 0;
}