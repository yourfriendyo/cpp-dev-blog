#include "comm.h"
int main()
{
	/* get */	
	key_t key = ftok(PATH_NAME, PROJECT_ID);	
	if (key < 0) {
		perror("server ftok fail");
	}
	printf("key:0x%u, ", key);

	int shmid = shmget(key, SIZE, IPC_CREAT | IPC_EXCL | 0666);
	if (shmid < 0) {
		perror("server shmget fail:");
		exit(1);
	}
	printf("shmid:%d\n", shmid);
	//sleep(5);

	/* attch */
	char* addr = (char*)shmat(shmid, NULL, 0);
	printf("shm attched success\n");
	//sleep(5);

	//业务逻辑
	while (1) {
		printf("addr-> %s\n", addr);
	}
	/* detach */
	shmdt(addr);
	printf("shm detached success\n");
	//sleep(5);

	/* control */
	shmctl(shmid, IPC_RMID, NULL);
	printf("key:0x%u, shmid:%d, shm has been deleted\n", key, shmid);
	//sleep(5);

	return 0;
}
