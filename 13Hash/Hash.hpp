#pragma once
#include <iostream>
#include <vector>

using namespace std;


// 状态
enum STATUS
{
    EXIST,  // 存在
    EMPTY,  // 为空
    DELETE  // 被删
};


template <class K, class V>
struct HashData
{
    pair<K, V> _kv;
    STATUS _status = EMPTY; // 存储位置上数据的状态
};


template <class K, class V>
class HashTable
{
public:
    HashData<K, V>* Find(const K& key)
    {

        return nullptr;
    }

    bool Insert(const pair<K, V>& kv)
    {
        // 增容
        if (_table.size() == 0 || _n * 10 / _table.size() >= 7)
        {
            size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;

            HashTable<K, V> newHT;
            newHT._table.resize(newSize);

            for (auto e : _table)
            {
                if (e._status == EXIST)
                    newHT.Insert(e._kv);
            }

            _table.swap(newHT._table);
        }

        // 探测
        size_t pos = kv.first % _table.size(); // 线性探测的起始位置
        size_t index = pos;
        size_t i = 0;

        while (_table[index]._status == EXIST)
        {
            i++;
            // index = pos + i;
            index = pos + i * i;

            index %= _table.size(); // 环形防止越界
        }

        // 插入
        _table[index]._kv = kv;
        _table[index]._status = EXIST;
        ++_n;

        return true;

    }



    bool erase()
    {

    }

private:
    vector<HashData<K, V>> _tables;
    size_t _n = 0; // 有效存储数据个数

};

void TestHash1()
{
    HashTable<int, int> hash;

    vector<int> v1 = { 2 };
    vector<int> v2 = { 2,12 };
    vector<int> v3 = { 2,12,22 };
    vector<int> v4 = { 2,12,22,32 };
    vector<int> v5 = { 2,12,22,32,42 };
    vector<int> v6 = { 2,12,22,32,42,52 };
    vector<int> v7 = { 2,12,22,32,42,52,62 };

    for (auto e : v7)
    {
        hash.Insert(make_pair(e, e));
    }

}