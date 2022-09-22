#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include "test.hpp"
#include "Hash.hpp"
#include "UnorderedMap.hpp"
#include "UnorderedSet.hpp"
#include "BitSet.hpp"

using namespace std;

int main()
{
    // test_unordered_set();
    //
    // test_op();

    // unordered_map<int, int> hash;
    // for (auto e : hash)
    //     cout << e.first << ":" << e.second << endl;
    // cout << endl << endl;;

    // NS_Close_Hash::TestHash1();
    // NS_Close_Hash::TestHash2();

    // NS_Open_Hash::TestHash1();

    // NS_Unordered_Set::test_unordered_set();
    // NS_Unordered_Map::test_unordered_map();

    // NS_Bit_Set::test_bitset1();
    NS_Bit_Set::test_bitset2();


    return 0;
}


void TestIndex()
{
    int key = 0;

    while (1)
    {
        set<int> s;

        int size = 0;

        cin >> key;

        int start = key % size;
        int index = start;

        for (int i = 0; i < 1000; i++)
        {
            s.insert(index);

            index = start + i * i;
            index %= size;
        }

        for (auto e : s)
        {
            cout << e << " ";
        }

    }

}