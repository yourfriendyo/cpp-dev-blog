#pragma once
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;
typedef int STDataType;

class Stack {
public:
	Stack(int capacity = 4) {
		int* ptr = (int*)malloc(sizeof(int) * capacity);
		if (ptr == nullptr) {
			cout << "Stack::malloc" << endl;
			exit(-1);
		}
		_a = ptr;
		_capacity = capacity;
		_top = 0;
	}
	Stack(const Stack& st);
	~Stack() {
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
	void Push(STDataType x);
	void Pop();
	STDataType Top();
	int Size();
	bool Empty();
private:
	STDataType* _a;
	int _top;
	int _capacity;
};
