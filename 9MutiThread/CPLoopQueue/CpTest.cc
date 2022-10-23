#include <ctime>
#include <unistd.h>
#include "LoopQueue.hpp"
#include  "Task.hpp"

using namespace CPLoopQueue;
using namespace CPTask;

void* consumer(void* args)
{
    LoopQueue<Task>* rq = (LoopQueue<Task>*)args;
    while (true)
    {
        // int data = 0;
        // rq->Pop(&data);
        // std::cout << "consumer: " << pthread_self() << ", get a data: " << data << std::endl;

        Task t;
        rq->Pop(&t);
        std::cout << "Consumer: " << pthread_self() << ", Task: ";
        t.ConsumerPrintTask();

        // sleep(1);
    }

}

void* producer(void* args)
{
    LoopQueue<Task>* rq = (LoopQueue<Task>*)args;
    while (true)
    {
        // int data = rand() % 20 + 1;
        // std::cout << "producer: " << pthread_self() << ", mad a data: " << data << std::endl;
        // rq->Push(data);

        Task t(rand() % 20 + 1, rand() % 10 + 1, "+-*/%"[rand() % 5]);
        t();
        rq->Push(t);
        std::cout << "Producer: " << pthread_self() << ", Task: ";
        t.ProducerPrintTask();

        sleep(1);
    }

}

int main()
{
    const int NUM = 5;

    srand((long long)time(nullptr));
    LoopQueue<Task>* rq = new LoopQueue<Task>();

    pthread_t c[NUM], p[NUM];
    for (int i = 0; i < NUM; i++) {
        pthread_create(c + i, nullptr, consumer, (void*)rq);
        pthread_create(p + i, nullptr, producer, (void*)rq);
    }

    for (int i = 0; i < NUM; i++) {
        pthread_join(c[i], nullptr);
        pthread_join(p[i], nullptr);
    }

    return 0;
}