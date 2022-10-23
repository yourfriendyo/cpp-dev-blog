#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//#include <iostream>

//命名冲突
// 
// 1.1 命名空间的定义
namespace test {
	int rand = 0;
}
int main()
{
	printf("hello world\n");
	printf("%d\n", rand);
	printf("%d\n", test::rand);


	return 0;
}

int a = 0;

int main()
{
	int a = 1;
	printf("%d\n", ::a);
	return 0;
}

// 命名空间的嵌套
namespace N1 {
	int a = 0;
	int b = 0;
	int Add(int a, int b) {
		return a + b;
	}
	namespace N2 {
		int c = 0;
		int d = 0;
		int Sub(int c, int d) {
			return c - d;
		}
	}
}
int main() 
{
	N1::a = 10;
	N1::N2::c = 20;

	int ret = N1::Add(N1::a, N1::b);
	printf("%d\n", ret);

	ret = N1::N2::Sub(N1::N2::c, N1::N2::d);
	printf("%d\n", ret);
	return 0;
}

// 
// 1.2 命名空间的使用
namespace test {
    //1.
    int rand = 0;
    //2. 
    int Add(int a, int b) {
        return a + b;
    }
    //3.
    struct Node {
        int data;
        struct Node* next;
    };
}

using test::Node;

//using namespace test;
int main()
{
    rand = 1;
    Add(1, 2);
    struct Node n1;

    return 0;
}
