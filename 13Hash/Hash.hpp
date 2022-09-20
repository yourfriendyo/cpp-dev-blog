#pragma once
#include <iostream>
#include <vector>

using namespace std;

#define LINEAR_DETECT 1

namespace NS_Close_Hash
{
    // 状态
    enum STATUS
    {
        EXIST,  // 存在
        EMPTY   // 为空
    };

    template <class K, class V>
    struct HashData
    {
        pair<K, V> _kv;
        STATUS _status = EMPTY; // 存储位置上数据的状态
    };

    template<class K>
    struct Hash
    {
        size_t operator()(const K& key)
        {
            return key;
        }
    };
    // 特化
    template<>
    struct Hash<string>
    {
        //BKDR
        size_t operator()(const string& s)
        {
            size_t value = 0;
            for (auto ch : s) {
                value = value * 131 + ch;
            }

            return value;
        }
    };

    struct Date
    {
        int _year;
        int _month;
        int _day;
    };
    struct HashDate
    {
        size_t operator()(const Date& date) {
            return date._year + date._month + date._day;
        }
    };


    template <class K, class V, class HashFunc = Hash<K>>
    class HashTable
    {
    public:
        HashData<K, V>* Find(const K& key)
        {
            if (_table.size() == 0)
                return nullptr;

            HashFunc hf;

            size_t pos = hf(key) % _table.size();
            size_t index = pos;
            size_t i = 0;

            while (_table[index]._status == EXIST)
            {
                if (_table[index]._kv.first == key)
                {
                    return &_table[index];
                }

                ++i;
#ifdef LINEAR_DETECT
                index = pos + i;
#else
                index = pos + i * i;
#endif
                index %= _table.size();
            }

            return nullptr;
        }

        bool Insert(const pair<K, V>& kv)
        {
            HashData<K, V>* ret = Find(kv.first);
            if (ret)
                return false;

            HashFunc hf;

            // 增容
            if (_table.size() == 0 || _n * 10 / _table.size() >= 7)
            {
                size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;

                HashTable<K, V, HashFunc> newHT;
                newHT._table.resize(newSize);

                for (auto e : _table)
                {
                    if (e._status == EXIST)
                        newHT.Insert(e._kv);
                }

                _table.swap(newHT._table);
            }

            // 探测
            size_t pos = hf(kv.first) % _table.size(); // 线性探测的起始位置
            size_t index = pos;
            size_t i = 0;

            while (_table[index]._status == EXIST)
            {
                i++;
#ifdef LINEAR_DETECT
                index = pos + i;
#else
                index = pos + i * i;
#endif
                index %= _table.size(); // 环形防止越界
            }

            // 插入
            _table[index]._kv = kv;
            _table[index]._status = EXIST;
            ++_n;

            return true;

        }

        bool Erase(const K& key)
        {
            HashData<K, V>* ret = Find(key);
            if (ret == nullptr)
                return false;
            else
            {
                ret->_status = EMPTY;
                return true;
            }
        }

    private:
        vector<HashData<K, V>> _table;
        size_t _n = 0; // 有效存储数据个数

    };

    void TestHash1()
    {
        // HashTable<int, int, Hash<int>> hash;
        HashTable<int, int> hash;

        vector<int> v7 = { 2,12,22,32,42,52,62 };

        for (auto e : v7)
        {
            hash.Insert(make_pair(e, e));
        }

        hash.Insert(make_pair(-1, -1));
        hash.Insert(make_pair(-9, -9));

    }

    void TestHash2()
    {
        // HashStr hs;
        // cout << hs("sort") << endl;
        // cout << hs("insert") << endl;
        //
        // cout << hs("ate") << endl;
        // cout << hs("eta") << endl;


        // HashTable<string, string, Hash<string>> ht;
        HashTable<string, string> ht;

        ht.Insert(make_pair("sort", "排序"));
        ht.Insert(make_pair("string", "字符串"));
        ht.Insert(make_pair("map", "地图"));
        ht.Insert(make_pair("develop", "开发"));

        // HashTable<Date, Date> hd;
    }

}

namespace NS_Open_Hash
{
    template <class K, class V>
    struct HashData
    {
        pair<K, V> _kv;
        HashData<K, V>* _next = nullptr;

        HashData()
        {}

        HashData(const pair<K, V>& kv)
            : _kv(kv)
        {}
    };

    template <class K>
    struct Hash
    {
        size_t operator()(const K& key) {
            return key;
        }

    };
    template<>
    struct Hash<string>
    {
        size_t operator()(const string& s)
        {
            size_t ret = 0;
            for (auto ch : s)
                ret = ret * 131 + ch;

            return ret;
        }
    };


    template <class K, class V, class Hash<K> >
    class HashTable
    {
        HashData<K, V>* Find(const K& key)
        {
            if (_table.size() == 0)
                return nullptr;

            int pos = key % _table.size(); // 位置
            HashData<K, V>* list = &_table[pos];

            while (list->_next)
            {
                if (list->_kv.first == key) {
                    return list;
                }
                list = list->_next;
            }
            return nullptr;
        }

        bool Insert(const pair<K, V> kv)
        {
            if (Find(kv.first))
                return false;

            if (_table.size() == 0 || _n * 10 / _table.size() >= 7)
            {
                size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;

                HashTable<K, V> newHT;
                newHT._table.resize(newSize);

                for (auto e : _table)
                    newHT.Insert(e);

                _table.swap(newHT._table);
            }

            size_t pos = kv.first % _table.size(); // 位置

            HashData<K, V>* list = &_table[pos]; // 获取链表地址
            if (!list) // 头插
            {
                HashData<K, V>* newNode = HashData(kv);
                _table[pos] = newNode;
            }

            //尾插
            while (list->_next) {
                list = list->_next;
            }

            HashData<K, V>* newNode = HashData(kv);
            list->_next = newNode;
        }

        bool Erase(const K& key)
        {
            HashData<K, V>* ret = Find(key);
            if (!ret) {
                return false;
            }
            else
            {
                size_t pos = key % _table.size();

                HashData<K, V>* next = ret->_next;
                HashData<K, V>* prev = _table[pos];

                while (prev->_next->_kv.first != key) {
                    prev = prev->_next;
                }

                prev->_next = next; // 链接
                delete prev->_next; // 释放

                return true;
            }
        }
    private:
        vector<HashData<K, V>> _table;
        size_t n;

    };

}