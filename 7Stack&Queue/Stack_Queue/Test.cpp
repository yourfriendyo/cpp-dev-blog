#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <list>  
using namespace std;
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"
using namespace test;

//void TestStack()
//{
//	stack<int> s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.push(4);
//
//	while (!s.empty()) {
//		cout << s.top() << " ";
//		s.pop();
//	}
//	cout << endl;
//}
//void TestQueue()
//{
//	std::queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	while (!q.empty()) {
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//}

int main() 
{

	//test_stack();
	//test_queue();
	test_priority_queue();

	return 0;
}