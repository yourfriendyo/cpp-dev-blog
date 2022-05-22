#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//typedef int DateType;
//typedef double DateType;

template <class T>
class Stack {
public:
	Stack(int capacity = 4) 
		:_top(0), _capacity(capacity)
	{
		_data = new T[capacity];
	}
	~Stack() {
		delete[] _data;
		_data = nullptr;
		_top = _capacity = 0;
	}
	void Push(T x);
private:
	T* _data;
	int _top;
	int _capacity;
};
template <class T>
void Stack<T>::Push(T x) {
	_data[top++] = x;
	//...
}
int main()
{
	Stack<int> st1;
	Stack<double> st1;

	
	return 0;
}
