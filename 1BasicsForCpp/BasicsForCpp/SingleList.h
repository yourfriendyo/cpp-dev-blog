#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <stdlib.h>
#include <assert.h>

/***********************************************
* 单链表结构体定义 
* 
***********************************************/

typedef int SLTDataType;

typedef struct SListNode {
	//数据域
	SLTDataType data;
	//指针域
	struct SListNode* next;
}SLTNode;

/***********************************************
* 单链表接口函数
* 
***********************************************/

//动态申请结点
SLTNode* SListNewNode(SLTDataType x);

//单链表打印
void SListPrint(SLTNode* phead);

//单链表尾插
void SListPushBack(SLTNode*& phead, SLTDataType x);

//单链表尾删
void SListPopBack(SLTNode*& phead);

//单链表头插
void SListPushFront(SLTNode*& phead, SLTDataType x);

//单链表头删
void SListPopFront(SLTNode*& phead);

//单链表查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//单链表随机前插
void SListInsertForward(SLTNode*& phead, SLTNode* pos, SLTDataType x);

//单链表随机后插
void SListInsertAfter(SLTNode* pos, SLTDataType x);

//单链表随机删除
void SListErase(SLTNode*& phead, SLTNode* pos);

//单链表随机后删
void SListEraseAfter(SLTNode* pos);

//单链表销毁
void SListDestroy(SLTNode*& phead);