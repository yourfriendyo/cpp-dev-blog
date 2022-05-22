#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//队列初始化
void QueueInit(Queue* pq) {
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}


//队列销毁
void QueueDestroy(Queue* pq) {
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur) {
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}


//队尾入队
void QueuePush(Queue* pq, QDataType x) {
	assert(pq);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL) {
		perror("Queue::malloc");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	//队列为空
	if (pq->head == NULL) {
		pq->head = pq->tail = newNode;
	}
	else {
		pq->tail->next = newNode;
		pq->tail = newNode;
	}
}


//队头出队
void QueuePop(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	//链表为空时尾指针置空
	if (pq->head == NULL) {
		pq->tail = NULL;
	}
}


//获取队头数据
QDataType QueueFront(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}


//获取队尾数据
QDataType QueueBack(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}


//获取队列元素个数
int QueueSize(Queue* pq) {
	assert(pq);
	int count = 0;
	QueueNode* cur = pq->head;
	while (cur) {
		count++;
		cur = cur->next;
	}
	return count;
}


//检测队列是否为空
bool QueueEmpty(Queue* pq) {
	assert(pq);
	return !pq->head;
}
