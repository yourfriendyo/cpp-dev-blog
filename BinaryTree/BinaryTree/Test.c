#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"

void BinaryTreeTest1() {
	BTNode* nA = BuildBTNode();
	BTNode* nB = BuildBTNode();
	BTNode* nC = BuildBTNode();
	BTNode* nD = BuildBTNode();
	BTNode* nE = BuildBTNode();
	BTNode* nF = BuildBTNode();
	BTNode* nG = BuildBTNode();
	nA->data = 'A';
	nA->left = nB;
	nA->right = nC;
	
	nB->data = 'B';
	nB->left = nD;
	nB->right = nE;
	
	nC->data = 'C';
	nC->left= nF;
	nC->right = nG;
	
	nD->data = 'D';
	nE->data = 'E';
	
	nF->data = 'F';
	nG->data = 'G';
	
	//PreOrder(nA);
	//printf("\n");
	//InOrder(nA);
	//printf("\n");
	//PostOrder(nA);
	//printf("\n");
	//levelOrder(nA);
	//printf("\n");

	//int count = 0;
	//BinaryTreeSize(nA, &count);
	//printf("%d\n", count);
	//int ret = BinaryTreeSize(nA);
	//printf("%d\n", ret);
	//int ret = BinaryTreeLeafSize(nA);
	//printf("%d\n", ret);
	//int ret = BinaryTreeLevelkSize(nA,3);
	//printf("%d\n", ret);
	//BTNode* ret = BinaryTreeFind(nA, 'E');
	//printf("%p\n", ret);
	//int ret = BinaryTreeDepth(nA);
	//printf("%d\n", ret);
	int ret = isBinaryTreeComplete(nA);
	printf("%d\n", ret);
}

void BinaryTreeTest2() {

}
int main()
{
	BinaryTreeTest1();
	//BinaryTreeTest2();
	

}

