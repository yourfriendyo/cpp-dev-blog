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

        if (parent->_kv.first < kv.first) // 链接在右边
        {
            parent->_right = curr;
            curr->_parent = parent;
        }
        else // 链接在左边
        {
            parent->_left = curr;
            curr->_parent = parent;
        }

        // 控制平衡
        // 1. 更新平衡因子
        // 2. 旋转处理异常平衡因子

        while (parent) // 更新到根
        {
            // 更新
            if (curr == parent->_left) {
                parent->_bf--;
            }
            else if (curr == parent->_right) {
                parent->_bf++;
            }

            // 检测
            if (parent->_bf == 0) { // 已经平衡，更新结束
                break;
            }
            else if (parent->_bf == 1 || parent->_bf == -1) // 向上更新
            {
                curr = parent;
                parent = parent->_parent;
            }
            else if (parent->_bf == 2 || parent->_bf == -2) // 平衡被打破，开始旋转
            {
                if (parent->_bf == -2 && curr->_bf == -1) {
                    RotateR(parent);
                }
                else if (parent->_bf == 2 && curr->_bf == 1) {
                    RotateL(parent);
                }
                else if (parent->_bf == -2 && curr->_bf == 1) {
                    RotateLR(parent);
                }
                else if (parent->_bf == 2 && curr->_bf == -1) {
                    RotateRL(parent);
                }
                break;
            }
            else { // 树构建出错
                assert(false);
            }
        }

        return true;
    }

    // 右单旋
    void RotateR(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;

        // 右子树作父节点的左子树
        parent->_left = subLR;
        if (subLR)
            subLR->_parent = parent;

        Node* parentP = parent->_parent;

        // 父节点作当前节点的右子树
        subL->_right = parent;
        parent->_parent = subL;

        // 更新根节点或链接爷节点
        if (parent == _root)
        {
            _root = subL;
            _root->_parent = nullptr;
        }
        else
        {
            if (parentP->_left == parent)
                parentP->_left = subL;
            else
                parentP->_right = subL;

            subL->_parent = parentP; // 维护三叉链
        }

        // 更新平衡因子
        subL->_bf = parent->_bf = 0;
    }

    // 左单旋
    void RotateL(Node* parent)
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;

        // 先将左子树链接到父节点下
        parent->_right = subRL;
        if (subRL)
            subRL->_parent = parent;

        Node* parentP = parent->_parent; // 先保存父节点的父
        // 再将父节点链接到当前节点下
        subR->_left = parent;
        parent->_parent = subR;

        // 与所在树链接
        if (_root == parent)
        {
            _root = subR;
            _root->_parent = nullptr;
        }
        else
        {
            if (parentP->_left == parent)
                parentP->_left = subR;
            else
                parentP->_right = subR;

            subR->_parent = parentP; // 维护三叉链
        }

        // 更新平衡因子
        subR->_bf = parent->_bf = 0;
    }

    // 左右双旋
    void RotateLR(Node* parent)
    {
        // 提前保存
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        int bf = subLR->_bf;

        RotateL(parent->_left);
        RotateR(parent);

        // subRL的平衡因子以区分情况
        if (bf == 1)
        {
            parent->_bf = 1;
            subL->_bf = 0;
            subLR->_bf = 0;
        }
        else if (bf == -1)
        {
            parent->_bf = 0;
            subL->_bf = -1;
            subLR->_bf = 0;
        }
        else if (bf == 0)
        {
            parent->_bf = 0;
            subL->_bf = 0;
            subLR->_bf = 0;
        }
        else {
            assert(false);
        }

    }

    // 右左双旋
    void RotateRL(Node* parent)
    {
        // 提前保存
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        int bf = subRL->_bf;

        RotateR(parent->_right);
        RotateL(parent);

        // subRL的平衡因子以区分情况
        if (bf == 1)
        {
            parent->_bf = -1;
            subR->_bf = 0;
            subRL->_bf = 0;
        }
        else if (bf == -1)
        {
            parent->_bf = 0;
            subR->_bf = 1;
            subRL->_bf = 0;
        }
        else if (bf == 0)
        {
            parent->_bf = 0;
            subR->_bf = 0;
            subRL->_bf = 0;
        }
        else {
            assert(false);
        }
    }

    void Inorder()
    {
        _Inorder(_root);
        cout << endl;
    }
    void _Inorder(Node* root)
    {
        if (root == nullptr)
            return;

        if (root->_left) _Inorder(root->_left);
        cout << root->_kv.first << ":" << root->_kv.second << " ";
        if (root->_right) _Inorder(root->_right);
    }

    bool IsBalance()
    {
        return _IsBalance(_root);
    }
    bool _IsBalance(Node* root)
    {
        if (root == nullptr)
            return true;

        // 检查
        int leftHeight = Height(root->_left);
        int rightHeight = Height(root->_right);

        if (rightHeight - leftHeight != root->_bf)
        {
            cout << root->_kv.first << "现在是：" << root->_bf << endl;
            cout << root->_kv.first << "应该是：" << rightHeight - leftHeight << endl;
            return false;
        }

        // 判断高度差是否满足
        return abs(rightHeight - leftHeight) < 2 &&
            _IsBalance(root->_left) && _IsBalance(root->_right);
    }

    int Height(Node* root)
    {
        if (root == nullptr)
            return 0;

        int leftHeight = Height(root->_left);
        int rightHeight = Height(root->_right);

        return rightHeight > leftHeight ? rightHeight + 1 : leftHeight + 1;
    }

private:
    Node* _root;
};


void TestAVLTree()
{
    AVLTree<int, int>* avl = new AVLTree<int, int>();

    int a[] = { 0,1,2,3,4,5 };
    //int a[] = { 4,2,6,1,3,5,15,7,16,14 };

    for (auto e : a)
    {
        avl->Insert(make_pair(e, e));
        avl->Inorder();
        cout << avl->IsBalance() << endl;
        cout << "-------------------------------------" << endl;
    }

    cout << avl->IsBalance() << endl;
}