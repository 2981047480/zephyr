#include<stdio.h>
#include<stdlib.h>
//头文件

int main(int argc, char *argv[])
{
	system("color f5");
	printf("请输入楼梯数量\n");
	int n, a[1000], i, sum=0, temp;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	if (n > 3)
	{
		for (i = 0; i < n - 1; i++)
		{
			if (a[i] < a[i + 1])
			{
				temp = a[i];
			}
			else
			{
				temp = a[i + 1];
				i++;
			}
			sum += temp;
		}
	}
	else if(n==3)
	{
		if (a[1] > a[0] + a[2])
		{
			sum = a[0] + a[2];
		}
		else
		{
			sum = a[1];
		}
	}
	else if (n == 2)
	{
		if (a[0] < a[1])
		{
			sum = a[0];
		}
		else
		{
			sum = a[1];
		}
	}
	else if (n == 1)
	{
		sum = 0;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}