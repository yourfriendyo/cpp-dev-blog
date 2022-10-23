#include <ctime>
#include "ThreadPool.hpp"
#include "Task.hpp"

using namespace NSThreadPool;
using namespace NSTask;

int main()
{
    srand((long long)time(nullptr));

    while (true)
    {
        sleep(1);

        Task t(rand() % 20 + 1, rand() % 10 + 1, "+-*/%"[rand() % 5]);

        ThreadPool<Task>::GetInstance()->PushTask(t); // 利用静态成员函数返回的静态对象指针调用PushTask函数

        std::cout << "main thread make a task success: ";
        t.ProducerPrintTask();
    }

    return 0;
}