#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	pid_t id = fork();
	if (id == 0) { //child
		int cnt = 3;
		while (cnt--) {
			printf("child proccess[%d] running, cnt:%d\n", getpid(), cnt);
			sleep(1);
		}
		//int a = 10;
		//a /= 0;
		exit(0);
	}
	//parent 
	//此处父进程不进行等待会直接退出，子进程就是僵尸进程
	//sleep(10);
	printf("parent waiting\n");
	//pid_t ret = wait(NULL);
	
	//pid_t ret = waitpid(id, NULL, 0); // id - 等待指定进程
	
	//pid_t ret = waitpid(-1, NULL, 0); // -1 - 等待任意某个进程
	
	int status = 0;
	//0 - 阻塞等待
	//pid_t ret = waitpid(id, &status, 0);       
	//if (ret > 0) { 
	//	//判断进程是否正常终止
	//	if (WIFEXITED(status)) {
	//		printf("exit code:%d\n", WEXITSTATUS(status)); //返回进程退出码
	//	} 
	//	else {
	//		printf("get a signal\n");	
	//	}
	//}
	//if (ret > 0) {
	//	printf("parent proccess wait[%d] seccess\n, status exit code:%d, status exit signal:%d\n", \
	//			ret, (status >> 8) & 0xff, status & 0x7f);
	//								FEDC BA98   7654 3210
	//										  |
	// status - 1111 1111 1111 1111 1111 1111 | 1111 1111
	// 0xff                         1111 1111 |     
	// ox3f                                     0111 1111 
    //}
    //else {
    //	  printf("parent proccess wait failed\n");
    //}
	//sleep(10);
	
	//WNOHANG - 非阻塞等待
 	while (1) {
		pid_t ret = waitpid(id, &status, WNOHANG); 
    	if (ret == 0) { // 子进程并未结束
			printf("parent do their things\n");
    	}
    	else if (ret > 0) { // 子进程退出成功
			printf("parent proccess wait[%d] seccess, status exit code:%d, status exit signal:%d\n", \
			ret, (status >> 8) & 0xff, status & 0x7f);
			break;
    	}
    	else { // 等待失败
			printf("parent wait failed\n"); 
			break;
    	}
		sleep(1);
	}
}
//int func() 
//{
//	exit(10);
//	printf("func()\n");
//
//	return 1;
//}
//int main()
//{
//	printf("hello world");
//
//	sleep(4);
//
//	_exit(20);
//
//	exit(EXIT_SUCCESS);
//	func();

//	int a  = 10;
//	a /= 0;	

//	for (int i = 0; i < 140; i++) {
//		printf("strerror[%d]->%s\n", i, strerror(i));
//	}
//
//
//	return 0;
//}
