#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

//��ȡ�Ϸ����������ֵ
int Date::GetMonthDay() const {
	static int MonthDayArray[13] = { 0, 31 ,28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = MonthDayArray[_month];
	//�ж�����
	if (_month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0))) {
		day += 1;
	}
	return day;
}

//���캯��
Date::Date(int year, int month, int day) {
	//�ж������Ƿ�Ϸ�
	_year = year;
	_month = month;
	_day = day;
	if (month > 12 || day > GetMonthDay()) {
		cout << "���������Ƿ�Ϸ���";
		Print();
	}
}

//��������
Date::~Date() {
	//cout << "~Date()" << endl;
	_year = _month = _day = 0;
}

//��ӡ
void Date::Print() const {
	cout << _year << "-" << _month << "-" << _day << endl;
}

//��������
Date::Date(const Date& d) {
	_year = d._year;
	_month = d._month;
	_day = d._day;
	//cout << "Date(const Date& d)" << endl;
}

//��������� >
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
//��������� >=
bool Date::operator>=(const Date& d) const {
	return (*this > d) || (*this == d);
}

//��������� <
bool Date::operator<(const Date& d) const {
	return !(*this >= d);
}
//��������� <=
bool Date::operator<=(const Date& d) const {
	return !(*this > d);
}

//��������� ==
bool Date::operator==(const Date& d) const {
	return (_year == d._year) && (_month == d._month) && (_day == d._day);
}
//��������� !=
bool Date::operator!=(const Date& d) const {
	return !(*this == d);
}

//��������� =
Date& Date::operator=(const Date& d) {
	if (this != &d) { //�Ż��Լ����Լ���ֵ�����
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

//��������� +=   ���� + ���� = ���� 
Date& Date::operator+=(int day) {
	if (_day < 0) {
		return *this -= -day;
	}
	_day += day;
	//��������Ƿ�Ϸ�
	while (_day > GetMonthDay()) {
		_day -= GetMonthDay();//�������Ϸ����ֵ --- �ȼ�ֵ���ٽ�λ
		//�·ݽ�λ
		_month += 1;
		if (_month == 13) { //��������Ƿ�Ϸ�
			_month = 1;
			_year += 1;//��ݽ�λ
		}
	}
	return *this;
}


//��������� +
Date Date::operator+(int day) const {//��ʱ���������٣����ɴ�����
	Date ret(*this);
	ret += day;//ret.operator+=(day);
	return ret;
}

//��������� -=
//���� - ���� = ����
Date& Date::operator-=(int day) {
	//��ֹ�����Ǹ���
	if (_day < 0) {
		return *this += -day;
	}
	_day -= day;
	//��������Ƿ�Ϸ�
	while (_day <= 0) {
		_month--;//�·ݽ�λ
		//����·��Ƿ�Ϸ�
		if (_month == 0) {
			_month = 12;
			_year--;//��ݽ�λ
		}
		_day += GetMonthDay();//�������ϺϷ����ֵ --- �Ƚ�λ���ټ�ֵ

	}
	return *this;
}

//��������� -
//���� - ���� = ����
Date Date::operator-(int day) const {
	Date ret(*this);
	ret -= day;
	return ret;
}

//���� - ���� = ����  
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
//	//��ֹ����Ϊ����
//	assert(*this > d);
//	if (*this == d) { // ʹ��+=���뵥��������ȵ������������
//		return 0;
//	}
//	Date thisDay = *this;
//	*this = d;
//	int retDay = 0;
//	//����this + ����retDay = ����thisDay
//	while (true) { 
//		retDay++;
//		if (operator+=(1) == thisDay) { 
//			break;
//		}
//	}
//	*this = thisDay;
//	return retDay;
//}


//ǰ��++
Date& Date::operator++() {
	return *this += 1;
}

//����++
Date Date::operator++(int) {
	return (*this += 1) - 1;
}
//Date ret = *this;
//*this + 1;
//return ret;

//ǰ��--
Date& Date::operator--() {
	return *this -= 1;
}

//����--
Date Date::operator--(int) {
	return (*this -= 1) + 1;
}

//��ȡ��������
void Date::PrintWeekDay() const {
	const char* arr[] =
	{ "����һ","���ڶ�","������","������","������","������" ,"������" };
	Date start(2022, 1, 3);//����һ
	int cnt = *this - start;
	cnt %= 7;
	if (cnt < 0) {
		cnt += 7;
	}
	cout << arr[cnt] << endl;
}

//������<<
ostream& operator<<(ostream& out, const Date& d) {
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

// ����ȡ>>
istream& operator>>(istream& in, Date& d) {
	in >> d._year >> d._month >> d._day;
	return in;
}
