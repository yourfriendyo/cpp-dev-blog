#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() 
{
	printf("hello myexe\n");
	extern char** environ;

	for (int i = 0; environ[i]; i++) 
	{
		printf("%s\n", environ[i]);
	}

	return 0;
}

//int main() 
//{
//	if (fork() == 0) { //child -- 进行程序替换
//		//exec*
//		execl("/usr/bin/ls", "ls", "-a", "-l", NULL);
//		exit(1);
//	}
//	//parent -- 等待子进程
//	waitpid(-1, NULL, 0);
//	printf("parent proc waited success\n");
//
//}

//int main() 
//{
//	//execl("/usr/bin/top", "top", NULL);
//	int ret = execl("/usr/bin/lss", "ls", "-al", NULL);
//	printf("%d\n", ret);
//
//	printf("there is something\n");
//	printf("there is something\n");
//	printf("there is something\n");
//	printf("there is something\n");
//}


//int main() 
//{
//	printf("proccess[%d] is running\n", getpid());
//
//	//execl("/usr/bin/ls", "ls", "-al", NULL);
//	//execl("/usr/bin/top", "top", NULL);
//
//	sleep(1);
//
//	pid_t id = fork();
//	if (id == 0) {
//		execl("/usr/bin/ls", "ls", "-al", NULL);
//		exit(0);
//	}
//
//	waitpid(id, NULL, 0);
//
//	printf("there is something\n");
//	printf("there is something\n");
//	printf("there is something\n");
//	printf("there is something\n");
//	
//
//	
//	return 0;
//}

