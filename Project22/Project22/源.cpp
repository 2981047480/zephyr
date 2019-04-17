#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)//使vs2017中的scanf_s机制忽略
//头文件

char name[100][10];
char temp[10];
int i, j, n;
//全局变量

int main(int argc, char *argv[])
{
	system("color f5");
	printf("请输入需要录入的名字个数\n");
	scanf("%d", &n);//名字数（用来判断循环次数）
	if (n > 100 || n < 1)
	{
		printf("请输入正确数据\n");
		system("pause");
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%s", name[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (strcmp(name[j], name[j + 1]) > 0)//比较如果字符顺序不对的话
			{
				strcpy_s(temp, name[j]);
				strcpy_s(name[j], name[j + 1]);
				strcpy_s(name[j + 1], temp);//交换位置，这个函数也要用strcpy_s
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%s\n", name[i]);
	}
	system("pause");
	return 0;
}