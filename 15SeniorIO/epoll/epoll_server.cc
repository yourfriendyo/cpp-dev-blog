#include <iostream>
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
    // ev.data =
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

            break;
        }

    }

    close(epfd);
    close(listen_sock);

    return 0;
}