#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
int main()
{
	//cout << "hello world" << endl;
	using std::cout;
	using std::endl;
	cout << "hello world" << endl;
	int i = 0;
	double d = 1.11;

	cout << i << " " << d << endl;

	cin >> i >> d;
	cout << i << " " << d << endl;




	return 0;
}