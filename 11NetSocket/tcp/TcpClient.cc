#include <iostream>
#include <string>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void Usage(std::string proc) {
    std::cout << "Usage: \t\n" << proc << " server_ip server_port" << std::endl;
}

// ./UdpClient server_ip server_port
int main(int argc, char* argv[])
{
    if (argc != 3) {
        Usage(argv[0]);
        exit(1);
    }
    std::cout << "hello tcp_client" << std::endl;

    std::string svr_ip = argv[1];
    uint16_t svr_port = atoi(argv[2]);

    //1. 建立连接
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cout << "socket error: " << errno << std::endl;
        exit(2);
    }

    // bind listen accept ??
    //2. 开始连接
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(svr_ip.c_str());
    //inet_addr 将点分十进制形式IP转化为4字节整数IP，并将主机序列转化为网络序列
    server.sin_port = htons(svr_port);
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        std::cout << "connect error" << std::endl;
        exit(3);
    }

    std::cout << "connect successs" << std::endl;

    //3. 业务代码
    while (true)
    {
        std::cout << "input-> ";
        char buffer[1024];
        fgets(buffer, sizeof(buffer), stdin);

        int cnt = send(sock, buffer, strlen(buffer), 0);

        ssize_t s = recv(sock, buffer, sizeof(buffer), 0);
        if (s > 0) {
            buffer[s] = 0;
            std::cout << buffer << std::endl;
        }
        else {
            std::cout << "recv error" << std::endl;
            exit(4);
        }

    }

    return 0;
}
