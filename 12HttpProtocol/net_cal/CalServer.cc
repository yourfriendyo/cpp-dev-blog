#include <iostream>
#include <string>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include "Socket.hpp"
#include "Protocol.hpp"

using namespace NSTcpSocket;

static void Usage(std::string proc) {
    std::cout << "Usage \n\t" << proc << " port" << std::endl;
    exit(1);
}

void* RequestHandler(void* args)
{
    pthread_detach(pthread_self());
    int sock = *(int*)args;

    // while (true) {
    request_t req;
    ssize_t s = recv(sock, &req, sizeof(req), 0);
    std::cout << req.x << req.op << req.y << std::endl;

    if (s > 0)
    {
        response_t resp = { 0,0 };

        switch (req.op) {
        case '+':
            resp.result = req.x + req.y;
            break;
        case '-':
            resp.result = req.x - req.y;
            break;
        case '*':
            resp.result = req.x * req.y;
            break;
        case '/':
            if (req.y == 0) resp.status = 1;
            else            resp.result = req.x / req.y;
            break;
        case '&':
            if (req.y == 0) resp.status = 2;
            else            resp.result = req.x & req.y;
            break;
        default:
            resp.status = 3;
        }
        send(sock, &resp, sizeof(resp), 0);
    }
    else {
        std::cerr << "recv error" << std::endl;
    }
    // }
    close(sock);
    std::cout << "server done" << std::endl;
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
        int new_sock = TcpSocket::Accept(sock); // 接收连接

        pthread_t tid;
        pthread_create(&tid, nullptr, RequestHandler, (void*)&new_sock);
    }

    return 0;
}