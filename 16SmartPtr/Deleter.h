#pragma once
#include <iostream>
using namespace std;

namespace deleter
{
    template <class T>
    struct default_delete
    {
        void operator()(const T* ptr)
        {
            cout << "default_delete: " << ptr << endl;
            delete ptr;
        }
    };

    template <class T>
    struct delete_array
    {
        void operator()(const T* ptr)
        {
            cout << "delete_array: " << ptr << endl;
            delete[] ptr;
        }
    };

    struct delete_file
    {
        void operator()(FILE* ptr)
        {
            cout << "delete_file: " << ptr << endl;
            fclose(ptr);
        }
    };


    struct A
    {
        ~A()
        {
            cout << "~A()" << endl;
        }

        int _a;
    };

    template <class T, class D = default_delete<T>>
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
            D()(_ptr);
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
        // A* p = new A[10];
        // delete[] p;

        unique_ptr<A> up1(new A);

        unique_ptr<A, delete_array<A>> up2(new A[2]);

        unique_ptr<FILE, delete_file> up3(new FILE);
    }
};