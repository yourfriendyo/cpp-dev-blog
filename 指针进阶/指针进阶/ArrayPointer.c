#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//�ַ�ָ��

//int main()
//{	
//	//char ch = 'w';
//	//char* pch = &ch;
//
//	char* pc = "hello";
//	printf("%c\n", *(pc + 1));
//	printf("%s\n", pc);
//	printf("%s\n", pc + 1);
//		
//

//	return 0;
//}
//int main()
//{
//	char str1[] = "hello bit";
//	char str2[] = "hello bit";
//
//	char* str3 = "hello bit";
//	char* str4 = "hello bit";
//
//	if (str1 == str2)
//		printf("str1 = str2\n");
//	else
//		printf("str1 != str2\n");
//
//	if (str3 == str4)
//		printf("str3 = str4\n");
//	else
//		printf("str3 != str4\n");
//	
//	return 0;
//}


//ָ������

//int main()
//{
//	//int arr[10];//��������
//	//char ch[5];//�ַ�����
//	//float f[20];//����������
//
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int d = 40;
//	
//
//	//float* pf[20];
//	//char* pch[5];
//	int* parr[10] = { &a, &b, &c, &d };
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d ", *parr[i]);
//	}
//
//	return 0;
//}

//int main() {
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//
//	int* parr[] = { arr1,arr2,arr3 };
//
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 5; j++) {
//			//printf("%d ", *(*(parr + i) + j));
//			printf("%d ", parr[i][j]);
//		}
//
//		printf("\n");
//	}
//
//
//	return 0;
//}

//int main()
//{
//	char* pch[] = { "abcde", "bcdef", "cdefg" };
//	for (int i = 0; i < 3; i++) {
//		//printf("%s", pch[i]);
//		//printf("%s", *(pch + i));
//		for (int j = 0; j < 5; j++) {
//			//printf("%c", pch[i][j]);
//			//printf("%c", *(*(pch + i) + j));
//		}
//		printf("\n");
//	}
//
//
//
//	return 0;
//}


//����ָ��Ķ���

//int main()
//{
//	char* pch;//����ָ��
//	int* pint;//����ָ��
//	int(*ptr)[10];//��������ָ�� - ָ�������ָ��
//	
//	char ch = 'w';
//	char* pch = &ch;//�ַ���ַ������ַ�ָ����
//
//	int a = 10;
//	int* pint = &a;//���͵�ַ���������ָ����
//
//	float f = 0.0;
//	float* pf = &f;//�����͵�ַ����ڸ�����ָ����
//
//	
//	
//	int arr[10] = { 0 };
//	//1.
//	int* pa = arr;
//	//2.
//	&arr;//��������ĵ�ַ
//	int* parr = &arr;
//	//3.
//	int* parr[10] = &arr;
//	//4.
//	int(*parr)[10] = &arr;
//
//
//	return 0;
//}
//


//&arr��arr
//int main()
//{
//	int arr[10] = { 0 };
//
// //��Ԫ�صĵ�ַ
//	printf("%p\n", arr);//0073FCA4
//	printf("%p\n", &arr[0]);//0073FCA4
//	//ȡ������ĵ�ַ
//	printf("%p\n", &arr);//0073FCA4
//
//
//	printf("%p\n", arr);//0073FCA4
//	printf("%p\n", arr + 1);//0073FCA8
//
//	printf("%p\n", &arr);//0073FCA4
//	printf("%p\n", &arr + 1);//0073FCCC
//
//	return 0;
//}

//
//int main()
//{
//	int* arr[10] = { 0 };
//	int* (*p)[10] = &arr;
//
//	return 0;
//}
//



//����ָ���ʹ��

//void Print1(int arr[], int sz) {
//	for (int i = 0; i < sz; i++) {
//		//printf("%d ", arr[i]); 
//		printf("%d ", *(arr + i));
//		
//	}
//}
//
//void Print2(int* arr, int sz) {
//	for (int i = 0; i < sz; i++) {
//		printf("%d ", arr[i]);
//		//printf("%d ", *(arr + i));
//	}
//}
//
//void Print3(int(*pa)[10], int sz) {//����ʾ��
//	for (int i = 0; i < sz; i++) {
//		//printf("%d ", pa[i]);
//		printf("%d ", *(pa+i));
//	}
//}
//
//void Print4(int(*pa)[10], int sz) {
//	for (int i = 0; i < sz; i++) {
//		printf("%d ", (*pa)[i]);
//		//printf("%d ", *(*pa) + i);// *(*(pa+0)+j)
//	}
//	
//}
//int main() {
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//Print1(arr, sz);
//	//Print2(arr, sz);
//	Print3(&arr, sz);
//	//Print4(&arr, sz);
//
//	return 0;
//}
//


//��ά���鴫��,�ö�ά�������

//void Print1(int arr[3][5], int r, int c) {//��ά���鴫�Σ�����������ָ�����
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			//printf("%d ", arr[i][j]);
//			printf("%d ", *(*(arr + i) + j));
//		}
//		printf("\n");
//	}
//}


//��ά���鴫��,��һά����ָ�����

//void Print2(int(*arr)[5], int r, int c) {//��ά���鿴��3��һά����5��Ԫ�ص�һ��ѭ����������
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			printf("%d ", arr[i][j]);
//			//printf("%d ", *(*(arr + i) + j));
//		}
//		printf("\n");
//	}
//}
//


//��ά���鴫�Σ��ö�ά����ָ�����
 
//void Print3(int(*arr)[3][5], int r, int c) {
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			//printf("%d ", arr[0][i][j]);
//			//printf("%d ", *(*(*(arr) + i) + j));//*(arr) - ȡ��һ��
//		}
//		printf("\n");
//	}
//}
//
////
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };
//	
//	Print2(arr, 3, 5);//��ά������Ԫ��������
//	Print3(&arr, 3, 5);
//
//	return 0;
//}

