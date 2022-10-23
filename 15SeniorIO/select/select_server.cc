#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <sys/select.h>
#include <sys/types.h>
#include "Socket.hpp"

using namespace NSTcpSocket;

static void Usage(std::string proc) {
    std::cout << "Usage: \n\t" << proc << " port" << std::endl;
    exit(1);
}

std::vector<int> fd_v;
inline int GetMaxFd() {
    int max = 0;
    for (auto e : fd_v) {
        if (max < e) {
            max = e;
        }
    }
    return max;
}
int GetIndex(int key) {
    auto pos = std::find(fd_v.begin(), fd_v.end(), key);
    if (pos != fd_v.end()) {
        return pos - fd_v.begin();
    }
    else {
        return -1;
    }
}

// ./select_server 8080
int main(int argc, char* argv[])
{
    if (argc != 2) {
        Usage(argv[0]);
    }
    uint16_t port = atoi(argv[1]);

    int listen_sock = TcpSocket::Socket();
    TcpSocket::Bind(listen_sock, port);
    TcpSocket::Listen(listen_sock);
    //先交给select等待，事件就绪后才能accept

    fd_v.push_back(listen_sock);
    //事件循环
    for (;;)
    {
        fd_set read_fds;
        FD_ZERO(&read_fds); // 清空fd集

        for (auto e : fd_v) {
            if (e != -1) {
                FD_SET(e, &read_fds); // 数组内容设置进fd集
            }
        }

        struct timeval timeout = { 5, 0 };

        switch (select(GetMaxFd() + 1, &read_fds, nullptr, nullptr, nullptr))
        {
        case 0:
            std::cout << "select timeout" << std::endl;
            break;
        case -1:
            std::cerr << "select failed" << std::endl;
            break;
        default:
            std::cout << "select get fds readly" << std::endl;
            for (auto& fd : fd_v)
            {
                if (fd != -1) // 首先排除非法fd
                {
                    if (FD_ISSET(fd, &read_fds)) // 读事件就绪
                    {
                        std::cout << "sock: " << fd << " 读事件就绪" << std::endl;
                        if (fd == listen_sock) // 监听读事件就绪
                        {
                            int sock = TcpSocket::Accept(fd);
                            std::cout << "事件为建立新链接: " << sock << std::endl;
                            if (sock >= 0)
                            {
                                //push到数组中，以待交给select等待
                                int pos = 1;
                                for (; pos < fd_v.size(); pos++) { // 查找可用位置
                                    if (fd_v[pos] == -1) {
                                        break;
                                    }
                                }
                                if (pos < fd_v.size()) {
                                    fd_v[pos] = sock; // 提取连接到来不代表读事件就绪
                                }
                                else {
                                    fd_v.push_back(sock);
                                }
                                std::cout << "新连接被添加在数组位置[" << pos << "]" << std::endl;
                            }
                            else {
                                close(fd);
                            }
                        }
                        else // 普通读事件就绪
                        {
                            std::cout << "事件为普通读取事件" << std::endl;
                            // 本次读取不会阻塞，但不能保证读取的可靠性，并且没有应用场景就没办法定制协议
                            std::string recv_buffer;
                            if (TcpSocket::Recv(fd, recv_buffer)) {
                                std::cout << "client [" << fd << "]# " << recv_buffer << std::endl;
                            }
                            else {
                                std::cout << "sock: " << fd << "关闭连接，客户端退出，数组位置["
                                    << GetIndex(fd) << "]已被清理" << std::endl;
                                fd = -1; //数组位置为-1
                                close(fd);
                            }
                        }
                    }
                }
            }
            break;
        }
    }

    return 0;
}
