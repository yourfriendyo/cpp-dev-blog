#define _CRT_SECURE_NO_WARNINGS 1
#include "SingleList.h"

void SListTest1() {
	/*SLTNode list;
	SLTNode* plist = &list;*/

	SLTNode* plist = NULL;
	
	SListPushBack(plist, 1);
	SListPushBack(plist, 2);
	SListPushBack(plist, 3);
	SListPushBack(plist, 4);

	SListPrint(plist);

	SListPopBack(plist);//4
	SListPrint(plist);
	SListPopBack(plist);//3
	SListPrint(plist);
	SListPopBack(plist);//2
	SListPrint(plist);
	SListPopBack(plist);//1
	SListPrint(plist);
	SListPopBack(plist);//assert
	SListPrint(plist);
}

void SListTest2() {
	SLTNode* plist = NULL;

	SListPushBack(plist, 1);
	SListPushBack(plist, 2);
	SListPushBack(plist, 3);
	SListPushBack(plist, 4);
	
	SListPrint(plist);

	SListPushFront(plist, -1);
	SListPrint(plist);
	SListPushFront(plist, -2);
	SListPrint(plist);
	SListPushFront(plist, -3);
	SListPrint(plist);
	SListPushFront(plist, -4);
	SListPrint(plist);
}

void SListTest3() {
	SLTNode* plist = NULL;

	SListPushBack(plist, 1);
	SListPushBack(plist, 2);
	SListPushBack(plist, 3);
	SListPushBack(plist, 4);
	SListPrint(plist);
	
	SListPopFront(plist);//1
	SListPrint(plist);
	SListPopFront(plist);//2
	SListPrint(plist);
	SListPopFront(plist);//3
	SListPrint(plist);
	SListPopFront(plist);//4
	SListPrint(plist);
	SListPopFront(plist);//assert
}

void SListTest4() {
	SLTNode* plist = NULL;
	
	SListPushBack(plist, 1);
	SListPushBack(plist, 2);
	SListPushBack(plist, 3);
	SListPushBack(plist, 4);
	
	SListPrint(plist);

	SLTNode* Node = SListFind(plist, 2);
	if (Node != NULL) {
		printf("%p->%d\n", Node, Node->data);
	}
	else {
		printf("NULL\n");
	}
}

void SListTest5() {
	SLTNode* plist = NULL;
	SListPushBack(plist, 1);
	SListPushBack(plist, 2);
	SListPushBack(plist, 3);
	SListPushBack(plist, 4);


	//SListInsertAfter(plist, 0);

	SListInsertForward(plist, plist, 0);

	SListPrint(plist);
}

void SListTest6() {
	SLTNode* plist = NULL;

	SListPushBack(plist, 1);
	SListPushBack(plist, 2);
	SListPushBack(plist, 3);

	SListPrint(plist);

	SListEraseAfter(plist);

	SListPrint(plist);
}

void SListTest7() {
	SLTNode* plist = NULL;
	SListPushBack(plist, 1);
	//SListPushBack(plist, 2);
	//SListPushBack(plist, 3);
	//SListPushBack(plist, 4);
	//SListPushBack(plist, 5);
	SListPrint(plist);

	SLTNode* pos = plist->next;
	SListInsertForward(plist, pos, 555);

	//while (pos != NULL) {
	//	pos = SListFind(pos, 2);
	//	if (pos != NULL) {
	//		printf("0x%p---%d->", pos, pos->data);
	//		pos = pos->next;
	//	}
	//}
	
	//while (pos != NULL) {
	//	pos = SListFind(pos, 2);
	//	if (pos != NULL) {
	//		pos->data = 3;
	//	}
	//}
	//SListPrint(plist);

	//pos = SListFind(pos, 1);
	if (pos != NULL) {
		//SListInsertForward(plist, pos, 555);
	}
	SListPrint(plist);


}

void SListTest8() {
	SLTNode* plist = NULL;
	SListPushBack(plist, 1);
	SListPrint(plist);
	SLTNode* pos = SListFind(plist, 1);
	if (pos != NULL) {
		SListInsertAfter(pos, 2);
	}
	SListPrint(plist);
}

void SListTest9() {
	SLTNode* plist = NULL;
	SListPushBack(plist, 1);
	SListPushBack(plist, 2);
	SListPushBack(plist, 3);
	SListPushBack(plist, 4);
	SListPushBack(plist, 5);
	SListPrint(plist);
	SListEraseAfter(plist->next);
	SListPrint(plist);
}


int main()
{
	//SListTest1();
	//SListTest2();
	//SListTest3();
	//SListTest4();
	//SListTest5();
	//SListTest6();
	//SListTest7();
	//SListTest8();
	SListTest9();

	return 0;
}