//int main()
//{
//	//1.
//	int arr[5];
//	//2.
//	int* pa1[5];
//	//3.
//	int(*pa2)[10];
//	//4.
//	int(*pa3[10])[5];
//
//
//	return 0;
//}



//���鴫�κ�ָ�봫��

//һά���鴫��
////1.
//void test(int arr[]) 
//{}
////2.
//void test(int arr[10]) 
//{}
////3.
//void test(int* arr) 
//{}
////4.
//void test2(int* arr[2])
//{}
////5.
//void test2(int** arr) 
//{}
//
//int main()
//{	
//	int arr[10] = { 0 };
//	int* arr2[10] = { 0 };
//	test(arr);
//	test2(arr2);
//
//
//	return 0;
//}


//��ά���鴫��

////1.
//void test(int arr[3][5]) 
//{}
////2.
//void test(int arr[][])
//{}
////3.
//void test(int arr[][5])
//{}
//
////4.
//void test(int* arr)
//{}
////5.
//void test(int* arr[5])
//{}
////6.
//void test(int(*arr)[5])
//{}
//7.
//void test(int** arr)
//{	
//}

//int main() {
//	int arr[3][5] = { 0 };
//	test(arr);
//}


//һ��ָ�봫��

//void Print(int* ptr, int sz)
//{
//	for (int i = 0; i < sz; i++) {
//		printf("%d ", *(ptr + i));
//	}
//}
//void Print(int arr[],int sz)
//{}
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Print(p, sz);
//
//	return 0;
//}


//����ָ�봫��

//
//void test(int** pp)
//{
//	printf("%d\n", **pp);
//}
//
//void test(int* arr[])
//{
//	printf("%d\n", *arr[0]);
//}
//
//int main() {
//	int a = 10;
//	int* p = &a;
//	int** pp = &p;
//	test(pp);
//
//	return 0;
//}


//void test(int** pp)
//{
//	printf("%d\n", **pp);
//}
//
//int main() {
//	int a = 10;
//	int* p = &a;
//	int** pp = &p;
//	int* arr[10] = { &a };
//	test(&p);
//	test(pp);
//	test(arr);
//	
//}


//����ָ��

//������ַ??

//
//int Add(int x, int y)
//{
//	return x + y;
//}

//int main()
//{
//	printf("%p\n", &Add);
//	printf("%p\n", Add);
//	return 0;
//}
//


//int main()
//{
//	//����ָ��
//	int* pa = &a;
//	//�ַ�ָ�� 
//	char* pc = &ch;
//	//����ָ��
//	int(*pa)[10] = &arr;
//	//����ָ�� - ��ź�����ַ
//	int(*pf)(int, int) = &Add;
//	
//
//	return 0;
//}
//


//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	
//	//1.
//	printf("%d\n", Add(2, 3));
//	//2.
//	printf("%d\n", (*Add)(2, 3));
//	//3.
//	printf("%d\n", (*&Add)(2, 3));
//	
//
//	int(*pAdd)(int, int) = &Add;//����ָ��ָ��Add����
//	//1.
//	printf("%d\n", (*pAdd)(2, 3));
//	//2.
//	printf("%d\n", pAdd(2, 3));
//	
//	////1.
//	//int ret2 = (*pAdd)(2, 3);
//	//printf("%d\n", ret2);
//	////2.
//	//int ret1 = pAdd(2, 3);
//	//printf("%d\n", ret1); 
//
//	return 0;
//}


//typedef void(*pf_t)(int);
//
//int main()
//{
//	void(*pf)() = (void(*)())0;
//
//	(* ( void(*)() ) 0 )();
//	 
//	return 0;
//}
//
//void (* signal(int, void(*)(int)) ) (int);
//
//pf_t signal(int, pf_t);
//void(*)(int) signal(int, void(*)(int));



//����ָ������

//����ָ������Ķ���
//int Add(int x, int y) {//int(*)(int,int)
//	return x + y;
//}
//int Sub(int x, int y) {
//	return x - y;
//}
//int Mul(int x, int y) {
//	return x * y;
//}
//int Div(int x, int y) {
//	return x / y;
//}


//����ָ�������ʹ��
//int main()
//{
//	//����ָ��
//	//int (*p1)(int, int) = Add;
//	//int (*p2)(int, int) = Sub;
//	//int (*p3)(int, int) = Mul;
//	//int (*p4)(int, int) = Div;
//
//
//	//����ָ������ - pfArr
//	int(*pfArr[4])(int, int) = { Add,Sub,Mul,Div };
//
//
//
//	return 0;
//}


//������ʵ��
//int Add(int x, int y) {//int(*)(int,int)
//	return x + y;
//}
//int Sub(int x, int y) {//int(*)(int,int)
//	return x - y;
//}
//int Mul(int x, int y) {//int(*)(int,int)
//	return x * y;
//}
//int Div(int x, int y) {//int(*)(int,int)
//	return x / y;
//}
//
//void menu() {
//	printf("**********************************\n");
//	printf("*****  1.Add  ******  2.Sub  *****\n");
//	printf("*****  3.Mul  ******  4.Div  *****\n");
//	printf("************  0.exit  ************\n");
//	printf("**********************************\n");
//
//}

