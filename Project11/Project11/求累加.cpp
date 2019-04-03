#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i, sum,sum1;
	sum = 0;
	sum1 = 0;
	for (i = 0; i < 100; i++)
	{
		sum = sum + i;
		sum1 = sum + sum1;
	}
	printf("%d", sum1);
	system("pause");
	return 0;
}