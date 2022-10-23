#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
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
            throw string("除零错误");
        }
        else if (b == 1) {
            throw a;
        }
        else {
            cout << "result: " << a / b << endl;
        }
    }
}

void test_exception()
{
    try {
        Func();
    }
    catch (const char* errmsg) {
        cerr << "execption: " << errmsg << endl;
    }
    catch (const int errnum) {
        cerr << "execption: " << errnum << endl;
    }
    catch (...) {
        cerr << "Unkown Exception" << endl;
    }
}

// int main()
// {
//     try {
//         // test_exception();
//         Func();
//     }
//     catch (const string& errstr) {
//         cerr << "main string: " << errstr.c_str() << endl;
//     }
//     catch (const char* errmsg) {
//         cerr << "main: " << errmsg << endl;
//     }
//
//     return 0;
// }

class Exception                          /* 异常基类 */
{
public:
    Exception(const string& errmsg, int id)
        :_errmsg(errmsg), _id(id)
    {}

    virtual string What() const // 多态
    {
        return _errmsg;
    }
protected:
    string _errmsg;
    int _id;
    // list<StackInfo> _traceStack;
    // ...
};

class SqlException : public Exception    /* 数据持久化层 */
{
public:
    SqlException(const string& errmsg, int id, const string sql)
        : Exception(errmsg, id), _sql(sql)
    {}

    virtual string What() const // 多态
    {
        return "SqlException: " + _sql + " : " + _errmsg;
    }
private:
    string _sql;
};

class CacheException : public Exception  /* 缓存服务层 */
{
public:
    CacheException(const string& errmsg, int id)
        : Exception(errmsg, id)
    {}

    virtual string What() const // 多态
    {
        return "CacheException: " + _errmsg;
    }
};

class HttpException : public Exception   /* 网络服务层 */
{
public:
    HttpException(const string& errmsg, int id, const string& type)
        : Exception(errmsg, id), _type(type)
    {}

    virtual string What() const // 多态
    {
        return "HttpException: " + _type + " : " + _errmsg;
    }
private:
    string _type;
};

void SqlMgr()
{
    //...
    if (rand() % 7 == 0)
        throw SqlException("sql sytanx wrong!", 100, "some error sql");
    if (rand() % 8 == 0)
        throw SqlException("permission denied!", 101, "select * from secret");
    //...
    throw "Unkown Exception";
}

void CacheMgr()
{
    //...
    if (rand() % 5 == 0)
        throw CacheException("insufficient space!", 100);
    if (rand() % 6 == 0)
        throw CacheException("permission denied!", 101);
    //...
    SqlMgr();
}

void HttpMgr()
{
    //...
    if (rand() % 3 == 0)
        throw HttpException("resource is not exist!", 100, "post");
    if (rand() % 4 == 0)
        throw HttpException("permission denied!", 101, "post");
    //...
    CacheMgr();
}

void ServerStart()
{
    srand((unsigned int)time(nullptr));
    while (1)
    {
        this_thread::sleep_for(chrono::seconds(1));
        try
        {
            HttpMgr();
        }
        catch (const Exception& e)
        {
            cout << e.What() << endl;
        }
        catch (...)
        {
            cout << "Unkown Exception" << endl;
        }

    }
}

//void test_throw() throw(std::bad_alloc);

void test_throw() noexcept
{
    throw 1;
    //throw "cao";
    cout << "test" << endl;
}

int main()
{
    test_throw();
    // ServerStart();
    // try
    // {
    //     vector<int> v;
    //     v.reserve(10000000000);

    // }
    // catch (const exception& e)
    // {
    //     cout << e.what() << endl;
    // }

    return 0;
}
