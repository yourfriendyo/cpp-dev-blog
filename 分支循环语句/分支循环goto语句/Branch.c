#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//C语言是结构化的程序设计语言
    //顺序结构
    //选择结构 if switch
    //循环结构 for while do..while


//int main()
//{
//    //语句
//    printf("hehe\n");
//    ;//空语句
//
//    return 0;
//}


/**************** if语句 ************************/
int main()
{

    int age = 20;
    

    //①单分支
    //if (age >= 18)
    //    printf("成年\n");

    //else
    //    printf("未成年\n");
    //if else只能走一个，不是if就是else
   

    //②多分支
    if (age < 18)
        printf("青少年\n");
    else if (age >= 18 && age < 30)
        printf("青年\n");
    else if (age >= 30 && age < 50)
        printf("壮年\n");
    else if (age >= 50 && age < 80)
        printf("老年\n");
    else
        printf("快没了\n");

    
    return 0;
}



//注意

//18 <= age < 30 
int main()
{
    int age = 50;
    if (18 <= age < 30)
        printf("青年\n");
    //18 <= age < 30 
    //该条件恒为真，从左向右看，18 <= age该条件要么0要么1，所以其恒小于30

    return 0;
}

//代码块
//提高代码可读性
//if控制多条语句，使用代码块
int main()
{
    int age = 10;
    if (age >= 18)
    {
        printf("成年了\n");
        printf("可以杀人了\n");
    }

    return 0;
}

//悬空else
int main()
{
    int a = 0;
    int b = 2;
    if (a == 1)
        if (b == 2)
            printf("hehe\n");
    else
        printf("haha\n");//else与其上最近的一个if匹配

    return 0;
}

//特例代码风格

//if(condition)
//return x;
//return y;

void test()
{
    if (1)
    {
        printf("hehe\n");
        return 0;
    }
    //函数返回值后，后面的代码不执行
    printf("haha\n");
}

int main()
{
   test();
   
   return 0;
}

//判断表达式误写成赋值表达式
int main()
{
    int a = 0;
    
    if (a = 5)
        printf("hehe\n");
    //赋值表达式 a = 5 ，整个式子的值就为5，条件为真，输出hehe
    
    return 0;
}

//输出1-100之间的奇数
int main()
{
    int i = 0;

    while (i <= 100)
    {
        if (i % 2 == 0)
            printf("%d ", i);
        i++;
    }

    for (i = 0; i < 100; i++)
    {
        if (i % 2 == 1)
        {
            printf("%d ", i);
        }
    }


    return 0;
}



/**********************switch语句***************************/
//switch(整型表达式)
//{
//    语句项;
//}


int main()
{
    int day = 0;
    scanf("%d", &day);

    switch (day)//整型表达式
    {
    case 1://整型常量表达式
    {
        printf("星期一\n");
        printf("美好的一天，从上班开始5555~");
        break;
    }//switch里可以加{}
    case 2:
        printf("星期二\n");
        break;
    case 3:
        printf("星期三\n");
        break;
    case 4:
        printf("星期四\n");
        break;
    case 5:
        printf("星期五\n");
        break;
    case 6:
        printf("星期六\n");
        break;
    case 7:
        printf("星期日\n");
        break;

    }

    return 0;
}

//多对一时
int main()
{
    int day = 0;
    scanf("%d", &day);
    switch (day)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        printf("工作日\n");
        break;
    case 6:
    case 7:
        printf("休息日\n");
        break;
    //default子句
    //与所以case标签不匹配的情况
    default:
        printf("输入数据有误，请重新输入\n");
        break;
    //case情况不存在顺序问题
    //随便排序
    }

    return 0;
}



//例题
//int main()
//{
//    int n = 1;
//    int m = 2;
//    switch (n)
//    {
//    case 1: m++;// 3 1
//    case 2: n++;// 3 2
//    case 3:
//        switch (n)
//            //switch允许嵌套使用
//        {
//        case 1: n++;
//        case 2: n++; m++;// 4 3 
//            break;
//            //此break跳出的是第二个switch语句
//        }
//    case 4: m++;//5 3
//        break;
//    default:
//        break;
//    }
//    printf("m = %d, n = %d", m, n);//m = 5, n = 3
//
//    return 0;
//}


