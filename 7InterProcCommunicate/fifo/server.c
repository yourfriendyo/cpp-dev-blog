#include "comm.h"
int main()
{
	umask(0);
	if (mkfifo(MY_FIFO, 0666) < 0) {
		perror("server mkfifo fail:");
		exit(1);
	}
	//文件操作	
	//server 读取端
	int fd = open(MY_FIFO, O_RDONLY);
	if (fd < 0) {
		perror("server open fail:");
		exit(1);
	}
	//业务逻辑
	char buff[64] = { 0 };
	while (1) {
		sleep(50);
		ssize_t s = read(fd, buff, sizeof(buff) - 1);
		if (s > 0) {
			buff[s] = 0;
			printf("client requst: %s\n", buff);
			if (strcmp(buff, "ll") == 0) {
				if (fork() == 0) {
					execlp("ls", "ls", "-l", NULL);
					exit(1);
				}
				waitpid(-1, NULL, 0);
			}
			else if (strcmp(buff, "pwd") == 0) {
				if (fork() == 0) {
					execlp("pwd", "pwd", NULL);
					exit(1);
				}
				waitpid(-1, NULL, 0);
			}
			else if (strcmp(buff, "clear") == 0) {
				if (fork() == 0) {
					execlp("clear", "clear", NULL);
					exit(1);
				}
				waitpid(-1, NULL, 0);
			}
		}
		else if (s == 0) {
			printf("client quit..\n");
			sleep(1);
		}
		else {
			printf("client closed\n");
			break;
		}
	}
	close(fd);

	return 0;
}
