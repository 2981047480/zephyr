#include<stdio.h>
#include<stdlib.h>

void helper(int i, int n, int k);

int main(int argc, char argv[])
{
	system("color f5");
	int n, k;
	printf("�����볤��n\n");
	scanf_s("%d", &n);
	printf("������k\n");
	scanf_s("%d", &k);
	for (int i = 1; i <= 9; i++)
	{
		helper(i, n, k);
	}
	system("pause");
}

void helper(int i, int n, int k)
{
	if (n==1) //��n=1��ʱ������
	{
		printf("%d\n", i);
		return;
	}
	int last = i % 10;//�����һ��ѭ�������ȡ����Բ�ִ��
	if (last + k <= 9)
		helper(i * 10 + last + k, n - 1, k);
	if (last - k >= 0)
		helper(i * 10 + last - k, n - 1, k);
}