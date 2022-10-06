#include <iostream>
#include <memory>
using namespace std;

namespace test
{
    template <class T>
    class auto_ptr
    {
    public:
        auto_ptr(T* ptr) : _ptr(ptr)
        {}

        auto_ptr(auto_ptr& sp)
            : _ptr(sp._ptr)
        {
            sp._ptr = nullptr;
        }

        T& operator*()
        {
            return *_ptr;
        }
        T& operator->()
        {
            return _ptr;
        }

        auto_ptr& operator++()
        {
            ++_ptr;
        }
        auto_ptr& operator--()
        {
            --_ptr;
        }

        ~auto_ptr()
        {
            if (_ptr)
            {
                cout << "delete :" << _ptr << endl;
                delete _ptr;
            }
        }

    private:
        T* _ptr;
    };

    void test_auto_ptr()
    {
        test::auto_ptr<int> p1(new int);
        *p1 = 0;

        test::auto_ptr<int> p2(p1); // 管理权转移

        cout << *p2 << endl;
        cout << *p1 << endl; //程序崩溃

    }

    template <class T>
    class unique_ptr
    {
    public:
        unique_ptr(T* ptr) : _ptr(ptr)
        {}

        unique_ptr(const unique_ptr<T>& sp) = delete;

        T& operator*()
        {
            return *_ptr;
        }
        T& operator->()
        {
            return _ptr;
        }

        unique_ptr& operator++()
        {
            ++_ptr;
        }
        unique_ptr& operator--()
        {
            --_ptr;
        }

        ~unique_ptr()
        {
            cout << "delete :" << _ptr << endl;
            delete _ptr;
        }

    private:
        T* _ptr;
    };

    void test_unique_ptr()
    {
        std::unique_ptr<int> up1(new int);

        //std::unique_ptr<int> up2(up1); // 编译报错

    }


}
