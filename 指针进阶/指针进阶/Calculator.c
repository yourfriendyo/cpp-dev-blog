#define _CRT_SECURE_NO_WARNINGS 1


/******
* ������ʵ��
* 4.0
******/
//
//void Calc(int (*pf)(int,int)) {
//	int a = 0;
//	int b = 0;
//	printf("�����������:>");
//	scanf("%d %d", &a, &b);
//	printf("%d\n", pf(a, b));
//}
//int main() {
//	int input = 0;
//	do {
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		switch (input) {
//		case 0:
//			printf("�˳��ɹ�\n");
//			break;
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		default:
//			printf("������ѡ��\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}
//

/******
* ������ʵ��
* 3.0
******/
//void Call(int(*pfArr[10](int, int)),int input) {
//	int a = 0;
//  int b = 0;
//	printf("�����������:>");
//	scanf("%d %d", &a, &b);
//	printf("%d\n", pfArr[input](a, b));
//}
//
//
//int main() {
//	int (*pfArr[10])(int, int) = { 0,Add,Sub,Mul,Div };
//	int input = 0;
//	do {
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		switch (input) {
//		case 0:
//			printf("�˳��ɹ�\n");
//			break;
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//			Call(pfArr��input);
//			break;
//		default:
//			printf("������ѡ��\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}
//

/******
* ������ʵ��
* 2.0
******/
//int main() {
//
//	int (*pfArr[10]) (int, int) = { 0,Add,Sub,Mul,Div };//�����±��ѡ�����ƥ��
//	//							    0  1   2   3   4
//	int input = 0;
//	int a = 0;
//	int b = 0;
//	do {
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		if (0 <= input && input <= 4) {
//			if (input == 0) {
//				printf("�˳���Ϸ\n");
//				break;
//			}
//			else {
//				printf("�����������\n");
//				scanf("%d %d", &a, &b);
//				printf("ret == %d\n", pfArr[input](a, b));
//				break;
//			}
//		}
//		else {
//			printf("�������\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//}

/******
* ������ʵ��
* 1.0
******/
//int main() {
//	int input = 0;
//	int a = 0;
//	int b = 0;
//
//	do {
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		switch (input) {
//		case 0:
//			printf("�˳��ɹ�\n");
//			break;
//		case 1:
//			printf("�����������:>");
//			scanf("%d %d", &a, &b);
//			printf("%d\n", Add(a, b));
//			break;
//		case 2:
//			printf("�����������:>");
//			scanf("%d %d", &a, &b);
//			printf("%d\n", Sub(a, b));
//			break;
//		case 3:
//			printf("�����������:>");
//			scanf("%d %d", &a, &b);
//			printf("%d\n", Mul(a, b));
//			break;
//		case 4:
//			printf("�����������:>");
//			scanf("%d %d", &a, &b);
//			printf("%d\n", Div(a, b));
//			break;
//		default:
//			printf("������ѡ��\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}


//int Add(int x, int y) {
//	return x + y;
//}
//
//
////ָ����ָ�������ָ��
//int main()
//{
//	//��������ָ��
//	int arr[10];
//	int(*parr)[10] = &arr;
//
//	//�ַ�����ָ��
//	char ch[10];
//	char(*pch)[10] = &ch;
//
//	//ָ����������ָ���ָ��
//	int(*(*pparr))[10] = &parr;
//	
//	//ָ���ַ�����ָ���ָ��
//	char(*(*ppch))[10] = &pch;
//
//	//����ָ��
//	int (*pf)(int, int) = Add;
//	//����ָ������
//	int (*pfArr[10])(int, int) = { Add };
//	//ָ����ָ�������ָ��
//	int(*(*ppfArr)[10])(int, int) = &pfArr;
//
//	return 0;
//}
//


