#pragma once
#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <queue>
#include <ctime>

namespace CPBlockQueue
{
    int g_deflaut_cap = 5;
    template <class T>
    class BlockQueue
    {
    private:
        std::queue<T> _q; // 阻塞队列
        int _cap;         // 队列元素上限
        pthread_mutex_t _mtx;
        // 生产满了就不要生产了，应该让消费者来消费；消费空了就不要消费了，应该让生产者来生产
        pthread_cond_t _isFull;  // 队列已满，消费者在该条件变量下等待
        pthread_cond_t _isEmpty; // 队列已空，生产者在该条件变量下等待

        bool IsFull() {
            return _q.size() == _cap;
        }
        bool IsEmpty() {
            return _q.size() == 0;
        }

        void LockQueue() {
            pthread_mutex_lock(&_mtx);
        }
        void UnlockQueue() {
            pthread_mutex_unlock(&_mtx);
        }

        void ProducerWait() {
            // 调用的时候，会自动释放锁
            // 返回的时候，会自动竞争锁，获取到锁后才会返回
            pthread_cond_wait(&_isEmpty, &_mtx); // 生产者在是否为空的条件变量下等待
        }
        void ConsumerWait() {
            pthread_cond_wait(&_isFull, &_mtx);  // 消费者在是否为满的条件变量下等待
        }

        void WakeupConsumer() {
            pthread_cond_signal(&_isFull);  // 消费者在是否为满下等待，唤醒消费者就是通知是否为满的条件
        }
        void WakeupProducer() {
            pthread_cond_signal(&_isEmpty); // 生产者在是否为空下等待，唤醒生产者就是通知是否为空的条件
        }
    public:
        BlockQueue() : _cap(g_deflaut_cap) {
            pthread_mutex_init(&_mtx, nullptr);
            pthread_cond_init(&_isFull, nullptr);
            pthread_cond_init(&_isEmpty, nullptr);
        }
        ~BlockQueue() {
            pthread_mutex_destroy(&_mtx);
            pthread_cond_destroy(&_isFull);
            pthread_cond_destroy(&_isEmpty);
        }

        void Push(const T& in)  
        {
            LockQueue(); //加锁

            while (IsFull()) {
                // 防止挂起失败或伪唤醒(条件不满足却被唤醒)，
                // 利用while循环持续检测，保证线程被唤醒时一定满足条件
                ProducerWait(); // 出函数必然获取到锁
            }

            _q.push(in); // 向队列中放数据
            // if (_q.size() > _cap / 2) {
            //     WakeupConsumer(); // 通知消费者来消费
            // }
            WakeupConsumer(); // 通知消费者来消费
            UnlockQueue();
        }

        void Pop(T* out)       
        {
            LockQueue(); //加锁

            while (IsEmpty()) {
                ConsumerWait(); 
            }

            *out = _q.front();
            _q.pop(); // 向队列中取数据

            // if (_q.size() < _cap / 2) {
            //     WakeupConsumer(); // 通知消费者来消费
            // }
            WakeupConsumer(); // 通知消费者来消费
            UnlockQueue();
        }
    };
}
