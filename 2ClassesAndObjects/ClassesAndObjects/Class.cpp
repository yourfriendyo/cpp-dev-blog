#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#include <iostream>
using namespace std;


/********************* 类和对象 上 ****************************/
struct Student {
	//成员变量
	char _name[20];
	int _age;
	int _id;
	//成员方法
	void Init(const char* name, int age, int id) {
		strcpy(_name, name);
		_age = age;
		_id = id;
	}
	void Print() {
		cout << _name << endl;
		cout << _age << endl;
		cout << _id << endl;
	}
};

class student {
private:
	//成员变量
	char _name[20];
	int _age;
	int _id;
public:
	//成员方法
	void init(const char* name, int age, int id) {
		strcpy(_name, name);
		_age = age;
		_id = id;
	}
	void print() {
		cout << _name << endl;
		cout << _age << endl;
		cout << _id << endl;
	}
};


class Stack {
public:
	Init();
	Push(int x);
	// ...
private:
	int* _a;
	int _top;
	int _capacity;
}; 

int main() {

	struct Student s1;
	Student s2;
	strcpy(s1.name, "yyo");
	strcpy(s2.name, "yyx");
	s1.age = 18;
	s2.age = 19;
	s1.id = 11; 
	s2.id = 22;

	s1.Init("yyo", 19, 1);
	s1.Print();
	s2.Init("yyx", 18, 2);
	s2.Print();

	Stack st;
	st._a;//Err
	st.Init();
	st.Push(1);
	st.Push(2);
	st.Push(3);
	int ret = st.Top();
	cout << ret << endl;

	cout << sizeof(Stack) << endl;
	cout << sizeof(st) << endl;

	return 0;
}


class Date {
public:
	//void Init(Date* this, int year, int month, int day)
	void Init(int year, int month, int day) {
		//Date::year = year;
		_year = year;
		_month = month;
		_day = day;
		//this->_year = year;
		//this->_month = month;
		//this->_day = day;
	}
	//void Print(Date* this)
	void Print() {
		cout << _year << "-" << _month << "-" << _day << endl;
		//cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	d1.Init(2020, 1, 18); // d1.Init(&d1,2020,1,18);
	d1.Print(); // d1.Print(&d1);
	Date d2;
	d2.Init(2020, 1, 19); // d2.Init(&d2,2020,1,19);
	d2.Print(); // d2.Print(&d2);

	return 0;
}


//d1.Print(); -> d1.Print(&d1);
//
//d2.Print(); -> d2.Print(&d2);


class A {
public:
	void Printa() {
		cout <<  _a << endl;
	}
	void Show() {
		cout << "Show()" << endl;
	}
private:
	int _a;
};

int main()
{
	A* a = nullptr;
	//1.
	a->Show();
	//2.
	a->Printa();
	return 0;
}