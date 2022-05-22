#define _CRT_SECURE_NO_WARNINGS 1



/**********************while循环****************************/

//while(表达式)
//    循环语句;

int main()
{

    int i = 0;

    while (i <= 10)
    {
        if (i == 6)
            break;

        printf("%d ", i);
        i++;
    }
    //break的作用
    //提前终止循环

    while (i <= 10)
    {
        if (i == 6)
            continue;

        printf("%d ", i);
        i++;
    }
    //continue的作用
    //跳过本次循环的剩余部分，直接进行下一次循环

    return 0;
}

//修改
int main()
{
    int i = 0;
    while (i <= 10)
    {
        i++;
        if (i == 6)
            continue;

        printf("%d ", i);//1 2 3 4 5 7 8 9 10 11
    }

    return 0;
}


//特例

//getchar - 从键盘获取字符
//putchar - 把字符打印到屏幕
int main()
{
    int ch = 0;
    while ((ch = getchar()) != EOF)
        putchar(ch);
    return 0;
}

int main()
{
    int ch = 0;
    char password[20] = { 0 };
    printf("请输入密码>:");
    scanf("%s", password);

    printf("请确认密码(Y/N):>");

    //清理\n
    //getchar();//只能清理一个字符
    while ((ch = getchar()) != '\n')
    {
        ;
    }

    ch = getchar();
    //getchar/scanf  -  输入缓冲区  -  键盘

    if (ch == 'Y')
        printf("确认成功\n");
    else
        printf("确认失败\n");


    //EOF - end of file 文件结束标志

    //1.返回字符的ACSII码值
    //2.getchar读取失败返回EOF，EOF即为-1
    //所以存放在整型变量中

    return 0;
}


//只打印数字字符
int main()
{
    int ch = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch < '0' || ch > '9')
            continue;
        putchar(ch);
    }

    return 0;
}



/******************************for循环********************************/

int main()
{
    int i = 1;//初始化部分
    //...
    while (i <= 10)//判断部分
    {
        //...
        printf("%d ", i);

        //...
        i++;//调整部分
    }

    return 0;
}
// 
//三个部分分离，不好找，修改时容易引起错误



//for (表达式1, 表达式2, 表达式3)
//    循环语句;

//表达式1表达式1为初始化部分，用于初始化循环变量的。
//表达式2表达式2为条件判断部分，用于判断循环时候终止。
//表达式3表达式3为调整部分，用于循环条件的调整。

int main()
{
    int i = 0;

    for (i = 1; i <= 10; i++)
    {
        printf("%d ", i);
    }

    return 0;
}


//for循环中的break
int main()
{
    int i = 0;
    for (i = 1; i <= 10; i++)
    {
        if (i == 5)
            break;
        printf("%d ", i);//1 2 3 4 
    }

    return 0;
}


//for循环的continue
int main()
{
    int i = 0;

    for (i = 1; i <= 10; i++)
    {
        if (i == 5)
            continue;
        printf("%d ", i);//1 2 3 4 6 7 8 9 10 
    }

    return 0;
}

//continue跳到for循环的调整部分，调整循环变量，不容易造成死循环


//建议

//1.不可在for循环体内修改循环变量，防止for循环失去控制。
int main()
{
    int i = 0;
    for (i = 1; i <= 10; i++)
    {
        if (i = 5)//循环体内修改循环变量
            printf("%d ", i);
    }

    return 0;
}

//循环体内修改循环变量，造成死循环

int main()
{
    int i = 0;
    for (i = 1; i <= 10; i++)
    {
        printf("%d ", i);
        i++;
    }

    return 0;
}


//2.建议for语句的循环控制变量的取值采用"左闭右开"写法。

int main()
{
    int i = 0;
    int arr[20] = { 0 };//0~9

    for (i = 0; i < 10; i++)//左闭右开
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 10; i++)//左闭右开
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

//for循环变种


int main()
{
    int i = 0;
    int j = 0;
    //初始化，判断，调整部分都可省略
    //判断部分省略，意味着判断恒为真
    for (i = 0;; i++)
    {
        printf("%d ", i);
    }
    for (; i < 10; i++)
    {
        for (; j < 10; j++)
        {
            printf("hehe\n");
        }
    }
    //省略了内循环变量的初始化
    //外循环第一遍后，j一直保持10就不进行内循环了

    return 0;
}

