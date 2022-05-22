#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Car {
public:
	virtual void f() = 0;
};

class BMW : public Car {
public:
	virtual void f() {
		cout << "BMW" << endl;
	}
};

int main()
{
	//Car c; //Err

	//Car* c = nullptr;
	//c->f(); //Err

	Car* c = new BMW;
	c->f();

	return 0;
}