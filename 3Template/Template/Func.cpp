#include "Func.h"
void Func1(int x) {
	cout << "Func1(int x)" << endl;
}
template <class T>
void Func2(T& x) {
	cout << "Func(T& x)" << endl;
}
//ÏÔÊ½ÊµÀý»¯
template
void Func2<int&>(int& x);