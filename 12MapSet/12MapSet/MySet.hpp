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
        struct SetKeyOfK
        {
            const K& operator()(const K& key) {
                return key;
            }
        };

        bool insert(const K& key)
        {
            return _t.Insert(key);
        }

        void inorder() {
            _t.Inorder();
        }

    private:
        RBTree<K, K, SetKeyOfK> _t;
    };

    void test_set()
    {
        srand(time(nullptr));
        set<int> s;

        // vector<int> v = { 1,2,3,4,5,6 };

        int N = 1000;
        vector<int> v;
        for (int i = 0; i < N; i++)
            v.push_back(rand());

        for (auto e : v)
        {
            s.insert(e);
            s.inorder();
        }
    }
}