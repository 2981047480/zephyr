#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
//头文件
void judge(char a[], char b[]);
//函数声明

int main(int argc, char *argv[])
{
	char a[1000], b[1000];
	printf("请输入第一个字符串\n");
	scanf("%s", a);
	printf("请输入第二个字符串\n");
	scanf("%s", b);
	judge(a, b);
	system("pause");
	return 0;
}

void judge(char a[], char b[])//用来比较以及输出相同的前缀
{
	int i = 0, j = 0, k, l;
	while (a[i] != '\0')
	{
		i++;
	}
	while (b[j] != '\0')
	{
		j++;
	}//得到两个数组的长度
	k = i > j ? i : j;
	printf("\"");
	for (l = 0; l <= k; l++)
	{
		if (a[l]==b[l])//如果这两个字符相等
		{
			printf("%c", a[l]);
		}
		else
		{
			printf("\"");
			break;
		}
	}
	//printf("\"");
}