#include <iostream>
#include <array>
using namespace std;

//#define N 100
template <class T, size_t N = 100>
//template <class T, size_t N, double D>
class Stack {
public:
	//...
private:
	T _a[N];
};

//int main()
//{
//	Stack<int> st1;
//	Stack<int, 200> st2;
//
//	int arr1[10] = { 0 };
//	int arr2[20] = { 0 };
//
//	array<int, 10> a1 = { 1 };
//	array<int, 20> a2 = { 2 };
//
//	//arr1[20] = 1; //数组检查不严格Err
//	//a1[20] = 1;
//
//
//	return 0;
//}
class Date {
public:
	Date(int year = 1, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	bool operator<(const Date d)
	{
		if (_year < d._year) {
			return true;
		}
		else if (_year == d._year && _month < d._month) {
			return true;
		}
		else if (_year == d._year && _month == d._month && _day < d._day) {
			return true;
		}
		else {
			return false;
		}
	}
private:
	int _year;
	int _month;
	int _day;
};

template <class T>
bool ObjLess(T l, T r)
{
	return l < r;
}
//bool ObjLess(Date* l, Date* r)
//{
//	return *l < *r;
//}
//函数模板特化的参数和函数模板参数完全一致
template<>
bool ObjLess<Date*>(Date* l, Date* r) 
{ 
	return *l < *r;
}

//int main()
//{
//	//cout << ObjLess(1, 2) << endl;
//	Date* p1 = new Date(2022, 4, 4);
//	Date* p2 = new Date(2020, 4, 4);
//	cout << ObjLess(p1, p2) << endl;
//
//	return 0;
//}

template <class T1, class T2>
class Data 
{
public:
	Data() {
		cout << "Data<T1, T2>" << endl;
	}
private:
	T1 _a;
	T2 _c;
};
//全特化
template <>
class Data<int, char> {
public:
	Data() {
		cout << "Data<int, char>" << endl;
	}
private:
	int _a;
	char _c;
};
//偏特化
template <class T1>
class Data<T1, char> //第二个模板参数为char
{
public:
	Data() {
		cout << "Data<T1, char>" << endl;
	}
private:
	T1 _a;
	char _c;
};
template <class T1, class T2>
class Data<T1*, T2*> 
{
public:
	Data() {
		cout << "Data<T1*, T2*>" << endl;
	}
private:
	T1 _a;
	char _c;
};
template <class T1, class T2>
class Data<T1&, T2&>
{
public:
	Data() {
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	T1 _a;
	char _c;
};

template <size_t N> 
class A {
public:
	A() {
		cout << "A<N>" << endl;
	}
};
template <>
class A<10> {
public:
	A() {
		cout << "A<10>" << endl;
	}
};

int main()
{
	//Data<int, int> d1;
	//Data<int, char> d2;
	//Data<long, char> d3;

	//Data<char*, char*> d4;
	//Data<char&, char&> d5;
	
 	A<20> a1;
	A<10> a2;

	return 0;
}