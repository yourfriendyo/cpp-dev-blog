#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//3. ȱʡ����

void Func(int a = 0) {
	cout << "a=" << a << endl;
}

int main()
{
	Func();
	Func(1);

	return 0;
}


//3.1 ȱʡ�����Ķ���

void Func(int a = 10, int b = 20, int c = 30) {
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
	cout << endl; 
}

int main()
{
	Func();
	Func(1);
	Func(1, 2);
	Func(1, 2, 3);
	

	return 0;
}



//3.2 ȱʡ�����ķ���


void Func(int a = 10, int b = 20, int c = 30) {
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
	cout << endl;

}

void Func(int a, int b = 20, int c = 30) {
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
	cout << endl;
}
int main()
{
	Func(1);
	Func(1, 2);
	Func(1, 2, 3);
	
	return 0;
}























