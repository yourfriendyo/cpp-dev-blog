#pragma once
#include <iostream>

namespace K
{
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
            if (parent->_key < key)
            {
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
                else
                {
                    return true;
                }
            }
            return false;
        }

        bool Erase(const K& key)
        {
            Node* parent = nullptr;
            Node* curr = _root;

            while (curr)
            {
                if (curr->_key < key)
                {
                    parent = curr;
                    curr = curr->_right;
                }
                else if (curr->_key > key)  /**  这里else没写，bug找了几个小时  **/
                {
                    parent = curr;
                    curr = curr->_left;
                }
                else {
                    // 简单删除
                    if (curr->_left == nullptr) /* 左子树为空 */
                    {
                        // 删除头节点特殊情况
                        if (curr == _root) {
                            _root = _root->_right;
                        }
                        else {
                            if (parent->_left == curr) {
                                parent->_left = curr->_right;
                            }
                            else {
                                parent->_right = curr->_right;
                            }
                        }
                        delete curr;
                    }
                    else if (curr->_right == nullptr) /* 左子树存在，右子树为空 */
                    {
                        // 删除头节点特殊情况
                        if (curr == _root) {
                            _root = _root->_left;
                        }
                        else {
                            if (parent->_left == curr)
                                parent->_left = curr->_left;
                            else
                                parent->_right = curr->_left;
                        }
                        delete curr;
                    }
                        // 替换法删除
                    else /* 左右子树都存在 */
                    {
                        Node* maxParent = curr;
                        Node* max = curr->_left;
                        // 拿到整棵树的左子树的最右节点
                        while (max->_right)
                        {
                            maxParent = max;
                            max = max->_right;
                        }

                        curr->_key = max->_key; // 覆盖到目标位置

                        // 维护链接关系
                        if (maxParent->_right == max)
                            maxParent->_right = max->_left;
                        else // 特殊情况左子树的最右节点正好就是左节点
                            maxParent->_left = max->_left;

                        delete max;
                    }
                    return true;
                }
            }
            return false;
        }


        bool InsertR(const K& key)
        {
            return _InsertR(_root, key);
        }

        void InOrder()
        {
            _InOrder(_root);
            std::cout << std::endl;
        }

        Node* FindR(const K& key)
        {
            return _FindR(_root, key);
        }

        bool EraseR(const K& key)
        {
            return _EraseR(_root, key);
        }

    private:

        bool _EraseR(Node*& root, const K& key)
        {
            if (root == nullptr)
                return false;

            if (root->_key < key)
            {
                return _EraseR(root->_right, key);
            }
            else if (root->_key > key)
            {
                return _EraseR(root->_left, key);
            }
            else
            {
                Node* del = root;
                if (root->_left == nullptr)
                {
                    root = root->_right;
                }
                else if (root->_right == nullptr)
                {
                    root = root->_left;
                }
                else
                {
                    Node* max = root->_left;
                    while (max->_right)
                    {
                        max = max->_right;
                    }

                    root->_key = max->_key;
                    return _EraseR(root->_left, max->_key); // 子树中再递归删除
                    // return _EraseR(max, max->_key); // max始终是替换节点的拷贝，没能将其置空，造成野指针访问
                }
                delete del;
                return true;
            }
        }

        bool _InsertR(Node*& root, const K& key)
        {
            if (root == nullptr) {
                root = new Node(key);
                return true;
            }

            if (root->_key < key)
                return _InsertR(root->_right, key);
            else if (root->_key > key)
                return _InsertR(root->_left, key);
            else
                return false;
        }

        Node* _FindR(Node* root, const K& key)
        {
            if (root == nullptr)
                return root;

            if (root->_key < key)
                _FindR(root->_right);
            else if (root->_key > key)
                _FindR(root->_left);
            else
                return root;
        }

        void _InOrder(Node* root)
        {
            if (root == nullptr) {
                return;
            }

            _InOrder(root->_left);
            std::cout << root->_key << " ";
            _InOrder(root->_right);
        }

    private:
        Node* _root;

    };

    void TestBSTree()
    {
        BSTree<int> t;
        int a[] = { 5,3,4,1,7,8,2,6,0,9 };

        for (auto e : a)
        {
            t.InsertR(e);
        }
        t.InOrder();

        // t.Erase(7);
        // t.InOrder();

        // t.Erase(5);
        // t.InOrder();

        // t.Erase(0);
        // t.InOrder();

        for (auto e : a) {
            t.EraseR(e);
            t.InOrder();
        }
    }
}

