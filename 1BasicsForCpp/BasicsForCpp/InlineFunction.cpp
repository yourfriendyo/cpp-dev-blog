#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//6. ��������

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
