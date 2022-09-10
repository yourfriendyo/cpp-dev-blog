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

        if (parent->_kv.first < kv.first) // Á´½ÓÔÚÓÒ±ß
        {
            parent->_right = curr;
            curr->_parent = parent;
        }
        else // Á´½ÓÔÚ×ó±ß
        {
            parent->_left = curr;
            curr->_parent = parent;
        }

        // ¿ØÖÆÆ½ºâ
        // 1. ¸üÐÂÆ½ºâÒò×Ó
        // 2. Ðý×ª´¦ÀíÒì³£Æ½ºâÒò×Ó

        while (parent) // ¸üÐÂµ½¸ù
        {
            // ¸üÐÂ
            if (curr == parent->_left) {
                parent->_bf--;
            }
            else if (curr == parent->_right) {
                parent->_bf++;
            }

            // ¼ì²â
            if (parent->_bf == 0) { // ÒÑ¾­Æ½ºâ£¬¸üÐÂ½áÊø
                break;
            }
            else if (parent->_bf == 1 || parent->_bf == -1) // ÏòÉÏ¸üÐÂ
            {
                curr = parent;
                parent = parent->_parent;
            }
            else if (parent->_bf == 2 || parent->_bf == -2) // Æ½ºâ±»´òÆÆ£¬¿ªÊ¼Ðý×ª
            {
                if (parent->_bf == -2 || cur->_bf == -1) {
                    RotateR(parent);
                }
                break;
            }
            else { // Ê÷¹¹½¨³ö´í
                assert(false);
            }
        }

        return true;
    }

    // ÓÒµ¥Ðý
    void RotateR(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;

        // å³å­æ ‘ä½œçˆ¶èŠ‚ç‚¹çš„å·¦å­æ ‘
        parent->_left = subLR;
        if (subLR)
            subLR->_parent = parent;

        // çˆ¶èŠ‚ç‚¹ä½œå½“å‰èŠ‚ç‚¹çš„å³å­æ ‘
        subL->_right = parent;
        parent->_parent = subL;

        // æ›´æ–°æ ¹èŠ‚ç‚¹æˆ–é“¾æŽ¥çˆ·èŠ‚ç‚¹
        Node* parentP = parent->_parent;

        if (parent == _root)
            _root = subL;
        else
        {
            if (parentP->_left == parent)
                parentP->_left = subL;
            else
                parentP->_right = subL;
        }
        subL->_parent = parentP; // ç»´æŠ¤ä¸‰å‰é“¾

        // æ›´æ–°å¹³è¡¡å› å­
        subL->_bf = 0;
        parent._bf = 0;
    }


private:
    Node* _root;
};


void TestAVLTree()
{
    AVLTree<int, int>* avl = new AVLTree<int, int>();

    int a[] = { 5, 4, 3, 2, 1 };

    for (auto e : a)
    {
        avl->Insert(make_pair(e, e));
    }

}