#include "comm.h"
int main()
{
	/* get */
	key_t key = ftok(PATH_NAME, PROJECT_ID);
	if (key < 0) {
		perror("client ftok failed:");
		exit(1);
	}

	int shmid = shmget(key, SIZE, IPC_CREAT);
	if (shmid < 0) {
		perror("client shmget failed");
		exit(1);
	}
	printf("key:0x%u, shmid:%d, client shmget success\n", key, shmid);
	//sleep(5);
	
	/* attch */	
	char* addr = (char*)shmat(shmid, NULL, 0);
	printf("client attch success\n");
	//sleep(5);

	//业务逻辑
	char ch  = 'A';
	while (ch <= 'Z') {
		addr[ch - 'A'] = ch;
		ch++;
		addr[ch - 'A'] = 0;
		sleep(1);
	}
	

	/* dettch */
	shmdt(addr);
	printf("client detach success\n");
	sleep(5);


	return 0;
}
