#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

//int count = 0;
//
//void handler(int signum) {
//	printf("count:%d\n", count);
//	exit(0);
//}
//int main()
//{
//	signal(SIGALRM, handler);
//	alarm(1);
//	while (1) {
//		//printf("hello count:%d\n", count++);
//		count++;	
//	}
//	return 0;
//}

//void handler(int signum) {
//	switch(signum) {
//		case 2:
//			printf("hello signum:%d\n", signum);
//			break;
//		case 3:
//			printf("hehe signum:%d\n", signum);
//			break;
//		case 9: //无法被捕捉
//			printf("haha signum:%d\n", signum);
//			break;
//		case 14: 
//			printf("hello alarm signum:%d\n", signum);
//			break;
//		default:
//			printf("default signum:%d\n", signum);
//			break;
//	}
//	exit(1);
//}

//int main()
//{
//	int signum = 1;
//	while (signum < 32) {
//		signal(signum, handler);
//		signum++;
//	}
//	//abort();
//	//raise(8);
//	
//	//printf("hello alarm by 10 seconds\n");
//	//size_t ret = alarm(10);
//	//while (1) {
//	//	printf("hello proc:%d, alarm ret:%ld\n", getpid(), ret);
//	//	sleep(1);
//	//	size_t res = alarm(5); //取消闹钟，并打印剩余时间
//	//	printf("alarm res:%ld\n", res);
//	//}
//
//	size_t ret = alarm(10);
//	sleep(2);
//	printf("alarm(10)->ret:%ld\n", ret);
//
//	ret = alarm(5); //重新设置闹钟，并返回上一个闹钟的剩余时间
//	//如果没有之前没有设置过闹钟，则返回0
//	printf("alarm(5) ->ret:%ld\n", ret);
//
//
//	return 0;
//}

//int main()
//{
//	if (fork() == 0) {
//		printf("hello raise\n");
//		abort();
//	}
//	int status = 0;
//	waitpid(-1, &status, 0);
//	printf("exit code:%d\n", (status >> 8) & 0xff);
//	printf("exit signal:%d\n", status & 0x7f);
//	return 0;
//}

// ./test signum pid
//int main(int argc, char* argv[])
//{
//	if (argc != 3) {
//		printf("Usage\n\t./test signum pid\n");
//		exit(1);
//	}
//	int signum = atoi(argv[1]);
//	int pid = atoi(argv[2]);
//
//	kill(pid, signum);
//	printf("kill -%d %d\n", signum, pid);
//
//	return 0;
//}


//int main()
//{
//	signal(11, handler);
//	//注册所有信号
//	//int sig = 1;
//	//while (sig <= 31) {
//	//	signal(sig, handler);
//	//	sig++;
//	//}
//	
//	//int a = 100;
//	//a /= 0;
//
//	//int *p = NULL;
//	//p = (int*)100;
//	//*p = 100;
//	
//	if (fork() == 0) {
//		while (1) {
//			printf("hello proc:%d\n", getpid());
//			sleep(1);
//		}
//		exit(1);
//	}
//	int status = 0;
//	waitpid(-1, &status, 0);
//	printf("exit code:%d\n", (status >> 8) & 0xff);
//	printf("exit signal:%d\n", status & 0x7f);
//	printf("core dump:%d\n", (status >> 7) & 1);
//
//
//	
//	return 0;
//}


//int main()
//{
//	//通过signal注册对2号信号的处理动作
//	signal(2, handler);
//	while (1) {
//		printf("hello proc:%d\n", getpid());
//		sleep(1);
//	}
//	return 0;
//}
