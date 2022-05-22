#define _CRT_SECURE_NO_WARNINGS 1
/* 
* 动态内存函数的介绍
* 1. malloc
* 2. free
* 3. calloc
* 4. realloc
* */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//malloc&free

//int main()
//{
//	//申请空间
//	int* p = (int*)malloc(40);
//	//开辟失败
//	if (p == NULL) {
//		printf("%s\n", strerror(errno));
//		return -1;
//	}
//	//开辟成功
//	for (int i = 0; i < 10; i++) {
//		*(p + i) = i;
//		printf("%d ", *(p + i));
//	}
//	//释放空间 
//	free(p);
//	//置空
//	p = NULL;
//
//	return 0;
//}

//calloc&realloc

//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL) {
//		perror("");
//		return -1;
//	}
//	for (int i = 0; i < 10; i++) {
//		*(p + i) = i;
//		printf("%d ", p[i]);
//	}
//	//p = (int*)realloc(p, 20 * sizeof(int));
//	int* ptr = (int*)realloc(p, 20 * sizeof(int));
//	if (ptr == NULL) {
//		return -1;
//	}
//	p = ptr;
//	for (int i = 10; i < 20; i++) {
//		*(p + i) = i;
//		printf("%d ", p[i]);
//	}
//
//
//
//
//	free(p);
//	p = NULL;
//
//
//	return 0;
//}

