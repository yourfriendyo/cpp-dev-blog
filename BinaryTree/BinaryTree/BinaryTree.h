#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "Queue.h"

typedef char BTDataType;

typedef struct BinaryTreeNode {
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;


BTNode* BuildBTNode();
void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);
void levelOrder(BTNode* root);


int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelkSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
int BinaryTreeDepth(BTNode* root);
bool isBinaryTreeComplete(BTNode* root);
void BinaryTreeDestroy(BTNode* root);