#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
* 常见的动态内存错误
* */

//extern void test();
//int main()
//{
//	test();
//	return 0;
//}

//1. 不检查野指针

//void test() {
//	int* p = (int*)malloc(INT_MAX / 4);
//	if (p == NULL) {
//		return;
//	}
//	*p = 20;
//	free(p);
//}

//2. 越界访问

//void test() {
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p) {
//		exit(EXIT_FAILURE);
//	}
//	for (int i = 0; i <= 10; i++) {
//		*(p + i) = i;
//	}
//	free(p);
//	p = NULL;
//}

//3. 释放非开辟内存

//void test() {
//	int a = 10;
//	int* p = &a;
//	free(p);
//	p = NULL;
//}

//4. 改变内存指针

//int main()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);
//
//	return 0;
//}
 
//5. 重复释放内存

//void test() {
//	int* p = (int*)malloc(100);
//	free(p);
//	free(p);
//}

//6. 内存泄漏

//void test() {
//    int* p = (int*)malloc(100);
//    if (NULL != p) {
//        *p = 20;
//    }
//}
//int main() {
//    test();
//    while (1);
//}
