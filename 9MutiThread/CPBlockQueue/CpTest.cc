#include "BlockQueue.hpp"
#include "Task.hpp"

using namespace CPBlockQueue;
using namespace CPTask;
#define NUM 5

void* consumer(void* args)
{
    BlockQueue<Task>* bq = (BlockQueue<Task>*)args;
    while (true) {
        Task t;
        bq->Pop(&t); // 获取任务
        // t.Run(); // 执行任务
        t();
        sleep(1);
        std::cout << "consumer: " << pthread_self() << " get a task: ";
        t.PrintTask();
    }
}

void* producer(void* args)
{
    BlockQueue<Task>* bq = (BlockQueue<Task>*)args;
    std::string ops = "+-*/&"; // 操作集

    while (true) {
        int x = rand() % 20 + 1;
        int y = rand() % 20 + 1;
        char op = ops[rand() % 5]; // [0, 4] 利用操作集的下标
        Task t(x, y, op); // 生成任务

        bq->Push(t); // 派发任务到队列中
        sleep(1); // 不加 sleep 导致队列满后卡住

        std::cout << "Producer: " << pthread_self() << " distribute a task: ";
        t.PrintTask();
    }   
}

int main()
{
    srand((long long)time(nullptr)); // 生成随机数
    
    BlockQueue<Task>* bq = new BlockQueue<Task>(); // 定义阻塞队列

    pthread_t c[5], p[5]; // 定义生产者和消费者线程
    // 创建线程
    for (int i = 0; i < NUM; i++) {
        pthread_create(c + i, nullptr, consumer, (void*)bq); 
        pthread_create(p + i, nullptr, producer, (void*)bq);
    }
    // 等待线程
    for (int i = 0; i < NUM; i++) {
        pthread_join(c[i], nullptr);
        pthread_join(p[i], nullptr);
    }

    return 0;
}


// void* consumer(void* args)
// {
//     BlockQueue<int>* bq = (BlockQueue<int>*)args;
//     while (true) {
//         int data = 0;
//         bq->Pop(&data);  // 不断出数据
//         std::cout << "消费者消费数据：" << data << std::endl;
//         // sleep(2);
//     }
// 
// }
// void* producer(void* args)
// {
//     BlockQueue<int>* bq = (BlockQueue<int>*)args;
//     while (true) {
//         int data = rand() % 20 + 1; // [1, 20]
//         std::cout << "生产者生产数据：" << data << std::endl;
//         bq->Push(data); // 不断入数据
//         // sleep(2);
//     }
// 
// }