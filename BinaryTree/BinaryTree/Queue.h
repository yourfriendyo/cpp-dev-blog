#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//#include "BinaryTree.h"

/*********************************************************
* ���м����н��ṹ�嶨��
* 
*********************************************************/
struct BinaryTreeNode;

typedef struct BinaryTreeNode* QDataType;

typedef struct QueueNode {
	QDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue {
	struct QueueNode* head;
	struct QueueNode* tail;
}Queue;


/*******************************************************
* ���к�������
* 
********************************************************/

//���г�ʼ��
void QueueInit(Queue* pq);

//��������
void QueueDestroy(Queue* pq);

//�������
void QueuePush(Queue* pq, QDataType x);

//���г���
void QueuePop(Queue* pq);

//��ȡ��ͷ����
QDataType QueueFront(Queue* pq);

//��ȡ��β����
QDataType QueueBack(Queue* pq);

//��ȡ����Ԫ�ظ���
int QueueSize(Queue* pq);

//�������Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

