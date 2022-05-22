#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//��ʼ�����̺���ʵ��

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j]=' ';
		}
	}
}


//��ӡ���̺���ʵ��
//    |   |
// ---|---|---
//    |   | 
// ---|---|---
//    |   |

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)//��ӡ������
		{
			printf(" %c ", board[i][j]);
			if (j != col - 1)
				printf("|");
		}
		printf("\n");
		if (i != row - 1)//�����β���ӡ�ָ���
		{
			for (j = 0; j < col; j++)//��ӡ�ָ���
			{
				printf("---");
				if (j != col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}


//����ߺ���ʵ��
void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("�����\n");
	int x = 0;
	int y = 0;
	printf("����������:>");

	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)//�����Ƿ�Ϸ�
		{
			if (board[x - 1][y - 1] == ' ')//λ���Ƿ��ȱ
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("λ���ѱ�ռ�ã�����������:>\n");
			}
		}
		else
		{
			printf("�����������������:>\n");
		}
	}	
}


//�����ߺ���ʵ��
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("������\n");
	while (1)
	{
		i = rand() % ROW;
		j = rand() % COL;
		if (i <= row && j <= col)//�ж�λ���Ƿ�Ϸ�
		{
			if (board[i][j] == ' ')//�ж�λ���Ƿ��ȱ
			{
				board[i][j] = '#';
				break;
			}	
		}
	}
}


//�ж������Ƿ���������ʵ��
int Isfull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}


//�ж���Ӯ����ʵ��
//�����Խ���
//�� - [i][j-1] [i][j] [i][j+1]
//�� - [i-1][j] [i][j] [i+1][j]
//�Խ��� - [i-1][j-1] [i][j] [i+1][j+1]
//���Ӯ - ����*
//����Ӯ - ����#
//ƽ�� - ����Q
//���� - ����C
char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�ж���
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	int j = 0;
	//�ж���
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
			return board[1][j];
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' '
		|| board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	else
		if (Isfull(board,row,col) == 1)
			return 'Q';
	else
		return 'C';

}


//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)
//		{
//			//���Ӯ
//			if ((board[i][j - 1] == board[i][j] && board[i][j] == board[i][j + 1])/*��*/
//				|| (board[i - 1][j] == board[i][j] && board[i][j] == board[i + 1][j])/*��*/
//				|| (board[i - 1][j - 1] == board[i][j] && board[i][j] == board[i + 1][j + 1])/*�Խ���*/
//				&& (board[i][j] == '*' && board[i][j] != '#'))
//				return '*';
//			//����Ӯ
//			else if ((board[i][j - 1] == board[i][j] && board[i][j] == board[i][j + 1])/*��*/
//				|| (board[i - 1][j] == board[i][j] && board[i][j] == board[i + 1][j])/*��*/
//				|| (board[i - 1][j - 1] == board[i][j] && board[i][j] == board[i + 1][j + 1])/*�Խ���*/
//				&& board[i][j] != '*' && board[i][j] == '#')
//				return '#';
//			//����
//			else if ((board[i][j - 1] != board[i][j] || board[i][j] != board[i][j + 1])/*��*/
//				|| (board[i - 1][j] != board[i][j] || board[i][j] != board[i + 1][j])/*��*/
//				|| (board[i - 1][j - 1] != board[i][j] && board[i][j] != board[i + 1][j + 1]))/*�Խ���*/
//				return 'C';
//			//ƽ��
//			else
//				return 'Q';
//
//		}
//	}
//		
//}












