#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


/*****************************************************
* �ѵĽṹ�嶨��
*
*****************************************************/

typedef int HPDataType;

typedef struct heap {
	HPDataType* a;
	int size;
	int capacity;
}heap;

/*****************************************************
* �ӿں���ʵ��
* 
*****************************************************/

//�ѳ�ʼ��
void HeapInit(heap* php);

//������
void HeapDestroy(heap* php);

//�ѵĲ���
void HeapPush(heap* php, HPDataType x);

//����
void Swap(HPDataType* px, HPDataType* py);

//�ѵ�ɾ��
void HeapPop(heap* php);

//��ȡ�Ѷ�����
HPDataType HeapTop(heap* php);

//�ѵ�Ԫ�ظ���
int HeapSize(heap* php);

//�ѵ��п�
bool HeapEmpty(heap* php);

//�ѵĴ�ӡ
void HeapPrint(heap* php);

//�����ϵ���
void AdjustUp(HPDataType* a, int size, int child);

//�����µ���
void AdjustDown(HPDataType* a, int size, int child);






