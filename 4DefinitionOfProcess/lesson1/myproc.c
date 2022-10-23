#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
//	FILE* fp = fopen("log.txt","w");
//	fclose(fp);
	fork();
	while (1) {
		printf("hello pid:%d, ppid:%d\n", getpid(), getppid());
		sleep(1);
	}

//	int ret = fork();
//	if (ret > 0) {
//		printf("hello world\n");
//	}
//	else {
//		printf("hello else proc\n");
//	}
	sleep(1);

//	while (1) {
//		printf("hello process pid:%d, ppid:%d\n", getpid(), getppid());
//		sleep(1);
//	}	
//	printf("hello world\n");
  
	return 110; // 退出码
}
