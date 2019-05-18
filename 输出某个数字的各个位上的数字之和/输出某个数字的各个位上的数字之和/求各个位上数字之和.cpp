#include<stdio.h>
#include<stdlib.h>
//头文件

int main(int argc, char *argv[])
{
	int num, i=0, n;
	printf("请输入\n");
	scanf_s("%d", &num);
	while (true)
	{
		while (num)
		{
			n = num % 10;
			i = i + n;
			num = num / 10;//用循环算出所有的位并相加
		}
		num = i;
		if (i < 10)
		{
			break;
		}
		i = 0;
	}
	printf("%d\n", i);
	system("pause");
	return 0;
}