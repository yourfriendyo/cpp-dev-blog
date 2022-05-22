#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//int main()
//{
//	char arr1[20] = { 0 };//destination
//	char arr2[] = "damn it!";//source
//
//	strcpy(arr1, arr2);
//
//	printf("%s\n", arr1);
//
//	return 0;
//}

//int main()
//{
//	char arr1[20] = "xxxxxxxxxxxxxx";
//	char arr2[] = "damn it!";
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//
//	return 0;
//}

//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "damn it!";
//	//char* ret = strcpy(arr1, arr2);
//	//printf("%s\n", ret);
//	printf("%s\n", strcpy(arr1, arr2));
//
//	return 0;
//}

//int main()
//{
//	char arr[20] = "damn it!";
//	memset(arr, 'x', 2);
//	//1.
//	printf("%s\n", arr);
//	//2.
//	printf("%s\n", (char*)memset(arr, 'x', 2));
//
//	return 0;
//}

//int main()
//{
//	int arr[30] = { 0 };
//	memset(arr, 1, 5 * sizeof(int));
//	//这样的话只能把整型变量中每一个字节都变成1
//	//printf("%s\n", arr);
//
//		return 0;
//}

//自定义函数

//int get_max(int x, int y)//形式参数
//{
//	return x > y ? x : y;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);//实际参数
//	//求最大值
//	int ret = get_max(a, b);
//	printf("max:%d", ret);
//
//	return 0;
//}

//void Swap1(int x, int y)
//{
//	int t = 0;
//	t = x;
//	x = y;
//	y = t;
//}
//void Swap2(int* px, int* py)
//{
//	int t = 0;
//	t = *px;
//	*px = *py;
//	*py = t;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap1(a, b);
//	//传值调用
//	//实参传给形参是时，形参相当于实参的一份临时拷贝
//	//改变形参变量时不会影响实参的值
//	printf("Swap1：a=%d,b=%d\n", a, b);
//	//函数
//	Swap2(&a, &b);
//	//传址调用
//	printf("Swap2：a=%d,b=%d\n", a, b);
//
//	return 0;
//}
//



//练习

//打印素数 
//is_prime
//是素数返回1
//不是素数返回0

//#include<math.h>
//int is_prime(int n)
//{
//	//试除法
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//			return 0;	
//	}
//	return 1;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	if (is_prime(n))  
//		printf("%d是素数\n",n);
//	else
//		printf("%d不是素数\n",n);	
//
//	return 0;
//}

//判断闰年
//int is_leap_year(int y)
//{
//	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
//	{
//		return 1;
//	}
//	return 0;
//}

//int is_leap_year(int y)
//{
//	return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
//}
//
//int main()
//{
//	int y = 0;
//	scanf("%d", &y);
//	
//	if (is_leap_year(y))
//	{
//		printf("%d是闰年\n", y);
//	}
//	else
//		printf("%d不是闰年\n", y);
//
//	return 0;
//}


//二分查找
//int binary_search(char arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;	
//	while (left<=right)
//	{
//		int mid = (left+right)/2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//  		}
//		else
//			return mid;
//	}
//	return -1;
//}
//
//int main()
//{
//	char arr[20] = { 1,2,3,4,5,6,7,8,9,10 };
//	int key = 0;
//	scanf("%d", &key);
//	//计算数组元素个数
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//找到返回下标0~9
//	//找不到返回-1
//	int ret = binary_search(arr, key, sz);//TDD - 测试驱动开发
//	if (ret == -1)
//	{
//		 printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了，下标为%d", ret);
//	}
//
//	return 0;
//}


//2. 
//二分查找
//int binary_search(char arr[], int k, int left, int right)
//{
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//			return mid;
//	}
//	return -1;
//}
//
//int main()
//{
//	char arr[20] = { 1,2,3,4,5,6,7,8,9,10 };
//	int key = 0;
//	scanf("%d", &key);
//
//	int ret = binary_search(arr, key, 5, 9);
//	//TDD - 测试驱动开发
//	if (ret == -1)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了，下标为%d", ret);
//	}
//
//	return 0;
//}


//num++
//void Add(int* pnum)
//{
//	(*pnum)++;
//}
//int main()
//{
//	int num = 0;
//	Add(&num);
//	printf("%d\n", num);
//	return 0;
//}



//int Add(int num)
//{
//	num++;
//
//}
//int main()
//{
//	int num = 0;
//	num = Add(num);
//
//	return 0;
//}


//void fun1()
//{
//    printf("hanpidiaoyong\n");
//}
//void fun2()
//{
//    fun1();
//}
//int main()
//{
//    fun2();
//    return 0;
//}



//int main()
//{
//    printf("%d\n", strlen("abcde"));
//
//    return 0;
//}

//int main()
//{
//	char arr1[20] = "xxxxxxx";
//	char arr2[20] = "abcde";
//	strcpy(arr1,arr2);
//	printf("%s\n", strcpy(arr1, arr2));
//
//	return 0;
//}


//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));
//
//	return 0;
//}

//void test();
//int main()
//{
//	test();
//}
//void test()
//{}

//#include "Add.h"
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	int ret = Add(a, b);
//	printf("%d\n", ret);
//
//	return 0;
//}



//函数递归
//void print(size_t n)
//{
//	if (n > 9)//满足条件不递归
//	{
//		print(n / 10);//越来越接近条件
//	}
//	printf("%d ", n%10);
//}
//
//int main()
//{
//	//接收无符号整型值，按顺序打印每一位
//	unsigned int num = 0;
//	scanf("%d", &num);
//	print(num);
//
//	return 0;
//}

//int my_strlen(char* pa)
//{
//	int count = 0;
//	while (*pa++ != '\0')
//	{
//		//pa++;
//		count++;
//	}
//	return count;
//}
//

//my_strlen求字符串长度
//int my_strlen(char* pa)
//{
//	if (*pa == 0)
//	{
//		return 0;
//	}
//	return 1+my_strlen(pa + 1);//直接返回长度
//	
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	//求字符串长度
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//
//	return 0;
//}

//字符指针+1，向后跳一个字节
//整型指针+1，向后跳四个字节
//指针+1都是向后跳一个元素的地址，指针类型不同向后跳的字节也不同


//迭代可以简单的理解为循环
//int fac1(int n)
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//
//int fac(int n)
//{
//
//
//	if (n <= 1)
//		return 1;
//	else
//		return n * fac(n - 1);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fac(n);
//	printf("%d\n", ret);
//
//	return 0;
//}

//斐波那契数列

//int fib1(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//
//int fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//
//	while (n >= 3)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fib(n);
//	printf("%d\n", ret);
//
//	return 0;
//}