#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <sys/epoll.h>

#define EPOLL_SIZE 128
#define EVENT_NUM 128

// IO时，只有三种接口需要处理：处理读取，处理写入，处理异常

typedef int (*callback_t)(struct Event*); //回调函数指针

class Reactor;

// 交给epoll管理的基本节点
struct Event
{
public:
    int _fd;                  // 事件的文件描述符fd
    uint32_t _events;         // fd对应关心的事件

    std::string _in_buffer;   // fd对应的输入缓冲区
    std::string _out_buffer;  // fd对应的输出缓冲区

    //为fd设置回调
    callback_t _recver;
    callback_t _sender;
    callback_t _errorer;

    Reactor* _R_ptr;          // 设置Event回指Reactor的指针
public:
    Event(int fd = -1, uint32_t events = 0, Reactor* r_ptr = nullptr)
        :_fd(fd), _events(events), _R_ptr(r_ptr),
        _recver(nullptr), _sender(nullptr), _errorer(nullptr)
    {}

    void RegisterCallback(callback_t recver, callback_t sender, callback_t errorer) {
        _recver = recver;
        _sender = sender;
        _errorer = errorer;
    }

    ~Event() {}
};


// 封装Reactor类，用来管理Event
class Reactor
{
private:
    int _epfd;
    std::unordered_map<int, Event*> _events; // 建立fd和Event类的映射，所有Event的集合
public:
    Reactor() :_epfd(-1)
    {}

    void InitReactor() {
        _epfd = epoll_create(EPOLL_SIZE);
        if (_epfd < 0) {
            std::cerr << "epoll_creater error" << std::endl;
            exit(2);
        }
        std::cout << "epoll_creater success" << std::endl;
    }

    bool InsertEvent(Event* evp) // 插入结构和关心的事件
    {
        //1. 将ev中的sock插入到epoll中
        struct epoll_event ev;
        ev.events = evp->_events;
        ev.data.fd = evp->_fd;

        if (epoll_ctl(_epfd, EPOLL_CTL_ADD, evp->_fd, &ev) < 0) {
            std::cerr << "epoll_ctl failed" << std::endl;
            return false;
        }
        std::cout << "epoll_ctl success" << std::endl;
        //2. 将ev本身插入到map中
        _events.insert({ evp->_fd, evp });
    }

    void DeleteEvent(Event* evp) // 删除结构和关心的事件
    {
        //1. 将fd及其事件在epfd中删除
        epoll_ctl(_epfd, EPOLL_CTL_DEL, evp->_fd, nullptr);

        //2. 将fd及其事件在map中删除
        auto iter = _events.find(evp->_fd);
        if (iter != _events.end()) {
            _events.erase(iter);
        }
    }

    void ModifyEvent() {} //TODO

    // 就绪事件派发器
    void Dispatcher(int timeout = -1)
    {
        struct epoll_event revs[EVENT_NUM];
        int n = epoll_wait(_epfd, revs, EVENT_NUM, timeout);
        for (int i = 0; i < n; i++)
        {
            int fd = revs[i].data.fd;
            uint32_t revents = revs[i].events;
            // 差错处理
            if (revents & EPOLLERR)  revents |= (EPOLLIN | EPOLLOUT); // 事件出错转化为读写就绪
            if (revents & EPOLLHUP)  revents |= (EPOLLIN | EPOLLOUT); // 事件关闭转化为读写就绪

            // 读就绪处理 BUG??
            if (revents & EPOLLIN) {
                if (_events[fd]->_recver) _events[fd]->_recver(_events[fd]); // 调用接收回调
            }
            // 写就绪处理
            if (revents & EPOLLOUT) {
                if (_events[fd]->_sender) _events[fd]->_sender(_events[fd]); // 调用发送回调
            }
        }
    }

    ~Reactor() {}
};