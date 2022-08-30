#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <stdlib.h>
#include <assert.h>

/***********************************************
* ������ṹ�嶨�� 
* 
***********************************************/

typedef int SLTDataType;

typedef struct SListNode {
	//������
	SLTDataType data;
	//ָ����
	struct SListNode* next;
}SLTNode;

/***********************************************
* ������ӿں���
* 
***********************************************/

//��̬������
SLTNode* SListNewNode(SLTDataType x);

//�������ӡ
void SListPrint(SLTNode* phead);

//������β��
void SListPushBack(SLTNode*& phead, SLTDataType x);

//������βɾ
void SListPopBack(SLTNode*& phead);

//������ͷ��
void SListPushFront(SLTNode*& phead, SLTDataType x);

//������ͷɾ
void SListPopFront(SLTNode*& phead);

//���������
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//���������ǰ��
void SListInsertForward(SLTNode*& phead, SLTNode* pos, SLTDataType x);

//������������
void SListInsertAfter(SLTNode* pos, SLTDataType x);

//���������ɾ��
void SListErase(SLTNode*& phead, SLTNode* pos);

//�����������ɾ
void SListEraseAfter(SLTNode* pos);

//����������
void SListDestroy(SLTNode*& phead);