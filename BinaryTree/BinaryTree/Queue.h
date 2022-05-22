#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//#include "BinaryTree.h"

/*********************************************************
* 队列及队列结点结构体定义
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
* 队列函数定义
* 
********************************************************/

//队列初始化
void QueueInit(Queue* pq);

//队列销毁
void QueueDestroy(Queue* pq);

//队列入队
void QueuePush(Queue* pq, QDataType x);

//队列出队
void QueuePop(Queue* pq);

//获取队头数据
QDataType QueueFront(Queue* pq);

//获取队尾数据
QDataType QueueBack(Queue* pq);

//获取队列元素个数
int QueueSize(Queue* pq);

//检测队列是否为空
bool QueueEmpty(Queue* pq);

