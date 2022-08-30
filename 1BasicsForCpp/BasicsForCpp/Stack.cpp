#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void StackInit(struct Stack* ps, int capacity) {
	ps->a = (int*)malloc(capacity * sizeof(int));
	//...
	ps->top = 0;
	ps->capacity = capacity;
}

int main()
{
	struct Stack st;
	StackInit(&st);
	StackInit(&st, 100);
	//...
	return 0;
}

void f() {
	cout << "f()" << endl;
}
void f(int a) {
	cout << "f(int a = 0)" << endl;
}

