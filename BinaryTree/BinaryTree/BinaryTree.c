#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"


BTNode* BuildBTNode() {
	BTNode* ret = (BTNode*)malloc(sizeof(BTNode));
	assert(ret);
	ret->left = ret->right = 0;
	return ret;
}


void PreOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root) {
	if (root == NULL) {
		printf("\\0 ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root) {
	if (root == NULL) {
		printf("\\0 ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}

void levelOrder(BTNode* root) {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q)) {
		BTNode* front = QueueFront(&q);
		printf("%c ", front->data);
		QueuePop(&q);
		if (front->left) {
			QueuePush(&q, front->left);
		}
		if (front->right) {
			QueuePush(&q, front->right);
		}
	}

	QueueDestroy(&q);
}

//1. 
void BinaryTreeSize1(BTNode* root, int* pcount) {
	if (root == NULL) {
		return;
	}
	(*pcount)++;
	BinaryTreeSize1(root->left, pcount);
	BinaryTreeSize1(root->right, pcount);
}
//2. 
int BinaryTreeSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	else if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	else {
		return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
	}
}

int BinaryTreeLevelkSize(BTNode* root, int k) {
	if (root == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return BinaryTreeLevelkSize(root->left, k - 1) + BinaryTreeLevelkSize(root->right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	if (root == NULL) {
		return NULL;
	}
	if (root->data == x) {
		return root;
	}
	BTNode* leftRet = BinaryTreeFind(root->left, x);
	if (leftRet) {
		return leftRet;
	}
	BTNode* rightRet = BinaryTreeFind(root->right, x);
	if (rightRet) {
		return rightRet;
	}
	return NULL;
}

int BinaryTreeDepth(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		int leftDepth = BinaryTreeDepth(root->left);
		int rightDepth = BinaryTreeDepth(root->right);
		return leftDepth > rightDepth ? leftDepth : rightDepth + 1;
	}
}

bool isBinaryTreeComplete(BTNode* root) {
	if (root == NULL) {
		return true;
	}
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	// 1. 找到第一个空结点
	while (!QueueEmpty(&q)) {
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL) {
			break;
		}
		else {
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
	}
	// 2. 检查队列中剩余结点是否有非空结点
	while (!QueueEmpty(&q)) {
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front) {
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}

void BinaryTreeDestroy(BTNode* root) {
	if (!root) {
		return;
	}
	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);	
	free(root);
}