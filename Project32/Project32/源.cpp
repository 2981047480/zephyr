#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//头文件

int main(int argc, char argv[])
{
	system("color f5");
	int n,m,i,j;
	int a[1000][2];
	double b[1000][1000];
	printf("请输入要输入的个数:\n");
	scanf_s("%d", &n);
	for (i=0; i < n; i++)
	{
		scanf_s("%d %d", &a[i][0], &a[i][1]);
	}
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-1; j++)
		{
			m = pow(a[i][0] - a[j][0], 2) + pow(a[i+1][1] - a[j+1][1], 2);
			b[i][j] = sqrt(m);
			printf("%d", b[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}