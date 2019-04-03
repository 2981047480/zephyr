#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	float sum, j, i,sum1,k;
	sum = 1;
	i = 1;
	while (1)
	{
		sum1 = 0;
		for (k = 1; k <= i; k++)
		{
			sum1 = sum1 + k;
		}
		j = 1 / sum1;
		if (j >= 1e-7)
		{
			sum = sum + j;
			i++; 
			j = 1 / sum1;
		}
		else
		{
			break;
		}
	}
	printf("%f\n", sum);
	system("pause");
	return 0;
}