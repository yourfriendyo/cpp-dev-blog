#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int noinit_val;
int inited_val = 0;

int main(int argc, char* argv[], char* env[])
{
	int local = 0;
	printf("  code addr -> %p\n", main);
	printf("string addr -> %p\n", "hello world");
	printf("inited addr -> %p\n", &inited_val);
	printf("noinit addr -> %p\n", &noinit_val);
	printf("  heap addr -> %p\n", malloc(1));
	printf(" stack addr -> %p\n", &local);

	for (int i = 0; argv[i]; i++) {
		printf("   argv[%d] -> %p\n", i, argv[i]);
	}

	for (int i = 0; env[i]; i++) {
		printf("    env[%d] -> %p\n", i, env[i]);
	}
	
	return 0;
}



//int g_val = 0;
//int main()
//{
//	if (fork() == 0) { //child
//
//		int cnt = 5;
//		while (cnt--) {
//			printf("I am  child proc, g_val=%d, &g_val=%p, times:%d\n", g_val, &g_val, cnt);
//			sleep(1);
//			if (cnt == 3) {
//				printf("################ child change g_val ###################\n");
//				g_val = 2;
//				printf("################ g_val changed done ###################\n");
//			}
//		} 
//		exit(0);
//	}
//	//parent
//	while (1) {
//		printf("I am parent proc, g_val=%d, &g_val=%p\n",g_val, &g_val);
//		sleep(1);
//	}
//	
//	return 0;
//}

//int noinit; 
//int inited = 0;
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	printf("stack_a addr -> %p\n", &a);
//	printf("stack_b addr -> %p\n", &b);
//	printf("stack_c addr -> %p\n", &c);
//	printf("stack_d addr -> %p\n", &d);
//
//	printf(" heap_a addr -> %p\n", malloc(10));
//	printf(" heap_b addr -> %p\n", malloc(10));
//	printf(" heap_c addr -> %p\n", malloc(10));
//	printf(" heap_d addr -> %p\n", malloc(10));
//
//	printf("noited addr -> %p\n", &noinit);
//	printf("inited addr -> %p\n", &inited);
//	printf("string addr -> %p\n", "hello");
//	printf("  code addr -> %p\n", main);
//
//}

