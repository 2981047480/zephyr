#include<stdio.h>
#include<stdlib.h>
//头文件
void fuc(int a);
bool isprimenumber(int a);
//函数声明

int main(int argc, char argv[])
{
	system("color f5");
	int m;
	printf("请输入m:\n");
	scanf_s("%d", &m);
	fuc(m);
	system("pause");
}
//主函数

bool isprimenumber(int a)
{
	int flag=0,i;
	for (i = 2; i < a; i++)
	{
		if (a%i == 0)
		{
			flag = 1;//flag为1时不是素数
		}
	}
	if (flag == 1)
	{
		return false;
	}
	if (flag == 0)
	{
		return true;
	}
}

void fuc(int a)
{
	int i,b;
	b = a;//用来代替a作为循环条件
	for (i = b; i > 1;)
	{
		if (isprimenumber(i) == true)//是素数
		{
			if (a%i == 0)//如果可以整除i
			{
				printf("%d\n", i);
				a = a / i;
			}
			else
			{
				i--;
			}
		}
		else//不是素数
		{
			i--;
		}
	}
}