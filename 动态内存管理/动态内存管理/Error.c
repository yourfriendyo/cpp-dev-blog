#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
* �����Ķ�̬�ڴ����
* */

//extern void test();
//int main()
//{
//	test();
//	return 0;
//}

//1. �����Ұָ��

//void test() {
//	int* p = (int*)malloc(INT_MAX / 4);
//	if (p == NULL) {
//		return;
//	}
//	*p = 20;
//	free(p);
//}

//2. Խ�����

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

//3. �ͷŷǿ����ڴ�

//void test() {
//	int a = 10;
//	int* p = &a;
//	free(p);
//	p = NULL;
//}

//4. �ı��ڴ�ָ��

//int main()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);
//
//	return 0;
//}
 
//5. �ظ��ͷ��ڴ�

//void test() {
//	int* p = (int*)malloc(100);
//	free(p);
//	free(p);
//}

//6. �ڴ�й©

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
