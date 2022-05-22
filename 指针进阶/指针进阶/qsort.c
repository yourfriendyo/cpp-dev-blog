#define _CRT_SECURE_NO_WARNINGS 1


//前情回顾：

//int Add(int x, int y) {
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
//int main()
//{
//	//字符指针
//	char c = 'w';
//	char* pc = &c;
//	char* str = "hello bit.";
//
//	//指针数组
//	int* arr[10];
//	char* ch[10];
//
//	//数组指针
//	int arr2[10];
//
//	int* p = arr2;//int*
//	int(*pArr)[10] = &arr2;//int(*)[10]
//
//	//函数指针
//	int (*pf)(int, int) = &Add;
//	//int (*pf)(int x, int y) = &Add;
//	printf("%d\n", (*pf)(2, 3));
//	//printf("%d\n", pf(2, 3));
//
//	//函数指针数组
//	int (*pA)(int, int) = &Add;
//	int (*pS)(int, int) = &Sub;
//	int (*pM)(int, int) = &Mul;
//	int (*pD)(int, int) = &Div;
//	
//	int (*pfArr[10])(int, int) = { 0,Add,Sub,Mul,Div };
//	
//	//指向函数数组的指针
//	int (*(*ppfArr)[10])(int, int) = &pfArr;
//
//	return 0;
//}

//int Add(int x, int y) {
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
//void menu() {
//	printf("**********************************\n");
//	printf("*****  1.Add  ******  2.Sub  *****\n");
//	printf("*****  3.Mul  ******  4.Div  *****\n");
//	printf("************  0.exit  ************\n");
//	printf("**********************************\n");
//
//}
//int Calc(int (*(*ppfArr)[5])(int, int),	int input, int op1, int op2)
//{
//	return (*ppfArr)[input](op1, op2);
//}
//
//int main()
//{
//	int (*pfArr[5])(int, int) = { 0,Add,Sub,Mul,Div };
//	int input = 0;
//	int op1 = 0;
//	int op2 = 0;
//	do {
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		if (input != 0) {
//			printf("请输入操作数\n");
//			scanf("%d%d", &op1, &op2);
//			printf("%d\n", Calc(pfArr, input, op1, op2));
//		}
//		else {
//			break;
//		}
//	} while (input);
//
//	return 0;
//}
//
//

//回调函数


//int Add(int x, int y) {
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
//
//Calc(int(*pf)(int, int))
//{
//	int ret = pf(1, 2);
//	//printf("%p\n", pf);
//	printf("%d\n", ret);
//}
//int main()
//{
//	//Calc(Add);
//	Calc(Sub);
//	
//	//printf("%p\n", Sub);
//
//	return 0;
//}


//
//void Bubble_sort(int arr[], int sz) {
//	for (int i = 0; i < sz - 1; i++) {//sz-1趟
//		for (int j = 0; j < sz - 1 - i; j++) {//sz-1-i次
//			//比较函数
//			if (arr[j] > arr[j + 1]) {
//				//交换函数
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//void Print(int arr[], int sz) {
//	for (int i = 0; i < sz; i++) {
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Bubble_sort(arr, sz);
//	Print(arr, sz);
//
//	return 0;
//}
//
//



#include <stdlib.h>
//qsort
//void qsort(void* base, size_t num, size_t width,
//	int(*cmp)(const void* e1, const void* e2));

//int main() {
//	int a = 10;
//	float f = 1.0f;
//
//	//char* p1 = &a;//从int*到char*的类型不兼容
//	//char* p2 = &f;//从float*到char*的类型不兼容
//
//	void* p1 = &a;
//	void* p2 = &f;
//
//	//p1++;
//	//*p1;
//	//p1 - p2;
//	//p1 > p2;
//
//	return 0;
//}



//用qsort模拟实现bubble_sort

//void Print(int arr[], int sz) {
//	for (int i = 0; i < sz; i++) {
//		printf("%d ", arr[i]);
//	}
//}
////比较函数：整型
//int int_cmp(const void* e1, const void* e2) {
//	return *(int*)e1 - *(int*)e2;
//}
//int main()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), int_cmp);
//	Print(arr, sz);
//
//	return 0;
//}


//qsort排序结构体

//void my_qsort(void* base, size_t num, size_t width,
//	int(*cmp)(const void* e1, const void* e2));
//struct stu {
//	char* name;
//	short age;
//	float score;
//};
//int score_cmp(const void* e1, const void* e2) {
//	//return ((struct stu*)e1)->score - ((struct stu*)e2)->score;//升序
//	return ((struct stu*)e2)->score - ((struct stu*)e1)->score;//降序
//}
//int name_cmp(const void* e1,const void* e2) {
//	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
//}
//int main()
//{
//	struct stu s[3] = { 
//		{ "张三", 22, 99.5f },{ "李四", 21, 66.4f },{ "王五", 18, 80.1f } 
//		//lisi		wangwu		zhangsan			
//	};
//	int sz = sizeof(s) / sizeof(s[0]);
//	my_qsort(s, sz, sizeof(s[0]), name_cmp);
//	//qsort(s, sz, sizeof(s[0]), score_cmp);
//	return 0;
//}


//用qsort的逻辑，实现冒泡排序

////打印函数
//void print_arr(int arr[],int sz) {
//	for (int i = 0; i < sz; i++) {
//		printf("%d ", arr[i]);
//	}
//}
////交换函数
//void Swap(char* buf1, char* buf2, size_t width) {
//	for (size_t i = 0; i < width; i++) {//宽度次
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
////比较函数
//int cmp(const void* e1, const void* e2) {
//	return *(int*)e1 - *(int*)e2;
//}
////排序函数
//void my_qsort(void* base, size_t num, size_t width, 
//	int(*cmp)(const void* e1, const void* e2)) {
//	for (size_t i = 0; i < num - 1; i++) {
//		for (size_t j = 0; j < num - 1 - i; j++) {
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0) {//以字节为单位
//				//以字节为单位进行交换
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//int main() {
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	my_qsort(arr, sz, sizeof(arr[0]), cmp);
//	print_arr(arr, sz);
//
//	return 0;
//}
//