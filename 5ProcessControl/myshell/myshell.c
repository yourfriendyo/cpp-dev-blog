#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define CMD_NUM 128
#define ARGV_NUM 64
int main()
{
	char cmd[CMD_NUM]; 
	while (1) {
		cmd[0] =  0;
		//1. 打印提示符
    	printf("[who@HostName mydir]# ");
		fflush(stdout);

    	//2. 获取命令行参数 "ls -a -b -l -n\n\0"
		fgets(cmd, CMD_NUM, stdin);		
		cmd[strlen(cmd) - 1] = '\0'; // 处理fgets读取回车的问题
		//pri1ntf("echo: %s\n", cmd);
		
    	//3. 截取字符串
    	char* argv[ARGV_NUM] = { NULL };

		argv[0] = strtok(cmd, " ");
		//"\0"
		if (argv[0] == 0) { //处理空串的问题
			continue;
		}
		int i = 1;
		while (argv[i] = strtok(NULL, " ")) {
			i++;
		}

		//for (int i = 0; argv[i] != NULL; i++) {
		//	printf("argv[%d]->%s\n", i, argv[i]);
		//}
	
    	//4. 检测内建命令
		if (strcmp(argv[0], "cd") == 0) {
			if (argv[1] != NULL) {
				chdir(argv[1]);
			}
			continue;
		}

    	//5. 执行第三方命令
		if (fork() == 0) {
			execvp(argv[0], argv);
			exit(1);
		}	

    	//6. 获取退出码
		int status = 0;
		pid_t ret = waitpid(-1, &status, 0);
		if (ret > 0) {
			printf("exit code:%d, exit signal:%d\n", \
					(status >> 8) & 0xff, status & 0x7f);
		}
		else {
			printf("wait failed\n")
		}
	}
	return 0;
}
