#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

//获取合法天数的最大值
int Date::GetMonthDay() const {
	static int MonthDayArray[13] = { 0, 31 ,28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = MonthDayArray[_month];
	//判断闰年
	if (_month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0))) {
		day += 1;
	}
	return day;
}

//构造函数
Date::Date(int year, int month, int day) {
	//判断日期是否合法
	_year = year;
	_month = month;
	_day = day;
	if (month > 12 || day > GetMonthDay()) {
		cout << "请检查日期是否合法：";
		Print();
	}
}

//析构函数
Date::~Date() {
	//cout << "~Date()" << endl;
	_year = _month = _day = 0;
}

//打印
void Date::Print() const {
	cout << _year << "-" << _month << "-" << _day << endl;
}

//拷贝构造
Date::Date(const Date& d) {
	_year = d._year;
	_month = d._month;
	_day = d._day;
	//cout << "Date(const Date& d)" << endl;
}

//运算符重载 >
bool Date::operator>(const Date& d) const {
	if (_year > d._year) {
		return true;
	}
	else if (_year == d._year && _month > d._month) {
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day) {
		return true;
	}
	return false;
}
//运算符重载 >=
bool Date::operator>=(const Date& d) const {
	return (*this > d) || (*this == d);
}

//运算符重载 <
bool Date::operator<(const Date& d) const {
	return !(*this >= d);
}
//运算符重载 <=
bool Date::operator<=(const Date& d) const {
	return !(*this > d);
}

//运算符重载 ==
bool Date::operator==(const Date& d) const {
	return (_year == d._year) && (_month == d._month) && (_day == d._day);
}
//运算符重载 !=
bool Date::operator!=(const Date& d) const {
	return !(*this == d);
}

//运算符重载 =
Date& Date::operator=(const Date& d) {
	if (this != &d) { //优化自己给自己赋值的情况
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

//运算符重载 +=   日期 + 天数 = 日期 
Date& Date::operator+=(int day) {
	if (_day < 0) {
		return *this -= -day;
	}
	_day += day;
	//检查天数是否合法
	while (_day > GetMonthDay()) {
		_day -= GetMonthDay();//天数减合法最大值 --- 先减值，再进位
		//月份进位
		_month += 1;
		if (_month == 13) { //检查月数是否合法
			_month = 1;
			_year += 1;//年份进位
		}
	}
	return *this;
}


//运算符重载 +
Date Date::operator+(int day) const {//临时变量会销毁，不可传引用
	Date ret(*this);
	ret += day;//ret.operator+=(day);
	return ret;
}

//运算符重载 -=
//日期 - 天数 = 日期
Date& Date::operator-=(int day) {
	//防止天数是负数
	if (_day < 0) {
		return *this += -day;
	}
	_day -= day;
	//检查天数是否合法
	while (_day <= 0) {
		_month--;//月份借位
		//检查月份是否合法
		if (_month == 0) {
			_month = 12;
			_year--;//年份借位
		}
		_day += GetMonthDay();//天数加上合法最大值 --- 先借位，再加值

	}
	return *this;
}

//运算符重载 -
//日期 - 天数 = 日期
Date Date::operator-(int day) const {
	Date ret(*this);
	ret -= day;
	return ret;
}

//日期 - 日期 = 天数  
int Date::operator-(const Date& d) const {
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (max < min) {
		max = d;
		min = *this;
		flag = -1;
	}
	int gap = 0;
	while ((min + gap) != max) {
		gap++;
	}
	return gap * flag;
}


//operator- V2
//int Date::operator-(const Date& d) {
//	//防止天数为负数
//	assert(*this > d);
//	if (*this == d) { // 使用+=必须单独考虑相等的情况，不够好
//		return 0;
//	}
//	Date thisDay = *this;
//	*this = d;
//	int retDay = 0;
//	//日期this + 天数retDay = 日期thisDay
//	while (true) { 
//		retDay++;
//		if (operator+=(1) == thisDay) { 
//			break;
//		}
//	}
//	*this = thisDay;
//	return retDay;
//}


//前置++
Date& Date::operator++() {
	return *this += 1;
}

//后置++
Date Date::operator++(int) {
	return (*this += 1) - 1;
}
//Date ret = *this;
//*this + 1;
//return ret;

//前置--
Date& Date::operator--() {
	return *this -= 1;
}

//后置--
Date Date::operator--(int) {
	return (*this -= 1) + 1;
}

//获取当天星期
void Date::PrintWeekDay() const {
	const char* arr[] =
	{ "星期一","星期二","星期三","星期四","星期五","星期六" ,"星期日" };
	Date start(2022, 1, 3);//星期一
	int cnt = *this - start;
	cnt %= 7;
	if (cnt < 0) {
		cnt += 7;
	}
	cout << arr[cnt] << endl;
}

//流插入<<
ostream& operator<<(ostream& out, const Date& d) {
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

// 流提取>>
istream& operator>>(istream& in, Date& d) {
	in >> d._year >> d._month >> d._day;
	return in;
}
