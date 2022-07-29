#include <iostream>
#include <string>
#include <cstdlib>
#include "Socket.hpp"
using namespace NSTcpSocket;

void Usage(std::string proc) {
    std::cout << "Usage \n\t" << proc << "server_ip server_port" << std::endl;
    exit(1);
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        Usage(argv[0]);
    }
    std::cout << "hello HttpClient" << std::endl;

    int sock = TcpSocket::Socket();

    TcpSocket::Connect(sock, argv[1], atoi(argv[2]));

    while (true)
    {
        std::cout << "input->";

        std::string send_string;
        std::cin >> send_string;

        TcpSocket::Send(sock, send_string);

        TcpSocket::Recv(sock, send_string);
    }

    return 0;
}