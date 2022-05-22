#include <stdio.h> 


//预定义符号

//声明函数
//extern int Add(int x, int y);
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret = 0;
//	ret = Add(a, b);
//	printf("ret = %d\n", ret);
//
//	return 0;
//}

//int main()
//{
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//	//printf("%s\n", __STDC__);
//
//	return 0;
//}


//#define定义

//#define MAX 100
//int main() 
//{
//	int m = MAX;
//
//	return 0;
//}
//
//#define INT int 
//int main()
//{
//	int a = 10;
//	INT b = 10;
//
//	return 0;
//}

//1.
//#define a 10
//int main()
//{
//	printf("%d\n", 100;);
//	return 0;
//}
//

//2.
//#define MAX 100;
//int main()
//{
//	int a = 0;
//	if (1)
//		a = MAX;
//	else
//		b = 10;
//	return 0;
//}

//
//#define SQUARE(x) x*x
//
//int main()
//{
//	int ret = SQUARE(5 + 1);
//	printf("%d\n", ret);
//
//	return 0;
//}
//
//#define DOUBLE(x) (x)+(x)
//
//int main()
//{
//	int ret = 2 * DOUBLE(5);
//	printf("%d\n", ret);
//
//	return 0;
//}
//

//
//#define INT int
//typedef int int_t;

//#define的替换规则

//#define MAX(x,y) ((x)>(y)?(x):(y))
//#define ADD(x,y) ((x)+(y))
//int main()
//{
//	int ret = ADD(10,MAX(10,20));
//	printf("%d\n", ret);
//
//	return 0;
//}

//#和##

//#define PRINT(n) printf("The value of "#n" is %d\n",n)
//int main()
//{
//	int a = 10;
//	printf("The value of a is %d\n", a);
//	int b = 10;
//	printf("The value of b is %d\n", b);
//	int c = 10;
//	printf("The value of c is %d\n", c);
//
//	printf("Hello world\n");
//	printf("Hello ""world\n");
//
//	PRINT(a);
//
//	return 0;
//}

//#define CAT(x,y) x##y
//int main()
//{
//	int class102 = 100;
//	
//	printf("%d\n", CAT(class,102));
//	
//	printf("%d\n", CAT(1, 0));
//	
//	CAT(class, 102) = 1000;
//	printf("%d\n", CAT(class, 102));
//
//	printf("%s\n", CAT("111", "111"));
//  return 0;
//}

//副作用的宏参数
 
//int main()
//{
//
//	int a = 1;
//	int b = 0;
//	
//	b = a + 1;
//	b = a++;
//
//	return 0;
//}

//
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//
//int main()
//{
//	int a = 20;
//	int b = 10;
//	int m = MAX(a++, b++);
//	//(a++)>(b++)?(a++):(b++)
//	// 20    10    21
//	// 21    11    22
//
//
//	return 0;
//}

//#undef

//#define MAX 100
//int main()
//{
//	int a = MAX;
//	
//#undef MAX
//	//int b = MAX;Err
//
//	return 0; 
//}


//条件编译

//#if&#endif

//int main()
//{
//
//#if 1
//	printf("haha\n");
//#endif
//
//#if 0 
//	printf("hehe\n");
//#endif
//
//	return 0;
//}

//int main()
//{
//#if 1==2
//	printf("hehe\n");
//#elif 2==3
//	printf("haha\n");
//#else
//	printf("...\n");
//
//#endif 
//
//	return 0;
//}

//#define MAX 100
//int main()
//{
//#if defined (MAX)
//	printf("haha\n");
//#endif
//
//#ifdef MAX
//	printf("hehe\n");
//#endif
//
//
//#if !defined (MAX)
//	printf("dada\n");
//#endif
//
//#ifndef MAX
//	printf("titi\n");
//#endif
//
//	return 0;
//}
//

//#define SBL 100
//#define OPTION 100
//int main()
//{
//#if defined (SBL1)
//	#ifdef OPTION1
//		printf("hehe\n");
//	#endif
//	#ifdef OPTION2
//		printf("haha\n");
//	#endif
//#elif defined (SBL2)
//	#ifdef OPTION3
//		printf("dada\n");
//	#endif
//	#ifdef OPTION4
//		printf("titi\n");
//	#endif
//#endif
//
//	return 0;
//}



