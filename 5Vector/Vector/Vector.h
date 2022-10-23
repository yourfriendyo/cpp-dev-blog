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
		/*����Ŀ�������ֻ��ע��Ч���ݲ��֣�ʣ�������������*/
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
				//����
				T* tmp = new T[n];
				if (_start) {
					//memcpy(tmp, _start, size() * sizeof(T));
					for (int i = 0; i < size(); i++) 
					{
						tmp[i] = _start[i];//_startָ��Ŀռ���������Ͷ���������
					}
					delete[] _sta rt;
				}
				size_t oldSize = size(); //�ͷŲ���ı��ַ���
				// ���µ�����λ��
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
				while (_finish != _start + n) //����_finish
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
				//����
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
			assert(_start <= pos && pos <= _finish); //���posλ���Ƿ�Ϸ�
			// ����
			if (_finish == _end_of_storage) {
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2); //���ݻᵼ�µ�����ʧЧ��������λ�ó¾�
				pos = _start + len; //���ݺ����pos
			}
			// ���� [pos,_finish)
			iterator end = _finish;
			while (end != pos) {
				*end = *(end - 1);
				--end;
			}
			// ����
			*pos = val;
			++_finish;
			return pos; //���ص���������λ��
		}
		iterator erase(iterator pos)
		{
			assert(_start <= pos && pos < _finish);
			//ǰ��
			/*
			iterator begin = pos;
			while (begin != _finish)
			{
				*begin = *(begin + 1); //Խ����� begin=_finish-1ʱ��begin+1 == _finish
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
			memset(_start, val, sizeof(T) * n); //������ֵError
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


		//���Գ���
		// 1 2 3 4 5 -> ����
		// 1 2 3 4   -> ���� - ż����β
		// 1 2 4 5   -> ���� - ����ż��
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		//v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		//ɾ������ż��
		vector<int>::iterator pos = v1.begin();
		while (pos != v1.end())
		{
			if (*pos % 2 == 0)
			{
				pos = v1.erase(pos);//ɾ����pos��λ����������Ԫ��
			}
			else
			{
				++pos;//������ɾ�������ĲŽ�λ
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