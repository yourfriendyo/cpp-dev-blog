#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

/* ���캯�� */
//int main()
//{
//	//cout << "String" << endl;
//
//	//string s1("hello");
//
//	//cout << sizeof(char) << endl;//1
//	//cout << sizeof(wchar_t) << endl;//4
//
//	string s1;//Ĭ�Ϲ��캯��
//	string s2("hello");//���캯��
//	string s3(s2);//��������
//
//	//cin >> s1;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	string s4(s2, 1, 2);//���±�Ϊ1���±�Ϊ2
//	cout << s4 << endl;
//
//	string s5("hello world", 4);//��ǰn���ַ�����
//	cout << s5 << endl;
//
//	string s6(10, '!');//��n���ַ�����
//	cout << s6 << endl;
//
//	string s7 = "s7";//��ֵ����
//	string s8 = s7;//��ֵ����
//
//	return 0;
//}


/* �������� */
//int main()
//{
//	string s1("hehe");
//	string s2("������");
//
//	cout << s1.size() << endl;//������'\0'����Ч�ַ�����
//	cout << s2.length() << endl;
//
//	cout << s1.max_size() << endl;
//
//	cout << s1.capacity() << endl;
//	s1.clear();//���
//	cout << s1 << endl;
//	cout << s1.capacity() << endl;
//
//	cout << s1.empty() << endl;//�п�
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


/* ���ʲ���*/
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
//	//��������
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
//	//���������
//	string s1("hello world");
//	string::iterator it = s1.begin();
//	while (it != s1.end()) {
//		*it += 1;
//		it++;
//	}
//	
//	it = s1.begin();//������ʼλ��
//	while (it != s1.end()) {
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	//�������������
//	string::const_iterator cit = s1.cbegin();
//	while (cit != s1.cend()) {
//		cout << *cit << endl;
//		cit++;
//	}
//	cout << endl;
//	string s2 = ("hello string");
//	//���������
//	string::reverse_iterator rit = s2.rbegin();
//	while (rit != s2.rend()) {
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//	//�������������
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
//	//3.��Χfor
//
//	//for (auto& e : s) {
//	//	e -= 1;
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//	return 0;
//}


/* �޸Ĳ��� */
//int main()
//{
//	string s1("hehe");
//	string s2("haha");
//
//	s1.push_back('c'); // β���ַ�
//
//	s1.append("ddd"); // β���ַ���
//	s1.append(s2);
//	cout << s1 << endl;
//
//	s1 += "sss"; //+= �ַ���
//	s1 += s2; // += ����
//	s1 += 'a';
//
//	cout << s1 << endl;
//
//	return 0;
//}

//int main()
//{
//	string s("hello world");
//	s.insert(0, s, 0, 5);//ָ��λ�ò���ָ���Ĳ��ֶ���
//	s.insert(0, "insert", 3);//ָ��λ�ò���ָ���Ĳ����ַ���
//
//	s.insert(0, 5, 'c');//ָ��λ�ò���n���ַ�
//	s.insert(s.begin(), 'c');//ָ��λ�ò����ַ�
//	s.insert(0, s);//ָ��λ�ò������
//	s.insert(0, "insert");//ָ��λ�ò����ַ���
//	
//	cout << s << endl;
//	return 0;
//}
//int main()
//{
//	string s("hello world"); 
//	s.erase(0,	1);//ɾ���±�λ����֮��ָ�����ȵ��ַ���
//	cout << s << endl;
//	s.erase(s.begin());//ɾ��ָ��������λ�õ��ַ�
//	cout << s << endl;
//	s.erase(s.begin(), s.end());//ɾ��ָ��������������ַ�
//	cout << s << endl;
//
//	return 0;
//}


/* ���ݻ��� */
//void TestPushBack() {
//	string s;
//	s.reserve(1000);//Ϊ�ַ���������ǰ���ٺ�1000�ֽڵ�����
//	size_t sz = s.capacity();
//	cout << "capacity: " << sz << endl;
//	cout << "making s grow:\n";
//	for (int i = 0; i < 1000; i++) {
//		s += 'c';//����ַ�
//     	if (sz != s.capacity()) {
//			//��������
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


/* ���Ҳ��� */
//int main()
//{
//	string s("hello world");
//	cout << s << endl;
//	cout << s.c_str() << endl;
//
//	string file("test.txt.tar.gz");
//	FILE* ptr = fopen(file.c_str(), "w");
//
//	//�ҳ��ļ���׺
//	size_t pos = file.rfind('.');
//	if (pos != string::npos) {
//		//��׺
//		string suffix = file.substr(pos, file.size() - pos);//�±꣬����
//		//string suffix = file.substr(pos, string::npos);//�±꣬��ֵ
//		//string suffix = file.substr(pos);//�±�
//		cout << suffix << endl;
//	}
//
//	return 0;
//}

//����url��ַ
//http://www.cplusplus.com/reference/string/string/find/
//int main()
//{
//	//����ҿ��±�������ȼ���һ��λ�õ��±�
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


/* �������� */

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


/* ģ��ʵ�� */

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
