#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define BACK_LOG 5
#define BUFFER_SIZE 1024

class TcpSocket
{
public:
    static int Socket()
    {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock <= 0) {
            std::cerr << "socket error" << std::endl;
            exit(2);
        }
        int opt = 1;
        setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
        return sock;
    }
    static void Bind(int sock, uint16_t port)
    {
        struct sockaddr_in local;
        memset(&local, 0, sizeof(local));
        local.sin_family = AF_INET;
        local.sin_addr.s_addr = INADDR_ANY;
        local.sin_port = htons(port);
        if (bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0) {
            std::cerr << "bind error" << std::endl;
            exit(3);
        }
    }
    static void Listen(int sock)
    {
        if (listen(sock, BACK_LOG) < 0) {
            std::cerr << "listen error" << std::endl;
            exit(4);
        }
    }
    static int Accept(int sock)
    {
        struct sockaddr_in peer;
        socklen_t len = sizeof(peer);
        int new_sock = accept(sock, (struct sockaddr*)&peer, &len);
        // if (new_sock <= 0) {
        //    std::cerr << "accept error" << std::endl;
        //    exit(5);
        // }
        return new_sock;
    }
    static void Connect(int sock, const std::string& ip, int16_t port)
    {
        struct sockaddr_in peer;
        peer.sin_family = AF_INET;
        peer.sin_addr.s_addr = inet_addr(ip.c_str());
        peer.sin_port = htons(port);

        if (connect(sock, (struct sockaddr*)&peer, sizeof(peer)) < 0) {
            std::cerr << "connect error" << std::endl;
            exit(6);
        }
        else {
            std::cout << "connect success" << std::endl;
        }
    }

    static bool Send(int sock, std::string& buffer)
    {
        ssize_t s = send(sock, buffer.c_str(), buffer.size(), 0);
        if (s > 0) {
            // TODO

        }
        else if (s == 0) {
            std::cout << "send remote quit ..." << std::endl;
        }
        else {
            std::cerr << "send error" << std::endl;
            // exit(7);
        }
        return s > 0;
    }

    static int Recv(int sock, std::string& buffer)
    {
        buffer.clear();
        char tmp[BUFFER_SIZE];
        while (true)
        {
            ssize_t s = recv(sock, tmp, sizeof(tmp) - 1, 0);
            if (s > 0) {
                tmp[s] = 0;
                buffer += tmp;
            }
            else if (s < 0)
            {
                if (errno == EINTR) {                          //0. 被信号中断
                    continue;
                }
                if (errno == EAGAIN || errno == EWOULDBLOCK) { //1. 读完了
                    return 0;
                }
                return -1;                                     //2. 出错了
            }
            else {
                return -1;                                     // 对端关闭
            }
        }
    }
};