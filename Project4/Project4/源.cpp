#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	system("color f5");
	int n, sum, i, flag;
	sum = 0;
	scanf_s("%d", &n);
	for (i=0;i<=n;i++)
	{
		flag = pow(-1, i - 1);
		int(flag);
		sum = sum + i * pow(-1, i - 1);
	}
	printf("%d", sum);
	system("pause");
	return 0;
}