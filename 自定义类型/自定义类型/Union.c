#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
* 3. ���ϣ������壩
* ���ϵĶ���
* ���ϵ��ص�
* ���ϴ�С�ļ���
* */

//���ϵĶ���

//union Un {
//	char c;//1
//	int i;//4
//};

//int main()
//{
//	union Un u = { 0 };
//	//printf("%d\n", sizeof(union Un));
//	//printf("%d\n", sizeof(u));
//
//	printf("%p\n", &u);//00EFF934
//	printf("%p\n", &u.c);//00EFF934
//	printf("%p\n", &u.i);//00EFF934
//
//	return 0;
//}

//���ϵ��ص�

//int main()
//{
//	int  a = 1;
//	char* pc = (char*)&a;
//	if (*pc == 1) {
//		printf("С�˴洢\n");
//	}
//	else {
//		printf("��˴洢\n");
//	}
//
//	return 0;
//}

//union U {
//	char c;
//	int i;
//};
//
//int main()
//{
//	union U u;
//	u.i = 1;
//	if (u.c == 1) {
//		printf("С�˴洢\n");
//	}
//	else {
//		printf("��˴洢\n");
//	}
//	return 0;
//}

//int check_sys() {
//	union U {
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.c;
//}
//int main()
//{
//	if (check_sys() == 1) {
//		printf("С�˴洢\n");
//	}
//	else {
//		printf("��˴洢\n");
//	}
//
//	return 0;
//}

//���ϴ�С�ļ���

//union Un1 {
//	char c[5];
//	int i;
//};
//
//union Un2 {
//	short c[7];
//	int i;
//};
//
//int main()
//{
//	printf("%d\n", sizeof(union Un1));
//	printf("%d\n", sizeof(union Un2));
//
//	return 0;
//}