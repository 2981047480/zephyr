//爬楼梯问题
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char argv[])
{
	system("color f5");
	int a[100],i;
	a[1] = 1;
	a[0] = 1;//前两项均为1，所以数组初始化为1
	for (i = 2; i <= 99; i++)//之后的项等于前两项之和
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	int num;//要求用户输入的项数
	printf("请输入第几层楼梯\n");
	scanf_s("%d", &num);
	if (num < 1 || num>100 || num%1!=0)
	{
		printf("请输入一个在1-100之间的整数\n");
		exit(-1);
	}
	printf("%d", a[num-1]);//打印出第num项
	system("pause");
	return 0;
}