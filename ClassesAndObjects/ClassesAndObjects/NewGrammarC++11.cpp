#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class B {
public:
	B(int b1 = 0, int b2 = 0)
		:_b1(b1)
		, _b2(b2)
	{}
private:
	int _b1;
	int _b2;
};
class A {
public:
	A()
		:_a(10)
	{
		//_a = 11;
	}
private:
	int _a = 1;
	B _b ;
	int _arr[10] = { 1,2,3,4,5,6 };
	int* _p = &_a;
};
int main() {
	A a;
	return 0;
}