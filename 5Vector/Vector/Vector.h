using namespace std;
namespace test
{
	template <class T>
	class vector {
	public:
		void print()
		{
			for (auto e : *this)
			{
				cout << e << " ";
			}
			cout << endl;
		}

		/* constructor */
		//default constructor
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}
		//fill constructor
		vector(size_t n, const T& val = T())
			: _start(new T[n])
			, _finish(_start + n)
			, _end_of_storage(_finish)
		{
			memset(_start, val, sizeof(T) * n);
		}
		//range constructor
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first++);
			}
		}
		//copy constructor
		//vector(const vector<T>& v)
		//	: _start(new T[v.capacity()])
		//	, _finish(_start + v.size())
		//	, _end_of_storage(_start + v.capacity())
		//{
		//	memcpy(_start, v._start, sizeof(T) * v.size());
		//}
		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}
		/*库里的拷贝构造只关注有效数据部分，剩余容量不作理会*/
		~vector()
		{
			delete[] _start;
			_start = nullptr;
			_finish = nullptr;
			_end_of_storage = nullptr;
		}
		vector<T>& operator=(vector<T> v)  /* pass by value */
		{
			swap(v);
			return *this;
		}

		/* capacity */
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		bool empty() const
		{
			return _start == _finish;
		}
		void reserve(size_t n)
		{
			if (n > capacity()) {
				//增容
				T* tmp = new T[n];
				if (_start) {
					//memcpy(tmp, _start, size() * sizeof(T));
					for (int i = 0; i < size(); i++) 
					{
						tmp[i] = _start[i];//_start指向的空间存任意类型都能完成深拷贝
					}
					delete[] _sta rt;
				}
				size_t oldSize = size(); //释放不会改变地址编号
				// 更新迭代器位置
				_start = tmp;
				_finish = _start + oldSize;
				_end_of_storage = _start + n;
			}
		}
		void resize(size_t n, const T& val = T())
		{
			/*
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				memset(_start, val, n);
				_finish = _start + n;
			}
			*/
			if (n > size())
			{
				if (n > capacity())
				{
					reserve(n);
				}
				//memset(_start, val, sizeof(T) * n);
				while (_finish != _start + n) //设置_finish
				{
					*_finish = val;
					_finish++;
				}
			}
			//_finish = _start + n; 
		}

		/* access */
		T& operator[] (size_t pos) {
			return *(_start + pos);
		}
		const T& operator[](size_t pos) const {
			return *(_start + pos);
		}
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}

		/* modify */
		void swap(vector<T> v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage) {
				//增容
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}
		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}
		iterator insert(iterator pos, const T& val)
		{
			assert(_start <= pos && pos <= _finish); //检查pos位置是否合法
			// 增容
			if (_finish == _end_of_storage) {
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2); //增容会导致迭代器失效，迭代器位置陈旧
				pos = _start + len; //增容后更新pos
			}
			// 后移 [pos,_finish)
			iterator end = _finish;
			while (end != pos) {
				*end = *(end - 1);
				--end;
			}
			// 插入
			*pos = val;
			++_finish;
			return pos; //返回迭代器最新位置
		}
		iterator erase(iterator pos)
		{
			assert(_start <= pos && pos < _finish);
			//前移
			/*
			iterator begin = pos;
			while (begin != _finish)
			{
				*begin = *(begin + 1); //越界访问 begin=_finish-1时，begin+1 == _finish
				begin++;
			}*/
			iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				begin++;
			}
			_finish--;
			return pos;
		}
		void assign(size_t n, const T& val)
		{
			resize(n);
			memset(_start, val, sizeof(T) * n); //出其他值Error
		}
		void clear()
		{
			_finish = _start;
		}

		/* others */
		bool operator==(vector<T> v)
		{
			if (&v != this)
			{
				for (size_t i = 0; i < size(); i++)
				{
					if ((*this)[i] != v[i])
					{
						return false;
					}
				}
			}
			return true;
		}
		bool operator!=(vector<T> v)
		{
			return !(*this == v);
		}
		bool operator< (vector<T> v)
		{
			for (size_t i = 0; i < size(); i++)
			{
				if ((*this)[i] >= v[i])
				{
					return false;
				}
			}
			return true;
		}
		bool operator<=(vector<T> v)
		{
			return *this < v || *this == v;
		}
		bool operator> (vector<T> v)
		{
			return !(*this <= v);
		}
		bool operator>=(vector<T> v)
		{
			return !(*this < v);
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
	void test_vector1()
	{
		/*vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		v.push_back(5);
		v.print();
		vector<int> v1(v);
		v1.print();*/

		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		//sort(v.begin(), v.end());

		list<int> lt;
		lt.push_back(10);
		lt.push_back(20);
		lt.push_back(30);
		//sort(lt.begin(), lt.end());//Err

		forward_list<int> flt;
		flt.push_front(1);
		flt.push_front(2);
		flt.push_front(3);
		flt.push_front(4);

		//reverse(flt.begin(), flt.end());/Err

	}
	void test_vector2()
	{
		vector<int> v;

		v.reserve(10);
		v.reserve(100);

		v.resize(10);
		v.resize(100);
	}
	void test_vector3()
	{
		vector<int> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.print();

		v.insert(v.begin(), 0);
		v.print();

		v.insert(v.begin(), -1);
		v.print();
	}
	void test_vector4()
	{
		vector<int> v1;
		/*vector<int> v2(v1);*/
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.print();
		/*v2 = v1;
		v2.print();*/

		v1.assign(5, 1);
		v1.print();
	}
	void test_vector5()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		vector<int> v2;
		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);
		v2.push_back(4);
		cout << (v1 == v2) << endl;
		cout << (v1 != v2) << endl;
		cout << (v1 < v2) << endl;
		cout << (v1 <= v2) << endl;
		cout << (v1 > v2) << endl;
		cout << (v1 >= v2) << endl;
	}
	void test_vector6()
	{
		//vector<int> v;
		//v.push_back(1);
		//v.push_back(2);
		//v.push_back(3);
		//v.push_back(4);

		//v.resize(10, 1);
		//vector<int> v1(v.begin(), v.end());
		//v1.print();

		//vector<int>::iterator pos = find(v.begin(), v.end(), 2);
		//if (pos != v.end()) 
		//{
		//	pos = v.insert(pos, 20);
		//}
		//v.print(); 

		//vector<int> v1;
		//v1.push_back(1);
		//v1.push_back(2);
		//v1.push_back(3);
		//v1.push_back(4);
		//vector<int>::iterator pos = find(v1.begin(), v1.end(), 1);
		//if (pos != v1.end()) 
		//{
		//	v1.erase(pos);
		//}
		//v1.print(); 


		//测试场景
		// 1 2 3 4 5 -> 正常
		// 1 2 3 4   -> 崩溃 - 偶数结尾
		// 1 2 4 5   -> 错误 - 连续偶数
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		//v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		//删除所有偶数
		vector<int>::iterator pos = v1.begin();
		while (pos != v1.end())
		{
			if (*pos % 2 == 0)
			{
				pos = v1.erase(pos);//删除后pos复位，避免跳过元素
			}
			else
			{
				++pos;//不符合删除条件的才进位
			}
		}
		v1.print();
	}
	void test_vector7()
	{
		vector<string> v;
		v.push_back("111111111111111111111");
		v.push_back("111111111111111111111");
		v.push_back("1111111");
		v.push_back("1111111");
		v.push_back("1111111");

		v.print();

	}


}