#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void handler(int signum) {
	while (1) {
		printf("hello signum:%d\n", signum);
		sleep(1);
	}
}

int main()
{
	struct sigaction  act;
	struct sigaction oact;

	memset( &act, 0,  sizeof(act));
	memset(&oact, 0, sizeof(oact));

	act.sa_handler = handler;
	//act.sa_handler = SIG_IGN;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, 2);
	sigaction(2, &act, &oact);

	while (1) {
		printf("hello world\n");
		sleep(1);
	}

	return 0;
}


//
//void show(sigset_t* set) {
//	printf("pending->");
//	int i = 0;
//	for (i = 1; i < 32; i++) {
//		printf("%d", sigismember(set, i));
//	}
//	printf("\n");
//
//}
//
//int main()
//{
//	signal(SIGINT, handler);
//	sigset_t set;
//	sigset_t oset;
//
//	sigemptyset(&set);
//	sigemptyset(&oset);
//
//	sigaddset(&set, 2);
//	sigaddset(&set, 3);
//	sigaddset(&set, 4);
//
//	sigprocmask(SIG_SETMASK, &set, &oset);
//	printf("2) 3) 4) is blocked\n");
//
//	int cnt = 15;
//	while (1) {
//		sigpending(&set);
//
//		show(&set);
//
//		if (cnt-- == 0) {
//			printf("2) SIGINT is unblocked\n");
//			sigprocmask(SIG_SETMASK, &oset, NULL); //解除2号信号的阻塞
//		}
//		sigemptyset(&set);
//		sleep(1);
//	}
//
//	return 0;
//}


//int main() 
//{
//	sigset_t set;
//	sigset_t oset;
//	 
//	sigemptyset(&set);	
//	sigemptyset(&oset);	
//
//	sigaddset(&set, 2);
//	sigaddset(&set, 3);
//	sigaddset(&set, 9); //Err
//	
//	sigprocmask(SIG_BLOCK, &set, &oset);
//
//	while (1) {
//		printf("hello block\n");
//		sleep(1);
//	}
//
//	return 0;
//}
