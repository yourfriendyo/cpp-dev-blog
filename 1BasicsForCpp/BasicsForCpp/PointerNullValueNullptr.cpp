#define _CRT_SECURE_NO_WARNINGS 1

//9. nullptr

//9.1 C++98�е�ָ���ֵ
#include <stddef.h>

#ifndef NULL
	#ifdef __cplusplus
		#define NULL 0
	#else
		#define NULL ((void *)0)
	#endif
#endif

nullptr
