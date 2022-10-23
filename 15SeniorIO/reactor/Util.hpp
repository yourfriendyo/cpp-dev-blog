#pragma once
#include <iostream>
#include <vector>
#include <string>
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

    // 1+2X2+3X4+6X
    // 1+2X3+
    // 1+
    static void SplitSegment(std::string& in_buffer, std::vector<std::string>* tokens, std::string sep)
    {
        std::cout << "in_buffer:" << in_buffer << std::endl;
        while (true)
        {
            auto pos = in_buffer.find(sep);
            if (pos == std::string::npos) { // 没找到直接退出
                break;
            }
            std::string sub = in_buffer.substr(0, pos); //[,)
            tokens->push_back(sub);
            in_buffer.erase(0, pos + sep.size());
        }
    }

    //1+2
    static bool Deserialize(std::string& seg, std::string* out1, std::string* out2)
    {
        std::string op = "+";
        auto pos = seg.find(op);

        if (pos == std::string::npos)
            return false;

        *out1 = seg.substr(0, pos);
        *out2 = seg.substr(pos + op.size());
        return true;
    }
};