#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//C�����ǽṹ���ĳ����������
    //˳��ṹ
    //ѡ��ṹ if switch
    //ѭ���ṹ for while do..while


//int main()
//{
//    //���
//    printf("hehe\n");
//    ;//�����
//
//    return 0;
//}


/**************** if��� ************************/
int main()
{

    int age = 20;
    

    //�ٵ���֧
    //if (age >= 18)
    //    printf("����\n");

    //else
    //    printf("δ����\n");
    //if elseֻ����һ��������if����else
   

    //�ڶ��֧
    if (age < 18)
        printf("������\n");
    else if (age >= 18 && age < 30)
        printf("����\n");
    else if (age >= 30 && age < 50)
        printf("׳��\n");
    else if (age >= 50 && age < 80)
        printf("����\n");
    else
        printf("��û��\n");

    
    return 0;
}



//ע��

//18 <= age < 30 
int main()
{
    int age = 50;
    if (18 <= age < 30)
        printf("����\n");
    //18 <= age < 30 
    //��������Ϊ�棬�������ҿ���18 <= age������Ҫô0Ҫô1���������С��30

    return 0;
}

//�����
//��ߴ���ɶ���
//if���ƶ�����䣬ʹ�ô����
int main()
{
    int age = 10;
    if (age >= 18)
    {
        printf("������\n");
        printf("����ɱ����\n");
    }

    return 0;
}

//����else
int main()
{
    int a = 0;
    int b = 2;
    if (a == 1)
        if (b == 2)
            printf("hehe\n");
    else
        printf("haha\n");//else�����������һ��ifƥ��

    return 0;
}

//����������

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
    //��������ֵ�󣬺���Ĵ��벻ִ��
    printf("haha\n");
}

int main()
{
   test();
   
   return 0;
}

//�жϱ��ʽ��д�ɸ�ֵ���ʽ
int main()
{
    int a = 0;
    
    if (a = 5)
        printf("hehe\n");
    //��ֵ���ʽ a = 5 ������ʽ�ӵ�ֵ��Ϊ5������Ϊ�棬���hehe
    
    return 0;
}

//���1-100֮�������
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



/**********************switch���***************************/
//switch(���ͱ��ʽ)
//{
//    �����;
//}


int main()
{
    int day = 0;
    scanf("%d", &day);

    switch (day)//���ͱ��ʽ
    {
    case 1://���ͳ������ʽ
    {
        printf("����һ\n");
        printf("���õ�һ�죬���ϰ࿪ʼ5555~");
        break;
    }//switch����Լ�{}
    case 2:
        printf("���ڶ�\n");
        break;
    case 3:
        printf("������\n");
        break;
    case 4:
        printf("������\n");
        break;
    case 5:
        printf("������\n");
        break;
    case 6:
        printf("������\n");
        break;
    case 7:
        printf("������\n");
        break;

    }

    return 0;
}

//���һʱ
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
        printf("������\n");
        break;
    case 6:
    case 7:
        printf("��Ϣ��\n");
        break;
    //default�Ӿ�
    //������case��ǩ��ƥ������
    default:
        printf("����������������������\n");
        break;
    //case���������˳������
    //�������
    }

    return 0;
}



//����
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
//            //switch����Ƕ��ʹ��
//        {
//        case 1: n++;
//        case 2: n++; m++;// 4 3 
//            break;
//            //��break�������ǵڶ���switch���
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


