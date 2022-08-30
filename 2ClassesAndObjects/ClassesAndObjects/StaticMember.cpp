#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using std::cout;
using std::endl;

//计算创建了多少个类对象
class A {
public:
	A(int a = 0) {
		_sCount++;
	}
	A(const A& a) {
		_sCount++;
	}
	static int GetCount() { //无this指针
		return _sCount;
	}
private:
	static int _sCount; //声明
};
int A::_sCount = 0; //定义
int main()
{
	A a1;
	//...
	cout << A::GetCount() << endl;
	cout << a1.GetCount() << endl;
 

	return 0;
}