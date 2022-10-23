#include <iostream>
#include <unistd.h>
#include <pthread.h>
#define NUM 5

pthread_mutex_t mtx;
pthread_cond_t cond;

void* work(void* args)
{
    int number = *(int*)args;
    while (true) {
        pthread_cond_wait(&cond, &mtx);   // 等待条件变量
        std::cout << "worker: " << number << " is working..." << std::endl;
    }
}

void* control(void* args)
{
    std::string name = (char*)args;
    while (true) {
        std::cout << name << " tell worker to work -> ";
        pthread_cond_broadcast(&cond);    // 唤醒在条件变量下等待的所有线程
        // pthread_cond_signal(&cond);    // 唤醒在条件变量下等待的单个线程
        sleep(1);
    }
}

int main()
{
    pthread_mutex_init(&mtx, nullptr);    // 创建锁
    pthread_cond_init(&cond, nullptr);    // 创建条件变量

    pthread_t worker[NUM];                // 员工线程
    pthread_t boss;                       // 老板线程

    // 创建线程
    for (int i = 0; i < NUM; i++) {
        int* number = new int(i);
        pthread_create(worker + i, nullptr, work, (void*)number);
        // pthread_create(worker + i, nullptr, work, (void*)&i);
        // sleep(1);
    }
    pthread_create(&boss, nullptr, control, (void*)"boss");

    // 等待线程
    for (int i = 0; i < NUM; i++) {
        pthread_join(worker[i], nullptr);
    }
    pthread_join(boss, nullptr);

    pthread_mutex_destroy(&mtx);          // 释放锁
    pthread_cond_destroy(&cond);          // 释放条件变量

    return 0;
}
