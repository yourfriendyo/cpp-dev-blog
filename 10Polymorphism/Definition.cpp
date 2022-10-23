#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Person {
public:
	//virtual void BuyTicket(int i) { //Err
	//void BuyTicket() { //Err
	//virtual Person& BuyTicket() {
	virtual void BuyTicket() {
		cout << "成人全价" << endl; 
	}
};
class Student : public Person {
public:
	//virtual void BuyTicket(char c) { //Err
	//void BuyTicket() { //Err
	//virtual Student& BuyTicket() {
	virtual void BuyTicket() {
		cout << "学生半价" << endl;
	}
};
void Func(Person& p) { //父类指针或引用
	p.BuyTicket();
}
int main()
{
	//int i = 0;
	//double d = 1.1;

	//cout << i;  //cout.operator<<(int);
	//cout << d;  //cout.operator<<(double);

	//cout.operator<<(i);
	//cout.operator<<(d);

	Person p;
	Student s;
	Func(p);
	Func(s);

	return 0;
}

class A {
public:
	virtual ~A() { cout << "~A()" << endl; }
};
class B : public A {
public:
	virtual ~B() { cout << "~B()" << endl; }
};
int main() 
{
	//A a;
	//B b;

	//operator new + constructor
	A* pa = new A; 
	A* pb = new B; 
	
	//operator delete + destructor
	delete pa; // pa->destructor()
	delete pb; // pb->destructor() - 父类的指针成功调用构成多态的析构函数

	return 0;
}

class Person {
public:
	virtual void BuyTicket() { cout << "成人全价" << endl; }
	virtual ~Person() { cout << "~Person()" << endl; }
};
class Student : public Person {
//public: //属性被继承
	void BuyTicket() { cout << "学生半价" << endl; }
	~Student() { cout << "~Student()" << endl; }
};

void Func(Person* p) {
	p->BuyTicket();
}

int main()
{
	Person* p = new Person;
	Person* s = new Student;
	Func(p);
	Func(s);

	delete p;
	delete s;
}

class A  {
class A final {
public:
private:
	A(int a = 0) 
		:_a(a)
	{
		cout << "A()" << endl;
	}
public:
	static A CreateObj(int a = 0) {
		A* aa = new A(a);
		return *aa;
	}
protected:
	int _a;
};

class B : public A {
public:
	B() {
		cout << "B()" << endl;
	}
protected:
	int _s;
};

class C {
protected:
	virtual void f() {
		cout << "C::f()" << endl;
	}
};

class D : public C {
protected:
	virtual void f() override {
		cout << "D::f()" << endl;
	}
};


int main()
{
	B s;

	C c;
	D d;

	return 0;
}