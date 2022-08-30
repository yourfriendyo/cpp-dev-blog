#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//class A {
//public:
//	virtual void vFunc1() { cout << "A::vFunc1()" << endl; }
//	virtual void vFunc2() { cout << "A::vFunc2()" << endl; }
//protected:
//	int _a;
//};
//class B : public A {
//public:
//	virtual void vFunc1() { cout << "B::vFunc1()" << endl; } //重写
//	virtual void vFunc3() { cout << "B::vFunc3()" << endl; }
//	virtual void vFunc4() { cout << "B::vFunc4()" << endl; }
//protected:
//	int _b;
//};

//class A {
//public:
//	virtual void vFunc1() { cout << "A::vFunc1()" << endl; }
//	virtual void vFunc2() { cout << "A::vFunc2()" << endl; }
//protected:
//	int _a;
//};
//class B {
//public:
//	virtual void vFunc1() { cout << "B::vFunc1()" << endl; }
//	virtual void vFunc2() { cout << "B::vFunc2()" << endl; }
//protected:
//	int _b;
//};
//class C : public A, public B {
//public:
//	virtual void vFunc1() { cout << "C::vFunc1()" << endl; } //重写父类的vFunc1
//	virtual void vFunc3() { cout << "C::vFunc3()" << endl; }
//protected:
//	int _c;
//};
#define VIRTUAL

class A {
public:
	virtual void vFunc1() { cout << "A::vFunc1()" << endl; }
	virtual void vFunc2() { cout << "A::vFunc2()" << endl; }
	int _a;
};
class B : public A {
public:
	virtual void vFunc1() { cout << "B::vFunc1()" << endl; } //重写虚基类的vFunc1
	virtual void vFunc2() { cout << "B::vFunc2()" << endl; }
	int _b;
};
class C : public A {
public:
	virtual void vFunc1() { cout << "C::vFunc1()" << endl; } //重写虚基类的vFunc1
	virtual void vFunc3() { cout << "C::vFunc3()" << endl; }
	int _c;
};
#ifdef VIRTUAL
class D : virtual public B, virtual public C {
#else 
class D : public B, public C {
#endif
public:
	virtual void vFunc() { cout << "C::vFunc1()" << endl; } //重写父类的vFunc1
	virtual void vFunc4() { cout << "C::vFunc3()" << endl; }
	int _d;
};


typedef void(*VF_PTR)(); //虚函数指针 

void PrintVFTable(VF_PTR* table)  //虚表指针
{
	for (int i = 0; table[i] != nullptr; ++i) {
		printf("vf_table[%d][%p]->", i, table[i]);
		table[i]();
	}
}

//void Func(A& a) 
//{
//	VF_PTR* vf_table_ptr = (VF_PTR*)*(int*)&a; //虚表指针
//	VF_PTR vf1_ptr = *vf_table_ptr;
//	vf1_ptr();
//	VF_PTR vf2_ptr = *(vf_table_ptr + 1);
//	vf2_ptr();
//	VF_PTR vf3_ptr = *(vf_table_ptr + 2);
//	vf3_ptr();
//	cout << endl;
//}

int main()
{
	A a;
	B b;
	C c;
	/*Func(a);
	Func(b);*/
	//#ifdef _WIN64
	//	PrintVFTable((VF_PTR*)*(void**)&b);
	//#else
	//	PrintVFTable((VF_PTR*)*(int*)&c);
	//#endif

		//PrintVFTable((VF_PTR*)*(void**)&c);
		//cout << endl;
		////PrintVFTable((VF_PTR*)*(void**)((char*)&c+sizeof(A))); //B
		//B* pb = &c;
		//PrintVFTable((VF_PTR*)*(void**)pb);

	//A* pa = &c;
	//B* pb = &c;
	//PrintVFTable((VF_PTR*)*(void**)pa);
	//PrintVFTable((VF_PTR*)*(void**)pb);

	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;

	B* pb = &d;
	C* pc = &d;
	D* pd = &d;
	PrintVFTable((VF_PTR*)*(void**)pb);
	cout << endl;
	PrintVFTable((VF_PTR*)*(void**)pc);
	cout << endl;
	PrintVFTable((VF_PTR*)*(void**)pd);
	cout << endl;
	
	return 0;
}
