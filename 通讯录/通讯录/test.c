#define _CRT_SECURE_NO_WARNINGS 1
/*
* ͨѶ¼ʵ��
* 1. ������100��
*	��Ϣ������+�Ա�+����+�绰+סַ
* ���ܣ�
*	1. ������ϵ��
*	2. ɾ����ϵ��
*	3. �޸���ϵ��
*	4. ������ϵ��
*	5. ������ϵ��
*
* ��չ���ܣ�
* 1. ʹ�ö�̬�ڴ�
* 2. �����ļ�
*		1. �˳�ʱ�������ݽ��ļ�
*		2. ����ʱ�����ļ�����
* */

/*
* test.c 
* ���Ը�������
* */
#include "contact.h"

void menu() {
	printf("***********************************\n");
	printf("****** 1. Add    *** 2. Del   *****\n");
	printf("****** 3. Search *** 4.Modify *****\n");
	printf("****** 5. Show   *** 6.Sort   *****\n");
	printf("***********   0. Exit   ***********\n");
	printf("***********************************\n");
}

int main()
{
	int input = 0;
	struct Contact con;
	InitContact(&con);	
	do {
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input) {
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowConstact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			//����ͨѶ¼
			SaveContact(&con);
			//����ͨѶ¼
			DestroyContact(&con);
			printf("�˳��ɹ���������\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}
