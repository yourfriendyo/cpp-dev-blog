#include <ctime>
#include <unistd.h>
#include "LoopQueue.hpp"

using namespace CPLoopQueue;

void* consumer(void* args)
{
    LoopQueue<int>* rq = (LoopQueue<int>*)args;
    while (true)
    {
        int data = 0;
        rq->Pop(&data);
        std::cout << "consumer get a data: " << data << std::endl;
        // sleep(1);
    }

}

void* producer(void* args)
{
    LoopQueue<int>* rq = (LoopQueue<int>*)args;
    while (true)
    {
        int data = rand() % 20 + 1;
        std::cout << "producer make a data: " << data << std::endl;
        rq->Push(data);
        sleep(1);
    }

}

int main()
{
    srand((long long)time(nullptr));
    LoopQueue<int>* rq = new LoopQueue<int>();

    pthread_t c, p;
    pthread_create(&c, nullptr, consumer, (void*)rq);
    pthread_create(&p, nullptr, producer, (void*)rq);

    pthread_join(c, nullptr);
    pthread_join(p, nullptr);

    return 0;
}