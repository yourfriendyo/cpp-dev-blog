#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/***********************************************
* ˳���ṹ����
* 
***********************************************/

//#define NUM 1000
//typedef int SLDataType;//˳���Ԫ������
//
////��̬˳���
//typedef struct SeqList {
//	SLDataType data[NUM];//˳�������
//	int size;//Ԫ�ظ���
//	
//}SL;//˳���ṹ����



typedef int SLDataType;//˳���Ԫ������

//��̬˳���
typedef struct SeqList {
	SLDataType* data;//Ԫ������
	int size;//Ԫ�ظ���
	int capacity;//Ԫ��ʵ������
	
}SL;//˳���ṹ����



/***********************************************
* ˳�������ӿں���
*
***********************************************/
 
//˳����ʼ��
void SeqListInit(SL* ps);

//˳�������
void SeqListDestroy(SL* ps);

//˳���β��
void SeqListPushBack(SL* ps, SLDataType x);

//˳���βɾ
void SeqListPopBack(SL* ps);

//˳���ͷ��
void SeqListPushFront(SL* ps, SLDataType x);

//˳���ͷɾ
void SeqListPopFront(SL* ps);

//˳�������λ�ò���
void SeqListInsert(SL* ps, int pos, SLDataType x);

//˳�������λ��ɾ��
void SeqListErase(SL* ps, int pos);

//˳������
int SeqListFind(SL* ps, SLDataType x);

//˳����ӡ
void SeqListPrint(SL* ps);




