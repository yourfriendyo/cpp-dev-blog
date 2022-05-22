#define _CRT_SECURE_NO_WARNINGS 1
/*
* ±  ‘Ã‚
* */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//int main()
//{
//	test();
//
//	return 0;
//}

//1. 

//void GetMemory(char* p) {
//	p = (char*)malloc(100);
//}
//void test() {
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}

//∏ƒ’˝
//void GetMemory(char** p) {
//	*p = (char*)malloc(100);
//}
//void test() {
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//}

//2.

//char* GetMemory() {
//	char p[] = "hello world";
//	return p;
//}
//
//void test() {
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}

//3.

//void GetMemory(char** p,int num) {
//	*p = (char*)malloc(num);
//}
//void test() {
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//
//}

//4.

//void test(void) {
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL) {
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//

