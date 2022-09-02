#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

void TestSet1() {
    set<int> s;

    s.insert(3);
    s.insert(1);
    s.insert(5);
    s.insert(8);
    s.insert(2);

    s.insert(5);
    s.insert(8);
    s.insert(2);

    set<int>::iterator it = s.begin();

    set<int>::iterator pos = s.find(30);

    if (pos != s.end()) {
        s.erase(pos);
    }

    size_t ret = s.erase(30);
    cout << "ret: " << ret << endl;

    while (it != s.end()) {
        cout << *it << endl;
        ++it;
    }


}

void TestMultiSet() {
    multiset<int> s;

    s.insert(3);
    s.insert(1);
    s.insert(5);
    s.insert(1);
    s.insert(8);
    s.insert(2);

    s.insert(5);
    s.insert(8);
    s.insert(2);

//    set<int>::iterator pos = s.find(1);
//    while (pos != s.end() && *pos == 1)
//    {
//        auto next = pos;
//        s.erase(pos);
//
//        pos = ++next;
//    }

//    while (pos != s.end())
//    {
//        s.erase(pos);
//        cout << "找到了" << endl;
//        pos = s.find(1);
//    }
//
//
//    int ret = 1;
//    while (ret)
//    {
//        ret = s.erase(1);
//        cout << "找到了" << endl;
//    }

//    set<int>::iterator it = s.begin();
//    size_t ret = s.erase(30);
//    cout << "ret: " << ret << endl;



//    while (it != s.end())
//    {
//        cout << *it << " ";
//        ++it;
//    }

//    multiset<int>::iterator pos = s.find(2);
//
//    if (pos != s.end())
//    {
//        *pos = 1;
//    }




}

void TestMap() {
    map<string, string> dict;
    pair<string, string> kv1("sort", "排序");

    dict.insert(kv1);
    dict.insert(pair<string, string>("string", "字符串"));
    dict.insert(make_pair("arrary", "数组"));

    map<string, string>::iterator it = dict.begin();

//    while (it != dict.end())
//    {
//        cout << *it << " ";
//        cout << it->first << ":" << it->second << endl;
//        ++it;
//    }
//    cout << endl;

    for (auto &kv: dict) {
        cout << kv.first << ":" << kv.second << " ";
    }
    cout << endl;

}

void TestMap2() {
    string arr[] = {"苹果", "香蕉", "菠萝", "苹果", "香蕉", "苹果", "苹果"};
    map<string, int> countMap;
//    for (auto& str: arr)
//    {
//        auto kv = countMap.insert(make_pair(str, 1));
//        if (kv.second == false)
//        {
//            kv.first->second++;
//        }
//    }

    for (auto &kv: arr) {
        countMap[kv]++;
    }

    for (auto &kv: countMap) {
        cout << kv.first << ":" << kv.second << endl;
    }
    cout << endl;

//    mapped_type& operator[] (const key_type& k)
//    {
//        return (
//            *(
//                (
//                    this->insert( make_pair(k,mapped_type()) ) // 返回值是键值对
//                ).first // 获得键值对中的key 迭代器
//             ) // 对迭代器解引用
//         ).second; // 解引用迭代器访问value
//    }

}

void TestMap3() {
    map<string, string> dict;
    dict.insert(make_pair("sort", "排序"));
    dict.insert(make_pair("left", "左边"));
    dict.insert(make_pair("left", "剩余"));

    dict["left"] = "剩余"; // 修改
    dict["test"];         //
    cout << dict["sort"] << endl;

}

void TestMultiMap() {
    multimap<string, string> dict;
    dict.insert(make_pair("sort", "排序"));
    dict.insert(make_pair("left", "左边"));
    dict.insert(make_pair("left", "剩余"));

//    dict["left"] = "剩余"; // 修改
//    dict["test"];         //
//    cout << dict["sort"] << endl;

    cout << dict.count("left") << endl;
}

struct CountVal {
    bool operator()(const pair<string, int> &l, const pair<string, int> &r) {
        return l.second < r.second;
    }
};

struct CountIterVal {
    bool operator()(const map<string, int>::iterator &l, const map<string, int>::iterator &r) {
        return l->second < r->second;
    }
};

void GetFavoriteFruit(vector<string> &fruits, size_t k) {
    map<string, int> countMap;

    for (auto &e: fruits) {
        countMap[e]++;
    }

//    multimap<int, string> map;

    // sort
//    vector<map<string, int>::iterator> sortV;
//    auto it = countMap.begin();
//    while (it != countMap.end())
//    {
//        sortV.push_back(it);
//        ++it;
//    }
//
//    sort(sortV.begin(), sortV.end(), CountIterVal());
//    for (auto& e : sortV)
//    {
//        cout << e->first << ":" << e->second << " ";
//    }
//    cout << endl;

//    vector<pair<string, int>> sortV;
//
//    for (auto& e: countMap) {
//        sortV.push_back(e);
//    }
//
//    sort(sortV.begin(), sortV.end(), CountVal());
//
//    for (auto& e : sortV)
//    {
//        cout << e.first << ":" << e.second << " ";
//    }
//    cout << endl;


    //multmap
//    multimap<int, string, greater<int>> sortMap;
//    for (auto& kv: countMap)
//    {
//        sortMap.insert(make_pair(kv.second, kv.first));
//    }
//
//    for (auto& e : sortMap)
//    {
//        cout << e.first << ":" << e.second << " ";
//    }
//    cout << endl;

    // priority_queue
    priority_queue<map<string, int>::iterator, vector<map<string, int>::iterator>, CountIterVal> pq;

    map<string, int>::iterator it = countMap.begin();
    while (it != countMap.end()) {
        pq.push(it);
        ++it;
    }


//    for (auto &kv: countMap) {
//        pq.push(kv);
//    }

    while (k--) {
        cout << pq.top()->first << ":" << pq.top()->second << endl;
        pq.pop();
    }
    cout << endl;



}


int main() {
//    TestSet1();
//    TestMultiSet();
//    TestMap();
//    TestMap2();
//    TestMap3();
//    TestMultiMap();

    vector<string> fruits = {"苹果", "苹果", "香蕉", "菠萝", "橘子", "橙子", "栗子"};
    GetFavoriteFruit(fruits, 2);


    return 0;

}