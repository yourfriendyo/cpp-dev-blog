#pragma once
#include <iostream>
#include <cassert>
using namespace std;

class Date {
public:
	//构造函数
	Date(int year = 1, int month = 1, int day = 1);

	//打印
	void Print() const;

	//拷贝构造
	Date(const Date& d);

	//析构函数
	~Date();

	//获取当月天数
	int GetMonthDay() const;

	//获取当天星期
	void PrintWeekDay() const;

	// >运算符重载
	bool operator>(const Date& d) const;

	// >=运算符重载
	bool operator>=(const Date& d) const;

	// <运算符重载
	bool operator<(const Date& d) const;

	// <=运算符重载
	bool operator<=(const Date& d) const;

	// ==运算符重载
	bool operator==(const Date& d) const;

	// !=运算符重载
	bool operator!=(const Date& d) const;

	// =运算符重载
	Date& operator=(const Date& d);

	//日期+天数=日期
	Date& operator+=(int day);

	//日期+天数=日期
	Date operator+(int day) const;

	//日期-天数=日期
	Date& operator-=(int day);

	//日期-日期=天数  
	int operator-(const Date& d) const;

	//日期-天数=日期
	Date operator-(int day) const;

	//前置++
	Date& operator++();

	//后置++
	Date operator++(int);

	//前置--
	Date& operator--();

	//后置--
	Date operator--(int);


	//取地址操作符重载
	//Date* operator&() {
	//	return this;
	//	//return NULL;
	//}
	//const Date* operator&() const {
	//	return this;
	//}


    //流插入<<
	friend ostream& operator<<(ostream& out, const Date& d);

	// 流提取>>
	friend istream& operator>>(istream& in, Date& d);

private:
	int _year;
	int _month;
	int _day;
};