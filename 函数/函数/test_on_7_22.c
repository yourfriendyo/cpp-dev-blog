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
//	//�����Ļ�ֻ�ܰ����ͱ�����ÿһ���ֽڶ����1
//	//printf("%s\n", arr);
//
//		return 0;
//}

//�Զ��庯��

//int get_max(int x, int y)//��ʽ����
//{
//	return x > y ? x : y;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);//ʵ�ʲ���
//	//�����ֵ
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
//	//��ֵ����
//	//ʵ�δ����β���ʱ���β��൱��ʵ�ε�һ����ʱ����
//	//�ı��βα���ʱ����Ӱ��ʵ�ε�ֵ
//	printf("Swap1��a=%d,b=%d\n", a, b);
//	//����
//	Swap2(&a, &b);
//	//��ַ����
//	printf("Swap2��a=%d,b=%d\n", a, b);
//
//	return 0;
//}
//



//��ϰ

//��ӡ���� 
//is_prime
//����������1
//������������0

//#include<math.h>
//int is_prime(int n)
//{
//	//�Գ���
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
//		printf("%d������\n",n);
//	else
//		printf("%d��������\n",n);	
//
//	return 0;
//}

//�ж�����
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
//		printf("%d������\n", y);
//	}
//	else
//		printf("%d��������\n", y);
//
//	return 0;
//}


//���ֲ���
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
//	//��������Ԫ�ظ���
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//�ҵ������±�0~9
//	//�Ҳ�������-1
//	int ret = binary_search(arr, key, sz);//TDD - ������������
//	if (ret == -1)
//	{
//		 printf("�Ҳ���\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±�Ϊ%d", ret);
//	}
//
//	return 0;
//}


//2. 
//���ֲ���
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
//	//TDD - ������������
//	if (ret == -1)
//	{
//		printf("�Ҳ���\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±�Ϊ%d", ret);
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



//�����ݹ�
//void print(size_t n)
//{
//	if (n > 9)//�����������ݹ�
//	{
//		print(n / 10);//Խ��Խ�ӽ�����
//	}
//	printf("%d ", n%10);
//}
//
//int main()
//{
//	//�����޷�������ֵ����˳���ӡÿһλ
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

//my_strlen���ַ�������
//int my_strlen(char* pa)
//{
//	if (*pa == 0)
//	{
//		return 0;
//	}
//	return 1+my_strlen(pa + 1);//ֱ�ӷ��س���
//	
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	//���ַ�������
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//
//	return 0;
//}

//�ַ�ָ��+1�������һ���ֽ�
//����ָ��+1��������ĸ��ֽ�
//ָ��+1���������һ��Ԫ�صĵ�ַ��ָ�����Ͳ�ͬ��������ֽ�Ҳ��ͬ


//�������Լ򵥵����Ϊѭ��
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

//쳲���������

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