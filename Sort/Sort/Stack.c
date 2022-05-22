#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"


//初始化栈
void StackInit(ST* ps) {
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}


//入栈
void StackPush(ST* ps, STDataType data) {
	assert(ps);
	//检测容量
	if (ps->capacity == ps->top) {
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* ptr = (STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (ptr == NULL) {
			perror("StackPush::realloc");
			exit(-1);
		}
		ps->a = ptr;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top] = data;
	ps->top++;
}


//出栈
void StackPop(ST* ps) {
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}


//获取栈顶元素
STDataType StackTop(ST* ps) {
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}


//获取栈元素个数
int StackSize(ST* ps) {
	assert(ps);
	return ps->top;
}


//检测空栈
bool StackEmpty(ST* ps) {
	assert(ps);
	return !ps->top;
}


//销毁栈
void StackDestroy(ST* ps) {
	assert(ps);
	free(ps->a);
	ps->capacity = ps->top = 0;
}