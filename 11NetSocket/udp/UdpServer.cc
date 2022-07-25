#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// const uint16_t PORT = 8080; //网络服务进程端口不可轻易修改
const int BUFFER_SIZE = 1024; //读写缓冲区大小

void Usage(std::string proc) {
    std::cout << "Usage: \n\t" << proc << " port" << std::endl;
    exit(1);
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        Usage(argv[0]);
        exit(1);
    }
    uint16_t port = atoi(argv[1]);

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
    local.sin_port = htons(port);        // 端口 - htons 主机转网络短整型（小端转大端）
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

        // 接受数据
        ssize_t cnt = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&peer, &len);

        if (cnt > 0) {
            // 打印接受数据
            buffer[cnt] = 0;
            std::cout << "client# " << buffer << std::endl;

            FILE* fp = popen(buffer, "r"); //看作命令

                std::string res;
                while (fgets(buffer, sizeof(buffer), fp) != NULL) {
                    res += buffer;
                }
                // 发送数据
                // std::string reply = ">>> " + std::endl + std::string(buffer) + std::endl + " <<<";
                std::string reply = std::string(buffer);
                sendto(sock, reply.c_str(), reply.size(), 0, (struct sockaddr*)&peer, len);
        }
        else {
            std::cerr << "recvfrom error" << std::endl;
        }
    }

    return 0;
}