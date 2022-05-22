#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"

//堆初始化
void HeapInit(heap* php) {
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}


//堆销毁
void HeapDestroy(heap* php) {
	assert(php);
	free(php->a);
	php->size = php->capacity = 0;
}

void Swap(HPDataType* px, HPDataType* py) {
	assert(px && py);
	HPDataType tmp = *px;
	*px = *py;
	*py = tmp;
}

//堆向上调整
void AdjustUp(HPDataType* a, int size, int child) {
	assert(a);
	while (child > 0) {
		int parent = (child - 1) / 2;
		//大堆
		if (a[child] > a[parent]) {
			Swap(&a[child], &a[parent]);
			//迭代
			child = parent;
		}
		else {
			break;
		}
	}
}

//堆的插入
void HeapPush(heap* php, HPDataType x) {
	assert(php);
	if (php->size == php->capacity) {
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newCapacity);
		if (tmp == NULL) {
			perror("HeapPush::malloc");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newCapacity;
	}
	php->a[php->size] = x;
	php->size++;
	//调整
	AdjustUp(php->a, php->size, php->size - 1);
}


//堆向下调整
void AdjustDown(HPDataType* a, int size, int parent) {
	int child = parent * 2 + 1;
	//小堆
	while (child < size) {
		//选出大小子结点
		if (child + 1 < size && a[child + 1] > a[child]) {
			child++;
		}
		//交换
		if (a[child] > a[parent]) {
			Swap(&a[child], &a[parent]);
			//迭代
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

//堆的删除（删除堆顶数据）
void HeapPop(heap* php) {
	assert(php);
	assert(!HeapEmpty(php));
	//删除
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	//调整
	AdjustDown(php->a, php->size, 0);
}


//获取堆顶数据
HPDataType HeapTop(heap* php) {
	assert(php);
	assert(!HeapEmpty(php));
	return php->a[0];
}


//堆的元素个数
int HeapSize(heap* php) {
	assert(php);
	return php->size;
}


//堆的判空 
bool HeapEmpty(heap* php) {
	assert(php);
	return !php->size;
}


//堆的打印
void HeapPrint(heap* php) {
	assert(php);
	for (int i = 0; i < php->size; i++) {
		printf("%d ", php->a[i]);
	}
	printf("\n");
}
