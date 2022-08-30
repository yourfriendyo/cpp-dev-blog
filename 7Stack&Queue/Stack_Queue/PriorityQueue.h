#pragma once
namespace test
{
	template <class T>
	struct Less {
		bool operator()(const T& left, const T& right) const {
			return left < right;
		}
	};
	template <class T>
	struct Greater {
		bool operator()(const T& left, const T& right) const {
			return left > right;
		}
	}; 
	template <class T, class Container = vector<T>, class Compare = Less<T>>
	//默认传入less，排得是大堆（莫非寓意后面的数据比前面的less）
	class priority_queue
	{
	private:
		//size_t 出事
		void adjust_up(int child) 
		{
			while (child > 0) {
				int parent = (child - 1) / 2;
				//if (_con[child] > _con[parent]) {
				if (Compare()(_con[parent], _con[child])) {
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else {
					break;
				}
			}
		}
		void adjust_down(int parent) {
			int child = parent * 2 + 1;
			while (child < _con.size()) {
				//if (child + 1 < _con.size() && _con[child + 1] > _con[child]) {
				if (child + 1 < _con.size() && 
					Compare()(_con[child], _con[child + 1])) 
				{
					child = child + 1;
				}
				//if (_con[child] > _con[parent]) {
				if (Compare()(_con[parent], _con[child])) {
					swap(_con[child], _con[parent]);
					parent = child;
				}
				else {
					break;
				}
			}
		}
	public:
		priority_queue() 
		{}
		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_con(first, last)
		{
			if (_con.size() < 2) {
				return;
			}
			//建堆
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; i--) {
				adjust_down(i);
			}
		}
		void push(const T& x) {
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}
		void pop() {
			swap(_con[0], _con[size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}
		bool empty() const {
			return _con.empty();
		}
		int size() const {
			return _con.size();
		}
		T& top() {
			return _con.front();
		}
	private:
		Container _con;
	};
	void test_priority_queue() {
		//priority_queue<int> pq
		priority_queue<int,vector<int>,greater<int>> pq;
		pq.push(1);
		pq.push(2);
		pq.push(3);
		pq.push(4);
		pq.push(5);

		while (!pq.empty()) {
			cout << pq.top() << endl;
			pq.pop();
		}
		cout << endl;
	}
}