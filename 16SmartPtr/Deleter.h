#pragma once
#include <iostream>
using namespace std;

namespace deleter
{
    class A
    {
    public:
        ~A()
        {
            cout << "~A()" << endl;
        }
    private:
        int _a;
    };

    template <class T> //, class D = default_delete>
    class unique_ptr
    {
    public:
        unique_ptr(T* ptr)
            : _ptr(ptr)
        {}

        unique_ptr(const unique_ptr<T>&) = delete;
        unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;

        ~unique_ptr()
        {
            delete _ptr;
        }

        T& operator*()
        {
            return *_ptr;
        }
        T* operator->()
        {
            return _ptr;
        }
        T* get() const
        {
            return _ptr;
        }

    private:
        T* _ptr;
    };

    void test_deleter()
    {
        A* p = new A[10];
        delete[] p;

    }
};