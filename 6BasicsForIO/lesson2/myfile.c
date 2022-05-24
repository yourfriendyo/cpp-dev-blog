#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	close(1);
	int fd = open("./log.txt", O_CREAT | O_WRONLY, 0664);
	printf("fd:%d\n", fd);

	fprintf(stdout, "hello world\n");
	fprintf(stdout, "hello world\n");
	fprintf(stdout, "hello world\n");
	fprintf(stdout, "hello world\n");

	close(fd);
	
	return 0;
}
//int main()
//{
//	int fd = open("./log.txt", O_RDONLY);
//	if (fd < 0)
//	{
//		return 1;
//	}
//	dup2(fd, 0);
//	char buff[64] = { 0  };
//
//	scanf("%s", buff);
//	printf("%s\n", buff);
//
//	fscanf(stdin, "%s", buff);
//	printf("%s\n", buff);
//
//	fgets(buff, sizeof(buff) - 1, stdin);
//	printf("%s\n", buff);
//
//	return 0;
//}


//int main()
//{
//	int fd = open("./log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
//	if (fd < 0) {
//		perror("open");
//		exit(1);
//	}
//	dup2(fd, 1);
//	
//	printf("hello world\n");
//	fprintf(stdout, "hello world\n");
//	fputs("hello world\n", stdout);
//
//	return 0;
//}

//int main() 
//{
//	printf("stdin ->fd:%d\n", stdin->_fileno);
//	printf("stdout->fd:%d\n", stdout->_fileno);
//	printf("stderr->fd:%d\n", stderr->_fileno);
//
//	FILE* fp = fopen("./log.txt", "w");
//
//	printf("./log.txt->fd:%d\n", fp->_fileno);
//
//	return 0;
//}

//int main()
//{
//	close(0);
//	int fd = open("./log.txt", O_RDONLY);
//	printf("fd:%d\n", fd); //fd=0
//
//	char buff[1024] = { 0  };
//	while (fgets(buff, sizeof(buff) - 1, stdin)) {
//		printf("%s", buff);
//	}
//
//	return 0;
//}

//int main()
//{
//	close(1);
//	int fd = open("./log.txt", O_CREAT | O_WRONLY |  O_APPEND, 0664);
//	printf("fd:%d\n", fd);
//
//	fprintf(stdout, "hello world\n");
//	fprintf(stdout, "hello world\n");
//	fprintf(stdout, "hello world\n");
//	fprintf(stdout, "hello world\n");
//	
//	return 0;
//}
//int main()
//{
//	close(1);
//	int fd = open("./log.txt", O_CREAT| O_WRONLY, 0664);
//	printf("%d\n", fd);
//
//	fprintf(stdout, "hello world\n");
//	fprintf(stdout, "hello world\n");
//	fprintf(stdout, "hello world\n");
//	fprintf(stdout, "hello world\n");
//	fprintf(stdout, "hello world\n");
//	fprintf(stdout, "hello world\n");
//
//	return 0;
//}

//int main() 
//{
//	const char* msg = "hello world\n";
//
//	write(1, msg, strlen(msg));
//	write(2, msg, strlen(msg));
//
//	char buff[64] = { 0 };
//	read(0, buff, sizeof(buff) - 1);
//	printf("echo: %s", buff);
//
//	return 0;
//}
//int main()
//{
//	int fd = open("./log.txt", O_WRONLY | O_CREAT, 0664);
//	if (fd < 0) {
//		perror("open fail\n");
//		exit(1);
//	}
//
//	const char* msg = "hello log.txt\n";
//	int ret = write(fd, msg, strlen(msg));
//	printf("ret:%d\n", ret);
//	
//	close(fd);
//	return 0;
//}

//int main() 
//{
//	int fd = open("./log.txt", O_RDONLY);
//	if (fd < 0) {
//		perror("open fail\n");
//	}
//
//	char buff[1024]; // { 0 };
//	int ret = read(fd, buff, sizeof(buff) - 1);
//
//	if (ret > 0) {
//		buff[ret - 1] = 0;
//		printf("ret:%d\n", ret);
//	}
//	printf("%s\n", buff);
//	close(fd);
//	return 0;
//}
