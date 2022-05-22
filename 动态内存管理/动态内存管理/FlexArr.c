#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//C/C++内存划分

//int globalVar = 1;
//static int staticGlobalVar = 1;
//int main() {
//	static int staticVar = 1;
//	
//	int localVar = 1;
//	int num1[10] = { 1,2,3,4 };
//	char char2[] = "abcd";
//	char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(4 * sizeof(int));
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, 4 * sizeof(int));
//
//	free(ptr1);
//	free(ptr3);
//	return 0;
//}
//


//柔性数组的定义

//struct st_type {
//	char c;
//	char d[];//柔性数组成员
//};
//struct st_type {
//	int i;
//	int a[0];
//};

//柔性数组的使用

//struct st_type {
//	int i;
//	int a[0];
//};
//int main()
//{
//	//printf("%d\n", sizeof(struct st_type));
//	//1.
//	struct st_type st;//Err
//	//2.
//	struct st_type* pst = (struct st_type*)malloc(sizeof(struct st_type) + 10 * sizeof(int));
//	//开辟失败
//	if (pst == NULL) {
//		perror("pst");
//		return -1;
//	}
//	//开辟成功
//	pst->i = 10;
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", pst->a[i] = i);
//	}
//	//调整空间大小
//	struct st_type* ptr = (struct st_type*)realloc(pst, sizeof(struct st_type) + 20 * sizeof(int));
//	if (ptr == NULL) {
//		perror("ptr");
//		return -1;
//	}
//	pst = ptr;
//	for (int i = 10; i < 20; i++) {
//		printf("%d ", pst->a[i] = i);
//	}
//	//释放
//	free(pst);
//	pst = NULL;
//	
//	return 0;
//}

//柔性数组的优势


//struct st_type {
//	int i;
//	int* pa;
//};
//
//int main()
//{
//	struct st_type* pst = (struct st_type*)malloc(sizeof(struct st_type));
//	pst->i = 100;
//	pst->pa = (int*)malloc(10 * sizeof(int));
//	if (pst->pa == NULL) {
//		perror("pa");
//		return -1;
//	}
//	
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", *(pst->pa + i) = i);
//	}
//	int* ptr = (int*)realloc(pst->pa, 20 * sizeof(int));
//	if (ptr == NULL) {
//		perror("ptr");
//		return -1;
//	}
//	pst->pa = ptr;
//	for (int i = 10; i < 20; i++) {
//		printf("%d ", *(pst->pa + i) = i);
//	}
//	free(pst);
//	pst = NULL;
//	free(pst->pa);
//	pst->pa = NULL;
//
//	return 0;
//}
