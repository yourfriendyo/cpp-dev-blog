#include "ThreadPool.hpp"
#include "Task.hpp"
#include <ctime>
#include <unistd.h>

using namespace NSThreadPool;
using namespace NSTask;

int main()
{
    srand((long long)time(nullptr));
    ThreadPool<Task>* tp = new ThreadPool<Task>();
    tp->InitThreadPool();

    while (true)
    {
        Task t(rand() % 20 + 1, rand() % 10 + 1, "+-*/%"[rand() % 5]);

        std::cout << "main thread make a task success: ";
        t.ProducerPrintTask();
        
        tp->PushTask(t);

        sleep(1);
    }

    return 0;
}