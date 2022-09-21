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

        bool insert(const pair<K, V>& kv) {
            return _ht.Insert(kv);
        }

    private:
        HashTable<K, pair<K, V>, MapKeyOfT, hash> _ht;

    };

    void test_unordered_map()
    {
        unordered_map<int, int> um;

    }


}
