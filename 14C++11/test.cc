#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include "List.h"
using namespace std;

struct Point
{
    int _x;
    int _y;
public:
    Point(int x, int y) : _x(x), _y(y)
    {}
};

class A
{
public:
    A(int a) : _a(a)
    {}
private:
    int _a;
};

void test_initializer_list()
{
    Point p = { 1 , 2 };              // C++98
    Point pp{ 1 , 2 };                // C++11
    Point parr[]{ {1, 2}, {3, 4} };   // C++11

    int a = 1;                        // C++98
    int b1 = { 2 };                   // C++11
    int b2{ 2 };                      // C++11
    int b3({ 2 });                    // C++11

    int* ptr1 = new int[5];           // C++98
    int* ptr2 = new int[5] {1, 2, 3}; // C++11

    int arr[10] = { 1, 2, 3, 4 };     // C++98
    vector<int> v = { 1,2, 3,4 };     // C++11

    A a2 = 2;               // 单参数隐式类型转换
    //Point pp{ 1 , 2 };    // 多参数隐式类型转换


    initializer_list<int> il = { 1,2,3,4,5,6 };

    vector<int> v1 = { 1,2,3,4,5,6 };
    list<int> lt1 = { 1,2,3,4,5,6 };

    pair<string, string> kv = { "left", "左边" };
    map<string, string> dict = {
        {"sort", "排序"},
        {"insert", "插入"},
        {"map", "地图"},
        kv,
        make_pair("list", "列表")
    };

    test::test_list();
};

int func(int a)
{
    cout << "int func(int a)" << endl;
    return a;
}

void test_type_declare()
{
    int x = 1;
    double y = 2.2;

    cout << typeid(x).name() << endl; // 获取变量类型名
    decltype(x) i = 1; // 使用x的类型创建变量

    int(*pfunc1)(int) = &func;
    decltype(func) pfunc2;

}

int fmin(int& x, int& y)
{
    return x < y ? x : y;
}

void test_right_value_ref()
{
    double x = 1.1, y = 2.2;
    int a = 0;
    int* p = new int(0);

    const int& r1 = 10;
    const int& r2 = x + y;
    const int& r3 = fmin(x, y);

    int*&& rr1 = std::move(p);
    int&& rr2 = std::move(*p);
    int&& rr3 = std::move(a);

    int&& rrr1 = 10;
    cout << &rrr1 << endl;



}

int main()
{
    // test_initializer_list();
    // test_type_declare();

    test_right_value_ref();


    return 0;
}