#define _CRT_SECURE_NO_WARNINGS 1
/* 
* ��̬�ڴ溯���Ľ���
* 1. malloc
* 2. free
* 3. calloc
* 4. realloc
* */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//malloc&free

//int main()
//{
//	//����ռ�
//	int* p = (int*)malloc(40);
//	//����ʧ��
//	if (p == NULL) {
//		printf("%s\n", strerror(errno));
//		return -1;
//	}
//	//���ٳɹ�
//	for (int i = 0; i < 10; i++) {
//		*(p + i) = i;
//		printf("%d ", *(p + i));
//	}
//	//�ͷſռ� 
//	free(p);
//	//�ÿ�
//	p = NULL;
//
//	return 0;
//}

//calloc&realloc

//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL) {
//		perror("");
//		return -1;
//	}
//	for (int i = 0; i < 10; i++) {
//		*(p + i) = i;
//		printf("%d ", p[i]);
//	}
//	//p = (int*)realloc(p, 20 * sizeof(int));
//	int* ptr = (int*)realloc(p, 20 * sizeof(int));
//	if (ptr == NULL) {
//		return -1;
//	}
//	p = ptr;
//	for (int i = 10; i < 20; i++) {
//		*(p + i) = i;
//		printf("%d ", p[i]);
//	}
//
//
//
//
//	free(p);
//	p = NULL;
//
//
//	return 0;
//}

