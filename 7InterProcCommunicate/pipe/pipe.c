#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>



//int main()
//{
//	int pipefd[2] = { 0 };
//	if (pipe(pipefd) != 0) {
//		perror("pipe failed\n");
//	}
//	if (fork() == 0) {
//		close(pipefd[0]);
//		while (1) {
//			write(pipefd[1], "hello wrold", 11);
//		}
//		exit(0);
//	}
//	close(pipefd[1]);
//	while (1) {
//		sleep(10);
//		char buff[64] = { 0 };
//		ssize_t s = read(pipefd[0], buff, sizeof(buff) - 1);
//		if (s == 0) {
//			printf("read finished\n");
//			break;
//		}
//		else if (s > 0) {
//			printf("child write:%s\n", buff);
//			break;
//		}
//		else {
//			printf("read failed\n");
//			break;
//		}
//	}
//	close(pipefd[0]);
//	int status = 0;
//	waitpid(-1, &status, 0);
//	printf("exit code: %d, exit sigal:%d\n", \
//			(status >> 8) & 0xff, status & 0x7f);
//
//	printf("write closed\n");
//	return 0;
//}

//int main()
//{
//	int pipefd[2] = { 0 };
//	if (pipe(pipefd) != 0) {
//		perror("pipe failed\n");
//	}
//	if (fork() == 0) {
//		close(pipefd[0]);
//		while (1) {
//			write(pipefd[1], "hello wrold", 11);
//			break;
//		}
//		sleep(5);
//		close(pipefd[1]);
//		exit(0);
//	}
//	close(pipefd[1]);
//	while (1) {
//		char buff[64] = { 0 };
//		ssize_t s = read(pipefd[0], buff, sizeof(buff) - 1);
//		if (s == 0) {
//			printf("read finished\n");
//			break;
//		}
//		else if (s > 0) {
//			printf("child write:%s\n", buff);
//		}
//		else {
//			printf("read failed\n");
//			break;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int pipefd[2] = { 0 };
//	if (pipe(pipefd) != 0) {
//		perror("pipe failed\n");
//	}
//	if (fork() == 0) {
//		close(pipefd[0]);
//		sleep(10);
//		exit(0);
//	}
//	close(pipefd[1]);
//	while (1) {
//		char buff[64] = { 0 };
//		ssize_t s = read(pipefd[0], buff, sizeof(buff) - 1);
//		if (s == 0) {
//			printf("read finished\n");
//			break;
//		}
//		else if (s > 0) {
//			printf("child write:%c\n", *buff);
//		}
//		else {
//			printf("read failed\n");
//			break;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int pipefd[2] = { 0 };
//	if (pipe(pipefd) != 0) {
//		perror("pipe failed\n");
//	}
//	if (fork() == 0) {
//		close(pipefd[0]);
//		int cnt = 0;
//		while (1) {
//			write(pipefd[1], "a", 1);
//			printf("cnt:%d\n", cnt++);
//		}
//		exit(0);
//	}
//	close(pipefd[1]);
//	while (1) {
//		sleep(10);
//		char buff[1024 * 4 + 1] = { 0 };
//		ssize_t s = read(pipefd[0], buff, sizeof(buff) - 1);
//		if (s == 0) {
//			printf("read finished\n");
//			break;
//		}
//		else if (s > 0) {
//			printf("child write:%c\n", *buff);
//		}
//		else {
//			printf("read failed\n");
//			break;
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int pipefd[2] = { 0 };
//	if (fork() == 0) {
//		//child 子进程写
//		close(pipefd[0]); //关读	
//		const char* msg = "hello world";
//		while (1) {
//			write(pipefd[1], msg, strlen(msg));
//		//	sleep(1);
//		}
//		exit(0);
//	}
//	//parent 父进程读
//	close(pipefd[1]); //关写
//	while (1) {
//		sleep(1);
//		char buff[64] = { 0 };
//		ssize_t ret = read(pipefd[0], buff, sizeof(buff) - 1);
//		if (ret >= 0) {
//			printf("child write:%s\n", buff);
//		}
//		else if (ret == 0) {
//			printf("read finished\n");
//			break;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int pipefd[2] = { 0 };
//	if (pipe(pipefd) != 0) {
//		perror("pipe fail:");
//	}
//	//目的：子进程写，父进程读
//	if (fork() == 0) {
//		//child
//		close(pipefd[0]); //关读	
//		const char* msg = "hello world";
//		while (1) {
//			write(pipefd[1], msg, strlen(msg));
//		//	sleep(1);
//		}
//		exit(0);
//	}
//	//parent
//	close(pipefd[1]); //关写
//	while (1) {
//		sleep(1);
//		char buff[64] = { 0 };
//		ssize_t ret = read(pipefd[0], buff, sizeof(buff) - 1);
//		if (ret >= 0) {
//			printf("child write:%s\n", buff);
//		}
//		else if (ret == 0) {
//			printf("read finished\n");
//			break;
//		}
//		else {
//			printf("read failed\n");
//			break;
//		}
//	}
//
//	return 0;
//}
