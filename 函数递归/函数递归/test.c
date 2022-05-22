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


//输入密码实例
//int main()
//{
//	char password[20] = { 0 };
//	printf("请输入密码:>");
//	scanf("%s", password);
//	
//	//清理内容
//	while (getchar() != '\n')
//	{
//		;
//	}
//
//	printf("请确认密码[Y/N]:>");
//	int ch = getchar();
//	if (ch == 'Y')
//	{
//		printf("确认成功\n");
//	}
//	else
//	{
//		printf("确认失败\n");
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
//递归方式实现打印一个整数的每一位
//print(1234)
//print(123)+4
//print(12)+3+4
//print(1)+2+3+4
//printf(1)+2+3+4
//
//逻辑：
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
//递归和非递归分别实现求n的阶乘（不考虑溢出）
//n*n-1*n-2*n-3*…*1
//逻辑
//fac(n) = n * fac(n-1) , n>1
//fac(n) = 1 , n=0


//int fac1(int n)//非递归
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
//int fac2(int n)//递归
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
//strlen的模拟（递归实现）
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
//将参数字符串中的字符反向排列，不是逆序打印
//a bcdef
//a b cdef
//a b c def
//a b c d ef
//a b c d e f
//void reserve_string1(char* ch)//指针
//{
//	char* left = ch;
//	char* right = ch + strlen(ch) - 1;
//	while (left < right)
//	{
//		char tmp = *left;//不能交换地址，只能交换内容
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void reserve_string2(char* ch)//数组
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
//void reverse_string3(char* ch)//递归
////reverse("abcdef\0")
////交换a和f + reverse("f bcde\0\0")
////交换a和f + 交换b和e + reverse("fe cd\0\0\0")
////交换a和f + 交换b和e + 交换c和d + reverse("fed \0\0\0\0")
//{
//	char* left = ch;
//	char* right = ch + strlen(ch) - 1;
//
//	if (*ch != '\0')
//	{
//		char tmp = *left;//提取
//		*left = *right;//赋值
//		*right = '\0';//赋\0
//
//		reverse_string3(ch+1);//+1而不是后置的++
//
//		*right = tmp;//赋值
//	}
//}
//
//int main()
//{
//	char ch[20] = "abcdefg";
//	//char* ch = "abcdef";//err - 常量字符串不可修改
//	reverse_string3(ch);
//	printf("%s\n", ch);
//
//	return 0;
//}



//5.
//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
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
//		return n;//递归的出口
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
//递归实现n的k次方
//n^k = n * n^(k-1) ,k > 0
//n^k = 1 , k = 0
//
//double power(int n,int k)
//{
//	if (k > 0)
//		return n * power(n, k - 1);
//	else if (k == 0)
//		return 1.0;//递归的出口k=0
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
//递归和非递归分别实现求第n个斐波那契数
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
//	int c = 2;//n=3时不用运算
//	while (n - 3 > 0)//从头开始移动n-2次，n=3时不用
//	{
//		a = b;//b赋值给a
//		b = c;//c赋值给b
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



//汉诺塔
//1.n-1个移动A->B -- hannoi()
//2.n个移动A->C  -- move()
//3.n-1个移动B->C --hannoi()

//hannoi代码逻辑
//if(n>1) -- hannoi()
//else -- A->B or A->C
//hannoi(num,start,dest)

//void move(int n, int x, int z)
//{
//	printf("%d盘：%c->%c\n", n, x, z);
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
//		printf("输入盘数开始测试（0. 退出测试）\n");
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