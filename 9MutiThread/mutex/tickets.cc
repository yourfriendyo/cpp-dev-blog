#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>

#define NUM 5

class Ticket
{
    // private:
public:
    int tickets;         // 临界资源
    pthread_mutex_t mtx; // 给临界资源加锁
public:
    Ticket() : tickets(1000)
    {
        pthread_mutex_init(&mtx, nullptr);
    }
    // 抢票
    bool GetTickets()
    {
        // static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
        bool ret = false;
        pthread_mutex_lock(&mtx); // 加锁

        // 临界区：加锁后的临界区，一次只有一个执行流进入
        if (tickets > 0)
        {
            usleep(1000); // 1s == 1000ms, 1ms == 1000us
            std::cout << pthread_self() << " thread get a ticket, left tickets: " << tickets << std::endl;
            tickets--;
        }
        else
        { // 没票
            std::cout << "there is no tickets" << std::endl;
            ret = true;
        }
        pthread_mutex_unlock(&mtx); // 解锁
        return ret;
    }
    ~Ticket()
    {
        pthread_mutex_destroy(&mtx);
    }
};

// 抢票逻辑
void *ThreadRun(void *args)
{
    Ticket *t = (Ticket *)args;
    while (true)
    {
        if (t->GetTickets())
        {
            break;
        }
    }

    return (void *)args;
}

int main()
{
    Ticket*t = new Ticket();
    pthread_t tid[NUM];

    for (int i = 0; i < NUM; i++)
    {
        pthread_create(tid + i, NULL, ThreadRun, (void *)t);
        // sleep(1);
    }

    void *status = NULL;
    for (int i = 0; i < NUM; i++)
    {
        pthread_join(tid[i], &status);
    }

    return 0;
}