namespace KV
{
    template <class K, class V>
    struct BSTNode
    {
        BSTNode<K, V>* _left;
        BSTNode<K, V>* _right;
        K _key;
        V _value;
        BSTNode(const K& key, const V& value)
                : _left(nullptr), _right(nullptr), _key(key), _value(value)
        {}
    };

    template <class K, class V>
    class BSTree
    {
        typedef BSTNode<K, V> Node;
    public:
        BSTree() : _root(nullptr)
        {}

        bool Insert(const K& key, const V& value)
        {
            if (_root == nullptr)
            {
                _root = new Node(key, value);
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
                parent->_right = new Node(key, value);
            }
            else {
                parent->_left = new Node(key, value);
            }

            return true;
        }

        Node* Find(const K& key)
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
                else
                {
                    return curr;
                }
            }
            return nullptr;
        }

        bool Erase(const K& key)
        {
            Node* parent = nullptr;
            Node* curr = _root;

            while (curr)
            {
                if (curr->_key < key)
                {
                    parent = curr;
                    curr = curr->_right;
                }
                else if (curr->_key > key)  /**  这里else没写，bug找了几个小时  **/
                {
                    parent = curr;
                    curr = curr->_left;
                }
                else {
                    // 简单删除
                    if (curr->_left == nullptr) /* 左子树为空 */
                    {
                        // 删除头节点特殊情况
                        if (curr == _root) {
                            _root = _root->_right;
                        }
                        else {
                            if (parent->_left == curr) {
                                parent->_left = curr->_right;
                            }
                            else {
                                parent->_right = curr->_right;
                            }
                        }
                        delete curr;
                    }
                    else if (curr->_right == nullptr) /* 左子树存在，右子树为空 */
                    {
                        // 删除头节点特殊情况
                        if (curr == _root) {
                            _root = _root->_left;
                        }
                        else {
                            if (parent->_left == curr)
                                parent->_left = curr->_left;
                            else
                                parent->_right = curr->_left;
                        }
                        delete curr;
                    }
                        // 替换法删除
                    else /* 左右子树都存在 */
                    {
                        Node* maxParent = curr;
                        Node* max = curr->_left;
                        // 拿到整棵树的左子树的最右节点
                        while (max->_right)
                        {
                            maxParent = max;
                            max = max->_right;
                        }
                        // 覆盖到目标位置
                        curr->_key = max->_key;
                        curr->_value = max->_value;

                        // 维护链接关系
                        if (maxParent->_right == max)
                            maxParent->_right = max->_left;
                        else // 特殊情况左子树的最右节点正好就是左节点
                            maxParent->_left = max->_left;

                        delete max;
                    }
                    return true;
                }
            }
            return false;
        }

        void InOrder()
        {
            _InOrder(_root);
        }

    private:
        void _InOrder(Node* root)
        {
            if (root == nullptr) {
                return;
            }

            _InOrder(root->_left);
            std::cout << root->_key << ":" << root->_value << " ";
            _InOrder(root->_right);
        }

    private:
        Node* _root;

    };
    void TestBSTree()
    {
        // 字典
        BSTree<std::string, std::string> dist;
        dist.Insert("sort", "排序");
        dist.Insert("left", "左");
        dist.Insert("right", "右");
        dist.Insert("map", "地图，映射");
        //...

        std::string str;
        while (std::cin >> str)
        {
            BSTNode<std::string, std::string>* ret = dist.Find(str);
            if (ret) {
                std::cout << "对应解释为：" << ret->_value << std::endl;
            }
            else {
                std::cout << str << " 无对应解释" << std::endl;
            }
        }
    }

    void TestBSTree2()
    {
        std::string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "西瓜" , "苹果", "西瓜" };
        BSTree<std::string, int> countTree;
        for (auto& str : arr) {
            BSTNode<std::string, int>* ret = countTree.Find(str);
            if (ret) {
                std::cout << ret->_key << ":" << ret->_value << std::endl;
                ret->_value++;
            }
            else {
                countTree.Insert(str, 1);
            }
        }
        countTree.InOrder();

    }
}