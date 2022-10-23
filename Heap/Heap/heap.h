#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


/*****************************************************
* 堆的结构体定义
*
*****************************************************/

typedef int HPDataType;

typedef struct heap {
	HPDataType* a;
	int size;
	int capacity;
}heap;

/*****************************************************
* 接口函数实现
* 
*****************************************************/

//堆初始化
void HeapInit(heap* php);

//堆销毁
void HeapDestroy(heap* php);

//堆的插入
void HeapPush(heap* php, HPDataType x);

//交换
void Swap(HPDataType* px, HPDataType* py);

//堆的删除
void HeapPop(heap* php);

//获取堆顶数据
HPDataType HeapTop(heap* php);

//堆的元素个数
int HeapSize(heap* php);

//堆的判空
bool HeapEmpty(heap* php);

//堆的打印
void HeapPrint(heap* php);

//堆向上调整
void AdjustUp(HPDataType* a, int size, int child);

//堆向下调整
void AdjustDown(HPDataType* a, int size, int child);






