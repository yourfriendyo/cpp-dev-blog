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
#define FRISTSOLUTION 1



#ifdef FRISTSOLUTION // ��һ�ַ���

	#ifdef __cplusplus 
	extern "C"
	{
	#endif

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

	#ifdef __cplusplus 
	}
	#endif



#else //�ڶ��ַ���

	#ifdef __cplusplus
		#define EXTERN_C extern "C"
	#else 
		#define EXTERN_C
	#endif

	//��ʼ��ջ
	EXTERN_C void StackInit(ST* ps);
	//��ջ
	EXTERN_C void StackPush(ST* ps, STDataType data);
	//��ջ
	EXTERN_C void StackPop(ST* ps);
	//��ȡջ��Ԫ��
	EXTERN_C STDataType StackTop(ST* ps);
	//��ȡջԪ�ظ���
	EXTERN_C int StackSize(ST* ps);
	//����ջ
	EXTERN_C bool StackEmpty(ST* ps);
	//����ջ
	EXTERN_C void StackDestroy(ST* ps);


#endif
