#define _CRT_SECURE_NO_WARNINGS 1


/******
* 计算器实现
* 4.0
******/
//
//void Calc(int (*pf)(int,int)) {
//	int a = 0;
//	int b = 0;
//	printf("请输入操作数:>");
//	scanf("%d %d", &a, &b);
//	printf("%d\n", pf(a, b));
//}
//int main() {
//	int input = 0;
//	do {
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input) {
//		case 0:
//			printf("退出成功\n");
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
//			printf("请重新选择\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}
//

/******
* 计算器实现
* 3.0
******/
//void Call(int(*pfArr[10](int, int)),int input) {
//	int a = 0;
//  int b = 0;
//	printf("请输入操作数:>");
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
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input) {
//		case 0:
//			printf("退出成功\n");
//			break;
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//			Call(pfArr，input);
//			break;
//		default:
//			printf("请重新选择\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}
//

/******
* 计算器实现
* 2.0
******/
//int main() {
//
//	int (*pfArr[10]) (int, int) = { 0,Add,Sub,Mul,Div };//数组下标和选项序号匹配
//	//							    0  1   2   3   4
//	int input = 0;
//	int a = 0;
//	int b = 0;
//	do {
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		if (0 <= input && input <= 4) {
//			if (input == 0) {
//				printf("退出游戏\n");
//				break;
//			}
//			else {
//				printf("请输入操作数\n");
//				scanf("%d %d", &a, &b);
//				printf("ret == %d\n", pfArr[input](a, b));
//				break;
//			}
//		}
//		else {
//			printf("输入错误\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//}

/******
* 计算器实现
* 1.0
******/
//int main() {
//	int input = 0;
//	int a = 0;
//	int b = 0;
//
//	do {
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input) {
//		case 0:
//			printf("退出成功\n");
//			break;
//		case 1:
//			printf("请输入操作数:>");
//			scanf("%d %d", &a, &b);
//			printf("%d\n", Add(a, b));
//			break;
//		case 2:
//			printf("请输入操作数:>");
//			scanf("%d %d", &a, &b);
//			printf("%d\n", Sub(a, b));
//			break;
//		case 3:
//			printf("请输入操作数:>");
//			scanf("%d %d", &a, &b);
//			printf("%d\n", Mul(a, b));
//			break;
//		case 4:
//			printf("请输入操作数:>");
//			scanf("%d %d", &a, &b);
//			printf("%d\n", Div(a, b));
//			break;
//		default:
//			printf("请重新选择\n");
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
////指向函数指针数组的指针
//int main()
//{
//	//整型数组指针
//	int arr[10];
//	int(*parr)[10] = &arr;
//
//	//字符数组指针
//	char ch[10];
//	char(*pch)[10] = &ch;
//
//	//指向整型数组指针的指针
//	int(*(*pparr))[10] = &parr;
//	
//	//指向字符数组指针的指针
//	char(*(*ppch))[10] = &pch;
//
//	//函数指针
//	int (*pf)(int, int) = Add;
//	//函数指针数组
//	int (*pfArr[10])(int, int) = { Add };
//	//指向函数指针数组的指针
//	int(*(*ppfArr)[10])(int, int) = &pfArr;
//
//	return 0;
//}
//


