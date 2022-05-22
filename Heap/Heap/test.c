#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"


/**************************************************
* HeapTest
*
**************************************************/

//    1
//  2   3
// 4 5 6  7
void HeapTest1() {
	heap hp;
	HeapInit(&hp);

	HeapPush(&hp, 1);
	HeapPush(&hp, 2);
	HeapPush(&hp, 3);
	HeapPush(&hp, 4);
	HeapPush(&hp, 5);
	HeapPush(&hp, 6);
	//HeapPush(&hp, 0);
	HeapPush(&hp, 7);

	//HeapPrint(&hp);
	while (!HeapEmpty(&hp)) {
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}


	HeapDestroy(&hp);
}

void HeapTest2() {
	heap hp;
	HeapInit(&hp);
	HeapPush(&hp, 1);
	HeapPush(&hp, 2);
	HeapPush(&hp, 3);
	HeapPush(&hp, 4);
	HeapPush(&hp, 5);
	HeapPush(&hp, 6);

	while (!HeapEmpty(&hp)) {
		HeapPrint(&hp);
		HeapPop(&hp);
	}	

	HeapDestroy(&hp);
}


/**************************************************
* Top-K
* 
**************************************************/

void PrintTopK(int* a, int n, int k) {
	heap hp;
	HeapInit(&hp);
	//创建小堆
	for (int i = 0; i < k; i++) {
		HeapPush(&hp, a[i]);
	}
	//比较
 	for (int i = k; i < n; i++) {
		int ret = HeapTop(&hp);
		if (a[i] > ret) {
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	HeapPrint(&hp);
}

void HeapTopk() {
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	assert(a);
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 10000;
	}
	a[5] = 10000 + 1;
	a[143] = 10000 + 2;
	a[888] = 10000 + 4; 
	a[4343] = 10000 + 3;
	a[5413] = 10000 + 5;
	PrintTopK(a, n, 5);

}


/**************************************************
* HeapSort
*
**************************************************/

//排升序
void HeapSort(int* a, int sz) {
	//建小堆
	//for (int i = 1; i < sz; i++) {
	//	  AdjustUp(a, sz, i);
	//}
	//
	//for (int i = (sz - 1 - 1) / 2; i >= 0; i--) {
	//	//向下调整
	//	AdjustDown(a, sz, i);
	//	//
	//}
	//
	//for (int i = 0; i < sz; i++) {
	//	printf("%d ", a[i]);
	//}
	//printf("\n");
	
	//建堆
	for (int i = (sz - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(a, sz, i);
	}
	//排序
	for (int i = sz - 1; i >= 0; i--) {//元素个数-1
		//首位互换
		Swap(&a[0], &a[i]);
		//向下调整
		AdjustDown(a, i, 0);
	}


	for (int i = 0; i < sz; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	//1.
	//HeapTest1();
	//HeapTest2();
	
	//2.
	//HeapTopk();

	//3.
	int arr[] = { 70,56,30,25,15,10,75,33,49,81 };
	
	HeapSort(arr, sizeof(arr)/sizeof(arr[0]));
	
	//HeapSort();

	return 0;
}
