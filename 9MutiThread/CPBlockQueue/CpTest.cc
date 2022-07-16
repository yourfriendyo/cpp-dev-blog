#include "BlockQueue.hpp"
using namespace CPBlockQueue;

void* consumer(void* args)
{
    BlockQueue<int>* bq = (BlockQueue<int>*)args;
    while (true) {
        int data = 0;
        bq->Pop(&data);  // 不断出数据
        std::cout << "消费者消费数据：" << data << std::endl;
        // sleep(2);
    }

}
void* producer(void* args)
{
    BlockQueue<int>* bq = (BlockQueue<int>*)args;
    while (true) {
        int data = rand() % 20 + 1; // [1, 20]
        std::cout << "生产者生产数据：" << data << std::endl;
        bq->Push(data); // 不断入数据
        // sleep(2);
    }

}
int main()
{
    srand((long long)time(nullptr)); // 生成随机数
    
    BlockQueue<int>* bq = new BlockQueue<int>(); // 定义阻塞队列

    pthread_t c, p; // 定义生产者和消费者线程

    pthread_create(&c, nullptr, consumer, (void*)bq); // 创建线程
    pthread_create(&p, nullptr, producer, (void*)bq);

    pthread_join(c, nullptr); // 等待线程
    pthread_join(p, nullptr);

    return 0;
}