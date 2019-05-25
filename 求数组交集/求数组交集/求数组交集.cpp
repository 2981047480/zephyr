#include<stdio.h>
#include<stdlib.h>
//头文件

int c = 0;

int* compare(int p[], int q[], int m, int n);

int main(int argc, char *argv[])
{
	system("color f5");
	int *q, n, m, *p;
	printf("请输入两个数组元素个数\n");
	scanf_s("%d %d", &m, &n);
	p = (int *)malloc(m * sizeof(int));
	q = (int *)malloc(n * sizeof(int));//动态申请数组
	for (int i = 0; i < m; i++)
	{
		printf("请输入第%d个数字\n",i+1);
		scanf_s("%d", p + i);
	}
	printf("请输入第二个数组的元素\n");
	for (int i = 0; i < n; i++)
	{
		printf("请输入第%d个数字\n", i + 1);
		scanf_s("%d", q + i);
	}
	int *temp;
	temp=compare(p,q,m,n);
	for (int i = 0; i < c; i++)
	{
		printf("%d ", *(temp + i));
	}
	printf("\n");
	system("pause");
	return 0;
}

int* compare(int p[], int q[], int m, int n)
{
	int *z;
	//int n = 0;//考虑后这里还是用全局变量比较好
	int min=m<n?m:n;
	int a[100] = {0};
	z = (int *)malloc(min * sizeof(int));
	for (int i = 0; i < m-1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (*(p + i) == *(q + j) && a[*(p + i)] == 0)//寻找两个数组中相等的项
			{
				a[*(p + i)]++;
				*(z + c) = *(p + i);//找到之后赋值给这个数组
				c++;//这里之所以把c用作全局变量，是因为主函数中输出还要用到c
			}
		}
	}//查过后网上有两种方法，不过最后发现排序那种还不如这种。
	return z;
}