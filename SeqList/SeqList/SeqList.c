#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"


//顺序表初始化
void SeqListInit(SL* ps) {
	ps->data = NULL;
	ps->size = 0;
	ps->capacity = 0;
}


//顺序表销毁
void SeqListDestroy(SL* ps) {
	free(ps->data);
	ps->data = NULL;
	ps->size = 0;
	ps->capacity = 0;
}


//检查容量
void CheckCapacity(SL* ps) {
	if (ps->size == ps->capacity) {
		//扩容
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* ptr = (SLDataType*)realloc(ps->data, newcapacity * sizeof(SLDataType));
		if (ptr == NULL) {
			perror("mallocfail");
			exit(-1);
		}
		ps->data = ptr;
		ps->capacity = newcapacity;
		printf("增容成功\n");
	}
}


//顺序表尾插
void SeqListPushBack(SL* ps, SLDataType x) {
	CheckCapacity(ps);
	ps->data[ps->size] = x;
	ps->size++;
	printf("尾插成功\n");
}


//顺序表尾删
void SeqListPopBack(SL* ps) {
	//有效个数为0
	if (ps->size == 0) {
		printf("尾删失败\n");
		return;

	}
	ps->size--;
	printf("尾删成功\n");

}


//顺序表打印
void SeqListPrint(SL* ps) {
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}


//顺序表头插
void SeqListPushFront(SL* ps, SLDataType x) {
	//检查容量
	CheckCapacity(ps);
	//1.
	int end = ps->size - 1;
	while (end >= 0) {
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	ps->data[0] = x;
	ps->size++;
	printf("头插成功\n");
	//2. 

}

//顺序表头删
void SeqListPopFront(SL* ps) {
	//有效个数为0
	if (ps->size == 0) {
		printf("头删失败\n");
		return;
	}
	int begin = 1;
	//从第二个到第size-1个
	while (begin < ps->size) {	
		ps->data[begin - 1] = ps->data[begin];
		begin++;
	}
	ps->size--;
	printf("头删成功\n");
}


//顺序表任意位置插入
void SeqListInsert(SL* ps, int pos, SLDataType x) {
	assert(pos >= 0 && pos <= ps->size);
	
	CheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos) {
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	ps->data[pos] = x;
	ps->size++;
	printf("pos插入成功\n");
}


//顺序表任意位置删除
void SeqListErase(SL* ps, int pos) {
	assert(pos >= 0 && pos < ps->size);
	if (ps->size == 0) {
		printf("pos删除失败\n");
		return;
	}
	int begin = pos + 1;
	while (begin < ps->size) {
		ps->data[begin - 1] = ps->data[begin];
		begin++;
	}
	ps->size--;
	printf("pos删除成功\n");
}


//顺序表查找
int SeqListFind(SL* ps, SLDataType x) {
	for (int i = 0; i < ps->size; i++) {
		if (ps->data[i] == x) {
			return i;
		}
	}
	return -1;
}