#include <iostream>
#include <string>
#include <cstdlib>
#include <pthread.h>
#include "Socket.hpp"

using namespace NSTcpSocket;

static void Usage(std::string proc) {
    std::cout << "Usage \n\t" << proc <<" port" << std::endl;
    exit(1);
}

void* RequestHandler(void* args)
{
    pthread_detach(pthread_self());
    int sock = *(int*)args;

    std::string recv_string;
    std::cout << "Server Recv begin" << std::endl;
    TcpSocket::Recv(sock, recv_string);
    std::cout << "Server Recv over" << std::endl;

    std::cout << recv_string << std::endl;

    TcpSocket::Send(sock, recv_string);

    return nullptr;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        Usage(argv[0]);
    }
    std::cout << "hello HttpServer" << std::endl;
    uint16_t port = atoi(argv[1]);

    int sock = TcpSocket::Socket(); // 创建套接字
    TcpSocket::Bind(sock, port); // 绑定
    TcpSocket::Listen(sock); // 监听

    while (true)
    {
        TcpSocket::Accept(sock); // 接收连接

        pthread_t tid;
        pthread_create(&tid, nullptr, RequestHandler, (void*)&sock);
    }


    return 0;
}