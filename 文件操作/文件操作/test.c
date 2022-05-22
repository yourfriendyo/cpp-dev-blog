#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
* 文件操作
* */

//文件的打开和关闭

//int main() {
//	//打开文件
//	//FILE* pf = fopen("data.txt", "w");
//	FILE* pf = fopen("C:\\Users\\w3395\\Desktop\\data.txt", "w");
//
//	//打开失败
//	if (pf == NULL) {
//		perror("fopen");
//		return -1;
//	}
//	//操作文件
//	
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//
//	return 0;
//}

//文件的顺序读写

//int main()
//{
//	FILE* pf = fopen("C:\\Users\\w3395\\Desktop\\data.txt", "w");
//	if (pf == NULL) {
//		perror("fopen");
//		return -1;
//	}
//	fputc('b', pf);
//	fputc('i', pf);
//	fputc('t', pf);
//	//fgetc();
//	fputc('b', stdout);
//	fputc('i', stdout);
//	fputc('t', stdout);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\w3395\\Desktop\\data.txt", "r");
//	if (pf == NULL) {
//		perror("fopen");
//		return -1;
//	}
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\w3395\\Desktop\\data.txt", "r+");
//	if (pf == NULL) {
//		perror("fopen");
//		return -1;
//	}
//	fputc('a', pf);
//	fputc('b', pf);
//	fputc('c', pf);
//	
//	int ch = fgetc(pf);
//	printf("%c ", ch);
//	ch = fgetc(pf);
//	printf("%c ", ch);
//	ch = fgetc(pf);
//	printf("%c ", ch);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
//int main()
//{
//	fputc('b', stdout);
//	fputc('i', stdout);
//	fputc('t', stdout);
//	
//	int ch = 0;
//	ch = fgetc(stdin);
//	printf("%c\n", ch);
//	ch = fgetc(stdin);
//	printf("%c\n", ch);
//	ch = fgetc(stdin);
//	printf("%c\n", ch);
//
//	return 0;
//}

//int main(){
//	FILE* pf = fopen("C:\\Users\\w3395\\Desktop\\data.txt", "w");
//	if (pf == NULL) {
//		perror("fopen");
//		return -1;
//	}
//	fputs("hello world!\n", pf);
//	fputs("hello bit!\n", pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
// 
//
//int main() {
//	FILE* pf = fopen("C:\\Users\\w3395\\Desktop\\data.txt", "r");
//	if (pf == NULL) {
//		perror("fopen");
//		return -1;
//	}
//	char arr[20] = { 0 };
//	fgets(arr, 5, pf);
//	printf("%s\n", arr);
//	fgets(arr, 5, pf);
//	printf("%s\n", arr);
//
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
//struct S {
//	int a;
//	char c;
//	double d;
//};
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\w3395\\Desktop\\data.txt", "w");
//	if (pf == NULL) {
//		perror("fopen");
//		return -1;
//	}
//	struct S s = { 100,'w',3.14 };
//	fprintf(pf, "%d %c %lf", s.a, s.c ,s.d);
//
//	return 0;
//}
//
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\w3395\\Desktop\\data.txt", "r");
//	if (pf == NULL) {
//		perror("fopen");
//		return -1;
//	}
//	struct S s = { 0 };
//	fscanf(pf, "%d %c %lf", &s.a, &s.c, &s.d);
//	printf("%d %c %lf", s.a, s.c, s.d);
//	return 0;
//}

//struct S {
//	int a;
//	char c[20];
//	double d;
//};
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\w3395\\Desktop\\data.txt", "wb");
//	if (pf == NULL) {
//		perror("fopen");
//		return -1;
//	}
//	struct S s = { 100,"yyx",3.14 };
//	fwrite(&s, sizeof(s), 1, pf);
//	return 0;
//}
//
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\w3395\\Desktop\\data.txt", "rb");
//	if (pf == NULL) {
//		perror("fopen");
//		return -1;
//	}
//	struct S s = { 0 };
//	fread(&s, sizeof(s), 1, pf);
//	printf("%d %s %lf", s.a, s.c, s.d);
//
//	return 0;
//}

