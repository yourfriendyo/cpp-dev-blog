#pragma once
#include "Reactor.hpp"
#include "Socket.hpp"
#include "Util.hpp"
#include "Service.hpp"

int Accepter(Event* evp)
{
    std::cout << "有新链接到来，就绪fd为: " << evp->_fd << std::endl;

    while (true)
    {
        int sock = TcpSocket::Accept(evp->_fd);
        if (sock <= 0) {
            std::cout << "Accept Done!" << std::endl;
            break;
        }
        Util::SetNoBlock(sock); // 获取链接成功，设置非阻塞

        //构建Event事件柴火并添加到Reactor反应堆中
        Event* new_evp = new Event(sock, EPOLLIN | EPOLLET, evp->_R_ptr);
        new_evp->RegisterCallback(Recver, Sender, Errorer);

        evp->_R_ptr->InsertEvent(new_evp);

        // 为什么要所有的Event都指向Reactor？
        // 1. 能够直接调用Reactor内部方法。

    }

}