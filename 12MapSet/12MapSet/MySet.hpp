#pragma once
#include <iostream>
#include "RBTree.hpp"

using namespace std;

namespace test
{
    template <class K>
    class set
    {
    public:
        struct SetKeyOfK {
            const operator()(const K& key) {
                return key;
            }
        };
        bool insert(const K& key)
        {
            return _t.Insert(key);
        }

    private:
        RBTree<K, K, SetKeyOfK> _t;
    };

}