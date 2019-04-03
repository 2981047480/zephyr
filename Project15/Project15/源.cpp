#include<stdio.h>
#include<stdlib.h>

int main(int argc, char argv[])
{
	int i, j;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			printf("%d*%d=%d ", i, j, i*j);
			if (j == 9)
			{
				printf("\n");
			}
		}
	}
	system("pause");
	return 0;
}