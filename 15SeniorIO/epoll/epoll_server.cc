#include <iostream>
#include <string>
#include <sys/epoll.h>
#include <unistd.h>
#include "Socket.hpp"

using namespace NSTcpSocket;

#define NUM 128

static void Usage(std::string proc) {
    std::cerr << "Usage: \n\t" << proc << " port" << std::endl;
    exit(1);
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        Usage(argv[0]);
    }
    uint16_t port = atoi(argv[1]);

    //1. 建立tcp socket
    int listen_sock = TcpSocket::Socket();
    TcpSocket::Bind(listen_sock, port);
    TcpSocket::Listen(listen_sock);

    //2. 创建epoll模型
    int epfd = epoll_create(128);

    //3. 添加listen_sock和事件到内核
    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = listen_sock;
    epoll_ctl(epfd, EPOLL_CTL_ADD, listen_sock, &ev);

    //4. 事件循环
    struct epoll_event repevs[NUM];
    volatile bool quit = false;
    while (!quit)
    {
        int timeout = 1000;
        //repevs就绪事件
        int n = epoll_wait(epfd, repevs, NUM, timeout);
        switch (n)
        {
        case -1:
            std::cerr << "poll failed" << std::endl;
            break;
        case 0:
            std::cout << "poll timeout" << std::endl;
            break;
        default:
            std::cout << "有事件就绪" << std::endl;
            //5. 处理就绪
            for (int i = 0; i < n; i++)
            {
                int fd = repevs[i].data.fd; // 暂时方案
                std::cout << "fd: " << fd << " 上有事件就绪啦" << std::endl;
                if (repevs[i].events & EPOLLIN)
                {
                    std::cout << "fd: " << fd << " 读事件就绪" << std::endl;
                    if (fd == listen_sock) // 处理链接事件
                    {
                        std::cout << "fd: " << fd << " 是链接读事件" << std::endl;
                        int sock = TcpSocket::Accept(listen_sock);
                        if (sock >= 0)
                        {
                            std::cout << "fd: " << fd << " 链接获取成功 sock: " << sock << std::endl;
                            struct epoll_event _ev;
                            _ev.data.fd = sock;
                            _ev.events = EPOLLIN;
                            epoll_ctl(epfd, EPOLL_CTL_ADD, sock, &_ev);
                            std::cout << "sock: " << sock << " 交给epoll托管成功" << std::endl;
                        }
                        else {}
                    }
                    else // 处理普通读取事件
                    {
                        std::cout << "fd: " << fd << " 普通读事件就绪" << std::endl;
                        std::string recv_buffer;
                        TcpSocket::Recv(fd, recv_buffer);
                        std::cout << "client# " << recv_buffer << std::endl;
                    }
                }
                else if (repevs[i].events & EPOLLOUT) // 处理写入事件
                {

                }
                else {}
            }
            break;
        }
    }

    close(epfd);
    close(listen_sock);
    return 0;
}