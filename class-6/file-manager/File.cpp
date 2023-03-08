#include "File.h"

File::File(std::string fileName, int fd) : 
    mFileName(fileName), 
    mFd(fd)
{

}

void File::setFileName(std::string name)
{
    mFileName = name;
}
std::string File::getFileName()
{
    return mFileName;
}
void File::setFd(int fd)
{
    mFd = fd;
}
int File::getFd()
{
    return mFd;
}
