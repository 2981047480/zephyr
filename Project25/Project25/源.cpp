#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//头文件
void printnum(void);
//声明函数

int main(int argc, char *argv[])
{
	system("color f5");
	printnum();
	system("pause");
	return 0;
}
//主函数

void printnum(void)
{
	int i, j, k, l ,sum;
	for (i = 100; i < 1000; i++)
	{
		j = i / 100;
		k = i / 10 - j * 10;
		l = i - j * 100 - k * 10;
		sum = pow(j, 3) + pow(k, 3) + pow(l, 3);
		if (sum == i)
		{
			printf("%d\n", i);
		}
	}
}