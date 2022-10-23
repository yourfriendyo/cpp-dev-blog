#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <cstdlib>
using namespace std;

//int f(int i) {
//	if (i <= 1) {
//		return i;
//	}
//	return f(i - 1) + f(i);
//}
//
//int main()
//{
//	int ret = f(1000);
//	cout << ret << endl;
//	
//	return 0;
//}

//int main()
//{
//	//C语言动态申请
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = (int*)malloc(sizeof(int) * 5);
//	free(p1);
//	p1 = NULL;
//	free(p2);
//	p2 = NULL;
//
//	int* p3 = new int;
//	int* p4 = new int[5];
//	//动态释放
//
//	delete p3;
//	p3 = nullptr;
//	delete[] p4;
//	p4 = nullptr;
//
//	return 0;
//}

class A {
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A():" << this << endl;
	}
	~A() {
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};

//int main()
//{
//	//int* p1 = new int(5);
//	//int* p2 = new int[5];
//
//	//char* p3 = new char('a');
//
//	//A* p4 = new A;
//
//	return 0;
//}
// 

//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = (A*)malloc(sizeof(A) * 5);
//	A* p3 = new A(1);
//	A* p4 = new A[5]{ 1,2,3,4,5 };
//
//	free(p1);
//	free(p2);
//	delete p3;
//	delete[] p4;
//
//	return 0;
//}


//面向对象：抛异常
//面向过程：错误码

int main()
{
	//char* p = (char*)malloc(1024u*1024u*1024u*2u);
	//if (p == nullptr) {
	//	printf("%d:", errno);
	//	printf("%s\n", strerror(errno));
	//}
	char* p2 = nullptr;
	try {
		//new char[1024u * 1024u * 1024u * 5u];

	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	//printf("%p\n", p2);

	return 0;
}
