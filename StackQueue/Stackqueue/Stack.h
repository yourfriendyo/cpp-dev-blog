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