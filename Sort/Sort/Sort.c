#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"

//升序

void PrintArray(int* a, int n) {
	assert(a);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}


void Swap(int* px, int* py) {
	assert(px && py);
	int tmp = *px;
	*px = *py;
	*py = tmp;
}


/*****************************************************
* 直接插入排序
*
*****************************************************/
void InsertSort(int* a, int n) {
	assert(a);
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int x = a[end + 1];
		while (end >= 0) {
			if (a[end] > x) {
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = x;
	}
}


/*******************************************************
* 希尔排序
*
*******************************************************/
void ShellSort(int* a, int n) {
	assert(a);
	int gap = n;
	while (gap > 1) {
		gap /= 2;
		//排gap组
		for (int j = 0; j < gap; j++) {
			//多趟排序
			for (int i = j; i < n - gap; i += gap) {
				int end = i;
				int x = a[end + gap];
				//单趟排序
				while (end >= 0) {
					if (a[end] > x) {
						a[end + gap] = a[end];
						end -= gap;
					}
					else {
						break;
					}
				}
				a[end + gap] = x;
			}
		}
	}
}

//简化
void ShellSort1(int* a, int n) {
	assert(a);
	int gap = n;
	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int x = a[end + gap];
			while (end >= 0) {
				if (a[end] > x) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = x;
		}
	}
}


/*******************************************************
* 直接选择排序
*
*******************************************************/
void SelectSort(int* a, int n) {
	assert(a);
	int begin = 0, end = n - 1;
	while (begin < end) {
		int mini = begin, maxi = begin;
		for (int i = begin; i <= end; i++) {
			if (a[i] < a[mini]) {
				mini = i;
			}
			if (a[i] > a[maxi]) {
				maxi = i;
			}
		}
		//交换
		Swap(&a[mini], &a[begin]);
		//修正
		if (maxi == begin) {
			maxi = mini;
		}
		Swap(&a[maxi], &a[end]);
		++begin;
		--end;
	}
}

void SelectSort1(int* a, int n) {
	assert(a);
	while (n) {
		int maxi = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > a[maxi]) {
				maxi = i;
			}
		}
		Swap(&a[maxi], &a[n - 1]);
		n--;
	}
}

void SelectSort2(int* a, int n) {
	assert(a);
	int sz = n;
	while (sz > n / 2) {
		int maxi = n - sz;
		int mini = n - sz;
		//找最值
		for (int i = n - sz; i < sz; i++) {
			if (a[i] < a[mini]) {
				mini = i;
			}
			if (a[i] > a[maxi]) {
				maxi = i;
			}
		}
		//交换
		Swap(&a[maxi], &a[sz - 1]);
		//修正
		if (mini == sz - 1) {
			mini = maxi;
		}
		Swap(&a[mini], &a[n - sz]);

		sz--;
	}
}


