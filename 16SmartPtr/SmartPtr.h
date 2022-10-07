#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
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
        unique_ptr<T>& operator=(const unique_ptr& sp) = delete;

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

    // template<class T>
    // class shared_ptr
    // {
    // public:
    //     shared_ptr(T* ptr)
    //         : _ptr(new int)
    //     {
    //         _useCount = 1;
    //     }
    //
    //     shared_ptr(const shared_ptr<T>& sp)
    //         : _ptr(sp._ptr)
    //     {
    //         _useCount++;
    //     }
    //
    //     T* operator->()
    //     {
    //         return _ptr;
    //     }
    //     T& operator*()
    //     {
    //         return *_ptr;
    //     }
    //
    //     ~shared_ptr()
    //     {
    //         if (--_useCount == 0) // 最后一个管理对象
    //             delete _ptr;
    //     }
    //
    // private:
    //     T* _ptr;
    //     static int _useCount; // 引用计数
    // };
    //
    // template <class T>
    // int shared_ptr<T>::_useCount = 0;

    // template<class T>
    // class shared_ptr
    // {
    // public:
    //     shared_ptr(T* ptr)
    //         : _ptr(new T())
    //         , _pUseCount(new atomic<int>(1)) // 为资源配一个引用计数
    //     {}
    //
    //     shared_ptr(const shared_ptr<T>& sp)
    //         : _ptr(sp._ptr)
    //         , _pUseCount(sp._pUseCount)
    //     {
    //         AddRef();
    //     }
    //
    //     void AddRef()
    //     {
    //         (*_pUseCount)++;
    //     }
    //
    //     shared_ptr<T>& operator=(const shared_ptr<T>& sp)
    //     {
    //         if (_ptr != sp._ptr)
    //         {
    //             shared_ptr<T> tmp(sp);
    //
    //             swap(_ptr, tmp._ptr);
    //             swap(_pUseCount, tmp._pUseCount);
    //         }
    //         return *this;
    //     }
    //
    //     T* operator->()
    //     {
    //         return _ptr;
    //     }
    //     T& operator*()
    //     {
    //         return *_ptr;
    //     }
    //     int use_count()
    //     {
    //         return *_pUseCount;
    //     }
    //     T* get()
    //     {
    //         return _ptr;
    //     }
    //
    //     void Release()
    //     {
    //         if (--(*_pUseCount) == 0) // 最后一个管理对象
    //         {
    //             cout << "delete: " << _ptr << endl;
    //             delete _ptr;
    //             delete _pUseCount;
    //         }
    //     }
    //
    //     ~shared_ptr()
    //     {
    //         Release();
    //     }
    //
    // private:
    //     T* _ptr;
    //     atomic<int>* _pUseCount; // 引用计数
    // };

    template<class T>
    class shared_ptr
    {
    public:
        shared_ptr(T* ptr)
            : _ptr(new T())
            , _pUseCount(new int(1)) // 为资源配一个引用计数
            , _pmtx(new mutex)
        {}

        shared_ptr(const shared_ptr<T>& sp)
            : _ptr(sp._ptr)
            , _pUseCount(sp._pUseCount)
            , _pmtx(sp._pmtx)
        {
            AddRef();
        }

        void AddRef()
        {
            _pmtx->lock();

            (*_pUseCount)++;

            _pmtx->unlock();
        }

        shared_ptr<T>& operator=(const shared_ptr<T>& sp)
        {
            if (_ptr != sp._ptr)
            {
                shared_ptr<T> tmp(sp);

                swap(_ptr, tmp._ptr);
                swap(_pUseCount, tmp._pUseCount);
                swap(_pmtx, tmp._pmtx);
            }
            return *this;
        }

        T* operator->()
        {
            return _ptr;
        }
        T& operator*()
        {
            return *_ptr;
        }
        int use_count()
        {
            return *_pUseCount;
        }
        T* get()
        {
            return _ptr;
        }

        void Release()
        {
            _pmtx->lock();
            bool flg = false;

            if (--(*_pUseCount) == 0) // 最后一个管理对象
            {
                cout << "delete: " << _ptr << endl;
                delete _ptr;
                delete _pUseCount;
                flg = true;
            }
            _pmtx->unlock();

            if (flg) delete _pmtx;
        }

        ~shared_ptr()
        {
            Release();
        }

    private:
        T* _ptr;
        int* _pUseCount; // 引用计数
        mutex* _pmtx;
    };

    struct Date
    {
        int _year = 0;
        int _month = 0;
        int _day = 0;
    };

    void SharedPtrFunc(shared_ptr<Date>& sp, size_t n, mutex& mtx)
    {
        for (size_t i = 0; i < n; ++i)
        {
            shared_ptr<Date> copy(sp); // 测试引用计数线程安全

            // 测试资源的线程安全
            {
                unique_lock<mutex> lck(mtx);
                ++copy->_year;
                ++copy->_month;
                ++copy->_day;
            }
        }
    }

    struct ListNode
    {
        int _val = 0;
        shared_ptr<ListNode> _prev = nullptr;
        shared_ptr<ListNode> _next = nullptr;

        ListNode() = default;
    };

    void test_shared_ptr()
    {
        // shared_ptr<int> sp1(new int);
        // shared_ptr<int> sp2(sp1);
        // shared_ptr<int> sp3(sp2);
        //
        // shared_ptr<int> sp4(new int);
        // shared_ptr<int> sp5(sp4);
        //
        // sp1 = sp4;
        // sp2 = sp4;
        // sp3 = sp4;
        //
        // shared_ptr<Date> p(new Date);
        //
        // const size_t n = 100000;
        // mutex mtx;
        // thread t1(SharedPtrFunc, std::ref(p), n, std::ref(mtx));
        // thread t2(SharedPtrFunc, std::ref(p), n, std::ref(mtx));
        //
        // t1.join();
        // t2.join();
        //
        // cout << p->_year << endl;
        // cout << p->_month << endl;
        // cout << p->_day << endl;
        // cout << p.use_count() << endl;

        shared_ptr<ListNode> n1 = new ListNode;
        shared_ptr<ListNode> n2 = new ListNode;

        n1->_next = n2;
        n2->_prev = n1;
    }

}
