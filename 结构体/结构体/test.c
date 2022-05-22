#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//结构体类型声明
//
//struct book
//{
//	char name[20];
//	char author[15];
//	float price;
//}b1,b2;
//struct point
//{
//	int x;
//	int y;
//}p1,p2;
//
//typedef 
//struct human
//{
//	char name[20];
//	int age;
//	char sex[10];
//	char id[20];
//}hu;
//
//int main()
//{
//
//	struct book b;
//	struct human man;
//	hu man;
//	return 0;
//}
//
//typedef unsigned int size_t;

//结构体变量定义和初始化
//typedef struct human
//{
//	char name[20];
//	int age;
//	char sex[10];
//	char id[20];
//}hu;
//
//
//struct book
//{
//	char name[20];
//	char id[20];
//	float price;
//	char author[20];
//};
//
//struct book b1;
//
//typedef struct point
//{
//	int x;
//	int y;
//}point;
//
//point p1 = { 1,2 };
//
//int main()
//{
//	struct human man1 = { "张三",20,"女装大佬","20203100" };
//	point p1 = { 1,2 };
//	return 0;
//}

//struct S
//{
//	int a;
//	char c;
//	double d;
//};
//struct T
//{
//	struct S s;
//	char name[20];
//	int num;
//};
//
//int main()
//{
//	struct T t = { {10, 'x', 1.00}, "yourfriendyo", 21 };
//
//	return 0;
//}

//结构体成员访问

//struct S
//{
//	int a;
//	char c;
//	double d;
//};
//
//struct T
//{
//	struct S s;
//	char name[20];
//	int num;
//};
//
//int main()
//{
//	struct T t = { {10, 'x', 1.00}, "yourfriendyo", 21 };
//	printf("%d %c %lf %s %d\n", t.s.a, t.s.c, t.s.d, t.name, t.num);
//	struct T* pt = &t;
//	printf("%d %c %lf %s %d\n", (*pt).s.a, (*pt).s.c, (*pt).s.d, (*pt).name, (*pt).num);
//	printf("%d %c %f %s %d\n", pt->s.a, pt->s.c, pt->s.d, pt->name, pt->num);
//	struct S* ps = &(t.s);
//	printf("%d %c %f %s %d\n", ps->a, ps->c, ps->d, pt->name, pt->num);
//
//	return 0;
//}

//结构体传参
//struct S
//{
//	char arr[100];
//	int num;
//	float f;
//};
//
//void Print1(struct S ss)
//{
//	printf("%c %c %c %d %f\n", ss.arr[0], ss.arr[1], ss.arr[2], ss.num, ss.f);
//
//}
//void Print2(struct S* s)
//{
//	printf("%c %c %c %d %f\n", s->arr[0], s->arr[1], s->arr[2], s->num, s->f);
//}
//int main()
//{
//	struct S s = { {'1','2','3','4'}, 22, 3.14};
//	Print1(s);
//	Print2(&s);
//	return 0;
//}
