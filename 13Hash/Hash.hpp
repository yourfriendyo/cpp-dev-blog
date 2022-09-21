#pragma once
#include <iostream>
#include <vector>
#include <cassert>

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
    struct HashNode
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
        HashNode<K, V>* Find(const K& key)
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
            HashNode<K, V>* ret = Find(kv.first);
            if (ret)
                return false;

            HashFunc hf;

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
            HashNode<K, V>* ret = Find(key);
            if (ret == nullptr)
                return false;
            else
            {
                ret->_status = EMPTY;
                --_n;
                return true;
            }
        }

    private:
        vector<HashNode<K, V>> _table;
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
    template <class T>
    struct HashNode
    {
        T _data;
        HashNode<T>* _next;

        HashNode(const T& data)
            : _data(data), _next(nullptr)
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

    template <class K, class T, class KeyOfT, class HashFunc>
    class HashTable;

    template <class K, class T, class Ref, class Ptr, class KeyOfT, class HashFunc>
    struct __HTIterator
    {
        typedef HashNode<T> Node;
        typedef HashTable<K, T, KeyOfT, HashFunc> HashTable;
        typedef __HTIterator<K, T, Ref, Ptr, KeyOfT, HashFunc> Self;

        Node* _node;
        HashTable* _pht; // 指向哈希表的对象指针

        __HTIterator(Node* node, HashTable* pht)
            : _node(node), _pht(pht)
        {}

        Ref operator*() {
            return _node->_data;
        }

        Ptr operator->() {
            return &_node->_data;
        }

        bool operator==(const Self& it) const
        {
            return _node == it._node;
        }

        bool operator!=(const Self& it) const
        {
            return !(_node == it._node);
        }

        Self& operator++()
        {
            if (_node->_next)
            {
                _node = _node->_next;
            }
            else
            {
                KeyOfT kot;
                HashFunc hf;
                // 计算当前哈希桶位置
                size_t pos = hf(kot(_node->_data)) % _pht->_table.size();
                ++pos;

                // 找到下一个不为空的桶
                while (pos < _pht->_table.size() && !_pht->_table[pos]) {
                    ++pos;
                }

                if (pos < _pht->_table.size()) {
                    _node = _pht->_table[pos]; // 指向该桶的首位元素
                }
                else {
                    _node = nullptr; // 走完了
                }
            }
            return *this;
        }

    };

    template <class K, class T, class KeyOfT, class HashFunc>
    class HashTable
    {
        // 声明友元
        template <class K, class T, class Ref, class Ptr, class KeyOfT, class HashFunc>
        friend struct __HTIterator;
    public:
        typedef HashNode<T> Node;
        typedef __HTIterator<K, T, T&, T*, KeyOfT, HashFunc> iterator;

    private:
        HashFunc hf;
        KeyOfT kot;

    public:
        iterator begin()
        {
            for (auto& e : _table) {
                if (e)
                    return iterator(e, this);
            }
            return end();
        }
        iterator end()
        {
            return iterator(nullptr, this);
        }


    public:
        Node* Find(const K& key)
        {
            if (_table.empty())
                return nullptr;

            size_t pos = hf(key) % _table.size(); // 位置
            Node* curr = _table[pos];

            while (curr)
            {
                if (kot(curr->_data) == key) {
                    return curr;
                }
                curr = curr->_next;
            }

            return nullptr;
        }

        bool Insert(const T& data)
        {
            if (Find(kot(data)))
                return false;

            // 扩容
            if (_table.empty() || _n == _table.size())
            {
                size_t newSize = _table.empty() ? 10 : _table.size() * 2;

                vector<Node*> newTable;
                newTable.resize(newSize);

                for (auto& e : _table) // 遍历原哈希表
                {
                    Node* curr = e;
                    Node* next = curr;

                    // 遍历
                    while (curr != nullptr) // 当下链表不为空
                    {
                        next = curr->_next; // 记录下一个位置

                        size_t pos = hf(kot(curr->_data)) % newSize; // 找到插入位置
                        // 头插
                        curr->_next = newTable[pos];
                        newTable[pos] = curr;

                        curr = next; // 步进
                    }

                    e = nullptr; // 置空
                }

                _table.swap(newTable); // 置换
            }

            // 位置
            size_t pos = hf(kot(data)) % _table.size();
            // 头插
            Node* newNode = new Node(data);

            newNode->_next = _table[pos];
            _table[pos] = newNode;

            ++_n;
            return true;
        }

        bool Erase(const K& key)
        {
            Node* ret = Find(key);
            if (!ret)
                return false;

            size_t pos = key % _table.size();

            Node* prev = nullptr;
            Node* curr = _table[pos]; // 链表起始位置

            while (curr)
            {
                if (kot(curr->_data) == key)
                {
                    // 头删
                    if (prev == nullptr) {
                        _table[pos] = curr->_next;
                    }
                    else
                    {
                        prev->_next = curr->_next; // 链接
                        delete ret; // 释放
                    }
                    --_n;
                    return true;
                }

                prev = curr;
                curr = curr->_next;
            }

            return false;
        }

    private:
        vector<Node*> _table;
        size_t _n;

    };

    void TestHash1()
    {
        // HashTable<int, pair<int, int>> hash;

        // vector<int> v = { 4,24,14,7,37,27,57,67,34,14,54 };

        // for (auto e : v) {
        //     hash.Insert(make_pair(e, e));
        // }

        // hash.Insert(make_pair(64, 64));


        // for (auto e : v)
        // {
            // cout << e << endl;

            // HashNode<int, int>* ret = hash.Find(e);
            // printf("%p\n", ret);

            // hash.Erase(e);

            // ret = hash.Find(e);
            // printf("%p\n", ret);

            // cout << "---------------------" << endl;
        // }
    }

}