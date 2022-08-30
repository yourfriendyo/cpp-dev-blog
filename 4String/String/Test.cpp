#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

/* 构造函数 */
//int main()
//{
//	//cout << "String" << endl;
//
//	//string s1("hello");
//
//	//cout << sizeof(char) << endl;//1
//	//cout << sizeof(wchar_t) << endl;//4
//
//	string s1;//默认构造函数
//	string s2("hello");//构造函数
//	string s3(s2);//拷贝构造
//
//	//cin >> s1;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	string s4(s2, 1, 2);//从下标为1到下标为2
//	cout << s4 << endl;
//
//	string s5("hello world", 4);//用前n个字符构造
//	cout << s5 << endl;
//
//	string s6(10, '!');//用n个字符构造
//	cout << s6 << endl;
//
//	string s7 = "s7";//赋值重载
//	string s8 = s7;//赋值重载
//
//	return 0;
//}


/* 容量操作 */
//int main()
//{
//	string s1("hehe");
//	string s2("我来了");
//
//	cout << s1.size() << endl;//不包含'\0'，有效字符长度
//	cout << s2.length() << endl;
//
//	cout << s1.max_size() << endl;
//
//	cout << s1.capacity() << endl;
//	s1.clear();//清空
//	cout << s1 << endl;
//	cout << s1.capacity() << endl;
//
//	cout << s1.empty() << endl;//判空
//
//
//	return 0;
//}

//int main()
//{
//	string s1 = "hello world";
//	s1.reserve(100);
//
//	string s2 = "hello world";
//	s2.resize(100, 'x');
//	string::iterator it = s2.begin();
//	while (it != s2.end()) {
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl; 
//	
//	s2.resize(1);
//	it = s2.begin();
//	while (it != s2.end()) {
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	return 0;
//}


/* 访问操作*/
//#include <list>
//int main()
//{
//	//string s1 = "hehehe";
//
//	//for (size_t i = 0; i < s1.size(); i++) {
//	//	cout << s1[i] << " ";
//	//	cout << s1.operator[](i) << " ";
//	//}
//	//cout << endl;
//
//	//for (size_t i = 0; i < s1.size(); i++) {
//	//	s1[i] += 1;
//	//}
//
//	//for (size_t i = 0; i < s1.size(); i++) {
//	//	cout << s1[i] << " ";
//	//}
//	//cout << endl;
//
//	//for (size_t i = 0; i < s1.size(); i++) {
//	//	s1.at(i) -= 1;
//	//}
//	//cout << s1 << endl;
//
//	//for (size_t i = 0; i < s1.size(); i++) {
//	//	//	cout 
//	//}
//
//	//s1[1111];
//	//try {
//	//	s1.at(111);
//	//}
//	//catch (exception e) {
//	//	cout << "exception" << endl;
//	//}
//
//
//	//string s1("hello world");
//
//	//遍历操作
//	
//	//1.[]
//
//	//for (size_t i = 0; i < s1.size(); i++) {
//	//	s1[i] += 1;
//	//}
//	//for (size_t i = 0; i < s1.size(); i++) {
//	//	cout << s1[i] << " ";
//	//}
//	//cout << endl;
//	
//	//2.iterator
//	
//	//正向迭代器
//	string s1("hello world");
//	string::iterator it = s1.begin();
//	while (it != s1.end()) {
//		*it += 1;
//		it++;
//	}
//	
//	it = s1.begin();//返回起始位置
//	while (it != s1.end()) {
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	//常量正向迭代器
//	string::const_iterator cit = s1.cbegin();
//	while (cit != s1.cend()) {
//		cout << *cit << endl;
//		cit++;
//	}
//	cout << endl;
//	string s2 = ("hello string");
//	//反向迭代器
//	string::reverse_iterator rit = s2.rbegin();
//	while (rit != s2.rend()) {
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//	//常量反向迭代器
//	string::const_reverse_iterator crit = s2.crbegin();
//	while (crit != s2.crend()) {
//		cout << *crit << endl;
//		crit++;
//	}
//	cout << endl;
//	//list<int>
//	list<int> li(10,5);
//	list<int>::iterator liit = li.begin();
//	while (liit != li.end()) {
//		cout << *liit << " ";
//		liit++;
//	}
//	cout << endl;
//
//	//3.范围for
//
//	//for (auto& e : s) {
//	//	e -= 1;
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//	return 0;
//}


/* 修改操作 */
//int main()
//{
//	string s1("hehe");
//	string s2("haha");
//
//	s1.push_back('c'); // 尾插字符
//
//	s1.append("ddd"); // 尾插字符串
//	s1.append(s2);
//	cout << s1 << endl;
//
//	s1 += "sss"; //+= 字符串
//	s1 += s2; // += 对象
//	s1 += 'a';
//
//	cout << s1 << endl;
//
//	return 0;
//}

