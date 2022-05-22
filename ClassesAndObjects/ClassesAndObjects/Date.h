#pragma once
#include <iostream>
#include <cassert>
using namespace std;

class Date {
public:
	//���캯��
	Date(int year = 1, int month = 1, int day = 1);

	//��ӡ
	void Print() const;

	//��������
	Date(const Date& d);

	//��������
	~Date();

	//��ȡ��������
	int GetMonthDay() const;

	//��ȡ��������
	void PrintWeekDay() const;

	// >���������
	bool operator>(const Date& d) const;

	// >=���������
	bool operator>=(const Date& d) const;

	// <���������
	bool operator<(const Date& d) const;

	// <=���������
	bool operator<=(const Date& d) const;

	// ==���������
	bool operator==(const Date& d) const;

	// !=���������
	bool operator!=(const Date& d) const;

	// =���������
	Date& operator=(const Date& d);

	//����+����=����
	Date& operator+=(int day);

	//����+����=����
	Date operator+(int day) const;

	//����-����=����
	Date& operator-=(int day);

	//����-����=����  
	int operator-(const Date& d) const;

	//����-����=����
	Date operator-(int day) const;

	//ǰ��++
	Date& operator++();

	//����++
	Date operator++(int);

	//ǰ��--
	Date& operator--();

	//����--
	Date operator--(int);


	//ȡ��ַ����������
	//Date* operator&() {
	//	return this;
	//	//return NULL;
	//}
	//const Date* operator&() const {
	//	return this;
	//}


    //������<<
	friend ostream& operator<<(ostream& out, const Date& d);

	// ����ȡ>>
	friend istream& operator>>(istream& in, Date& d);

private:
	int _year;
	int _month;
	int _day;
};