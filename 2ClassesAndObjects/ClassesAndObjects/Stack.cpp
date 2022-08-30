#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
//��ջ
void Stack::Push(STDataType x) {
	if (_top == _capacity) {
		int newCapacity = _capacity == 0 ? 4 : _capacity * 2;
		STDataType* ptr = (STDataType*)realloc(_a, newCapacity * sizeof(STDataType));
		if (ptr == nullptr) {
			printf("CheckCapacity::realloc");
			exit(-1);
		}
		_a = ptr;
		_capacity = newCapacity;
	}
	_a[_top] = x;
	_top++;
}
//��ջ
void Stack::Pop() {
	assert(!Empty());
	_top--;
}
//��ȡջ��Ԫ��
STDataType Stack::Top() {
	assert(!Empty());
	return _a[_top - 1];
}
//��ȡջԪ�ظ���
int Stack::Size() {
	return _top;
}
//����ջ
bool Stack::Empty() {
	return !_top;
}
//�������캯��
Stack::Stack(const Stack & st) {
	_capacity = st._capacity;
	_top = st._top;
	_a = (int*)malloc(sizeof(int) * _capacity);
	if (_a == nullptr) {
		exit(-1);
	}
	for (int i = 0; i < st._top; i++) {
		*(_a + i) = *(st._a + i);
	}
}