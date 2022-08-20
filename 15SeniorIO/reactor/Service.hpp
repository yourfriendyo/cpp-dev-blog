#pragma once
#include <vector>
#include "Reactor.hpp"
#include "Socket.hpp"
#include "Util.hpp"


int Recver(Event* evp)
{
    std::cout << "Recver Callback has been called!" << std::endl;

    //1. 读取
    int result = TcpSocket::Recv(evp->_fd, evp->_in_buffer);
    // 差错处理
    if (result < 0) {
        if (evp->_errorer)  evp->_errorer(evp);
        return -1;
    }

    //2. 分包 -- 只提取完整的报文，多余的放入缓冲区中
    //1+2X3+5X

    std::string sep = "X";
    std::vector<std::string> tokens;
    Util::SplitSegment(evp->_in_buffer, &tokens, sep);

    for (auto& seg : tokens)
    {
        //3. 反序列化
        std::string data1;
        std::string data2;

        if (Util::Deserialize(seg, &data1, &data2))
        {
            //4. 业务处理 -- 得到结果
            int x = atoi(data1.c_str());
            int y = atoi(data2.c_str());
            int z = x + y;
            //5. 构建响应 -- 结果放到out_buffer
            std::string res = data1 + "+" + data2 + "=" + std::to_string(z) + sep;
            evp->_out_buffer += res;
        }
    }
    //6. 尝试直接或间接发送
    //TODO

}

int Sender(Event* evp)
{
    std::cout << "Sender Callback has been called!" << std::endl;

}

int Errorer(Event* evp)
{
    std::cout << "Errorer Callback has been called!" << std::endl;

}
