#include<stdio.h>
#include<stdlib.h>
//ͷ�ļ�
void fuc();
//��������

int main(int argc, char argv[])
{
	system("color f5");
	fuc();
	system("pause");
}

void fuc()
{
	int i,j,sum=0;
	for (i=1; i < 10000; i++)
	{
		sum = 0;
		for (j = 1; j < i; j++)
		{
			if (i%j == 0)
			{
				sum += j;
			}
		}
		if (sum == i)
		{
			printf("%d\n", i);
		}
	}
}