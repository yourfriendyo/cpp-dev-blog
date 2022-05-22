#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


//8. 基于范围的for循环
void TestFor(int arr[]) {
	for (auto e : arr) {
		cout << e << " ";
	}
}


int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//for (int i = 0; i < sz; i++) {
	//	cout << arr[i] << " ";
	//}
	//cout << endl;
	//for (auto e : arr) {
	//	cout << e << " ";
	//}
	//cout << endl;

	//for (int i = 0; i < sz; i++) {
	//	arr[i] *= 2;
	//} 
	//for (auto& e : arr) {
	//	e *= 2;
	//}
	//for (auto e : arr) {
	//	cout << e << " ";
	//}
	//cout << endl;
	TestFor(arr);

	return 0;
}

