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

    COLOR _col;

    RBTNode(const pair<K, V>& kv)
        : _left(nullptr), _right(nullptr), _parent(nullptr),
        _kv(kv), _col(RED)
    {}
};

template <class K, class V>
class RBTree
{
    typedef RBTNode<K, V> Node;
public:
    RBTree() : _root(nullptr)
    {}

    bool Insert(const pair<K, V>& kv)
    {
        if (_root == nullptr)
        {
            _root = new Node(kv);
            _root->_col = BLACK;
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
        curr->_col = RED;

        if (parent->_kv.first < kv.first)
        {
            parent->_right = curr;
            curr->_parent = parent;
        }
        else
        {
            parent->_left = curr;
            curr->_parent = parent;
        }

        // 控制平衡

        while (parent && parent->_col == RED) // 父节点存在且为红
        {
            Node* grandpa = parent->_parent; // 父为红则不可能为根，此时一定存在爷节点

            if (grandpa->_left == parent) // 父在左
            {
                Node* uncle = grandpa->_right;

                /* 情况一：u存在且为红 */
                if (uncle && uncle->_col == RED) // 叔节点存在且为红
                {
                    // 变色
                    parent->_col = uncle->_col = BLACK;
                    grandpa->_col = RED;

                    // 向上调整
                    curr = grandpa; // 越过父节点直接跳到爷节点
                    parent = grandpa->_parent;
                }

                /* 情况二：u不存在或存在但为黑 */
                else
                {
                    if (parent->_left == curr) // 本在左，父在左 -- 右单旋
                    {
                        // 旋转
                        RotateR(grandpa);
                        // 变色
                        parent->_col = BLACK;
                        grandpa->_col = RED;
                    }
                    else // 本在右，父在左 -- 左右双旋
                    {
                        // 旋转
                        RotateL(parent);
                        RotateR(grandpa);
                        // 变色
                        curr->_col = BLACK;
                        grandpa->_col = RED;
                    }
                }
            }
            else // 父在右
            {
                Node* uncle = grandpa->_left;

                /* 情况一：u存在且为红 */
                if (uncle && uncle->_col == RED) // 叔节点存在且为红
                {
                    // 变色
                    parent->_col = uncle->_col = BLACK;
                    grandpa->_col = RED;

                    // 向上调整
                    curr = grandpa; // 越过父节点直接跳到爷节点
                    parent = grandpa->_parent;
                }

                /* 情况二：u不存在或存在但为黑 */
                else
                {
                    if (parent->_right == curr) // 新在右，父在右 -- 左单旋
                    {
                        // 旋转
                        RotateL(grandpa);
                        // 变色
                        parent->_col = BLACK;
                        grandpa->_col = RED;
                    }
                    else // 新在左，父在右 -- 右左双旋
                    {
                        // 旋转
                        RotateR(parent);
                        RotateL(grandpa);
                        // 变色
                        curr->_col = BLACK;
                        grandpa->_col = RED;
                    }
                }
            }

            break;
        }

        _root->_col = BLACK; // 维护根节点颜色

        return true;

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
        if (_root && _root->_col == RED)
        {
            cout << "root point is not black" << endl;
            return false;
        }

        Node* curr = _root;
        int bench_mark = 0;

        while (curr)
        {
            if (curr->_col == BLACK) bench_mark++;
            curr = curr->_left;
        }

        int black_cnt = 0;
        return _IsBalance(_root, bench_mark, black_cnt);
    }
    bool _IsBalance(Node* root, int& bench_mark, int black_cnt)
    {
        if (root == nullptr)
        {
            if (black_cnt != bench_mark) return false;
            return true;
        }

        if (root->_col == RED && root->_parent->_col == RED)
        {
            cout << root->_kv.first << ":" << root->_col << " ";
            cout << root->_parent->_kv.first << ":" << root->_parent->_col << endl;
            cout << "连续出现红色节点" << endl;
            return false;
        }

        if (root->_col == BLACK)
            black_cnt++;

        return _IsBalance(root->_left, bench_mark, black_cnt) &&
            _IsBalance(root->_right, bench_mark, black_cnt);
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
    }

private:
    Node* _root;

};


void TestRBTree()
{

    RBTree<int, int> rbt;

    // int a[] = { 5,4,3,2,1,0 };
    int a[] = { 4,2,6,1,3,5,15,7,16,14 };

    for (auto e : a)
    {
        rbt.Insert(make_pair(e, e));
        rbt.Inorder();
        cout << rbt.IsBalance() << endl;
        cout << "-------------------------------------" << endl;
    }

}