#include <iostream>
#include <string>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

void Usage(std::string proc) {
    std::cout << "Usage: \n\t" << proc << " port" << std::endl;
}
void ServerIO(int new_sock) {
    while (true)
    {
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        ssize_t s = recv(new_sock, buffer, sizeof(buffer), 0);
        // ssize_t s = read(new_sock, buffer, sizeof(buffer));

        if (s > 0) {
            buffer[s] = 0;
            std::cout << "client# " << buffer << std::endl;

            std::string reply = ">>>server<<< " + std::string(buffer);
            send(new_sock, reply.c_str(), reply.size(), 0);
            // write(new_sock, reply.c_str(), reply.size());
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
}

// ./TcpServer 8081
int main(int argc, char* argv[])
{
    if (argc != 2) {
        Usage(argv[0]);
        exit(1);
    }
    std::cout << "hello tcp_server" << std::endl;

    //1. 创建套接字
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        std::cerr << "socket error" << errno << std::endl;
        exit(2);
    }

    //2. 绑定IP地址和端口
    struct sockaddr_in local;
    memset(&local, 0, sizeof(local));
    local.sin_family = AF_INET;
    local.sin_port = htons(atoi(argv[1]));
    local.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_sock, (struct sockaddr*)&local, sizeof(local)) < 0) {
        std::cerr << "bind error" << errno << std::endl;
        exit(3);
    }

    //3. tcp 面向连接通信，在通信前先建立连接
    // 客户端主动建立连接，服务端被动接受连接
    // 故要不断提供给用户一个建立连接的功能，设置套接字为listen状态，本质是允许用户连接
    const int back_log = 5;
    if (listen(listen_sock, back_log) < 0) {
        std::cerr << "listen error" << errno << std::endl;
        exit(4);
    }
    signal(SIGCHLD, SIG_IGN); //忽略子进程信号，子进程自动释放

    for ( ; ; ) {
        //4. 获取连接
        struct sockaddr_in peer;
        socklen_t len = sizeof(peer);
        int new_sock = accept(listen_sock, (struct sockaddr*)&peer, &len);
        if (new_sock < 0) {
            continue;
        }
        std::cout << "get a new link ..."<< new_sock << std::endl;
        //5. 提供服务

        //Version2:多进程版
        pid_t id = fork();
        if (id < 0) {
            continue;
        }
        else if (id == 0) { // child
            ServerIO(new_sock);
            exit(0);
        }
        else { // father
            //donothing
        }
        //Version1:单进程版，无人使用！
        // ServerIO(new_sock);
    }

    return 0;
}