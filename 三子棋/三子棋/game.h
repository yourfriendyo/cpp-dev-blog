#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//声明初始化棋盘
extern void InitBoard(char board[ROW][COL], int row, int col);

//声明打印棋盘
extern void DisplayBoard(char board[ROW][COL], int row, int col);

//声明玩家走
extern void PlayerMove(char board[ROW][COL], int row, int col);

//声明电脑走
extern void ComputerMove(char board[ROW][COL], int row, int col);

//声明判断输赢
extern char Iswin(char board[ROW][COL], int row, int col);

//声明判断满盘
int Isfull(char board[ROW][COL], int row, int col);
