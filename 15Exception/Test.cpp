#include <iostream>
#include "String.h"

using namespace std;

void Func()
{
    while (1)
    {
        int a, b;
        cin >> a >> b;
        if (b == 0)
        {
            // throw "Division by zero condition";
            throw test::string("除零错误");
        }
        else if (b == 1) {
            throw a;
        }
        else {
            cout << "result: " << a / b << endl;
        }
    }
}

// void test_exception()
// {
//     try {
//         Func();
//     }
//     catch (const char* errmsg) {
//         cerr << "execption: " << errmsg << endl;
//     }
//     catch (const int errnum) {
//         cerr << "execption: " << errnum << endl;
//     }
//     catch (...) {
//         cerr << "Unkown Exception" << endl;
//     }
// }

int main()
{
    try {
        // test_exception();
        Func();
    }
    catch (const test::string& errstr) {
        cerr << "main string: " << errstr.c_str() << endl;
    }
    catch (const char* errmsg) {
        cerr << "main: " << errmsg << endl;
    }
    // catch (const int errnum) {
    //     cerr << "main: " << errnum << endl;
    // }
    catch (...) {
        cerr << "Unkown Exception" << endl;
    }

    return 0;
}