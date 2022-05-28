#include "comm.h"
int main()
{	
	int fd = open(MY_FIFO, O_WRONLY);
	if (fd < 0) {
		perror("client open fail:");
		exit(1);
	}
	//业务逻辑
	//const char* msg = "hello server";
	//while (1) {
	//	write(fd, msg, strlen(msg));
	//	sleep(1);
	//}
	while (1) {
		char buff[64] = { 0 };
		ssize_t s = read(0, buff, sizeof(buff) - 1);
		buff[s - 1] = 0;
		printf("%s\n", buff);
		write(fd, buff, strlen(buff));
	}
	close(fd);

	return 0;
}
