
#include "List.h"
using namespace std;

//void test_list1()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//
//	list<int>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	list<int>::reverse_iterator rit = lt.rbegin();
//	while (rit != lt.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	lt.push_front(0);
//	lt.push_front(-1);
//	lt.push_front(-2);
//	list<int>::iterator it2 = lt.begin();
//	while (it2 != lt.end())
//	{
//		cout << *it2 << " ";
//		it2++;
//	}
//	cout << endl;
//
//	lt.pop_front();
//	lt.pop_back();
//
//	list<int>::iterator it3 = lt.begin();
//	while (it3 != lt.end())
//	{
//		cout << *it3 << " ";
//		it3++;
//	}
//	cout << endl;
//}
//void test_list2()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(5);
//	lt.push_back(8);
//	lt.push_back(4);
//	lt.push_back(4);
//	lt.push_back(3);
//	lt.push_back(4);
//
//	lt.sort();
//
//	list<int>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	lt.unique();
//	list<int>::iterator it2 = lt.begin();
//	while (it2 != lt.end())
//	{
//		cout << *it2 << " ";
//		it2++;
//	}
//	cout << endl;
//}
//void test_list3()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	list<int> list;
//	list.push_back(1);
//	list.push_back(2);
//	list.push_back(3);
//
//	list.splice(list.begin(), lt, lt.begin(), lt.end());
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	for (auto e : list)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//}

using namespace test;
int main()
{
	//TestList1();
	//TestList2();
	//TestList3();
	//TestList4();
	//TestList5();
	//TestList6();
	TestList7();


	return 0;
}
