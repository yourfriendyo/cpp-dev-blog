#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//4. 函数重载

//4.1 函数重载的定义

int Add(int a, int b) {
	return a + b;
}
int Add(int a, int b, int c) {
	return a + b + c;
}
float Add(int a, float b) {
	return a + b;
}
float Add(float a, int b) {
	return a + b;
}
int main()
{
	Add(1, 2);
	Add(1, 2, 3);
	Add(1, 2.2f);
	Add(2.2f, 1);
	return 0;
}



//1.
void f(int a) {
	cout << "f(int a)" << endl;
}
void f(int a = 0) {
	cout << "f(int a = 0)" << endl;
}
//2.
void f() {
	cout << "f()" << endl;
}
void f(int a = 0) {
	cout << "f(int a = 0)" << endl;
}

#include "Stack.h"
int main()
{
	//f();
	f(1);
	return 0;
}


//4.2 名字修饰


#include <stdio.h>

int Add(int a, int b) {
	return a + b;

}

void func(int a, double b, int* p) {
	;
}

int main()
{
	Add(1, 2);
	func(1, 2, 0);

	return 0;
}


//4.3 extern "C"

extern "C" 
{
#include "../../StackLibrary/StackLibrary/Stack.h"
}

bool isValid(const char* s) {
	ST st;
	StackInit(&st);
	while (*s) {
		if (*s == '(' || *s == '[' || *s == '{') {
			StackPush(&st, *s);
		}
		else {
			//栈无元素，无法与右括号匹配  
			if (StackEmpty(&st)) {
				StackDestroy(&st);
				return false;
			}
			STDataType ret = StackTop(&st);
			if ((ret == '(' && *s != ')') ||
				(ret == '[' && *s != ']') ||
				(ret == '{' && *s != '}')) {
				StackDestroy(&st);
				return false;
			}
			else {
				StackPop(&st);
			}
		}
		s++;
	}
	if (StackEmpty(&st)) {
		StackDestroy(&st);
		return true;
	}
	else {
		StackDestroy(&st);
		return false;
	}
}

int main()
{

	printf("%d\n", isValid("[{()}]"));
	printf("%d\n", isValid("[{(}]("));

	return 0;
}