#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using std::cout;
using std::endl;

//���㴴���˶��ٸ������
class A {
public:
	A(int a = 0) {
		_sCount++;
	}
	A(const A& a) {
		_sCount++;
	}
	static int GetCount() { //��thisָ��
		return _sCount;
	}
private:
	static int _sCount; //����
};
int A::_sCount = 0; //����
int main()
{
	A a1;
	//...
	cout << A::GetCount() << endl;
	cout << a1.GetCount() << endl;
 

	return 0;
}