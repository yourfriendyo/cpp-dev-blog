#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
* 1. 结构体
* 结构体的声明
* 结构体自引用
* 结构体变量的定义
* 结构体内存对齐
* 结构体传参
* 位段
* */


//结构体的声明

//复杂对象
//人：姓名+年龄+身高+体重+身份证号码+电话
//书：书名+作者+出版社+定价+书号
//struct Book {
//	char name[20];
//	char author[20];
//	double price;
//}b1, b2;
//struct Book b3 = { 0 };

//struct Human {
//	char name[20];
//	short age;
//	char id[20];
//	char tele[20];
//};

//struct {
//	int a;
//	char c;
//	double d;
//}s1, s2;
//struct {
//	int a;
//	char c;
//	double d;
//}*ps;
//
//int main()
//{
//	ps = &s1;//指针类型不兼容
//
//	return 0;
//}


//结构体自引用

//struct Node 
//{
//	int data;
//	struct Node next;
//};
//
//struct Node {
//	int data;
//	struct Node* next; 
//};

//typedef struct {
//	int data;
//	Node* next;
//
//}Node;
//
//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node;


//结构体变量的定义

//struct Point {
//	int x;
//	int y;
//}p2 = { 3,3 }, p3 = { 4,4 };
//struct Point p4 = { 1,2 };
//struct S {
//	double d;
//	struct Point p;
//	char n[10];
//};
//int main()
//{
//	struct Point p1 = { 3,4 };
//	struct S s = { 3.14, {1,1}, "zhangsan"};
//	printf("%lf %d,%d %s\n", s.d, s.p.x, s.p.y, s.n);
//	return 0;
//}


//结构体内存对齐

//#pragma pack(8)//设置默认对齐数
//struct S1 {
//	char c1;
//	int a;
//	char c2;
//};
//#pragma pack()//恢复默认对齐数
////12
//struct S2 {
//	char c1;
//	char c2;
//	int a;
//};
////8
//
//struct S3 {
//	double d;
//	char c;
//	int a;
//};
////16
//struct S4 {
//	char c1;//1
//	struct S3 s;//8
//	double d;//8
//};
////32

//int main()
//{
//	struct S1 s = { 'x',100,'y' };
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//	printf("%d\n", sizeof(struct S3));
//	printf("%d\n", sizeof(struct S4));
//
//	return 0;
//}

//#include <stddef.h>
//int main()
//{
//	printf("%d\n", offsetof(struct S1, c1));
//	printf("%d\n", offsetof(struct S1, c2));
//	printf("%d\n", offsetof(struct S1, a));
//
//
//	return 0;
//}


//结构体传参

//struct S {
//	int data[1000];
//	int num;
//};

//void Print1(struct S tmp) {
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", tmp.data[i]);
//	}
//	printf("\n%d\n", tmp.num);
//}
//void Print2(struct S* ps) {
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", ps->data[i]);
//	}
//	printf("\n%d\n", ps->num);
//}

//int main()
//{
//	struct S s = { {1,2,3,4,5,6,7,8,9,10},100 };
//	Print1(s);
//	Print2(&s);
//
//	return 0;
//}

//位段

//struct A {
//	int a : 2; 
//	int b : 5;
//	int c : 10;
//	int d : 30;
//};
//
//int main()
//{
//	printf("%d\n", sizeof(struct A));//8
//
//
//	return 0;
//}


//struct S {
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//struct S s = { 0 };
//int main()
//{
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//
//	return 0;
//}
