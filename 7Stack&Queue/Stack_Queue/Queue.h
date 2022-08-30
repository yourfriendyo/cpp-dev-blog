#pragma once
namespace test
{
	template <class T, class Container = deque<T>>
	class queue
	{
	public:
		void push(int x) {
			_con.push_back(x);
		}
		void pop() {
			_con.pop_front();
		}
		bool empty() {
			return _con.empty();
		}
		bool size() {
			return _con.size();
		}
		T& front() {
			return _con.front();
		}
	private:
		Container _con;
	};
	void test_queue()
	{
		queue<int> q1;
		queue<int, list<int>> q2;
		q1.push(1);
		q1.push(2);
		q1.push(3);
		q1.push(4);
		while (!q1.empty()) 
		{
			cout << q1.front() << " ";
			q1.pop();
		}
		cout << endl;

		q2.push(1);
		q2.push(2);
		q2.push(3);
		q2.push(4);
		while (!q2.empty())
		{
			cout << q2.front() << " ";
			q2.pop();
		}
		cout << endl;
	}
}