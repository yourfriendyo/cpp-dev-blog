#pragma once
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

enum COLOR {
    RED,
    BLACK
};

template <class T>
struct RBTNode
{
    RBTNode<T>* _left;
    RBTNode<T>* _right;
    RBTNode<T>* _parent;

    T _data;
    COLOR _col;

    RBTNode(const T& data)
        : _left(nullptr), _right(nullptr), _parent(nullptr),
        _data(data), _col(RED)
    {}
};


template <class T, class Ref, class Ptr>
struct RBTIterator
{
    typedef RBTNode<T> Node;
    typedef RBTIterator<T, Ref, Ptr> Self;
    Node* _node;

    RBTIterator(Node* node) : _node(node)
    {}

    Ref operator*() {
        return _node->_data;
    }

    Ptr operator->() {
        return &_node->_data;
    }

    Self& operator++()
    {
        /* 右子树不为空，访问右子树的最左节点 */
        if (_node->_right)
        {
            Node* min = _node->_right;

            while (min->_left) {
                min = min->_left;
            }
            _node = min;
        }
        /* 右子树为空，找到cur非其右孩子的父亲 */
        else
        {
            Node* curr = _node;
            Node* parent = curr->_parent;

            while (parent && curr == parent->_right)
            {
                curr = curr->_parent;
                parent = parent->_parent;
            }

            _node = parent;
        }

        return *this;
    }

    Self& operator--()
    {
        /* 左子树不为空，访问左子树的最右节点 */
        if (_node->_left)
        {
            Node* max = _node->_left;

            while (max->_right) {
                max = max->_right;
            }
            _node = max;
        }
        /* 左子树为空，找到cur非其左孩子的父节点 */
        else
        {
            Node* curr = _node;
            Node* parent = _node->_parent;

            while (parent && parent->_left == curr)
            {
                curr = curr->_parent;
                parent = parent->_parent;
            }

            _node = parent;
        }

        return *this;
    }

    bool operator==(const Self& it) {
        return _node == it._node;
    }

    bool operator!=(const Self& it) {
        return !operator==(it);
    }
};


// set RBTree <K, K, SetKeyOfT>
// map RBTree <K, T, MapKeyOfT>
template <class K, class T, class KeyOfT>
class RBTree
{
    typedef RBTNode<T> Node;
    KeyOfT kot;
public:
    typedef RBTIterator<T, T&, T*> iterator;
    typedef RBTIterator<T, const T&, const T*> const_iterator;
    typedef RBTIterator<T, T&, T*> reverse_iterator;
    typedef RBTIterator<T, const T&, const T*> const_reverse_iterator;

    iterator begin()
    {
        Node* left = _root;
        while (left && left->_left) {
            left = left->_left;
        }

        return iterator(left);
    }
    iterator end() {
        return iterator(nullptr);
    }

    reverse_iterator rbegin()
    {
        Node* right = _root;
        while (right && right->_right) {
            right = right->_right;
        }

        return iterator(right);
    }
    reverse_iterator rend() {
        return iterator(nullptr);
    }


    const_iterator cbegin() {}
    const_iterator cend() {}
    const_reverse_iterator crbegin() {}
    const_reverse_iterator crend() {}


    RBTree() : _root(nullptr)
    {}

    RBTree(const RBTree<K, T, KeyOfT>& t)
    {
        _root = Copy(t._root);
    }

    Node* Copy(Node* root, Node* parent = nullptr)
    {
        if (root == nullptr)
            return nullptr;

        Node* new_node = new Node(root->_data);
        new_node->_col = root->_col;
        new_node->_parent = parent; // 链接父节点

        new_node->_left = Copy(root->_left, new_node);
        new_node->_right = Copy(root->_right, new_node);

        return new_node;
    }

    ~RBTree() {
        Destroy(_root);
    }

    void Destroy(Node* root)
    {
        if (root == nullptr)
            return;

        Destroy(root->_left);
        Destroy(root->_right);

        delete root;
    }

    pair<iterator, bool> Insert(const T& data)
    {
        if (_root == nullptr)
        {
            _root = new Node(data);
            _root->_col = BLACK;
            return make_pair(iterator(_root), true);
        }

        Node* parent = nullptr;
        Node* curr = _root;

        while (curr)
        {
            if (kot(curr->_data) < kot(data))
            {
                parent = curr;
                curr = curr->_right;
            }
            else if (kot(curr->_data) > kot(data))
            {
                parent = curr;
                curr = curr->_left;
            }
            else {
                return make_pair(iterator(curr), false);
            }
        }

        curr = new Node(data);
        curr->_col = RED;

        Node* save_node = curr; // 保存curr的位置，以便返回

        if (kot(parent->_data) < kot(data))
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

                    break;
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
                    break;
                }
            }

        }

        _root->_col = BLACK; // 维护根节点颜色

        return make_pair(iterator(save_node), true);

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
        cout << kot(root->_data) << " ";
        if (root->_right) _Inorder(root->_right);
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
