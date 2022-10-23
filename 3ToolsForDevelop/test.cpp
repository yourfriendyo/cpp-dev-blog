#include <iostream>
using namespace std;
class Stack {
public:
	Stack(int capacity = 0) 
		: _a(nullptr)
		, _top(0)
		, _capacity(capacity)
	{}
private:
	int* _a;
	int _top;
	int _capacity;
};

int main()
{
	Stack st;
	return 0;
}