//int main()
//{
//	string s("hello world");
//	s.insert(0, s, 0, 5);//指定位置插入指定的部分对象
//	s.insert(0, "insert", 3);//指定位置插入指定的部分字符串
//
//	s.insert(0, 5, 'c');//指定位置插入n个字符
//	s.insert(s.begin(), 'c');//指定位置插入字符
//	s.insert(0, s);//指定位置插入对象
//	s.insert(0, "insert");//指定位置插入字符串
//	
//	cout << s << endl;
//	return 0;
//}
//int main()
//{
//	string s("hello world"); 
//	s.erase(0,	1);//删除下标位置起之后指定长度的字符串
//	cout << s << endl;
//	s.erase(s.begin());//删除指定迭代器位置的字符
//	cout << s << endl;
//	s.erase(s.begin(), s.end());//删除指定迭代器区间的字符
//	cout << s << endl;
//
//	return 0;
//}


/* 增容机制 */
//void TestPushBack() {
//	string s;
//	s.reserve(1000);//为字符串对象提前开辟好1000字节的容量
//	size_t sz = s.capacity();
//	cout << "capacity: " << sz << endl;
//	cout << "making s grow:\n";
//	for (int i = 0; i < 1000; i++) {
//		s += 'c';//添加字符
//     	if (sz != s.capacity()) {
//			//发生增容
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << endl;
//		}
//	}
//}
//int main()
//{
//
//	TestPushBack();
//
//	return 0;
//}


/* 查找操作 */
//int main()
//{
//	string s("hello world");
//	cout << s << endl;
//	cout << s.c_str() << endl;
//
//	string file("test.txt.tar.gz");
//	FILE* ptr = fopen(file.c_str(), "w");
//
//	//找出文件后缀
//	size_t pos = file.rfind('.');
//	if (pos != string::npos) {
//		//后缀
//		string suffix = file.substr(pos, file.size() - pos);//下标，长度
//		//string suffix = file.substr(pos, string::npos);//下标，最值
//		//string suffix = file.substr(pos);//下标
//		cout << suffix << endl;
//	}
//
//	return 0;
//}

//解析url地址
//http://www.cplusplus.com/reference/string/string/find/
//int main()
//{
//	//左闭右开下标减，长度即下一个位置的下标
//	string url("http://www.cplusplus.com/reference/string/string/find/");
//	string protocol;
//	string Domain;
//	string path;
//
//	int pos1 = url.find(':', 0);
//	if (pos1 != string::npos) {
//		protocol = url.substr(0, pos1 - 0);//http : 0~pos1
//	}
//	int pos2 = url.find('/', pos1 + 3);
//	if (pos2 != string::npos) {
//		Domain = url.substr(pos1 + 3, pos2 - (pos1 + 3)); //www.cplusplus.com : pos1~pos2
//	}
//
//	path = url.substr(pos2, url.size() - pos2);///reference/string/string/find/ : pos2~npos
//
//	cout << protocol << endl;
//	cout << Domain << endl;
//	cout << path << endl;
//
//	return 0;
//}


/* 其他操作 */

//int main()
//{
//	string s1 = "string:";
//	string s2 = "hello world";
//	swap(s1, s2);
//	cout << "s1: " << s1 << endl;
//	cout << "s2: " << s2 << endl;
//	return 0;
//}
//int main()
//{
//	string s1("money");
//	string s2("goods");
//
//	cout << "Before the swap, buyer has " << s1;
//	cout << " and seller has " << s1 << '\n';
//
//	swap(s1, s2);
//
//	cout << " After the swap, buyer has " << s1;
//	cout << " and seller has " << s2 << '\n';
//
//	return 0;
//}
//int main()
//{
//	string s("111");
//	int i = stoi(s);
//	long l = stol("1111111");
//	cout << i << endl;
//	cout << l << endl;
//
//	string s1 = to_string(1.111);
//	cout << s1 << endl;
//
//	return 0;
//}


/* 模拟实现 */

#include "String.h"
using namespace test;

int main()
{
	//TestString1();
	//TestString2();
	//TestString3();
	//TestString4();
	//TestString5();
	TestString6();
	//TestString7();
	//TestString8();
}

//int main()
//{
//	string str1 = "hello world";
//	string str2 = str1;
//
//	printf("Sharing the memory:\n");
//	printf("/tstr1's address: %x\n", str1.c_str());
//	printf("/tstr2's address: %x\n", str2.c_str());
//
//	str1[1] = 'q';
//	str2[1] = 'w';
//
//	printf("After Copy-On-Write:\n");
//	printf("/tstr1's address: %x\n", str1.c_str());
//	printf("/tstr2's address: %x\n", str2.c_str());
//
//	return 0;
//}
