#include<stdio.h>
#include<stdlib.h>

int main(int argc, char argv[])
{
	system("color f5");
	int n,i,j,k;
	scanf_s("%d", &n);
	for (i = 0; i <= n; i++)
	{
		k = i;
		j = n - k;
		while (k!=0)
		{
			printf(" ");
			k--;
		}
		while (j!=0)
		{
			printf("*");
			j--;
		}
		printf("\n");
	}
	system("pause");
	return 0;
}