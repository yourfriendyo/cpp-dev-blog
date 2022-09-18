#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <ctime>

using namespace std;

void test_unordered_set()
{
	unordered_set<int> us;
	unordered_multiset<int> ums;
	set<int> s;

	// 去重
	us.insert(5);
	us.insert(1);
	us.insert(2);
	us.insert(7);
	us.insert(1);
	us.insert(3);
	us.insert(1);

	ums.insert(5);
	ums.insert(1);
	ums.insert(2);
	ums.insert(7);
	ums.insert(1);
	ums.insert(3);
	ums.insert(1);

	s.insert(5);
	s.insert(1);
	s.insert(2);
	s.insert(7);
	s.insert(1);
	s.insert(3);
	s.insert(1);

	unordered_set<int>::iterator uit = us.begin();
	cout << "去重 unordered_set: ";
	while (uit != us.end())
	{
		cout << *uit << " ";
		uit++;
	}
	cout << endl;

	unordered_multiset<int>::iterator umit = ums.begin();
	cout << "unordered_multiset: ";
	while (umit != ums.end())
	{
		cout << *umit << " ";
		umit++;
	}
	cout << endl;

	set<int>::iterator it = s.begin();
	cout << "排序+去重      set: ";
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
}

void test_op()
{
	int n = 100000000;
	vector<int> v;
	srand((unsigned int)time(nullptr));
	for (int i = 0; i < n; i++) {
		v.push_back(rand());
		// v.push_back(i);
	}

	set<int> s;
	unordered_set<int> us;

	int begin1 = clock();
	for (auto e : v) {
		s.insert(e);
	}
	int end1 = clock();

	int begin2 = clock();
	for (auto e : v) {
		us.insert(e);
	}
	int end2 = clock();

	cout << "          set insert: " << end1 - begin1 << endl;
	cout << "unordered_set insert: " << end2 - begin2 << endl;


	int begin3 = clock();
	for (auto e : v) {
		s.find(e);
	}
	int end3 = clock();

	int begin4 = clock();
	for (auto e : v) {
		us.find(e);
	}
	int end4 = clock();

	cout << "          set find: " << end3 - begin3 << endl;
	cout << "unordered_set find: " << end4 - begin4 << endl;


	int begin5 = clock();
	for (auto e : v) {
		s.erase(e);
	}
	int end5 = clock();

	int begin6 = clock();
	for (auto e : v) {
		us.erase(e);
	}
	int end6 = clock();

	cout << "          set erase: " << end5 - begin5 << endl;
	cout << "unordered_set erase: " << end6 - begin6 << endl;
}

int main()
{
	// test_unordered_set();

	// test_op();

	unordered_map<int, int> hash;

	for (auto e : hash)
		cout << e.first << ":" << e.second << endl;

	cout << endl << endl;;

	return 0;
}
