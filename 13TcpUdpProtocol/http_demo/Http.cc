#include <iostream>
#include <string>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include "Socket.hpp"

using namespace NSTcpSocket;

#define WWWROOT "./wwwroot/"
#define HOME_PAGE "index.html"

void Usage(std::string proc) {
    std::cout << "Usage: \n\t" << proc << " port" << std::endl;
    exit(1);
}

void* HttpResquestHandler(void* args)
{
    pthread_detach(pthread_self());
    int sock = *(int*)args;

    std::string buffer;
    // 这种读法其实是不正确的
    if (TcpSocket::Recv(sock, buffer)) {
        std::cout << buffer; //打印HTTP的请求格式

        std::string home_page = std::string(WWWROOT) + std::string(HOME_PAGE); // 默认首页路径
        struct stat st;
        stat(home_page.c_str(), &st); // 以待获取文件信息

        std::string http_response;

        //响应正文是index.html的文件内容
        std::ifstream ifs(home_page);
        if (!ifs.is_open())
        {
            std::cerr << "ifs open fail" << std::endl;
        }
        else
        {
            http_response += "http/1.0 200 OK\n"; // 状态行
            // http_response += "Location: https://qq.com/\n\n";

            http_response += "Set-Cookie: id=111&passwd=222\n";
            http_response += "Content-Type: text/html; charset=utf-8\n";  // 响应报头
            http_response += "Content-Length: ";
            http_response += std::to_string(st.st_size); // 补齐正文内容属性数据
            http_response += "\n\n";  // 补齐属性的换行和空行

            char buffer[st.st_size];  // 以文件大小创建缓冲区
            memset(buffer, 0, sizeof(buffer));
            ifs.read(buffer, st.st_size); // 将文件内容读进缓冲区
            http_response += buffer;
        }

        TcpSocket::Send(sock, http_response);
    }
    close(sock);
    return nullptr;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        Usage(argv[0]);
    }
    uint16_t port = atoi(argv[1]);

    int listen_sock = TcpSocket::Socket();
    TcpSocket::Bind(listen_sock, port);
    TcpSocket::Listen(listen_sock);


    std::cout << "Listen Done" << std::endl;

    while (true) 
    {
        sleep(1);
        int sock = TcpSocket::Accept(listen_sock);
        std::cout << "socket_fd: " << sock << std::endl;
        //  if (sock > 0) {
        //      pthread_t tid;
        //      pthread_create(&tid, nullptr, HttpResquestHandler, (void*)&sock);
        //  }
    }

    return 0;
}
