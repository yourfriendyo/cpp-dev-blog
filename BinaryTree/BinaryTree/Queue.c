#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//���г�ʼ��
void QueueInit(Queue* pq) {
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}


//��������
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


//��β���
void QueuePush(Queue* pq, QDataType x) {
	assert(pq);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL) {
		perror("Queue::malloc");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	//����Ϊ��
	if (pq->head == NULL) {
		pq->head = pq->tail = newNode;
	}
	else {
		pq->tail->next = newNode;
		pq->tail = newNode;
	}
}


//��ͷ����
void QueuePop(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	//����Ϊ��ʱβָ���ÿ�
	if (pq->head == NULL) {
		pq->tail = NULL;
	}
}


//��ȡ��ͷ����
QDataType QueueFront(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}


//��ȡ��β����
QDataType QueueBack(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}


//��ȡ����Ԫ�ظ���
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


//�������Ƿ�Ϊ��
bool QueueEmpty(Queue* pq) {
	assert(pq);
	return !pq->head;
}
