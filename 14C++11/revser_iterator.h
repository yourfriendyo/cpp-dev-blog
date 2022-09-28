#pragma once
#include <iostream>
using namespace std;

namespace test
{
	template <class Iterator, class Ref, class Ptr>
	struct reverse_iterator
	{
		typedef reverse_iterator self;
		reverse_iterator(Iterator it)
			:_it(it)
		{}

		Ref operator*()
		{
			//return *_it;
			Iterator tmp = _it;
			return *--tmp;
		}
		Ptr operator->()
		{
			Iterator tmp = _it;
			return &*--tmp;
		}

		self& operator++()
		{
			--_it;
			return *this;
		}
		self& operator--()
		{
			++_it;
			return *this;
		}

		bool operator!=(const self& it)
		{
			return _it != it._it;
		}

	private:
		Iterator _it;
	};
}