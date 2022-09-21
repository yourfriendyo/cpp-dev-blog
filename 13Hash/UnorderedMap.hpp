#pragma once
#include <iostream>
#include "Hash.hpp"
using namespace std;
using namespace NS_Open_Hash;

namespace NS_Unordered_Map
{
    template <class K, class V, class hash = Hash<K>>
    class unordered_map
    {
    public:
        struct MapKeyOfT {
            const K& operator()(const pair<K, V>& kv) {
                return kv.first;
            }
        };

    public:
        typedef typename HashTable<K, pair<K, V>, MapKeyOfT, hash>::iterator iterator;

        iterator begin() {
            return _ht.begin();
        }
        iterator end() {
            return _ht.end();
        }

        bool insert(const pair<K, V>& kv) {
            return _ht.Insert(kv);
        }

    private:
        HashTable<K, pair<K, V>, MapKeyOfT, hash> _ht;
    };

    void test_unordered_map()
    {
        unordered_map<int, int> um;

        vector<int> v = { 2,12,22,32,42,52,62 };

        for (auto e : v)
        {
            um.insert(make_pair(e, e));
        }

        unordered_map<int, int>::iterator it = um.begin();
        while (it != um.end())
        {
            cout << it->first << ":" << it->second << endl;
            ++it;
        }

    }


}
