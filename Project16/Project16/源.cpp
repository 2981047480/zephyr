#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int i, j, flag, count;
	count = 0;
	for (i = 3; i < 100; i++)
	{
		flag = 0;
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			printf("%d ", i);
			count++;
			if (count % 10 == 0)
			{
				printf("\n");
			}
		}
	}
	system("pause");
	return 0;
}