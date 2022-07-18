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
        sem_t _blank_sem;  // 生产者关心的空位置资源
        sem_t _data_sem;   // 消费者关心的数据资源
        // 利用信号量描述资源的个数，实现同步和互斥机制，提高并发性
        int _cStep; // 消费者当前位置
        int _pStep; // 生产者当前位置
    public:
        LoopQueue(int cap = g_defualt_cap)
            : _cap(cap)
            , _q(cap)
        {
            sem_init(&_blank_sem, 0, _cap);
            sem_init(&_data_sem, 0, 0);
        }
        ~LoopQueue()
        {
            sem_destroy(&_blank_sem);
            sem_destroy(&_data_sem);
        }

        // 生产接口
        void Push(const T& in)
        {
            sem_wait(&_blank_sem); // 申请空位 P(blank)

            //单生产者单消费者
            _q[_pStep++] = in; // 插入下标位置
            _pStep %= _cap;

            sem_post(&_data_sem);  // 释放数据 V(data)
        }
        // 消费接口
        void Pop(T* out)
        {
            sem_wait(&_data_sem);  // 申请数据 P(data)

            //单生产者单消费者
            *out = _q[_cStep++]; // 插入下标位置
            _cStep %= _cap;

            sem_post(&_blank_sem); // 释放空位 V(blank)
        }
    };
}

