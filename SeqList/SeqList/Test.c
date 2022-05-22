#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//void SeqListTest1() {
//	
//	SL sl;
//
//	SeqListInit(&sl);
//
//	SeqListPushBack(&sl, 1);
//	SeqListPushBack(&sl, 2);
//	SeqListPushBack(&sl, 3);
//	SeqListPushBack(&sl, 4);
//	SeqListPushBack(&sl, 5);
//	SeqListPushBack(&sl, 6);
//	SeqListPushBack(&sl, 7);
//	SeqListPushBack(&sl, 8);
//	SeqListPushBack(&sl, 9);
//
//	SeqListPrint(&sl);
//	
//	SeqListPopBack(&sl);//9
//	SeqListPrint(&sl);
//	SeqListPopBack(&sl);//8
//	SeqListPrint(&sl);
//	SeqListPopBack(&sl);//7
//	SeqListPrint(&sl);
//	SeqListPopBack(&sl);//6
//	SeqListPrint(&sl);
//	SeqListPopBack(&sl);//5
//	SeqListPrint(&sl);
//	SeqListPopBack(&sl);//4
//	SeqListPrint(&sl);
//	SeqListPopBack(&sl);//3
//	SeqListPrint(&sl);
//	SeqListPopBack(&sl);//2
//	SeqListPrint(&sl);
//	SeqListPopBack(&sl);//1
//	SeqListPrint(&sl);
//	SeqListPopBack(&sl);
//	SeqListPrint(&sl);
//
//	SeqListPrint(&sl);
//
//
//	SeqListDestroy(&sl);
//}
//
//void SeqListTest2() {
//	
//	SL sl;
//
//	SeqListInit(&sl);
//
//	SeqListPushBack(&sl, 1);
//	SeqListPushBack(&sl, 2);
//	SeqListPushBack(&sl, 3);
//
//	SeqListPrint(&sl);
//	
//	SeqListPushFront(&sl,  0);
//	SeqListPushFront(&sl, -1);
//	SeqListPushFront(&sl, -2);
//
//	SeqListPrint(&sl);
//
//	SeqListPopFront(&sl);
//	SeqListPopFront(&sl);
//
//	SeqListPrint(&sl);
//
//	SeqListDestroy(&sl);
//
//}
//
//void SeqListTest3(){
//	
//	SL sl;
//	SeqListInit(&sl);
//
//	SeqListPushBack(&sl, 1);
//	SeqListPushBack(&sl, 2);
//	SeqListPushBack(&sl, 3);
//	SeqListPushBack(&sl, 4);
//	SeqListPushBack(&sl, 5);
//	
//	SeqListPrint(&sl);
//
//	SeqListInsert(&sl, 1, 11);
//	SeqListInsert(&sl, 0, 00);
//	SeqListInsert(&sl, 7, 77);
//	
//	SeqListPrint(&sl);
//
//	SeqListErase(&sl, 0);
//	SeqListErase(&sl, 1);
//	SeqListErase(&sl, 5);
//
//	SeqListPrint(&sl);
//
//	SeqListDestroy(&sl);
//
//}
//
//void SeqListTest4() {
//	SL sl;
//	SeqListInit(&sl);
//
//	SeqListPushBack(&sl, 1);
//	SeqListPushBack(&sl, 2);
//	SeqListPushBack(&sl, 3);
//	SeqListPushBack(&sl, 4);
//	SeqListPushBack(&sl, 5);
//
//	int ret = 0;
//	ret = SeqListFind(&sl, 5);
//	printf("�±�Ϊ��%d\n", ret);
//
//	SeqListDestroy(&sl);
//}

void menu() {
	printf("********************************************\n");
	printf("*******  1. β��  *******  2. βɾ  ********\n");
	printf("*******  3. ͷ��  *******  4. ͷɾ  ********\n");
	printf("*** 5. ����λ�ò���  *** 6. ����λ��ɾ�� ***\n");
	printf("*******  7. ����  *******  8. ��ӡ  ********\n");
	printf("****************** 0. �˳� *****************\n");
	printf("********************************************\n");
}
int main()
{
	
	int input = 0;
	int x = 0;
	int pos = 0;

	SL sl;
	SeqListInit(&sl);
	do {
		menu();
		printf("������ѡ��:>");
		scanf("%d", &input);
		if (input % 2 != 0) {
			printf("�����������:>");
			scanf("%d", &x);
		}
		if (input == 5 || input == 6) {
			printf("������λ���±�:>");
			scanf("%d", &pos);
		}
		switch (input) {
		case 1:
			SeqListPushBack(&sl, x);
			break;
		case 2:
			SeqListPopBack(&sl);
			break;
		case 3:
			SeqListPushFront(&sl, x);
			break;
		case 4:
			SeqListPopFront(&sl);
			break;
		case 5:
			SeqListInsert(&sl, pos, x);
			break;
		case 6:
			SeqListErase(&sl,pos);
			break;
		case 7:
			SeqListFind(&sl, x);
			break;
		case 8:
			SeqListPrint(&sl);
			break;
		case 0:
			SeqListDestroy(&sl);
			break;
		default:
			printf("ѡ���������������\n");

		}

	} while (input);
	return 0;
}