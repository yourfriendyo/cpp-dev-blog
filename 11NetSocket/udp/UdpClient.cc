#include <iostream>
#include <string>
#include <cstring>
#include <cerrno>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const int BUFFER_SIZE = 1024; //读写缓冲区大小

void Usage(std::string proc) {
    std::cout << "Usage: \n\t" << proc << " server_ip, server_port" << std::endl;
}

int main(int argc, char* argv[])
{
    // 获取命令行参数
    if (argc != 3) {
        Usage(argv[0]);
        exit(0);
    }

    std::cout << "Hello UdpClient" << std::endl;

    //1. 创建套接字，打开网络文件
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        std::cerr << "socket error: " << errno << std::endl;
        exit(1);
    }

    //客户端进行网络通信必须要有IP地址和端口，但不需要显式绑定指定的端口
    //由系统随机分配，防止端口被占用

    //2. 使用服务
    // 服务端地址结构体
    struct sockaddr_in server;
    server.sin_family = AF_INET;                   // 协议家族
    server.sin_addr.s_addr = inet_addr(argv[1]);   // IP地址
    server.sin_port = htons(atoi(argv[2]));        // 端口

    bool quit = false;
    while (!quit)
    {
        char message[1024];
        std::cout << "MyShell: ";
        fgets(message, sizeof(message), stdin);

        //发送数据
        sendto(sock, message, strlen(message), 0, (struct sockaddr*)&server, sizeof(server));

        struct sockaddr_in tmp; //tmp仅用于传参，无实际意义
        socklen_t len = sizeof(tmp);
        char buffer[BUFFER_SIZE] = { 0 };

        //接受数据
        ssize_t cnt = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&tmp, &len);
        if (cnt > 0) {
            buffer[cnt] = 0;
            std::cout << "server # " << std::endl << buffer << std::endl;
        }
        else {
            std::cerr << "recvfrom error" << std::endl;
        }
    }

    return 0;
}