/*******************************************************
* 堆排序
*
*******************************************************/
void AdjustDown(int* a, int n, int parent) {
	assert(a);
	int child = parent * 2 + 1;
	while (child < n) {
		if (child + 1 < n && a[child + 1] > a[child]) {
			child++;
		}
		if (a[child] > a[parent]) {
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

void HeapSort(int* a, int n) {
	assert(a);
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(a, n, i);
	}
	//堆排序
	int end = n - 1;
	while (end) {
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}


/*******************************************************
* 冒泡排序
*
*******************************************************/
void BubbleSort(int* a, int n) {
	assert(a);
	//1. 
	for (int i = 0; i < n - 1; i++) {
		bool exchange = true;
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				exchange = false;
				Swap(&a[j], &a[j + 1]);
			}
		}
		if (exchange) {
			break;
		}
	}

	//2. 
	int end = n - 1;
	while (end > 0) {
		for (int j = 0; j < end; j++) {
			if (a[j] > a[j + 1]) {
				Swap(&a[j], &a[j + 1]);
			}
		}
		--end;
	}
}


/*******************************************************
* 快速排序
*
*******************************************************/

//三数取中
int GetMidIndex(int* a, int left, int right) {
	assert(a);
	int midi = left + ((right - left) >> 1);
	//取中逻辑
	//取得left right midi 三者下标所在元素的中间值，并返回其下标
	if (a[left] < a[right]) {
		if (a[midi] < a[left]) {
			return left;
		}
		else if (a[midi] < a[right]) {
			return midi;
		}
		else {
			return right;
		}
	}
	else {
		if (a[midi] > a[left]) {//mid > left > right
			return left;
		}
		else if (a[midi] > a[right]) {//left > mid > right
			return midi;
		}
		else {//left > right > mid
			return right;
		}
	}
}

//1. hoare版本
int Partition1(int* a, int left, int right) {
	assert(a);
	//三数取中
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);
	//...
	int keyi = left;
	while (left < right) {
		//左边为key，先走右
		//右找小
		while (left < right && a[right] >= a[keyi]) {
			--right;
		}
		//左找大
		while (left < right && a[left] <= a[keyi]) {
			++left;
		}
		//左右交换
		Swap(&a[left], &a[right]);
	}
	//交换key
	Swap(&a[keyi], &a[left]);
	return left;
}

//2. 挖坑法
int Partition2(int* a, int left, int right) {
	assert(a);
	//三数取中
	int midi = GetMidIndex(a, left, right);
	//Swap(&a[midi], &a[left]);
	//定义key保存最左边的值
	int key = a[left];
	//定义第一个坑位
	int pivot = left;
	while (left < right) {
		while (left < right && a[right] >= key) {
			--right;
		}
		//右下标的值放到左边的坑位中
		a[pivot] = a[right];
		pivot = right;
		//左下标的值放到右边的坑位中
		while (left < right && a[left] <= key) {
			++left;
		}
		a[pivot] = a[left];
		pivot = left;
	}
	a[pivot] = key;
	return pivot;
}

//3. 前后指针法
int Partition3(int* a, int left, int right) {
	assert(a);
	//三数取中
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);
	//左边作key
	{
		int keyi = left;
		int prev = left;
		int cur = prev + 1;
		//cur找小
		while (cur <= right) {
			if (a[cur] < a[keyi]) {
				prev++;
				Swap(&a[cur], &a[prev]);
			}
			cur++;
		}
		Swap(&a[keyi], &a[prev]);
		return prev;
	}
	//右边作key
	{
		int keyi = right;
		int cur = left;
		int prev = cur - 1;
		while (cur < right) {
			if (a[cur] < a[keyi] && ++prev != cur) {//cur找小
				Swap(&a[cur], &a[prev]);
			}
			cur++;
		}
		//prev++
		Swap(&a[++prev], &a[cur]);
		return prev;
	}
}

//递归版本
void QuickSort(int* a, int left, int right) {
	assert(a);
	//临界条件
	if (left >= right) {
		return;
	}
	//小区间优化
	if (right - left < 10) {
		//调用插入排序
		//InsertSort(a + left, right - left + 1);
	}
	//
	int keyi = Partition2(a, left, right);
	//[left, keyi-1] keyi [keyi+1, right]
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}

//非递归版本
void QuickSortNonR(int* a, int left, int right) {
	assert(a);
	ST st;//建立栈
	StackInit(&st);
	//
	StackPush(&st, left);
	StackPush(&st, right);
	//
	while (!StackEmpty(&st)) {
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);
		//
		int keyi = Partition1(a, begin, end);
		//[left,keyi-1] keyi [keyi+1,right]
		//
		if (end - keyi > 1) {
			StackPush(&st, keyi + 1);
			StackPush(&st, end);
		}
		if (keyi - begin > 1) {
			StackPush(&st, begin);
			StackPush(&st, keyi - 1);
		}
	}
	StackDestroy(&st);
}


/*******************************************************
* 归并排序
*
*******************************************************/




/*******************************************************
* 计数排序
*
*******************************************************/