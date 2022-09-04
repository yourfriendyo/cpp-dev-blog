#pragma once
#include <iostream>
#include <cassert>

using namespace std;

template<class K, class V>
struct AVLTNode 
{
    AVLTNode<K, V>*  _left;
    AVLTNode<K, V>* _right;
    AVLTNode<K, V>* _parent;

    pair<K, V> _kv;

    int _bf; // balance factor

    AVLTNode(const pair<K, V> &kv)
            : _left(nullptr), _right(nullptr), _parent(nullptr), _bf(0), _kv(kv)
    {}
};

template<class K, class V>
class AVLTree 
{
    typedef AVLTNode<K, V> Node;

public:
    AVLTree() : _root(nullptr) 
    {}

    bool Insert(const pair<K, V> &kv) 
    { if (_root == nullptr) 
        {
            _root = new Node(kv);
            return _root;
        }

        Node *parent = nullptr;
        Node *cur = _root;
        while (cur) 
        {
            if (cur->_kv.first < kv.first) 
            {
                parent = cur;
                cur = cur->_right;
            } 
            else if (cur->_kv.first > kv.first) 
            {
                parent = cur;
                cur = cur->_left;
            } 
            else {
                return false;
            }
        }
        cur = new Node(kv);
        if (parent->_kv.first < kv.first) 
        {
            parent->_right = cur;
            cur->_parent = parent;
        }
        else 
        {
            parent->_left = cur;
            cur->_parent = parent;
        }

        // 控制平衡
        // 1. 更新平衡因子
        // 2. 旋转平衡处理异常平衡因子

        while (parent) 
        {
            if (cur == parent->_left) {
                parent->_bf--;
            }
            else if (cur == parent->_right) {
                parent->_bf++;
            }

            if (parent->_bf == 0) {
                break;
            }
            else if (parent->_bf == 1 || parent->_bf == -1) // 需要继续更新
            {
                cur = parent;
                parent = parent->_parent;
            }
            else if (parent->_bf == 2 || parent->_bf == -2) // 进行旋转
            {

            } 
            else {
                assert(false);
            }
        }

        return true;
    }

private:
    Node *_root;

};


void TestAVLTree() 
{
    AVLTree<int, int> t;

    int a[] = {1, 2, 3};

    for (auto e: a) 
    {
        t.Insert(make_pair(e, e));
    }
}
