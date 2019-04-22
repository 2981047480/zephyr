#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//头文件
void judge(char a[]);
//函数声明

int main(int argc, char *argv[])
{
	system("color f5");
	char str[1000];
	printf("请输入要判断的字符串\n");
	scanf("%s", str);//读入字符串
	judge(str);
	system("pause");
	return 0;
}

void judge(char a[])
{
	int i=0,j,k,l;//此处l为下面循环中返回的值，作用是记录最小相同的字符的下标
	while (a[i] != '\0')
	{
		i++;
	}
	l = i;
	for (j = 0; j < i; j++)
	{
		for (k = i; k > j; k--)
		{
			if (a[j] == a[k]&&k<l)
			{
				l = k;
			}
		}
	}
	for (int b = 0; b < l; b++)
	{
		printf("%c", a[b]);
	}
}