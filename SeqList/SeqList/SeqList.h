#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/***********************************************
* 顺序表结构定义
* 
***********************************************/

//#define NUM 1000
//typedef int SLDataType;//顺序表元素类型
//
////静态顺序表
//typedef struct SeqList {
//	SLDataType data[NUM];//顺序表数组
//	int size;//元素个数
//	
//}SL;//顺序表结构体名



typedef int SLDataType;//顺序表元素类型

//动态顺序表
typedef struct SeqList {
	SLDataType* data;//元素数组
	int size;//元素个数
	int capacity;//元素实际容量
	
}SL;//顺序表结构体名



/***********************************************
* 顺序表基本接口函数
*
***********************************************/
 
//顺序表初始化
void SeqListInit(SL* ps);

//顺序表销毁
void SeqListDestroy(SL* ps);

//顺序表尾插
void SeqListPushBack(SL* ps, SLDataType x);

//顺序表尾删
void SeqListPopBack(SL* ps);

//顺序表头插
void SeqListPushFront(SL* ps, SLDataType x);

//顺序表头删
void SeqListPopFront(SL* ps);

//顺序表任意位置插入
void SeqListInsert(SL* ps, int pos, SLDataType x);

//顺序表任意位置删除
void SeqListErase(SL* ps, int pos);

//顺序表查找
int SeqListFind(SL* ps, SLDataType x);

//顺序表打印
void SeqListPrint(SL* ps);




