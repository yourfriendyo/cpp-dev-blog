#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <forward_list>
#include <cassert>
#include "Vector.h"
using namespace test;

/* vector 的使用 */
//void TestVector1() 
//{
//	vector<int> v1;
//	vector<int> v2(2, 1);
//	vector<int> v3(v2.begin(), v2.end());
//
//	vector<int> v4(v3);
//
//	string s("hello");
//	vector<char> v(s.begin(), s.end());
//}

//void TestVector2()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
	//for (size_t i = 0; i < v1.size(); i++) 
	//{
	//	v1[i] += 1;
	//	cout << v1[i] << " ";
	//}
	//cout << endl;
//}

//void testVector3()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//	vector<int>::iterator it = v1.begin();
//	while (it != v1.end()) 
//	{
//		(*it)-=1;
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	for (auto e : v1) 
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	cout << v1.max_size() << endl;
//
//}

//void testVector3()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//
//	v1.reserve(100);
//	v1.resize(100,1);
//	v1.resize(10);
//
//	v1[8];
//	v1.at(8);
//}

//void testVector4()
//{
//	vector<int> v1({ 1,2,3,4,5 });
//	vector<int> v2;
//	v2 = { 1,2,4,5 };
//	vector<int>::iterator ret = find(v1.begin(), v1.end(), 3);
//	if (ret != v1.end()) 
//	{
//		cout << *ret << endl;
//		/*v1.insert(ret, 30);
//		v1.insert(ret, 2, 30);
//		v1.insert(ret, v2.begin(), v2.end());*/
//	}
//	vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
//	if (pos != v1.end())
//	{
//		/*v1.erase(pos);
//		v1.erase(v1.begin(), v1.end());*/
//	}
//
//	// v1.assign(10, 3); 
//	for (auto e : v1) 
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	v1.clear();
//}

//void testVector5() 
//{
//	vector<int> v;
//	size_t sz = v.capacity();
//	cout << "making v gorw:\n" << endl;
//	for (int i = 0; i < 100; i++) 
//	{
//		v.push_back(1);
//		if (sz != v.capacity()) 
//		{
//			sz = v.capacity();
//			cout << "new capcity:" << sz << endl;
//		}
//	}
//}
//
//int main()
//{
//	cout << "vector" << endl;
//	//TestVector1();
//	//TestVector2();
//	//testVector3();
//	//testVector4();
//	testVector5();
//	return 0;
//}


/* vector 模拟实现 */

int main()
{
	//test_vector1();
	//test_vector6();
	
	test_vector7();


	return 0;
}