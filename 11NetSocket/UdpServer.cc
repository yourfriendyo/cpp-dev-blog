#include <iostream>
#include <string>
#include <cerrno>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const int PORT = 8080; //网络服务进程端口不可轻易修改
const int BUFFER_SIZE = 1024; //读写缓冲区大小

int main()
{
    std::cout << "Hello UdpServer" << std::endl;

    //1. 创建套接字，打开网络文件
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) { // 3
        std::cerr << "socket error: " << errno << std::endl;
        exit(1);
    }

    //2. 绑定IP和端口
    struct sockaddr_in local;
    local.sin_family = AF_INET;          // 协议家族
    local.sin_port = htons(PORT);        // 端口 - htons 主机转网络短整型（小端转大端）
    local.sin_addr.s_addr = INADDR_ANY;  // IP地址
    // 云服务器不允许显式绑定IP，防止单主机多IP的情况
    // local.sin_addr = inet_addr("81.68.165.71"); // IP地址 - inet_addr 将点分十进制IP转化成4字节整数IP

    if (bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0) {
        std::cerr << "bind error: " << errno << std::endl;
        exit(2);
    }

    //3. 提供服务
    bool quit = false;
    while (!quit)
    {
        struct sockaddr_in peer;           // 远端地址
        socklen_t len = sizeof(peer);      // 远端地址结构体大小
        char buffer[BUFFER_SIZE] = { 0 };  // 缓冲区

        recvfrom(sock, buffer, sizeof(buffer) - 1, 0, (struct sockaddr*)&peer, &len); // 接受数据
        std::cout << "client # " << buffer << std::endl; // 打印接受数据

        sendto(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&peer, len); // 发送数据
    }

    return 0;
}
