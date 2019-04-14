#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[])
{
	system("color f5");
	int a[3][4],b[3][4];
	int i, j;
	while (1)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 4; j++)
			{
				a[i][j] = rand();
				srand(time(NULL));
				b[i][j] = rand();
				srand(time(NULL));
			}
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 4; j++)
			{
				a[i][j] = a[i][j] + b[i][j];
				printf("%d ", a[i][j]);
				if (j == 3)
				{
					printf("\n");
				}
			}
		}
		system("pause");
	}
}