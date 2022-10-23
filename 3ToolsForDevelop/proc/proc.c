#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
#define NUM 100
	char bar[NUM] = {'\0'};
	char* circle = "|/-\\|/_";
	int i = 0;
	while (i <= 100) {
		printf("[%s][%-3d%%][%c]\r", bar, i, circle[i%7]);
		memset(bar, '#', i);
		fflush(stdout);
		usleep(100000);

		i++;
	}
	return 0;
}