int main()
{
    int x = 0;
    int y = 0;
    for (x = 0, y = 0; x < 5 && y < 7; x++, y++)
    {
        printf("hehe\n");
    }

    return 0;
}


//一道笔试题

int main()
{
    int i = 0;
    int k = 0;
    for (i = 0, k = 0; k = 0; i++, k++)
    {
        k++;
    }

    return 0;
}

//k=0,判断部分条件恒为假，循环0次



/***********************do..while****************************/

//do
//{
//	循环语句;
//}while(表达式)

//特点
//先执行，再判断
//至少执行一次


//break,continue

int main()
{
    int i = 1;

    do
    {
        if (i == 5)
            break;
        printf("hehe\n");
        i++;

    } while (i < 10);

    return 0;
}

int main()
{
    int i = 1;

    do
    {
        if (i == 5)
            continue;
        printf("hehe\n");
        i++;

    } while (i < 10);

    return 0;
}
//死循环

/***************************练习*******************************/

//封装阶乘函数
int factorial()
{
    int n = 0;
    int i = 1;
    int pro = 1;
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        pro *= i;
    }
    return pro;
}


//封装阶乘求和函数 
int sum_on_factorial()
{
    int i = 0;
    int n = 0;
    int pro = 1;
    int sum = 0;
    for (n = 1; n <= 10; n++)
    {
        pro = 1;
        for (i = 1; i <= n; i++)
        {
            pro *= i;
        }
        sum += pro;
    }
    return sum;
}
//修改后
int sum_on_factorial2()
{
    int n = 0;
    int pro = 1;
    int sum = 0;
    for (n = 1; n <= 10; n++)
    {
        //这里的pro就不用初始化了
        pro *= n;
        sum += pro;
    }
    return sum;
}


//封装有序数组查找元素函数
void findkey()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int key = 7;
    //求数组长度
    int sz = sizeof(arr) / sizeof(arr[0]);

    //遍历数组
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        if (arr[i] == key)
        {
            printf("找到了，下标是%d\n", i);
            break;
        }
    }
    if (i == sz)
    {
        printf("找不到\n");
    }

    //二分查找
    int left = 0;
    int right = sz - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] > key)
        {
            right = mid - 1;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            printf("找到了，下标为%d\n", mid);
            break;
        }
    }
    if (left > right)
        printf("没找到\n");
}


//演示一行代码从两端移动，向中间汇聚
#include <string.h>
#include <windows.h>
#include <stdlib.h>
int string_move()
{
    char arr1[] = "happy birthday to you!!!";
    char arr2[] = "########################";

    int len = strlen(arr1);
    int left = 0;
    int right = len - 1;

    while (left <= right)
    {
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        printf("%s\n", arr2);

        Sleep(500);//1000ms
        system("cls");

        left++;
        right--;
    }
    printf("%s\n", arr2);

    return 0;
}


//模拟用户登录情景
#include <string.h>
int followsignup()
{
    int i = 0;
    char password[20] = { 0 };
    //假设密码为abcdef
    for (i = 0; i < 3; i++)
    {
        printf("请输入密码:>\n");
        scanf("%s", password);

        if (strcmp(password, "abcdef") == 0)
            //字符串比较函数
        {
            printf("密码正确\n");
            break;
        }
        else
        {
            printf("密码输入错误，请重新输入\n");
        }
    }
    if (i == 3)
    {
        printf("三次输入错误，退出系统\n");
    }
    else
    {
        printf("登录成功\n");
    }

    return 0;
}
/*******************goto语句**************************/
//从理论上goto语句是没有必要的，一般来说用goto语句的地方也可以用循环代替。
//其常见用法就是使程序在各种深层嵌套的代码中一次性跳出来，break一般只能跳出一次的循环。

int main()
{
again:

    //...
    goto again;

    return 0;

}
//关机程序
#include <windows.h>
int Shutdown()
{
    char input[20] = { 0 };
    system("shutdown -s -t 60");
    printf("你的电脑将于60s内关机，若输入我是猪，则取消关机\n");
again:
    scanf("%s", input);
    if (strcmp(input, "我是猪") == 0)
    {
        system("shutdown -a");
    }
    else
    {
        goto again;
    }

    return 0;
}
