#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int score;
	system("color f5");
	printf("欢迎使用成绩分等级器\n");
	printf("请输入要判断的成绩\n");
	scanf_s("%d", &score);         //在vs2017中，scanf需要写成scanf_s，系统认为scanf_s更加安全
	if (score>89)//成绩大于89则运行
	{
		printf("A");
	}
	else
	{
		if (score>69)//已经判断过成绩小于90
		{
			printf("B");
		}
		else
		{
			if (score > 59)
			{
				printf("C");
			}
			else
				printf("D");
		}
	}
	system("pause");
}