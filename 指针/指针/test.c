#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//������ʱ
//int main()
//{
//	int a = 0x11223344;
//	char* pa = &a;
//
//	*pa = 0;
//
//
//	return 0;
//}



//ָ��+-����
//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	char* pc = &a;
//	printf("%p\n", pa);
//	printf("%p\n", pc);
//	printf("%p\n", pa+1);
//	printf("%p\n", pc+1);
//
//
//	return 0;
//}



//int main()
//{
//	int arr[10] = { 0 };
//	int* pa = arr;
//	//char* pa = arr;
//	for (int i = 0; i < 10; i++)
//	{
//		*(pa + i) = 1;
//	}
//
//	return 0;
//}

//
//int main()
//{
//	int* p;//δ��ʼ�� 
//	*p = 20;
//
//
//	return 0;
//}
 
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	for (int i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;
//	}
//
//	return 0;
//}

//
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	printf("hehe\n");
//	printf("%d\n", *p);
//	//*p = 20;
//
//	return 0;
//}



//ָ������


//ָ��Ӽ�����

//#define N_VALUE 5
//int main()
//{
//	float VALUES[N_VALUE];
//	float* vp = VALUES;
//	for (vp = &VALUES[0]; vp < &VALUES[N_VALUE];)
//	{
//		*vp++=0;
//	}
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr[9];
//	printf("%p\n", p);
//	printf("%p\n", p - 1);
//
//
//	return 0;
//}


//ָ��-ָ��

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	char ch[] = { '1','2','3' };
//	printf("%d\n", &arr[9] - &ch[0]);
//
//	return 0;
//}

//int my_strlen(char* s)
//{
//	char* begin = s;
//	while (*s++)
//	{
//		;
//	}
//	return s - begin - 1;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", my_strlen(arr));
//
//
//	return 0;
//}

//ָ��Ĺ�ϵ����

//#define N_VALUE 5
//
//int main()
//{
//
//    int values[5] = {1,2,3,4,5};
//    int* vp = values;
//
//    //1.
//    for (vp = &values[N_VALUE]; vp > &values[0];)
//    {
//        *--vp = 0;
//    }
//    //2.
//    for (vp = &values[N_VALUE - 1]; vp >= &values[0]; vp--)
//    {
//        *vp = 0;
//    }
//    return 0;
//}



//ָ�������
//int main()
//{
//	int arr[10] = { 0 }; 
//	int sz = sizeof(arr);
//	printf("%d\n", sz);
//	//1.sizeof(arr) ��������������Ԫ�صĵ�ַ����ʾ��������
//	//2.&arr��ʾ��������
//
//	 
//
//	//printf("%p\n", arr);
//	//printf("%p\n", &arr[0]);
//
//
//	return 0;
//}

//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//for (int i = 0; i < sz; i++)
//	//{
//	//	*(p + i) = i;
//	//}
//	//for (int i = 0; i < sz; i++)
//	//{
//	//	printf("%d ", *(p + i));
//	//}
//	for (int i = 0; i < sz; i++)
//	{
//		printf("&arr[%d] = %p <===> p+%d = %p\n", i, &arr[i], i, p + i);
//	}
//
//
//	return 0;
//}


//����ָ��
//int main()
//{
//	int a = 0;
//	int * p = &a;//һ��ָ��
//	int* * pp = &p;//����ָ��
//	int** * ppp = &pp;//����ָ��
//
//	*p = 1;
//	**pp = 2;
//	***ppp = 3;
//
//	printf("%d\n", a);
//
//	return 0;
//}


//ָ������
//int main()
//{
//	int arr[10] = { 0 };
//	//�������� - ������ͱ���������
//	char ch[10] = { '0' };
//	//�ַ����� - ����ַ�����������
//
//	int* parr[10];
//	char* pch[5];
//
//  return 0;
//}


//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = 3;
//
//	int* parr[] = { &a,&b,&c };
//
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d ", *parr[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d ", **(parr + i));
//	}
//
//
//	return 0;
//}
//






//int main()
//{
//	int arr[5] = { 10,20,30 };
//	int* parr[5] = {NULL};
//	for (int i = 0; i < 3; i++)
//	{
//		parr[i] = &arr[i];
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d ", **(parr+i));
//	}
//
//	return 0;
//}