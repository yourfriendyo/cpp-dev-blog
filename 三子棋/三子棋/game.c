#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//初始化棋盘函数实现

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


//打印棋盘函数实现
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
		for (j = 0; j < col; j++)//打印数据行
		{
			printf(" %c ", board[i][j]);
			if (j != col - 1)
				printf("|");
		}
		printf("\n");
		if (i != row - 1)//第三次不打印分割行
		{
			for (j = 0; j < col; j++)//打印分割行
			{
				printf("---");
				if (j != col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}


//玩家走函数实现
void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("玩家走\n");
	int x = 0;
	int y = 0;
	printf("请输入坐标:>");

	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)//坐标是否合法
		{
			if (board[x - 1][y - 1] == ' ')//位置是否空缺
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("位置已被占用，请重新输入:>\n");
			}
		}
		else
		{
			printf("坐标错误，请重新输入:>\n");
		}
	}	
}


//电脑走函数实现
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("电脑走\n");
	while (1)
	{
		i = rand() % ROW;
		j = rand() % COL;
		if (i <= row && j <= col)//判断位置是否合法
		{
			if (board[i][j] == ' ')//判断位置是否空缺
			{
				board[i][j] = '#';
				break;
			}	
		}
	}
}


//判断棋盘是否已满函数实现
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


//判断输赢函数实现
//横竖对角线
//行 - [i][j-1] [i][j] [i][j+1]
//列 - [i-1][j] [i][j] [i+1][j]
//对角线 - [i-1][j-1] [i][j] [i+1][j+1]
//玩家赢 - 返回*
//电脑赢 - 返回#
//平局 - 返回Q
//继续 - 返回C
char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	int j = 0;
	//判断列
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
			return board[1][j];
	}
	//对角线
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
//			//玩家赢
//			if ((board[i][j - 1] == board[i][j] && board[i][j] == board[i][j + 1])/*行*/
//				|| (board[i - 1][j] == board[i][j] && board[i][j] == board[i + 1][j])/*列*/
//				|| (board[i - 1][j - 1] == board[i][j] && board[i][j] == board[i + 1][j + 1])/*对角线*/
//				&& (board[i][j] == '*' && board[i][j] != '#'))
//				return '*';
//			//电脑赢
//			else if ((board[i][j - 1] == board[i][j] && board[i][j] == board[i][j + 1])/*行*/
//				|| (board[i - 1][j] == board[i][j] && board[i][j] == board[i + 1][j])/*列*/
//				|| (board[i - 1][j - 1] == board[i][j] && board[i][j] == board[i + 1][j + 1])/*对角线*/
//				&& board[i][j] != '*' && board[i][j] == '#')
//				return '#';
//			//继续
//			else if ((board[i][j - 1] != board[i][j] || board[i][j] != board[i][j + 1])/*行*/
//				|| (board[i - 1][j] != board[i][j] || board[i][j] != board[i + 1][j])/*列*/
//				|| (board[i - 1][j - 1] != board[i][j] && board[i][j] != board[i + 1][j + 1]))/*对角线*/
//				return 'C';
//			//平局
//			else
//				return 'Q';
//
//		}
//	}
//		
//}












