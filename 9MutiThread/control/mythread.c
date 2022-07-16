#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define NUM 5

/*********************** LWP  pthread_t ***********************/

// void* thread_run(void* args)
// {
//     while(1)
//     {
//         printf("new  thread id: 0x%x\n", pthread_self());
//         sleep(1);
//     }
// 
// }
// 
// int main()
// {
//     pthread_t tid;
//     pthread_create(&tid, NULL, thread_run, (void*)"new thread");
// 
//     while (1)
//     {
//         printf("main thread id: 0x%x\n", pthread_self());
//         sleep(1);
//     }
// }

/************************** 线程分离 **************************/

//void* thread_run(void* args)
//{
//    pthread_detach(pthread_self());
//
//    int id = *(int*)args;
//
//    while (1)
//    {
//        printf("I am new thread[%d], id: %ld\n", id, pthread_self());
//        sleep(2);
//    }
//
//    return (void*)id;
//}
//
//int main()
//{
//    pthread_t tid[NUM];
//
//    for (int i = 0; i < NUM; i++)
//    {
//        pthread_create(tid + i, NULL, thread_run, (void*)&i);
//        sleep(1);
//    }
//
//    //void* status = NULL;
//
//    //for (int i = 0; i < NUM; i++)
//    //{
//    //    int ret = pthread_join(tid[i], &status);
//    //    printf("thread[%d] join ret: %d, status: %d\n", i, ret,  (int)status);
//    //    sleep(1);
//    //}
//
//    return 0;
//}

/************************** 线程终止 **************************/

//pthread_t g_tid;
//
//void* thread_run(void* args)
//{
//    int id = *(int*)args;
//
//    while (1)
//    {
//        printf("thread[%d] created, id: %ld\n", id, pthread_self());
//        sleep(1);
//
//        printf("cancel main thread now!\n");
//        pthread_cancel(g_tid);
//        break;
//    }
//
//    
//    // pthread_exit((void*)id);
//    
//    // return (void*)id;
//    
//}
//
//
//int main()
//{
//    pthread_t tid[NUM];
//
//    g_tid = pthread_self();
//
//    for (int i = 0; i < NUM; i++)
//    {
//        pthread_create(tid + i, NULL, thread_run, (void*)&i);
//        sleep(1);
//    }
//
//    for (int i = 0; i < NUM; i++)
//    {
//        pthread_cancel(tid[i]);
//        printf("cancel thread[%d] success\n", i);
//        sleep(1);
//    }
//
//    for (int i = 0; i < NUM; i++)
//    {
//        void* retval = NULL;
//        pthread_join(tid[i], &retval);
//        printf("thread[%d] retval: %d\n", i, (int)retval);
//    }
//
//
//    return 0;
//}


/************************** 线程等待 **************************/

//void* thread_run(void* args)
//{
//    int id = *(int*)args;
//
//    while (1)
//    {
//        printf("new thread, id:%d, self: %ld\n", id, pthread_self());
//        sleep(5);
//        break;
//    }
//    return (void*)id;
//}
//
//int main()
//{
//    pthread_t tid[NUM];
//
//    // pthread_create
//    for (int i = 0; i < NUM; i++)
//    {
//        pthread_create(tid + i, NULL, thread_run, (void*)&i);
//        sleep(1);
//    }
//
//    // pthread_join 
//    for (int i = 0; i < NUM; i++) 
//    {
//        void* retval = NULL;
//        pthread_join(tid[i], &retval);
//
//        //printf("hello retval:%lld\n", (long long)retval);
//        printf("hello retval:%d\n", (int)retval); // 获取返回值
//    }
//
//
//
//    return 0;
//}


/************************** 线程创建 **************************/

//void* thread_run(void* args)
//{
//    int id =  *(int*)args;
//
//    while (1)
//    {
//        printf("我是[%d]线程，id: %ld\n", id, pthread_self());
//        sleep(3);
//        //野指针问题
//        if (id == 3) 
//        {
//            printf("hello thread[%d]\n", id);
//            int *p = NULL;
//            *p = 10;
//        }
//    }
//}
//
//
//int main()
//{
//    pthread_t tid[5];
//    for (int i = 0; i < 5; i++)
//    {
//        pthread_create(tid + i, NULL, thread_run, (void*)&i);
//        sleep(1);
//    }
//    while (1) 
//    {
//        printf("我是 主线程，self: %ld\n", pthread_self());
//
//        printf("--------------------- begin ----------------------------\n");
//        for (int i = 0; i < 5; i++)
//        {
//            printf("创建[%d]线程，id: %ld\n", i, tid[i]);
//        }    
//        printf("---------------------  end  ----------------------------\n");
//
//        sleep(1);
//    }
//    
//
//	return 0;
//}
