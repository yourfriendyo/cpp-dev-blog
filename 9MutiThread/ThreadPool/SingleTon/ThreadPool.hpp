#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <pthread.h>
#include <unistd.h>


namespace NSThreadPool
{
    const int g_num = 5;

    template <class T>
    class ThreadPool
    {
    private:
        int _num;                    // 线程个数
        std::queue<T> _taskQueue;    // 任务队列

        pthread_mutex_t _mtx;        // 维护任务队列的互斥访问
        pthread_cond_t _cond;        // 唤醒因队列为空而挂起的线程 

        static ThreadPool<T>* _ins;  // 类内静态指针

    private:
        //构造函数一定要有，因为new对象仍然会调用构造，只是外部不允许构造
        ThreadPool(int num = g_num) : _num(num)
        {
            pthread_mutex_init(&_mtx, nullptr);
            pthread_cond_init(&_cond, nullptr);
        }

        ThreadPool(const ThreadPool<T>& tp) = delete;

        ThreadPool<T>& operator=(ThreadPool<T>& tp) = delete;

        void InitThreadPool()
        {
            pthread_t tid;
            for (int i = 0; i < _num; i++)
            {
                pthread_create(&tid, nullptr, Routine, (void*)this);
            }
        }
    public:
        ~ThreadPool()
        {
            pthread_mutex_destroy(&_mtx);
            pthread_cond_destroy(&_cond);
        }

        void Lock() {
            pthread_mutex_lock(&_mtx);
        }
        void Unlock() {
            pthread_mutex_unlock(&_mtx);
        }
        void Wait() {
            pthread_cond_wait(&_cond, &_mtx); 
        }
        void Wakeup() {
            pthread_cond_signal(&_cond);
        }
        bool IsEmpty() {
            return _taskQueue.empty();
        }

    public:
        static ThreadPool<T>* GetInstance()
        {
            // 此时如果多个线程同时进行判断并进入，就会创建多份，因此线程不安全
            // if (_ins == nullptr)
            // {
            //     _ins = new ThreadPool<T>();
            //     _ins->InitThreadPool(); // 在非静态成员函数中可以利用静态指针调用非静态函数
            //     std::cout << "首次加载对象" << std::endl;
            // }

            static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
            if (_ins == nullptr) // 双判断，避免多线程同时竞争锁到锁内判断降低效率
            {
                pthread_mutex_lock(&lock);
                if (_ins == nullptr)
                {
                    _ins = new ThreadPool<T>();
                    _ins->InitThreadPool(); // 在非静态成员函数中可以利用静态指针调用非静态函数
                    std::cout << "首次加载对象" << std::endl;
                }
                pthread_mutex_unlock(&lock);
            }
            return _ins;
        }

        // 线程执行函数如果是类内成员，需要设置为静态成员，因为非静态成员函数参数有隐含this指针
        static void* Routine(void* args)
        {
            ThreadPool<T>* tp = (ThreadPool<T>*)args; // 通过参数显式传递this指针
            pthread_detach(pthread_self());

            while (true)
            {
                tp->Lock(); // 访问临界资源先加锁

                while (tp->IsEmpty())  // 任务队列为空，线程应该挂起
                {
                    tp->Wait(); // 等待条件变量
                }

                T t;
                tp->PopTask(&t); // 获取任务

                tp->Unlock();

                t(); // 解锁之后进行处理任务，避免占用锁，提高效率
                t.ConsumerPrintTask();
            }
        }


        void PushTask(const T& in)
        {
            Lock();
            _taskQueue.push(in);
            Unlock();

            Wakeup(); // 唤醒线程处理任务
        }

        void PopTask(T* out)
        {
            *out = _taskQueue.front();
            _taskQueue.pop();
        }

    };
    template <class T>
    ThreadPool<T>* ThreadPool<T>::_ins = nullptr;
}
