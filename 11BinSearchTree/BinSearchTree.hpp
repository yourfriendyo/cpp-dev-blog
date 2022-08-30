#pragma once
#include <iostream>


template <class K>
struct BSTNode
{
    BSTNode<K>* _left;
    BSTNode<K>* _right;
    K _key;
    BSTNode(const K& key) : _left(nullptr), _right(nullptr), _key(key)
    {}
};

template <class K>
class BSTree
{
    typedef BSTNode<K> Node;
public:
    BSTree() : _root(nullptr)
    {}

    bool Insert(const K& key)
    {
        if (_root == nullptr)
        {
            _root = new Node(key);
            return true;
        }

        Node* parent = nullptr;
        Node* curr = _root;

        while (curr)
        {
            if (curr->_key < key)
            {
                parent = curr;
                curr = curr->_right;
            }
            else if (curr->_key > key)
            {
                parent = curr;
                curr = curr->_left;
            }
            else {
                return false;
            }
        }
        if (parent->_key < key) {
            parent->_right = new Node(key);
        }
        else {
            parent->_left = new Node(key);
        }

        return true;
    }

    bool Find(const K& key)
    {
        Node* curr = _root;
        while (curr)
        {
            if (curr->_key < key)
            {
                curr = curr->_right;
            }
            else if (curr->_key > key)
            {
                curr = curr->_left;
            }
            else if
            {
                return true;
            }
        }
        return false;
    }

    bool Erase(const K& key)
    {

    }

    void _InOrder(Node* root)
    {
        if (root == nullptr)
        {
            return;
        }

        _InOrder(root->_left);
        std::cout << root->_key << " ";
        _InOrder(root->_right);
    }
    void InOrder()
    {
        _InOrder(_root);
    }

private:
    Node* _root;

};

void TestBSTree()
{
    BSTree<int> t;
    int a[] = { 5,3,5,1,7,8,2,6,0,9 };

    for (auto e : a)
    {
        t.Insert(e);
    }

    t.InOrder();

}