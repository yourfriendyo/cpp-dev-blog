#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main() 
{

	int fd = open("./log.txt", O_WRONLY | O_CREAT, 0664);
	if (fd < 0) {
		printf("file open failed");

	}
	printf("file descript:%d\n", fd);

	int fd1 = open("./log.txt", O_WRONLY | O_CREAT, 0664);
	printf("file descript:%d\n", fd1);
	int fd2 = open("./log.txt", O_WRONLY | O_CREAT, 0664);
	printf("file descript:%d\n", fd2);
	int fd3 = open("./log.txt", O_WRONLY | O_CREAT, 0664);
	printf("file descript:%d\n", fd3);

	close(fd);
	return 0;
}

//int main() 
//{
//
//	const char* msg = "hello stdout\n";
//	fputs(msg, stderr);
//
//	const char* msg = "hello stdout\n";
//	fputs(msg, stdout);
//	
//	FILE* fp = fopen("./log.txt", "a");
//	if (fp == NULL) {
//		printf("fp error\n");
//		exit(1);
//	}
//	int cnt = 5;
//	while (cnt--) {
//		fputs("hello log.txt\n", fp);
//	}
//	fclose(fp);
//
//
//	FILE* fp = fopen("./log.txt", "r");
//	if (fp == NULL) {
//		printf("fp error\n");
//		exit(1);		
//	}
//	char buffer[64] = { 0 };
//
//	fread(buffer, sizeof(buffer), 1, fp);  //文件指针不移动，下次读取仍在首行
//	
//	fscanf(fp, "%s\n", buffer); //文件指针移动但无法读取空格
//	
//	while (fgets(buffer, sizeof(buffer), fp)) 
//	{
//		printf("%s\n", buffer);
//	}
//
//	if (!feof(fp)) {
//		printf("fgets quit not normal\n");
//	}
//	else {
//		printf("reach endoffile\n");
//	}
//	fclose(fp);
//
//	FILE* fp = fopen("./log.txt", "w");
//	
//	if (fp == NULL) {
//		printf("fp error\n");
//	}
//	const char* msg = "hello log.txt\n";
//
//	fputs(msg, fp);
//
//	fprintf(fp, "hello log.txt\n");
//
//	fwrite(msg, 15, 1, fp);
//
//	fclose(fp);
//	
//	return 0;
//
//}
