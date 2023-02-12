#include <string>

class MyLogger
{
private:
    int logLevel = 0;
public:
    void printMessage(std::string msg, int logLevel);
};