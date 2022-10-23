#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//5. 引用

//5.1 引用的定义

int main()
{
	int a = 0;
	int& b = a;

	a = 20;
	b = 30;

	return 0;

}


//5.2 引用的特性

int main()
{
	int a = 10;
	//int& b;//Err
	int& b = a;

	int& c = b;
	int& d = c;

	b = 20;
	c = 30;
	d = 40;

	int e = 1;
	int& f = a;
	f = e;


	return 0;
}

//5.3 常引用

void f(const int& ra) {
	//ra =222;//Err
}
int main()
{
	//权限放大
	const int a = 0;
	//int& ra = a;//Err
	//权限缩小
	int b = 0;
	const int rb = b;
	//权限相同
	const int c = 0;
	const int& rc = c;
	
	f(a);
	f(b);
	f(c);

	return 0;
}

int main()
{
	double d = 1.11;
	int i = d;


	double d = 1.11;
	const int& i = d;

	return 0;
}

//5.4 使用场景

void Swap(int x, int y) {
	int tmp = x;
	x = y;
	y = tmp;
}
void Swap(int* px, int* py) {
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

void Swap(int& rx, int& ry) {
	int tmp = rx;
	rx = ry;
	ry = tmp;
}

int main()
{
	int x = 0;
	int y = 1;
	Swap(&x, &y);
	cout << x << " " << y << endl;
	Swap(x, y);
	cout << x << " " << y << endl;

	return 0;
}

int& Add(int a, int b) {
	int c = a + b;
	return c;
}
int main()
{
	int& ret = Add(1, 2);
	cout << ret << endl;
	Add(10, 20);
	cout << ret << endl;

	return 0;
}

int a = 10;
int* pa = &a;
int& ret = a;
*pa = 22;

int main()
{
	int a = 0;
	int& tmp = a;
	int ret = tmp;

	return 0;
}

//5.5 传值传址效率对比

#include <time.h>
#include <stdlib.h>
struct A {int a[100000];};
A a;
A TestFunc1() {return a;}
A& TestFunc2() {return a;}
void TestRefAndValue() {
	//
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; i++) 
		TestFunc1();
	size_t end1 = clock();
	//
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; i++) 
		TestFunc2();
	size_t end2 = clock();
	//
	cout << "A TestFunc1():" << end1 - begin1 << endl;
	cout << "A& TestFunc2():" << end2 - begin2 << endl;
}

int main()
{
	TestRefAndValue();

	return 0;
}

#include <time.h>
struct A { int a[10000]; };
A a;
void TestFunc1(A a) {}
void TestFunc2(A& a) {}
void TestTransferRefAndValue() {
	
	size_t begin1 = clock();
	for (size_t i = 0; i < 1000000; i++)
		TestFunc1(a);
	size_t end1 = clock();
	
	size_t begin2 = clock();
	for (size_t i = 0; i < 1000000; i++)
		TestFunc2(a);
	size_t end2 = clock();
	cout << "TestFunc1(A a):" << end1 - begin1 << endl;
	cout << "TestFunc2(A& a):" << end2 - begin2 << endl;

}
int main()
{
	TestTransferRefAndValue();

	return 0;
}

int& Add(int a, int b) {
	int c = a + b;
	return c;
}
int main()
{
	int& ret = Add(1, 2);
	cout << ret << endl;
	ret = 22;


	return 0;
}


//5.6 引用和指针的区别

int main()
{
	int a = 10;

	int* pa = &a;

	*pa = 20;


	return 0;
}



#define N 10
int& At(int i) {
	static int a[N];
	return a[i];
}
int main()
{
	for (int i = 0; i < N; i++) {
		cout << "a[" << i << "]=" << (At(i) = i) << endl;
		//printf("a[%d]=%d\n", i, At(i) = i);
	}

	return 0;
}


void f1(int* p) {
	
}
void f2(int& r) {
	
}
int main()
{
	int a = 0;
	f1(&a);
	f1(0);
	f1(NULL);
	f(a);


	return 0;
}
