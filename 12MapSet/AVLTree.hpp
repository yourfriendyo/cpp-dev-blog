#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template <class K, class V>
struct AVLTNode
{
    AVLTNode<K, V>* _left;
    AVLTNode<K, V>* _right;
    AVLTNode<K, V>* _parent;

    pair<K, V> _kv;
    int _bf; // balance factor


    AVLTNode(const pair<K, V>& kv)
        :_left(nullptr), _right(nullptr), _parent(nullptr), _kv(kv), _bf(0)
    {}
};

template <class K, class V>
class AVLTree
{
    typedef AVLTNode<K, V> Node;

public:
    AVLTree() : _root(nullptr)
    {}

public:
    bool Insert(const pair<K, V>& kv)
    {
        if (_root == nullptr)
        {
            _root = new Node(kv);
            return true;
        }

        Node* parent = nullptr;
        Node* curr = _root;

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

        curr = new Node(kv);

        if (parent->_kv.first < curr->_kv.first) // 链接在左边
        {
            parent->_left = curr;
            curr->_parent = parent;
        }
        else // 链接在右边
        {
            parent->_right = curr;
            curr->_parent = parent;
        }

        // 控制平衡
        // 1. 更新平衡因子
        // 2. 旋转处理异常平衡因子

        while (parent) // 更新到根
        {
            // 更新
            if (curr == parent->_left)
            {
                parent->_bf--;
            }
            else if (curr == parent->_right)
            {
                parent->_bf++;
            }

            // 检测
            if (parent->_bf == 0) // 已经平衡，更新结束
            {
                break;
            }
            else if (parent->_bf == 1 || parent->_bf == -1) // 向上更新
            {
                curr = parent;
                parent = parent->_parent;
            }
            else if (parent->_bf == 2 || parent->_bf == -2) // 平衡被打破，开始旋转
            {
            }
            else // 树构建出错
            {
                assert(false);
            }
        }

        return true;
    }

    //    bool RotateR();
    //    bool RotateL();
    //    bool RotateRL();
    //    bool RotateLR();

private:
    Node* _root;
};


void TestAVLTree()
{
    AVLTree<int, int>* avl = new AVLTree<int, int>();

    int a[] = { 1, 2, 3 };

    for (auto e : a)
    {
        avl->Insert(make_pair(e, e));
    }

}