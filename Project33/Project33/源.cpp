#include<stdio.h>
#include<stdlib.h>
//头文件
int sum(int n);
//函数声明
int main(int argc, char argv[])
{
	int n;
	scanf_s("%d", &n);
	printf("%d",sum(n));
	system("pause");
	return 0;
}

int sum(int n)
{
	int s=1;
	if (n == 1)
	{
		s = 1;
	}
	else
	{
		s = n * sum(n - 1);
	}
	return s;
}