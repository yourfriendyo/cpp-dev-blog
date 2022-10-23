#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class A {
//public:
//	A(int a = 0) {
//		cout << "A(int a = 0)" << endl;
//		_a = a;
//	}
//	A(const A& a) {
//		cout << "A(const A& a)" << endl;
//		_a = a._a;
//	}
//	A operator=(const A& a) {
//		cout << "A operator=(const A& a)" << endl;
//		_a = a._a;
//		return *this; //拷贝构造
//	}
//private:
//	int _a;
//};
//class Date {
//public:
//	Date(int year, int month, int day, const A& a)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		//, _a(a) //拷贝构造
//	{
//		_a = a; // 构造函数，赋值重载
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	A _a;
//};
//int main()
//{
//	A a(1); // 构造函数
//	Date d1(2022,2,1,a);
//
//	return 0;
//}

//class Date {
//public:
//	Date(int year = 1, int month = 1, int day = 1, int i = 1, const A& a)
//		: _ref(i)
//		, _j(0)
//		//, _a(11)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		_a = a;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	int& _ref;//引用必须初始化
//	const int _j;//const修饰的变量必须初始化
//	A _a;
//};
//
//int main()
//{
//	A a(1);
//	int i = 1;
//
//	Date d(2022, 1, 31, i, a);
//	return 0;
//}



//class A {
//public:
//	A()
//		:_a1(1)
//		, _a2(_a1)
//	{}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//
//int main()
//{
//	A().Print();
//	return 0;
//}

//
//class Date {
//public:
//	explicit Date(int year =	1, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(1111);
//	Date d2 = { 2222,2,1 };  // 隐式类型转换
//
//	double d = 1.11;
//	int i = d;
//
//	return 0;
//}
//
//