//struct S {
//	int a;
//	char c[20];
//	double d;
//};
//int main() {
//	struct S s = { 100,"yyx",3.14 };
//	char arr[20] = { 0 };
//	sprintf(arr, "%d%s%lf", s.a, s.c, s.d);
//	
//	printf("%s\n", arr);
//
//	return 0;
//}
//int main() {
//	struct S s = { 0 };
//	char arr[20] = "100 yyx 3.14";
//	sscanf(arr, "%d %s %lf", &s.a, &s.c, &s.d);
//
//	printf("%d %s %lf", s.a, s.c, s.d);
//
//	return 0;
//}

//文件的随机读写

//int main()
//{
//	FILE* pf = fopen("C:\\Users\\w3395\\Desktop\\data.txt", "r");
//	if (pf == NULL) {
//		perror("fopen");
//		return -1;
//	}
//	printf("%c", fgetc(pf));//y
//	fseek(pf, 1, SEEK_SET);
//	printf("%c", fgetc(pf));//o
//	fseek(pf, 2, SEEK_SET);
//	printf("%c", fgetc(pf));//u
//	fseek(pf, 3, SEEK_SET);
//	printf("%c", fgetc(pf));//r
//	fseek(pf, -2, SEEK_CUR);
//	printf("%c", fgetc(pf));//u
//	fseek(pf, -2, SEEK_CUR);
//	printf("%c", fgetc(pf));//o
//	fseek(pf, -2, SEEK_CUR);
//	printf("%c", fgetc(pf));//y
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("C:\\Users\\w3395\\Desktop\\data.txt", "r");
//	if (pf == NULL) {
//		perror("fopen");
//		return -1;
//	}
//	fseek(pf, 3, SEEK_SET);
//	int ret = ftell(pf);
//	printf("%d\n", ret);
//	
//	return 0;
//}

//文件类型

//49 48 48 48 48

//int main() 
//{
//	FILE* pf = fopen("C:\\Users\\w3395\\Desktop\\data.txt", "wb+");
//	if (pf == NULL) {
//		perror("fopen");
//		return -1;
//	}
//	int a = 10000;
//	int b = 0;
//	fwrite(&a, 4, 1, pf);
//	fseek(pf, 0, SEEK_SET);
//	
//	fread(&b, 4, 1, pf);
//	printf("%d\n", b);
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//10 27 00 00 
//00000000 00000000 00100111 00010000
//00010000 00100111 00000000 00000000
//1   0    2   7    0   0    0   0



//文件缓冲区

//文件结束的判断

//int main()
//{
//	FILE* pf = fopen("C:\\Users\\w3395\\Desktop\\data.txt", "r");
//	if (pf == NULL) {
//		perror("fopen");
//		return -1;
//	}
//
//	//fgetc
//	int ch = 0;
//	while ((ch = fgetc(pf)) != EOF) {
//		printf("%c ", ch);
//	}
//	
//	//fgets
//	char arr[2][20] = { 0 };
//	while ((fgets(arr, 3, pf)) != NULL) {
//		printf("%s\n", arr);
//	}
//
//	//fscanf
//	int ch = 0;
//	while (fscanf(pf, "%c", &ch) == 1) {
//		printf("%c\n", ch);
//	}
//
//	//fread
//	int ch = 0;
//	while (fread(&ch, 1, 1, pf) == 1) {
//		printf("%c\n", ch);
//	}
//	
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



int main()
{
	FILE* pf = fopen("C:\\Users\\w3395\\Desktop\\data.txt", "r");
	if (pf == NULL) {
		perror("fopen");
		return -1;
	}
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF) {
		printf("%c ", ch);
	}
	if (feof(pf)) {
		printf("\n%s\n", "end of file reached successfully");
	}
	else {
		printf("\n%s\n", "unknowed error");
	}

	fclose(pf);
	pf = NULL;
	return 0;
}


