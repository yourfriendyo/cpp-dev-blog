#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//��ӡ�˵�
void menu()
{
	printf("****************************************\n");
	printf("************** 1. play  ****************\n");
	printf("************** 0. exit  ****************\n");
	printf("****************************************\n");
}

//�����Ӯ
void PrintWin(char ret_Iswin)
{
	if (ret_Iswin == '*')
		printf("���Ӯ\n");
	else if (ret_Iswin == '#')
		printf("����Ӯ\n");
	else if (ret_Iswin == 'Q')
		printf("ƽ��\n");
}

//��Ϸ�����߼�
void game()
{
	srand((unsigned int)time(NULL));
	//��������
	char board[ROW][COL];
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//�����
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		if (Iswin(board, ROW, COL) != 'C')
			break;
		//������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//
		if (Iswin(board, ROW, COL) != 'C')
			break;
	}
	PrintWin(Iswin(board, ROW, COL));
}


int main()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			//������Ϸ
			game();
			break;
		case 0:
			printf("������Ϸ\n");
			break;
		default :
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}