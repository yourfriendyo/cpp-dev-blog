#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//
//void Swap(int& l, int& r) {
//	int t = l;
//	l = r;
//	r = t;
//}
//
//void Swap(double& l, double& r) {
//	double t = l;
//	l = r;
//	r = t;
//}
//
//void Swap(char& l, char& r) {
//	char t = l;
//	l = r;
//	r = t;
//}

//template <class T>
//void Swap(T& l, T& r) {
//	T t = l;
//	l = r;
//	r = t;
//}
//int main()
//{
//	int a = 0, b = 1;
//	Swap(a, b);
//	double c = 1.1, d = 2.2;
//	Swap(c, d);
//	char e = 'e', f = 'f';
//	Swap(e, f);
//
//	cout << a << " " << b << endl;
//	cout << c << " " << d << endl;
//	cout << e << " " << f << endl;
//
//	return 0;
//}


//template <class T>
//T Add(const T& rx, const T& ry) {
//	return rx + ry;
//}
//int main()
//{
//	int a = 10, b = 20;
//	double c = 3.33, d = 4.44;
//	cout << Add<int>(a, b) << endl;
//	cout << Add<double>(c, d) << endl;
//
//	//cout << Add(a, d) << endl;//Err
//	//cout << Add((double)a, d) << endl;
//
//	cout << Add<int>(a, d) << endl;
//	cout << Add<double>(a, d) << endl;
//
//	return 0;
//}


//template <class T1, class T2>
//T2 Add(const T1& rx, const T2& ry) 
//{
//	return rx + ry;
//}
//int main()
//{
//	cout << Add(10, 20.2) << endl;
//	return 0;
//}


//template <class T> 
//T Add(const T& rx, const T& ry) //适用于任意类型
//{
//	return rx + ry;
//}
//int main()
//{
//	Add(1, 2);
//	Add(1, 2.0);
//
//	return 0;
//}
//
