#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	int arr[10];
//
//	int count = 10;
//	int arr2[count];
//
//	float arr3[20];
//	char ch[10];
//
//	return 0;
//}

//int main()
//{
//	//��ʼ��
//	int arr[10] = { 1,2,3 };//����ȫ��ʼ��
//
//	int arr2[] = { 1,2,3,4 };//���ó�ʼ�����ݣ�ָ�������С
//
//	char arr3[] = "abc";//�ַ�����ʼ������ 
//	char arr4[] = { 'a','b','c' };
//	char arr5[] = { 'a',98,'c' };
//
//
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//������±��Ǵ�0��ʼ��0~9
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//��ַ�ռ�
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("&arr[%d]=%p\n", i,&arr[i]);
//	}
//
//	return 0;
//}

//& arr[0] = 0113FD48
//& arr[1] = 0113FD4C
//& arr[2] = 0113FD50
//& arr[3] = 0113FD54
//& arr[4] = 0113FD58
//& arr[5] = 0113FD5C
//& arr[6] = 0113FD60
//& arr[7] = 0113FD64
//& arr[8] = 0113FD68
//& arr[9] = 0113FD6C


//int main()
//{
//
//	char ch[4][7];//4��5��
//	double arr3[2][4];//2��4��
//
//
//	//3��5��
//	int arr1[3][5] = { 1,2,3,4,5,6,7,8,9,10,11 };
//	//int arr2[3][5] = { {1,2},{3,4},{5,6,7} };
//	//int arr3[][5] = { {1,2},{3,4},{5,6,7} };
//	//int arr2[3][] = { {1,2},{3,4},{5,6,7} };//err
//
//
//	char ch1[2][4] = { 'a','b' };
//	char ch2[2][4] = { {'a'},{'b'} };
//	char ch3[3][5] = { "abc","def","gh" };
//
//	int arr2[3][5] = { {1,2},{3,4},{5,6,7} };
//	//for (int i = 0; i < 3; i++)//�� 0~2
//	//{
//	//	for (int j = 0; j < 5; j++)//��0~4
//	//	{
//	//		printf("%d ", arr2[i][j]);
//	//	}
//	//	printf("\n");
//	//}
//
//	//for (int i = 0; i < 3; i++)//�� 0~2
//	//{
//	//	for (int j = 0; j < 5; j++)//��0~4
//	//	{
//	//		printf("%p\n", &arr2[i][j]);
//	//	}
//	//	printf("\n");
//	//}
//
//	return 0;
//}



//int main()
//{
//	int arr[3][5] = { {1,2,3},{4,5,6},{7,8} };
//	int* p = &arr[0][0];
//	for (int i = 0; i < 15; i++)
//	{
//		printf("%d ", *p++);
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	for (int i = 0; i <= 15; i++)
//	{
//		arr[i] = i;
//	}
//
//	return 0;
//}
//

void Print(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", *arr++);
	}
}

//void Sort(int arr[],int sz)//int* arr
void Sort(int *arr,int sz)
//�������βα�����ָ��
//���齵���Ż�Ϊ��Ԫ�ص�ַ
{
	//int sz = sizeof(arr) / sizeof(arr[0]);//err//��ָ���sizeofֵ������һ��ֵ = 4 / 4 = 1
	for (int i = 0; i < sz - 1; i++)//n-1��
	{
		for (int j = 0; j < sz - 1 - i; j++)//n-1-i��
		{
			if (arr[j] > arr[j + 1])//Ŀ������
			{
				//����
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

//ð������
int main()
{
	int arr[] = { 1,4,6,3,7,9,3,2,8,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//��������������sizeof�У���ʾ��������

	//����
	Sort(arr,sz);
	//��ӡ
	Print(arr,sz);

	return 0;
}
