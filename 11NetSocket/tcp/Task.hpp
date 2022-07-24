#pragma once
#include <iostream>

namespace NSTask
{
    class Task
    {
    private:
        int _sock;
        int Run()
        {
            while (true) {
                char buffer[1024];
                memset(buffer, 0, sizeof(buffer));
                ssize_t s = recv(_sock, buffer, sizeof(buffer), 0);

                if (s > 0) {
                    buffer[s] = 0;
                    std::cout << "client# " << buffer << std::endl;

                    std::string reply = ">>>server<<< " + std::string(buffer);
                    send(_sock, reply.c_str(), reply.size(), 0);
                }
                else if (s == 0) {
                    std::cout << "client quit..." << std::endl;
                    break;
                }
                else {
                    std::cerr << "recv error" << std::endl;
                    break;
                }
            }
            close(_sock); // 释放套接字
        }
    public:
        Task() : _sock(-1)
        {}
        Task(int sock) : _sock(sock)
        {}
        ~Task()
        {}

        int operator()() {
            return Run();
        }
    };
}