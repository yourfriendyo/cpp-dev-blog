#define _CRT_SECURE_NO_WARNINGS 1



/**********************whileѭ��****************************/

//while(���ʽ)
//    ѭ�����;

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
    //break������
    //��ǰ��ֹѭ��

    while (i <= 10)
    {
        if (i == 6)
            continue;

        printf("%d ", i);
        i++;
    }
    //continue������
    //��������ѭ����ʣ�ಿ�֣�ֱ�ӽ�����һ��ѭ��

    return 0;
}

//�޸�
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


//����

//getchar - �Ӽ��̻�ȡ�ַ�
//putchar - ���ַ���ӡ����Ļ
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
    printf("����������>:");
    scanf("%s", password);

    printf("��ȷ������(Y/N):>");

    //����\n
    //getchar();//ֻ������һ���ַ�
    while ((ch = getchar()) != '\n')
    {
        ;
    }

    ch = getchar();
    //getchar/scanf  -  ���뻺����  -  ����

    if (ch == 'Y')
        printf("ȷ�ϳɹ�\n");
    else
        printf("ȷ��ʧ��\n");


    //EOF - end of file �ļ�������־

    //1.�����ַ���ACSII��ֵ
    //2.getchar��ȡʧ�ܷ���EOF��EOF��Ϊ-1
    //���Դ�������ͱ�����

    return 0;
}


//ֻ��ӡ�����ַ�
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



/******************************forѭ��********************************/

int main()
{
    int i = 1;//��ʼ������
    //...
    while (i <= 10)//�жϲ���
    {
        //...
        printf("%d ", i);

        //...
        i++;//��������
    }

    return 0;
}
// 
//�������ַ��룬�����ң��޸�ʱ�����������



//for (���ʽ1, ���ʽ2, ���ʽ3)
//    ѭ�����;

//���ʽ1���ʽ1Ϊ��ʼ�����֣����ڳ�ʼ��ѭ�������ġ�
//���ʽ2���ʽ2Ϊ�����жϲ��֣������ж�ѭ��ʱ����ֹ��
//���ʽ3���ʽ3Ϊ�������֣�����ѭ�������ĵ�����

int main()
{
    int i = 0;

    for (i = 1; i <= 10; i++)
    {
        printf("%d ", i);
    }

    return 0;
}


//forѭ���е�break
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


//forѭ����continue
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

//continue����forѭ���ĵ������֣�����ѭ�������������������ѭ��


//����

//1.������forѭ�������޸�ѭ����������ֹforѭ��ʧȥ���ơ�
int main()
{
    int i = 0;
    for (i = 1; i <= 10; i++)
    {
        if (i = 5)//ѭ�������޸�ѭ������
            printf("%d ", i);
    }

    return 0;
}

//ѭ�������޸�ѭ�������������ѭ��

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


//2.����for����ѭ�����Ʊ�����ȡֵ����"����ҿ�"д����

int main()
{
    int i = 0;
    int arr[20] = { 0 };//0~9

    for (i = 0; i < 10; i++)//����ҿ�
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 10; i++)//����ҿ�
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

//forѭ������


int main()
{
    int i = 0;
    int j = 0;
    //��ʼ�����жϣ��������ֶ���ʡ��
    //�жϲ���ʡ�ԣ���ζ���жϺ�Ϊ��
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
    //ʡ������ѭ�������ĳ�ʼ��
    //��ѭ����һ���jһֱ����10�Ͳ�������ѭ����

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


//һ��������

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

//k=0,�жϲ���������Ϊ�٣�ѭ��0��



/***********************do..while****************************/

//do
//{
//	ѭ�����;
//}while(���ʽ)

//�ص�
//��ִ�У����ж�
//����ִ��һ��


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
//��ѭ��

/***************************��ϰ*******************************/

//��װ�׳˺���
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


//��װ�׳���ͺ��� 
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
//�޸ĺ�
int sum_on_factorial2()
{
    int n = 0;
    int pro = 1;
    int sum = 0;
    for (n = 1; n <= 10; n++)
    {
        //�����pro�Ͳ��ó�ʼ����
        pro *= n;
        sum += pro;
    }
    return sum;
}


//��װ�����������Ԫ�غ���
void findkey()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int key = 7;
    //�����鳤��
    int sz = sizeof(arr) / sizeof(arr[0]);

    //��������
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        if (arr[i] == key)
        {
            printf("�ҵ��ˣ��±���%d\n", i);
            break;
        }
    }
    if (i == sz)
    {
        printf("�Ҳ���\n");
    }

    //���ֲ���
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
            printf("�ҵ��ˣ��±�Ϊ%d\n", mid);
            break;
        }
    }
    if (left > right)
        printf("û�ҵ�\n");
}


//��ʾһ�д���������ƶ������м���
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


//ģ���û���¼�龰
#include <string.h>
int followsignup()
{
    int i = 0;
    char password[20] = { 0 };
    //��������Ϊabcdef
    for (i = 0; i < 3; i++)
    {
        printf("����������:>\n");
        scanf("%s", password);

        if (strcmp(password, "abcdef") == 0)
            //�ַ����ȽϺ���
        {
            printf("������ȷ\n");
            break;
        }
        else
        {
            printf("���������������������\n");
        }
    }
    if (i == 3)
    {
        printf("������������˳�ϵͳ\n");
    }
    else
    {
        printf("��¼�ɹ�\n");
    }

    return 0;
}
/*******************goto���**************************/
//��������goto�����û�б�Ҫ�ģ�һ����˵��goto���ĵط�Ҳ������ѭ�����档
//�䳣���÷�����ʹ�����ڸ������Ƕ�׵Ĵ�����һ������������breakһ��ֻ������һ�ε�ѭ����

int main()
{
again:

    //...
    goto again;

    return 0;

}
//�ػ�����
#include <windows.h>
int Shutdown()
{
    char input[20] = { 0 };
    system("shutdown -s -t 60");
    printf("��ĵ��Խ���60s�ڹػ�����������������ȡ���ػ�\n");
again:
    scanf("%s", input);
    if (strcmp(input, "������") == 0)
    {
        system("shutdown -a");
    }
    else
    {
        goto again;
    }

    return 0;
}
