#include <stdio.h>
#include "./lib/add.h"
#include "./lib/sub.h"

int main()
{
	int x = 20;
	int y = 10;
	int ret1 = add(x, y);
	int ret2 = sub(x, y);

	printf("ret1:%d\n", ret1);
	printf("ret2:%d\n", ret2);

	return 0;
}
