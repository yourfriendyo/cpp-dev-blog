#define _CRT_SECURE_NO_WARNINGS 1

//7. auto�ؼ���

//7.1 auto�Ķ���
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 10;
//	auto d = 'A';
//	auto f = 11.11;
//	auto e = "str";
//
//
//	return 0;
//}

//7.2 auto��ʹ��

int main()
{
	int a = 10;
	auto pa1 = &a;
	auto* pa = &a;
	auto& ra = a;

	auto a = 1, b = 2;
	
	//auto c = 3, d = 4.0;//Err


	return 0;
}


//7.3 auto����ʹ�õĳ���

//int Add(int b, auto a = 1)//
//int Add(auto a = 1)//
//int Add(auto a)//
//
//int main()
//{
//	int a = 10;
//	int arr1[] = { 10,20 };
//	//auto arr2[] = { 20,30 };//Err
//
//
//	return 0;
//}