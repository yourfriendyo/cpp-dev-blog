#pragma once

template<class T>
struct list_node
{
    list_node* _next = nullptr;
    list_node* _prev = nullptr;
    T _data;

    list_node()
    {}
};

namespace test
{
    template <class T>
    class list
    {
        typedef list_node<T> Node;
    public:
        list()
        {
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;
        }

        void push_back(T&& x)
        {
            insert(_head, std::forward<T>(x));
        }

        void push_front(T&& x)
        {
            insert(_head->_next, std::forward<T>(x));
        }

        void insert(Node* pos, T&& x)
        {
            Node* prev = pos->_prev;

            // Node* newNode = new Node;
            // newNode->_data = std::forward<T>(x);

            Node* newNode = (Node*)malloc(sizeof(Node));
            new(&newNode->_data)T(std::forward<T>(x));

            prev->_next = newnode;
            newnode->_prev = prev;

            newnode->_next = pos;
            pos->_prev = newnode;
        }

        void insert(Node* pos, const T& x)
        {
            Node* prev = pos->_prev;
            Node* newnode = new Node;
            newnode->_data = x; // 关键位置

            // prev newnode pos
            prev->_next = newnode;
            newnode->_prev = prev;

            newnode->_next = pos;
            pos->_prev = newnode;
        }
    private:
        Node* _head;
    };
}