#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//打印菜单
void menu()
{
	printf("****************************************\n");
	printf("************** 1. play  ****************\n");
	printf("************** 0. exit  ****************\n");
	printf("****************************************\n");
}

//输出输赢
void PrintWin(char ret_Iswin)
{
	if (ret_Iswin == '*')
		printf("玩家赢\n");
	else if (ret_Iswin == '#')
		printf("电脑赢\n");
	else if (ret_Iswin == 'Q')
		printf("平局\n");
}

//游戏大体逻辑
void game()
{
	srand((unsigned int)time(NULL));
	//定义棋盘
	char board[ROW][COL];
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//玩家走
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		if (Iswin(board, ROW, COL) != 'C')
			break;
		//电脑走
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
		printf("请选择:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			//进入游戏
			game();
			break;
		case 0:
			printf("结束游戏\n");
			break;
		default :
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);

	return 0;
}