#include <iostream>
#include "File.h"

int main(int argc, char const *argv[])
{
    File file("file/path", 1);
    file.setFd(2);
    std::cout << file.getFd() << std::endl;

    return 0;
}
