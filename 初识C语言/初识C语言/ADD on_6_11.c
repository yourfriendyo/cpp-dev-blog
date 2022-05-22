#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//static修饰全局变量
//使其不可跨文件使用（外部链接属性失效）
static int g_val = 2021;

//static修饰的函数
//函数被static修饰，使其外部链接属性变内部链接属性
static int Add(int x, int y)
{
	return x + y;

}