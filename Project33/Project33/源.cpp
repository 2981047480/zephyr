#include<stdio.h>
#include<stdlib.h>
//ͷ�ļ�
int sum(int n);
//��������
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