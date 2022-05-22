#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() 
{

	if (fork() == 0) {
		/* exec* */

		//execl && execv
		//execl("/usr/bin/ls"/**/, "ls", "-a", "-b", "-l"/**/, NULL);	
		//
		//char* const argv[] = {
		//	"ls",
		//	"-a",
		//	"-b",
		//	"-l",
		//	NULL
		//};
		//execv("/usr/bin/ls"/**/, argv);
		
		//execl && execlp
		//execl("/usr/bin/ls"/**/, "ls", "-a", "-b", "-l"/**/, NULL);	
		//
		//execlp("ls"/**/, "ls", "-a", "-b", "-l"/**/, NULL);
		
		//execlp && execvp		
		//execlp("ls"/**/, "ls", "-a", "-b", "-l"/**/, NULL);
		//
		//char* const argv[] = {
		//	"ls",
		//	"-a",
		//	"-b",
		//	"-l",
		//	NULL
		//};
		//execvp("ls"/**/, argv);
		
		//printf("hello exec* -> ");
		//fflush(stdout);
		//execl("./myexe", "myexe", NULL);

		//execle && execve
		//char* env[] = {
		//	"myenv1=hehe",
		//	"myenv2=haha",
		//	NULL
		//};
		//char* argv[] = {
		//	"myexe", 
		//	NULL
		//};
		//execle("./myexe"/**/, "myexe"/**/, NULL, env);
		//execve("./myexe", argv, env);
		
		execl("/usr/bin/python3", "python", "test.py", NULL);
		printf("error\n");
		exit(-1);
	}

	waitpid(-1, NULL, 0);
	printf("parent proc waited success\n");

	return 0;
}
