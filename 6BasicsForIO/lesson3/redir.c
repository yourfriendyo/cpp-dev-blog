#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	FILE* fp = fopen("./log.txt", "w");


	fprintf(fp, "hello fprintf\n");

	fclose(fp);

	return 0;
}

int main()
{
	//系统调用
	const char* msg1 = "hello 标准输出\n";
	write(1, msg1, strlen(msg1));

	//C库函数
	printf("hello printf\n");
	fputs("hello fputs\n", stdout);
	fprintf(stdout, "hello fprintf\n");

	fflush(stdout);
	
	fork();

	return 0;
}

int main()
{
	close(1);

	int fd = open("./log.txt", O_WRONLY | O_CREAT, 0664);
	printf("fd:%d\n", fd);
	
	printf("hello printf\n");
	fprintf(stdout, "hello printf\n");

	fflush(stdout); //手动刷新

	close(fd); //关闭文件

	return 0;
}




