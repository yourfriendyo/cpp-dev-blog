#pragma once
#include <iostream>
#include <list>
#include <algorithm>
#include <cassert>
#include "revser_iterator.h"

using namespace std;

namespace test
{
    template <class T>
    struct __list_node
    {
        __list_node(const T& data = T())
            : _prev(nullptr)
            , _next(nullptr)
            , _data(data)
        {}
        //
        __list_node* _prev;
        __list_node* _next;
        T _data;
    };

    template <class T, class Ref, class Ptr>
    struct __list_iterator
    {
        typedef __list_node<T> Node;
        typedef __list_iterator<T, Ref, Ptr> self;
        __list_iterator(Node* node)
            : _node(node)
        {}

        //*it
        Ref operator*()
        {
            return _node->_data;
        }
        //->
        Ptr operator->()
        {
            return &_node->_data;
        }
        //it!=it
        bool operator!=(const self& it) const
        {
            return _node != it._node;
        }
        //++it
        self& operator++()
        {
            _node = _node->_next;
            return *this;
        }
        //it++
        self operator++(int)
        {
            self tmp(_node);
            _node = _node->_next;
            return tmp;
        }
        //--it
        self& operator--()
        {
            _node = _node->_prev;
            return *this;
        }
        //it--
        self operator--(int)
        {
            self tmp(_node);
            _node = _node->_prev;
            return tmp;
        }

        Node* _node;
    };

    template <class T>
    class list
    {
    public:
        typedef __list_node<T> Node;
        typedef __list_iterator<T, T&, T*> iterator;
        typedef __list_iterator<T, const T&, const T*> const_iterator;
        typedef test::reverse_iterator<iterator, T&, T*> reverse_iterator;
        typedef test::reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

        /* constructor */
        list(T x = T()) : _head(new Node(x))
        {
            _head->_prev = _head;
            _head->_next = _head;
        }
        list(int n, const int& val = int()) : _head(new Node(val))
        {
            _head->_prev = _head;
            _head->_next = _head;
            while (n)
            {
                push_back(val);
                n--;
            }
        }
        list(size_t n, const T& val = T()) : _head(new Node(val))
        {
            _head->_prev = _head;
            _head->_next = _head;
            while (n)
            {
                push_back(val);
                n--;
            }
        }
        template <class InputIterator>
        list(InputIterator first, InputIterator last) : _head(new Node)
        {
            _head->_prev = _head;
            _head->_next = _head;
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        list(const list<T>& lt) : _head(new Node)
        {
            _head->_prev = _head;
            _head->_next = _head;

            list<T> tmp(lt.begin(), lt.end());
            std::swap(_head, tmp._head);
        }

        list(initializer_list<T> il) : _head(new Node)
        {
            _head->_prev = _head;
            _head->_next = _head;

            list<T> tmp(il.begin(), il.end());
            std::swap(_head, tmp._head);
        }

        list& operator=(const list<T> lt)
        {
            //swap(_head, lt._head);
            return *this;
        }

        ~list()
        {
            clear();
            delete _head;
            _head = nullptr;
        }

        /* iterator */
        iterator begin() {
            return iterator(_head->_next);
        }
        iterator end() {
            return iterator(_head);
        }

        const_iterator begin() const {
            return const_iterator(_head->_next);
        }
        const_iterator end() const {
            return const_iterator(_head);
        }

        reverse_iterator rbegin() {
            return reverse_iterator(end());
        }
        reverse_iterator rend() {
            return reverse_iterator(begin());
        }

        const_reverse_iterator rbegin() const {
            return const_reverse_iterator(end());
        }
        const_reverse_iterator rend() const {
            return const_reverse_iterator(begin());
        }

        /* modify */
        iterator insert(iterator pos, const T& x)
        {
            Node* newNode = new Node(x);
            Node* prev = pos._node->_prev;
            Node* cur = pos._node;

            // prev - newNode - cur
            prev->_next = newNode;
            newNode->_prev = prev;

            cur->_prev = newNode;
            newNode->_next = cur;

            return iterator(newNode);
        }

        iterator erase(iterator pos)
        {
            assert(pos != end());
            Node* prev = pos._node->_prev;
            Node* next = pos._node->_next;

            delete pos._node;

            // prev - pos - after
            prev->_next = next;
            next->_prev = prev;

            return iterator(next);
        }

        void push_back(const T& data) {
            insert(end(), data);
        }
        void pop_back() {
            erase(--end());
        }

        void push_front(const T& data) {
            insert(begin(), data);
        }
        void pop_front() {
            erase(begin());
        }

        /* capacity */
        void clear()
        {
            iterator it = begin();

            while (it != end()) {
                it = erase(it);
            }
        }

        size_t size() const
        {
            assert(!empty());
            size_t n = 0;

            for (auto e : *this) {
                n++;
            }
            return n;
        }

        bool empty() const {
            return _head->_next == _head;
        }

        T& front() {
            return *begin();
        }
        const T& front() const {
            return *begin();;
        }

        T* back() {
            return *end();
        }
        const T* back() const {
            return *end();
        }

        void swap(list<T>& lt) {
            swap(_head, lt._head);
        }

    private:
        Node* _head;
    };

    template <class T>
    void print_list(const list<T>& lt)
    {
        list<int>::const_iterator cit = lt.begin();
        while (cit != lt.end())
        {
            cout << *cit << " ";
            ++cit;
        }
        cout << endl;
    }
    template <class inputiterator, class T>
    inputiterator find(inputiterator first, inputiterator last, const T& data)
    {
        list<int>::iterator it = last;
        while (it != last)
        {
            if (data == it._node->_data) {
                return it;
            }
            ++it;
        }
        return last;
    }

    void TestList1()
    {
        list<int> lt = { 1,2,3,4,5 };

        for (auto e : lt)
        {
            cout << e << " ";
        }
        cout << endl;
    }

}
