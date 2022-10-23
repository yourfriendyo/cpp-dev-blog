#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "Stack.h"
using namespace std;

/********************* 类和对象 中 ****************************/


// 构造函数

//class Date {
//public:
//	//Date() {
//	//	_year = 0;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//	Date(int year = 0, int month = 1, int day = 1) {
//		_year = year;
//		_month = month; 
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};

//class A {
//public:
//	A(int a = 10) {
//		cout << "A::_a = " << (_a = a) << endl;
//	}
//private:
//	int _a;
//};
//class Date {
//public:
//	void Print() {
//		cout << this << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	//A _aa; //自定义类型
//};
//int main()
//{
//	Date d1;
//	// d1.Print();
//
//	return 0;
//}


//析构函数
//
//class Stack {
//public:
//	Stack(int capacity = 4) {
//		int* ptr = (int*)malloc(sizeof(int) * capacity);
//		if (ptr == nullptr) {
//			cout << "Stack::malloc" << endl;
//			exit(-1);
//		}
//		_a = ptr;
//		_capacity = capacity;
//		_top = 0;
//	}
//	~Stack() {
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//	// ... 
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//class Date {
//public:
//	Date(int year = 0, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	~Date() {
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(2022, 1, 18);
//
//	Stack st1(10);
//	Stack st2(20);
//
//
//	return 0;
//}

//class MyQueue {
//public:
//
//	//void push(int x) {
//	//}
//
//	//int pop() {
//	//}
//
//	//int peek() {
//	//}
//
//	//bool empty() {
//	//}
//};

// 拷贝构造函数


//class Stack {
//public:
//	Stack(int capacity = 4) {
//		int* ptr = (int*)malloc(sizeof(int) * capacity);
//		if (ptr == nullptr) {
//			cout << "Stack::malloc" << endl;
//			exit(-1);
//		}
//		_a = ptr;
//		_capacity = capacity;
//		_top = 0;
//	}
//	Stack(const Stack& st) {
//		_capacity = st._capacity;
//		_top = st._top;
//		_a = (int*)malloc(sizeof(int) * _capacity);
//		if (_a == nullptr) {
//			exit(-1);
//		}
//		for (int i = 0; i < st._capacity; i++) {
//			*(_a + i) = *(st._a + i);
//		}
//	}
//	~Stack() {
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//	// ... 
//private:
//	int* _a;
//	int _top;
//	int _capacity;
////};
//class A {
//public:
//	A() {
//		//
//	}
//	A(const A& a) {
//		cout << "A(const A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//class Date {
//public:
//	Date(int year = 0, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//Date(const Date* d) {
//	//	_year = d->_year;
//	//	_month = d->_month;
//	//	_day = d->_day;
//	//}
//	//Date(const Date& d) {
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//	
//	//}
//	~Date() {
//		//cout << "~Date()" << endl;
//	}
//	void Print() {
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	//A _aa;
//};
//
//int main()
//{
//	Date d1(2022, 1, 18);
//	//d1.Print();
//	Date d2(d1);
//	//d2.Print();
//	d2 = d1;//Err
//	
//
//	//Stack st1(10);
//	//st1.Push(1);
//	//st1.Push(3);
//	//st1.Push(4);
//	//st1.Push(5);
//	//Stack st2(st1);
//	//
//
//	return 0;
//}



//运算符重载

//class Date {
//public:
//	Date(int year = 0, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d) {
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		cout << "Date(const Date& d)" << endl;
//	}  
//	bool operator>(const Date& d);
//	Date& operator=(const Date& d);
//	void Print() {
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////bool Date::operator>(Date* const this, const Date& d) {...}
//
//bool Date::operator>(const Date& d) {
//	if (_year > d._year) {
//		return true;
//	}
//	else if (_year == d._year && _month > d._month) {
//		return true;
//	}
//	else if (_year == d._year && _month == d._month && _day > d._day) {
//		return true;
//	}
//	return false;
//}
//
//Date& Date::operator=(const Date& d) {
//	if (this != &d) {
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	return *this;
//}

//bool operator>(const Date& d1, const Date& d2) {
//	if (d1._year > d2._year) {
//		return true;
//	}
//	else if (d1._year == d2._year && d1._month > d2._month) {
//		return true;
//	}
//	else if (d1._year == d2._year && d1._month == d2._month && d1._day > d2._day) {
//		return true;
//	}
//	return false;
//}
//int operator-(const Date& d1, const Date& d2);



//int main() 
//{
//	Date d1(2022, 1, 20);
//
//	Date d2(2022, 1, 31);
//
//	Date d3(2022, 2, 26);
//	d1 > d2;
//	cout << (d1 > d2) << endl;
//	//cout << operator>(d1, d2) << endl;
//
//	cout << d1.operator>(d2) << endl;
//
//	//int day1 = d2 - d1;
//
//	//int day2 = d3 - d1;
//
//	return 0;
//}
//
//int main()
//{
//	Date d1(2022, 1, 20);
//
//	Date d2(2022, 1, 31);
//
//	Date d3(2022, 2, 26);
//	
//	Date d4(d3);//拷贝构造
//	d4.Print();
//	d4 = d2;//赋值拷贝
//	d4.Print();
//
//	d4 = d3 = d2 = d1;
//
//	Date d5 = d1;
//}