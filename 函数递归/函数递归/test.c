#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//int main()
//{
//	int ch = 0;
//	
//	while ((ch=getchar())!=EOF)
//	{
//		putchar(ch);
//	}
//
//	return 0;
//}


//��������ʵ��
//int main()
//{
//	char password[20] = { 0 };
//	printf("����������:>");
//	scanf("%s", password);
//	
//	//��������
//	while (getchar() != '\n')
//	{
//		;
//	}
//
//	printf("��ȷ������[Y/N]:>");
//	int ch = getchar();
//	if (ch == 'Y')
//	{
//		printf("ȷ�ϳɹ�\n");
//	}
//	else
//	{
//		printf("ȷ��ʧ��\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	while (ch = getchar() != EOF)
//	{
//		if (ch <= '9' && ch >= '0')
//			continue;
//		else
//			putchar(ch);
//	}
//
//	return 0;
//}







//1.
//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
//print(1234)
//print(123)+4
//print(12)+3+4
//print(1)+2+3+4
//printf(1)+2+3+4
//
//�߼���
//if(num>9)	print(num/10);
//printf(num%10);

//void Print(int n)
//{
//	if (n > 9)
//	{
//		Print(n / 10);
//	}
//	printf("%d", n%10);
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	Print(num);	
//
//	return 0;
//}
//


//2.
//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ������������
//n*n-1*n-2*n-3*��*1
//�߼�
//fac(n) = n * fac(n-1) , n>1
//fac(n) = 1 , n=0


//int fac1(int n)//�ǵݹ�
//{
//	int ret = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//
//
//int fac2(int n)//�ݹ�
//{
//	if (n > 0)
//		return n * fac2(n - 1);
//	else
//		return 1;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	
//	printf("%d\n", fac2(n));
//	return 0;
//}


//3.
//strlen��ģ�⣨�ݹ�ʵ�֣�
//abcdef\0
//a+strlen(bcdef\0)
//a+b+strlen(cdef\0)
//a+b+c+strlen(def\0)
//a+b+c+d+strlen(ef\0)
//a+b+c+d+e+strlen(f\0)
//a+b+c+d+e+f+strlen(\0)

//*ch!=0 , strlen(arr) = 1 + strlen(arr+1)
//*ch==0 , strlen(arr) = 0

//int my_strlen(char* ch)
//{
//	if (*ch != '\0')
//	{
//		return 1 + my_strlen(ch + 1);
//	}
//	else
//		return 0;
//}
//
//int main()
//{
//	char ch[20] = { 0 };
//	scanf("%s", &ch);
//
//	printf("%d", my_strlen(ch));
//
//	return 0;
//}
//



//4.
//�������ַ����е��ַ��������У����������ӡ
//a bcdef
//a b cdef
//a b c def
//a b c d ef
//a b c d e f
//void reserve_string1(char* ch)//ָ��
//{
//	char* left = ch;
//	char* right = ch + strlen(ch) - 1;
//	while (left < right)
//	{
//		char tmp = *left;//���ܽ�����ַ��ֻ�ܽ�������
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void reserve_string2(char* ch)//����
//{
//	//int left = 0;
//	//int right = strlen(ch) - 1;
//	//while (left < right)
//	//{
//	//	char tmp = ch[right];
//	//	ch[right] = ch[left];
//	//	ch[left] = tmp;
//	//	left++;
//	//	right--;
//	//}
//}
//
//void reverse_string3(char* ch)//�ݹ�
////reverse("abcdef\0")
////����a��f + reverse("f bcde\0\0")
////����a��f + ����b��e + reverse("fe cd\0\0\0")
////����a��f + ����b��e + ����c��d + reverse("fed \0\0\0\0")
//{
//	char* left = ch;
//	char* right = ch + strlen(ch) - 1;
//
//	if (*ch != '\0')
//	{
//		char tmp = *left;//��ȡ
//		*left = *right;//��ֵ
//		*right = '\0';//��\0
//
//		reverse_string3(ch+1);//+1�����Ǻ��õ�++
//
//		*right = tmp;//��ֵ
//	}
//}
//
//int main()
//{
//	char ch[20] = "abcdefg";
//	//char* ch = "abcdef";//err - �����ַ��������޸�
//	reverse_string3(ch);
//	printf("%s\n", ch);
//
//	return 0;
//}



//5.
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
//1234
//DS(123)+4
//DS(12)+3+4
//DS(1)+2+3+4
//1+2+3+4
 
//1234%10=4
//1234/10=123
//
//123%10=3
//123/10=12
// 
//12%10=2
//12/10=1
// 
//1%10=1
//1/10=0

//
//int DigitSum(int n)
//{
//	if (n > 9)
//		return DigitSum(n / 10) + n % 10;
//	else
//		return n;//�ݹ�ĳ���
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", DigitSum(n));
//
//	return 0;
//}





//6.
//�ݹ�ʵ��n��k�η�
//n^k = n * n^(k-1) ,k > 0
//n^k = 1 , k = 0
//
//double power(int n,int k)
//{
//	if (k > 0)
//		return n * power(n, k - 1);
//	else if (k == 0)
//		return 1.0;//�ݹ�ĳ���k=0
//	else
//		return 1.0 / power(n, -k);
//	
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d%d", &n, &k);
//	printf("%lf\n", power(n, k));
//}



//7.
//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
//1 1 2 3 5 8 13 21 34 55 89 ...
//F(n) = F(n-1) + F(n-2) , n>2
//F(1) = F(2) = 1


//
//int Fib(int n)
//{
//	if (n > 2)
//		return Fib(n - 1) + Fib(n - 2);
//	else
//		return 1;
//
//}
//
//
//int Fib(int n)
//{
//	if (n <= 2)
//		return 1;
//
//	int a = 1;
//	int b = 1;
//	int c = 2;//n=3ʱ��������
//	while (n - 3 > 0)//��ͷ��ʼ�ƶ�n-2�Σ�n=3ʱ����
//	{
//		a = b;//b��ֵ��a
//		b = c;//c��ֵ��b
//		c = a + b;
//		n--;
//	}
//
//	return c;
//
//
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d",Fib(n));
//
//
//	return 0;
//}



//��ŵ��
//1.n-1���ƶ�A->B -- hannoi()
//2.n���ƶ�A->C  -- move()
//3.n-1���ƶ�B->C --hannoi()

//hannoi�����߼�
//if(n>1) -- hannoi()
//else -- A->B or A->C
//hannoi(num,start,dest)

//void move(int n, int x, int z)
//{
//	printf("%d�̣�%c->%c\n", n, x, z);
//}
//void hannoi(int n, char x, char y, char z)
//{
//	if (n == 1)
//		move(n, x, z);
//	else
//	{
//		hannoi(n - 1, x, z, y);
//		move(n, x, z);
//		hannoi(n - 1, y, x, z);
//	}
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		printf("����������ʼ���ԣ�0. �˳����ԣ�\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			break;
//		default:
//			hannoi(input, 'A', 'B', 'C');
//			break;
//		}
//	} while (input);
//	return 0;
//}
//
//
//int fib(int n)
//{
//	if (n > 1)
//		return fib(n - 1) + fib(n - 2);
//	else
//		return 1;
//}
//int main()
//{
//	int n = 0;
//	int arr[50] = { 0 };
//	scanf("%d", &n);
//	
//	printf("%d\n", fib(n));
//
//}