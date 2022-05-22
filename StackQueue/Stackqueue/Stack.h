#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


/******************************************************
* ջ�ṹ�嶨��
* 
*******************************************************/

typedef int STDataType;

typedef struct Stack {
	STDataType* a;
	int top;
	int capacity;
}ST;


/******************************************************
* ջ�ӿں�������
*
*******************************************************/

//��ʼ��ջ
void StackInit(ST* ps);

//��ջ
void StackPush(ST* ps, STDataType data);

//��ջ
void StackPop(ST* ps);

//��ȡջ��Ԫ��
STDataType StackTop(ST* ps);

//��ȡջԪ�ظ���
int StackSize(ST* ps);

//����ջ
bool StackEmpty(ST* ps);

//����ջ
void StackDestroy(ST* ps);