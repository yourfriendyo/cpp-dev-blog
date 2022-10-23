#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <poll.h>
#include <sys/types.h>
#include "Socket.hpp"
#define NUM 128
using namespace NSTcpSocket;

static void Usage(std::string proc) {
    std::cout << "Usage: \n\t" << proc << " port" << std::endl;
    exit(1);
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        Usage(argv[0]);
    }
    uint16_t port = atoi(argv[1]);

    int listen_sock = TcpSocket::Socket();
    TcpSocket::Bind(listen_sock, port);
    TcpSocket::Listen(listen_sock);

    struct pollfd nfds[NUM];
    for (int i = 0; i < NUM; i++) {
        nfds[i].fd = -1;
        nfds[i].events = 0;
        nfds[i].revents = 0;
    }
    nfds[0].fd = listen_sock;
    nfds[0].events = POLLIN;
    nfds[0].revents = 0;

    //事件循环
    for (;;)
    {
        switch (poll(nfds, NUM, -1))
        {
        case 0:
            std::cout << "poll timeout" << std::endl;
            break;
        case -1:
            std::cerr << "poll failed" << std::endl;
            break;
        default:
            std::cout << "有事件就绪" << std::endl;
            for (int i = 0; i < NUM; i++)
            {
                if (nfds[i].fd != -1 && nfds[i].revents != 0)
                {
                    if (nfds[i].fd == listen_sock)
                    {
                        int sock = TcpSocket::Accept(nfds[i].fd);
                        std::cout << "事件为建立新链接: " << sock << std::endl;
                        if (sock >= 0)
                        {
                            //push到数组中，以待交给select等待
                            int pos = 1;
                            for (; pos < NUM; pos++) { // 查找可用位置
                                if (nfds[pos].fd == -1) {
                                    break;
                                }
                            }
                            if (pos < NUM) {
                                nfds[pos].fd = sock; // 提取连接到来不代表读事件就绪
                                nfds[pos].events = POLLIN;
                                std::cout << "新连接被添加在数组位置[" << pos << "]，并设置等待事件" << std::endl;
                            }
                            else {
                                close(nfds[i].fd);
                            }
                        }
                        else {
                            close(nfds[i].fd);
                        }
                    }
                    else { // 普通事件就绪
                        if (nfds[i].revents & POLLIN)
                        {
                            std::cout << "事件为普通读取事件" << std::endl;
                            // 本次读取不会阻塞，但不能保证读取的可靠性，并且没有应用场景就没办法定制协议
                            std::string recv_buffer;
                            if (TcpSocket::Recv(nfds[i].fd, recv_buffer)) {
                                std::cout << "client [" << nfds[i].fd << "]# " << recv_buffer << std::endl;
                            }
                            else {
                                std::cout << "sock: " << nfds[i].fd << "关闭连接，客户端退出，数组位置["
                                    << i << "]已被清理" << std::endl;
                                nfds[i].fd = -1; //数组位置为-1
                                nfds[i].events = 0;
                                close(nfds[i].fd);
                            }
                        }
                        else {
                            std::cout << "事件为普通写入事件" << std::endl;
                        }
                    }
                }
            }
            break;
        }
    }
    return 0;
}
