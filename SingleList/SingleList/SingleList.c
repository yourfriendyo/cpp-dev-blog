#define _CRT_SECURE_NO_WARNINGS 1
#include "SingleList.h"

//�����������
SLTNode* SListNewNode(SLTDataType x) {
	//�����½��
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newNode == NULL) {
		perror("newNode::malloc");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//�������ӡ
void SListPrint(SLTNode* phead) {
	SLTNode* cur = phead;
	while (cur != NULL) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


//������β��
void SListPushBack(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* newNode = SListNewNode(x);
	//�޽��
	if (*pphead == NULL) {
		*pphead = newNode;
	}
	//�н��
	else {
		//��β���
		SLTNode* tail = *pphead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//�޸�β���ָ����
		tail->next = newNode;
	}
}


//������βɾ
void SListPopBack(SLTNode** pphead) {
	//�����п�
	assert(*pphead);
	//������Ϊ1
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else {
		//��β���
		SLTNode* tail = *pphead;
		//1.
		////ǰ��ָ�� 
		SLTNode* prev = NULL;
		//while (tail->next != NULL) {
		//	prev = tail;
		//	tail = tail->next;
		//}
		////�ͷ�β���
		//free(tail);
		//tail = NULL;
		////�ÿ�ǰ�����ָ����
		//prev->next = NULL;
		
		//2.
		while (prev->next->next) {
			prev = prev->next;
		}
		free(prev->next);
		prev->next = NULL;
	}
}


//������ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x) {
	aasert(pphead);
	SLTNode* newNode = SListNewNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}


//������ͷɾ
void SListPopFront(SLTNode** pphead) {
	//0�����
	assert(*pphead);
	//1���������Ͻ��
	SLTNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
	//*pphead = (*pphead)->next//Err

}
 

//���������
SLTNode* SListFind(SLTNode* phead, SLTDataType x) {
	assert(phead);
	while (phead != NULL) {
		//�ж�
		if (phead->data == x) {
			return phead;
		}
		phead = phead->next;
	}
	//�޸�Ԫ��
	return NULL;
}


//���������ǰ��
void SListInsertForward(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(pphead && pos);
	SLTNode* newNode = SListNewNode(x);
	//ͷ��ʱ
	if (pos == *pphead) {
		newNode->next = *pphead;
		*pphead = newNode;
	}
	else {
		//��ǰ�����
		SLTNode* prev = *pphead;
		while (prev->next != pos) {
			prev = prev->next;
		}
		prev->next = newNode;
		newNode->next = pos;
	}
}


//������������
void SListInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* newNode = SListNewNode(x);
	//0�����ʱ
	if (pos == NULL) {
		pos = newNode;
	}
	//
	else {
		newNode->next = pos->next;
		pos->next = newNode;
	}
}


//���������ɾ����ɾ��pos��㣩
void SListErase(SLTNode** pphead, SLTNode* pos) {
	//����Ϊ��
	assert(pos);
	//if (pos->next == NULL) {
	//}
	//���ж�1����������������жϲ����׽������
	//�׽��ʱ
	if (*pphead == pos) {
		*pphead = pos->next;
		free(pos);
	}
	else {
		SLTNode* prev = *pphead;
		while (prev->next != pos) {
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}

	//ɾ��pos��㣬��Ҫ�ı��ϸ���㣬��Ҫ������ǰ��
	//ֻҪ����һ����㣬��Ҫ���ǽ����Ϊ1�������
}


//�����������ɾ��ɾ��pos����һ����㣩
void SListEraseAfter(SLTNode* pos) {
	//1����㣨pos���޽�㣩
	assert(pos->next);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
}


//�������ͷ�
void SListDestroy(SLTNode** pphead) {
	assert(*pphead);
	SLTNode* cur = *pphead;
	while (cur) {
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

