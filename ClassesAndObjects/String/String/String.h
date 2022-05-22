#pragma once
#include <iostream>
#include <cassert>
using namespace std;

namespace test
{
	class string {
	public:
		void string::swap(string& s);
		// string
		string(const char* str = "");
		string(const string& s);
		string& operator=(string s);
		//string& operator=(const string& s);
		~string();

		// capacity
		const char* c_str() const;
		size_t size() const;
		size_t capacity() const;
		void reserve(size_t n);
		void string::resize(size_t n, char ch = '\0');

		// access
		char& operator[](size_t pos);
		const char& operator[](size_t pos) const;
		//
		typedef char* iterator;
		typedef const char* const_iterator;
		typedef char* reverse_iterator;
		typedef const char* const_reverse_iterator;
		iterator begin();
		iterator end();
		const_iterator cbegin() const;
		const_iterator cend() const;
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator crbegin() const;
		const_reverse_iterator crend() const;

		// push
		void push_back(char ch);
		void append(char* str);
		string& operator+=(char ch);
		string& operator+=(char* str);
		string& operator+=(string& s);
		//
		string& insert(size_t pos, char ch);
		string& insert(size_t pos, const char* str);
		string& insert(size_t pos, const string& s);
		iterator erase(iterator itPos);
		string& erase (size_t pos = 0, size_t len = npos);
		iterator erase(iterator lit, iterator rit);

		// find
		size_t find (char ch, size_t pos = 0) const;
		size_t find (const char* str, size_t pos = 0) const;
		size_t find (const string& s, size_t pos = 0) const;
		size_t rfind(char ch, size_t pos = 0) const;
		size_t rfind(const char* str, size_t pos = 0) const;
		size_t rfind(const string& s, size_t pos = 0) const;
		//
		string substr(size_t pos = 0, size_t len = npos) const;

		//other
		bool operator==(const string& s) const;
		bool operator==(const char* str) const;
		bool operator!=(const string& s) const;
		bool operator!=(const char* str) const;
		bool operator< (const string& s) const;
		bool operator< (const char* str) const;
		bool operator<=(const string& s) const;
		bool operator<=(const char* str) const;
		bool operator> (const string& s) const;
		bool operator> (const char* str) const;
		bool operator>=(const string& s) const;
		bool operator>=(const char* str) const;

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos;
	};
	const size_t string::npos = -1;


	/* 传统写法 */
	////s1("str")
	//string::string(const char* str)
	//	: _size(strlen(str))
	//	, _capacity(_size)
	//{
	//	_str = new char[_capacity + 1];
	//	strcpy(_str, str);
	//}
	////s1(s2)
	//string::string(const string& s)
	//	: _size(s._size)
	//	, _capacity(s._capacity)
	//{
	//	_str = new char[_capacity + 1];
	//	strcpy(_str, s._str);
	//}
	////s1 = s2
	//string& string::operator=(const string& s)
	//{
	//	if (this != &s) { // 避免自赋值
	//		char* tmp = new char[s._capacity + 1]; // 先开辟空间再释放原空间
	//		strcpy(tmp, s._str);
	//		delete[] _str; //释放后再赋值，避免空间不够或浪费
	//		_str = tmp;
	//		_size = s._size;
	//		_capacity = s._capacity;
	//	}
	//	return *this;
	//}

	/* 现代写法 */
	//string::string(const string& s)
	//	: _str(nullptr)
	//	, _size(strlen(s._str))
	//	, _capacity(_size)
	//{
	//	string tmp(s._str);
	//	swap(_str, tmp._str);
	//}
	//string& string::operator=(const string& s)
	//{
	//	if (this != &s) {
	//		string tmp(s);
	//		swap(_str, tmp._str);
	//		_size = s._size;
	//		_capacity = s._capacity;
	//	}
	//	return *this;
	//}
	//string& string::operator=(string s)
	//{
	//	swap(_str, s._str);
	//	_size = s._size;
	//	_capacity = s._capacity;
	//	return *this;
	//}

