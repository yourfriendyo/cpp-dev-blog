#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
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
void SListPushBack(SLTNode** phead, SLTDataType x);

//������βɾ
void SListPopBack(SLTNode** pphead);

//������ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x);

//������ͷɾ
void SListPopFront(SLTNode** pphead);

//���������
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//���������ǰ��
void SListInsertForward(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//������������
void SListInsertAfter(SLTNode* pos, SLTDataType x);

//���������ɾ��
void SListErase(SLTNode** pphead, SLTNode* pos);

//�����������ɾ
void SListEraseAfter(SLTNode* pos);

//����������
void SListDestroy(SLTNode** plist);