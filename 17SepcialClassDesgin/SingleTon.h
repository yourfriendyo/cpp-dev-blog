#pragma once
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// int callCount = 0;
class CallInfo
{
public:
    static CallInfo* getInstance()
    {
        if (!_inst)
        {
            _inst = new CallInfo();
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

    CallInfo(const CallInfo& cl) = delete;
    CallInfo& operator=(const CallInfo& cl) = delete;

private:
    CallInfo() : _callCount(0)
    {}

private:
    int _callCount;
    vector<pair<int, int>> _v;

    static CallInfo* _inst;
};

CallInfo* CallInfo::_inst = nullptr;

// 统计快排递归调用的次数
void QuickSort(int* a, int left, int right)
{
    CallInfo::getInstance()->AddCallCount();
    CallInfo::getInstance()->Push(make_pair(left, right));

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
    cout << CallInfo::getInstance()->getCallCount() << endl;

    delete a1;
}

void testSingleTon()
{

}