#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i,j,k;
	for (i = 1; i <= 5; i++)
	{
		for (j=4;j>=i;j--)
		{
			printf(" ");
		}
		for (k = 1; k <= i; k=2*k-1)
		{
			printf("*");
		}
		printf("\n");/*
		j = j - 1;
		k = k + 1;*/
	}
	system("pause");
}