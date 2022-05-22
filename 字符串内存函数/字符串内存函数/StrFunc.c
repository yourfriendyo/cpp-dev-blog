#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

//长度不受限制的字符串函数

/*
*
* strlen
* */

int main()
{
	char arr1[] = "abcd";
	printf("%d\n", strlen(arr1));
	char arr2[] = { 'a','b','c','d' };
	printf("%d\n", strlen(arr2));
	int a = 10;
	printf("%d\n", strlen(a));

	return 0;
}

int main() 
{
	size_t ret = strlen("abcdef");
	printf("%u\n", ret);


	return 0;
}



int main()
{
	if (strlen("abc") - strlen("abcdef") < 0) {
		printf("hehe\n");
	}
	else {
		printf("haha\n");
	}

}

//1.
size_t my_strlen(const char* p) {
	assert(p);
	size_t count = 0;
	while (*p) {
		count++;
		p++;
	}
	return count;
}
//2.
size_t my_strlen(const char* p) {
	assert(p);
	char* begin = p;
	while (*p) {
		p++;
	}
	return p - begin;
}
//3.
size_t my_strlen(const char* p) {
	if (*p) {
		return 1 + my_strlen(p + 1);
	}
	else {
		return 0;
	}
}
int main()
{
	char* p = "abcdef";
	printf("%u\n", my_strlen(p));

	return 0;

}




/*
*
* strcpy
* */


int main()
 {
	char arr1[] = "xxxxxxx";
	//char arr2[] = "abcd\0s";
	char arr2[] = { 'a','b','c' };

	strcpy(arr1, arr2);

	return 0;
}



int main()
{
	//1.
	char arr1[] = "xxx";//目标空间不够大
	char arr2[] = "abcdef";
	//.2
	const char arr1[] = "xxxxxxxxxx";//目标空间不可修改
	char arr2[] = "abcdef";

	strcpy(arr1, arr2);

	return 0;
}

char* my_strcpy(char* dest, const char* src) {
	char* begin = dest;
	assert(dest && src);
	while (*dest++ = *src++) {
		;
	}
	return begin;
}
int main() {
	char arr1[] = "xxxxxxx";
	char* pc = "hello";

	my_strcpy(arr1, pc);

	printf("%s\n", arr1);
	return 0;
}



/*
*
* strcat
* */


int main()
{
	char arr1[20] = "abc";
	char arr2[] = { 'a','b','c' };
	strcat(arr1, arr2);
	
	printf("%s\n", arr1);
	return 0;
}


int main()
{
	char arr1[8] = "abc";
	strcat(arr1, "def");

	printf("%s\n", arr1);
	return 0;
}

char* my_strcat(char* dest, const char* src) {
	assert(dest && src);
	char* begin = dest;
	//移到末尾
	while (*dest) {
		dest++;
	}
	//追加
	while (*dest++ = *src++) {
		;
	}
	return begin;
}
int main()
{
	char arr1[10] = "abc";
	char arr2[] = "def";
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	

	return 0;
}



/*
*
* strcmp
* */

