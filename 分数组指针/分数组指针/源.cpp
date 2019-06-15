#include<stdio.h>
#include<stdlib.h>

int p(int a,int b);
int q(int a,int b);
int com(int a,int b);

int main()
{
	int a, b;
	printf("please enter a and b\n");
	scanf_s("%d%d", &a, &b);
	int temp;
	temp = com(a, b);
	printf("%d\n", temp);
	system("pause");
	return 0;
}

int p(int a, int b)
{
	int c;
	c = a + b;
	return c;
}

int q(int a, int b)
{
	int c;
	c = a - b;
	return c;
}

int com(int a, int b)
{
	int c;
	int(*temp)(int a,int b);
	if (a > b)
	{
		temp = p;
	}
	else
	{
		temp = q;
	}
	c = (*temp)(a, b);
	return c;
}