	//swap
	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}
	//string
	string::string(const char* str)
		: _size(strlen(str))
		, _capacity(_size)
	{
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}
	string::string(const string& s)
		: _str(nullptr)
	{
		string tmp(s._str);
		swap(tmp);
	}
	string& string::operator=(string s)
	{
		swap(s);
		return *this;
	}
	//string& string::operator=(const string& s)
	//{
	//	if (this != &s) {
	//		string tmp(s);
	//		swap(tmp);
	//	}
	//	return *this;
	//}
	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}

	// size
	const char* string::c_str() const
	{
		return _str;
	}
	size_t string::size() const {
		return _size;
	}
	size_t string::capacity() const
	{
		return _capacity;
	}
	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];//为'\0'开辟空间
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}
	void string::resize(size_t n, char ch)
	{
		//if (n < _size) {
		//	_size = n;
		//	_str[_size] = '\0';
		//}
		//else {
		//	if (n > _capacity) {
		//		reserve(n);
		//	}
		//	memset(_str + _size, ch, n - _size); 
		//	_size = n;
		//	_str[_size] = '\0';
		//}
		if (n > _size) {
			if (n > _capacity) {
				reserve(n);
			}
			memset(_str + _size, ch, n - _size);
		}
		_size = n;
		_str[_size] = '\0';
	}
	// []
	char& string::operator[](size_t pos) {
		assert(pos < _size);
		return _str[pos];
	}
	const char& string::operator[](size_t pos) const {
		assert(pos < _size);
		return _str[pos];
	}
	// iterator
	typedef char* iterator;
	typedef const char* const_iterator;
	typedef char* reverse_iterator;
	typedef const char* const_reverse_iterator;
	iterator string::begin()
	{
		return _str;
	}
	iterator string::end()
	{
		return _str + _size;
	}
	const_iterator string::cbegin() const
	{
		return _str;
	}
	const_iterator string::cend() const
	{
		return _str + _size;
	}
	reverse_iterator string::rbegin()
	{
		return _str + _size - 1;
	}
	reverse_iterator string::rend()
	{
		return _str - 1;
	}
	const_reverse_iterator string::crbegin() const
	{
		return _str + _size - 1;
	}
	const_reverse_iterator string::crend() const
	{
		return _str - 1;
	}

	// +=
	void string::push_back(char ch)
	{
		if (_size == _capacity)
		{
			//普通增容
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size++] = ch;
		_str[_size] = '\0';
	}
	void string::append(char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			//按字符串长度增容
			reserve(_size + len);
		}
		//for (size_t i = 0; i < len; i++)
		//{
		//	_str[_size++] = str[i];
		//}
		//_str[_size] = '\0';

		strcpy(_str + _size, str);
		_size += len;
	}
	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}
	string& string::operator+=(char* str)
	{
		append(str);
		return *this;
	}
	string& string::operator+=(string& s)
	{
		append(s._str);
		return *this;
	}
	string& string::insert(size_t pos, char ch)
	{
		assert(pos <= _size); //==时尾插
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		//后移一位 [pos,_size] 
		/*
		size_t end = _size;
		while (end >= pos) //Err::i>=pos，防无符号死循环，其他解决方法：转int×、比较地址√
		{
			_str[end + 1] = _str[end];
			end--;
		}
		*/
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}
		_size++;
		//插入元素 pos
		_str[pos] = ch;
		return *this;
	}
	string& string::insert(size_t pos, const char* str)
	{
		assert(pos < _size);
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		//后移len位 [pos,_size] 
		if (0) {
			/*
			for (size_t i = _size + 1; i > pos; i--)
			{
				_str[i - 1 + len] = _str[i - 1];//前面元素赋值给后面元素
			}
			*/
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end - 1 + len] = _str[end - 1];
				end--;
			}
		}
		if (0) {
			for (size_t i = _size; i >= pos; i--)//i无符号死循环
			{
				_str[i + len] = _str[i];
			}
		}
		if (0) {
			size_t end = _size + len + 1;
			while (end > pos + len)
			{
				_str[end - 1] = _str[end - len - 1];
				--end;
			}
		}
		if (1) {
			size_t end = _size + len;
			while (end > pos + len)
			{
				_str[end] = _str[end - len];//end-len无符号死循环
				--end;
			}
		}
		_size += len;
		//插入字符串 pos
		/*
		for (size_t i = pos; i < pos + len; i++)
		{
			_str[i] = str[i - pos];
		}
		*/
		strncpy(_str + pos, str, len);
		return *this;
	}
	string& string::insert(size_t pos, const string& s)
	{
		assert(pos < _size);
		insert(pos, s._str);
		return *this;
	}
	iterator string::erase(iterator itPos)
	{
		// 向前移动1位 [pos+1,_size]
		for (iterator it = itPos + 1; it != this->end() + 1; it++)
		{
			*(it - 1) = *it;
		}
		_size--;
		return this->begin();
	}
	string& string::erase (size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len == npos || pos + len >= _size)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else //向前移动len位 [pos, pos + len]
		{
			strcpy(_str + pos, _str + pos + len);
			_size -= len;
		}
		return *this;
	}
	iterator string::erase(iterator lit, iterator rit)
	{
		int len = rit - lit;
		int pos = lit - begin();
		erase(pos, len);
		return this->begin();
	}

	// find
	size_t string::find (char ch, size_t pos) const
	{
		assert(pos < _size);
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}
	size_t string::find (const char* str, size_t pos) const
	{
		assert(pos < _size);
		size_t sp = 0; //遍历str
		size_t s1 = pos, s2 = 0; //s1总指针s2活动指针

		while (s1 < _size)
		{
			if (_str[s2] == str[sp])
			{
				s2++;
				sp++;
			}
			else
			{
				s1++;//不相等s1进位
				s2 = s1;//s2归位
				sp = 0;//s2归位
			}
			if (str[sp] == '\0') //str遍历结束
			{
				return s2 - strlen(str);
			}
		}
		return npos;
	}
	size_t string::find (const string& s, size_t pos) const
	{
		assert(pos < _size);
		return find(s._str, pos);
	}
	size_t string::rfind(char ch, size_t pos) const
	{
		assert(pos < _size);
		for (size_t i = _size; i > pos; i--)
		{
			if (_str[i - 1] == ch) //使用i-1位置进行判断，防无符号死循环
			{
				return i - 1;
			}
		}
		return npos;
	}
	size_t string::rfind(const char* str, size_t pos) const
	{
		assert(pos < _size);
		size_t len = strlen(str);
		size_t sp = len - 1;
		size_t endNext1 = _size, end2 = _size - 1; //end1总指针end2活动指针
		/*endNext1放在end1的下一个位置，防止出现-1死循环的情况*/
		while (endNext1 > 0)
		{
			if (_str[end2] == str[sp])
			{
				end2--;
				sp--;
			}
			else
			{
				endNext1--;//end1--到最后还没找到，导致end1从0减到-1，出现死循环 
				end2 = endNext1 - 1;
				sp = len - 1;
			}
			if (sp == npos)
			{
				return end2 + 1;
			}
		}
		return npos;
	}
	size_t string::rfind(const string& s, size_t pos) const
	{
		assert(pos < _size);
		return rfind(s._str, pos);
	}
	//
	string string::substr(size_t pos, size_t len) const
	{
		assert(pos < _size);
		if (len == npos)
		{
			len = _size;
		}
		string ret;
		for (size_t i = 0; i < len; i++)
		{
			ret += _str[pos + i];
		}
		return ret;
	}

	//other
	bool string::operator==(const char* str) const 
	{
		if (strcmp(_str, str) == 0)
		{
			return true;
		}
		return false;
	}
	bool string::operator==(const string& s) const 
	{
		return _str == s._str;
	}
	bool string::operator!=(const char* str) const 
	{
		return !(_str == str);
	}
	bool string::operator!=(const string& s) const 
	{
		return _str != s._str;
	}
	bool string::operator< (const char* str) const 
	{
		if (strcmp(_str, str) < 0)
		{
			return true;
		}
		return false;
	}
	bool string::operator< (const string& s) const 
	{
		return _str < s._str;
	}
	bool string::operator<=(const char* str) const 
	{
		return _str < str || _str == str;
	}
	bool string::operator<=(const string& s) const 
	{
		return _str <= s._str;
	}
	bool string::operator> (const char* str) const 
	{
		return !(_str <= str);
	}
	bool string::operator> (const string& s) const 
	{
		return _str > s._str;
	}
	bool string::operator>=(const char* str) const 
	{
		return !(_str < str);
	}
	bool string::operator>=(const string& s) const 
	{
		return _str >= s._str;
	}
	//
	istream& operator>>(istream&  in, string& s)
	{
		char ch = in.get();
		while (ch != '\0' && ch != '\n') 
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}
	ostream& operator<<(ostream& out, string& s)
	{
		for (auto ch : s)
		{
			cout << ch;
		}
		return out;
	}

	void TestString1()
	{
		string s1("hello");
		cout << s1.c_str() << endl;

		string s2(s1);
		cout << s2.c_str() << endl;

		string s3;
		s3 = s1;
		cout << s3.c_str() << endl;


		for (auto e : s1) {
			cout << e << " ";
		}
		cout << endl;

		auto it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;


	}
	void TestString2()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		std::string s2;
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s1.size(); i++)
		{
			s1[i]++;
		}

		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

		const string s3("test string");

		for (size_t i = 0; i < s3.size(); i++)
		{
			cout << s3[i] << " ";
		}
	}
	void TestString3()
	{
		string s1("hello world");

		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		string::reverse_iterator rit = s1.rbegin();
		while (rit != s1.rend())
		{
			cout << *rit << " ";
			rit--;//
		}
		cout << endl;

		const string s2("hello string");

		string::const_iterator cit = s2.cbegin();
		while (cit != s2.cend())
		{
			cout << *cit << " ";
			cit++;
		}
		cout << endl;

		string::const_reverse_iterator crit = s2.crbegin();
		while (crit != s2.crend())
		{
			cout << *crit << " ";
			crit--;//
		}
		cout << endl;


		for (auto e : s1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void TestString4()
	{
		string s1("hello world");
		string s2("hello string");

		s1.push_back('p');
		s1.push_back('h');
		cout << s1.c_str() << endl;

		s1.append(" and hello you");
		cout << s1.c_str() << endl;

		s1 += 'N';
		cout << s1.c_str() << endl;

		s1 += "new string";
		cout << s1.c_str() << endl;

		s1 += s2;
		cout << s1.c_str() << endl;
	}
	void TestString5()
	{
		string s1("hello world");
		string s2("hello string");
		s1.resize(20);
		s1.reserve(15);
		s1.resize(5);
		s1.reserve(15);
		s1.resize(10);
	}
	void TestString6()
	{
		string s1("hello");
		//s1.insert(0, 'a');
		//cout << s1.c_str() << endl;

		s1.insert(0, "new");
		cout << s1.c_str() << endl;

		//s1.insert(s1.size(), s2);
		//cout << s1.c_str() << endl;

		//s1.erase(s1.begin());
		//cout << s1.c_str() << endl;

		//s1.erase(6, 5);
		//cout << s1.c_str() << endl;

		//s1.erase(s1.begin(), s1.end());
		//cout << s1.c_str() << endl;

	}
	void TestString7()
	{
		string s1("hellohello");
		cout << s1.find('e') << endl;

		cout << s1.find("he") << endl;

		cout << s1.rfind('d') << endl;

		cout << s1.rfind("3") << endl;

		cout << s1.substr(0, 21).c_str() << endl;

	}
	void TestString8()
	{
		string s1("hello world");
		string s2("hello string");
		//cout << (s1 < s2) << endl;
		//cout << (s1 <= s2) << endl;
		//cout << (s1 > s2) << endl;
		//cout << (s1 >= s2) << endl;
		//cout << (s1 == s2) << endl;
		//cout << (s1 != s2) << endl;

		string s;
		cin >> s;
		cout << s; 

	}

}
