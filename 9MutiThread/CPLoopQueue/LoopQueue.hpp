#pragma once
#include <iostream>
#include <pthread.h>
#include <vector>
#include <semaphore.h>

namespace CPLoopQueue
{
    int g_defualt_cap = 5;
    template <class T>
    class LoopQueue
    {
    private:
        std::vector<T> _q; // 循环队列
        int _cap;

        // 利用信号量描述资源的个数，实现同步和互斥机制，提高并发性
        sem_t _blankSem;  // 生产者关心的空位置资源
        sem_t _dataSem;   // 消费者关心的数据资源

        int _cStep; // 消费者当前位置
        int _pStep; // 生产者当前位置

        // 维护多生产者和多消费者各自之间的互斥关系
        pthread_mutex_t _cLock; // 消费者之间的锁
        pthread_mutex_t _pLock; // 生产者之间的锁
    public:
        LoopQueue(int cap = g_defualt_cap)
            : _cap(cap)
            , _q(cap)
        {
            sem_init(&_blankSem, 0, _cap);
            sem_init(&_dataSem, 0, 0);
        }
        ~LoopQueue()
        {
            sem_destroy(&_blankSem);
            sem_destroy(&_dataSem);
        }

        // 生产接口
        void Push(const T& in)
        {
            sem_wait(&_blankSem); // 申请空位 P(blank)
            pthread_mutex_lock(&_pLock); // 先申请信号量后加锁，提前预定资源，提高效率
            // 多生产和多消费的优势在于并发地获取和处理任务

            _q[_pStep++] = in; // 插入下标位置
            _pStep %= _cap;

            pthread_mutex_unlock(&_pLock);
            sem_post(&_dataSem);  // 释放数据 V(data)
        }
        // 消费接口
        void Pop(T* out)
        {
            sem_wait(&_dataSem);  // 申请数据 P(data)
            pthread_mutex_lock(&_cLock);

            *out = _q[_cStep++]; // 插入下标位置
            _cStep %= _cap;

            pthread_mutex_unlock(&_cLock);
            sem_post(&_blankSem); // 释放空位 V(blank)
        }
    };
}
