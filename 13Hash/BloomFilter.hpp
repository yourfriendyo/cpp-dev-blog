#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

namespace NS_Bloom_Filter
{
    struct BKDRHash
    {
        size_t operator()(const string& s)
        {
            int val = 0;
            for (auto e : s)
                val = val * 131 + e;
            return val;
        }
    };

    struct APHash
    {
        size_t operator()(const string& s)
        {
            register size_t hash = 0;

            for (size_t i = 0; i < s.size(); ++i)
            {
                if ((i & 1) == 0)
                    hash ^= ((hash << 7) ^ s[i] ^ (hash >> 3));
                else
                    hash ^= (~(hash << 11) ^ s[i] ^ (hash >> 5));
            }
            return hash;
        }
    };

    struct DJBHash
    {
        size_t operator()(const string& s)
        {
            size_t hash = 5381;
            for (auto e : s)
                hash += (hash << 5) + e;
            return hash;
        }
    };

    template <size_t N,
        size_t MUL = 4,
        class K = string,
        class HashFunc1 = BKDRHash,
        class HashFunc2 = APHash,
        class HashFunc3 = DJBHash>
    class BloomFilter
    {
    public:
        void Set(const K& key)
        {
            size_t len = MUL * N;
            size_t index1 = HashFunc1()(key) % len;
            size_t index2 = HashFunc2()(key) % len;
            size_t index3 = HashFunc3()(key) % len;

            // cout << index1 << endl << index2 << endl << index3 << endl << endl;

            _bs.set(index1);
            _bs.set(index2);
            _bs.set(index3);
        }

        bool Test(const K& key)
        {
            size_t len = MUL * N;
            size_t index1 = HashFunc1()(key) % len;
            size_t index2 = HashFunc2()(key) % len;
            size_t index3 = HashFunc3()(key) % len;

            if (!_bs.test(index1)) return false;
            if (!_bs.test(index2)) return false;
            if (!_bs.test(index3)) return false;

            return true;
        }

    private:
        bitset<N* MUL> _bs;

    };

    void Test_Bloom_Filter1()
    {
        BloomFilter<1000> bf;

        bf.Set("set");
        bf.Set("insert");
        bf.Set("delete");
        bf.Set("ate");
        bf.Set("eat");
    }

    void Test_Bloom_Filter2()
    {
        // BloomFilter<100> bf;
        // bf.Set("张三");
        // bf.Set("李四");
        // bf.Set("牛魔王");
        // bf.Set("红孩儿");
        // bf.Set("eat");
        //
        // cout << bf.Test("张三") << endl;
        // cout << bf.Test("李四") << endl;
        // cout << bf.Test("牛魔王") << endl;
        // cout << bf.Test("红孩儿") << endl;
        // cout << bf.Test("孙悟空") << endl;
        // cout << bf.Test("二郎神") << endl;
        // cout << bf.Test("猪八戒") << endl;
        // cout << bf.Test("ate") << endl;


        BloomFilter<1000, 4> bf;

        size_t N = 1000;
        vector<string> v1;
        for (size_t i = 0; i < N; ++i)
        {
            string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
            url += to_string(1234 + i);
            v1.push_back(url);
        }
        for (auto& str : v1) {
            bf.Set(str);
        }

        vector<string> v2;
        for (size_t i = 0; i < N; ++i)
        {
            string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
            url += to_string(6789 + i);
            v2.push_back(url);
        }

        size_t num = 0;
        for (auto& str : v2) {
            if (bf.Test(str)) {
                ++num;
            }
        }
        cout << "相似字符串误判率:" << num * 1.0 / N << endl;


        vector<string> v3;
        for (size_t i = 0; i < N; ++i)
        {
            // string url = "zhihu.com";
            // string url = "www.baidu.com/s?wd=ln2&rsv_spt=1&rsv_iqid=0xc1c7784f000040b1&issp=1&f=8&rsv_bp=1&rsv_idx=2&ie=utf-8&tn=baiduhome_pg&rsv_dl=tb&rsv_enter=1&rsv_sug3=8&rsv_sug1=7&rsv_sug7=100&rsv_sug2=0&rsv_btype=i&prefixsug=ln2&rsp=5&inputT=4576&rsv_sug4=5211";
            // string url = "zhidao.baidu.com/question/1945717405689377028.html?fr=iks&word=ln2&ie=gbk&dyTabStr=MCw0LDMsMiw2LDEsNSw3LDgsOQ==";
            // string url = "www.cnblogs.com/-clq/archive/2012/01/31/2333247.html";

            url += std::to_string(4482 + i);
            v3.push_back(url);
        }

        size_t n3 = 0;
        for (auto& str : v3) {
            if (bf.Test(str)) {
                ++n3;
            }
        }
        cout << "不相似字符串误判率:" << n3 * 1.0 / N << endl;

    }
}
