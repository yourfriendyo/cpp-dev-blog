#pragma once
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
/*********************************
 * 单例模式
 * 饿汉模式搞对象
 * 懒汉模式搞指针
 *
*/

// int callCount = 0;
// 饿汉模式
class CallInfo_Eager
{
public:
    static CallInfo_Eager& getInstance()
    {
        return _inst;
    }
    void AddCallCount()
    {
        ++_callCount;
    }

    int getCallCount()
    {
        return _callCount;
    }
    void Push(const pair<int, int>& kv)
    {
        _v.push_back(kv);
    }

    CallInfo_Eager(const CallInfo_Eager& cl) = delete;
    CallInfo_Eager& operator=(const CallInfo_Eager& cl) = delete;

private:
    CallInfo_Eager() : _callCount(0)
    {}

private:
    int _callCount;
    vector<pair<int, int>> _v;

    static CallInfo_Eager _inst;
};
CallInfo_Eager CallInfo_Eager::_inst;


// 懒汉模式
class CallInfo_Idler
{
public:
    static CallInfo_Idler* getInstance()
    {
        if (!_inst)
        {
            _inst = new CallInfo_Idler();
        }
        return _inst;
    }
    void AddCallCount()
    {
        ++_callCount;
    }

    int getCallCount()
    {
        return _callCount;
    }
    void Push(const pair<int, int>& kv)
    {
        _v.push_back(kv);
    }

    CallInfo_Idler(const CallInfo_Idler& cl) = delete;
    CallInfo_Idler& operator=(const CallInfo_Idler& cl) = delete;

private:
    CallInfo_Idler() : _callCount(0)
    {}

private:
    int _callCount;
    vector<pair<int, int>> _v;

    static CallInfo_Idler* _inst;
};

CallInfo_Idler* CallInfo_Idler::_inst = nullptr;

// 统计快排递归调用的次数
void QuickSort(int* a, int left, int right)
{
    //CallInfo_Eager::getInstance().AddCallCount();
    //CallInfo_Eager::getInstance().Push(make_pair(left, right));
    CallInfo_Idler::getInstance()->AddCallCount();
    CallInfo_Idler::getInstance()->Push(make_pair(left, right));

    if (left >= right)
    {
        return;
    }

    int keyi = left;
    int prev = left;
    int curr = prev + 1;
    while (curr <= right)
    {
        if (a[curr] < a[keyi] && ++prev != curr)
        {
            swap(a[curr], a[prev]);
        }
        ++curr;
    }

    swap(a[prev], a[keyi]);
    keyi = prev;

    QuickSort(a, left, keyi - 1);
    QuickSort(a, keyi + 1, right);
}

void TestOP()
{
    srand(time(0));
    const int N = 10000;
    int* a1 = new int[N];

    for (int i = 0; i < N; i++)
    {
        a1[i] = rand();
    }

    int begin1 = clock();
    QuickSort(a1, 0, N - 1);
    int end1 = clock();

    cout << end1 - begin1 << endl;
    // cout << CallInfo_Eager::getInstance().getCallCount() << endl;
    cout << CallInfo_Idler::getInstance()->getCallCount() << endl;


    delete[] a1;
}

void testSingleTon()
{

}