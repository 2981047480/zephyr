#include<stdio.h>
#include<stdlib.h>

void helper(int i, int n, int k);

int main(int argc, char argv[])
{
	system("color f5");
	int n, k;
	printf("请输入长度n\n");
	scanf_s("%d", &n);
	printf("请输入k\n");
	scanf_s("%d", &k);
	for (int i = 1; i <= 9; i++)
	{
		helper(i, n, k);
	}
	system("pause");
}

void helper(int i, int n, int k)
{
	if (n==1) //当n=1的时候跳出
	{
		printf("%d\n", i);
		return;
	}
	int last = i % 10;//这里第一次循环中这个取余可以不执行
	if (last + k <= 9)
		helper(i * 10 + last + k, n - 1, k);
	if (last - k >= 0)
		helper(i * 10 + last - k, n - 1, k);
}