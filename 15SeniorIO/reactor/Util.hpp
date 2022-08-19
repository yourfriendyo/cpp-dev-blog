#pragma once
#include <iostream>
#include <unistd.h>
#include <fcntl.h>

//工具类

class Util
{
public:
    static void SetNoBlock(int fd)
    {
        int fl = fcntl(fd, F_GETFL);
        if (fl < 0) {
            std::cerr << "fcntl failed" << std::endl;
            return;
        }
        fcntl(fd, F_SETFL, fl | O_NONBLOCK);

    }
};