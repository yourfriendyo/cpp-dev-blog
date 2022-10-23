#pragma once
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

namespace NS_Bit_Set
{
    template <size_t N>
    class bitset
    {
    public:
        bitset() {
            _bs.resize(N / 8 + 1);
        }

        void set(size_t x)
        {
            size_t i = x / 8; // 字节位
            size_t j = x % 8; // 比特位

            _bs[i] |= (1 << j);
        }

        void reset(size_t x)
        {
            size_t i = x / 8; // 字节位
            size_t j = x % 8; // 比特位

            _bs[i] &= ~(1 << j);
        }

        bool test(size_t x)
        {
            size_t i = x / 8; // 字节位
            size_t j = x % 8; // 比特位

            return _bs[i] & (1 << j);
        }

    private:
        vector<char> _bs;
    };

    void test_bitset1()
    {
        bitset<100> bs;

        bs.set(1);
        bs.set(2);
        bs.set(3);

        bs.set(8);
        bs.set(9);
        bs.set(10);

        cout << bs.test(1) << endl;
        cout << bs.test(2) << endl;
        cout << bs.test(3) << endl;
        cout << bs.test(8) << endl;
        cout << bs.test(9) << endl;
        cout << bs.test(10) << endl;

        bs.reset(1);
        bs.reset(2);
        bs.reset(3);

        bs.reset(8);
        bs.reset(9);
        bs.reset(10);

        cout << bs.test(1) << endl;
        cout << bs.test(2) << endl;
        cout << bs.test(3) << endl;
        cout << bs.test(8) << endl;
        cout << bs.test(9) << endl;
        cout << bs.test(10) << endl;
    }

    // 给定100亿个整数，设计算法找到只出现一次的整数？
    // 位图1表示只出现一次的状态，位图2表示2次及以上的状态
    template <size_t N>
    void handlequestion1(vector<int>& in, vector<int>* out)
    {
        bitset<N> bs1;
        bitset<N> bs2;

        for (auto e : in)
        {
            if (!bs1.test(e) && !bs2.test(e)) { // 00 -> 01
                bs1.set(e);
            }
            else if (bs1.test(e) && !bs2.test(e)) // 01 -> 10
            {
                bs1.reset(e);
                bs2.set(e);
            }
        }

        for (size_t i = 0; i < N; ++i)
        {
            if (bs1.test(i) && !bs2.test(i))
                out->push_back(i);
        }
    }

    // 给两个文件，分别有100亿个整数，我们只有1G内存，如何找到两个文件交集？
    template <size_t N>
    void handlequestion2(vector<int>& in1, vector<int>& in2, vector<int>* out)
    {
        if (0)
        {
            bitset<N> bs1;

            for (auto e : in1) {
                bs1.set(e);
            }

            for (auto e : in2)
            {
                if (bs1.test(e))
                {
                    bs1.reset(e);
                    out->push_back(e);
                }
            }
        }
        else
        {
            std::bitset<N> bs1;
            std::bitset<N> bs2;

            for (auto e : in1)
                bs1.set(e);

            for (auto e : in2)
                bs2.set(e);

            for (int i = 0; i < N; i++) {
                bs1[i] = bs1[i] & bs2[i];
            }

            for (int i = 0; i < N; i++)
            {
                if (bs1.test(i))
                    out->push_back(i);
            }
        }
    }

    // 位图应用变形：1个文件有100亿个int，1G内存，设计算法找到出现次数不超过2次的所有整数。
    // 位图1表示0次和1次的状态，位图2表示2次和2次以上的状态
    template <size_t N>
    void handlequestion3(vector<int>& in, vector<int>* out)
    {
        bitset<N> bs1;
        bitset<N> bs2;

        for (auto e : in)
        {
            if (!bs1.test(e) && !bs2.test(e)) { // 00 -> 01
                bs1.set(e);
            }
            else if (bs1.test(e) && !bs2.test(e)) // 01 -> 10
            {
                bs1.reset(e);
                bs2.set(e);
            }
            else if (!bs1.test(e) && bs2.test(e)) // 10 -> 11
            {
                bs1.set(e);
            }
        }

        for (int i = 0; i < N; i++)
        {
            if ((bs1.test(i) && !bs2.test(i)) ||
                !bs1.test(i) && bs2.test(i))
            {
                out->push_back(i);
            }
        }
    }

    void test_bitset2()
    {
        vector<int> input1 = { 90,0,4,50,33,50,44,2,5,99,90,44,50,3,2 };
        vector<int> input2 = { 1,2,4,4,45,5 };

        vector<int> output;

        // handlequestion1(input1, &output);
        // handlequestion2(input1, input2, &output);
        handlequestion3<100>(input1, &output);

        for (auto e : output)
            cout << e << endl;
    }
}
