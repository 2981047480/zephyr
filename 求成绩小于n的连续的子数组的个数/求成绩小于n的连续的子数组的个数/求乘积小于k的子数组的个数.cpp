#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *nums, k, num=1, n, m=-1, j=0;
	printf("������������Ԫ�صĸ���\n");
	scanf_s("%d", &n);
	nums = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		printf("����������ĵ�%d��Ԫ��\n", i + 1);
		scanf_s("%d", nums + i);//����һ����̬���鲢��������ֵ
	}
	printf("������Ҫ�õ���ֵ\n");
	scanf_s("%d", &k);
	for (int i = 0; i < n; i++)
	{
		num = 1;
		for (j = i; j < n && num < k; j++)
		{
			num = num * *(nums + j);
			m++;
		}
	}
	printf("%d\n",m);
	system("pause");
	return 0;
}