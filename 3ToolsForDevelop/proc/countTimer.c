#include <stdio.h>
#include <unistd.h>
int main()
{
	int n = 9;
	while (n)
	{
		printf("%d\r", n);
		fflush(stdout);
		usleep(500000);
		n--;
	}

	return 0;
}
