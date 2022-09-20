#pragma once
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define LINEAR_DETECT 1

namespace NS_Open_Hash
{
    template <class K, class V>
    struct HashNode
    {
        pair<K, V> _kv;
        HashNode<K, V>* _next = nullptr;

        HashNode()
        {}
        HashNode(const pair<K, V>& kv)
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


    template <class K, class V, class HashFunc = Hash<K>>
    class HashTable
    {
        typedef HashNode<K, V> Node;
        HashFunc hf;

    public:
        Node* Find(const K& key)
        {
            if (_table.empty())
                return nullptr;

            size_t pos = hf(key) % _table.size(); // 位置
            Node* curr = _table[pos];

            while (curr)
            {
                if (curr->_kv.first == key) {
                    return curr;
                }
                curr = curr->_next;
            }

            return nullptr;
        }

        bool Insert(const pair<K, V>& kv)
        {
            if (Find(kv.first))
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

                        size_t pos = hf(curr->_kv.first) % newSize; // 找到插入位置
                        // 头插
                        curr->_next = newTable[pos];
                        newTable[pos] = curr;

                        curr = next; // 步进
                    }

                    e = nullptr; // 置空，以便后期释放
                }

                _table.swap(newTable); // 置换
            }

            // 位置
            size_t pos = hf(kv.first) % _table.size();
            // 头插
            Node* newNode = new Node(kv);

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
                if (curr->_kv.first == key)
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
        HashTable<int, int> hash;

        vector<int> v = { 4,24,14,7,37,27,57,67,34,14,54 };

        for (auto e : v) {
            hash.Insert(make_pair(e, e));
        }

        hash.Insert(make_pair(64, 64));


        for (auto e : v)
        {
            cout << e << endl;

            HashNode<int, int>* ret = hash.Find(e);
            printf("%p\n", ret);

            hash.Erase(e);

            ret = hash.Find(e);
            printf("%p\n", ret);

            cout << "---------------------" << endl;
        }
    }

}