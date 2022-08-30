#pragma once
#include <iostream>
#include <list>
#include <algorithm>	
#include <cassert>
#include "revser_iterator.h"

using namespace std;
namespace test
{
	template <class T>
	struct __list_node
	{
		__list_node(const T& data = T())
			: _prev(nullptr)
			, _next(nullptr)
			, _data(data)
		{}
		//
		__list_node* _prev;
		__list_node* _next;
		T _data;
	};

	template <class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
		__list_iterator(Node* node)
			: _node(node)
		{}
		//*it
		Ref operator*()
		{
			return _node->_data;
		}
		//->
		Ptr operator->()
		{
			return &_node->_data;
		}
		//it!=it
		bool operator!=(const self& it) const
		{
			return _node != it._node;
		}
		//++it
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		//it++
		self operator++(int)
		{
			self tmp(_node);
			_node = _node->_next;
			return tmp;
		}
		//--it	
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		//it--
		self operator--(int)
		{
			self tmp(_node);
			_node = _node->_prev;
			return tmp;
		}

		//
		Node* _node;
	};

	template <class T>
	class list
	{
	public:
		typedef __list_node<T> Node;
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		typedef test::reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef test::reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

		/* constructor */
		list(T x = T())
			:_head(new Node(x))
		{
			_head->_prev = _head;
			_head->_next = _head;
		}
		//taditional
		//list(const list<T>& lt)
		//	:_head(new Node)
		//{
		//	_head->_prev = _head;
		//	_head->_next = _head;
		//	for (auto e : lt) 
		//	{
		//		push_back(e);
		//	}
		//}
		//list& operator=(const list<T>& lt)
		//{
		//	if (this != &lt)
		//	{
		//		clear();
		//		for (auto e : lt)
		//		{
		//			push_back(e);
		//		}
		//	}
		//	return *this;
		//}
		
		//list<int> lt(3, 5);
		list(int n, const int val = int())
			:_head(new Node)
		{
			_head->_prev = _head;
			_head->_next = _head;
			while (n)
			{
				push_back(val);
				n--;
			}
		}
		list(size_t n, const T& val = T())
			:_head(new Node)
		{
			_head->_prev = _head;
			_head->_next = _head;
			while (n)
			{
				push_back(val);
				n--;
			}
		}
		template <class InputIterator>
		list(InputIterator first, InputIterator last)
			:_head(new Node)
		{
			_head->_prev = _head;
			_head->_next = _head;
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		//modern
		list(const list<T>& lt)
			: _head(new Node)
		{
			_head->_prev = _head;
			_head->_next = _head; //处理随机值
			list<T> tmp(lt.begin(),lt.end());
			//swap(_head, tmp._head);
		}
		list& operator=(const list<T> lt)
		{
			//swap(_head, lt._head);
			return *this;
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		/* iterator */
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}
		/* modify */
		iterator insert(iterator pos, const T& x)
		{
			Node* newNode = new Node(x);
			Node* prev = pos._node->_prev;
			Node* cur  = pos._node;
			// prev - newNode - cur
			prev->_next = newNode;
			newNode->_prev = prev;
			cur ->_prev = newNode;
			newNode->_next =  cur;
			return iterator(newNode);
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;
			delete pos._node;
			// prev - pos - after
			prev->_next = next;
			next->_prev = prev;
			return iterator(next);
		}
		void push_back(const T& data)
		{
			//Node* newNode = new Node(data);
			//Node* tail = _head->_prev;
			//tail->_next = newNode;
			//newNode->_prev = tail;
			//_head->_prev = newNode;
			//newNode->_next = _head;
			insert(end(), data);
		}
		void pop_back()
		{
			erase(--end());
		}
		void push_front(const T& data)
		{
			insert(begin(), data);
		}
		void pop_front()
		{
			erase(begin());
		}
		/* capacity */
		void clear()
		{
			iterator it = begin();
			
			//while (it != end())
			//{
			//	iterator del = it++;
			//	delete del._node;
			//}
			//_head->_prev = _head;
			//_head->_next = _head;
			
			
			while (it != end()) {
				it = erase(it);
			}
		}
		size_t size() const
		{
			assert(!empty());
			size_t n = 0;
			for (auto e : *this)
			{
				n++;
			}
			return n;
		}
		bool empty() const
		{
			return _head->_next == _head;
		}
		T& front()
		{
			return *begin();
		}
		const T& front() const
		{
			return *begin();;
		}
		T* back()
		{
			return *end();
		}
		const T* back() const
		{
			return *end();
		}
		void swap(list<T>& lt)
		{
			swap(_head, lt._head);
		}

	private:
		Node* _head;
	};

	template <class T>
	void print_list(const list<T>& lt)
	{
		list<int>::const_iterator cit = lt.begin();
		while (cit != lt.end())
		{
			cout << *cit << " ";
			++cit;
		}
		cout << endl;
	}
	template <class inputiterator, class T>
	inputiterator find(inputiterator first, inputiterator last, const T& data)
	{
		list<int>::iterator it = last;
		while (it != last)
		{
			if (data == it._node->_data)
			{
				return it;
			}
			++it;
		}
		return last;
	}
	struct Date
	{
		int _year;
		int _month;
		int _day;
		Date(int year = 1, int month = 1, int day = 1)
			: _year(year), _month(month), _day(day)
		{}
	};

	void TestList1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
	}
	void TestList2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		//list<int>::iterator it = lt.begin();
		//while (it != lt.end()) 
		//{
		//	cout << *it << " ";
		//	it++;
		//}
		//cout << endl;

		print_list(lt);

		list<int>::iterator pos = find(lt.begin(), lt.end(), 5);

		pos = lt.insert(lt.end(), 50);
		print_list(lt);
		lt.erase(pos);
		print_list(lt);
	}
	void TestList3()
	{
		list<int> lt;
		lt.push_back(1);
		print_list(lt);
		lt.push_back(2);
		print_list(lt);

		lt.pop_back();
		print_list(lt);
		lt.pop_back();
		print_list(lt);

		lt.push_front(2);
		print_list(lt);
		lt.push_front(1);
		print_list(lt);

		lt.pop_front();
		print_list(lt);
		lt.pop_front();
		print_list(lt);

	}
	void TestList4()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);
		print_list(lt1);

		list<int> lt2(lt1);
		print_list(lt2);

		list<int> lt3;
		lt3 = lt2;
		print_list(lt3);

		lt3.clear();
		print_list(lt3);
		lt3.push_back(1);
		lt3.push_back(2);
		lt3.push_back(3);
		print_list(lt3);
	}
	void TestList5()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::reverse_iterator rit = lt.rbegin();
		while (rit != lt.rend())
		{
			cout << *rit << " ";
			++rit;
		}

	}
	void TestList6()
	{
		list<Date> lt1;
		lt1.push_back(Date(2022, 3, 27));
		lt1.push_back(Date(2022, 3, 28));
		lt1.push_back(Date(2022, 3, 29));
		lt1.push_back(Date(2022, 3, 30));

		list<Date>::iterator it = lt1.begin();

		while (it != lt1.end()) {
			//cout << (*it)._year << "/" << (*it)._month << "/" << (*it)._day << endl;
			cout << it->_year << "/" << it->_month << "/" << it->_day << endl;
			++it;
		}
	}
	void TestList7() 
	{
		//list<int> lt;
		//list<int>::iterator it = lt.begin();
		//lt.push_back(1);
		//lt.push_back(2);
		//lt.push_back(3);
		//lt.push_back(4);

		//print_list(lt);
		//lt.clear();
		//print_list(lt);

		list<Date> lt1(3, Date(2020,1,1));


		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.push_back(6);
		lt.push_back(7);

		list<int>::reverse_iterator rit = lt.rbegin();
		while (rit != lt.rend()) 
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;
	}
}
