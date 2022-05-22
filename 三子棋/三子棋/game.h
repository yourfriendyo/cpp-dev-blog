#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//������ʼ������
extern void InitBoard(char board[ROW][COL], int row, int col);

//������ӡ����
extern void DisplayBoard(char board[ROW][COL], int row, int col);

//���������
extern void PlayerMove(char board[ROW][COL], int row, int col);

//����������
extern void ComputerMove(char board[ROW][COL], int row, int col);

//�����ж���Ӯ
extern char Iswin(char board[ROW][COL], int row, int col);

//�����ж�����
int Isfull(char board[ROW][COL], int row, int col);
