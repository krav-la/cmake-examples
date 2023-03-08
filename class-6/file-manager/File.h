#if !defined(FILE_H)
#define FILE_H

#include <string>

class File
{
private:
    std::string mFileName;
    int mFd;
public:
    File() = default;
    File(std::string fileName, int fd);
    void setFileName(std::string name);
    std::string getFileName();
    void setFd(int id);
    int getFd();
};


#endif // FILE_H