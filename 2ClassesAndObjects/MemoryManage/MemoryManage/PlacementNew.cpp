#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Test {
public:
	Test(int data = 0) 
		:_data(data)
	{}
	~Test() {
		cout << "~Test()" << endl;
	}
private:
	int _data;
};

class A {
public:
	A(int a = 0) 
		:_a(a)
	{}
	~A() {
		_a = 0;
	}
private:
	int _a;
};
int main()
{
	
 	Test* pt = (Test*)malloc(sizeof(Test));
	
	//已开辟好的空间，初始化已有空间
	new(pt) Test; //
	new(pt) Test(1); //

	pt->~Test();

	
	A* a1 = new A;

	a1->~A();

	A* a2 = (A*)operator new(sizeof(A));
	new(a2) A;

	a2->~A();
	operator delete(a2);

	
	return 0;
}
