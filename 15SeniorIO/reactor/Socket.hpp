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

    // 1: 全部发送完成
    // 0: 数据没有发完，但不能继续
    //-1: 发送失败
    static int Send(int sock, std::string& buffer)
    {
        const char* start = buffer.c_str();
        int size = buffer.size();
        ssize_t total = 0;
        while (true)
        {
            ssize_t curr = send(sock, start + total, size - total, 0);
            if (curr > 0) {
                total += curr;
                if (total == size) {
                    buffer.clear();
                    return 1;
                }
            }
            else {
                if (errno == EINTR)
                    continue;
                if (errno == EAGAIN || errno == EWOULDBLOCK) {
                    buffer.erase(0, total);
                    return 0;
                }
                return -1;
            }
        }
    }

    // 1: 全部接受完成
    // 0: 数据没有收完，但不能继续
    //-1: 接受失败
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
            else if (s < 0) {
                if (errno == EINTR)
                    continue;
                if (errno == EAGAIN || errno == EWOULDBLOCK) { //1. 读完了
                    return 1;
                }
                return -1;                                     //2. 出错了
            }
            else {
                return 0;
            }
        }
    }
};