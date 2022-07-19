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
        int _num;                  // 线程个数
        std::queue<T> _taskQueue;  // 任务队列
        pthread_mutex_t _mtx;      // 维护任务队列的互斥访问
        pthread_cond_t _cond;      //  

    public:
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

        ThreadPool(int num = g_num) : _num(num)
        {
            pthread_mutex_init(&_mtx, nullptr);
            pthread_cond_init(&_cond, nullptr);
        }
        ~ThreadPool()
        {
            pthread_mutex_destroy(&_mtx);
            pthread_cond_destroy(&_cond);
        }
    public:
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
        void InitThreadPool()
        {
            pthread_t tid;
            for (int i = 0; i < _num; i++)
            {
                pthread_create(&tid, nullptr, Routine, (void*)this);
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

}
