#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"


//��ʼ��ջ
void StackInit(ST* ps) {
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}


//��ջ
void StackPush(ST* ps, STDataType data) {
	assert(ps);
	//�������
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


//��ջ
void StackPop(ST* ps) {
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}


//��ȡջ��Ԫ��
STDataType StackTop(ST* ps) {
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}


//��ȡջԪ�ظ���
int StackSize(ST* ps) {
	assert(ps);
	return ps->top;
}


//����ջ
bool StackEmpty(ST* ps) {
	assert(ps);
	return !ps->top;
}


//����ջ
void StackDestroy(ST* ps) {
	assert(ps);
	free(ps->a);
	ps->capacity = ps->top = 0;
}