#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"


//˳����ʼ��
void SeqListInit(SL* ps) {
	ps->data = NULL;
	ps->size = 0;
	ps->capacity = 0;
}


//˳�������
void SeqListDestroy(SL* ps) {
	free(ps->data);
	ps->data = NULL;
	ps->size = 0;
	ps->capacity = 0;
}


//�������
void CheckCapacity(SL* ps) {
	if (ps->size == ps->capacity) {
		//����
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* ptr = (SLDataType*)realloc(ps->data, newcapacity * sizeof(SLDataType));
		if (ptr == NULL) {
			perror("mallocfail");
			exit(-1);
		}
		ps->data = ptr;
		ps->capacity = newcapacity;
		printf("���ݳɹ�\n");
	}
}


//˳���β��
void SeqListPushBack(SL* ps, SLDataType x) {
	CheckCapacity(ps);
	ps->data[ps->size] = x;
	ps->size++;
	printf("β��ɹ�\n");
}


//˳���βɾ
void SeqListPopBack(SL* ps) {
	//��Ч����Ϊ0
	if (ps->size == 0) {
		printf("βɾʧ��\n");
		return;

	}
	ps->size--;
	printf("βɾ�ɹ�\n");

}


//˳����ӡ
void SeqListPrint(SL* ps) {
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}


//˳���ͷ��
void SeqListPushFront(SL* ps, SLDataType x) {
	//�������
	CheckCapacity(ps);
	//1.
	int end = ps->size - 1;
	while (end >= 0) {
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	ps->data[0] = x;
	ps->size++;
	printf("ͷ��ɹ�\n");
	//2. 

}

//˳���ͷɾ
void SeqListPopFront(SL* ps) {
	//��Ч����Ϊ0
	if (ps->size == 0) {
		printf("ͷɾʧ��\n");
		return;
	}
	int begin = 1;
	//�ӵڶ�������size-1��
	while (begin < ps->size) {	
		ps->data[begin - 1] = ps->data[begin];
		begin++;
	}
	ps->size--;
	printf("ͷɾ�ɹ�\n");
}


//˳�������λ�ò���
void SeqListInsert(SL* ps, int pos, SLDataType x) {
	assert(pos >= 0 && pos <= ps->size);
	
	CheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos) {
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	ps->data[pos] = x;
	ps->size++;
	printf("pos����ɹ�\n");
}


//˳�������λ��ɾ��
void SeqListErase(SL* ps, int pos) {
	assert(pos >= 0 && pos < ps->size);
	if (ps->size == 0) {
		printf("posɾ��ʧ��\n");
		return;
	}
	int begin = pos + 1;
	while (begin < ps->size) {
		ps->data[begin - 1] = ps->data[begin];
		begin++;
	}
	ps->size--;
	printf("posɾ���ɹ�\n");
}


//˳������
int SeqListFind(SL* ps, SLDataType x) {
	for (int i = 0; i < ps->size; i++) {
		if (ps->data[i] == x) {
			return i;
		}
	}
	return -1;
}