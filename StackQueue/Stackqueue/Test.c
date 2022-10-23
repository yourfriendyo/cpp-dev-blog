#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#include "Queue.h"

void StackTest1() {
	ST stack;
	StackInit(&stack);

	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);
	StackPush(&stack, 4);
	StackPush(&stack, 5);
	StackPush(&stack, 6);
	StackPush(&stack, 7);
	StackPush(&stack, 8);
	StackPush(&stack, 9);
	StackPush(&stack, 10);

	//—≠ª∑¥Ú”°
	while (!StackEmpty(&stack)) {
		printf("%d ", StackTop(&stack));
		StackPop(&stack);
	}

	//StackPop(&stack);

	while (!StackEmpty(&stack)) {
		printf("%d ", StackSize(&stack));
		StackPop(&stack);
	}

	StackDestroy(&stack);
	
}

void QueueTest1() {
	Queue queue;
	QueueInit(&queue);
	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	QueuePush(&queue, 4);
	QueuePush(&queue, 5);
	QueuePush(&queue, 6);
	QueuePush(&queue, 7);
	
	QueuePop(&queue);//1
	QueuePop(&queue);//2
	QueuePop(&queue);//3
	QueuePop(&queue);//4
	QueuePop(&queue);//5
	QueuePop(&queue);//6
	QueuePop(&queue);//7
	//QueuePop(&queue);


	QueueDestroy(&queue);

}

void QueueTest2() {

	Queue queue;
	QueueInit(&queue);
	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	QueuePush(&queue, 4);
	QueuePush(&queue, 5);
	QueuePush(&queue, 6);
	QueuePush(&queue, 7);
	printf("%d\n", QueueFront(&queue));
	printf("%d\n", QueueBack(&queue));

	while (!QueueEmpty(&queue)) {
		printf("Data:%d ", QueueFront(&queue));
		printf("Size:%d ", QueueSize(&queue));
		QueuePop(&queue);
	}

	QueueDestroy(&queue);

}
int main()
{
	//StackTest1();
	//QueueTest1();
	QueueTest2();

	return 0;
}