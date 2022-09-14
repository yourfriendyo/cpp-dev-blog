#pragma once
#include <iostream>
using namespace std;

enum COLOR {
    RED,
    BLACK
};

template <class K, class V>
struct RBTNode
{
    RBTNode* _left;
    RBTNode* _right;
    RBTNode* _parent;
    pair<K, V> _kv;

    enum COLOR _col;

    RBTNode(const pair<K, V> kv, enum COLOR col)
        : _left(nullptr), _right(nullptr), _parent(nullptr),
        _kv(kv), _col(col)
    {}
};

template <class K, class V>
class RBTree
{
    typedef RBTNode<K, V> Node;
public:
    RBTree() {}

    bool Insert(const pair<K, V> kv)
    {
        if (_root == nullptr)
        {
            _root = new Node(kv, BLACK);
            return true;
        }

        Node* parent = nullptr;
        Node* curr = nullptr;

        while (curr)
        {
            if (curr->_kv.first < kv.first)
            {
                parent = curr;
                curr = curr->_right;
            }
            else if (curr->_kv.first > kv.first)
            {
                parent = curr;
                curr = curr->_left;
            }
            else {
                return false;
            }
        }

        curr = new Node(kv, RED);

        if (parent->_kv.first < kv.first)
        {
            parent->_right = curr;
            curr->_parent = parent;
        }
        else if (parent->_kv.first > kv.first)
        {
            parent->_left = curr;
            curr->_parent = parent;
        }

        //

    }


private:
    Node* _root;

};


void TestRBTree()
{

}