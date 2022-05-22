#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
* 3. 联合（共用体）
* 联合的定义
* 联合的特点
* 联合大小的计算
* */

//联合的定义

//union Un {
//	char c;//1
//	int i;//4
//};

//int main()
//{
//	union Un u = { 0 };
//	//printf("%d\n", sizeof(union Un));
//	//printf("%d\n", sizeof(u));
//
//	printf("%p\n", &u);//00EFF934
//	printf("%p\n", &u.c);//00EFF934
//	printf("%p\n", &u.i);//00EFF934
//
//	return 0;
//}

//联合的特点

//int main()
//{
//	int  a = 1;
//	char* pc = (char*)&a;
//	if (*pc == 1) {
//		printf("小端存储\n");
//	}
//	else {
//		printf("大端存储\n");
//	}
//
//	return 0;
//}

//union U {
//	char c;
//	int i;
//};
//
//int main()
//{
//	union U u;
//	u.i = 1;
//	if (u.c == 1) {
//		printf("小端存储\n");
//	}
//	else {
//		printf("大端存储\n");
//	}
//	return 0;
//}

//int check_sys() {
//	union U {
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.c;
//}
//int main()
//{
//	if (check_sys() == 1) {
//		printf("小端存储\n");
//	}
//	else {
//		printf("大端存储\n");
//	}
//
//	return 0;
//}

//联合大小的计算

//union Un1 {
//	char c[5];
//	int i;
//};
//
//union Un2 {
//	short c[7];
//	int i;
//};
//
//int main()
//{
//	printf("%d\n", sizeof(union Un1));
//	printf("%d\n", sizeof(union Un2));
//
//	return 0;
//}