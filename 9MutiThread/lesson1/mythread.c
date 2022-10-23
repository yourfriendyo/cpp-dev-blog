#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
void* thread_run(void* args)
{
	const char* id = (char*)args;

	while (1)
	{
		printf("I am [%s] thread, pid:%d\n", id, getpid());
		sleep(1);
	}

	return (void*)"111";
}
int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, thread_run, (void*)"1");
	
	while (1)
	{
		printf("I am mainthread, pid:%d\n", getpid());
		sleep(1);
	}
	return 0;
}
