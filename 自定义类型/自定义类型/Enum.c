#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
* 2. 枚举类型
* 枚举的定义
* 枚举的优点
* 枚举的使用
* */


//枚举类型

//enum Day {
//	Mon,
//	Tues,
//	Wed,
//	Thur,
//	Fri,
//	Sat,
//	Sun
//};
//enum Sex {
//FAMALE,
//MALE,
//SECRET
//};

//枚举的定义

//enum Color {
//	RED,
//	GREEN,
//	BLUE
//};

//int main()
//{
//	//printf("%d\n", RED);
//	//printf("%d\n", GREEN);
//	//printf("%d\n", BLUE);
//
//	enum Color c = GREEN;
//	if (c == GREEN) {
//		printf("GREEN\n");
//	}
//	return 0;
//}

//枚举的优点

//#define RED 0
//#define GREEN 1
//#define BLUE 2

//枚举的使用

//enum Option {
//	EXIT,//0
//	ADD,//1
//	SUB,//2
//	MUL,//3
//	DIV,//4
//};
 
//int Add(int x, int y) {
//	return x + y;
//}
//int Sub(int x, int y) {
//	return x - y;
//}
//int Mul(int x, int y) {
//	return x * y;
//}
//int Div(int x, int y) {
//	return x / y;
//}

//void Calc(int (*pf)(int, int)) {
//	int a = 0;
//	int b = 0;
//	printf("请输入操作数:>");
//	scanf("%d %d", &a, &b);
//	printf("%d\n", pf(a, b));
//}

//void menu() {
//	printf("*************************\n");
//	printf("**** 1.ADD     2.SUB ****\n");
//	printf("**** 3.MUL *** 4.DIV ****\n");
//	printf("*******  0.exit  ********\n");
//	printf("*************************\n");
//}

//int main()
//{
//	int input = 0;
//
//	do {
//		menu();
//		printf("请选择\n");
//		scanf("%d", &input);
//
//		switch (input) {
//		case ADD:
//			Calc(Add);
//			break;
//		case SUB:
//			Calc(Sub);
//			break;
//		case MUL:
//			Calc(Mul);
//			break;
//		case DIV:
//			Calc(Div);
//			break;
//		case EXIT:
//			break;
//		default :
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

