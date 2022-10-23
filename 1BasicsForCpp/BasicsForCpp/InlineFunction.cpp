#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//6. ÄÚÁªº¯Êı

inline int Add(int a, int b) {
	int c = a + b;
	return c;
}
int main()
{
	int ret = Add(1, 2);
	cout << ret << endl;

	return 0;
}
