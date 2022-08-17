#include <iostream>
#include <string>
#include <vector>
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
int GetMaxFd()
{
    int max = 0;
    for (auto e : fd_v) {
        if (max < e) {
            max = e;
        }
    }
    return max;
}

//./select_server 8080
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
        FD_ZERO(&read_fds);

        struct timeval timeout = { 5, 0 };

        switch (select(listen_sock + 1, &read_fds, nullptr, nullptr, nullptr))
        {
        case 0:
            std::cout << "select timeout" << std::endl;
            break;
        case -1:
            std::cerr << "select failed" << std::endl;
            break;
        default:
            std::cout << "select get fds readly" << std::endl;
            // TcpSocket::Accept(listen_sock);
            break;

        }

    }

    return 0;
}
