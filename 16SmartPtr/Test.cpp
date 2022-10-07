#include <iostream>
#include "SmartPtr.h"

using std::cout;
using std::endl;

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

// template <class T>
// class SmartPtr
// {
// public:
//     SmartPtr(T* ptr) : _ptr(ptr)
//     {}
//
//     //SmartPtr(const SmartPtr& sp)// = delete;
//
//     T& operator*() {
//         return *_ptr;
//     }
//     T& operator->() {
//         return _ptr;
//     }
//
//     SmartPtr& operator++() {
//         ++_ptr;
//     }
//     SmartPtr& operator--() {
//         --_ptr;
//     }
//
//     ~SmartPtr() {
//         delete _ptr;
//     }
//
// private:
//     T* _ptr;
// };
//
// int main()
// {
//     SmartPtr<int> sp1 = new int;
//
//     int* p2 = new int;
//     SmartPtr<int> sp2 = p2;
//
//     (*sp1) = 0;
//
//     (*sp1)++;
//     cout << *sp1 << endl;
//     (*sp1)++;
//     cout << *sp1 << endl;
//
//     SmartPtr<int> sp3(sp1);
//
//
//     return 0;
// }

int main()
{
    //test::test_auto_ptr();
    //test::test_unique_ptr();
    //test::test_shared_ptr();
    test::test_weak_ptr();

    return 0;
}