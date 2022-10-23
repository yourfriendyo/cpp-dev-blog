#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"

//�ѳ�ʼ��
void HeapInit(heap* php) {
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}


//������
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

//�����ϵ���
void AdjustUp(HPDataType* a, int size, int child) {
	assert(a);
	while (child > 0) {
		int parent = (child - 1) / 2;
		//���
		if (a[child] > a[parent]) {
			Swap(&a[child], &a[parent]);
			//����
			child = parent;
		}
		else {
			break;
		}
	}
}

//�ѵĲ���
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
	//����
	AdjustUp(php->a, php->size, php->size - 1);
}


//�����µ���
void AdjustDown(HPDataType* a, int size, int parent) {
	int child = parent * 2 + 1;
	//С��
	while (child < size) {
		//ѡ����С�ӽ��
		if (child + 1 < size && a[child + 1] > a[child]) {
			child++;
		}
		//����
		if (a[child] > a[parent]) {
			Swap(&a[child], &a[parent]);
			//����
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

//�ѵ�ɾ����ɾ���Ѷ����ݣ�
void HeapPop(heap* php) {
	assert(php);
	assert(!HeapEmpty(php));
	//ɾ��
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	//����
	AdjustDown(php->a, php->size, 0);
}


//��ȡ�Ѷ�����
HPDataType HeapTop(heap* php) {
	assert(php);
	assert(!HeapEmpty(php));
	return php->a[0];
}


//�ѵ�Ԫ�ظ���
int HeapSize(heap* php) {
	assert(php);
	return php->size;
}


//�ѵ��п� 
bool HeapEmpty(heap* php) {
	assert(php);
	return !php->size;
}


//�ѵĴ�ӡ
void HeapPrint(heap* php) {
	assert(php);
	for (int i = 0; i < php->size; i++) {
		printf("%d ", php->a[i]);
	}
	printf("\n");
}
