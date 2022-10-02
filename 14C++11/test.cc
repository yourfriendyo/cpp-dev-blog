#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <thread>
#include "List.h"
#include "String.h"

using std::cout;
using std::endl;

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

    //test::test_list();
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

void func1(test::string s)
{}

void func2(const test::string& s)
{}

test::string func3()
{
    test::string s("hello");
    return s;
}

void Func(int& x) { cout << "左值引用" << endl; }
void Func(const int& x) { cout << "const左值引用" << endl; }
void Func(int&& x) { cout << "右值引用" << endl; }
void Func(const int&& x) { cout << "const右值引用" << endl; }

template <class T>
void PerfectForward(T&& t)
{
    Func(std::forward<T>(t));
}

void test_right_value_ref()
{
    // double x = 1.1, y = 2.2;
    // int a = 0;
    // int* p = new int(0);
    //
    // const int& r1 = 10;
    // const int& r2 = x + y;
    // const int& r3 = fmin(x, y);
    //
    // int*&& rr1 = std::move(p);
    // int&& rr2 = std::move(*p);
    // int&& rr3 = std::move(a);
    //
    // int&& rrr1 = 10;
    // cout << &rrr1 << endl;

    // func1(str);
    // func2(str);
    // func3();

    // test::string s("hello world");
    //
    // test::string s1 = s;
    // test::string s2 = std::move(s);
    // test::string s3 = s1 + s2;

    // test::string toS = test::to_string(1234);
    //
    // cout << func3().c_str() << endl;
    // test::string ret = func3();

    // test::string s1("hello world");
    // test::string s2;

    // //s2 = move(s1);
    // //s2 = func3();

    // test::list<test::string> lt;
    // lt.push_back(std::move(s1));
    // cout << endl;

    // lt.push_back(func3());
    // cout << endl;

    // lt.push_back("constant");
    // cout << endl;


    //PerfectForward(10);

    //int a;
    //PerfectForward(a);
    //PerfectForward(std::move(a));

    //const int b = 8;
    //PerfectForward(b);
    //PerfectForward(std::move(b));

    test::list<test::string> lt;
    lt.push_back("list");

}

struct Good
{
    string _name;
    double _price;
    int _eval; // 评分
    Good(const char* name, double price, int eval)
        :_name(name), _price(price), _eval(eval)
    {}
};

struct CompareByPrice {
    // price 升序
    bool operator()(const Good& g1, const Good& g2) {
        return g1._price > g2._price;
    }
};

void test_lambda_express()
{
    int a = 1, b = 2;
    auto swap1 = [](int& x, int& y) { // 引用传参
        int tmp = x;
        x = y;
        y = tmp;
    };

    auto swap2 = [a, b]() mutable {  // mutable 去除变量的const常属性，但不影响传值调用
        int tmp = a;
        a = b;
        b = tmp;
    };

    auto swap3 = [&a, &b]() { // 引用捕捉
        int tmp = a;
        a = b;
        b = tmp;
    };

    auto swap4 = [&]() mutable { // 全引用捕捉
        int tmp = a;
        a = b;
        b = tmp;
    };

    [=]() {};

    // swap(a, b);
    // swap3();
    //
    // cout << "a:" << a << " - " << "b:" << b << endl;

    vector<Good> v = { {"apple", 1, 5} ,{"banana", 3, 4} , {"orange", 2.2, 3} };
    // sort(v.begin(), v.end(), CompareByPrice());

    sort(v.begin(), v.end(), [](Good& g1, Good& g2) { return g1._price > g2._price; });
    sort(v.begin(), v.end(), [](Good& g1, Good& g2) { return g1._price < g2._price; });
    sort(v.begin(), v.end(), [](Good& g1, Good& g2) { return g1._eval > g2._eval; });
    sort(v.begin(), v.end(), [](Good& g1, Good& g2) { return g1._eval < g2._eval; });

    auto lamdba = []() {};
    cout << typeid(lamdba).name() << endl;
}

// void Swap(int a, int b) const 只有成员函数才有const一说
// {
//     int t = a;
//     a = b;
//     b = t;
// }

class Person
{
public:
    Person(const char* name = "", int age = 18) : _name(name), _age(age)
    {}
    // #define kbgz 1
    // #define kbfz 1
    // #define xg 1

#ifdef kbgz
    Person(const Person& p) : _name(p._name), _age(p._age)
    {}
#endif

#ifdef kbfz
    Person operator=(const Person& p)
    {
        if (this == &p) {
            Person tmp(p);
            return tmp;
        }
        return *this;
    }
#endif

#ifdef xg
    ~Person()
    {}
#endif

private:
    test::string _name;
    int _age;

};
void test_move_member_func()
{
    Person p1("hello", 18);

    Person p2 = std::move(p1);
    p1 = std::move(p2);
}

// template <class ...Args>
// void ShowList(Args... args)
// {
//     cout << sizeof...(Args) << endl;
//     cout << sizeof...(args) << endl;
//
//     cout << endl;
// }

// void ShowList() // 递归终止函数
// {}
//
// template <class Now_Type, class ...TypeSet>
// void ShowList(Now_Type now_arg, TypeSet... args)
// {
//     cout << typeid(now_arg).name() << ":" << now_arg << endl;
//     ShowList(args...); // 参数包向下传递
//
//     cout << endl;
// }

template <class T>
int ShowArgs(T arg)
{
    cout << typeid(arg).name() << ":" << arg << endl;
    return 0;
}

template <class ...TypeSet>
void ShowList(TypeSet... args)
{
    int arr[] = { ShowArgs(args)... }; // 利用列表初始化过程
}

void test_variadic_templates()
{
    // ShowList(1);
    // ShowList(1, "A");
    ShowList(1, "A", 1.1);
}

template <class F, class T>
T useF(F f, T x)
{
    static int cnt = 0;
    cout << (++cnt) << endl;
    cout << (&cnt) << endl;

    return f(x);
}

double f(double i) {
    return i / 2;
}

struct Functor {
    double operator()(double x) {
        return x / 2;
    }
};

void test_function_adapter()
{
    cout << useF(f, 10.10) << std::endl;;
    cout << useF(Functor(), 10.10) << std::endl;
    cout << useF([](double x) {return x / 2;}, 10.10) << std::endl;

}

void Print(int l, int r, int x)
{
    // for (int i = l; i < r; ++i) {
    //     cout << i * x << endl;
    // }
    // cout << "id: " << this->get_id();
}

void test_thread()
{
    // thread t1;
    // thread t2(Print, 1, 20, 2);
    // t2.join();

    int n;
    cin >> n;
    vector<thread> thdsv;
    thdsv.resize(n);

    for (auto& td : thdsv) {
        td = thread(Print, 1, 10, 1);
    }

    for (auto& td : thdsv) {
        td.join();
    }

}

int main()
{

    // test_initializer_list();
    // test_type_declare();
    // test_right_value_ref();
    // test_lambda_express();
    // test_move_member_func();
    // test_variadic_templates();

    // test_thread();

    test_function_adapter();



    return 0;
}