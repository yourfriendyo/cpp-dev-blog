#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class A {
//public:
//	friend void Func();
//private:
//	int _a;
//};
//
//void Func() {
//
//}

class Date;

class Time {
public:
	friend class Date; //日期类是时间类的友元类
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}
	void Print(Date d);
private:
	int _hour;
	int _minute;
	int _second;
};

class Date {
public:
	friend class Time;
	Date(int year = 1,int month = 1,int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		_t._hour = _t._minute = _t._second = 0;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
void Time::Print(Date d) {
	cout << d._year << endl;
}