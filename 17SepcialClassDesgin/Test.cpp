#include <iostream>
#include "SingleTon.h"
using namespace std;

// 只能在堆上创建对象
class HeapOnly
{
public:
    static HeapOnly* getObject()
    {
        return new HeapOnly;
    }

    // 禁掉拷贝和赋值
    HeapOnly(const HeapOnly& ho) = delete;
    HeapOnly& operator=(const HeapOnly& ho) = delete;

private:
    HeapOnly() : _a(0) // 构造函数私有化，不允许直接使用构造创建对象
    {}

private:
    int  _a;
};

void testHeapOnly()
{
    HeapOnly* pho = HeapOnly::getObject(); // 非静态成员函数需要对象才能调用，现在没有对象，只能用静态函数
    // HeapOnly ho;
    // HeapOnly* pho = new HeapOnly;
}

class StackOnly
{
public:
    static StackOnly&& getObj() // 封装构造函数
    {
        return StackOnly();
    }

    void* operator new(size_t size) = delete; // 禁掉new关键字
    void operator delete(void* p) = delete; // 禁掉delete关键字

private:
    StackOnly() : _a(0)
    {}

private:
    int _a;
};

void testStackOnly()
{
    // StackOnly* ptr = new HeapOnly;

    StackOnly so1 = StackOnly::getObj();
    //StackOnly* so2 = new StackOnly(so1); // 利用拷贝构造new一个对象
}

class CopyBan
{
public:
    CopyBan() : _a(0)
    {}

    //C++11
    //CopyBan(const CopyBan& cb) = delete;
    //CopyBan& operator=(const CopyBan& cb) = delete;
private:
    CopyBan(const CopyBan& cb);
    CopyBan& operator=(const CopyBan& cb);

private:
    int _a;
};

void testCopyBan()
{
    CopyBan cb;
    // CopyBan cb1(cb);
}

// class InheBan
// {
// public:
// 	InheBan getObj()
// 	{
// 		return InheBan();
// 	}
//
// private:
// 	InheBan() : _a(0) //C++98 智能将构造函数私有化
// 	{}
//
// private:
// 	int _a;
//
// };

class InheBan final // C++11 直接支持final
{
public:
    InheBan() : _a(0)
    {}

private:
    int _a;
};

void testInhBan()
{}


int main()
{
    // testSingleTon();
    TestOP();

    return 0;
}
