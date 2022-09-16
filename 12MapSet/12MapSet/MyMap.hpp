#pragma once
#include <iostream>
#include "RBTree.hpp"

using namespace std;

namespace test
{
    template <class K, class V>
    class map
    {
    public:
        struct MapKeyOfT {
            const operator()(const pair<K, V>& kv) {
                return kv.first;
            }
        };
        bool insert(const pair<K, V>& kv)
        {
            return _t.Insert(kv);
        }

    private:
        RBTree<K, pair<K, V>, MapKeyOfT> _t;
    };

}