#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
class A {
private:
	static int _i;
	int _a; 
public:
	int GetSize() {
		return sizeof(A);
	}
	class B {
	private:
		int _b;
	};
};
int main()
{
	cout << A().GetSize() << endl;

	return 0;
}