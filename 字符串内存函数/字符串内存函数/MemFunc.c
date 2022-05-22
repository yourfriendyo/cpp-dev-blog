#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

/*
*
* memcpy
* */

void* my_memcpy(void* dest, const void* src, size_t count) {
	assert(dest && src);
	void* begin = dest;
	while (count--) {
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return begin;
}


int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr + 2, arr, 4 * sizeof(int));
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

struct H {
	char name[20];
	int age;
	char id[20];
};
int main()
{
	struct H h = { "yourfriendyo",18,"2020313222" };
	struct H h1 = { 0 };
	my_memcpy(&h1, &h, 44);
	printf("%s\n%d\n%s\n", h1.name, h1.age, h1.id);

	return 0;
}

int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 0 };
	my_memcpy(arr2, arr1, sizeof(arr1));
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr2[i]);
	}

	return 0;
}




/*
*
* memmove
* */

void* my_memmove(void* dest, const void* src, size_t count) {
	assert(dest && src);
	char* begin = dest;
	//目标空间在原空间的后面
	if (dest > src) {
		while (count--) {
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	//目标空间在原空间的前面
	else {
		while (count--) {
			*(char*)dest = *(char*)src;
			(char*)dest += 1;
			(char*)src += 1;
		}
	}
	return begin;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//1234->3456
	my_memmove(arr + 2, arr, 4 * sizeof(int));
	//3456->1234
	my_memmove(arr, arr + 2, 4 * sizeof(int));
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}



/*
*
* memcmp
* */
int my_memcmp(const void* buf1, const void* buf2, size_t count) {
	assert(buf1 && buf2);
	while (count-- && (*(char*)buf1 == *(char*)buf2)) {
		(char*)buf1 += 1;
		(char*)buf2 += 1;
	}
	return *(char*)buf1 - *(char*)buf2;
}
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,3,4,6 };

	int ret = my_memcmp(arr1, arr2, 1 * sizeof(int));
	printf("%d\n", ret);

	return 0;
}


/*
*
* memset
* */

int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	memset(arr, 0, 6 * sizeof(int));

	return 0;
}
