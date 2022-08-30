#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
//
//struct ListNode {
//	ListNode* prev;
//	ListNode* next;
//	int _val;
//	ListNode(int val = 0)
//		: prev(nullptr)
//		, next(nullptr)
//		, _val(val)
//	{}
//};

class Stack {
public:
	Stack(int capacity = 4)
		: _capacity(capacity)
		, _top(0)
	{
		_a = new int[_capacity];
		//不需要判空
	}
	~Stack() {
		delete[] _a;
		_capacity = _top = 0;
	}

private:
	int* _a;
	int _top;
	int _capacity;
};

//int main()
//{
//	//c
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	n1->prev = NULL;
//	n1->next = NULL;
//	n1->_val = 0;
//	
//	//c++
//	ListNode* n2 = new ListNode;
//	ListNode* n3 = new ListNode(1);
//
//	//动态开辟，主动控制生命周期
//	Stack* pst1 = new Stack(8); //开辟空间，调用构造函数
//
//	Stack* pst2 = (Stack*)operator new(sizeof(Stack));
//	//operator new 只能开辟空间和抛异常
//
//	delete pst1; //调用析构函数，释放空间
//
//
//	operator delete(pst2);
//	
//	//operator new(1);
//
//	return 0;
//}


//int main()
//{
//	char* p1 = (char*)malloc(1024u * 1024u * 1024u * 2u - 1);
//	if (p1 == NULL) {
//		perror("Malloc");
//	}
//
//	try {
//		char* p2 = (char*)operator new(1024u * 1024u * 1024u * 2u - 1);
//	}
//	catch (exception& e) {
//		cout << e.what() << endl;
//	}
//	
//	return 0;
//}
//


///*
//	operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；申请空间失败，
//	尝试执行空间不足应对措施，如果改应对措施用户设置了，则继续申请，否则抛异常。
//*/
//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)
//		if (_callnewh(size) == 0)
//		{
//			// report no memory
//			// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}
///*
//	operator delete: 该函数最终是通过free来释放空间的
//*/
//void operator delete(void* pUserData)
//{
//	_CrtMemBlockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//	if (pUserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK); /* block other threads */
//	__TRY
//		/* get a pointer to memory block header */
//		pHead = pHdr(pUserData);
//	/* verify block type */
//	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//	_free_dbg(pUserData, pHead->nBlockUse);
//	__FINALLY
//		_munlock(_HEAP_LOCK); /* release other threads */
//	__END_TRY_FINALLY
//		return;
//}
///*
//	free的实现
//*/
//#define free(p)    _free_dbg(p, _NORMAL_BLOCK)


//int main()
//{
//	Stack* pst = new Stack[3] { 1,2,3 };
//
//	//Stack* pst = (Stack*)operator new[](sizeof(Stack) * 3);
//
//	delete[] pst;
//
//	return 0;
//}



//class ListNode {
//public:
//	ListNode(int val = 0)
//		: _prev(nullptr)
//		, _next(nullptr)
//		, _val(val)
//	{}
//
//	friend class List;
//	void* operator new(size_t size) {
//		void* p = nullptr;
//		p = allocator<ListNode>().allocate(1);
//		cout << "memory pool allocate" << endl;
//		return p;
//	}
//	void operator delete(void* p) {
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//	}
//private:
//	ListNode* _prev;
//	ListNode* _next;
//	int _val;
//};
//
//class List {
//public:
//	List() {
//		_head = new ListNode(0xfeeefeee);
//		_head->_prev = _head;
//		_head->_next = _head;
//	}
//	~List() {
//		ListNode* cur = _head->_next;
//		while (cur != _head) {
//			ListNode* next = cur->_next;
//			delete cur;
//			cur = next;
//		}
//		delete _head;
//		_head = nullptr;
//	}
//	void PushBack(int val = 0) {
//		ListNode* newNode = new ListNode(val);
//		ListNode* tail = _head->_prev;
//		//
//		tail->_next = newNode;
//		newNode->_prev = tail;
//		newNode->_next = _head;
//		_head->_prev = newNode;
//	}
//private:
//	ListNode* _head;
//};
//
//int main()
//{
//	List* pl = new List;
//
//	pl->PushBack(1);
//	pl->PushBack(2);
//	pl->PushBack(3);
//	pl->PushBack(4);
//	pl->PushBack(5);
//
//	return 0;
//}