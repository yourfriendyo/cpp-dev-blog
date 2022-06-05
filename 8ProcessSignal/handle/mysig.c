#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

//子进程退出时会向父进程发送SIGCHLD信号，默认动作是忽略
void handler(int signum) {
	//waitpid()
	printf("hello signum:%d\n", signum);
}
int main()
{
	//signal(SIGCHLD, handler);
	signal(SIGCHLD, SIG_IGN); 
	//显式对SIGCHLD注册忽略动作，可自动回收子进程
	
	if (fork() == 0) {
		int cnt = 10;
		while (cnt--) {
			printf("child proc:%d\n", getpid());
			sleep(1);
		}
		exit(0);
	}
	while (1) {
		;
	}

	return 0;
}

//volatile int flag = 0; //volatile拒绝将变量优化到寄存器中
//
//void handler(int signum) {
//	flag = 1;
//	printf("change flag 0 -> 1\n");
//}
//
//int main()
//{
//	signal(2, handler);
//	//编译器检测到flag 所在执行流中没有被修改，故将flag 优化到寄存器中	
//	//内存中的flag在其他执行流中被修改，但CPU只访问寄存器中的flag
//	while (!flag) { 
//		;
//	}
//	printf("proc exited success\n");
//
//	return 0;
//}
