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

        typedef typename RBTree<K, K, SetKeyOfK>::iterator iterator;

        iterator begin() {
            return _t.begin();
        }

        iterator end() {
            return _t.end();
        }

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
        srand((unsigned int)time(nullptr));
        set<int> s;

        // vector<int> v = { 1,2,3,4,5,6 };

        int N = 100;
        vector<int> v;
        for (int i = 0; i < N; i++)
            v.push_back(rand());

        for (auto e : v)
        {
            s.insert(e);
        }

        set<int>::iterator it = s.begin();
        while (it != s.end())
        {
            cout << *it << " ";
            ++it;
        }
            cout << endl;
    }
}