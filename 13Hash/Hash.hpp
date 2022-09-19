#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace LinkedHash
{
    template <class K, class V>
    struct HashNode
    {
        pair<K, V> _kv;
        HashNode<K, V>* _next;
    };


    template <class K>
    struct Hash
    {
        size_t operator()(const K& key)
        {

        }

    };


    template <class K, class V, class HashFunc = Hash<K> >
    class HashTable
    {
        typedef HashNode<K, V> Node;

    public:
        bool Insert(const pair<K, V>& kv)
        {

        }

    private:
        vector<Node*> _table;
        size_t _n;

    };

}
