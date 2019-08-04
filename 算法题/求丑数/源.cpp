#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int num;
	printf("请输入要判断的数\n");
	scanf("%d", &num);
	while (true)
	{
		if (num == 1)
		{
			printf("True\n");
			system("pause");
			return 0;
		}
		else
		{
			if (num % 2 == 0)
			{
				num = num / 2;
			}
			else if (num % 3 == 0)
			{
				num = num / 3;
			}
			else if (num % 5 == 0)
			{
				num = num / 5;
			}
			else
			{
				printf("False\n");
				system("pause");
				return 0;
			}
		}
	}
}