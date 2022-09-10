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

        if (parent->_kv.first < kv.first) // �������ұ�
        {
            parent->_right = curr;
            curr->_parent = parent;
        }
        else // ���������
        {
            parent->_left = curr;
            curr->_parent = parent;
        }

        // ����ƽ��
        // 1. ����ƽ������
        // 2. ��ת�����쳣ƽ������

        while (parent) // ���µ���
        {
            // ����
            if (curr == parent->_left) {
                parent->_bf--;
            }
            else if (curr == parent->_right) {
                parent->_bf++;
            }

            // ���
            if (parent->_bf == 0) { // �Ѿ�ƽ�⣬���½���
                break;
            }
            else if (parent->_bf == 1 || parent->_bf == -1) // ���ϸ���
            {
                curr = parent;
                parent = parent->_parent;
            }
            else if (parent->_bf == 2 || parent->_bf == -2) // ƽ�ⱻ���ƣ���ʼ��ת
            {
                if (parent->_bf == -2 || cur->_bf == -1) {
                    RotateR(parent);
                }
                break;
            }
            else { // ����������
                assert(false);
            }
        }

        return true;
    }

    // �ҵ���
    void RotateR(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;

        // 右子树作父节点的左子树
        parent->_left = subLR;
        if (subLR)
            subLR->_parent = parent;

        // 父节点作当前节点的右子树
        subL->_right = parent;
        parent->_parent = subL;

        // 更新根节点或链接爷节点
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
        subL->_parent = parentP; // 维护三叉链

        // 更新平衡因子
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