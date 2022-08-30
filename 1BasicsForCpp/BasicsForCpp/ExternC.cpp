#define _CRT_SECURE_NO_WARNINGS 1

//C++

#include <iostream>
using namespace std;
extern "C"
{
#include "../../StackLibrary/StackLibrary/Stack.h"
}


//C

#include <stdbool.h>
#include <stdio.h>

#include "../../StackLibrary/StackLibrary/Stack.h"



bool isValid(const char* s) {
	ST st;
	StackInit(&st);
	while (*s) {
		if (*s == '(' || *s == '[' || *s == '{') {
			StackPush(&st, *s);
		}
		else {
			//栈无元素，无法与右括号匹配  
			if (StackEmpty(&st)) {
				StackDestroy(&st);
				return false;
			}
			STDataType ret = StackTop(&st);
			if ((ret == '(' && *s != ')') ||
				(ret == '[' && *s != ']') ||
				(ret == '{' && *s != '}')) {
				StackDestroy(&st);
				return false;
			}
			else {
				StackPop(&st);
			}
		}
		s++;
	}
	if (StackEmpty(&st)) {
		StackDestroy(&st);
		return true;
	}
	else {
		StackDestroy(&st);
		return false;
	}
}

int main()
{

	printf("%d\n", isValid("[{()}]"));
	printf("%d\n", isValid("[{(}]("));

	return 0;
}