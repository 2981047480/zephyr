#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int  k;
	float sum,i,j;
	k = 1;
	sum = 0;
	for (i = 1; i <= 100; i++)
	{
		j = 1.0 / i;
		sum = sum + j * k;
		k = -k;
	}
	printf("%f\n", sum);
	system("pause");
	return 0;
}