#include <iostream>

using namespace std;

// int div()
// {
// 	int a = 0, b = 0;
// 	cin >> a >> b;
// 	if (b == 0)
// 		throw invalid_argument("division by zero!");
//
// 	return a / b;
// }
//
// void Func()
// {
// 	int* p = new int;
// 	cout << div() << endl;
//
// 	cout << "delete p :" << p << endl;
// 	delete p;
// }
//
// int main()
// {
//     try
//     {
//         Func();
//     }
//     catch (const exception& e)
//     {
//         cout << e.what() << endl;
//     }
//
//
//     return 0;
// }

template <class T>
class SmartPtr
{
public:
    SmartPtr(T* ptr) : _ptr(ptr)
    {}

    ~SmartPtr()
    {
        delete _ptr;
    }

private:
    T* _ptr;
};

int main()
{
    SmartPtr<int> sp1 = new int;

    int* p2 = new int;
    SmartPtr<int> sp2 = p2;


    return 0;
}