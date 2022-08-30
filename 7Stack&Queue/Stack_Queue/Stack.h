#pragma once
namespace test
{
	template <class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(int x) {
			_con.push_back(x);
		}
		void pop() {
			_con.pop_back();
		}
		bool empty() {
			return _con.empty();
		}
		bool size() {
			return _con.size();
		}
		T& top() { 
			return _con.back();
		}
	private:
		Container _con;
	};
	void test_stack() 
	{
		stack<int> st1;
		stack<int, list<int>> st2;
		st1.push(1);
		st1.push(2);
		st1.push(3);
		st1.push(4);
		while (!st1.empty())
		{
			cout << st1.top() << " ";
			st1.pop();
		}
		cout << endl;

		st2.push(1);
		st2.push(2);
		st2.push(3);
		st2.push(4);
		while (!st2.empty())
		{
			cout << st2.top() << " ";
			st2.pop();
		}
		cout << endl;
	}
}

