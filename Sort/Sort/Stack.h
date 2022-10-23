#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


/******************************************************
* 栈结构体定义
*
*******************************************************/

typedef int STDataType;

typedef struct Stack {
	STDataType* a;
	int top;
	int capacity;
}ST;


/******************************************************
* 栈接口函数定义
*
*******************************************************/
#define FRISTSOLUTION 1



#ifdef FRISTSOLUTION // 第一种方案

	#ifdef __cplusplus 
	extern "C"
	{
	#endif

		//初始化栈
		void StackInit(ST* ps);
		//入栈
		void StackPush(ST* ps, STDataType data);
		//出栈
		void StackPop(ST* ps);
		//获取栈顶元素
		STDataType StackTop(ST* ps);
		//获取栈元素个数
		int StackSize(ST* ps);
		//检测空栈
		bool StackEmpty(ST* ps);
		//销毁栈
		void StackDestroy(ST* ps);

	#ifdef __cplusplus 
	}
	#endif



#else //第二种方案

	#ifdef __cplusplus
		#define EXTERN_C extern "C"
	#else 
		#define EXTERN_C
	#endif

	//初始化栈
	EXTERN_C void StackInit(ST* ps);
	//入栈
	EXTERN_C void StackPush(ST* ps, STDataType data);
	//出栈
	EXTERN_C void StackPop(ST* ps);
	//获取栈顶元素
	EXTERN_C STDataType StackTop(ST* ps);
	//获取栈元素个数
	EXTERN_C int StackSize(ST* ps);
	//检测空栈
	EXTERN_C bool StackEmpty(ST* ps);
	//销毁栈
	EXTERN_C void StackDestroy(ST* ps);


#endif
