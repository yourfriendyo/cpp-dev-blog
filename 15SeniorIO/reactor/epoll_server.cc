#include "Socket.hpp"
#include "Reactor.hpp"
#include "Accepter.hpp"
#include "Util.hpp"

static void Usage(std::string proc) {
    std::cout << "Usage: \n\t" << proc << " port" << std::endl;
    exit(1);
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        Usage(argv[0]);
    }
    uint16_t port = atoi(argv[1]);

    //1. 创建套接字
    int listen_sock = TcpSocket::Socket();
    Util::SetNoBlock(listen_sock); // 设置非阻塞
    TcpSocket::Bind(listen_sock, port);
    TcpSocket::Listen(listen_sock);

    //2. 创建Reactor对象
    Reactor* R_ptr = new Reactor();
    R_ptr->InitReactor();

    //3. 给Reactor反应堆加柴火
    Event* evp = new Event(listen_sock, EPOLLIN | EPOLLET, R_ptr);

    evp->RegisterCallback(Accepter, nullptr, nullptr); // Accepter连接管理器

    R_ptr->InsertEvent(evp);

    //4. 事件派发
    volatile bool quit = false;
    int timeout = 1000;
    while (!quit)
    {
        R_ptr->Dispatcher(timeout);

    }


}