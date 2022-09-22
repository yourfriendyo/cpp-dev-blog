#pragma once
#include <iostream>
#include "Hash.hpp"
using namespace std;
using namespace NS_Open_Hash;

namespace NS_Unordered_Set
{
    template <class K, class hash = Hash<K>>
    class unordered_set
    {
    public:
        struct SetKeyOfT {
            const K& operator()(const K& key) {
                return key;
            }
        };

    public:
        typedef typename HashTable<K, K, SetKeyOfT, hash>::iterator iterator;

        iterator begin() {
            return _ht.begin();
        }
        iterator end() {
            return _ht.end();
        }

        pair<iterator, bool> insert(const K& key) {
            return _ht.Insert(key);
        }

    private:
        HashTable<K, K, SetKeyOfT, hash> _ht;
    };

    void test_unordered_set()
    {
        unordered_set<int> ius;

        ius.insert(1);
        ius.insert(8);
        ius.insert(4);
        ius.insert(5);
        ius.insert(5);
        ius.insert(14);

        unordered_set<int>::iterator it = ius.begin();
        while (it != ius.end())
        {
            cout << *it << endl;
            ++it;
        }

        unordered_set<string> sus;

        sus.insert("string");
        sus.insert("top");
        sus.insert("resize");
        sus.insert("insert");
        sus.insert("qwer");
        sus.insert("your");


    }

}