int my_strcmp(const char* str1, const char* str2) {
	assert(str1 && str2);
	while (*str1 == *str2) {
		if (*str1 == '\0') {
			return 0;
		}
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int my_strcmp(const char* s1, const char* s2)
{
	assert(s1 && s2);

	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
	}

	return *s1 - *s2;
}

int main()
{
	char arr1[] = "abc";
	char arr2[] = "abcaa";
	int ret = my_strcmp(arr1, arr2);
	printf("%d\n", ret);

	return 0;
}




/*
* 
* strncpy
* */

char* my_strncpy(char* dest, const char* src, size_t count) {
	assert(dest && src);
	char* begin = dest;
	
	//1.
	//while (count && *src) {
	//  *dest++ = *src++;
	//	count--;
	//}
	//2.
	//while (count && (*dest++ = *src++)) {
	//	count--;
	//}
	//3.
	while (count-- && (*dest++ = *src++)) {
		;
	}
	while (count) {
		*dest++ = '\0';
		count--;
	}
	return begin;
}
int main()
{
	char arr1[10] = "abcdef";
	char arr2[] = "xxx";
	
	my_strncpy(arr1, arr2, 5);
	printf("%s\n", arr1);
 
	return 0;
}




/*
* 
* strncat
* */

char* my_strncat(char* dest, const char* src, size_t count) {
	assert(dest && src);
	char* begin = dest;
	//1. 来到目标字符串末尾
	while (*dest) {
		dest++;
	}
	//2. 追加
	while (count && (*dest++ = *src++)) {
		count--;
	}
	//3. count小于字符个数补0
	if (count == 0) {
		*dest = '\0';
	}
	return begin;
}
int main() 
{
	char arr1[10] = "abc\0xxxxx";
	char arr2[] = "def";
	
	my_strncat(arr1, arr2, 6);
	printf("%s\n", arr1);

	return 0;
}



/*
* 
* strncmp
* */

int my_strncmp(const char* str1, const char* str2, size_t count) {
	while (count-- && (*str1 == *str2)) {
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
int main()
{
	char arr1[] = "abcdqf";
	char arr2[] = "abcdq";
	
	int ret = my_strncmp(arr1, arr2, 2);
	printf("%d\n", ret);

	return 0;
}



/*
* 
* strstr
* */

char* my_strstr(const char* str, const char* set) {
	assert(str && set);
	char* s1 = str;
	char* s2 = set;
	//特殊情况 - set=\0
	//if (*s2 == '\0') {
	//	return s1;
	//}
	while (*s1) {
		//归位 - 一定放在判断上面
		str = s1; 
		set = s2;
		//防止s1=s1=\0 - 字符串末尾时
		while ((*str != '\0' && *set != '\0') && (*str == *set)) {
			str++;
			set++;
		}		
		//判断
		if (*set == '\0') {
			return s1;
		}
		//进位
		s1++;
	}
	return NULL;
}
int main()
{
	char arr1[] = "adcaadmyyds";
	//char arr2[] = "adm";
	char arr2[] = "\0yyds";
	
	char* ret = my_strstr(arr1, arr2);
	printf("%s\n", ret);

	return 0;
}




/*
* 
* strtok
* */

//yourfriendyo@ms.com
//www.yourfriendyo.top
//192.168.12.1

int main()
{
	char arr1[] = "yourfriendyo@ms.com";
	char arr2[] = "www.yourfriendyo.top";
	char arr3[] = "192.168.12.1";

	printf("%s  ", strtok(arr1, "@."));
	printf("%s  ", strtok(NULL, "@."));
	printf("%s\n", strtok(NULL, "@."));
	putchar(10);

	printf("%s  ", strtok(arr2, "."));
	printf("%s  ", strtok(NULL, "."));
	printf("%s\n", strtok(NULL, "."));
	putchar(10);

	printf("%s  ", strtok(arr3, "."));
	printf("%s  ", strtok(NULL, "."));
	printf("%s  ", strtok(NULL, "."));
	printf("%s\n", strtok(NULL, "."));

	return 0;
}

int main()
{
	char arr[] = "yourfriendyo@ms.com";
	char* sep = "@.";
	for (char* i = strtok(arr, sep); i != NULL; i = strtok(NULL, sep)) {
		printf("%s\n", i);
	}

	return 0;
}




/*
* 
* strerror
* */

int main()
{
	printf("%s\n", strerror(40));//Function not implemented
	printf("%s\n", strerror(30));//Read - only file system
	printf("%s\n", strerror(20));//Not a directory
		
	return 0;
}

int main()
{
	FILE* pFile = fopen("D:test.txt", "r");
	if (pFile == NULL) {
		//text.txt: No such file or directory
		printf("text.txt: %s\n", strerror(errno));
		perror("text.txt");
	}

	return 0;
}
