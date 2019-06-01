#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *nums, k, num=1, n, m=-1, j=0;
	printf("请输入数组中元素的个数\n");
	scanf_s("%d", &n);
	nums = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		printf("请输入数组的第%d个元素\n", i + 1);
		scanf_s("%d", nums + i);//创建一个动态数组并输入它的值
	}
	printf("请输入要得到的值\n");
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